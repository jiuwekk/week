// ================================================================================================
//! \file       CTRL_HP1_LOGIC.h
//! \brief      ������˫оƬԭ��ͼ
//! \author     ������
//! \version    1.0.0
//! \date       2021��12��29��
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
#define USE_4C           6                          //!< ����Ϊ1��ʹ��4C��ǣ�Ϊ0��ʹ�ñ�ƽ������;
                                                    //       2:ʹ�����һ;3:˫оƬ;4:20Kw��оƬ���ǵ�600A;
                                                    //       5:20Kw��оƬ500A;6:20Kw��оƬ400A
#define INVTEMP_TYPE     5                          //!< ������¶Ȳɼ� 1��NTC473��·1
                                                    //             2:NTC473��·2
                                                    //             3:IGBT���£�1��0����
                                                    //             4��IGBT���£�1.5����
                                                    //             5:˫оƬ_�����ư�  ��  20Kw��оƬ
#define MOTTEMPTYPE      4                          //!< ����¶Ȳɼ�  1��PT100��·1 2��PT100d��·2 4��PWM����Դ
#if  USE_4C == 1
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< ��������������[+U    +W]
    #define CUR_RANGE        31680                      //!< ���������������̷�Χ 0.1A ==> 400S
#elif USE_4C == 2
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< ��������������[+U    +W]
    #define CUR_RANGE        22000                      //!< ���������������̷�Χ 0.1A ==> 800M(800A==>2V)
#elif USE_4C == 3
    #define CUR_SEN_TYPE     CUR_SEN_mnusU_noneV_mnusW  //!< ��������������[-U    -W]
    #define CUR_RANGE        14760//10200                      //!< ���������������̷�Χ 0.1A (600A/500A)==> 900M(900A==>2V)
#elif USE_4C == 4
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< ��������������[+U    +W]
    #define CUR_RANGE        14760                      //!< ���������������̷�Χ6000 * 0.1A
#elif USE_4C == 5
    #define CUR_SEN_TYPE     CUR_SEN_mnusU_noneV_mnusW  //!< ��������������[-U    -W]
    #define CUR_RANGE        10200                      //!< ���������������̷�Χ 4000 * 0.1A
#elif USE_4C == 6
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< ��������������[+U    +W]
    #define CUR_RANGE        10200                      //!< ���������������̷�Χ 4000 * 0.1A
#else
    #define CUR_SEN_TYPE     CUR_SEN_mnusU_noneV_mnusW  //!< ��������������[-U    -W]
    #define CUR_RANGE        22000               //!< ���������������̷�Χ 0.1A ==> 900M(900A==>2V)
#endif

#define CURBUS_RANGE     0                          //!< ĸ�ߵ��������������̷�Χ  0=û��ĸ�ߵ���������
#define VOLTBUS_RANGE    11050                       //!< ĸ�ߵ�ѹ�����̷�Χ     0.1V ������
#define VOLTCAP_RANGE    11050                       //!< ���ݵ�ѹ�����̷�Χ     0.1V ������
#define VOLPHASE_RANGE    5500                       //!< ���ߵ�ѹ�����̷�Χ     0.1V ������
#define VOLT_MAX         7500                       //!< ����������ѹ              0.1V
#define CUR_MAX          5500                       //!< ������������              0.1A

//===================================1.ģ��ӳ��=============================================//
#define M1_SPI_HANDLE    halHandle->spiAHandle              //!< QEP-SPI�ӿ�
//#define M1_SPIB_HANDLE   halHandle->spiBHandle              //!< SPI�ӿ�
#define M1_QEP_HANDLE    halHandle->qepHandle[HAL_Qep_QEP1] //!< QEP�ӿ�
#define M1_SCI_HANDLE    halHandle->sciHandle[SCI_MODULE_B] //!< SCI�ӿ�
#define M1_CAN_HANDLE    halHandle->canAHandle              //!< CAN�ӿ�
#define M1_I2C_HANDLE    halHandle->i2cHandle               //!< I2C�ӿ�
#define M1_I2C_SDA_GPIO  GPIO_Number_28                     //!< I2C_SDA GPIO
#define M1_I2C_SCL_GPIO  GPIO_Number_29                     //!< I2C_SCL GPIO
#define M1_I2C_SDA_MODE  GPIO_28_Mode_SDDA                  //!< GPIOģʽ
#define M1_I2C_SCL_MODE  GPIO_29_Mode_SCLA                  //!< GPIOģʽ
//===================================2.ADͨ��=============================================//
//1.�����   ADCͨ���ź�ӳ��
#define M1_CUR_U        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_0)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_CUR_V        (2048)
#define M1_CUR_W        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_8)
#define M1_CUR_BUS      (4096)
//2.ĸ�ߵ�ѹ
#define M1_VOLT_BUS     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_10)//ADC_ResultNumber_10
#define M1_VOLT_CAP     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_10)//ADC_ResultNumber_10
//3.�߼���ѹ
#define M1_VOLT_05V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_7)
#define M1_VOLT_05V_out ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_6)
#define M1_VOLT_12V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_5)
#define M1_VOLT_15V     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_4)
#define M1_VOLT_24V     (4096)
//4.IGBT�¶�
#define M1_TEMP_INV1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
#define M1_TEMP_INV2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
#define M1_TEMP_INV3    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
//5.����¶�
#define M1_TEMP_MOT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_11)
#define M1_TEMP_MOT2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_12)
#define M1_TEMP_NTC     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_15)
//6.�˿�ģ�����ɼ�
#define ACCEL_A_AD      ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_14)
#define ACCEL_B_AD      ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_13)
#define M1_VOLT_POT1    (4096)//
#define M1_VOLT_POT2    (4096)//
#define M1_VOLT_POT3    (4096)//
//7.�����ѹ�ɼ�
#define M1_VOLT_U       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_1)
#define M1_VOLT_V       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_9)
#define M1_VOLT_W       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_2)

