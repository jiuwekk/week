// ================================================================================================
//! \file       Setting.h
//! \brief      
//! \author     xjh
//! \version    1.0.0
//! \date       2019年11月07日
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
 * 程序功能性修改记录：
 * 2021-4-8：将Debug在主循环函数中发送的代码放进DbgData源文件相应位置中，避免多个地方重复出现发送代码，方便修改与归纳
 * 2021-4-8：将电机数据发送在主循环中的代码放回SanProt源文件中，避免多处出现发送程序的情况，方便修改与归纳
 * 2021-4-8：将ProtFunc文件夹中除SanProt以外的文件删除
 * 2021-4-8：添加二分之一发波功能，通过setting头文件中Single_or_Double宏定义去实现
 * 2021-4-8：添加新上位机绘图加两个新ID功能，通过setting头文件中New_Mon_Test宏定义去选择上位机
 * 2021-4-8：底层适配模型相序标定程序
 * 2021-4-19：添加FDC系列化控制板头文件
 * 2021-4-21：完全适配FDC系列化控制板
 * 2021-4-23：添加电机脱机控制宏定义Loose_DM,如果是脱机状态,电压给固定404V,三相电流为0
 * 2021-7-8:适配05XB电机控制板
 * 2021-8-6:对接阿尔特的摩托罗拉格式协议,添加CRC8校验,添加故障码计算
 * 2021-8-21:修改成500K波特率
 * 2022-8-18:增加低有效IO口检测，直接开管切换转速模式500rpm
 * 2023-3-14:增加上电自检，缺相故障问题
 */
    #define VER_CHARS "M_MOT_KS126KW_103_IGBT600A_2901500Nm_M3_2.13_2.02_V1.004"//"M_MOT_1707_SH85_0101"
//                主控-电机-控制板-符合磁链-测试-版本
/*
 *  V1.001 修改缺相保护限制和生效时间，把主循环时间增加到2ms
 *  V1.002 把缺相保护电流给定到0.05
 *  V1.003 相线开路检测电流阶梯从0.006改正到0.001,增加控制帧驻坡档位信息
 *  V1.004 驻坡模式修改为最基本的加减速，增加变频和驻坡堵转判断
 *
 */
// ================================================================================================
/*合力 五合一控制器 模型 合力模型
 * #define MOTOR_ID                   (0x0C)  //!< 江特 30Kw 500Nm 电机
 * #define EVCBD_ID                   (0x05)  //!< EVCONTROLBOARD-107Z 五合一低功率控制器
 * #define FUNCVER                    (0x06)  //!< 功能版本
*/

