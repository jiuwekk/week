// ================================================================================================
//! \file       CTRL_EVCBD_01M.h
//! \brief      控制器EVCBD_01M原理图
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017年4月12日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _CTRL_EVCBD_01M_H_
#define _CTRL_EVCBD_01M_H_

//! @defgroup CTRL_EVCBD_01M
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================
// the includes

// ================================================================================================
// the defines

#define INVTEMP_TYPE     2                          //!< 逆变器温度采集 1：NTC473电路1 2:NTC473电路2 3:IGBT壳温（1。0倍） 4：IGBT壳温（1.5倍）
#define MOTTEMPTYPE      1                          //!< 电机温度采集  1：PT100电路1 2：PT100d电路2
#define CUR_SEN_TYPE     CUR_SEN_mnusU_mnusV_noneW  //!< 电流传感器类型[-U -V   ]
#define CUR_RANGE        4000                       //!< 电流传感器满量程范围 0.1A
#define CURBUS_RANGE     0                          //!< 母线电流传感器满量程范围  0=没有母线电流传感器
#define VOLTBUS_RANGE    1620                       //!< 母线电压满量程范围     0.1V 可配置
#define VOLTCAP_RANGE    1620                       //!< 电容电压满量程范围     0.1V 可配置
#define VOLT_MAX         800                        //!< 控制器最大电压              0.1V
#define CUR_MAX          2000                       //!< 控制器最大电流              0.1A

// 模块映射
#define M1_SPI_HANDLE         halHandle->spiBHandle
#define M1_QEP_HANDLE         halHandle->qepHandle[HAL_Qep_QEP1]
#define M1_SCI_HANDLE         halHandle->sciHandle[SCI_MODULE_A]
#define M1_CAN_HANDLE         halHandle->canAHandle
#define M1_I2C_HANDLE         halHandle->i2cHandle
#define M1_I2C_SDA_GPIO       GPIO_Number_32
#define M1_I2C_SCL_GPIO       GPIO_Number_33
#define M1_I2C_SDA_MODE       GPIO_32_Mode_SDDA
#define M1_I2C_SCL_MODE       GPIO_33_Mode_SCLA

// 传感器偏置
#define M1_CUR_U_OFFSET       (2044.81641)
#define M1_CUR_V_OFFSET       (2040.57422)
#define M1_CUR_W_OFFSET       (2048.00000)
#define M1_CUR_BUS_OFFSET     (2048.00000)
#define M1_VOLT_U_OFFSET      (2048.00000)
#define M1_VOLT_V_OFFSET      (2048.00000)
#define M1_VOLT_W_OFFSET      (2048.00000)
#define M1_VOLT_BUS_OFFSET    (2048.00000)
#define M1_VOLT_CAP_OFFSET    (2048.00000)

// 传感器量程
#define M1_VOLT_05V_RANGE     (9.9132264529058110)  //!< 信号缺省时，配置为(5.00000)
#define M1_VOLT_12V_RANGE     (23.139679358717434)  //!< 信号缺省时，配置为(12.0000)
#define M1_VOLT_24V_RANGE     (24.000000000000000)  //!< 信号缺省时，配置为(24.0000)
#define M1_VOLT_POT1_RANGE    (6.0500000000000000)  //!< 信号缺省时，配置为(5.00000)

// ADC通道信号映射
#define M1_CUR_U        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_1)
#define M1_CUR_V        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_2)
#define M1_CUR_W        (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_CUR_BUS      (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_VOLT_U       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_4)
#define M1_VOLT_V       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_5)
#define M1_VOLT_W       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_6)
#define M1_VOLT_BUS     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_8)
#define M1_VOLT_CAP     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_7)
#define M1_VOLT_05V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_12)
#define M1_VOLT_12V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_14)
#define M1_VOLT_24V     (4096)  //!< 信号缺失时，设定值为4096，防止误报故障
#define M1_VOLT_POT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_13)
#define M1_TEMP_INV1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_9)
#define M1_TEMP_INV2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_9)
#define M1_TEMP_INV3    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_9)
#define M1_TEMP_MOT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_10)
#define M1_TEMP_MOT2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_10)

// GPIO信号映射
#define HAL_Pwm_BUF1_En(halHandle)        {;}
#define HAL_Pwm_BUF1_Dis(halHandle)       {;}

#define HAL_Pwm_BUF2_En(halHandle)        {;}
#define HAL_Pwm_BUF2_Dis(halHandle)       {;}

#define HAL_Pwm_POWER_En(halHandle)       {;}
#define HAL_Pwm_POWER_Dis(halHandle)      {;}

#define HAL_Pwm_ShutDown_En(halHandle)    GPIO_setLow(halHandle->gpioHandle,GPIO_Number_7)
#define HAL_Pwm_ShutDown_Dis(halHandle)   GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_7)

#define HAL_Coder_RST_En(halHandle)       GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_11)  //!< 反
#define HAL_Coder_RST_Dis(halHandle)      GPIO_setLow(halHandle->gpioHandle,GPIO_Number_11)

#define HAL_DRV1_En(halHandle)            GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_9)
#define HAL_DRV1_Dis(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_9)

#define HAL_DRV2_En(halHandle)            GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_6)
#define HAL_DRV2_Dis(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_6)

#define HAL_LED1_on(halHandle)            GPIO_setLow(halHandle->gpioHandle,GPIO_Number_42)
#define HAL_LED1_off(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_42)
#define HAL_LED1_toggle(halHandle)        GPIO_toggle(halHandle->gpioHandle,GPIO_Number_42)

#define HAL_LED2_on(halHandle)            GPIO_setLow(halHandle->gpioHandle,GPIO_Number_22)
#define HAL_LED2_off(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_22)
#define HAL_LED2_toggle(halHandle)        GPIO_toggle(halHandle->gpioHandle,GPIO_Number_22)

#define HAL_KEEP_POWER_En(halHandle)      {;}
#define HAL_KEEP_POWER_Dis(halHandle)     {;}

#define HAL_KSI_SW(halHandle)             (ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_8) > 300)
#define HAL_Coder_Err(halHandle)          (!GPIO_read(halHandle->gpioHandle,GPIO_Number_8))
#define HAL_Pwm_Fault1(halHandle)         (0)  //!< 信号缺省时,配置为(0),无故障
#define HAL_Pwm_Fault2(halHandle)         (0)  //!< 信号缺省时,配置为(0),无故障
#define HAL_Pwm_Fault3(halHandle)         (0)  //!< 信号缺省时,配置为(0),无故障
#define HAL_DRV1_ST(halHandle)            (0)  //!< 信号缺省时,配置为(0),无故障
#define HAL_DRV2_ST(halHandle)            (0)  //!< 信号缺省时,配置为(0),无故障

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

//! @} // end of CTRL_EVCBD_01M

#endif // end of _CTRL_EVCBD_01M_H_
