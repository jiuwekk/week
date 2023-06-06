// ================================================================================================
//! \file       SantProt.h
//! \brief      
//! \author     xjh
//! \version    1.0.0
//! \date       2017年5月2日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _SANTPROT_H_
#define _SANTPROT_H_

//! @defgroup SantProt
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// the includes


// ================================================================================================
// the defines
#if PROTTYPE == 0
#define ORDER1ID    0x18ef2010
#define ORDER2ID    0x18ef2110
#define STAT1ID     0x18ef1020
#define STAT2ID     0x18ef1120
#define STAT3ID     0x18ef1220
#define STAT4ID     0x18ef1320
#define UPCOM_RXID  0x18ef20f0
#define UPCOM_TXID  0x18eff020
#define UPCOM_TXID1  0x18eff021
#define UPCOM_TXID2  0x18eff022
#define DBG1_ID     0x1f002008
#define DBG2_ID     0x1f002009
#define DBG3_ID     0x1f00200a
#define DBG4_ID     0x1f00200b
#define DBG5_ID     0x1f00200c
#define DBG6_ID     0x1f00200d
#elif PROTTYPE == 1
#define ORDER1ID    0x18ef6010
#define ORDER2ID    0x18ef6110
#define STAT1ID     0x18ef1060
#define STAT2ID     0x18ef1160
#define STAT3ID     0x18ef1260
#define STAT4ID     0x18ef1360
#define UPCOM_RXID  0x18ef60f0
#define UPCOM_TXID  0x18eff060
#define UPCOM_TXID1  0x18eff061
#define UPCOM_TXID2  0x18eff062
#define DBG1_ID     0x1f100008
#define DBG2_ID     0x1f100009
#endif




// ================================================================================================
// the typedefs

typedef union
{
    int16_t All[4];
    struct
    {
        int16_t BusCurrent :16;     // 母线电流   有符号1A
        uint16_t Heart :8;
        int16_t rsvd :4;
        uint16_t SwIn1:1;
        uint16_t SwIn2:1;
        uint16_t SwIn3:1;
        uint16_t SwIn4:1;
        int16_t RawTheta:16;       // 转子位置
        int16_t MotSpdReal:16;
    }Bit;
}MCU_STAT1_OBJ;
#define MCU_STAT1_OBJ_DEFAULTS {0,0,0,0}

typedef union
{
    uint16_t All[4];
    struct
    {
        uint16_t BusVoltage;    // 无符号0.1v
        uint16_t Rsvd;
        uint16_t CutBack : 8;   // 当前限制  无符号 1/100
        uint16_t Rsvd1   : 8;
        int16_t  InvTemp : 8;   // 偏移50℃
        int16_t  MotTemp : 8;   // 偏移50℃
    }Bit;
}MCU_STAT2_OBJ;
#define MCU_STAT2_OBJ_DEFAULTS {0,0,0,0}


typedef union
{
    int16_t All[4];
    struct
    {
        int16_t MotTqMax;      // Nm
        int16_t Rsvd0;
        int16_t MotTqReal;     // Nm
        int16_t Rsvd1;
    }Bit;
}MCU_STAT3_OBJ;
#define MCU_STAT3_OBJ_DEFAULTS {0,0,0,0}


