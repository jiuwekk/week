// ================================================================================================
//! \file       Globals.h
//! \brief      Ӧ�ò�ȫ�ֱ�����������ʼֵ
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017��3��23��
//! \copyright  SNATROLL.
// ================================================================================================

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

//! @defgroup GLOBALS GLOBALS
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================

extern void MainDrvStateflow(void);
extern void SflMainVoltComp(void);
extern unsigned char CRC8(unsigned char *ptr, unsigned char len);
extern unsigned char crc_high_first(unsigned char *ptr, unsigned char len);
extern unsigned char Crc8BitCalculate(void);//(unsigned char *ptr, unsigned char Len);
extern unsigned int BitCount(unsigned int n);

// ================================================================================================
// the includes

// ================================================================================================
// the defines

// ================================================================================================
// the typedefs

// --------------------------------------------------------
// ���Ͻṹ�����Ͷ���
typedef union
{
    uint16_t  All[4];
    struct
    {
        uint16_t PwrMdlErr        :1;         //(1,1)  IGBTģ�����,��������
        uint16_t CurSensorErr     :1;         //(1,2)  �����������
        uint16_t MotStallErr      :1;         //(1,3)  �����ת������
        uint16_t AcOverCur2Err    :1;         //(1,4)  �����2
        uint16_t AcOverCur1Err    :1;         //(1,5)  �����1 0Ť��
        uint16_t PreChargeErr     :1;         //(1,6)  Ԥ��ʧ��
        uint16_t PhaseBrkErr      :1;         //(1,7)  ���߿�·
        uint16_t DcOverVolt3Err   :1;         //(1,8)  ��ѹ3 ���ɻָ�

        uint16_t DcOverVolt2Err   :1;         //(2,1)  ��ѹ2 ����0Ť��
        uint16_t DcOverVolt1Err   :1;         //(2,2)  ��ѹ1
        uint16_t DcUnderVolt1Err  :1;         //(2,3)  Ƿѹ1
        uint16_t DcUnderVolt2Err  :1;         //(2,4)  Ƿѹ2 ����0Ť��
        uint16_t DcUnderVolt3Err  :1;         //(2,5)  Ƿѹ3 ���ɻָ�
        uint16_t Main_DNC_Err     :1;         //(2,6)  ���Ӵ���ѹ��
        uint16_t OverSpeed2Err    :1;         //(2,7)  ���� 2
        uint16_t DcOverCur1Err    :1;         //(2,8)  ĸ�߹���            1.1*��ֵ

        uint16_t Rsvd2            :8;         //(3,1)  Ԥ��
        uint16_t Rsvd3            :8;         //(4,1)  Ԥ��

        uint16_t OverSpeed1Err    :1;         //(5,1)  ���� 1 0Ť��
        uint16_t MotOverTemp3Err  :1;         //(5,2)  �������3       160 �ع�
        uint16_t InvOverTemp3Err  :1;         //(5,3)  ģ�����3       95 �ع�
        uint16_t LogicPowerErr    :1;         //(5,4)  24V����
        uint16_t Rsvd4_4          :1;         //(5,5)  Ԥ��
        uint16_t PosSensorErr     :1;         //(5,6)  ������Ϲع�
        uint16_t Rsvd4_6          :1;         //(5,7)  Ԥ��
        uint16_t MotOverTemp2Err  :1;         //(5,8)  �������2       140 ��Ť��

        uint16_t MotOverTemp1Err  :1;         //(6,1)  �������1       130 ������Ť��
        uint16_t InvOverTemp2Err  :1;         //(6,2)  ģ�����2       85 ��Ť��
        uint16_t InvOverTemp1Err  :1;         //(6,3)  ģ�����1       75 ������Ť��
        uint16_t MotTempSensorErr1:1;         //(6,4)  PT100#1
        uint16_t MotTempSensorErr2:1;         //(6,5)  PT100#2
        uint16_t InvTempSensorErr1:1;         //(6,6)  NTC#1
        uint16_t InvTempSensorErr2:1;         //(6,7)  NTC#2
        uint16_t InvTempSensorErr3:1;         //(6,8)  NTC#3

        uint16_t ParErr           :1;         //(7,1)  EE����
        uint16_t ParChangeErr     :1;         //(7,2)  �����޸Ĵ���
        uint16_t Msg1LostErr      :1;         //(7,3)  Vcuָ��ͨ��
        uint16_t Msg2LostErr      :1;         //(7,4)  Vcu����ͨ��
        uint16_t DisChgWarnErr    :1;         //(7,5)  �����ŵ�澯
        uint16_t DisChgOverTmErr  :1;         //(7,6)  �����ŵ糬ʱ
        uint16_t Rsvd6_6          :1;         //(7,7)  Ԥ��
        uint16_t Rsvd6_7          :1;         //(7,8)  Ԥ��

        uint16_t ErrLevel         :3;
        uint16_t Rsvd7            :5;         //(8,1)  Ԥ��
    }M3_FAULT_OBJ;
}FAULT_OBJ;

