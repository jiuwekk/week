// ================================================================================================
//! \file       FDC_M_01.h
//! \brief      ������FDC_M_01ԭ��ͼ
//! \author     JK
//! \version    1.0.0
//! \date       2020��05��26��
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
#define INVTEMP_TYPE     6                          //!< ������¶Ȳɼ� 1��NTC473��·1 2:NTC473��·2 3:IGBT���£�1��0���� 4��IGBT���£�1.5����;5:05XB
#define MOTTEMPTYPE      4                          //!< ����¶Ȳɼ�  1��PT100��·1 2��PT100d��·2 4��PWM����Դ;6:05XB˫·����Դ�л�
#define USE_4C           4                          //!< ����Ϊ1��ʹ��4C��ǣ�Ϊ0��ʹ�ñ�ƽ������; 2:ʹ�����һ;4:ʹ��05XB����������
#define USE_HALL_CURSEN  1                          //!< 6:05Xb:ʹ�û������������� 2019.10.12 �³�������   1����Ч 0:�ϰ����������
#if  USE_4C == 1
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< ��������������[+U    +W]
    #define CUR_RANGE        31680                      //!< ���������������̷�Χ 0.1A ==> 400S
#elif USE_4C == 2
    #define CUR_SEN_TYPE     CUR_SEN_plusU_noneV_plusW  //!< ��������������[+U    +W]
    #define CUR_RANGE        22000                      //!< ���������������̷�Χ 0.1A ==> 800M(800A==>2V)
#elif USE_4C == 4
    #if USE_HALL_CURSEN == 1
        #define CUR_SEN_TYPE     CUR_SEN_mnusU_mnusV_noneW  //!< ��������������[-U  -V    ]
        #define CUR_RANGE     12800                      //!< ���������������̷�Χ
    #elif USE_HALL_CURSEN == 0
        #define CUR_SEN_TYPE     CUR_SEN_plusU_plusV_noneW  //!< ��������������[+U  +V    ]
        #define CUR_RANGE      20200                      //!< ���������������̷�Χ
    #endif
#else
    #define CUR_SEN_TYPE     CUR_SEN_mnusU_noneV_mnusW  //!< ��������������[-U    -W]
    #define CUR_RANGE        22000                      //!< ���������������̷�Χ 0.1A ==> 900M(900A==>2V)
#endif

#define CURBUS_RANGE     0                          //!< ĸ�ߵ��������������̷�Χ  0=û��ĸ�ߵ���������
#define VOLTBUS_RANGE    3100                       //!< ĸ�ߵ�ѹ�����̷�Χ     0.1V ������
#define VOLTCAP_RANGE    3100                       //!< ���ݵ�ѹ�����̷�Χ     0.1V ������
#define VOLT_MAX         3100                        //!< ����������ѹ              0.1V
#define CUR_MAX          4000                       //!< ������������              0.1A

#define Fan_Work_Vol           24         //���ȹ�����ѹ
#define PWM_Num_Fan            1          //������1��PWM��
#define PWM_Num_MainRelay      3          //���Ӵ�����3��PWM��

