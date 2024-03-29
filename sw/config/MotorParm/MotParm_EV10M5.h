// ================================================================================================
//! \file       MotParm_EV10M5.h
//! \brief      EV390电机 370A 2500Nm
//! \author     XJH
//! \version    1.0.0
//! \date       2019.05.17
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _MOTPARM_EV10M5_H_
#define _MOTPARM_EV10M5_H_

//! @defgroup MOTPARM_EV10M5
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================
// the includes

// ================================================================================================
// the defines

#define ELECZERO            87         //!< 电机旋变零点，台架10m5
#define CURBASE   (3700 * SQRT2)       //!< 电流基值(峰值)*0.1A
#define VOLTBASE            5400       //!< 电压基值*0.1V
#define SPEEDBASE           5000       //!< 转速基值
#define IF                  3362       //!< 等效励磁电流*0.1A
#define BEMF                4385       //!< 1000rpm反电势对应的电压 *0.1V
#define MOTPOLEPAIRS        6          //!< 电机极对数#
#define ENCODERPOLEPAIRS    6          //!< 旋变极对数#
#define SWAPENCODERDIR      0          //!< 旋变方向换向
#if EVCBD_ID == 0x05 || EVCBD_ID == 0x06
#define SWAPPHASE           0          //!< 电机相线换向
#else
#define SWAPPHASE           1          //!< 电机相线换向
#endif
// y = 1.2737x3 - 2.972x2 + 2.5935x - 0.0084
#define MTPA_K3             1.2737     //!< MTPA拟合3次方系数#
#define MTPA_K2             (-2.972)  //!< MTPA拟合2次方系数#
#define MTPA_K1             2.5935     //!< MTPA拟合1次方系数#
#define MTPA_K0             0.0000     //!< MTPA拟合0次方系数#
#define PEAKPOWER           0          //!< 输出机械功率限制 ，0.1Kw,0=不限制
#define PEAKTORQUE          0          //!< 输出扭矩限制，  NM,0=不限制

#define PWM_LOW_FREQ        2000       //!< 低频，2K
#define PWM_HIGH_FREQ       4800       //!< 高频，5k 高低相等不变频
#define PWM_LOW_FREQ_HZ     2          //!< 低频，电机Hz
#define PWM_HIGH_FREQ_HZ    10         //!< 高频，电机Hz 高低相等不变频

#define KP_ID               3000       //!< D轴Kp参数*0.001
#define KI_ID               1500       //!< D轴Ki参数*0.0001
#define KP_IQ               3000       //!< Q轴Kp参数*0.001
#define KI_IQ               1500       //!< Q轴Ki参数*0.0001
#define KP_FW1              250        //!< IdWeak_Kp参数*0.001
#define KI_FW1              58         //!< IdWeak_Ki参数*0.0001
#define KP_FW2              62         //!< AngleWeak_Kp参数*0.001
#define KI_FW2              15         //!< AngleWeak_Ki参数*0.0001
#define FW1_REF             1.05       //!< IdWeak参考
#define FW2_REF             1.05       //!< AngleWeak参考
#define UDMAX               1.4        //!< D轴电压最大值
#define UQMAX               1.4        //!< Q轴电压最大值

#define DCOVERCUR           5000       //!< 母线过流       0.1A
#define ACOVERCUR1          6000//5500       //!< 相线过流1 0.1A(峰值)
#define ACOVERCUR2          6200//5800       //!< 相线过流2 0.1A(峰值)
#define DCOVERVOLT3         7800       //!< 电压过压3 0.1V
#define DCOVERVOLT2         7500       //!< 电压过压2 0.1V
#define DCOVERVOLT1         7200       //!< 电压过压1 0.1V
#define DCUNDERVOLT1        4000       //!< 电压欠压1 0.1V
#define DCUNDERVOLT2        3000       //!< 电压欠压2 0.1V
#define DCUNDERVOLT3         300       //!< 电压欠压3 0.1V

#define OVERSPD1            3500       //!< 超速1转速
#define OVERSPD2            4000       //!< 超速2转速
#define KP_SPDLIMIT         4000       //!< 限速Kp参数*0.001
#define KI_SPDLIMIT         200        //!< 限速Ki参数*0.0001

#define DIRVECURLIMIT       5000       //!< 驱动母线电流限制*0.1A
#define BRAKECURLIMIT       5000       //!< 制动母线电流限制*0.1A
#define KP_IDCLIMIT         500        //!< 母线限流Kp参数*0.001
#define KI_IDCLIMIT         100        //!< 母线限流Ki参数*0.0001


#define KP_SPDM0            8000       //!< 速度模式0Kp参数*0.001
#define KI_SPDM0            200        //!< 速度模式0Ki参数*0.0001
#define KP_SPDM1            1000       //!< 速度模式1Kp参数*0.001
#define KI_SPDM1            100        //!< 速度模式1Ki参数*0.0001
#define KP_SPDM2            1000       //!< 速度模式2Kp参数*0.001
#define KI_SPDM2            100        //!< 速度模式2Ki参数*0.0001

#define PT100_1             0          //!< PT100_1 0==>没有
#define PT100_2             1          //!< PT100_2 0==>没有

#define TABNSTART           600        //!< 电机特性表中转速起始值rpm
#define TABNEND             3700       //!< 电机特性表中转速最高值rpm
#define TABNNUM             32         //!< 电机特性表中转速点数
#define TABNREFU            5400       //!< 测定特性表时的电压0.1V
#define TABNREFCUR     (3700 * SQRT2)  //!< 测点特性表时的电流0.1A
#define TABYNUM             11         //!< 纵坐标列数