#define FAULT_OBJ_DEFAULTS {0,0,0,0}
// --------------------------------------------------------
//! �û�������
typedef struct
{
    // FaultHistory_Menu
    uint16_t FaultHis[16];     // 000 EE���ڴ洢��ʷ����
    // PowerDownSave_Menu
    uint16_t OdometerH;        // 000 ��ʻ����̸ߣ����������������ܿ���
    uint16_t OdometerL;        // 001 ��ʻ����̵ͣ����������������ܿ���
    uint16_t HourMeterH;       // 002 ����������ʱ���
    uint16_t HourMeterL;       // 003 ����������ʱ���
    uint16_t SOC;              // 004 ���������������ܿ���
    uint16_t Rsvd0[11];        // 005 - 015
    // ConstantParam_Menu
    uint16_t MfgDate1;         // 016 �������к�1
    uint16_t MfgDate2;         // 017 �������к�2
    uint16_t MfgDate3;         // 018 �������к�3
    uint16_t MfgDate4;         // 019 �������к�4
    uint16_t Rsvd020;          // 020
    uint16_t Rsvd021;          // 021
    uint16_t CurU_Range;       // 022
    uint16_t CurV_Range;       // 023
    uint16_t CurW_Range;       // 024
    uint16_t CurBus_Range;     // 025
    uint16_t Rsvd026;          // 026
    uint16_t Rsvd027;          // 027
    uint16_t Rsvd028;          // 028
    uint16_t VoltBus_Range;    // 029
    uint16_t VoltCap_Range;    // 030
    uint16_t TempCruSource;    // 031
    // Info_Menu
    uint16_t ParamBlkVersion;  // 032 �����汾
    uint16_t SoftwareVersion;  // 033 ����汾
    uint16_t HardwareVersion;  // 034 Ӳ���汾
    uint16_t ElecZero;         // 035 ������
    uint16_t MechZero;         // 036 ��е���
    uint16_t Rsvd2[11];        // 037 - 047
    // BaseValue_menu
    uint16_t VoltBase;         // 048 ��ѹ��ֵ
    uint16_t CurBase;          // 049 ������ֵ
    uint16_t SpeedBase;        // 050 ת�ٻ�ֵ
    // ModeSettings_Menu
    uint16_t CtrlMode;         // 051 ����ģʽ
    uint16_t PeakPower;        // 052 ��ֵ��������
    uint16_t DriveCurLimit;    // 053 �������Ƶ���
    uint16_t BrakeCurLimit;    // 054 �������Ƶ���
    uint16_t FwdMaxSpd;        // 055 ǰ����������
    uint16_t RevMaxSpd;        // 056 ���˷�������
    // TrqMode_Menu
    uint16_t Kp_TrqSpd;        // 057 Ť��ģʽ����ת�� Kp
    uint16_t Ki_TrqSpd;        // 058 Ť��ģʽ����ת�� Ki
    uint16_t Kp_TrqCur;        // 059 Ť��ģʽ���Ƶ��� Kp
    uint16_t Ki_TrqCur;        // 060 Ť��ģʽ���Ƶ��� Ki
    // SpdMode_Menu
    uint16_t Kp_SpdM0;         // 061 ת�ٻ�ģʽ Kp
    uint16_t Ki_SpdM0;         // 062 ת�ٻ�ģʽ Ki
    uint16_t Kp_SpdM1;         // 063 ����
    uint16_t Ki_SpdM1;         // 064 ����
    uint16_t Kp_SpdM2;         // 065 ����
    uint16_t Ki_SpdM2;         // 066 ����
    uint16_t Kp_SpdM3;         // 067 פ��ģʽ Kp
    uint16_t Ki_SpdM3;         // 068 פ��ģʽ Ki
    uint16_t HighSpd;          // 069 ������ֵ�����ݲ�ͬת�٣�ʹ�ò�ͬ��Kp��Kiϵ��ʹ��
    uint16_t LowSpd;           // 070 ������ֵ�����ݲ�ͬת�٣�ʹ�ò�ͬ��Kp��Kiϵ��ʹ��
    // PosMode_Menu
    uint16_t Spd_Pos_Thr;      // 071 ת�ٺ�λ����ֵ
    uint16_t Kp_Pos;           // 072 λ�û�Kp
    uint16_t Ki_Pos;           // 073 λ�û�Ki
    uint16_t Kd_Pos;           // 074 λ�û�Kd
    // MotParam_Menu
    uint16_t MotType;          // 075 �������
    uint16_t MotRatedSpd;      // 076 ����ת��
    uint16_t MotRatedVolt_L2L; // 077 �����ߵ�ѹ
    uint16_t MotPolePairs;     // 078 ���������
    uint16_t EncoderPolePairs; // 079 ���伫����
    uint16_t EncoderSteps;     // 080 ����������
    uint16_t SwapEncoderDir;   // 081 �������䷽��
    uint16_t SwapPhase;        // 082 ��������
    // FaultParam_Menu
    uint16_t DcOverVolt3;      // 083 ��ѹ��ֵ3
    uint16_t DcOverVolt2;      // 084 ��ѹ��ֵ2
    uint16_t DcOverVolt1;      // 085 ��ѹ��ֵ1
    uint16_t DcUnderVolt1;     // 086 Ƿѹ��ֵ1
    uint16_t DcUnderVolt2;     // 087 Ƿѹ��ֵ2
    uint16_t DcUnderVolt3;     // 088 Ƿѹ��ֵ3
    uint16_t DcOverCur1;       // 089 ĸ�߹���
    uint16_t AcOverCur1;       // 090 AC����1
    uint16_t AcOverCur2;       // 091 AC����2
    uint16_t OverSpd1;         // 092 ������ֵ1
    uint16_t OverSpd2;         // 093 ������ֵ2
    uint16_t PhaseBrkVari_Thr; // 094
    uint16_t PhaseBrkVari_Tmr; // 095
    uint16_t PhaseBrkCurRef_Thr;// 096
    uint16_t PhaseBrkCurfdb_Thr;// 097
    uint16_t PhaseBrkCur_Tmr;  // 098
    uint16_t PhaseBrkVolt_Thr; // 099
    uint16_t PhaseBrkFilt_Tr;  // 100
    uint16_t MotStallCur_Thr;  // 101 ��ת������ֵ
    uint16_t MotStallSpd_Thr;  // 102 ��תת����ֵ
    uint16_t MotStall_Tmr;     // 103 ��תʱ����ֵ
    uint16_t MotStallErrOut;   // 104 ��ת�������
    // InvTemp_Menu
    uint16_t InvTempType;      // 105 �������¶ȴ���������
    uint16_t InvTempOffSet;    // 106 �������¶ȴ�����ƫ��
    uint16_t InvTempErrOut;    // 107 �������¶ȴ������������
    uint16_t InvOverTemp3;     // 108 ����������3��ֵ
    uint16_t InvOverTemp2;     // 109 ����������2��ֵ
    uint16_t InvOverTemp1;     // 110 ����������1��ֵ
    // MotTemp_Menu
    uint16_t MotTempType;      // 111 ����¶ȴ���������
    uint16_t MotTempOffSet;    // 112 ����¶ȴ�����ƫ��
    uint16_t MotTempErrOut;    // 113 ����¶ȴ������������
    uint16_t MotOverTemp3;     // 114 �������3��ֵ
    uint16_t MotOverTemp2;     // 115 �������2��ֵ
    uint16_t MotOverTemp1;     // 116 �������1��ֵ
    // Vehicle_Menu
    uint16_t GearRatio;        // 117 �����ٱ�
    uint16_t TireDiameter;     // 118 ����ֱ��
    uint16_t CaptureSpd;       // 119 ��׽�ٶ�
    // Throttle_Menu
    uint16_t MainDrvCompEn;    // 120
    uint16_t MainDrvPullInVolt;// 121
    uint16_t MainDrvHoldVolt;  // 122
    uint16_t PWM2PullInVolt;   // 123
    uint16_t PWM2HoldVolt;     // 124
    // MainContact_Menu
    uint16_t MainDrv_En;       // 125 ���Ӵ���ʹ��
    uint16_t MainDNC_Thr;      // 126 ���Ӵ����Ͽ���ֵ
    uint16_t PreCharge_En;     // 127 Ԥ���ʹ��
    uint16_t PreChargeTim1;    // 128 Ԥ��ʱ��1
    uint16_t PreChargeTim2;    // 129 Ԥ��ʱ��2
    uint16_t PreChargeTim3;    // 130 Ԥ��ʱ��3
    uint16_t DisChargeTim1;    // 131 �����ŵ�ʱ��
    uint16_t DisChargeCur1;    // 132 �����ŵ����
    // TimeConstant_Menu
    uint16_t Spd_Tr;           // 133
    uint16_t VDC_Tr;           // 134
    uint16_t IDC_Tr;           // 135
    uint16_t LogicV_Tr;        // 136
    uint16_t MotTemp_Tr;       // 137
    uint16_t InvTemp_Tr;       // 138
    uint16_t Is_Tr;            // 139
    uint16_t Id_Tr;            // 140
    uint16_t Iq_Tr;            // 141
    uint16_t Vs_Tr;            // 142
    uint16_t Vd_Tr;            // 143
    uint16_t Vq_Tr;            // 144
    uint16_t Beta_Tr;          // 145
    uint16_t CutBack_Tr;       // 146
    uint16_t IpL_Tr;           // 147
    uint16_t nCt_Tr;           // 148
    uint16_t Ins_Tr;           // 149
    uint16_t IsL_Tr;           // 150
    uint16_t iWe_Tr;           // 151
    uint16_t Mr_Tr;            // 152
    uint16_t Vd0_Tr;           // 153
    uint16_t Vq0_Tr;           // 154
    uint16_t VdE_Tr;           // 155
    uint16_t VqE_Tr;           // 156
    // Debug_Menu
    uint16_t DebugMode;        // 157
    uint16_t VsMax;            // 158
    uint16_t Kp_Id;            // 159
    uint16_t Ki_Id;            // 160
    uint16_t Kp_Iq;            // 161
    uint16_t Ki_Iq;            // 162
    uint16_t Kp_FW1;           // 163
    uint16_t Ki_FW1;           // 164
    uint16_t Kp_FW2;           // 165
    uint16_t Ki_FW2;           // 166
    uint16_t Kp_IdcLmt;        // 167
    uint16_t Ki_IdcLmt;        // 168
    uint16_t FaultMask1_0;     // 169
    uint16_t FaultMask1_1;     // 170
    uint16_t FaultMask1_2;     // 171
    uint16_t FaultMask1_3;     // 172
    uint16_t FaultMask2_0;     // 173
    uint16_t FaultMask2_1;     // 174
    uint16_t FaultMask2_2;     // 175
    uint16_t FaultMask2_3;     // 176
    uint16_t HarmonicComp;     // 177
    uint16_t SVPWM_SEGs;       // 178
    uint16_t CalibratStep;     // 179
    uint16_t ElecZeroStudyType;// 180
    uint16_t If;               // 181
    uint16_t Bemf;             // 182
    uint16_t VsMax_Ref;        // 183
    uint16_t SlopeIsMax;       // 184
    uint16_t rsvd185;          // 185
    uint16_t rsvd186;          // 186
    uint16_t TuneFreqCoef;     // 187 ��Ƶϵ��
    uint16_t FreqLow;          // 188 �ز����Ƶ
    uint16_t FreqUp;           // 189 �ز����Ƶ
    uint16_t ASCSpd;           // 190 ASCʹ���ٶ�
    uint16_t DamperTimer;      // 191 ���������˲�ʱ��
    uint16_t DamperGain;       // 192 ������������ϵ��
    uint16_t CalibMTPATheta;   // 193 ��ʼ�궨MTPA�Ƕ�   [0 pi/2]  rad  0.01����
    uint16_t FLStartAng;       // 194 ɨ��Ƕȣ������޶�Q�ᣩ���Ƕ��ƣ�  0.01����
    uint16_t HighDevice;       // 195 �߱�����ʹ��
    uint16_t SpeadRef;         // 195 U�����AD
    uint16_t CUR_W;            // 195 W�����AD
}USER_OBJ;

