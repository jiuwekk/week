// ================================================================================================
//! \file       MotParm_EV290_262.h
//! \brief      
//! \author     zdf
//! \version    1.0.0
//! \date       2019年8月13日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef SW_CONFIG_MOTPARM_EV290_262_1700_H_
#define SW_CONFIG_MOTPARM_EV290_262_1700_H_

//! @defgroup SW_CONFIG_MOTPARM_EV290_262_H_ SW_CONFIG_MOTPARM_EV290_262_H_
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================

#if XAGV_20_50 == 20
    #define SWAPENCODERDIR      0          //!< 旋变方向换向
    #define SWAPPHASE           1          //!< 电机相线换向
#elif XAGV_20_50 == 50
    #define SWAPENCODERDIR      1          //!< 旋变方向换向
    #define SWAPPHASE           0          //!< 电机相线换向
#endif
#define ELECZERO            138       //!< 电机旋变零点，8.5m车上电机
#define CURBASE   (3700 * SQRT2)       //!< 电流基值(峰值)*0.1A
#define VOLTBASE            5400       //!< 电压基值*0.1V
#define SPEEDBASE           5000       //!< 转速基值
#define IF                  3020       //!< 等效励磁电流*0.1A
#define BEMF                3322       //!< 1000rpm反电势对应的电压 *0.1V
#define MOTPOLEPAIRS        5          //!< 电机极对数#
#define ENCODERPOLEPAIRS    5          //!< 旋变极对数#
//y = 1.928x3 - 4.1056x2 + 2.9812x + 0.0232
//y = 0.7858x3 - 2.0287x2 + 1.866x + 0.1879

#define MTPA_K3             0.7858     //!< MTPA拟合3次方系数#
#define MTPA_K2             (-2.0287)  //!< MTPA拟合2次方系数#
#define MTPA_K1             1.866     //!< MTPA拟合1次方系数#
#define MTPA_K0             0.1879     //!< MTPA拟合0次方系数#
#define PEAKPOWER           0          //!< 输出机械功率限制 ，0.1Kw,0=不限制
#define PEAKTORQUE          0          //!< 输出扭矩限制，  NM,0=不限制

#define PWM_LOW_FREQ        3000       //!< 低频，2K
#define PWM_HIGH_FREQ       6000       //!< 高频，5k 高低相等不变频
#define PWM_LOW_FREQ_HZ     2          //!< 低频，电机Hz
#define PWM_HIGH_FREQ_HZ    10         //!< 高频，电机Hz 高低相等不变频

#define KP_ID               3500       //!< D轴Kp参数*0.001
#define KI_ID               1000       //!< D轴Ki参数*0.0001
#define KP_IQ               3500       //!< Q轴Kp参数*0.001
#define KI_IQ               1000       //!< Q轴Ki参数*0.0001
#define KP_FW1              100        //!< IdWeak_Kp参数*0.01
#define KI_FW1              3000       //!< IdWeak_Ki参数*0.01
#define KP_FW2              62         //!< AngleWeak_Kp参数*0.01
#define KI_FW2              50         //!< AngleWeak_Ki参数*0.01
#define FW1_REF             1.05       //!< IdWeak参考
#define FW2_REF             1.05       //!< AngleWeak参考
#define UDMAX               1.4        //!< D轴电压最大值
#define UQMAX               1.4        //!< Q轴电压最大值

#define DCOVERCUR           5000       //!< 母线过流       0.1A
#define ACOVERCUR1          5750       //!< 相线过流1 0.1A(峰值)
#define ACOVERCUR2          10000       //!< 相线过流2 0.1A(峰值)
#define DCOVERVOLT3         7300       //!< 电压过压3 0.1V
#define DCOVERVOLT2         7100       //!< 电压过压2 0.1V
#define DCOVERVOLT1         7000       //!< 电压过压1 0.1V
#define DCUNDERVOLT1        4000       //!< 电压欠压1 0.1V
#define DCUNDERVOLT2        3500       //!< 电压欠压2 0.1V
#define DCUNDERVOLT3        2000       //!< 电压欠压3 0.1V

#define OVERSPD1            4000       //!< 超速1转速
#define OVERSPD2            5000       //!< 超速2转速
#define KP_SPDLIMIT         4000       //!< 限速Kp参数*0.001
#define KI_SPDLIMIT         200        //!< 限速Ki参数*0.0001

#define DIRVECURLIMIT       5000       //!< 驱动母线电流限制*0.1A
#define BRAKECURLIMIT       5000       //!< 制动母线电流限制*0.1A
#define KP_IDCLIMIT         20        //!< 母线限流Kp参数*0.001
#define KI_IDCLIMIT         0        //!< 母线限流Ki参数*0.0001


#define KP_SPDM0            8000       //!< 速度模式0Kp参数*0.001
#define KI_SPDM0            200        //!< 速度模式0Ki参数*0.0001
#define KP_SPDM1            1000       //!< 速度模式1Kp参数*0.001
#define KI_SPDM1            100        //!< 速度模式1Ki参数*0.0001
#define KP_SPDM2            1000       //!< 速度模式2Kp参数*0.001
#define KI_SPDM2            100        //!< 速度模式2Ki参数*0.0001

#define PT100_1             1          //!< PT100_1 0==>没有
#define PT100_2             1          //!< PT100_2 0==>没有

#define TABNSTART           500        //!< 电机特性表中转速起始值rpm
#define TABNEND             3500       //!< 电机特性表中转速最高值rpm
#define TABNNUM             31         //!< 电机特性表中转速点数
#define TABNREFU            3500       //!< 测定特性表时的电压0.1V
#define TABNREFCUR     (3650 * SQRT2)  //!< 测点特性表时的电流0.1A
#define TABYNUM             11         //!< 特性表二维表列数


