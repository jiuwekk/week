// ================================================================================================
//! \file       CTRL_HP1_LOGIC.h
//! \brief      控制器双芯片原理图
//! \author     王鹏翔
//! \version    1.0.0
//! \date       2021年12月29日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _CTRL_HP1_LOGIC_H_
#define _CTRL_HP1_LOGIC_H_

//! @defgroup FDC_M_01
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================
// the includes

// ================================================================================================
// the defines
#define USE_4C           6                          //!< 设置为1：使用4C外壳；为0：使用扁平控制器;
                                                    //       2:使用五合一;3:双芯片;4:20Kw单芯片比亚迪600A;
                                                    //       5:20Kw单芯片500A;6:20Kw单芯片400A
#define INVTEMP_TYPE     5                          //!< 逆变器温度采集 1：NTC473电路1
                                                    //             2:NTC473电路2
                                                    //             3:IGBT壳温（1。0倍）
                                                    //             4：IGBT壳温（1.5倍）
                                                    //             5:双芯片_主控制板  与  20Kw单芯片
#define MOTTEMPTYPE      4                          //!< 电机温度采集  1：PT100电路1 2：PT100d电路2 4：PWM恒流源
#if  USE_4C == 1
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< 电流传感器类型[+U    +W]
    #define CUR_RANGE        31680                      //!< 电流传感器满量程范围 0.1A ==> 400S
#elif USE_4C == 2
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< 电流传感器类型[+U    +W]
    #define CUR_RANGE        22000                      //!< 电流传感器满量程范围 0.1A ==> 800M(800A==>2V)
#elif USE_4C == 3
    #define CUR_SEN_TYPE     CUR_SEN_mnusU_noneV_mnusW  //!< 电流传感器类型[-U    -W]
    #define CUR_RANGE        14760//10200                      //!< 电流传感器满量程范围 0.1A (600A/500A)==> 900M(900A==>2V)
#elif USE_4C == 4
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< 电流传感器类型[+U    +W]
    #define CUR_RANGE        14760                      //!< 电流传感器满量程范围6000 * 0.1A
#elif USE_4C == 5
    #define CUR_SEN_TYPE     CUR_SEN_mnusU_noneV_mnusW  //!< 电流传感器类型[-U    -W]
    #define CUR_RANGE        10200                      //!< 电流传感器满量程范围 4000 * 0.1A
#elif USE_4C == 6
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< 电流传感器类型[+U    +W]
    #define CUR_RANGE        10200                      //!< 电流传感器满量程范围 4000 * 0.1A
#else
    #define CUR_SEN_TYPE     CUR_SEN_mnusU_noneV_mnusW  //!< 电流传感器类型[-U    -W]
    #define CUR_RANGE        22000               //!< 电流传感器满量程范围 0.1A ==> 900M(900A==>2V)
#endif

#define CURBUS_RANGE     0                          //!< 母线电流传感器满量程范围  0=没有母线电流传感器
#define VOLTBUS_RANGE    11050                       //!< 母线电压满量程范围     0.1V 可配置
#define VOLTCAP_RANGE    11050                       //!< 电容电压满量程范围     0.1V 可配置
#define VOLPHASE_RANGE    5500                       //!< 相线电压满量程范围     0.1V 可配置
#define VOLT_MAX         7500                       //!< 控制器最大电压              0.1V
#define CUR_MAX          5500                       //!< 控制器最大电流              0.1A

