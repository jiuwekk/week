// ================================================================================================
//! \file       FDC_M_01.h
//! \brief      控制器FDC_M_01原理图
//! \author     JK
//! \version    1.0.0
//! \date       2020年05月26日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _S_CTRL_05XB_H_
#define _S_CTRL_05XB_H_

//! @defgroup FDC_M_01
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================
// the includes

// ================================================================================================
// the defines
#define INVTEMP_TYPE     6                          //!< 逆变器温度采集 1：NTC473电路1 2:NTC473电路2 3:IGBT壳温（1。0倍） 4：IGBT壳温（1.5倍）;5:05XB
#define MOTTEMPTYPE      4                          //!< 电机温度采集  1：PT100电路1 2：PT100d电路2 4：PWM恒流源;6:05XB双路恒流源切换
#define USE_4C           4                          //!< 设置为1：使用4C外壳；为0：使用扁平控制器; 2:使用五合一;4:使用05XB霍尔传感器
#define USE_HALL_CURSEN  1                          //!< 6:05Xb:使用霍尔电流传感器 2019.10.12 新出驱动板   1：有效 0:老版电流传感器
#if  USE_4C == 1
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< 电流传感器类型[+U    +W]
    #define CUR_RANGE        31680                      //!< 电流传感器满量程范围 0.1A ==> 400S
#elif USE_4C == 2
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< 电流传感器类型[+U    +W]
    #define CUR_RANGE        22000                      //!< 电流传感器满量程范围 0.1A ==> 800M(800A==>2V)
#elif USE_4C == 4
    #if USE_HALL_CURSEN == 1
        #define CUR_SEN_TYPE     CUR_SEN_mnusU_mnusV_noneW  //!< 电流传感器类型[-U  -V    ]
        #define CUR_RANGE     12800                      //!< 电流传感器满量程范围
    #elif USE_HALL_CURSEN == 0
        #define CUR_SEN_TYPE     CUR_SEN_plusU_plusV_noneW  //!< 电流传感器类型[+U  +V    ]
        #define CUR_RANGE      20200                      //!< 电流传感器满量程范围
    #endif
#else
    #define CUR_SEN_TYPE     CUR_SEN_mnusU_noneV_mnusW  //!< 电流传感器类型[-U    -W]
    #define CUR_RANGE        22000                      //!< 电流传感器满量程范围 0.1A ==> 900M(900A==>2V)
#endif

#define CURBUS_RANGE     0                          //!< 母线电流传感器满量程范围  0=没有母线电流传感器
#define VOLTBUS_RANGE    3100                       //!< 母线电压满量程范围     0.1V 可配置
#define VOLTCAP_RANGE    3100                       //!< 电容电压满量程范围     0.1V 可配置
#define VOLT_MAX         3100                        //!< 控制器最大电压              0.1V
#define CUR_MAX          4000                       //!< 控制器最大电流              0.1A

#define Fan_Work_Vol           24         //风扇工作电压
#define PWM_Num_Fan            1          //风扇用1号PWM脚
#define PWM_Num_MainRelay      3          //主接触器用3号PWM脚

//===================================1.模块映射=============================================//
#define M1_SPI_HANDLE    halHandle->spiAHandle              //!< SPI接口
#define M1_QEP_HANDLE    halHandle->qepHandle[HAL_Qep_QEP2] //!< QEP接口
#define M1_SCI_HANDLE    halHandle->sciHandle[SCI_MODULE_B] //!< SCI接口
#define M1_CAN_HANDLE    halHandle->canAHandle              //!< CAN接口
#define M1_I2C_HANDLE    halHandle->i2cHandle               //!< I2C接口
#define M1_I2C_SDA_GPIO  GPIO_Number_28                     //!< I2C_SDA GPIO
#define M1_I2C_SCL_GPIO  GPIO_Number_29                     //!< I2C_SCL GPIO
#define M1_I2C_SDA_MODE  GPIO_28_Mode_SDDA                  //!< GPIO模式
#define M1_I2C_SCL_MODE  GPIO_29_Mode_SCLA                  //!< GPIO模式
//===================================2.AD通道=============================================//
//result号要跟SOC号对应,但是SOC可以在Hal_adc里面与不同的AB号即通道关联
//1.相电流   ADC通道信号映射
#define M1_CUR_U        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_1)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_CUR_V        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_2)
#define M1_CUR_W        (4096)
#define M1_CUR_BUS      (4096)
//2.母线电压
#define M1_VOLT_U       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
#define M1_VOLT_V       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_4)
#define M1_VOLT_W       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_5)
#define M1_VOLT_BUS     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_6)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_VOLT_CAP     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_7)
//3.逻辑电压
#define M1_VOLT_05V     (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_VOLT_12V     (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_VOLT_24V     (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_VOLT_POT1    (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
//4.IGBT温度
#define M1_TEMP_INV1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_11)
#define M1_TEMP_INV2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_11)
#define M1_TEMP_INV3    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_11)
//5.电机温度
//测温开管控制                            注意高低有效
#define HAL_MOTTEMP_En1(halHandle)        GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_40)
#define HAL_MOTTEMP_Dis1(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_40)
#define HAL_MOTTEMP_En2(halHandle)        GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_16)
#define HAL_MOTTEMP_Dis2(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_16)

#define HAL_MOTTEMP_EN1(halHandle)        HAL_MOTTEMP_En1(halHandle);HAL_MOTTEMP_Dis2(halHandle)  // 280uA电路有效
#define HAL_MOTTEMP_EN2(halHandle)        HAL_MOTTEMP_En2(halHandle);HAL_MOTTEMP_Dis1(halHandle)  // 4.254mA电路有效

