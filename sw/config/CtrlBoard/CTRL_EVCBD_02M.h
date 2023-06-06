// ================================================================================================
//! \file       CTRL_EVCBD_02M.h
//! \brief      控制器EVCBD_02M原理图(带IGBT壳温采集)
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017年4月12日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _CTRL_EVCBD_02M_H_
#define _CTRL_EVCBD_02M_H_

//! @defgroup CTRL_EVCBD_02M
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================
// the includes

// ================================================================================================
// the defines

#define INVTEMP_TYPE     3                          //!< 逆变器温度采集 1：NTC473电路1 2:NTC473电路2 3:IGBT壳温（1。0倍） 4：IGBT壳温（1.5倍）
#define MOTTEMPTYPE      1                          //!< 电机温度采集  1：PT100电路1 2：PT100d电路2
#define CUR_SEN_TYPE     CUR_SEN_noneU_plusV_plusW  //!< 电流传感器类型[   +V +W]
#define CUR_RANGE        15840                      //!< 电流传感器满量程范围 0.1A ==> 400S 400A莱姆是31680，200A莱姆是15840
#define CURBUS_RANGE     0                          //!< 母线电流传感器满量程范围  0=没有母线电流传感器
#define VOLTBUS_RANGE    9380                       //!< 母线电压满量程范围     0.1V 可配置
#define VOLTCAP_RANGE    9380                       //!< 电容电压满量程范围     0.1V 可配置
#define VOLT_MAX         7500                       //!< 控制器最大电压              0.1V
#define CUR_MAX          5500                       //!< 控制器最大电流              0.1A

// 模块映射
#define M1_SPI_HANDLE    halHandle->spiAHandle              //!< SPI接口
#define M1_QEP_HANDLE    halHandle->qepHandle[HAL_Qep_QEP2] //!< QEP接口
#define M1_SCI_HANDLE    halHandle->sciHandle[SCI_MODULE_B] //!< SCI接口
#define M1_CAN_HANDLE    halHandle->canAHandle              //!< CAN接口
#define M1_I2C_HANDLE    halHandle->i2cHandle               //!< I2C接口
#define M1_I2C_SDA_GPIO  GPIO_Number_28                     //!< I2C_SDA GPIO
#define M1_I2C_SCL_GPIO  GPIO_Number_29                     //!< I2C_SCL GPIO
#define M1_I2C_SDA_MODE  GPIO_28_Mode_SDDA                  //!< GPIO模式
#define M1_I2C_SCL_MODE  GPIO_29_Mode_SCLA                  //!< GPIO模式

// 传感器偏置
#define M1_CUR_U_OFFSET    (2048.0)              //!< U相电流默认偏置AD
#define M1_CUR_V_OFFSET    (2048.0)              //!< V相电流默认偏置AD
#define M1_CUR_W_OFFSET    (2048.0)              //!< W相电流默认偏置AD
#define M1_CUR_BUS_OFFSET  (2048.0)              //!< 母线电流默认偏置AD

// 传感器量程
#define M1_VOLT_05V_RANGE  (5.0000000000000000)  //!< 信号缺省时，配置为(5.00000)
#define M1_VOLT_12V_RANGE  (20.603370786516855)  //!< 信号缺省时，配置为(12.0000)
#define M1_VOLT_24V_RANGE  (40.945631067961159)  //!< 信号缺省时，配置为(24.0000)
#define M1_VOLT_POT1_RANGE (5.00000)             //!< 信号缺省时，配置为(5.00000)

// ADC通道信号映射
#define M1_CUR_U        (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_CUR_V        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_1)
#define M1_CUR_W        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_2)
#define M1_CUR_BUS      (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_VOLT_U       (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_VOLT_V       (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_VOLT_W       (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_VOLT_BUS     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
#define M1_VOLT_CAP     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
#define M1_VOLT_05V     (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_VOLT_12V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_5)
#define M1_VOLT_24V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_4)
#define M1_VOLT_POT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_8)
#define M1_TEMP_INV1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_9)
#define M1_TEMP_INV2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_10)
#define M1_TEMP_INV3    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_11)
#define M1_TEMP_MOT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_12)
#define M1_TEMP_MOT2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_13)


// GPIO信号映射
#define HAL_Pwm_BUF1_En(halHandle)        GPIO_setLow(halHandle->gpioHandle,GPIO_Number_55)
#define HAL_Pwm_BUF1_Dis(halHandle)       GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_55)

#define HAL_Pwm_BUF2_En(halHandle)        GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_56)
#define HAL_Pwm_BUF2_Dis(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_56)

#define HAL_Pwm_POWER_En(halHandle)       GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_6)
#define HAL_Pwm_POWER_Dis(halHandle)      GPIO_setLow(halHandle->gpioHandle,GPIO_Number_6)

#define HAL_Pwm_ShutDown_En(halHandle)    GPIO_setLow(halHandle->gpioHandle,GPIO_Number_7)
#define HAL_Pwm_ShutDown_Dis(halHandle)   GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_7)  //!< 正常工作时Dis

#define HAL_Coder_RST_En(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_20)
#define HAL_Coder_RST_Dis(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_20)  //!< 正常工作时Dis

#define HAL_DRV1_En(halHandle)            GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_12)
#define HAL_DRV1_Dis(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_12)

#define HAL_DRV2_En(halHandle)            GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_53)
#define HAL_DRV2_Dis(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_53)

#define HAL_LED1_on(halHandle)            GPIO_setLow(halHandle->gpioHandle,GPIO_Number_58)
#define HAL_LED1_off(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_58)
#define HAL_LED1_toggle(halHandle)        GPIO_toggle(halHandle->gpioHandle,GPIO_Number_58)

#define HAL_LED2_on(halHandle)            GPIO_setLow(halHandle->gpioHandle,GPIO_Number_13)
#define HAL_LED2_off(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_13)
#define HAL_LED2_toggle(halHandle)        GPIO_toggle(halHandle->gpioHandle,GPIO_Number_13)

#define HAL_KEEP_POWER_En(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_8)
#define HAL_KEEP_POWER_Dis(halHandle)     GPIO_setLow(halHandle->gpioHandle,GPIO_Number_8)

#define HAL_KSI_SW(halHandle)             (!GPIO_read(halHandle->gpioHandle,GPIO_Number_44))
#define HAL_Coder_Err(halHandle)          GPIO_read(halHandle->gpioHandle,GPIO_Number_21)
#define HAL_Pwm_Fault1(halHandle)         (!GPIO_read(halHandle->gpioHandle,GPIO_Number_50))
#define HAL_Pwm_Fault2(halHandle)         (!GPIO_read(halHandle->gpioHandle,GPIO_Number_51))
#define HAL_Pwm_Fault3(halHandle)         (!GPIO_read(halHandle->gpioHandle,GPIO_Number_52))
#define HAL_DRV1_ST(halHandle)            (!GPIO_read(halHandle->gpioHandle,GPIO_Number_16))
#define HAL_DRV2_ST(halHandle)            (!GPIO_read(halHandle->gpioHandle,GPIO_Number_54))


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

//! @} // end of CTRL_EVCBD_02M

#endif // end of _CTRL_EVCBD_02M_H_