//===================================1.模块映射=============================================//
#define M1_SPI_HANDLE    halHandle->spiAHandle              //!< QEP-SPI接口
//#define M1_SPIB_HANDLE   halHandle->spiBHandle              //!< SPI接口
#define M1_QEP_HANDLE    halHandle->qepHandle[HAL_Qep_QEP1] //!< QEP接口
#define M1_SCI_HANDLE    halHandle->sciHandle[SCI_MODULE_B] //!< SCI接口
#define M1_CAN_HANDLE    halHandle->canAHandle              //!< CAN接口
#define M1_I2C_HANDLE    halHandle->i2cHandle               //!< I2C接口
#define M1_I2C_SDA_GPIO  GPIO_Number_28                     //!< I2C_SDA GPIO
#define M1_I2C_SCL_GPIO  GPIO_Number_29                     //!< I2C_SCL GPIO
#define M1_I2C_SDA_MODE  GPIO_28_Mode_SDDA                  //!< GPIO模式
#define M1_I2C_SCL_MODE  GPIO_29_Mode_SCLA                  //!< GPIO模式
//===================================2.AD通道=============================================//
//1.相电流   ADC通道信号映射
#define M1_CUR_U        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_0)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_CUR_V        (2048)
#define M1_CUR_W        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_8)
#define M1_CUR_BUS      (4096)
//2.母线电压
#define M1_VOLT_BUS     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_10)//ADC_ResultNumber_10
#define M1_VOLT_CAP     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_10)//ADC_ResultNumber_10
//3.逻辑电压
#define M1_VOLT_05V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_7)
#define M1_VOLT_05V_out ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_6)
#define M1_VOLT_12V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_5)
#define M1_VOLT_15V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_4)
#define M1_VOLT_24V     (4096)
//4.IGBT温度
#define M1_TEMP_INV1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
#define M1_TEMP_INV2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
#define M1_TEMP_INV3    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
//5.电机温度
#define M1_TEMP_MOT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_11)
#define M1_TEMP_MOT2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_12)
#define M1_TEMP_NTC     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_15)
//6.端口模拟量采集
#define ACCEL_A_AD      ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_14)
#define ACCEL_B_AD      ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_13)
#define M1_VOLT_POT1    (4096)//
#define M1_VOLT_POT2    (4096)//
#define M1_VOLT_POT3    (4096)//
//7.三相电压采集
#define M1_VOLT_U       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_1)
#define M1_VOLT_V       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_9)
#define M1_VOLT_W       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_2)

//===================================3.AD换算=============================================//
// 传感器偏置
#define M1_CUR_U_OFFSET    (2048.0)              //!< U相电流默认偏置AD
#define M1_CUR_V_OFFSET    (2048.0)              //!< V相电流默认偏置AD
#define M1_CUR_W_OFFSET    (2048.0)              //!< W相电流默认偏置AD
#define M1_CUR_BUS_OFFSET  (2048.0)              //!< 母线电流默认偏置AD

// 传感器量程
#define M1_VOLT_05V_RANGE  (6.600)  //!< 信号缺省时，配置为(5.00000)
#define M1_VOLT_12V_RANGE  (34.38216433)  //!< 信号缺省时，配置为(12.0000)
#define M1_VOLT_24V_RANGE  (24.0000)//(41.52879612)  //!< 信号缺省时，配置为(24.0000)
#define M1_VOLT_POT1_RANGE (4.986373)  //!< 信号缺省时，配置为(5.00000)

//===================================4.GPIO配置=============================================//
//1.LED 配置
#define HAL_LED1_on(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_32)
#define HAL_LED1_off(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_32)
#define HAL_LED1_toggle(halHandle)       GPIO_toggle(halHandle->gpioHandle,GPIO_Number_32)

#define HAL_LED2_on(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_33)
#define HAL_LED2_off(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_33)
#define HAL_LED2_toggle(halHandle)       GPIO_toggle(halHandle->gpioHandle,GPIO_Number_33)

// GPIO信号映射
//2.Buffer缓冲芯片使能
#define HAL_Pwm_BUF1_En(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_16)
#define HAL_Pwm_BUF1_Dis(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_16)
//只有一个BUF1_EN
#define HAL_Pwm_BUF2_En(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_16)
#define HAL_Pwm_BUF2_Dis(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_16)
//3.IGBT使能复位
#define HAL_Pwm_POWER_En(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_6)
#define HAL_Pwm_POWER_Dis(halHandle)     GPIO_setLow(halHandle->gpioHandle,GPIO_Number_6)

