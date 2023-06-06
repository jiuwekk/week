// ================================================================================================
//! \file       Globals.h
//! \brief      应用层全局变量声明及初始值
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017年3月23日
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
// 故障结构体类型定义
typedef union
{
    uint16_t  All[4];
    struct
    {
        uint16_t PwrMdlErr        :1;         //(1,1)  IGBT模块故障,驱动光耦
        uint16_t CurSensorErr     :1;         //(1,2)  相电流传感器
        uint16_t MotStallErr      :1;         //(1,3)  电机堵转？？？
        uint16_t AcOverCur2Err    :1;         //(1,4)  相过流2
        uint16_t AcOverCur1Err    :1;         //(1,5)  相过流1 0扭矩
        uint16_t PreChargeErr     :1;         //(1,6)  预充失败
        uint16_t PhaseBrkErr      :1;         //(1,7)  相线开路
        uint16_t DcOverVolt3Err   :1;         //(1,8)  过压3 不可恢复

        uint16_t DcOverVolt2Err   :1;         //(2,1)  过压2 发电0扭矩
        uint16_t DcOverVolt1Err   :1;         //(2,2)  过压1
        uint16_t DcUnderVolt1Err  :1;         //(2,3)  欠压1
        uint16_t DcUnderVolt2Err  :1;         //(2,4)  欠压2 驱动0扭矩
        uint16_t DcUnderVolt3Err  :1;         //(2,5)  欠压3 不可恢复
        uint16_t Main_DNC_Err     :1;         //(2,6)  主接触器压差
        uint16_t OverSpeed2Err    :1;         //(2,7)  超速 2
        uint16_t DcOverCur1Err    :1;         //(2,8)  母线过流            1.1*峰值

        uint16_t Rsvd2            :8;         //(3,1)  预留
        uint16_t Rsvd3            :8;         //(4,1)  预留

        uint16_t OverSpeed1Err    :1;         //(5,1)  超速 1 0扭矩
        uint16_t MotOverTemp3Err  :1;         //(5,2)  电机过温3       160 关管
        uint16_t InvOverTemp3Err  :1;         //(5,3)  模块过温3       95 关管
        uint16_t LogicPowerErr    :1;         //(5,4)  24V故障
        uint16_t Rsvd4_4          :1;         //(5,5)  预留
        uint16_t PosSensorErr     :1;         //(5,6)  旋变故障关管
        uint16_t Rsvd4_6          :1;         //(5,7)  预留
        uint16_t MotOverTemp2Err  :1;         //(5,8)  电机过温2       140 零扭矩

        uint16_t MotOverTemp1Err  :1;         //(6,1)  电机过温1       130 线性限扭矩
        uint16_t InvOverTemp2Err  :1;         //(6,2)  模块过温2       85 零扭矩
        uint16_t InvOverTemp1Err  :1;         //(6,3)  模块过温1       75 线性限扭矩
        uint16_t MotTempSensorErr1:1;         //(6,4)  PT100#1
        uint16_t MotTempSensorErr2:1;         //(6,5)  PT100#2
        uint16_t InvTempSensorErr1:1;         //(6,6)  NTC#1
        uint16_t InvTempSensorErr2:1;         //(6,7)  NTC#2
        uint16_t InvTempSensorErr3:1;         //(6,8)  NTC#3

        uint16_t ParErr           :1;         //(7,1)  EE参数
        uint16_t ParChangeErr     :1;         //(7,2)  参数修改错误
        uint16_t Msg1LostErr      :1;         //(7,3)  Vcu指令通信
        uint16_t Msg2LostErr      :1;         //(7,4)  Vcu限制通信
        uint16_t DisChgWarnErr    :1;         //(7,5)  主动放电告警
        uint16_t DisChgOverTmErr  :1;         //(7,6)  主动放电超时
        uint16_t Rsvd6_6          :1;         //(7,7)  预留
        uint16_t Rsvd6_7          :1;         //(7,8)  预留

        uint16_t ErrLevel         :3;
        uint16_t Rsvd7            :5;         //(8,1)  预留
    }M3_FAULT_OBJ;
}FAULT_OBJ;