#define PARM_NUM (sizeof(USER_OBJ))

//!  �û���������ṹ������
typedef struct
{
    USER_OBJ   Var;       //!< Variable
    USER_OBJ   Sts;       //!< Variable Status
    int16_t    ErrCode;   //!< ������
    int16_t    ErrIndex;  //!< ����������±�
    uint16_t*  VarPnt;    //!< ָ�룬ָ��OBJ->Var
    uint16_t*  StsPnt;    //!< ָ�룬ָ��OBJ->Sts
    void  (*Init)();      //!< Pointer to  initialization  function
    void  (*Stateflow)(); //!< Pointer to  Stateflow  function
}USER_PARM_OBJ;

#define USER_PARM_OBJ_DEFAULTS {  {0},\
                                  {0},\
                                  0,\
                                  0,\
                                  NULL,\
                                  NULL,\
                                  (void (*)(long))ParmInit,\
                                  (void (*)(long))ParmStateflow}

//! \brief     �û�������ʼ��
//! \param[in] v    Handle to USER_PARM_OBJ object
extern void ParmInit(USER_PARM_OBJ* v);


//! \brief     �û���������״̬���������������
//! \param[in] v    Handle to USER_PARM_OBJ object
extern void ParmStateflow(USER_PARM_OBJ* v);


typedef enum
{
    PARM_IDLE = 0,          //!< ���У������޲���
    PARM_WRITING = 1,       //!< ����д��EEPROM������
    PARM_WRITE_ERR = 2,     //!< ����д��EEPROM�����У����ִ���
    PARM_READ_ERR = 3,      //!< ������EEPROM��ȡ�����У����ִ���
    PARM_RANGE_ERR = 4      //!< ����������Χ
}PARM_STATE_e;


typedef struct
{
    uint16_t Min;
    uint16_t Var;
    uint16_t Max;
}CONSTANT_OBJ;

// ----------------------------------------------------------------------------
// ������
typedef struct
{
    uint32_t OffsetCalcEn;
    float CurU;
    float CurV;
    float CurW;
    float CurBus;
    float CurU_Coef;
    float CurV_Coef;
    float CurW_Coef;
    float CurBus_Coef;
    float CurU_Offset;
    float CurV_Offset;
    float CurW_Offset;
    float CurBus_Offset;

    void  (*OffsetCalc)();
    void  (*ValueCalc)();
}SENSOR_OBJ;

#define SENSOR_OBJ_DEFAULTS   { 0,\
                                0,0,0,0,0,0,0,0,0,0,0,0,\
                                (void (*)(long))SensOffsetCalc,\
                                (void (*)(long))SensValueCalc}


extern void SensOffsetCalc(ADC_Handle adcHandle,SENSOR_OBJ* S);
extern void SensValueCalc(SENSOR_OBJ* S);
// ----------------------------------------------------------------------------