/*江淮 系列化控制器 模型 合力模型
 * #define MOTOR_ID                   (0x0C)  //!< 江特 30Kw 500Nm 电机
 * #define EVCBD_ID                   (0x07)  //!< LV-MCU-101,2.5吨物流车控制器
 * #define FUNCVER                    (0x06)  //!< 功能版本
*/
// ================================================================================================
// MOTOR ID
//#define MOTOR_ID                   (0x01)  //!< 8.5m电机，峰值扭矩1700Nm,350A  390-180
//#define MOTOR_ID                   (0x02)  //!< 8.5M电机，峰值扭矩2000Nm,480A
//#define MOTOR_ID                   (0x03)  //!< 10.5m电机，峰值扭矩2500Nm,370A
//#define MOTOR_ID                   (0x04)  //!< 10.5m电机，峰值扭矩2800Nm,430A
//#define MOTOR_ID                   (0x05)  //!< 290_169,直极,1000Nm
//#define MOTOR_ID                   (0x06)  //!< 290_169,斜极,1000Nm
//#define MOTOR_ID                   (0x07)  //!< 290_262 1700Nm
//#define MOTOR_ID                   (0x08)  //!< 390_213,2500Nm
//#define MOTOR_ID                   (0x09)  //!< 明恒390电机
//#define MOTOR_ID                   (0x0A)  //!< 杭叉牵引车电机
//#define MOTOR_ID                   (0x0B)  //!< 江特 30Kw 200Nm 电机
//#define MOTOR_ID                   (0x0C)  //!< 江特 30Kw 500Nm 电机
//#define MOTOR_ID                   (0x0D)  //!< 江特 500Nm 电机 测试
//#define MOTOR_ID                   (0x0e)  //!< 220测功机电机测试的程序
//#define MOTOR_ID                   (0x0f)  //!< 220-p2测功机电机测试的程序
//#define MOTOR_ID                   (0x11)  //!< 德普达
//#define MOTOR_ID                   (0x13)  //!< 太阳能155电机程序
//#define MOTOR_ID                   (0x14)  //!< 自制防爆180电机程序
//#define MOTOR_ID                   (0x15)  //!< XP50电机程序
//#define MOTOR_ID                   (0x16)  //!< 290-262电机磁链控制程序
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
//#define EVCBD_ID                   (0x01)  //!< RLESS-LOGIC-01-01,三合一控制器
//#define EVCBD_ID                   (0x02)  //!< EVCONTROLBOARD-104M
//#define EVCBD_ID                   (0x03)  //!< EVCBD-01M(索姆版)
//#define EVCBD_ID                   (0x04)  //!< EVCBD-02M(锁母版三项IGBT温度采集)
//#define EVCBD_ID                   (0x05)  //!< EVCONTROLBOARD-107Z 五合一低功率控制器
//#define EVCBD_ID                   (0x06)  //!< EVCONTROLBOARD-105Z 五合一低功率控制器
#define EVCBD_ID                   (0x07)  //!< LV-MCU-101,2.5吨物流车控制器   适配102与103
//#define EVCBD_ID                   (0x08)  //!< CTRL_FDC_M_01, 系列化控制器逻辑板
//#define EVCBD_ID                   (0x09)  //!< 05XB,叉车S控制器
//#define EVCBD_ID                   (0x0A)  //!< M_PMS_02,叉车M控制器
//#define EVCBD_ID                   (0x0D)  //!< CTRL_HP1_LOGIC飞机电机控制器
//
// ================================================================================================
// Coustomer ID
#define COUST_ID                   (0x00) //!< 松正
//#define COUST_ID                   (0x01) //!< 安凯
//#define COUST_ID                   (0x02) //!< 宇通
//#define COUST_ID                   (0x03) //!< 苏州金龙
//#define COUST_ID                   (0x04) //!< 南京金龙
//#define COUST_ID                   (0x05) //!< 中通
//#define COUST_ID                   (0x06) //!< 黄海
//#define COUST_ID                   (0x07) //!< 金旅
//#define COUST_ID                   (0x08) //!< 飞驰
//#define COUST_ID                   (0x09) //!< 海格
//#define COUST_ID                   (0x0a) //!< 福田
//#define COUST_ID                   (0x0b) //!< 恒通
//#define COUST_ID                   (0x0c) //!< 五龙
//#define COUST_ID                   (0x0d) //!< 源正（广西申龙）
//#define COUST_ID                   (0x0e) //!< 青衫
//#define COUST_ID                   (0x0f) //!< 扬子江
//#define COUST_ID                   (0x10) //!< 比亚迪
//#define COUST_ID                   (0x12) //!< 银隆
//#define COUST_ID                   (0x13) //!< 潍柴
//#define COUST_ID                   (0x14) //!< 贵阳长江
//#define COUST_ID                   (0x15) //!< 中叉
//#define COUST_ID                   (0x16) //!< 东莞捷径
//#define COUST_ID                   (0x17) //!< 金龙新能源
//#define COUST_ID                   (0x1c) //!< 上海申龙
//#define COUST_ID                   (0x1d) //!< 中兴
//#define COUST_ID                   (0x1e) //!< 明恒
//#define COUST_ID                   (0x1f) //!< 阿尔特太阳能车

#define FUNCVER                    (0x00) //!< 功能版本
#define PROTTYPE                   (0x00) //!< 协议类型  （松正协议0:主控 1：发控）
#define PROTVER                    (0x00) //!< 协议版本
#define PROTUPCOMM                 (0x00) //!< 上位机协议 0：主控 1：发控

// ================================================================================================
// PARMVER
#define PARMVER                    ((MOTOR_ID << 8) | EVCBD_ID)

#define Modle_or_Handecode         1          //采用模型或者手写程序.1:采用模型;0:采用手写

#define Single_or_Double           2          //发波与更新。1单发波单更新。2双发波双更新。3单发波二分之一更新
#define Soft_Version               1          //程序版本号。1：使用软件版本号、0：使用硬件版本号
#define New_Mon_Test               1          //1：执行绘图分离新上位机测试程序段、0：不执行绘图分离新上位机测试程序段，运行1.6.6版本上位机不可分离绘图
#define Watch_TripleIndex          1          //监控单报文三倍索引.1:启用\0:不启用(上位机都能识别,只是表格不同)
#define Loose_DM                   0//1          //脱离电机状态.1:脱离电机,将一些电压电流等参数写死\0:存在电机
#if COUST_ID == (0x1f)
    #if EVCBD_ID == 0x09
        #define XB05_Precharge_En          0          //05XB控制板预充功能开关.1:有预充功能;0:没有预充功能
        #define Pre_PWM_Hight_Duty       1.0        //预充控制PWM占空比正反向控制.1:1-duty=0为0%(关);0:1-duty=1为0%(关)
    #else
        #define XB05_Precharge_En          0          //05XB控制板预充功能开关.1:有预充功能;0:没有预充功能
    #endif
    #define Err_Code_En            1          // 阿尔特用故障码
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


#define ASCCONDSPD  1000     // ASC触发条件转速值


#define SLOPERUNTMTHR  3000  // 驻坡运行时间3s
#define SLOPESTOPTMTHR 1000  // 驻坡停止时间1s
#define SLOPERUNPROD   3     // 驻坡运行周期 3次

#define INITTIME   1000    //!< 单片机正常通讯后，初始化时间 ms 最小50ms

// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of

#endif // end of _SETTING_H_
