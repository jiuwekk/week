// ================================================================================================
//! \file       MotParm_EV390_213_LV.h
//! \brief      EV390电机460A 2500Nm
//! \author     XJH
//! \version    1.0.0
//! \date       2019.05.17
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _MOTPARM_EV390_213_H_
#define _MOTPARM_EV390_213_H_

//! @defgroup MOTPARM_EV390_213
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================
// the includes

// ================================================================================================
// the defines

#define ELECZERO              65       //!< 电机旋变零点，
#define CURBASE   (4600 * SQRT2)       //!< 电流基值(峰值)*0.1A
#define VOLTBASE            5400       //!< 电压基值*0.1V
#define SPEEDBASE           5000       //!< 转速基值
#define IF                  3422       //!< 等效励磁电流*0.1A
#define BEMF                3774       //!< 1000rpm反电势对应的电压 *0.1V
#define MOTPOLEPAIRS        6          //!< 电机极对数#
#define ENCODERPOLEPAIRS    6          //!< 旋变极对数#
#define SWAPENCODERDIR      0          //!< 旋变方向换向
#if EVCBD_ID == 0x05 || EVCBD_ID == 0x06
#define SWAPPHASE           0          //!< 电机相线换向
#else
#define SWAPPHASE           1          //!< 电机相线换向
#endif
// y = 1.8678x3 - 4.1396x2 + 3.1558x + 0.0159
#define MTPA_K3             1.8678     //!< MTPA拟合3次方系数#
#define MTPA_K2             (-4.1396)  //!< MTPA拟合2次方系数#
#define MTPA_K1             3.1558     //!< MTPA拟合1次方系数#
#define MTPA_K0             0.0159     //!< MTPA拟合0次方系数#
#define PEAKPOWER           0          //!< 输出机械功率限制 ，0.1Kw,0=不限制
#define PEAKTORQUE          0          //!< 输出扭矩限制，  NM,0=不限制

#define PWM_LOW_FREQ        2000       //!< 低频，2K
#define PWM_HIGH_FREQ       5100       //!< 高频，5k 高低相等不变频
#define PWM_LOW_FREQ_HZ     2          //!< 低频，电机Hz
#define PWM_HIGH_FREQ_HZ    10         //!< 高频，电机Hz 高低相等不变频

#define KP_ID               3500       //!< D轴Kp参数*0.001
#define KI_ID               2500       //!< D轴Ki参数*0.0001
#define KP_IQ               3500       //!< Q轴Kp参数*0.001
#define KI_IQ               2500       //!< Q轴Ki参数*0.0001
#define KP_FW1              250        //!< IdWeak_Kp参数*0.001
#define KI_FW1              58         //!< IdWeak_Ki参数*0.0001
#define KP_FW2              62         //!< AngleWeak_Kp参数*0.001
#define KI_FW2              15         //!< AngleWeak_Ki参数*0.0001
#define FW1_REF             1.05       //!< IdWeak参考
#define FW2_REF             1.05       //!< AngleWeak参考
#define UDMAX               1.4        //!< D轴电压最大值
#define UQMAX               1.4        //!< Q轴电压最大值

#define DCOVERCUR           5000       //!< 母线过流       0.1A
#define ACOVERCUR1          7500       //!< 相线过流1 0.1A(峰值)
#define ACOVERCUR2          7800       //!< 相线过流2 0.1A(峰值)
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

#define PT100_1             1          //!< PT100_1 0==>没有
#define PT100_2             1          //!< PT100_2 0==>没有

#define TABNSTART           600        //!< 电机特性表中转速起始值rpm
#define TABNEND             3700       //!< 电机特性表中转速最高值rpm
#define TABNNUM             32         //!< 电机特性表中转速点数
#define TABNREFU            5400       //!< 测定特性表时的电压0.1V
#define TABNREFCUR     (4600 * SQRT2)  //!< 测点特性表时的电流0.1A
#define TABYNUM             11         //!< 纵坐标列数

#define TM_TAB {2532,2529,2477,2200,1925,1713,1520,1372,1250,1145,\
        1055,978,910,850,794,746,705,666,630,598,\
        568,542,522,498,477,457,440,423,408,392,375,100}

#define ISM_TAB {\
        1.0000,1.0000,1.0000,1.0000,1.0000,0.9800,0.9181,0.8655,0.8128,0.7434,\
        0.6865,0.6276,0.5932,0.5576,0.5250,0.5032,0.4764,0.4517,0.4282,0.4055,\
        0.3885,0.3739,0.3585,0.3414,0.3291,0.3231,0.3080,0.2932,0.2830,0.2732,0.2630,0.1000}