typedef struct
{
    int16_t KSI_SW              ; // 00
    int16_t VoltBus             ; // 00
    int16_t VoltCap             ; // 00
    int16_t TqMax               ; // 01
    int16_t TqReal              ; // 01
    int16_t MotTemp             ; // 01
    int16_t InvTemp             ; // 02
    int16_t ThetaRawE           ; // 02
    int16_t ThetaRawM           ; // 02

    int16_t Angle_park          ; // 03
    int16_t Angle_Ipark         ; // 03
    int16_t MBD_PwmWorkMode     ; // 03
    int16_t MotState            ; // 04
    int16_t MotMode             ; // 04
    int16_t Speed               ; // 04
    int16_t ThetaRT             ; // 05
    int16_t MainLoopUsage       ; // 05
    int16_t MainISR_Usage       ; // 05

    int16_t ParmErrCode         ; // 06
    int16_t ParmErrIndex        ; // 06
    int16_t CurBus              ; // 06
    int16_t IGBT1Err            ; // 07
    int16_t IGBT2Err            ; // 07
    int16_t IGBT3Err            ; // 07
    int16_t MBD_KeepPowerEn     ; // 08
    int16_t rsvd1     ; // 08
    int16_t rsvd2     ; // 08
// һ��Ҫ�����3�ı���������ʵʱ�������������������� PMSM_Input
}WATCH_VAR_OBJ;
                              //  0     1     2     3     4     5     6     7     8     9
#define WATCH_VAR_OBJ_DEFAULTS {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}//,0,0,0,\
//                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
//                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
//                                0,0,0}

#define WATCH_NUM (sizeof(WATCH_VAR_OBJ))

typedef struct
{
    WATCH_VAR_OBJ Var;    //!< ��ر���
    uint16_t* VarPnt;     //!< ָ�룬ָ��OBJ->Var
    void (*Init)();
}WATCH_OBJ;

#define WATCH_OBJ_DEFAULTS {WATCH_VAR_OBJ_DEFAULTS,\
                            NULL,\
                            (void (*)(long))Watch_Init}

extern void Watch_Init(WATCH_OBJ* W);

// ----------------------------------------------------------------------------


#if COUST_ID == 0
typedef struct
{
    uint32_t DCRelayState:1;   // Ԥ�����
    uint32_t MotGateReq  :1;   // ϵͳʹ��
    uint32_t HandBrake   :1;   // ��ɲ�ź�
    uint32_t FootBrake   :1;   // ��ɲ�ź�
    uint32_t GearPos     :8;   // ��λ   0���յ� 1��ǰ�� 2������
    uint32_t MotModeReq  :8;   // ����ָ�0��ת�� 1��ת�� 2������ 3������ 4��פ�� 5��ͬ�� 6�������ϵ� 7��������· 15��ͣ��
    uint32_t Rsvd0:12;

    float MotTqReq;            // Ť������ 1/4096
    float MotTqRef2;           // Ť������ 1/4096�����ڵ���궨
    float MotSpdReq;           // ת������ rpm
    float MotSpdLim;           // ����ת��,Ť�ػ�������
    float MotSpdHold;          // פ��ת��
    float BusCurGeneLim;       // ����ĸ������             �޷��� 1A
    float BusCurDriveLim;      // ����ĸ������            �޷��� 1A
    float MotTorqLimPos;       // Ť����������             1/4096��ת�ٻ���������
    float MotTorqLimNeg;       // ת�����Ʒ���            1/4096��ת�ٻ���������

}MOT_CMD_OBJ;
#define MOT_CMD_OBJ_DEFAULTS {0,0,0,0,0,0,0,\
                              0,0,0,0,0,500,500,1.0,-1.0}

typedef struct
{
    uint16_t Fault[4];
    float MotTqReal;           // ʵ��Ť��
    float MotSpdReal;          // ʵ��ת��
    float MotTqMax;            // ���ת��
    float BusCurrent;          // ĸ�ߵ���
    float BusVoltage;          // ĸ�ߵ�ѹ����ضˣ�
    float InvTemp;             // �¶�
    float MotTemp;             // �¶�
}MOT_STS_OBJ;

#define MOT_STS_OBJ_DEFAULTS {0,0,0,0,\
                              0,0,0,0,0,0,0}
typedef struct
{
    MOT_CMD_OBJ Cmd;
    MOT_STS_OBJ Sts;
}MOT_INTF_OBJ;
#define MOT_INTF_OBJ_DEFAULTS {\
                               MOT_CMD_OBJ_DEFAULTS,\
                               MOT_STS_OBJ_DEFAULTS}
#endif

typedef enum
{
    TorqueMod = 0,             //!< Ť��ģʽ
    SpeedMod  = 1,             //!< �ٶ�ģʽ
    GeneMod   = 2,             //!< ����ģʽ
    DriveMod  = 3,             //!< ����ģʽ
    SlopeMod  = 4,             //!< פ��ģʽ
    SyncMod   = 5,             //!< ͬ��ģʽ
    ActDisChgMod = 6,          //!< �����ŵ�ģʽ
    StopMod   = 15,            //!< ֹͣģʽ
}VCU_MODE_REQ_e;

typedef enum
{
    Gear_N = 0,        // �յ�
    Gear_D = 1,        // ǰ��
    Gear_R = 2,        // ����
}GEAR_POS_e;
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
typedef union
{
    uint32_t All;
    struct
    {
        uint32_t SW_En:1;
        uint32_t HW_EN:1;
        uint32_t AcOverCur2ErrAsc : 1;
        uint32_t DcOverVolt3ErrAsc: 1;

        uint32_t DcUnderVolt3ErrAsc:1;
        uint32_t OverSpd2Asc : 1;
        uint32_t PosSensorErr:1;
        uint32_t CurSensorErr:1;

        uint32_t PhaseBrkErr:1;
        uint32_t LogicPowerErr:1;
        uint32_t MotStallErr:1;
        uint32_t DcOverVolt3Err:1;

        uint32_t DcUnderVolt3Err:1;
        uint32_t AcOverCur2Err:1;
        uint32_t PwrMdlErr:1;
        uint32_t ParErr:1;

        uint32_t ParChangeErr:1;
    }Bit;
}MOT_EN_OBJ;

#define MOT_EN_OBJ_DEFAULTS {0}

typedef enum
{
    MOT_State_Idle = 0,              //!< the Motor idle state
    MOT_State_Ready = 1,             //!< the Motor ready state
    MOT_State_OnLine = 2,            //!< the Motor online state
    MOT_State_Asc    = 3,            //!< the Motor ASC state
    MOT_State_OffLine = 4,           //!< the Motor offline state
}MOT_STATEFLOW_e;

typedef struct
{
    MOT_EN_OBJ En;
    MOT_STATEFLOW_e State;
    MOT_STATEFLOW_e StateHis;

    void (*Update)();
}MOT_STATE_OBJ;