#define TM_TAB {2494,2482,2252,1998,1786,1586,1418,1280,1164,1076,\
        990,919,870,803,755,710,671,634,599,572,\
        540,518,496,476,456,440,424,406,390,378,362,100}

#define ISM_TAB {\
        1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,0.9700,0.8855,0.8194,0.7507,\
        0.7109,0.6590,0.6065,0.5743,0.5337,0.5167,0.4950,0.4648,0.4420,0.4203,\
        0.4018,0.3873,0.3713,0.3603,0.3376,0.3282,0.3190,0.2993,0.2922,0.2864,0.2790,0.1000}

#define TLIN_TAB  {\
0.0000,0.1201,0.2179,0.3091,0.3991,0.4908,0.5853,0.6827,0.7811,0.8851,1.0000,\
0.0000,0.1198,0.2174,0.3084,0.3983,0.4897,0.5840,0.6810,0.7792,0.8828,1.0000,\
0.0000,0.1104,0.2007,0.2824,0.3638,0.4456,0.5302,0.6211,0.7219,0.8409,1.0000,\
0.0000,0.1006,0.1805,0.2548,0.3298,0.4095,0.4959,0.5872,0.6895,0.8128,1.0000,\
0.0000,0.0896,0.1617,0.2344,0.3111,0.3914,0.4761,0.5656,0.6665,0.7893,1.0000,\
0.0000,0.0796,0.1525,0.2251,0.3016,0.3804,0.4614,0.5475,0.6448,0.7646,1.0000,\
0.0000,0.0769,0.1542,0.2310,0.3073,0.3856,0.4656,0.5507,0.6459,0.7600,1.0000,\
0.0000,0.0819,0.1626,0.2412,0.3181,0.3946,0.4733,0.5557,0.6479,0.7610,1.0000,\
0.0000,0.0719,0.1468,0.2234,0.3001,0.3773,0.4572,0.5411,0.6343,0.7502,1.0000,\
0.0000,0.0662,0.1365,0.2115,0.2893,0.3692,0.4512,0.5375,0.6338,0.7537,1.0000,\
0.0000,0.0598,0.1234,0.1949,0.2705,0.3492,0.4298,0.5127,0.6106,0.7324,1.0000,\
0.0000,0.0566,0.1163,0.1864,0.2607,0.3395,0.4234,0.5114,0.6101,0.7353,1.0000,\
0.0000,0.0544,0.1113,0.1809,0.2565,0.3368,0.4217,0.5133,0.6158,0.7425,1.0000,\
0.0000,0.0522,0.1058,0.1731,0.2462,0.3255,0.4107,0.5010,0.6050,0.7358,1.0000,\
0.0000,0.0503,0.1009,0.1680,0.2406,0.3197,0.4038,0.4981,0.6082,0.7394,1.0000,\
0.0000,0.0482,0.0964,0.1604,0.2300,0.3072,0.3920,0.4851,0.5925,0.7258,1.0000,\
0.0000,0.0462,0.0924,0.1527,0.2189,0.2948,0.3800,0.4724,0.5780,0.7076,1.0000,\
0.0000,0.0451,0.0901,0.1496,0.2154,0.2904,0.3742,0.4678,0.5743,0.7023,1.0000,\
0.0000,0.0444,0.0888,0.1464,0.2103,0.2865,0.3710,0.4648,0.5731,0.7074,1.0000,\
0.0000,0.0443,0.0886,0.1458,0.2091,0.2847,0.3695,0.4647,0.5747,0.7114,1.0000,\
0.0000,0.0428,0.0856,0.1406,0.2023,0.2782,0.3610,0.4563,0.5693,0.7038,1.0000,\
0.0000,0.0420,0.0841,0.1380,0.1990,0.2732,0.3547,0.4473,0.5567,0.6908,1.0000,\
0.0000,0.0415,0.0831,0.1354,0.1951,0.2682,0.3500,0.4437,0.5537,0.6909,1.0000,\
0.0000,0.0412,0.0825,0.1333,0.1914,0.2645,0.3463,0.4383,0.5462,0.6897,1.0000,\
0.0000,0.0413,0.0826,0.1342,0.1934,0.2667,0.3490,0.4432,0.5556,0.7000,1.0000,\
0.0000,0.0405,0.0809,0.1309,0.1895,0.2612,0.3424,0.4360,0.5482,0.6918,1.0000,\
0.0000,0.0397,0.0794,0.1288,0.1887,0.2598,0.3400,0.4320,0.5394,0.6828,1.0000,\
0.0000,0.0406,0.0812,0.1315,0.1900,0.2611,0.3427,0.4374,0.5467,0.6888,1.0000,\
0.0000,0.0402,0.0804,0.1305,0.1898,0.2604,0.3400,0.4321,0.5441,0.6896,1.0000,\
0.0000,0.0396,0.0791,0.1275,0.1856,0.2528,0.3305,0.4254,0.5320,0.6730,1.0000,\
0.0000,0.0396,0.0791,0.1275,0.1856,0.2528,0.3305,0.4254,0.5320,0.6730,1.0000,\
0.0000,0.0396,0.0791,0.1275,0.1856,0.2528,0.3305,0.4254,0.5320,0.6730,1.0000}
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

//! @} // end of MOTPARM_EV10M5

#endif // end of _MOTPARM_EV10M5_H_