#define M1_TEMP_MOT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_12)
#define M1_TEMP_MOT2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_13)


//6.端口模拟量采集                 外部模拟量输入,有用到在配
//#define M1_VOLT_POT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_12)
//#define M1_VOLT_POT2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_13)
//#define M1_VOLT_POT3    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_14)
//#define M1_VOLT_POT4    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_15)
//#define M1_VOLT_POT5    (4096)//ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_15)

//===================================3.AD换算=============================================//
// 传感器偏置                                                 根据实际采集到的数值在做精确计算
#define M1_CUR_U_OFFSET    (2048.0)              //!< U相电流默认偏置AD
#define M1_CUR_V_OFFSET    (2048.0)              //!< V相电流默认偏置AD
#define M1_CUR_W_OFFSET    (2048.0)              //!< W相电流默认偏置AD
#define M1_CUR_BUS_OFFSET  (2048.0)              //!< 母线电流默认偏置AD

// 传感器量程                                                 根据实际采集到的数值在做精确计算
#define M1_VOLT_05V_RANGE  (5.0000000000000000)  //!< 信号缺省时，配置为(5.00000)
#define M1_VOLT_12V_RANGE  (12.000000000000000)  //!< 信号缺省时，配置为(12.0000)
#define M1_VOLT_24V_RANGE  (24.000000000000000)  //!< 信号缺省时，配置为(24.0000)
#define M1_VOLT_POT1_RANGE (5.0000000000000000)  //!< 信号缺省时，配置为(5.00000)

//===================================4.GPIO配置=============================================//
//1.LED 配置
#define HAL_LED1_on(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_14)
#define HAL_LED1_off(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_14)
#define HAL_LED1_toggle(halHandle)       GPIO_toggle(halHandle->gpioHandle,GPIO_Number_14)

#define HAL_LED2_on(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_15)
#define HAL_LED2_off(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_15)
#define HAL_LED2_toggle(halHandle)       GPIO_toggle(halHandle->gpioHandle,GPIO_Number_15)

// GPIO信号映射
//2.Buffer缓冲芯片使能
#define HAL_Pwm_BUF1_En(halHandle)        GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_51)   // EN-PWM
#define HAL_Pwm_BUF1_Dis(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_51)
//只有一个BUF1_EN
#define HAL_Pwm_BUF2_En(halHandle)        {;}
#define HAL_Pwm_BUF2_Dis(halHandle)       {;}
//3.IGBT使能复位
#define HAL_Pwm_POWER_En(halHandle)       {;}
#define HAL_Pwm_POWER_Dis(halHandle)      {;}

#define HAL_Pwm_ShutDown_En(halHandle)    {;}
#define HAL_Pwm_ShutDown_Dis(halHandle)   {;}

//4.高边驱动
#define HAL_DRV1_En(halHandle)            GPIO_setLow(halHandle->gpioHandle,GPIO_Number_6) // 主接触器器 (PWM1待定)
#define HAL_DRV1_Dis(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_6)

#define HAL_DRV2_En(halHandle)            GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_43) // 预充接触器
#define HAL_DRV2_Dis(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_43)

#define HAL_DRV1_ST(halHandle)            (0)
#define HAL_DRV2_ST(halHandle)            (0)
//5.逻辑电源
//HOLD_Power 保持
#define HAL_KEEP_POWER_En(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_54)
#define HAL_KEEP_POWER_Dis(halHandle)     GPIO_setLow(halHandle->gpioHandle,GPIO_Number_54)
//KSI_TEST 钥匙 输入状态
#define HAL_KSI_SW(halHandle)             (GPIO_read(halHandle->gpioHandle,GPIO_Number_53))

//6.IGBT状态                         不确定用没用到
#define HAL_Pwm_Fault1(halHandle)         (0)
#define HAL_Pwm_Fault2(halHandle)         (0)
#define HAL_Pwm_Fault3(halHandle)         (0)

//7.AD2S1205旋变变压器  RDC_LOT 丢失
#define HAL_Coder_Err(halHandle)         (!GPIO_read(halHandle->gpioHandle,GPIO_Number_21))
////信号的丢失                         没用到
#define HAL_RDC_Dos(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_27))

//旋变芯片复位 0：有效
#define RDC_RST_En(halHandle)             GPIO_setLow(halHandle->gpioHandle,GPIO_Number_44)
#define RDC_RST_Dis(halHandle)            GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_44)
//采样结果     1->0转移
#define RDC_SAMPLE_H(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_39)
#define RDC_SAMPLE_L(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_39)
//1:位置  0:速度
#define RDC_RDVEL_LOC(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_34)
#define RDC_RDVEL_SPD(halHandle)          GPIO_setLow(halHandle->gpioHandle,GPIO_Number_34)
//输出缓冲使能  1->0转移 旋变
#define RDC_RD_H(halHandle)               GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_50)
#define RDC_RD_L(halHandle)               GPIO_setLow(halHandle->gpioHandle,GPIO_Number_50)

////8.开关量输入
#define HAL_SW3_ST(halHandle)             (GPIO_read(halHandle->gpioHandle,GPIO_Number_20))
#define HAL_SW4_ST(halHandle)             (GPIO_read(halHandle->gpioHandle,GPIO_Number_58))
#define HAL_SW5_ST(halHandle)             (GPIO_read(halHandle->gpioHandle,GPIO_Number_13))
#define HAL_SW6_ST(halHandle)             (GPIO_read(halHandle->gpioHandle,GPIO_Number_22))
#define HAL_SW7_ST(halHandle)             (GPIO_read(halHandle->gpioHandle,GPIO_Number_32))
#define HAL_SW8_ST(halHandle)             (GPIO_read(halHandle->gpioHandle,GPIO_Number_33))

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