#define MOT_STATE_OBJ_DEFAULTS { MOT_EN_OBJ_DEFAULTS,\
                                 MOT_State_Idle,\
                                 MOT_State_Idle,\
                                (void (*)(long))MotStateUpdate}

extern void MotStateUpdate(MOT_STATE_OBJ* S);

// ----------------------------------------------------------------------------
// �����˲�ϵ��

typedef struct
{
    float Spd_Tr;         //!< ʱ���� �ж�
    float VDC_Tr;         //!< ʱ���� �ж�
    float IDC_Tr;         //!< ʱ���� �ж�
    float LogicV_Tr;      //!< ʱ���� ��ѭ��
    float MotTemp_Tr;     //!< ʱ���� ��ѭ��
    float InvTemp_Tr;     //!< ʱ���� ��ѭ��
    float Is_Tr;          //!< ʱ���� �ж�
    float Id_Tr;          //!< ʱ���� �ж�
    float Iq_Tr;          //!< ʱ���� �ж�
    float Vs_Tr;          //!< ʱ���� �ж�
    float Vd_Tr;          //!< ʱ���� �ж�
    float Vq_Tr;          //!< ʱ���� �ж�
    float Beta_Tr;
    float CutBack_Tr;
    float IpL_Tr;
    float nCt_Tr;
    float Ins_Tr;
    float IsL_Tr;
    float iWe_Tr;
    float Mr_Tr;
    float Vd0_Tr;
    float Vq0_Tr;
    float VdE_Tr;
    float VqE_Tr;
    void (*Calc)();
}LPF_COEF_OBJ;

#define LPF_COEF_OBJ_DEFAULTS { 0,0,0,0,0,0,\
                                0,0,0,0,0,0,\
                                0,0,0,0,0,0,\
                                0,0,0,0,0,0,\
                                (void (*)(long))Lpf_Calc}

extern void Lpf_Calc(LPF_COEF_OBJ* B);


// ----------------------------------------------------------------------------
// ��������������
typedef struct
{
    uint16_t ActiveDisChargeEn:1;//!< 00 []
    uint16_t KSI_SW:1;           //!< 01 []
    uint16_t PosSensorErr:1;     //!< 02 []
    uint16_t PwrMdlErr1:1;       //!< 03 []
    uint16_t PwrMdlErr2:1;       //!< 04 []
    uint16_t PwrMdlErr3:1;       //!< 05 []
    uint16_t Drv1Stus:1;         //!< 06 []
    uint16_t Drv2Stus:1;         //!< 07 []
    uint16_t MotTemp1Err:1;      //!< 08 []
    uint16_t MotTemp2Err:1;      //!< 09 []
    uint16_t InvTemp1Err:1;      //!< 10 []
    uint16_t InvTemp2Err:1;      //!< 11 []
    uint16_t InvTemp3Err:1;      //!< 12 []
    uint16_t ParChangeErr:1;     //!< 13 []
    uint16_t DisChgWarnErr:1;    //!< 14 []
    uint16_t DisChgOverTmErr:1;  //!< 15 []
    uint16_t PhaseBrkErr:1;      //!< 16 []
    uint16_t PhaseBrkChkOk:1;    //!< 17 []
    uint16_t AngleECtrlEn:1;     //!< 18
    uint16_t IdIqCtrlEn:1;       //!< 19
    uint16_t AscCondOk:1;        //!< 20

    uint16_t SwIn1:1;            //21
    uint16_t SwIn2:1;            //22
    uint16_t SwIn3:1;            //23
    uint16_t SwIn4:1;            //24
    uint16_t Precharge_Relay_en:1;  //!< 25
    uint16_t Id5tm;
    uint16_t Id6tm;
}FLAG_BIT_OBJ;
typedef union
{
    uint32_t  All;
    FLAG_BIT_OBJ Bit;
}FLAG_OBJ;
                        // 0,1,2,3,4,5,6,7,8,9
#define FLAG_OBJ_DEFAULTS {0}