#define FAULT_OBJ_DEFAULTS {0,0,0,0}
// --------------------------------------------------------
//! 用户参数表
typedef struct
{
    // FaultHistory_Menu
    uint16_t FaultHis[16];     // 000 EE用于存储历史故障
    // PowerDownSave_Menu
    uint16_t OdometerH;        // 000 行驶总里程高，控制器做整车功能可用
    uint16_t OdometerL;        // 001 行驶总里程低，控制器做整车功能可用
    uint16_t HourMeterH;       // 002 控制器运行时间高
    uint16_t HourMeterL;       // 003 控制器运行时间低
    uint16_t SOC;              // 004 控制器做整车功能可用
    uint16_t Rsvd0[11];        // 005 - 015
    // ConstantParam_Menu
    uint16_t MfgDate1;         // 016 生产序列号1
    uint16_t MfgDate2;         // 017 生产序列号2
    uint16_t MfgDate3;         // 018 生产序列号3
    uint16_t MfgDate4;         // 019 生产序列号4
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
    uint16_t ParamBlkVersion;  // 032 参数版本
    uint16_t SoftwareVersion;  // 033 软件版本
    uint16_t HardwareVersion;  // 034 硬件版本
    uint16_t ElecZero;         // 035 电机零点
    uint16_t MechZero;         // 036 机械零点
    uint16_t Rsvd2[11];        // 037 - 047
    // BaseValue_menu
    uint16_t VoltBase;         // 048 电压基值
    uint16_t CurBase;          // 049 电流基值
    uint16_t SpeedBase;        // 050 转速基值
    // ModeSettings_Menu
    uint16_t CtrlMode;         // 051 控制模式
    uint16_t PeakPower;        // 052 峰值功率限制
    uint16_t DriveCurLimit;    // 053 驱动限制电流
    uint16_t BrakeCurLimit;    // 054 发电限制电流
    uint16_t FwdMaxSpd;        // 055 前进方向限速
    uint16_t RevMaxSpd;        // 056 后退方向限速
    // TrqMode_Menu
    uint16_t Kp_TrqSpd;        // 057 扭矩模式限制转速 Kp
    uint16_t Ki_TrqSpd;        // 058 扭矩模式限制转速 Ki
    uint16_t Kp_TrqCur;        // 059 扭矩模式限制电流 Kp
    uint16_t Ki_TrqCur;        // 060 扭矩模式限制电流 Ki
    // SpdMode_Menu
    uint16_t Kp_SpdM0;         // 061 转速环模式 Kp
    uint16_t Ki_SpdM0;         // 062 转速环模式 Ki
    uint16_t Kp_SpdM1;         // 063 待用
    uint16_t Ki_SpdM1;         // 064 待用
    uint16_t Kp_SpdM2;         // 065 待定
    uint16_t Ki_SpdM2;         // 066 待定
    uint16_t Kp_SpdM3;         // 067 驻坡模式 Kp
    uint16_t Ki_SpdM3;         // 068 驻坡模式 Ki
    uint16_t HighSpd;          // 069 高速阈值，根据不同转速，使用不同的Kp和Ki系数使用
    uint16_t LowSpd;           // 070 低速阈值，根据不同转速，使用不同的Kp和Ki系数使用
    // PosMode_Menu
    uint16_t Spd_Pos_Thr;      // 071 转速和位置阈值
    uint16_t Kp_Pos;           // 072 位置环Kp
    uint16_t Ki_Pos;           // 073 位置环Ki
    uint16_t Kd_Pos;           // 074 位置环Kd
    // MotParam_Menu
    uint16_t MotType;          // 075 电机类型
    uint16_t MotRatedSpd;      // 076 电机额定转速
    uint16_t MotRatedVolt_L2L; // 077 电机额定线电压
    uint16_t MotPolePairs;     // 078 电机极对数
    uint16_t EncoderPolePairs; // 079 旋变极对数
    uint16_t EncoderSteps;     // 080 编码器线数
    uint16_t SwapEncoderDir;   // 081 交换旋变方向
    uint16_t SwapPhase;        // 082 交换相序
    // FaultParam_Menu
    uint16_t DcOverVolt3;      // 083 过压阈值3
    uint16_t DcOverVolt2;      // 084 过压阈值2
    uint16_t DcOverVolt1;      // 085 过压阈值1
    uint16_t DcUnderVolt1;     // 086 欠压阈值1
    uint16_t DcUnderVolt2;     // 087 欠压阈值2
    uint16_t DcUnderVolt3;     // 088 欠压阈值3
    uint16_t DcOverCur1;       // 089 母线过流
    uint16_t AcOverCur1;       // 090 AC过流1
    uint16_t AcOverCur2;       // 091 AC过流2
    uint16_t OverSpd1;         // 092 超速阈值1
    uint16_t OverSpd2;         // 093 超速阈值2
    uint16_t PhaseBrkVari_Thr; // 094
    uint16_t PhaseBrkVari_Tmr; // 095
    uint16_t PhaseBrkCurRef_Thr;// 096
    uint16_t PhaseBrkCurfdb_Thr;// 097
    uint16_t PhaseBrkCur_Tmr;  // 098
    uint16_t PhaseBrkVolt_Thr; // 099
    uint16_t PhaseBrkFilt_Tr;  // 100
    uint16_t MotStallCur_Thr;  // 101 堵转电流阈值
    uint16_t MotStallSpd_Thr;  // 102 堵转转速阈值
    uint16_t MotStall_Tmr;     // 103 堵转时间阈值
    uint16_t MotStallErrOut;   // 104 堵转故障输出
    // InvTemp_Menu
    uint16_t InvTempType;      // 105 控制器温度传感器类型
    uint16_t InvTempOffSet;    // 106 控制器温度传感器偏置
    uint16_t InvTempErrOut;    // 107 控制器温度传感器故障输出
    uint16_t InvOverTemp3;     // 108 控制器过温3阈值
    uint16_t InvOverTemp2;     // 109 控制器过温2阈值
    uint16_t InvOverTemp1;     // 110 控制器过温1阈值
    // MotTemp_Menu
    uint16_t MotTempType;      // 111 电机温度传感器类型
    uint16_t MotTempOffSet;    // 112 电机温度传感器偏置
    uint16_t MotTempErrOut;    // 113 电机温度传感器故障输出
    uint16_t MotOverTemp3;     // 114 电机过温3阈值
    uint16_t MotOverTemp2;     // 115 电机过温2阈值
    uint16_t MotOverTemp1;     // 116 电机过温1阈值
    // Vehicle_Menu
    uint16_t GearRatio;        // 117 齿轮速比
    uint16_t TireDiameter;     // 118 车轮直径
    uint16_t CaptureSpd;       // 119 捕捉速度
    // Throttle_Menu
    uint16_t MainDrvCompEn;    // 120
    uint16_t MainDrvPullInVolt;// 121
    uint16_t MainDrvHoldVolt;  // 122
    uint16_t PWM2PullInVolt;   // 123
    uint16_t PWM2HoldVolt;     // 124
    // MainContact_Menu
    uint16_t MainDrv_En;       // 125 主接触器使能
    uint16_t MainDNC_Thr;      // 126 主接触器断开阈值
    uint16_t PreCharge_En;     // 127 预充电使能
    uint16_t PreChargeTim1;    // 128 预充时间1
    uint16_t PreChargeTim2;    // 129 预充时间2
    uint16_t PreChargeTim3;    // 130 预充时间3
    uint16_t DisChargeTim1;    // 131 主动放电时间
    uint16_t DisChargeCur1;    // 132 主动放电电流
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
    uint16_t TuneFreqCoef;     // 187 变频系数
    uint16_t FreqLow;          // 188 载波最低频
    uint16_t FreqUp;           // 189 载波最高频
    uint16_t ASCSpd;           // 190 ASC使能速度
    uint16_t DamperTimer;      // 191 主动阻尼滤波时间
    uint16_t DamperGain;       // 192 主动阻尼增益系数
    uint16_t CalibMTPATheta;   // 193 起始标定MTPA角度   [0 pi/2]  rad  0.01精度
    uint16_t FLStartAng;       // 194 扫面角度（二象限对Q轴）（角度制）  0.01精度
    uint16_t HighDevice;       // 195 高边驱动使用
    uint16_t SpeadRef;         // 195 U相电流AD
    uint16_t CUR_W;            // 195 W相电流AD
}USER_OBJ;