#define TLIN_TAB  {\
0.0000,0.1109,0.2014,0.2869,0.3735,0.4631,0.5562,0.6544,0.7607,0.8767,1.0000,\
0.0000,0.1109,0.2012,0.2867,0.3732,0.4624,0.5550,0.6529,0.7589,0.8744,1.0000,\
0.0000,0.1098,0.1987,0.2829,0.3679,0.4554,0.5460,0.6410,0.7433,0.8546,1.0000,\
0.0000,0.0997,0.1786,0.2540,0.3283,0.4033,0.4824,0.5651,0.6594,0.7793,1.0000,\
0.0000,0.0883,0.1601,0.2273,0.2919,0.3615,0.4349,0.5146,0.6082,0.7271,1.0000,\
0.0000,0.0803,0.1468,0.2092,0.2747,0.3439,0.4170,0.4954,0.5886,0.7007,1.0000,\
0.0000,0.0766,0.1432,0.2060,0.2752,0.3471,0.4219,0.5006,0.5927,0.7061,1.0000,\
0.0000,0.0732,0.1428,0.2108,0.2821,0.3557,0.4321,0.5128,0.6037,0.7198,1.0000,\
0.0000,0.0741,0.1483,0.2223,0.2960,0.3713,0.4486,0.5309,0.6241,0.7380,1.0000,\
0.0000,0.0841,0.1652,0.2439,0.3208,0.3970,0.4757,0.5569,0.6482,0.7597,1.0000,\
0.0000,0.0780,0.1573,0.2357,0.3127,0.3907,0.4702,0.5546,0.6490,0.7640,1.0000,\
0.0000,0.0728,0.1493,0.2282,0.3077,0.3883,0.4708,0.5580,0.6565,0.7773,1.0000,\
0.0000,0.0662,0.1370,0.2132,0.2921,0.3730,0.4550,0.5423,0.6410,0.7612,1.0000,\
0.0000,0.0627,0.1296,0.2028,0.2821,0.3619,0.4454,0.5352,0.6351,0.7586,1.0000,\
0.0000,0.0594,0.1225,0.1938,0.2709,0.3521,0.4375,0.5281,0.6289,0.7530,1.0000,\
0.0000,0.0558,0.1142,0.1830,0.2577,0.3367,0.4200,0.5097,0.6106,0.7342,1.0000,\
0.0000,0.0531,0.1079,0.1767,0.2511,0.3304,0.4145,0.5065,0.6085,0.7369,1.0000,\
0.0000,0.0512,0.1033,0.1702,0.2428,0.3215,0.4050,0.4961,0.6015,0.7343,1.0000,\
0.0000,0.0500,0.1000,0.1674,0.2395,0.3173,0.4000,0.4939,0.6000,0.7324,1.0000,\
0.0000,0.0490,0.0980,0.1634,0.2349,0.3143,0.3983,0.4929,0.6009,0.7349,1.0000,\
0.0000,0.0475,0.0951,0.1572,0.2259,0.3053,0.3903,0.4842,0.5918,0.7275,1.0000,\
0.0000,0.0465,0.0930,0.1548,0.2229,0.2993,0.3855,0.4795,0.5875,0.7297,1.0000,\
0.0000,0.0459,0.0919,0.1525,0.2194,0.2955,0.3800,0.4750,0.5864,0.7281,1.0000,\
0.0000,0.0452,0.0904,0.1499,0.2157,0.2908,0.3778,0.4732,0.5823,0.7214,1.0000,\
0.0000,0.0449,0.0898,0.1475,0.2113,0.2892,0.3744,0.4685,0.5752,0.7165,1.0000,\
0.0000,0.0434,0.0868,0.1432,0.2063,0.2808,0.3664,0.4607,0.5682,0.7092,1.0000,\
0.0000,0.0434,0.0869,0.1423,0.2036,0.2804,0.3653,0.4591,0.5676,0.7087,1.0000,\
0.0000,0.0435,0.0869,0.1445,0.2093,0.2830,0.3677,0.4653,0.5741,0.7168,1.0000,\
0.0000,0.0435,0.0870,0.1431,0.2057,0.2811,0.3638,0.4605,0.5758,0.7200,1.0000,\
0.0000,0.0424,0.0849,0.1397,0.2016,0.2780,0.3618,0.4563,0.5697,0.7190,1.0000,\
0.0000,0.0424,0.0849,0.1397,0.2016,0.2780,0.3618,0.4563,0.5697,0.7190,1.0000,\
0.0000,0.0424,0.0849,0.1397,0.2016,0.2780,0.3618,0.4563,0.5697,0.7190,1.0000}
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

//! @} // end of MOTPARM_EV390_213

#endif // end of _MOTPARM_EV390_213_H_