typedef struct
{
    float VoltBus;              //!< 000 [0.1V]  ĸ�ߵ�ѹ  Battery Voltage;
    float VoltBusFilted;        //!< 001 [0.1V]  ĸ�ߵ�ѹ�˲�ֵ  Battery Voltage;
    float VoltBus_pu;           //!< 002 [pu]    ĸ�ߵ�ѹ����ֵ  Battery Voltage;
    float CurBus;               //!< 003 [pu]    ĸ�ߵ���  Battery Current;
    float Power;                //!< 004 [pu]    (Vd*Id + Vq*Iq)*Vc
    float VoltCap;              //!< 005 [0.1V]  ���ݵ�ѹ   Capacitor Voltage;
    float VoltCapFilted;        //!< 006 [0.1V]  ���ݵ�ѹ�˲�ֵ    Capacitor Voltage Filted;
    float VoltCap_pu;           //!< 007 [pu]    ���ݵ�ѹ����ֵ    Capacitor Voltage;
    float VoltCap_pui;          //!< 008 [pu]    ���ݵ�ѹ�������ֵ    Capacitor Voltage Inverse;
    float VoltMax_pu;           //!< 009 [pu]    ���ݵ�ѹ���ص�ѹ���ֵ   Max(VoltCap,VoltBus);
    float VoltU;                //!< 010 [pu]    U���ѹ   Phase U voltage line to line
    float VoltV;                //!< 011 [pu]    V���ѹ   Phase V voltage line to line
    float VoltW;                //!< 012 [pu]    W���ѹ   Phase W voltage line to line
    float CurU;                 //!< 013 [pu]    U�����   Phase U current
    float CurV;                 //!< 014 [pu]    V�����   Phase V current
    float CurW;                 //!< 015 [pu]    W�����   Phase W current
    float MotTemp1;             //!< 016 [��]    NTC1�ɼ����¶�   Motor temperature 1
    float MotTemp2;             //!< 017 [��]    NTC2�ɼ����¶�   Motor temperature 2
    float MotTemp;              //!< 018 [��]    ʵ�ʵĵ���¶�      Motor temperature sent to the VCU
    float InvTemp1;             //!< 019 [��]    IGBT�¶�1 IGBT temperature 1
    float InvTemp2;             //!< 020 [��]    IGBT�¶�2 IGBT temperature 2
    float InvTemp3;             //!< 021 [��]    IGBT�¶�3 IGBT temperature 3
    float InvTemp;              //!< 022 [��]    IGBTʵ���¶�   IGBT temperature sent to the VCU
    float N_Base;               //!< 023 [rpm]   ת�ٻ�ֵ   Mechanical speed
    float Nm;                   //!< 024 [rpm]   ʵ��ת��   Mechanical speed
    float Nm_pu;                //!< 025 [pu]    ת�ٱ���ֵ  Mechanical speed
    float NmFilted;             //!< 026 [rpm]   �ɼ����ʵ��ת�ٺ��˲��ĵ��ת��  Mechanical speed
    float Ne;                   //!< 027 [rpm]   ��ת��    Electric speed
    float Ne_pu;                //!< 028 [pu]    ��ת�ٱ���ֵ Electric speed
    int16_t ThetaRT;            //!< 029 [0-4095]ʵ�ʽǶ�   Real time angle
    int16_t ThetaRawE;          //!< 030 [0-4095]��е�Ƕ�   Rotor electric angle
    int16_t ThetaRawM;          //!< 031 [0-4095]��Ƕ�    Rotor mechanical angle
    int16_t ThetaMech;          //!< 032 [0-4095]��е�Ƕ�   Mechanical angle
    float ThetaElec;            //!< 033 [pu]    FOC�õĵ�Ƕ�   Electric angle for FOC
    float Cutback;              //!< 034 [pu]    Ť�عع�   Torque Cutback;
    float CutBackFilted;        //!< 035 [pu]    Ť�عع��˲�ֵ    Torque Cutback filted;
    float InvTempCutback;       //!< 036 [pu]    ���������¹ع�
    float MotTempCutback;       //!< 037 [pu]    ������¹ع�
    float OverVoltCutback;      //!< 038 [pu]    ��ѹ�ع�
    float UnderVoltCutback;     //!< 039 [pu]    Ƿѹ�ع�
    float IdcDrvLmtCutBack;     //!< 040 [pu]    ���������ع�     Idc limit
    float IdcGenLmtCutBack;     //!< 041 [pu]    ���������ع�     Idc limit
    float IdRef;                //!< 042 [pu]    Id����
    float IdRef_Filted;         //!< 043 [pu]    Id�����˲�ֵ
    float If;                   //!< 044 [pu]    ��������
    float Id;                   //!< 045 [pu]    Idʵ��ֵ
    float IdFilted;             //!< 046 [pu]    Id�˲�ֵ
    float IqRef;                //!< 047 [pu]    Iq����
    float Iq;                   //!< 048 [pu]    Iqʵ��ֵ
    float IqFilted;             //!< 049 [pu]    Iq�˲�ֵ
    float CmdIsRef;             //!< 050 [pu]    VCU������Ť�������Ӧ��Is����   IsRef from the VCU torque request
    float Rsvd51;               //!< 051 [pu]
    float IsRef;                //!< 052 [pu]    FOcus�õ�Is����    IsRef for FOC
    float IsPosLmt;             //!< 053 [pu]    Is��������
    float IsNegLmt;             //!< 054 [pu]    Is��������
    float Is;                   //!< 055 [pu]    Isʵ��ֵ
    float IsFilted;             //!< 056 [pu]    Is�˲�ֵ
    float Vd;                   //!< 057 [pu]    Vdʵ��ֵ
    float VdFilted;             //!< 058 [pu]    Vd�˲�ֵ
    float Vq;                   //!< 059 [pu]    Vqʵ��ֵ
    float VqFilted;             //!< 060 [pu]    Vq�˲�ֵ
    float Vs;                   //!< 061 [pu]    VSʵ��ֵ
    float VsFilted;             //!< 062 [pu]    VS�˲�ֵ
    float VsMax;                //!< 063 [pu]    VS���ֵ���궨��ѹ��
    float FwErr;                //!< 064 [pu]    ���Ź���
    float IdWeak;               //!< 065 [pu]    Id�Ƕȷ���ֵ
    float AngleMTPA;            //!< 066 [pu]    MTPA�Ƕ�ֵ
    float AngleWeak;            //!< 067 [pu]
    float IdTorq;               //!< 068 [pu]    Id��Ӧ��Ť��
    float Ld ;                  //!< 069 [pu]    D����
    float Pot1Volt;             //!< 070 [pu]
    float Pot1Cmd;              //!< 071 [pu]
    float Brd05V;               //!< 072 [pu]
    float Brd12V;               //!< 073 [pu]
    float Brd24V;               //!< 074 [pu]
    float PolesRatio;           //!< 075 [pu]  motor and encoder poles ratio
    float DisChargeCur;         //!< 076 [pu]
    uint16_t PwmLowFreq;        //!< 077 [Hz]  PWM��Ƶֵ  PWM
    uint16_t PwmHighFreq;       //!< 078 [Hz]  PWM��Ƶֵ  PWM
    uint16_t PwmLowFreq_Hz;     //!< 079 [Hz]  PWM��Ƶ    motor
    uint16_t PwmHighFreq_Hz;    //!< 080 [Hz]  PWM��Ƶ    motor
    float    PwmMotSpeed_Hz;    //!< 081 [Hz]  ��ǰ���ת��
    float    PwmOutFreq;        //!< 082 [Hz]  PWM��Ƶ��Ƶ��
    float    PwmOutPeriod;      //!< 083 [us]  PWM��Ƶ�����ڣ���ֵ��PWM�����жϺ�����
    float    TabNStart;         //!< 084 [rpm]
    float    TabNEnd;           //!< 085 [rpm]
    float    TabNStep;          //!< 086 [rpm] ��ת�ټ��
    float    TabNRefU;          //!< 087 [rpm]
    float    NVComp;            //!< 088 []    ת�ٵ�ѹ��
    uint16_t ModeReq;           //!< 089
    uint16_t ModeHis;           //!< 090
    uint16_t MotStudyStep;      //!< 091
    uint16_t MotStudyResult;    //!< 092
    float    NmFiltedVCU;       //!< 093 []    VCU����������ת���˲����ת��
    float    TqLimit;           //!< 094 []    �����ǰ���Ť������
    int16_t  TqMax;             //!< 095 [Nm]  ���Ť��
    int16_t  TqReal;            //!< 096 [Nm]  ʵ��Ť��
    float    PhaseBrkIdErr;     //!< 097 []    d�᷽��
    float    PhaseBrkIdErrFilted;//!< 098 []
    float    PhaseBrkIqErr;      //!< 099 []   q�᷽��
    float    PhaseBrkIqErrFilted;//!< 100 []
    float    MotTemp1His;        //!< 101 [��]    �����ʷ�¶�1    Motor temperature 1
    float    MotTemp2His;        //!< 102 [��]    �����ʷ�¶�2    Motor temperature 2
    float    KCurrPIComp;        //!< 103 []
    float    TqMaxOutCutback;    //!< 104 [pu]   Torque Cutback;
    float    PWM1Duty;           //!< 105 0-1 PWMռ�ձ�
    float    VehicleSpd;         //!< 106 ����
    float    TotalMileage;       //!< 107 �����
    float    SingleMileage;      //!< 108 �������
    float    fRpmToSpdK;         //!< 109

    float    TestData1;          //!< 196 []
    float    TestData2;          //!< 197 []
    float    TestData3;          //!< 198 []
    float    TestData4;          //!< 199 []
    float    AngleEExSet;
    float    AngleE1ExSet;
    float    IdRefExSet;
    float    IqRefExSet;
    float MotTemp1cal;             //!< 016 [��]    NTC1�ɼ����¶�   Motor temperature 1
    float MotTemp2cal;             //!< 017 [��]    NTC2�ɼ����¶�   Motor temperature 2
    float VoltBase_reciprocal;             //!< ĸ�ߵ�ѹ����

    uint16_t FaultGrade;         // ���ϵȼ�

    FLAG_OBJ Flags;              //
}PMSM_VAR_OBJ;

