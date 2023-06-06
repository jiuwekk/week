// ================================================================================================
//! \file       ConfigParm.h
//! \brief      
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017Äê4ÔÂ12ÈÕ
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _CONFIGPARM_H_
#define _CONFIGPARM_H_

//! @defgroup CONFIGPARM CONFIGPARM
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================
// the includes

// ================================================================================================
// the defines


// ================================================================================================

#define CONSTANT_DEFAULTS {                                 \
/*Min, Value,            Max,             Name                */\
{0,     0,               0xFFFF }, /* 000 FaultHistory0;      */\
{0,     0,               0xFFFF }, /* 000 FaultHistory1;      */\
{0,     0,               0xFFFF }, /* 000 FaultHistory2;      */\
{0,     0,               0xFFFF }, /* 000 FaultHistory3;      */\
{0,     0,               0xFFFF }, /* 000 FaultHistory4;      */\
{0,     0,               0xFFFF }, /* 000 FaultHistory5;      */\
{0,     0,               0xFFFF }, /* 000 FaultHistory6;      */\
{0,     0,               0xFFFF }, /* 000 FaultHistory7;      */\
{0,     0,               0xFFFF }, /* 000 FaultHistory8;      */\
{0,     0,               0xFFFF }, /* 000 FaultHistory9;      */\
{0,     0,               0xFFFF }, /* 000 FaultHistory10;     */\
{0,     0,               0xFFFF }, /* 000 FaultHistory11;     */\
{0,     0,               0xFFFF }, /* 000 FaultHistory12;     */\
{0,     0,               0xFFFF }, /* 000 FaultHistory13;     */\
{0,     0,               0xFFFF }, /* 000 FaultHistory14;     */\
{0,     0,               0xFFFF }, /* 000 FaultHistory15;     */\
/* PowerDownSave_Menu                                         */\
{0,     0,               0xFFFF }, /* 000 OdometerH;          */\
{0,     0,               0xFFFF }, /* 001 OdometerL;          */\
{0,     0,               0xFFFF }, /* 002 HourMeterH;         */\
{0,     0,               0xFFFF }, /* 003 HourMeterL;         */\
{0,     0,               0xFFFF }, /* 004 SOC;                */\
{0,     0,               0xFFFF }, /* 005 Rsvd                */\
{0,     0,               0xFFFF }, /* 006 Rsvd                */\
{0,     0,               0xFFFF }, /* 007 Rsvd                */\
{0,     0,               0xFFFF }, /* 008 Rsvd                */\
{0,     0,               0xFFFF }, /* 009 Rsvd                */\
{0,     0,               0xFFFF }, /* 010 Rsvd                */\
{0,     0,               0xFFFF }, /* 011 Rsvd                */\
{0,     0,               0xFFFF }, /* 012 Rsvd                */\
{0,     0,               0xFFFF }, /* 013 Rsvd                */\
{0,     0,               0xFFFF }, /* 014 Rsvd                */\
{0,     0,               0xFFFF }, /* 015 Rsvd                */\
/* ConstantParam_Menu                                         */\
{0,     0,               0xFFFF }, /* 016 MfgDate1;           */\
{0,     0,               0xFFFF }, /* 017 MfgDate2;           */\
{0,     0,               0xFFFF }, /* 018 MfgDate3;           */\
{0,     0,               0xFFFF }, /* 019 MfgDate4;           */\
{0,     ELECZERO,        0xFFFF }, /* 020 Rsvd;               */\
{0,     0,               0xFFFF }, /* 021 Rsvd;               */\
{0,     32000,           0xFFFF }, /* 022 Rsvd                */\
{0,     32000,           0xFFFF }, /* 023 Rsvd                */\
{0,     32000,           0xFFFF }, /* 024 Rsvd                */\
{0,     32000,           0xFFFF }, /* 025 Rsvd                */\
{0,     9357,            0xFFFF }, /* 026 Rsvd                */\
{0,     9357,            0xFFFF }, /* 027 Rsvd                */\
{0,     9357,            0xFFFF }, /* 028 Rsvd                */\
{0,     VOLTBUS_RANGE,   0xFFFF }, /* 029 Rsvd                */\
{0,     VOLTCAP_RANGE,   0xFFFF }, /* 030 Rsvd                */\
{0,     0,               0xFFFF }, /* 031 Rsvd                */\
/* Info_Menu                                                  */\
{0,     PARMVER,         0xFFFF }, /* 032 ParamBlkVersion;    CONFIG.H*/\
{0,     0,               0xFFFF }, /* 033 SoftwareVersion;    */\
{0,     0,               0xFFFF }, /* 034 HardwareVersion;    */\
{0,     ELECZERO,        4096   }, /* 035 ElecZero            MotParm*/\
{0,     0,               0xFFFF }, /* 036 MechZero            */\
{0,     VOLTBUS_RANGE,   30000  }, /* 037 Rsvd                EVCBD_PRAM*/\
{0,     VOLTCAP_RANGE,   30000  }, /* 038 Rsvd                EVCBD_PRAM*/\
{0,     0,               0xFFFF }, /* 039 Rsvd                */\
{0,     0,               0xFFFF }, /* 040 Rsvd                */\
{0,     0,               0xFFFF }, /* 041 Rsvd                */\
{0,     0,               0xFFFF }, /* 042 Rsvd                */\
{0,     0,               0xFFFF }, /* 043 Rsvd                */\
{0,     0,               0xFFFF }, /* 044 Rsvd                */\
{0,     0,               0xFFFF }, /* 045 Rsvd                */\
{0,     0,               0xFFFF }, /* 046 Rsvd                */\
{0,     0,               0xFFFF }, /* 047 Rsvd                */\
/* BaseValue_Menu                                             */\
{1,     VOLTBASE,        10000  }, /* 048 VoltBase;           MotParm*/\
{1,     CURBASE,         10000  }, /* 049 CurBase;            MotParm*/\
{1,     SPEEDBASE,       65535  }, /* 050 SpeedBase;          MotParm*/\
/* ModeSettings_Menu                                          */\
{0,     0,               65535  }, /* 051 CtrlMode;           */\
{0,     PEAKPOWER,       65535  }, /* 052 PeakPower;          MotParm*/\
{0,     DIRVECURLIMIT,   65535  }, /* 053 DriveCurLimit;      MotParm*/\
{0,     BRAKECURLIMIT,   65535  }, /* 054 BrakeCurLimit;      MotParm*/\
{0,     8000,            65535  }, /* 055 FwdMaxSpd;          */\
{0,     8000,            65535  }, /* 056 RevMaxSpd;          */\
/* TrqMode_Menu                                               */\
{0,     KP_SPDLIMIT,     65535  }, /* 057 Kp_TrqSpd;          MotParm*/\
{0,     KI_SPDLIMIT,     65535  }, /* 058 Ki_TrqSpd;          MotParm*/\
{0,     1000,            65535  }, /* 059 Kp_TrqCur;          */\
{0,     100,             65535  }, /* 060 Ki_TrqCur;          */\
/* SpdMode_Menu                                               */\
{0,     KP_SPDM0,        65535  }, /* 061 Kp_SpdM0;           MotParm*/\
{0,     KI_SPDM0,        65535  }, /* 062 Ki_SpdM0;           MotParm*/\
{0,     KP_SPDM1,        65535  }, /* 063 Kp_SpdM1;           MotParm*/\
{0,     KI_SPDM1,        65535  }, /* 064 Ki_SpdM1;           MotParm*/\
{0,     KP_SPDM2,        65535  }, /* 065 Kp_SpdM2;           MotParm*/\
{0,     KI_SPDM2,        65535  }, /* 066 Ki_SpdM2;           MotParm*/\
{0,     10000,           65535  }, /* 067 Kp_SpdM3;           */\
{0,     3000,            65535  }, /* 068 Ki_SpdM3;           */\
{0,     0,               65535  }, /* 069 HighSpd;            */\
{0,     0,               65535  }, /* 070 LowSpd;             */\
/* PosMode_Menu                                               */\
{0,     0,               65535  }, /* 071 Spd_Pos_Thr;        */\
{0,     1000,            65535  }, /* 072 Kp_Pos;             */\
{0,     100,             65535  }, /* 073 Ki_Pos;             */\
{0,     0,               65535  }, /* 074 Kd_Pos;             */\
/* MotParam_Menu                                              */\
{0,     0,               65535  }, /* 075 MotType;            */\
{0,     0,               65535  }, /* 076 MotRatedSpd;        */\
{0,     0,               65535  }, /* 077 MotRatedVolt_L2L;   */\
{1,     MOTPOLEPAIRS,    50     }, /* 078 MotPolePairs;       */\
{1,     ENCODERPOLEPAIRS,20     }, /* 079 EncoderPolePairs;   */\
{0,     1024,            65535  }, /* 080 EncoderSteps;       */\
{0,     SWAPENCODERDIR,  1      }, /* 081 SwapEncoderDir;     MotParm*/\
{0,     SWAPPHASE,       1      }, /* 082 SwapPhase;          MotParm*/\
/* FaultParam_Menu                                            */\
{0,     DCOVERVOLT3,     65535  }, /* 083 DcOverVolt3;        MotParm*/\
{0,     DCOVERVOLT2,     65535  }, /* 084 DcOverVolt2;        MotParm*/\
{0,     DCOVERVOLT1,     65535  }, /* 085 DcOverVolt1;        MotParm*/\
{0,     DCUNDERVOLT1,    65535  }, /* 086 DcUnderVolt1;       MotParm*/\
{0,     DCUNDERVOLT2,    65535  }, /* 087 DcUnderVolt2;       MotParm*/\
{0,     DCUNDERVOLT3,    65535  }, /* 088 DcUnderVolt3;       MotParm*/\
{0,     DCOVERCUR,       65535  }, /* 089 DcOverCur1;         MotParm*/\
{0,     ACOVERCUR1,      65535  }, /* 090 AcOverCur1;         MotParm*/\
{0,     ACOVERCUR2,      65535  }, /* 091 AcOverCur2;         MotParm*/\
{0,     OVERSPD1,        65535  }, /* 092 OverSpd1;           MotParm*/\
{0,     OVERSPD2,        65535  }, /* 093 OverSpd2;           MotParm*/\
{0,     0,               65535  }, /* 094 PhaseBrkVari_Thr;   */\
{0,     0,               65535  }, /* 095 PhaseBrkVari_Tmr;   */\
{0,     0,               65535  }, /* 096 PhaseBrkCurRef_Thr; */\
{0,     0,               65535  }, /* 097 PhaseBrkCurfdb_Thr; */\
{0,     0,               65535  }, /* 098 PhaseBrkCur_Tmr;    */\
{0,     0,               65535  }, /* 099 PhaseBrkVolt_Thr;   */\
{0,     0,               65535  }, /* 100 PhaseBrkFilt_Tr;    */\
{0,     9000,            65535  }, /* 101 MotStallCur_Thr;    */\
{0,     15,              65535  }, /* 102 MotStallSpd_Thr;    */\
{0,     5000,            65535  }, /* 103 MotStall_Tmr;       */\
{0,     5000,            65535  }, /* 104 MotStallErrOut;     */\
/* InvTemp_Menu                                               */\
{0,     INVTEMP_TYPE,    65535  }, /* 105 InvTempType;        EVCBD_PRAM*/\
{0,     0,               65535  }, /* 106 InvTempOffSet;      */\
{0,     5000,            65535  }, /* 107 InvTempErrOut;      */\
{0,     95,              65535  }, /* 108 InvOverTemp3;       */\
{0,     85,              65535  }, /* 109 InvOverTemp2;       */\
{0,     75,              65535  }, /* 110 InvOverTemp1;       */\
/* MotTemp_Menu                                               */\
{0,     MOTTEMPTYPE,     65535  }, /* 111 MotTempType;        EVCBD_PRAM*/\
{0,     0,               65535  }, /* 112 MotTempOffSet;      */\
{0,     5000,            65535  }, /* 113 MotTempErrOut;      */\
{0,     165,             65535  }, /* 114 MotOverTemp3;       */\
{0,     150,             65535  }, /* 115 MotOverTemp2;       */\
{0,     140,             65535  }, /* 116 MotOverTemp1;       */\
/* Vehicle_Menu                                               */\
{0,     0,               65535  }, /* 117 GearRatio;          */\
{0,     0,               65535  }, /* 118 TireDiameter;       */\
{0,     0,               65535  }, /* 119 CaptureSpd;         */\
/* Throttle_Menu                                              */\
{0,     0,               65535  }, /* 120 ThrottleType;       */\
{0,     0,               65535  }, /* 121 ThrottleDeadband;   */\
{0,     0,               65535  }, /* 122 ThrottleMap;        */\
{0,     0,               65535  }, /* 123 ThrottleMax;        */\
{0,     0,               65535  }, /* 124 ThrottleOffset;     */\
/* MainContact_Menu                                           */\
{0,     0,               65535  }, /* 125 MainDrv_En;         */\
{0,     50,              65535  }, /* 126 MainDNC_Thr;        */\
{0,     0,               65535  }, /* 127 PreCharge_En;       */\
{0,     50,              65535  }, /* 128 PreChargeTim1;      */\
{0,     2000,            65535  }, /* 129 PreChargeTim2;      */\
{0,     500,             65535  }, /* 130 PreChargeTim3;      */\
{0,     2000,            65535  }, /* 131 DisChargeTim1;      */\
{0,     1000,            3000   }, /* 132 DisChargeCur1;      */\
/* TimeConstant_Menu                                          */\
{0,     300,             65535  }, /* 133 Spd_Tr;             */\
{0,     30,              65535  }, /* 134 VDC_Tr;             */\
{0,     10,              65535  }, /* 135 IDC_Tr;             */\
{0,     10,              65535  }, /* 136 LogicV_Tr;          */\
{0,     10,              65535  }, /* 137 MotTemp_Tr;         */\
{0,     10,              65535  }, /* 138 InvTemp_Tr;         */\
{0,     10,              65535  }, /* 139 Is_Tr;              */\
{0,     10,              65535  }, /* 140 Id_Tr;              */\
{0,     10,              65535  }, /* 141 Iq_Tr;              */\
{0,     10,              65535  }, /* 142 Vs_Tr;              */\
{0,     10,              65535  }, /* 143 Vd_Tr;              */\
{0,     10,              65535  }, /* 144 Vq_Tr;              */\
{0,     10,              65535  }, /* 145 Beta_Tr;            */\
{0,     2000,            65535  }, /* 146 CutBack_Tr;         */\
{0,     10,              65535  }, /* 147 IpL_Tr;             */\
{0,     10,              65535  }, /* 148 nCt_Tr;             */\
{0,     10,              65535  }, /* 149 Ins_Tr;             */\
{0,     10,              65535  }, /* 150 IsL_Tr;             */\
{0,     10,              65535  }, /* 151 iWe_Tr;             */\
{0,     10,              65535  }, /* 152 Mr_Tr;              */\
{0,     10,              65535  }, /* 153 Vd0_Tr;             */\
{0,     10,              65535  }, /* 154 Vq0_Tr;             */\
{0,     10,              65535  }, /* 155 VdE_Tr;             */\
{0,     10,              65535  }, /* 156 VqE_Tr;             */\
/* Debug_Menu                                                 */\
{0,     0,               65535  }, /* 157 DebugMode;          */\
{0,     10000,           65535  }, /* 158 VsMax;              */\
{0,     KP_ID,           65535  }, /* 159 Kp_Id;              MotParm*/\
{0,     KI_ID,           65535  }, /* 160 Ki_Id;              MotParm*/\
{0,     KP_IQ,           65535  }, /* 161 Kp_Iq;              MotParm*/\
{0,     KI_IQ,           65535  }, /* 162 Ki_Iq;              MotParm*/\
{0,     KP_FW1,          65535  }, /* 163 Kp_FW1;             MotParm*/\
{0,     KI_FW1,          65535  }, /* 164 Ki_FW1;             MotParm*/\
{0,     KP_FW2,          65535  }, /* 165 Kp_FW2;             MotParm*/\
{0,     KI_FW2,          65535  }, /* 166 Ki_FW2;             MotParm*/\
{0,     KP_IDCLIMIT,     65535  }, /* 167 Kp_IdcLmt;          MotParm*/\
{0,     KI_IDCLIMIT,     65535  }, /* 168 Ki_IdcLmt;          MotParm*/\
{0,     65535,           65535  }, /* 169 FaultMask1_0;       */\
{0,     65535,           65535  }, /* 170 FaultMask1_1;       */\
{0,     65535,           65535  }, /* 171 FaultMask1_2;       */\
{0,     65535,           65535  }, /* 172 FaultMask1_3;       */\
{0,     65535,           65535  }, /* 173 FaultMask2_0;       */\
{0,     65535,           65535  }, /* 174 FaultMask2_1;       */\
{0,     65535,           65535  }, /* 175 FaultMask2_2;       */\
{0,     65535,           65535  }, /* 176 FaultMask2_3;       */\
{0,     0,               65535  }, /* 177 HarmonicComp;       */\
{0,     1,               1      }, /* 178 SVPWM_SEGs;         */\
{0,     0,    			 8      }, /* 179 CalibratStep;       */\
{0,     0,    			 1      }, /* 180 ElecStudyType;      */\
{1,     IF, 			 65535  }, /* 181 If;                 */\
{1,     BEMF, 			 65535  }, /* 182 Bemf;               */\
{0,     5400,            6000   }, /* 183 VsMaxRef;           */\
{0,     8000,            10001  }, /* 184 SlopeIsMax;         */\
{0,     8000,            10001  }, /* 185 rsvd185;            */\
{0,     8000,            10001  }, /* 186 rsvd186;            */\
{0,     500,             1000   }, /* 187 TuneFreqCoef;       */\
{0,     PWM_LOW_FREQ,    50000  }, /* 188 FreqLow;            */\
{0,     PWM_HIGH_FREQ,   50000  }, /* 189 FreqUp;             */\
{0,     1200,            10000  }, /* 190 ASCSpd;             */\
{0,     100,             1000   }, /* 191 DamperTimer;        */\
{0,     100,             10000  }, /* 192 DamperGain;         */\
{0,     0,             10000    }, /* 193 CalibMTPATheta;     */\
{0,     0,             100    },   /* 194 FLStartAng;         */\
{0,     0,             1        }, /* 195 HighDevice;         */\
{0,     0,             4096    }, /* 196 SpeadRef;         */\
{0,     0,             4096    }} /* 197 CUR_W;         */\

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

//! @} // end of CONFIGPARM

#endif // end of _CONFIGPARM_H_