//===================================1.ģ��ӳ��=============================================//
#define M1_SPI_HANDLE    halHandle->spiAHandle              //!< SPI�ӿ�
#define M1_QEP_HANDLE    halHandle->qepHandle[HAL_Qep_QEP2] //!< QEP�ӿ�
#define M1_SCI_HANDLE    halHandle->sciHandle[SCI_MODULE_B] //!< SCI�ӿ�
#define M1_CAN_HANDLE    halHandle->canAHandle              //!< CAN�ӿ�
#define M1_I2C_HANDLE    halHandle->i2cHandle               //!< I2C�ӿ�
#define M1_I2C_SDA_GPIO  GPIO_Number_28                     //!< I2C_SDA GPIO
#define M1_I2C_SCL_GPIO  GPIO_Number_29                     //!< I2C_SCL GPIO
#define M1_I2C_SDA_MODE  GPIO_28_Mode_SDDA                  //!< GPIOģʽ
#define M1_I2C_SCL_MODE  GPIO_29_Mode_SCLA                  //!< GPIOģʽ
//===================================2.ADͨ��=============================================//
//result��Ҫ��SOC�Ŷ�Ӧ,����SOC������Hal_adc�����벻ͬ��AB�ż�ͨ������
//1.�����   ADCͨ���ź�ӳ��
#define M1_CUR_U        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_1)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_CUR_V        ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_2)
#define M1_CUR_W        (4096)
#define M1_CUR_BUS      (4096)
//2.ĸ�ߵ�ѹ
#define M1_VOLT_U       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_3)
#define M1_VOLT_V       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_4)
#define M1_VOLT_W       ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_5)
#define M1_VOLT_BUS     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_6)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_VOLT_CAP     ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_7)
//3.�߼���ѹ
#define M1_VOLT_05V     (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_VOLT_12V     (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_VOLT_24V     (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
#define M1_VOLT_POT1    (4096)  //!< �ź�ȱʧʱ���趨ֵΪ4096����ֹ�󱨹���
//4.IGBT�¶�
#define M1_TEMP_INV1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_11)
#define M1_TEMP_INV2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_11)
#define M1_TEMP_INV3    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_11)
//5.����¶�
//���¿��ܿ���                            ע��ߵ���Ч
#define HAL_MOTTEMP_En1(halHandle)        GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_40)
#define HAL_MOTTEMP_Dis1(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_40)
#define HAL_MOTTEMP_En2(halHandle)        GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_16)
#define HAL_MOTTEMP_Dis2(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_16)

#define HAL_MOTTEMP_EN1(halHandle)        HAL_MOTTEMP_En1(halHandle);HAL_MOTTEMP_Dis2(halHandle)  // 280uA��·��Ч
#define HAL_MOTTEMP_EN2(halHandle)        HAL_MOTTEMP_En2(halHandle);HAL_MOTTEMP_Dis1(halHandle)  // 4.254mA��·��Ч

#define M1_TEMP_MOT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_12)
#define M1_TEMP_MOT2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_13)


//6.�˿�ģ�����ɼ�                 �ⲿģ��������,���õ�����
//#define M1_VOLT_POT1    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_12)
//#define M1_VOLT_POT2    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_13)
//#define M1_VOLT_POT3    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_14)
//#define M1_VOLT_POT4    ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_15)
//#define M1_VOLT_POT5    (4096)//ADC_readResult(halHandle->adcHandle,ADC_ResultNumber_15)

//===================================3.AD����=============================================//
// ������ƫ��                                                 ����ʵ�ʲɼ�������ֵ������ȷ����
#define M1_CUR_U_OFFSET    (2048.0)              //!< U�����Ĭ��ƫ��AD
#define M1_CUR_V_OFFSET    (2048.0)              //!< V�����Ĭ��ƫ��AD
#define M1_CUR_W_OFFSET    (2048.0)              //!< W�����Ĭ��ƫ��AD
#define M1_CUR_BUS_OFFSET  (2048.0)              //!< ĸ�ߵ���Ĭ��ƫ��AD

// ����������                                                 ����ʵ�ʲɼ�������ֵ������ȷ����
#define M1_VOLT_05V_RANGE  (5.0000000000000000)  //!< �ź�ȱʡʱ������Ϊ(5.00000)
#define M1_VOLT_12V_RANGE  (12.000000000000000)  //!< �ź�ȱʡʱ������Ϊ(12.0000)
#define M1_VOLT_24V_RANGE  (24.000000000000000)  //!< �ź�ȱʡʱ������Ϊ(24.0000)
#define M1_VOLT_POT1_RANGE (5.0000000000000000)  //!< �ź�ȱʡʱ������Ϊ(5.00000)