/** \brief Default initializer for the XXXXXX object
*/
#define PMSM_VAR_OBJ_DEFAULTS  { 0,0,0,0,0,0,0,0,0,0,\
								 0,0,0,0,0,0,0,0,0,0,\
								 0,0,0,0,0,0,0,0,0,0,\
								 0,0,0,0,0,0,0,0,0,0,\
								 0,0,0,0,0,0,0,0,0,0,\
								 0,0,0,0,0,0,0,0,0,0,\
								 0,0,0,0,0,0,0,0,0,0,\
								 0,0,0,0,0,0,0,0,0,0,\
								 0,0,0,0,0,0,0,0,0,0,\
								 0,0,0,0,0,0,0,0,0,0,\
                                 0,0,0,0,0,0,0,0,0,0,\
                                 0,0,0,0,0,0,0,0,0,\
                                 FLAG_OBJ_DEFAULTS,\
                                 }

#if EVCBD_ID == 0x09
// ���Ӵ���
typedef union
{
    uint16_t All;
    struct
    {
        uint32_t MainDrvSet:1;       //!< �Ӵ������ϸ���
        uint32_t PreChargeRdy:1;     //!< Ԥ������
        uint32_t PreChargeFail:1;    //!< Ԥ�����
        uint32_t VoltDiff:1;         //!< �Ӵ�������ѹ��״̬
    }Bits;
}MAINDRV_STS;
#define MAINDRV_STS_DEFAULTS {0}
typedef struct
{
    float VoltBus;
    float VoltCap;
    float VoltCapHis;
    uint16_t MainOn;    //!< �Ӵ�����ǰ״̬
    uint16_t State;     //!< ״̬��״̬����
    uint16_t Delay0;    //!< ��Դ���Ӳ��Լ�ʱ��
    uint16_t Delay1;    //!< ���ݳ���ʱ��
    uint16_t Delay2;    //!< �����ʱ��������ѹ�������ʱ��
    uint16_t Delay3;    //!< �Ӵ�������ʱ�䣬���綯��ʱ��

    MAINDRV_STS Sts;
}MAINDRV_OBJ;
#define MAINDRV_OBJ_DEFAULTS { 0,0,0,0,0,0,0,0,0,\
                               MAINDRV_STS_DEFAULTS}
#endif
typedef struct
{
    MOT_INTF_OBJ  Intf;         //!< ������ƽӿ�
    MOT_STATE_OBJ StateFlow;    //!< ����������״̬
    LPF_COEF_OBJ  Lpf_Coef;     //!< ��ͨ�˲�����ϵ������
    PMSM_VAR_OBJ  Var;          //!< ���������ر���
    SENSOR_OBJ    Sens;         //!< ������
    FAULT_OBJ     FaultNow;     //!< ��ǰ����
    FAULT_OBJ     FaultMask;    //!< ���ϼ��MASK
    FAULT_OBJ     FauErr ;      //!< ��ѹ����

    PI_OBJ        PI_Pos;       //!< λ�û�PI
    PI_OBJ        PI_Spd;       //!< �ٶȻ�PI
    PI_OBJ        PI_TrqSpd;    //!< Ť�ػ�����PI
    PI_OBJ        PI_TrqCur;    //!< Ť�ػ�����PI
    PI_OBJ        PI_Id;        //!< Id����PI
    PI_OBJ        PI_Iq;        //!< Iq����PI
    PI_OBJ        PI_FW;        //!< ����PI
    PI_OBJ        PI_Angle;     //!< ����PI2
    PI_OBJ        PI_Slope;     //!< פ��ģʽ
    PI_OBJ        PI_ASC;       //!< ASCģʽPI
    PARK_OBJ      park;
    IPARK_OBJ     ipark;
    CLARKE_OBJ    clarke;
    SVPWM_OBJ     svpwm;
    ANGELCOMP_OBJ AngelComp;
}PMSM_OBJ;

#define PMSM_OBJ_DEFAULTS  { MOT_INTF_OBJ_DEFAULTS,\
                             MOT_STATE_OBJ_DEFAULTS,\
                             LPF_COEF_OBJ_DEFAULTS,\
                             PMSM_VAR_OBJ_DEFAULTS,\
                             SENSOR_OBJ_DEFAULTS,\
                             FAULT_OBJ_DEFAULTS,\
                             FAULT_OBJ_DEFAULTS,\
                             FAULT_OBJ_DEFAULTS,\
                             PI_OBJ_DEFAULTS,\
                             PI_OBJ_DEFAULTS,\
                             PI_OBJ_DEFAULTS,\
                             PI_OBJ_DEFAULTS,\
                             PI_OBJ_DEFAULTS,\
                             PI_OBJ_DEFAULTS,\
                             PI_OBJ_DEFAULTS,\
                             PI_OBJ_DEFAULTS,\
                             PI_OBJ_DEFAULTS,\
                             PI_OBJ_DEFAULTS,\
                             PARK_OBJ_DEFAULTS,\
                             IPARK_OBJ_DEFAULTS,\
                             CLARKE_OBJ_DEFAULTS,\
                             SVPWM_OBJ_DEFAULTS,\
                             ANGELCOMP_OBJ_DEFAULTS,\
                             }


typedef struct
{
    float NvCompTest;
    float TqPuTest;
    float TLinTest;
    float IsMaxTest;
    float TLimTest;
    float IsRefTest;

    float NvCompTestM;
    float TqPuTestM;
    float TLinTestM;
    float IsMaxTestM;
    float TLimTestM;
    float IsRefTestM;

    uint32_t HisFaultCode1;
    uint32_t HisFaultCode2;
}MBD_TEST_OBJ;

#define MBD_TEST_OBJ_DEFAULTS {0,0,0,0,0,0,\
                            0,0,0,0,0,0,0,0}