//===================================3.AD����=============================================//
// ������ƫ��
#define M1_CUR_U_OFFSET    (2048.0)              //!< U�����Ĭ��ƫ��AD
#define M1_CUR_V_OFFSET    (2048.0)              //!< V�����Ĭ��ƫ��AD
#define M1_CUR_W_OFFSET    (2048.0)              //!< W�����Ĭ��ƫ��AD
#define M1_CUR_BUS_OFFSET  (2048.0)              //!< ĸ�ߵ���Ĭ��ƫ��AD

// ����������
#define M1_VOLT_05V_RANGE  (6.600)  //!< �ź�ȱʡʱ������Ϊ(5.00000)
#define M1_VOLT_12V_RANGE  (34.38216433)  //!< �ź�ȱʡʱ������Ϊ(12.0000)
#define M1_VOLT_24V_RANGE  (24.0000)//(41.52879612)  //!< �ź�ȱʡʱ������Ϊ(24.0000)
#define M1_VOLT_POT1_RANGE (4.986373)  //!< �ź�ȱʡʱ������Ϊ(5.00000)

//===================================4.GPIO����=============================================//
//1.LED ����
#define HAL_LED1_on(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_32)
#define HAL_LED1_off(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_32)
#define HAL_LED1_toggle(halHandle)       GPIO_toggle(halHandle->gpioHandle,GPIO_Number_32)

#define HAL_LED2_on(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_33)
#define HAL_LED2_off(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_33)
#define HAL_LED2_toggle(halHandle)       GPIO_toggle(halHandle->gpioHandle,GPIO_Number_33)

// GPIO�ź�ӳ��
//2.Buffer����оƬʹ��
#define HAL_Pwm_BUF1_En(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_16)
#define HAL_Pwm_BUF1_Dis(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_16)
//ֻ��һ��BUF1_EN
#define HAL_Pwm_BUF2_En(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_16)
#define HAL_Pwm_BUF2_Dis(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_16)
//3.IGBTʹ�ܸ�λ
#define HAL_Pwm_POWER_En(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_6)
#define HAL_Pwm_POWER_Dis(halHandle)     GPIO_setLow(halHandle->gpioHandle,GPIO_Number_6)

#define HAL_Pwm_ShutDown_En(halHandle)   GPIO_setLow(halHandle->gpioHandle,GPIO_Number_7)
#define HAL_Pwm_ShutDown_Dis(halHandle)  GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_7)  //!< ��������ʱDis

//4.�߱�����
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
//5.�߼���Դ
//HOLD_Power ����
#define HAL_KEEP_POWER_En(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_15)
#define HAL_KEEP_POWER_Dis(halHandle)     GPIO_setLow(halHandle->gpioHandle,GPIO_Number_15)
//KSI_TEST Կ�� ����״̬
#define HAL_KSI_SW(halHandle)            (!GPIO_read(halHandle->gpioHandle,GPIO_Number_24))
//B+_TEST  ����
#define HAL_B_SW(halHandle)             (!GPIO_read(halHandle->gpioHandle,GPIO_Number_14))

//6.IGBT״̬
#define HAL_Pwm_Fault1(halHandle)        (!GPIO_read(halHandle->gpioHandle,GPIO_Number_8))
#define HAL_Pwm_Fault2(halHandle)        (!GPIO_read(halHandle->gpioHandle,GPIO_Number_9))
#define HAL_Pwm_Fault3(halHandle)        (!GPIO_read(halHandle->gpioHandle,GPIO_Number_10))

//7.AD2S1205�����ѹ��  RDC_LOT ��ʧ
#define HAL_Coder_Err(halHandle)         (!GPIO_read(halHandle->gpioHandle,GPIO_Number_27))
//�źŵĶ�ʧ
#define HAL_RDC_Dos(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_26))

//����оƬ��λ 0����Ч
#define RDC_RST_En(halHandle)             GPIO_setLow(halHandle->gpioHandle,GPIO_Number_52)
#define RDC_RST_Dis(halHandle)            GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_52)
//�������     1->0ת��
#define RDC_SAMPLE_H(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_13)
#define RDC_SAMPLE_L(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_13)
//1:λ��  0:�ٶ�
#define RDC_RDVEL_LOC(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_58)
#define RDC_RDVEL_SPD(halHandle)          GPIO_setLow(halHandle->gpioHandle,GPIO_Number_58)
//�������ʹ��  1->0ת�� ����
#define RDC_RD_H(halHandle)               GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_44)
#define RDC_RD_L(halHandle)               GPIO_setLow(halHandle->gpioHandle,GPIO_Number_44)

//8.����������
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
