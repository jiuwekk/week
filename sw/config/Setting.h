// ================================================================================================
//! \file       Setting.h
//! \brief      
//! \author     xjh
//! \version    1.0.0
//! \date       2019��11��07��
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _SETTING_H_
#define _SETTING_H_

//! @defgroup CONFIG CONFIG
//! @{

#ifdef __cplusplus
extern "C" {
#endif
/*
 * ���������޸ļ�¼��
 * 2021-4-8����Debug����ѭ�������з��͵Ĵ���Ž�DbgDataԴ�ļ���Ӧλ���У��������ط��ظ����ַ��ʹ��룬�����޸������
 * 2021-4-8����������ݷ�������ѭ���еĴ���Ż�SanProtԴ�ļ��У�����ദ���ַ��ͳ��������������޸������
 * 2021-4-8����ProtFunc�ļ����г�SanProt������ļ�ɾ��
 * 2021-4-8����Ӷ���֮һ�������ܣ�ͨ��settingͷ�ļ���Single_or_Double�궨��ȥʵ��
 * 2021-4-8���������λ����ͼ��������ID���ܣ�ͨ��settingͷ�ļ���New_Mon_Test�궨��ȥѡ����λ��
 * 2021-4-8���ײ�����ģ������궨����
 * 2021-4-19�����FDCϵ�л����ư�ͷ�ļ�
 * 2021-4-21����ȫ����FDCϵ�л����ư�
 * 2021-4-23����ӵ���ѻ����ƺ궨��Loose_DM,������ѻ�״̬,��ѹ���̶�404V,�������Ϊ0
 * 2021-7-8:����05XB������ư�
 * 2021-8-6:�ԽӰ����ص�Ħ��������ʽЭ��,���CRC8У��,��ӹ��������
 * 2021-8-21:�޸ĳ�500K������
 * 2022-8-18:���ӵ���ЧIO�ڼ�⣬ֱ�ӿ����л�ת��ģʽ500rpm
 * 2023-3-14:�����ϵ��Լ죬ȱ���������
 */
    #define VER_CHARS "M_MOT_KS126KW_103_IGBT600A_2901500Nm_M3_2.13_2.02_V1.004"//"M_MOT_1707_SH85_0101"
//                ����-���-���ư�-���ϴ���-����-�汾
/*
 *  V1.001 �޸�ȱ�ౣ�����ƺ���Чʱ�䣬����ѭ��ʱ�����ӵ�2ms
 *  V1.002 ��ȱ�ౣ������������0.05
 *  V1.003 ���߿�·���������ݴ�0.006������0.001,���ӿ���֡פ�µ�λ��Ϣ
 *  V1.004 פ��ģʽ�޸�Ϊ������ļӼ��٣����ӱ�Ƶ��פ�¶�ת�ж�
 *
 */
// ================================================================================================
/*���� ���һ������ ģ�� ����ģ��
 * #define MOTOR_ID                   (0x0C)  //!< ���� 30Kw 500Nm ���
 * #define EVCBD_ID                   (0x05)  //!< EVCONTROLBOARD-107Z ���һ�͹��ʿ�����
 * #define FUNCVER                    (0x06)  //!< ���ܰ汾
*/

/*���� ϵ�л������� ģ�� ����ģ��
 * #define MOTOR_ID                   (0x0C)  //!< ���� 30Kw 500Nm ���
 * #define EVCBD_ID                   (0x07)  //!< LV-MCU-101,2.5��������������
 * #define FUNCVER                    (0x06)  //!< ���ܰ汾
*/
// ================================================================================================
// MOTOR ID
//#define MOTOR_ID                   (0x01)  //!< 8.5m�������ֵŤ��1700Nm,350A  390-180
//#define MOTOR_ID                   (0x02)  //!< 8.5M�������ֵŤ��2000Nm,480A
//#define MOTOR_ID                   (0x03)  //!< 10.5m�������ֵŤ��2500Nm,370A
//#define MOTOR_ID                   (0x04)  //!< 10.5m�������ֵŤ��2800Nm,430A
//#define MOTOR_ID                   (0x05)  //!< 290_169,ֱ��,1000Nm
//#define MOTOR_ID                   (0x06)  //!< 290_169,б��,1000Nm
//#define MOTOR_ID                   (0x07)  //!< 290_262 1700Nm
//#define MOTOR_ID                   (0x08)  //!< 390_213,2500Nm
//#define MOTOR_ID                   (0x09)  //!< ����390���
//#define MOTOR_ID                   (0x0A)  //!< ����ǣ�������
//#define MOTOR_ID                   (0x0B)  //!< ���� 30Kw 200Nm ���
//#define MOTOR_ID                   (0x0C)  //!< ���� 30Kw 500Nm ���
//#define MOTOR_ID                   (0x0D)  //!< ���� 500Nm ��� ����
//#define MOTOR_ID                   (0x0e)  //!< 220�⹦��������Եĳ���
//#define MOTOR_ID                   (0x0f)  //!< 220-p2�⹦��������Եĳ���
//#define MOTOR_ID                   (0x11)  //!< ���մ�
//#define MOTOR_ID                   (0x13)  //!< ̫����155�������
//#define MOTOR_ID                   (0x14)  //!< ���Ʒ���180�������
//#define MOTOR_ID                   (0x15)  //!< XP50�������
//#define MOTOR_ID                   (0x16)  //!< 290-262����������Ƴ���
//#define MOTOR_ID                   (0x17)  //!< SH85
//#define MOTOR_ID                   (0x18)  //!< SH86
//#define MOTOR_ID                   (0x19)  //!< MotParm_Rmeax1000Nm
//#define MOTOR_ID                   (0x1A)  //!< 290_262_1000_N
//#define MOTOR_ID                   (0x20)  //MotParm_SH61
//#define MOTOR_ID                   (0x21)  // MotParm390,2000Nm
//#define MOTOR_ID                   (0x22)  //MotParm_HD55KW_MOT
#define MOTOR_ID                   (0x23)  //MotParm_EV290_1500
//#define MOTOR_ID                   (0x24)  //MotParm_YD220_MOT

// ================================================================================================
// Hardware type
//#define EVCBD_ID                   (0x01)  //!< RLESS-LOGIC-01-01,����һ������
//#define EVCBD_ID                   (0x02)  //!< EVCONTROLBOARD-104M
//#define EVCBD_ID                   (0x03)  //!< EVCBD-01M(��ķ��)
//#define EVCBD_ID                   (0x04)  //!< EVCBD-02M(��ĸ������IGBT�¶Ȳɼ�)
//#define EVCBD_ID                   (0x05)  //!< EVCONTROLBOARD-107Z ���һ�͹��ʿ�����
//#define EVCBD_ID                   (0x06)  //!< EVCONTROLBOARD-105Z ���һ�͹��ʿ�����
#define EVCBD_ID                   (0x07)  //!< LV-MCU-101,2.5��������������   ����102��103
//#define EVCBD_ID                   (0x08)  //!< CTRL_FDC_M_01, ϵ�л��������߼���
//#define EVCBD_ID                   (0x09)  //!< 05XB,�泵S������
//#define EVCBD_ID                   (0x0A)  //!< M_PMS_02,�泵M������
//#define EVCBD_ID                   (0x0D)  //!< CTRL_HP1_LOGIC�ɻ����������
//
// ================================================================================================
// Coustomer ID
#define COUST_ID                   (0x00) //!< ����
//#define COUST_ID                   (0x01) //!< ����
//#define COUST_ID                   (0x02) //!< ��ͨ
//#define COUST_ID                   (0x03) //!< ���ݽ���
//#define COUST_ID                   (0x04) //!< �Ͼ�����
//#define COUST_ID                   (0x05) //!< ��ͨ
//#define COUST_ID                   (0x06) //!< �ƺ�
//#define COUST_ID                   (0x07) //!< ����
//#define COUST_ID                   (0x08) //!< �ɳ�
//#define COUST_ID                   (0x09) //!< ����
//#define COUST_ID                   (0x0a) //!< ����
//#define COUST_ID                   (0x0b) //!< ��ͨ
//#define COUST_ID                   (0x0c) //!< ����
//#define COUST_ID                   (0x0d) //!< Դ��������������
//#define COUST_ID                   (0x0e) //!< ����
//#define COUST_ID                   (0x0f) //!< ���ӽ�
//#define COUST_ID                   (0x10) //!< ���ǵ�
//#define COUST_ID                   (0x12) //!< ��¡
//#define COUST_ID                   (0x13) //!< Ϋ��
//#define COUST_ID                   (0x14) //!< ��������
//#define COUST_ID                   (0x15) //!< �в�
//#define COUST_ID                   (0x16) //!< ��ݸ�ݾ�
//#define COUST_ID                   (0x17) //!< ��������Դ
//#define COUST_ID                   (0x1c) //!< �Ϻ�����
//#define COUST_ID                   (0x1d) //!< ����
//#define COUST_ID                   (0x1e) //!< ����
//#define COUST_ID                   (0x1f) //!< ������̫���ܳ�

#define FUNCVER                    (0x00) //!< ���ܰ汾
#define PROTTYPE                   (0x00) //!< Э������  ������Э��0:���� 1�����أ�
#define PROTVER                    (0x00) //!< Э��汾
#define PROTUPCOMM                 (0x00) //!< ��λ��Э�� 0������ 1������

// ================================================================================================
// PARMVER
#define PARMVER                    ((MOTOR_ID << 8) | EVCBD_ID)

#define Modle_or_Handecode         1          //����ģ�ͻ�����д����.1:����ģ��;0:������д

#define Single_or_Double           2          //��������¡�1�����������¡�2˫����˫���¡�3����������֮һ����
#define Soft_Version               1          //����汾�š�1��ʹ������汾�š�0��ʹ��Ӳ���汾��
#define New_Mon_Test               1          //1��ִ�л�ͼ��������λ�����Գ���Ρ�0����ִ�л�ͼ��������λ�����Գ���Σ�����1.6.6�汾��λ�����ɷ����ͼ
#define Watch_TripleIndex          1          //��ص�������������.1:����\0:������(��λ������ʶ��,ֻ�Ǳ��ͬ)
#define Loose_DM                   0//1          //������״̬.1:������,��һЩ��ѹ�����Ȳ���д��\0:���ڵ��
#if COUST_ID == (0x1f)
    #if EVCBD_ID == 0x09
        #define XB05_Precharge_En          0          //05XB���ư�Ԥ�书�ܿ���.1:��Ԥ�书��;0:û��Ԥ�书��
        #define Pre_PWM_Hight_Duty       1.0        //Ԥ�����PWMռ�ձ����������.1:1-duty=0Ϊ0%(��);0:1-duty=1Ϊ0%(��)
    #else
        #define XB05_Precharge_En          0          //05XB���ư�Ԥ�书�ܿ���.1:��Ԥ�书��;0:û��Ԥ�书��
    #endif
    #define Err_Code_En            1          // �������ù�����
#endif
// ================================================================================================
// the includes
/////////////////////////////////////////////////////////////////
#if MOTOR_ID == 0x01
    #include"sw/config/MotorParm/MotParm_EV8M5.h"
#elif MOTOR_ID == 0x02
    #include"sw/config/MotorParm/MotParm_EV8M5_430A.h"
#elif MOTOR_ID == 0x03
    #include"sw/config/MotorParm/MotParm_EV10M5.h"
#elif MOTOR_ID == 0x04
    #include"sw/config/MotorParm/MotParm_EV10M5_430A.h"
#elif MOTOR_ID == 0x05
    #include"sw/config/MotorParm/MotParm_EV290_169_Z.h"
#elif MOTOR_ID == 0x06
    #include"sw/config/MotorParm/MotParm_EV290_169_X.h"
#elif MOTOR_ID == 0x07
    #include"sw/config/MotorParm/MotParm_EV290_262.h"
#elif MOTOR_ID == 0x08
    #include"sw/config/MotorParm/MotParm_EV390_213.h"
#elif MOTOR_ID == 0x09
    #include"sw/config/MotorParm/MotParm_EV390_MH.h"
#elif MOTOR_ID == 0x0A
    #include"sw/config/MotorParm/MotParm_TZ210XS30H_310HC.h"
#elif MOTOR_ID == 0x0C
    #include"sw/config/MotorParm/MotParm_JT500N.h"
#elif MOTOR_ID == 0x0D
    #include"sw/config/MotorParm/MotParm_JT_Test.h"
#elif MOTOR_ID == 0x0e
    #include"sw/config/MotorParm/MotParm_POWER220_Test.h"
#elif MOTOR_ID == 0x0f
    #include"sw/config/MotorParm/MotParm_POWER220_P2_Test.h"
#elif MOTOR_ID == 0x11
    #include"sw/config/MotorParm/MotParm_SUNCAR_Test.h"
#elif MOTOR_ID == 0x13
    #include"sw/config/MotorParm/MotParm_SUNCAR_155.h"
#elif MOTOR_ID == 0x14
    #include"sw/config/MotorParm/MotParm_FB180_MOT.h"
#elif MOTOR_ID == 0x15
    #include"sw/config/MotorParm/MotParm_XP50_Test.h"
#elif MOTOR_ID == 0x16
    #include"sw/config/MotorParm/MotParm_EV290_262_1700.h"
#elif MOTOR_ID == 0x17
    #include"sw/config/MotorParm/MotParm_SH85.h"
#elif MOTOR_ID == 0x18
    #include"sw/config/MotorParm/MotParm_SH86125A.h"
#elif MOTOR_ID == 0x19
    #include"sw/config/MotorParm/MotParm_Rmeax1000Nm.h"
#elif MOTOR_ID == 0x1A
    #include"sw/config/MotorParm/MotParm_EV290N.h"
#elif MOTOR_ID == 0x20
    #include"sw/config/MotorParm/MotParm_SH61.h"
#elif MOTOR_ID == 0x21
    #include"sw/config/MotorParm/MotParm_390_2000Nm.h"
#elif MOTOR_ID == 0x22
    #include"sw/config/MotorParm/MotParm_HD55KW_MOT.h"
#elif MOTOR_ID == 0x23
    #include"sw/config/MotorParm/MotParm_EV290_1500Nm.h"
#elif MOTOR_ID == 0x24
    #include"sw/config/MotorParm/MotParm_YD220_MOT.h"
#endif





/////////////////////////////////////////////////////////////////////
#if EVCBD_ID == 0x01
    #include"sw/config/CtrlBoard/CTRL_RLESS_LOGIC_01.h"
#elif EVCBD_ID == 0x02
    #include"sw/config/CtrlBoard/CTRL_EVCBD_104M.h"
#elif EVCBD_ID == 0x03
    #include"sw/config/CtrlBoard/CTRL_EVCBD_01M.h"
#elif EVCBD_ID == 0x04
    #include"sw/config/CtrlBoard/CTRL_EVCBD_02M.h"
#elif EVCBD_ID == 0x05
    #include"sw/config/CtrlBoard/CTRL_EVCBD_107Z.h"
#elif EVCBD_ID == 0x06
    #include"sw/config/CtrlBoard/CTRL_EVCBD_105Z.h"
#elif EVCBD_ID == 0x07
    #include"sw/config/CtrlBoard/CTRL_LV_MCU_101.h"
#elif EVCBD_ID == 0x08
    #include"sw/config/CtrlBoard/CTRL_FDC_M_01.h"
#elif EVCBD_ID == 0x09
    #include"sw/config/CtrlBoard/S_CTRL_05XB.h"
#elif EVCBD_ID == 0x0A
    #include"sw/config/CtrlBoard/M_PMS_02.h"
#elif EVCBD_ID == 0x0D
    #include"sw/config/CtrlBoard/CTRL_HP1_LOGIC.h"
#endif

/////////////////////////////////////////////////////////////////


#define ASCCONDSPD  1000     // ASC��������ת��ֵ


#define SLOPERUNTMTHR  3000  // פ������ʱ��3s
#define SLOPESTOPTMTHR 1000  // פ��ֹͣʱ��1s
#define SLOPERUNPROD   3     // פ���������� 3��

#define INITTIME   1000    //!< ��Ƭ������ͨѶ�󣬳�ʼ��ʱ�� ms ��С50ms

// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of

#endif // end of _SETTING_H_