typedef struct
{
    uint16_t ID1TxFlg;
    uint16_t ID2TxFlg;
    uint16_t ID3TxFlg;
    uint16_t ID4TxFlg;
    uint16_t ID5TxFlg;
    uint16_t ID6TxFlg;
    uint16_t ID7TxFlg;
    uint16_t ID8TxFlg;
    uint16_t ID9TxFlg;
    uint16_t ID10TxFlg;
}CAN_ISR_TX_OBJ;

#define CAN_ISR_TX_OBJ_DEFAULTS {0,0,0,0,0,0,0,0,0,0}

typedef union
{
    uint16_t Data;
    struct
    {
        uint16_t PAR  :1;       //!< ��żУ��
        uint16_t LOT  :1;       //!< �źŶ�ʧ
        uint16_t DOS  :1;       //!< �ź��ӻ�
        uint16_t RDVEL:1;       //!< λ��(1)or�ٶ�(0)
        uint16_t Loc  :12;
    }M1;
}RDC_1205;

typedef enum
{
    Calib_Idle                = 0,              //!< �궨ֹͣ
    Calib_PhaseStudy_Idle     = 10,             //!< ����ѧϰ�ȴ�-������Ŵ�Լ50;
    Calib_PhaseStudy_Online   = 11,             //!< ����ѧϰ��
    Calib_PhaseStudy_OkRev    = 12,             //!< ����ѧϰ�ɹ�-����
    Calib_PhaseStudy_OkPos    = 13,             //!< ����ѧϰ�ɹ�-����
    Calib_PhaseStudy_Err      = 14,             //!< ����ѧϰʧ��
//    Calib_ElecZeroStudy_Drag_Idle    = 20,      //!< ���ѧϰ-����-�ȴ�
//    Calib_ElecZeroStudy_Drag_Online1 = 21,      //!< ���ѧϰ-����-�ֵ�
//    Calib_ElecZeroStudy_Drag_Online2 = 22,      //!< ���ѧϰ-����-�ֵ�
//    Calib_ElecZeroStudy_Drag_Ok      = 23,      //!< ���ѧϰ-����-���
//    Calib_ElecZeroStudy_Drag_Err     = 24,      //!< ���ѧϰ-����-ʧ��
    Calib_ElecZeroStudy_Rotate_Idle   = 30,      //!< ���ѧϰ-��ת-�ȴ�
    Calib_ElecZeroStudy_Rotate_U0Lock = 31,      //!< ���ѧϰ-��ת-��Ĭ�����
    Calib_ElecZeroStudy_Rotate_Try    = 32,      //!< ���ѧϰ-��ת-����
    Calib_ElecZeroStudy_Rotate_AddSpd = 33,      //!< ���ѧϰ-��ת-����
    Calib_ElecZeroStudy_Rotate_Calc   = 34,      //!< ���ѧϰ-��ת-����
    Calib_ElecZeroStudy_Rotate_Ok     = 35,      //!< ���ѧϰ-��ת-���
    Calib_ElecZeroStudy_Rotate_Err    = 36,      //!< ���ѧϰ-��ת-ʧ��
    Calib_IfStudy_Idle                = 40,      //!< ��������ѧϰ-�ȴ�
    Calib_IfStudy_IdAcc               = 41,      //!< ��������ѧϰ-���ӵ���
    Calib_IfStudy_Calc                = 42,      //!< ��������ѧϰ-����
    Calib_IfStudy_Ok                  = 43,      //!< ��������ѧϰ-���
    Calib_IfStudy_Err                 = 44,      //!< ��������ѧϰ-ʧ��
    Calib_PsiStudy_Idle               = 50,      //!< ������ѧϰ-�ȴ�
    Calib_PsiStudy_SpdStable          = 51,      //!< ������ѧϰ-ת���ȶ���
    Calib_PsiStudy_Calc               = 52,      //!< ������ѧϰ-����
    Calib_PsiStudy_Ok                 = 53,      //!< ������ѧϰ-�ɹ�
    Calib_PsiStudy_Err                = 54,      //!< ������ѧϰ-ʧ��
    Calib_MtpaStudy_Idle              = 60,      //!< mtpa�궨-�ȴ�
    Calib_MtpaStudy_IsAcc             = 61,      //!< mtpa�궨-�ӵ���
    Calib_MtpaStudy_AngleAcc          = 62,      //!< mtpa�궨-�ӽǶ�
    Calib_MtpaStudy_AngleDec          = 63,      //!< mtpa�궨-���Ƕ�
    Calib_MtpaStudy_IsDec             = 64,      //!< mtpa�궨-������
    Calib_MtpaStudy_Ok                = 65,      //!< mtpa�궨-���
    Calib_MtpaStudy_Err               = 66,      //!< mtpa�궨-ʧ��
    Calib_IsMaxStudy_Idle             = 70,      //!< IsMax�궨-�ȴ�
    Calib_IsMaxStudy_IsAcc            = 71,      //!< IsMax�궨-�ӵ���
    Calib_IsMaxStudy_IsDec            = 72,      //!< IsMax�궨-������
    Calib_IsMaxStudy_Ok               = 73,      //!< IsMax�궨-���
    Calib_IsMaxStudy_Err              = 74,      //!< IsMax�궨-ʧ��
    Calib_Rays_Idle                   = 80,      //!< ɨ��궨-�ȴ�
    Calib_Rays_AngleUp                = 81,      //!< ɨ��궨-�ӽǶ�
    Calib_Rays_IsUp                   = 82,      //!< ɨ��궨-�ӵ���
    Calib_Rays_IsDown                 = 83,      //!< ɨ��궨-������
    Calib_Rays_WaitTemp               = 84,      //!< ɨ��궨-����
    Calib_Rays_Stop                   = 85,      //!< ɨ��궨-ֹͣ-����2��������1%��ʼ
    Calib_Rays_TempUp                 = 86,      //!< ɨ��궨-����-���������1��ֵ��������
    Calib_Rays_IsZero                 = 87,      //!< ɨ��궨-��������-�뽫����1��ֵ����
}CALIB_STATE_e;
// ================================================================================================
// the globals

extern I2CMSG I2C_Msg;
extern SPEED_MEAS_M spdM;
extern PMSM_OBJ PMSM;
extern USER_PARM_OBJ UserParm;
extern const CONSTANT_OBJ  UserConst[PARM_NUM];
#if EVCBD_ID == 0x09
extern MAINDRV_OBJ MainDrv;
#endif
extern float const TmTab[TABNNUM];
extern float const IsmTab[TABNNUM];
extern float const TLinTab[TABNNUM][11];
extern float const OmTab[129];
//extern App_Output_bus McuSt;
extern MBD_TEST_OBJ MbdTest;

extern CAN_ISR_TX_OBJ CanIsrTxFlg;
extern RDC_1205   Rdc;
// ================================================================================================
// the function prototypes




// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of GLOBALS

#endif // end of _GLOBALS_H_