#define TM_TAB {1735,1699,1497,1292,1109,958,845,758,685,626,\
                575,532,494,466,435,409,385,364,344,326,\
                310,296,282,270,258,247,237,226,219,210,\
                201}

//2019-08-13 350V标定
#define ISM_TAB {\
        1.0000,1.0000,1.0000,1.0000,0.9300,0.8556,0.7592,0.7102,0.6504,0.5907,\
        0.5493,0.5133,0.4761,0.4504,0.4183,0.3976,0.3723,0.3517,0.3329,0.3127,\
        0.3014,0.2902,0.2744,0.2666,0.2574,0.2452,0.2297,0.2179,0.2156,0.2024,\
        0.1937}

// 2019.05.14 扭矩精度标定
#define TLIN_TAB  {\
        0.0000,0.1131,0.2072,0.2962,0.3857,0.4761,0.5691,0.6663,0.7699,0.8794,1.0000,\
        0.0000,0.1114,0.2048,0.2926,0.3800,0.4688,0.5599,0.6547,0.7551,0.8653,1.0000,\
        0.0000,0.1008,0.1823,0.2602,0.3366,0.4139,0.4977,0.5891,0.6929,0.8203,1.0000,\
        0.0000,0.0873,0.1604,0.2314,0.3029,0.3825,0.4667,0.5576,0.6605,0.7850,1.0000,\
        0.0000,0.0816,0.1547,0.2276,0.3049,0.3859,0.4706,0.5624,0.6649,0.7876,1.0000,\
        0.0000,0.0803,0.1607,0.2410,0.3219,0.4045,0.4898,0.5810,0.6750,0.7809,1.0000,\
        0.0000,0.0819,0.1671,0.2517,0.3342,0.4155,0.4975,0.5826,0.6755,0.7858,1.0000,\
        0.0000,0.0726,0.1490,0.2279,0.3075,0.3887,0.4707,0.5564,0.6494,0.7608,1.0000,\
        0.0000,0.0669,0.1378,0.2133,0.2917,0.3726,0.4558,0.5438,0.6397,0.7535,1.0000,\
        0.0000,0.0635,0.1307,0.2033,0.2831,0.3653,0.4503,0.5400,0.6396,0.7591,1.0000,\
        0.0000,0.0602,0.1237,0.1934,0.2710,0.3522,0.4378,0.5295,0.6300,0.7507,1.0000,\
        0.0000,0.0574,0.1174,0.1851,0.2597,0.3397,0.4251,0.5162,0.6183,0.7422,1.0000,\
        0.0000,0.0557,0.1135,0.1797,0.2531,0.3328,0.4185,0.5104,0.6146,0.7424,1.0000,\
        0.0000,0.0536,0.1087,0.1730,0.2433,0.3204,0.4053,0.4984,0.5996,0.7300,1.0000,\
        0.0000,0.0536,0.1085,0.1716,0.2414,0.3186,0.4031,0.4984,0.6063,0.7374,1.0000,\
        0.0000,0.0523,0.1055,0.1665,0.2337,0.3096,0.3953,0.4886,0.5957,0.7279,1.0000,\
        0.0000,0.0519,0.1044,0.1646,0.2306,0.3056,0.3898,0.4854,0.5947,0.7309,1.0000,\
        0.0000,0.0511,0.1027,0.1623,0.2275,0.3024,0.3876,0.4827,0.5919,0.7282,1.0000,\
        0.0000,0.0515,0.1034,0.1621,0.2261,0.3000,0.3872,0.4806,0.5900,0.7300,1.0000,\
        0.0000,0.0519,0.1043,0.1618,0.2245,0.2977,0.3843,0.4800,0.5914,0.7358,1.0000,\
        0.0000,0.0510,0.1023,0.1600,0.2224,0.2952,0.3794,0.4725,0.5838,0.7244,1.0000,\
        0.0000,0.0503,0.1008,0.1580,0.2186,0.2881,0.3712,0.4669,0.5784,0.7165,1.0000,\
        0.0000,0.0505,0.1012,0.1580,0.2185,0.2897,0.3721,0.4689,0.5808,0.7200,1.0000,\
        0.0000,0.0502,0.1004,0.1570,0.2164,0.2846,0.3665,0.4600,0.5718,0.7093,1.0000,\
        0.0000,0.0512,0.1026,0.1570,0.2146,0.2838,0.3653,0.4585,0.5705,0.7108,1.0000,\
        0.0000,0.0519,0.1039,0.1570,0.2131,0.2829,0.3634,0.4575,0.5676,0.7114,1.0000,\
        0.0000,0.0532,0.1064,0.1595,0.2170,0.2879,0.3719,0.4687,0.5810,0.7217,1.0000,\
        0.0000,0.0546,0.1090,0.1624,0.2206,0.2906,0.3746,0.4687,0.5844,0.7277,1.0000,\
        0.0000,0.0540,0.1078,0.1605,0.2174,0.2871,0.3677,0.4600,0.5711,0.7127,1.0000,\
        0.0000,0.0562,0.1118,0.1651,0.2240,0.2933,0.3752,0.4730,0.5856,0.7382,1.0000,\
        0.0000,0.0579,0.1146,0.1678,0.2269,0.2948,0.3791,0.4784,0.5918,0.7391,1.0000}

// ================================================================================================
// the includes


// ================================================================================================
// the defines


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

//! @} // end of SW_CONFIG_MOTPARM_EV290_262_H_

#endif // end of SW_CONFIG_MOTPARM_EV290_262_H_