#define PARM_NUM (sizeof(USER_OBJ))

//!  用户参数管理结构体类型
typedef struct
{
    USER_OBJ   Var;       //!< Variable
    USER_OBJ   Sts;       //!< Variable Status
    int16_t    ErrCode;   //!< 错误码
    int16_t    ErrIndex;  //!< 错误参数的下标
    uint16_t*  VarPnt;    //!< 指针，指向OBJ->Var
    uint16_t*  StsPnt;    //!< 指针，指向OBJ->Sts
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

//! \brief     用户参数初始化
//! \param[in] v    Handle to USER_PARM_OBJ object
extern void ParmInit(USER_PARM_OBJ* v);


//! \brief     用户参数管理状态机，管理参数更新
//! \param[in] v    Handle to USER_PARM_OBJ object
extern void ParmStateflow(USER_PARM_OBJ* v);


typedef enum
{
    PARM_IDLE = 0,          //!< 空闲，参数无操作
    PARM_WRITING = 1,       //!< 参数写入EEPROM过程中
    PARM_WRITE_ERR = 2,     //!< 参数写入EEPROM过程中，出现错误
    PARM_READ_ERR = 3,      //!< 参数从EEPROM读取过程中，出现错误
    PARM_RANGE_ERR = 4      //!< 参数超出范围
}PARM_STATE_e;


typedef struct
{
    uint16_t Min;
    uint16_t Var;
    uint16_t Max;
}CONSTANT_OBJ;

// ----------------------------------------------------------------------------
// 传感器
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
// 一定要定义成3的倍数，否则实时监控数据索引会出现问题 PMSM_Input
}WATCH_VAR_OBJ;
                              //  0     1     2     3     4     5     6     7     8     9