#define HAL_Pwm_ShutDown_En(halHandle)   GPIO_setLow(halHandle->gpioHandle,GPIO_Number_7)
#define HAL_Pwm_ShutDown_Dis(halHandle)  GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_7)  //!< 正常工作时Dis

//4.高边驱动
//#define HAL_DRV1_En(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_53)  //!<
//#define HAL_DRV1_Dis(halHandle)          GPIO_setLow(halHandle->gpioHandle,GPIO_Number_53)
//
//#define HAL_DRV2_En(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_39)  //!<
//#define HAL_DRV2_Dis(halHandle)          GPIO_setLow(halHandle->gpioHandle,GPIO_Number_39)
//
//#define HAL_DRV3_En(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_54)  //!<
//#define HAL_DRV3_Dis(halHandle)          GPIO_setLow(halHandle->gpioHandle,GPIO_Number_54)
//
//#define HAL_DRV4_En(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_55)  //!<
//#define HAL_DRV4_Dis(halHandle)          GPIO_setLow(halHandle->gpioHandle,GPIO_Number_55)
//
//#define HAL_DRV1_ST(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_16))
//#define HAL_DRV2_ST(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_56))
//5.逻辑电源
//HOLD_Power 保持
#define HAL_KEEP_POWER_En(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_15)
#define HAL_KEEP_POWER_Dis(halHandle)     GPIO_setLow(halHandle->gpioHandle,GPIO_Number_15)
//KSI_TEST 钥匙 输入状态
#define HAL_KSI_SW(halHandle)            (!GPIO_read(halHandle->gpioHandle,GPIO_Number_24))
//B+_TEST  常电
#define HAL_B_SW(halHandle)             (!GPIO_read(halHandle->gpioHandle,GPIO_Number_14))

//6.IGBT状态
#define HAL_Pwm_Fault1(halHandle)        (!GPIO_read(halHandle->gpioHandle,GPIO_Number_8))
#define HAL_Pwm_Fault2(halHandle)        (!GPIO_read(halHandle->gpioHandle,GPIO_Number_9))
#define HAL_Pwm_Fault3(halHandle)        (!GPIO_read(halHandle->gpioHandle,GPIO_Number_10))

//7.AD2S1205旋变变压器  RDC_LOT 丢失
#define HAL_Coder_Err(halHandle)         (!GPIO_read(halHandle->gpioHandle,GPIO_Number_27))
//信号的丢失
#define HAL_RDC_Dos(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_26))

//旋变芯片复位 0：有效
#define RDC_RST_En(halHandle)             GPIO_setLow(halHandle->gpioHandle,GPIO_Number_52)
#define RDC_RST_Dis(halHandle)            GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_52)
//采样结果     1->0转移
#define RDC_SAMPLE_H(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_13)
#define RDC_SAMPLE_L(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_13)
//1:位置  0:速度
#define RDC_RDVEL_LOC(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_58)
#define RDC_RDVEL_SPD(halHandle)          GPIO_setLow(halHandle->gpioHandle,GPIO_Number_58)
//输出缓冲使能  1->0转移 旋变
#define RDC_RD_H(halHandle)               GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_44)
#define RDC_RD_L(halHandle)               GPIO_setLow(halHandle->gpioHandle,GPIO_Number_44)

//8.开关量输入
//#define HAL_SW1_IN(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_22))
#define HAL_SW2_IN(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_50))
#define HAL_SW3_IN(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_54))
#define HAL_SW4_IN(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_53))
#define HAL_SW5_IN(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_12))
#define HAL_SW6_IN(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_51))

// ================================================================================================
// the typedefs


// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes



// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of CTRL_LV_MCU_101

#endif // end of _CTRL_LV_MCU_101_H_