typedef union
{
    uint16_t  All[4];
    struct
    {
        uint16_t PwrMdlErr:1;       //(1,1)  IGBT模块故障,驱动光耦
        uint16_t CurSensorErr:1;    //(1,2)  相电流传感器
        uint16_t MotStallErr:1;     //(1,3)  电机堵转？？？
        uint16_t AcOverCur2Err:1;   //(1,4)  相过流2
        uint16_t AcOverCur1Err:1;   //(1,5)  相过流1 0扭矩
        uint16_t PreChargeErr:1;    //(1,6)  预充失败
        uint16_t PhaseBrkErr:1;     //(1,7)  相线开路
        uint16_t DcOverVolt3Err:1;  //(1,8)  过压3 不可恢复

        uint16_t DcOverVolt2Err:1;  //(2,1)  过压2 发电0扭矩
        uint16_t DcOverVolt1Err:1;  //(2,2)  过压1
        uint16_t DcUnderVolt1Err:1; //(2,3)  欠压1
        uint16_t DcUnderVolt2Err:1; //(2,4)  欠压2 驱动0扭矩
        uint16_t DcUnderVolt3Err:1; //(2,5)  欠压3 不可恢复
        uint16_t Main_DNC_Err:1;    //(2,6)  主接触器压差
        uint16_t OverSpeed2Err:1;   //(2,7)  超速 2
        uint16_t DcOverCur1Err:1;   //(2,8)  母线过流            1.1*峰值

        uint16_t Rsvd2:8;           //(3,1)  预留
        uint16_t Rsvd3:8;           //(4,1)  预留

        uint16_t OverSpeed1Err:1;   //(5,1)  超速 1 0扭矩
        uint16_t MotOverTemp3Err:1; //(5,2)  电机过温3       160 关管
        uint16_t InvOverTemp3Err:1; //(5,3)  模块过温3       95 关管
        uint16_t LogicPowerErr:1;   //(5,4)  24V故障
        uint16_t Rsvd4_4      :1;   //(5,5)  预留
        uint16_t PosSensorErr :1;   //(5,6)  旋变故障关管
        uint16_t Rsvd4_6      :1;   //(5,7)  预留
        uint16_t MotOverTemp2Err:1; //(5,8)  电机过温2       140 零扭矩

        uint16_t MotOverTemp1Err:1;         //(6,1)  电机过温1       130 线性限扭矩
        uint16_t InvOverTemp2Err:1;         //(6,2)  模块过温2       85 零扭矩
        uint16_t InvOverTemp1Err:1;         //(6,3)  模块过温1       75 线性限扭矩
        uint16_t MotTempSensorErr1:1;       //(6,4)  PT100#1
        uint16_t MotTempSensorErr2:1;       //(6,5)  PT100#2
        uint16_t InvTempSensorErr1:1;       //(6,6)  NTC#1
        uint16_t InvTempSensorErr2:1;       //(6,7)  NTC#2
        uint16_t InvTempSensorErr3:1;       //(6,8)  NTC#3

        uint16_t ParErr       :1;     //(7,1)  EE参数
        uint16_t ParChangeErr :1;     //(7,2)  参数修改错误
        uint16_t Msg1LostErr  :1;     //(7,3)  Vcu指令通信
        uint16_t Msg2LostErr  :1;     //(7,4)  Vcu限制通信
        uint16_t DisChgWarnErr:1;     //(7,5)  主动放电告警
        uint16_t DisChgOverTmErr:1;   //(7,6)  主动放电超时
        uint16_t Rsvd6_6      :1;     //(7,7)  预留
        uint16_t Rsvd6_7      :1;     //(7,8)  预留

        uint16_t ErrLevel     :3;
        uint16_t Rsvd7:5;             //(8,1)  预留
    }M3_FAULT_OBJ;
}MCU_STAT4_OBJ;
#define MCU_STAT4_OBJ_DEFAULTS {0,0,0,0}


typedef union
{
    uint16_t All[4];
    struct
    {
        uint16_t DCRelayState:1;   // 母线接触器状态（预充状态）
        uint16_t Rsvd0:1;
        uint16_t MotGateReq:1;     // 使能
        uint16_t Rsvd1:4;
        uint16_t VcuKeyOn:1;       // VCU ON档信号
        uint16_t MotModeReq : 8;   // 动作命令

        int16_t Parm1TqRef;
        uint16_t Parm2;
        int16_t Parm3SpdLmt;
    }Bit;
}VCU_ORDER1_OBJ;
#define VCU_ORDER1_OBJ_DEFAULTS {0,0,0,0}


typedef union
{
    uint16_t All[4];
    struct
    {
        uint16_t BusCurGeneLim  ;   // 发电母线限流             无符号 1A
        uint16_t BusCurDriveLim ;   // 驱动母线限流            无符号 1A
        uint16_t MotTorqLim     ;   // 扭矩限制                      1/4096
        uint16_t Heart        :8;   // 心跳字
        uint16_t rsvd         :8;   //
    }Bit;
}VCU_ORDER2_OBJ;
#define VCU_ORDER2_OBJ_DEFAULTS {500,500,0,0}




//! VCU1 通讯协议类型定义
typedef struct
{
    MCU_STAT1_OBJ ID1;   // Tx
    MCU_STAT2_OBJ ID2;   // Tx
    MCU_STAT3_OBJ ID3;   // Tx
    MCU_STAT4_OBJ ID4;   // Tx
    VCU_ORDER1_OBJ ID5;   // Rx
    VCU_ORDER2_OBJ ID6;   // Rx
    ECANMSG      RMsg;
    ECANMSG      TMsg;
    uint16_t     ID5Update:1;
    uint16_t     ID6Update:1;
    uint16_t     ID5Lost:1;
    uint16_t     ID6Lost:1;
    uint16_t     Rsvd:12;
    void (*Rx)();
    void (*Tx)();
}VCU_OBJ;

#define VCU_OBJ_DEFAULTS {MCU_STAT1_OBJ_DEFAULTS,\
                            MCU_STAT2_OBJ_DEFAULTS,\
                            MCU_STAT3_OBJ_DEFAULTS,\
                            MCU_STAT4_OBJ_DEFAULTS,\
                           VCU_ORDER1_OBJ_DEFAULTS,\
                           VCU_ORDER2_OBJ_DEFAULTS,\
                           ECANMSG_DEFAULTS,\
                           ECANMSG_DEFAULTS,\
                           0,0,0,0,0,\
                           (void (*)(long))VCU_Rx,\
                           (void (*)(long))VCU_Tx}

extern void VCU_Rx(VCU_OBJ* V);
extern void VCU_Tx(VCU_OBJ* V);

extern VCU_OBJ VCU_Comm;

// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes
extern void CanOrderUpdate(void);
extern void CanSendUpdate(void);

// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of

#endif // end of _SANTPROT_H_