#define WATCH_VAR_OBJ_DEFAULTS {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}//,0,0,0,\
//                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
//                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
//                                0,0,0}

#define WATCH_NUM (sizeof(WATCH_VAR_OBJ))

typedef struct
{
    WATCH_VAR_OBJ Var;    //!< 监控变量
    uint16_t* VarPnt;     //!< 指针，指向OBJ->Var
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
    uint32_t DCRelayState:1;   // 预充完成
    uint32_t MotGateReq  :1;   // 系统使能
    uint32_t HandBrake   :1;   // 脚刹信号
    uint32_t FootBrake   :1;   // 手刹信号
    uint32_t GearPos     :8;   // 挡位   0：空挡 1：前进 2：后退
    uint32_t MotModeReq  :8;   // 动作指令：0：转矩 1：转速 2：发电 3：驱动 4：驻坡 5：同步 6：主动断电 7：主动短路 15：停机
    uint32_t Rsvd0:12;

    float MotTqReq;            // 扭矩请求 1/4096
    float MotTqRef2;           // 扭矩请求 1/4096，用于电机标定
    float MotSpdReq;           // 转速请求 rpm
    float MotSpdLim;           // 限制转速,扭矩环起作用
    float MotSpdHold;          // 驻坡转速
    float BusCurGeneLim;       // 发电母线限流             无符号 1A
    float BusCurDriveLim;      // 驱动母线限流            无符号 1A
    float MotTorqLimPos;       // 扭矩限制正向             1/4096，转速环中起作用
    float MotTorqLimNeg;       // 转矩限制反向            1/4096，转速环中起作用

}MOT_CMD_OBJ;
#define MOT_CMD_OBJ_DEFAULTS {0,0,0,0,0,0,0,\
                              0,0,0,0,0,500,500,1.0,-1.0}

typedef struct
{
    uint16_t Fault[4];
    float MotTqReal;           // 实际扭矩
    float MotSpdReal;          // 实际转速
    float MotTqMax;            // 最大转矩
    float BusCurrent;          // 母线电流
    float BusVoltage;          // 母线电压（电控端）
    float InvTemp;             // 温度
    float MotTemp;             // 温度
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
    TorqueMod = 0,             //!< 扭矩模式
    SpeedMod  = 1,             //!< 速度模式
    GeneMod   = 2,             //!< 发电模式
    DriveMod  = 3,             //!< 驱动模式
    SlopeMod  = 4,             //!< 驻坡模式
    SyncMod   = 5,             //!< 同步模式
    ActDisChgMod = 6,          //!< 主动放电模式
    StopMod   = 15,            //!< 停止模式
}VCU_MODE_REQ_e;

