// ================================================================================================
//! \file       CTRL_EVCBD_01M.h
//! \brief      ������EVCBD_01Mԭ��ͼ
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017��4��12��
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

#define INVTEMP_TYPE     2                          //!< ������¶Ȳɼ� 1��NTC473��·1 2:NTC473��·2 3:IGBT���£�1��0���� 4��IGBT���£�1.5����
#define MOTTEMPTYPE      1                          //!< ����¶Ȳɼ�  1��PT100��·1 2��PT100d��·2
#define CUR_SEN_TYPE     CUR_SEN_mnusU_mnusV_noneW  //!< ��������������[-U -V   ]
#define CUR_RANGE        4000                       //!< ���������������̷�Χ 0.1A
#define CURBUS_RANGE     0                          //!< ĸ�ߵ��������������̷�Χ  0=û��ĸ�ߵ���������
#define VOLTBUS_RANGE    1620                       //!< ĸ�ߵ�ѹ�����̷�Χ     0.1V ������
#define VOLTCAP_RANGE    1620                       //!< ���ݵ�ѹ�����̷�Χ     0.1V ������
#define VOLT_MAX         800                        //!< ����������ѹ              0.1V
#define CUR_MAX          2000                       //!< ������������              0.1A

// ģ��ӳ��
#define M1_SPI_HANDLE         halHandle->spiBHandle
#define M1_QEP_HANDLE         halHandle->qepHandle[HAL_Qep_QEP1]
#define M1_SCI_HANDLE         halHandle->sciHandle[SCI_MODULE_A]
#define M1_CAN_HANDLE         halHandle->canAHandle
#define M1_I2C_HANDLE         halHandle->i2cHandle
#define M1_I2C_SDA_GPIO       GPIO_Number_32
#define M1_I2C_SCL_GPIO       GPIO_Number_33
#define M1_I2C_SDA_MODE       GPIO_32_Mode_SDDA
#define M1_I2C_SCL_MODE       GPIO_33_Mode_SCLA

// ������ƫ��
#define M1_CUR_U_OFFSET       (2044.81641)
#define M1_CUR_V_OFFSET       (2040.57422)
#define M1_CUR_W_OFFSET       (2048.00000)
#define M1_CUR_BUS_OFFSET     (2048.00000)
#define M1_VOLT_U_OFFSET      (2048.00000)
#define M1_VOLT_V_OFFSET      (2048.00000)
#define M1_VOLT_W_OFFSET      (2048.00000)
#define M1_VOLT_BUS_OFFSET    (2048.00000)
#define M1_VOLT_CAP_OFFSET    (2048.00000)

// ����������
#define M1_VOLT_05V_RANGE     (9.9132264529058110)  //!< �ź�ȱʡʱ������Ϊ(5.00000)
#define M1_VOLT_12V_RANGE     (23.139679358717434)  //!< �ź�ȱʡʱ������Ϊ(12.0000)
#define M1_VOLT_24V_RANGE     (24.000000000000000)  //!< �ź�ȱʡʱ������Ϊ(24.0000)
#define M1_VOLT_POT1_RANGE    (6.0500000000000000)  //!< �ź�ȱʡʱ������Ϊ(5.00000)

// ADCͨ���ź�ӳ��
#define M1_CUR_U        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_1)
#define M1_CUR_V        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_2)
#define M1_CUR_W        (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_CUR_BUS      (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_VOLT_U       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_4)
#define M1_VOLT_V       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_5)
#define M1_VOLT_W       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_6)
#define M1_VOLT_BUS     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_8)
#define M1_VOLT_CAP     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_7)
#define M1_VOLT_05V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_12)
#define M1_VOLT_12V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_14)
#define M1_VOLT_24V     (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_VOLT_POT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_13)
#define M1_TEMP_INV1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_9)
#define M1_TEMP_INV2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_9)
#define M1_TEMP_INV3    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_9)
#define M1_TEMP_MOT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_10)
#define M1_TEMP_MOT2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_10)

// GPIO�ź�ӳ��
#define HAL_Pwm_BUF1_En(halHandle)        {;}
#define HAL_Pwm_BUF1_Dis(halHandle)       {;}

#define HAL_Pwm_BUF2_En(halHandle)        {;}
#define HAL_Pwm_BUF2_Dis(halHandle)       {;}

#define HAL_Pwm_POWER_En(halHandle)       {;}
#define HAL_Pwm_POWER_Dis(halHandle)      {;}

#define HAL_Pwm_ShutDown_En(halHandle)    GPIO_setLow(halHandle->gpioHandle,GPIO_Number_7)
#define HAL_Pwm_ShutDown_Dis(halHandle)   GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_7)

#define HAL_Coder_RST_En(halHandle)       GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_11)  //!< ��
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
#define HAL_Pwm_Fault1(halHandle)         (0)  //!< �ź�ȱʡʱ,����Ϊ(0),�޹���
#define HAL_Pwm_Fault2(halHandle)         (0)  //!< �ź�ȱʡʱ,����Ϊ(0),�޹���
#define HAL_Pwm_Fault3(halHandle)         (0)  //!< �ź�ȱʡʱ,����Ϊ(0),�޹���
#define HAL_DRV1_ST(halHandle)            (0)  //!< �ź�ȱʡʱ,����Ϊ(0),�޹���
#define HAL_DRV2_ST(halHandle)            (0)  //!< �ź�ȱʡʱ,����Ϊ(0),�޹���

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