//===================================4.GPIO����=============================================//
//1.LED ����
#define HAL_LED1_on(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_14)
#define HAL_LED1_off(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_14)
#define HAL_LED1_toggle(halHandle)       GPIO_toggle(halHandle->gpioHandle,GPIO_Number_14)

#define HAL_LED2_on(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_15)
#define HAL_LED2_off(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_15)
#define HAL_LED2_toggle(halHandle)       GPIO_toggle(halHandle->gpioHandle,GPIO_Number_15)

// GPIO�ź�ӳ��
//2.Buffer����оƬʹ��
#define HAL_Pwm_BUF1_En(halHandle)        GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_51)   // EN-PWM
#define HAL_Pwm_BUF1_Dis(halHandle)       GPIO_setLow(halHandle->gpioHandle,GPIO_Number_51)
//ֻ��һ��BUF1_EN
#define HAL_Pwm_BUF2_En(halHandle)        {;}
#define HAL_Pwm_BUF2_Dis(halHandle)       {;}
//3.IGBTʹ�ܸ�λ
#define HAL_Pwm_POWER_En(halHandle)       {;}
#define HAL_Pwm_POWER_Dis(halHandle)      {;}

#define HAL_Pwm_ShutDown_En(halHandle)    {;}
#define HAL_Pwm_ShutDown_Dis(halHandle)   {;}

//4.�߱�����
#define HAL_DRV1_En(halHandle)            GPIO_setLow(halHandle->gpioHandle,GPIO_Number_6) // ���Ӵ����� (PWM1����)
#define HAL_DRV1_Dis(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_6)

#define HAL_DRV2_En(halHandle)            GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_43) // Ԥ��Ӵ���
#define HAL_DRV2_Dis(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_43)

#define HAL_DRV1_ST(halHandle)            (0)
#define HAL_DRV2_ST(halHandle)            (0)
//5.�߼���Դ
//HOLD_Power ����
#define HAL_KEEP_POWER_En(halHandle)      GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_54)
#define HAL_KEEP_POWER_Dis(halHandle)     GPIO_setLow(halHandle->gpioHandle,GPIO_Number_54)
//KSI_TEST Կ�� ����״̬
#define HAL_KSI_SW(halHandle)             (GPIO_read(halHandle->gpioHandle,GPIO_Number_53))

//6.IGBT״̬                         ��ȷ����û�õ�
#define HAL_Pwm_Fault1(halHandle)         (0)
#define HAL_Pwm_Fault2(halHandle)         (0)
#define HAL_Pwm_Fault3(halHandle)         (0)

//7.AD2S1205�����ѹ��  RDC_LOT ��ʧ
#define HAL_Coder_Err(halHandle)         (!GPIO_read(halHandle->gpioHandle,GPIO_Number_21))
////�źŵĶ�ʧ                         û�õ�
#define HAL_RDC_Dos(halHandle)           (!GPIO_read(halHandle->gpioHandle,GPIO_Number_27))

//����оƬ��λ 0����Ч
#define RDC_RST_En(halHandle)             GPIO_setLow(halHandle->gpioHandle,GPIO_Number_44)
#define RDC_RST_Dis(halHandle)            GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_44)
//�������     1->0ת��
#define RDC_SAMPLE_H(halHandle)           GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_39)
#define RDC_SAMPLE_L(halHandle)           GPIO_setLow(halHandle->gpioHandle,GPIO_Number_39)
//1:λ��  0:�ٶ�
#define RDC_RDVEL_LOC(halHandle)          GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_34)
#define RDC_RDVEL_SPD(halHandle)          GPIO_setLow(halHandle->gpioHandle,GPIO_Number_34)
//�������ʹ��  1->0ת�� ����
#define RDC_RD_H(halHandle)               GPIO_setHigh(halHandle->gpioHandle,GPIO_Number_50)
#define RDC_RD_L(halHandle)               GPIO_setLow(halHandle->gpioHandle,GPIO_Number_50)

////8.����������
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