typedef enum
{
    Gear_N = 0,        // 空挡
    Gear_D = 1,        // 前进
    Gear_R = 2,        // 后退
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
// 变量滤波系数

typedef struct
{
    float Spd_Tr;         //!< 时基： 中断
    float VDC_Tr;         //!< 时基： 中断
    float IDC_Tr;         //!< 时基： 中断
    float LogicV_Tr;      //!< 时基： 主循环
    float MotTemp_Tr;     //!< 时基： 主循环
    float InvTemp_Tr;     //!< 时基： 主循环
    float Is_Tr;          //!< 时基： 中断
    float Id_Tr;          //!< 时基： 中断
    float Iq_Tr;          //!< 时基： 中断
    float Vs_Tr;          //!< 时基： 中断
    float Vd_Tr;          //!< 时基： 中断
    float Vq_Tr;          //!< 时基： 中断
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
// 电机控制所需变量
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
    float VoltBus;              //!< 000 [0.1V]  母线电压  Battery Voltage;
    float VoltBusFilted;        //!< 001 [0.1V]  母线电压滤波值  Battery Voltage;
    float VoltBus_pu;           //!< 002 [pu]    母线电压标幺值  Battery Voltage;
    float CurBus;               //!< 003 [pu]    母线电流  Battery Current;
    float Power;                //!< 004 [pu]    (Vd*Id + Vq*Iq)*Vc
    float VoltCap;              //!< 005 [0.1V]  电容电压   Capacitor Voltage;
    float VoltCapFilted;        //!< 006 [0.1V]  电容电压滤波值    Capacitor Voltage Filted;
    float VoltCap_pu;           //!< 007 [pu]    电容电压标幺值    Capacitor Voltage;
    float VoltCap_pui;          //!< 008 [pu]    电容电压逆向标幺值    Capacitor Voltage Inverse;
    float VoltMax_pu;           //!< 009 [pu]    电容电压与电池电压最大值   Max(VoltCap,VoltBus);
    float VoltU;                //!< 010 [pu]    U相电压   Phase U voltage line to line
    float VoltV;                //!< 011 [pu]    V相电压   Phase V voltage line to line
    float VoltW;                //!< 012 [pu]    W相电压   Phase W voltage line to line
    float CurU;                 //!< 013 [pu]    U相电流   Phase U current
    float CurV;                 //!< 014 [pu]    V相电流   Phase V current
    float CurW;                 //!< 015 [pu]    W相电流   Phase W current
    float MotTemp1;             //!< 016 [℃]    NTC1采集的温度   Motor temperature 1
    float MotTemp2;             //!< 017 [℃]    NTC2采集的温度   Motor temperature 2
    float MotTemp;              //!< 018 [℃]    实际的电机温度      Motor temperature sent to the VCU
    float InvTemp1;             //!< 019 [℃]    IGBT温度1 IGBT temperature 1
    float InvTemp2;             //!< 020 [℃]    IGBT温度2 IGBT temperature 2
    float InvTemp3;             //!< 021 [℃]    IGBT温度3 IGBT temperature 3
    float InvTemp;              //!< 022 [℃]    IGBT实际温度   IGBT temperature sent to the VCU
    float N_Base;               //!< 023 [rpm]   转速基值   Mechanical speed
    float Nm;                   //!< 024 [rpm]   实际转速   Mechanical speed
    float Nm_pu;                //!< 025 [pu]    转速标幺值  Mechanical speed
    float NmFilted;             //!< 026 [rpm]   采集电机实际转速后滤波的电机转速  Mechanical speed
    float Ne;                   //!< 027 [rpm]   电转速    Electric speed
    float Ne_pu;                //!< 028 [pu]    电转速标幺值 Electric speed
    int16_t ThetaRT;            //!< 029 [0-4095]实际角度   Real time angle
    int16_t ThetaRawE;          //!< 030 [0-4095]机械角度   Rotor electric angle
    int16_t ThetaRawM;          //!< 031 [0-4095]电角度    Rotor mechanical angle
    int16_t ThetaMech;          //!< 032 [0-4095]机械角度   Mechanical angle
    float ThetaElec;            //!< 033 [pu]    FOC用的电角度   Electric angle for FOC
    float Cutback;              //!< 034 [pu]    扭矩关管   Torque Cutback;
    float CutBackFilted;        //!< 035 [pu]    扭矩关管滤波值    Torque Cutback filted;
    float InvTempCutback;       //!< 036 [pu]    控制器过温关管
    float MotTempCutback;       //!< 037 [pu]    电机过温关管
    float OverVoltCutback;      //!< 038 [pu]    过压关管
    float UnderVoltCutback;     //!< 039 [pu]    欠压关管
    float IdcDrvLmtCutBack;     //!< 040 [pu]    驱动限流关管     Idc limit
    float IdcGenLmtCutBack;     //!< 041 [pu]    发电限流关管     Idc limit
    float IdRef;                //!< 042 [pu]    Id给定
    float IdRef_Filted;         //!< 043 [pu]    Id给定滤波值
    float If;                   //!< 044 [pu]    特征电流
    float Id;                   //!< 045 [pu]    Id实际值
    float IdFilted;             //!< 046 [pu]    Id滤波值
    float IqRef;                //!< 047 [pu]    Iq给定
    float Iq;                   //!< 048 [pu]    Iq实际值
    float IqFilted;             //!< 049 [pu]    Iq滤波值
    float CmdIsRef;             //!< 050 [pu]    VCU发来的扭矩请求对应的Is给定   IsRef from the VCU torque request
    float Rsvd51;               //!< 051 [pu]
    float IsRef;                //!< 052 [pu]    FOcus用的Is给定    IsRef for FOC
    float IsPosLmt;             //!< 053 [pu]    Is正向限制
    float IsNegLmt;             //!< 054 [pu]    Is负向限制
    float Is;                   //!< 055 [pu]    Is实际值
    float IsFilted;             //!< 056 [pu]    Is滤波值
    float Vd;                   //!< 057 [pu]    Vd实际值
    float VdFilted;             //!< 058 [pu]    Vd滤波值
    float Vq;                   //!< 059 [pu]    Vq实际值
    float VqFilted;             //!< 060 [pu]    Vq滤波值
    float Vs;                   //!< 061 [pu]    VS实际值
    float VsFilted;             //!< 062 [pu]    VS滤波值
    float VsMax;                //!< 063 [pu]    VS最大值（标定电压）
    float FwErr;                //!< 064 [pu]    弱磁故障
    float IdWeak;               //!< 065 [pu]    Id角度返回值
    float AngleMTPA;            //!< 066 [pu]    MTPA角度值
    float AngleWeak;            //!< 067 [pu]
    float IdTorq;               //!< 068 [pu]    Id对应的扭矩
    float Ld ;                  //!< 069 [pu]    D轴电感
    float Pot1Volt;             //!< 070 [pu]
    float Pot1Cmd;              //!< 071 [pu]
    float Brd05V;               //!< 072 [pu]
    float Brd12V;               //!< 073 [pu]
    float Brd24V;               //!< 074 [pu]
    float PolesRatio;           //!< 075 [pu]  motor and encoder poles ratio
    float DisChargeCur;         //!< 076 [pu]
    uint16_t PwmLowFreq;        //!< 077 [Hz]  PWM低频值  PWM
    uint16_t PwmHighFreq;       //!< 078 [Hz]  PWM高频值  PWM
    uint16_t PwmLowFreq_Hz;     //!< 079 [Hz]  PWM低频    motor
    uint16_t PwmHighFreq_Hz;    //!< 080 [Hz]  PWM高频    motor
    float    PwmMotSpeed_Hz;    //!< 081 [Hz]  当前电机转速
    float    PwmOutFreq;        //!< 082 [Hz]  PWM变频后频率
    float    PwmOutPeriod;      //!< 083 [us]  PWM变频后周期，赋值给PWM周期中断函数中
    float    TabNStart;         //!< 084 [rpm]
    float    TabNEnd;           //!< 085 [rpm]
    float    TabNStep;          //!< 086 [rpm] 表转速间距
    float    TabNRefU;          //!< 087 [rpm]
    float    NVComp;            //!< 088 []    转速电压比
    uint16_t ModeReq;           //!< 089
    uint16_t ModeHis;           //!< 090
    uint16_t MotStudyStep;      //!< 091
    uint16_t MotStudyResult;    //!< 092
    float    NmFiltedVCU;       //!< 093 []    VCU发来的期望转速滤波后的转速
    float    TqLimit;           //!< 094 []    电机当前输出扭矩能力
    int16_t  TqMax;             //!< 095 [Nm]  最大扭矩
    int16_t  TqReal;            //!< 096 [Nm]  实际扭矩
    float    PhaseBrkIdErr;     //!< 097 []    d轴方差
    float    PhaseBrkIdErrFilted;//!< 098 []
    float    PhaseBrkIqErr;      //!< 099 []   q轴方差
    float    PhaseBrkIqErrFilted;//!< 100 []
    float    MotTemp1His;        //!< 101 [℃]    电机历史温度1    Motor temperature 1
    float    MotTemp2His;        //!< 102 [℃]    电机历史温度2    Motor temperature 2
    float    KCurrPIComp;        //!< 103 []
    float    TqMaxOutCutback;    //!< 104 [pu]   Torque Cutback;
    float    PWM1Duty;           //!< 105 0-1 PWM占空比
    float    VehicleSpd;         //!< 106 车速
    float    TotalMileage;       //!< 107 总里程
    float    SingleMileage;      //!< 108 单次里程
    float    fRpmToSpdK;         //!< 109

    float    TestData1;          //!< 196 []
    float    TestData2;          //!< 197 []
    float    TestData3;          //!< 198 []
    float    TestData4;          //!< 199 []
    float    AngleEExSet;
    float    AngleE1ExSet;
    float    IdRefExSet;
    float    IqRefExSet;
    float MotTemp1cal;             //!< 016 [℃]    NTC1采集的温度   Motor temperature 1
    float MotTemp2cal;             //!< 017 [℃]    NTC2采集的温度   Motor temperature 2
    float VoltBase_reciprocal;             //!< 母线电压倒数

    uint16_t FaultGrade;         // 故障等级

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
// 主接触器
typedef union
{
    uint16_t All;
    struct
    {
        uint32_t MainDrvSet:1;       //!< 接触器吸合给定
        uint32_t PreChargeRdy:1;     //!< 预充电过程
        uint32_t PreChargeFail:1;    //!< 预充电结果
        uint32_t VoltDiff:1;         //!< 接触器触点压差状态
    }Bits;
}MAINDRV_STS;
#define MAINDRV_STS_DEFAULTS {0}
typedef struct
{
    float VoltBus;
    float VoltCap;
    float VoltCapHis;
    uint16_t MainOn;    //!< 接触器当前状态
    uint16_t State;     //!< 状态机状态变量
    uint16_t Delay0;    //!< 电源反接测试计时器
    uint16_t Delay1;    //!< 电容充电计时器
    uint16_t Delay2;    //!< 续充计时器，满足压差后，续充时间
    uint16_t Delay3;    //!< 接触器吸合时间，触电动作时间

    MAINDRV_STS Sts;
}MAINDRV_OBJ;
#define MAINDRV_OBJ_DEFAULTS { 0,0,0,0,0,0,0,0,0,\
                               MAINDRV_STS_DEFAULTS}
#endif
typedef struct
{
    MOT_INTF_OBJ  Intf;         //!< 电机控制接口
    MOT_STATE_OBJ StateFlow;    //!< 控制器运行状态
    LPF_COEF_OBJ  Lpf_Coef;     //!< 低通滤波器的系数计算
    PMSM_VAR_OBJ  Var;          //!< 电机控制相关变量
    SENSOR_OBJ    Sens;         //!< 传感器
    FAULT_OBJ     FaultNow;     //!< 当前故障
    FAULT_OBJ     FaultMask;    //!< 故障检测MASK
    FAULT_OBJ     FauErr ;      //!< 过压故障

    PI_OBJ        PI_Pos;       //!< 位置环PI
    PI_OBJ        PI_Spd;       //!< 速度环PI
    PI_OBJ        PI_TrqSpd;    //!< 扭矩环限速PI
    PI_OBJ        PI_TrqCur;    //!< 扭矩环电流PI
    PI_OBJ        PI_Id;        //!< Id跟踪PI
    PI_OBJ        PI_Iq;        //!< Iq跟踪PI
    PI_OBJ        PI_FW;        //!< 弱磁PI
    PI_OBJ        PI_Angle;     //!< 弱磁PI2
    PI_OBJ        PI_Slope;     //!< 驻坡模式
    PI_OBJ        PI_ASC;       //!< ASC模式PI
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
        uint16_t PAR  :1;       //!< 奇偶校验
        uint16_t LOT  :1;       //!< 信号丢失
        uint16_t DOS  :1;       //!< 信号劣化
        uint16_t RDVEL:1;       //!< 位置(1)or速度(0)
        uint16_t Loc  :12;
    }M1;
}RDC_1205;

