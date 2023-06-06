// ================================================================================================
//! \file       CTRL_EVCBD_02M.h
//! \brief      ������EVCBD_02Mԭ��ͼ(��IGBT���²ɼ�)
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017��4��12��
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

#define INVTEMP_TYPE     3                          //!< ������¶Ȳɼ� 1��NTC473��·1 2:NTC473��·2 3:IGBT���£�1��0���� 4��IGBT���£�1.5����
#define MOTTEMPTYPE      1                          //!< ����¶Ȳɼ�  1��PT100��·1 2��PT100d��·2
#define CUR_SEN_TYPE     CUR_SEN_noneU_plusV_plusW  //!< ��������������[   +V +W]
#define CUR_RANGE        15840                      //!< ���������������̷�Χ 0.1A ==> 400S 400A��ķ��31680��200A��ķ��15840
#define CURBUS_RANGE     0                          //!< ĸ�ߵ��������������̷�Χ  0=û��ĸ�ߵ���������
#define VOLTBUS_RANGE    9380                       //!< ĸ�ߵ�ѹ�����̷�Χ     0.1V ������
#define VOLTCAP_RANGE    9380                       //!< ���ݵ�ѹ�����̷�Χ     0.1V ������
#define VOLT_MAX         7500                       //!< ����������ѹ              0.1V
#define CUR_MAX          5500                       //!< ������������              0.1A

// ģ��ӳ��
#define M1_SPI_HANDLE    halHandle->spiAHandle              //!< SPI�ӿ�
#define M1_QEP_HANDLE    halHandle->qepHandle[HAL_Qep_QEP2] //!< QEP�ӿ�
#define M1_SCI_HANDLE    halHandle->sciHandle[SCI_MODULE_B] //!< SCI�ӿ�
#define M1_CAN_HANDLE    halHandle->canAHandle              //!< CAN�ӿ�
#define M1_I2C_HANDLE    halHandle->i2cHandle               //!< I2C�ӿ�
#define M1_I2C_SDA_GPIO  GPIO_Number_28                     //!< I2C_SDA GPIO
#define M1_I2C_SCL_GPIO  GPIO_Number_29                     //!< I2C_SCL GPIO
#define M1_I2C_SDA_MODE  GPIO_28_Mode_SDDA                  //!< GPIOģʽ
#define M1_I2C_SCL_MODE  GPIO_29_Mode_SCLA                  //!< GPIOģʽ

// ������ƫ��
#define M1_CUR_U_OFFSET    (2048.0)              //!< U�����Ĭ��ƫ��AD
#define M1_CUR_V_OFFSET    (2048.0)              //!< V�����Ĭ��ƫ��AD
#define M1_CUR_W_OFFSET    (2048.0)              //!< W�����Ĭ��ƫ��AD
#define M1_CUR_BUS_OFFSET  (2048.0)              //!< ĸ�ߵ���Ĭ��ƫ��AD

// ����������
#define M1_VOLT_05V_RANGE  (5.0000000000000000)  //!< �ź�ȱʡʱ������Ϊ(5.00000)
#define M1_VOLT_12V_RANGE  (20.603370786516855)  //!< �ź�ȱʡʱ������Ϊ(12.0000)
#define M1_VOLT_24V_RANGE  (40.945631067961159)  //!< �ź�ȱʡʱ������Ϊ(24.0000)
#define M1_VOLT_POT1_RANGE (5.00000)             //!< �ź�ȱʡʱ������Ϊ(5.00000)

// ADCͨ���ź�ӳ��
#define M1_CUR_U        (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_CUR_V        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_1)
#define M1_CUR_W        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_2)
#define M1_CUR_BUS      (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_VOLT_U       (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_VOLT_V       (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_VOLT_W       (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_VOLT_BUS     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
#define M1_VOLT_CAP     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
#define M1_VOLT_05V     (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_VOLT_12V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_5)
#define M1_VOLT_24V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_4)
#define M1_VOLT_POT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_8)
#define M1_TEMP_INV1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_9)
#define M1_TEMP_INV2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_10)
#define M1_TEMP_INV3    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_11)
#define M1_TEMP_MOT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_12)
#define M1_TEMP_MOT2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_13)


// GPIO�ź�ӳ��
#define HAL_Pwm_BUF1_En(halHandle)        GPIO_setLow(halHandle->gpioHandle,GPIO_Number_55)
#define HAL_Pwm_BUF1_Dis(halHandle)       GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_55)

#define HAL_Pwm_BUF2_En(halHandle)        GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_56)
#define HAL_Pwm_BUF2_Dis(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_56)

#define HAL_Pwm_POWER_En(halHandle)       GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_6)
#define HAL_Pwm_POWER_Dis(halHandle)      GPIO_setLow(halHandle->gpioHandle,GPIO_Number_6)

#define HAL_Pwm_ShutDown_En(halHandle)    GPIO_setLow(halHandle->gpioHandle,GPIO_Number_7)
#define HAL_Pwm_ShutDown_Dis(halHandle)   GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_7)  //!< ��������ʱDis

#define HAL_Coder_RST_En(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_20)
#define HAL_Coder_RST_Dis(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_20)  //!< ��������ʱDis

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