typedef enum
{
    Calib_Idle                = 0,              //!< 标定停止
    Calib_PhaseStudy_Idle     = 10,             //!< 相线学习等待-深踩油门大约50;
    Calib_PhaseStudy_Online   = 11,             //!< 相线学习中
    Calib_PhaseStudy_OkRev    = 12,             //!< 相线学习成功-反向
    Calib_PhaseStudy_OkPos    = 13,             //!< 相线学习成功-正向
    Calib_PhaseStudy_Err      = 14,             //!< 相线学习失败
//    Calib_ElecZeroStudy_Drag_Idle    = 20,      //!< 零点学习-被拖-等待
//    Calib_ElecZeroStudy_Drag_Online1 = 21,      //!< 零点学习-被拖-粗调
//    Calib_ElecZeroStudy_Drag_Online2 = 22,      //!< 零点学习-被拖-粗调
//    Calib_ElecZeroStudy_Drag_Ok      = 23,      //!< 零点学习-被拖-完成
//    Calib_ElecZeroStudy_Drag_Err     = 24,      //!< 零点学习-被拖-失败
    Calib_ElecZeroStudy_Rotate_Idle   = 30,      //!< 零点学习-自转-等待
    Calib_ElecZeroStudy_Rotate_U0Lock = 31,      //!< 零点学习-自转-找默认零点
    Calib_ElecZeroStudy_Rotate_Try    = 32,      //!< 零点学习-自转-尝试
    Calib_ElecZeroStudy_Rotate_AddSpd = 33,      //!< 零点学习-自转-加速
    Calib_ElecZeroStudy_Rotate_Calc   = 34,      //!< 零点学习-自转-计算
    Calib_ElecZeroStudy_Rotate_Ok     = 35,      //!< 零点学习-自转-完成
    Calib_ElecZeroStudy_Rotate_Err    = 36,      //!< 零点学习-自转-失败
    Calib_IfStudy_Idle                = 40,      //!< 特征电流学习-等待
    Calib_IfStudy_IdAcc               = 41,      //!< 特征电流学习-增加电流
    Calib_IfStudy_Calc                = 42,      //!< 特征电流学习-计算
    Calib_IfStudy_Ok                  = 43,      //!< 特征电流学习-完成
    Calib_IfStudy_Err                 = 44,      //!< 特征电流学习-失败
    Calib_PsiStudy_Idle               = 50,      //!< 反电势学习-等待
    Calib_PsiStudy_SpdStable          = 51,      //!< 反电势学习-转速稳定中
    Calib_PsiStudy_Calc               = 52,      //!< 反电势学习-计算
    Calib_PsiStudy_Ok                 = 53,      //!< 反电势学习-成功
    Calib_PsiStudy_Err                = 54,      //!< 反电势学习-失败
    Calib_MtpaStudy_Idle              = 60,      //!< mtpa标定-等待
    Calib_MtpaStudy_IsAcc             = 61,      //!< mtpa标定-加电流
    Calib_MtpaStudy_AngleAcc          = 62,      //!< mtpa标定-加角度
    Calib_MtpaStudy_AngleDec          = 63,      //!< mtpa标定-减角度
    Calib_MtpaStudy_IsDec             = 64,      //!< mtpa标定-减电流
    Calib_MtpaStudy_Ok                = 65,      //!< mtpa标定-完成
    Calib_MtpaStudy_Err               = 66,      //!< mtpa标定-失败
    Calib_IsMaxStudy_Idle             = 70,      //!< IsMax标定-等待
    Calib_IsMaxStudy_IsAcc            = 71,      //!< IsMax标定-加电流
    Calib_IsMaxStudy_IsDec            = 72,      //!< IsMax标定-减电流
    Calib_IsMaxStudy_Ok               = 73,      //!< IsMax标定-完成
    Calib_IsMaxStudy_Err              = 74,      //!< IsMax标定-失败
    Calib_Rays_Idle                   = 80,      //!< 扫描标定-等待
    Calib_Rays_AngleUp                = 81,      //!< 扫描标定-加角度
    Calib_Rays_IsUp                   = 82,      //!< 扫描标定-加电流
    Calib_Rays_IsDown                 = 83,      //!< 扫描标定-减电流
    Calib_Rays_WaitTemp               = 84,      //!< 扫描标定-降温
    Calib_Rays_Stop                   = 85,      //!< 扫描标定-停止-绕组2给定大于1%开始
    Calib_Rays_TempUp                 = 86,      //!< 扫描标定-升温-请给定绕组1的值用以升温
    Calib_Rays_IsZero                 = 87,      //!< 扫描标定-电流归零-请将绕组1的值归零
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
