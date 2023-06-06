/*
 * MotParm_TZ210XS30H_310HC_New.h
 *
 *  Created on: 2021年3月1日
 *      Author: P723
 */

#ifndef SW_CONFIG_MotParm_YD220_MOT_H_
#define SW_CONFIG_MotParm_YD220_MOT_H_

// ================================================================================================
// the includes

// ================================================================================================
// the defines

#define ELECZERO            1721//641       //!< 电机旋变零点
#define CURBASE             (3600 * SQRT2)//!< 电流基值(峰值)*0.1A
#define VOLTBASE            1440       //!< 电压基值*0.1V   不改
#define SPEEDBASE           10000       //!< 转速基值
#define IF                  2780       //!< 等效励磁电流*0.1A
#define BEMF                1100       //!< 1000rpm反电势对应的电压 *0.1V
#define MOTPOLEPAIRS        4          //!< 电机极对数#
#define ENCODERPOLEPAIRS    4          //!< 旋变极对数#
#define SWAPENCODERDIR      0          //!< 旋变方向换向
#define SWAPPHASE           1          //!< 电机相线换向
//1.5429x3 - 3.5843x2 + 2.933x + 0.0154
//y = 0.769x3 - 2.255x2 + 2.3474x + 0.0242
//y = 1.368x3 - 3.1294x2 + 2.5832x + 0.0135

//#define MTPA_K3             1.368      //!< MTPA拟合3次方系数#
//#define MTPA_K2             (-3.1294)  //!< MTPA拟合2次方系数#
//#define MTPA_K1             2.5832     //!< MTPA拟合1次方系数#
//#define MTPA_K0             0.0135     //!< MTPA拟合0次方系数#

#define MTPA_K3             1.5174     //!< MTPA拟合3次方系数#
#define MTPA_K2             (-3.4080)  //!< MTPA拟合2次方系数#
#define MTPA_K1             2.6804     //!< MTPA拟合1次方系数#
#define MTPA_K0             0.0195     //!< MTPA拟合0次方系数#

#define PEAKPOWER           0          //!< 输出机械功率限制 ，0.1Kw,0=不限制
#define PEAKTORQUE          0          //!< 输出扭矩限制，  NM,0=不限制


//#define PWM_LOW_FREQ        2000       //!< 低频，2K
#define PWM_LOW_FREQ        8000       //!< 低频，2K
#define PWM_HIGH_FREQ       8000       //!< 高频，5k 高低相等不变频
#define PWM_LOW_FREQ_HZ     2          //!< 低频，电机Hz
#define PWM_HIGH_FREQ_HZ    10         //!< 高频，电机Hz 高低相等不变频

#define KP_ID               1500       //!< D轴Kp参数*0.001
#define KI_ID               200        //!< D轴Ki参数*0.0001
#define KP_IQ               1500       //!< Q轴Kp参数*0.001
#define KI_IQ               100        //!< Q轴Ki参数*0.0001
#define KP_FW1              250        //!< IdWeak_Kp参数*0.001
#define KI_FW1              58         //!< IdWeak_Ki参数*0.0001
#define KP_FW2              62         //!< AngleWeak_Kp参数*0.001
#define KI_FW2              15         //!< AngleWeak_Ki参数*0.0001
#define FW1_REF             1.05       //!< IdWeak参考      过调制
#define FW2_REF             1.05       //!< AngleWeak参考     过调制
#define UDMAX               1.4        //!< D轴电压最大值
#define UQMAX               1.4        //!< Q轴电压最大值

#define DCOVERCUR           5000       //!< 母线过流       0.1A
#define ACOVERCUR1          5080       //!< 相线过流1 0.1A(峰值)
#define ACOVERCUR2          5500       //!< 相线过流2 0.1A(峰值)
#define DCOVERVOLT3         8000       //!< 电压过压3 0.1V
#define DCOVERVOLT2         7800       //!< 电压过压2 0.1V
#define DCOVERVOLT1         7500       //!< 电压过压1 0.1V
#define DCUNDERVOLT1        1500       //!< 电压欠压1 0.1V
#define DCUNDERVOLT2        1000       //!< 电压欠压2 0.1V
#define DCUNDERVOLT3         300       //!< 电压欠压3 0.1V

#define OVERSPD1            8000       //!< 超速1转速
#define OVERSPD2           10000       //!< 超速2转速
#define KP_SPDLIMIT         4000       //!< 限速Kp参数*0.001
#define KI_SPDLIMIT         200        //!< 限速Ki参数*0.0001

#define DIRVECURLIMIT       5000       //!< 驱动母线电流限制*0.1A
#define BRAKECURLIMIT       5000       //!< 制动母线电流限制*0.1A
#define KP_IDCLIMIT         500        //!< 母线限流Kp参数*0.001
#define KI_IDCLIMIT         100        //!< 母线限流Ki参数*0.0001


#define KP_SPDM0            10000       //!< 速度模式0Kp参数*0.001
#define KI_SPDM0            1500        //!< 速度模式0Ki参数*0.0001
#define KP_SPDM1            1000       //!< 速度模式1Kp参数*0.001
#define KI_SPDM1            100        //!< 速度模式1Ki参数*0.0001
#define KP_SPDM2            1000       //!< 速度模式2Kp参数*0.001
#define KI_SPDM2            100        //!< 速度模式2Ki参数*0.0001

#define PT100_1             0          //!< PT100_1 0==>没有
#define PT100_2             1          //!< PT100_2 0==>没有

#define TABNSTART           500        //!< 电机特性表中转速起始值rpm
#define TABNEND             5100       //!< 电机特性表中转速最高值rpm
#define TABNNUM             24         //!< 电机特性表中转速点数

//#define TABNSTART           500        //!< 电机特性表中转速起始值rpm
//#define TABNEND             3500       //!< 电机特性表中转速最高值rpm
//#define TABNNUM             16         //!< 电机特性表中转速点数

#define TABNREFU            3100       //!< 测定特性表时的电压0.1V
#define TABNREFCUR     (3000 * SQRT2)  //!< 测点特性表时的电流0.1A
#define TABYNUM             11         //!< 特性表二维表列数

#if TABNREFU == 3100
#define TM_TAB {504,504,504,504,504,499,464,417,374,345,\
                315,284,266,244,225,214,199,186,179,168,\
                159,153,144,136}
#elif TABNREFU == 2000
#define TM_TAB {508,508,508,459,400,343,305,259,228,208,\
                187,173,158,145,134,128}
#elif TABNREFU == 1500
#define TM_TAB {506,506,499,449,398,357,325,292,267,246,\
                230,208,195,186,172,163,153,146,139,132,\
                127,123,115,112,106,102}

//#define TM_TAB {508.0,490.0,406.0,334.7,278.0,238.0,206.0,181.3,159.6,142.0,\
//                129.0,117.0,107.5,99.0, 91.0, 83.6, 78.0, 73.0}
#endif

#if TABNREFU == 3100
#define ISM_TAB {\
        1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,0.9976,0.9389,0.8900,\
        0.8535,0.8104,0.7638,0.7286,0.6902,0.6546,0.6192,0.5799,0.5412,0.5136,\
        0.4794,0.4452,0.4081,0.3711}
#elif TABNREFU == 2000
#define ISM_TAB {\
        1.0000,1.0000,1.0000,1.0000,1.0000,0.9389,0.8731,0.7927,0.7074,0.6408,\
        0.5700,0.5184,0.4743,0.4205,0.3932,0.3656}
#elif TABNREFU == 1500
#define ISM_TAB {\
        1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,0.9560,0.9200,0.8588,0.7897,\
        0.7329,0.6964,0.6430,0.5941,0.5615,0.5228,0.4983,0.4722,0.4411,0.4169,\
        0.3914,0.3687,0.3552,0.3288,0.3127,0.3027}

//#define ISM_TAB {\
//        1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,\
//        1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,\
//        1.0000,1.0000,1.0000,1.0000,1.0000,1.0000}
#endif


//  扭矩精度标定
#if 0
#define TLIN_TAB  {\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000,\
0.0000,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0000}
#else
#define TLIN_TAB  {\
0.0000,0.1073,0.2047,0.2971,0.3863,0.4782,0.5719,0.6698,0.7738,0.8813,1.0000,\
0.0000,0.1092,0.2064,0.2971,0.3879,0.4800,0.5737,0.6704,0.7738,0.8849,1.0000,\
0.0000,0.1090,0.2061,0.2966,0.3871,0.4791,0.5726,0.6704,0.7742,0.8833,1.0000,\
0.0000,0.0998,0.1881,0.2709,0.3529,0.4355,0.5204,0.6115,0.7130,0.8336,1.0000,\
0.0000,0.0870,0.1654,0.2440,0.3255,0.4114,0.5024,0.6000,0.7160,0.8487,1.0000,\
0.0000,0.0817,0.1700,0.2572,0.3420,0.4263,0.5120,0.5978,0.6954,0.8113,1.0000,\
0.0000,0.0726,0.1487,0.2276,0.3079,0.3882,0.4722,0.5621,0.6643,0.7788,1.0000,\
0.0000,0.0632,0.1284,0.1966,0.2724,0.3500,0.4313,0.5189,0.6139,0.7359,1.0000,\
0.0000,0.0570,0.1165,0.1835,0.2573,0.3345,0.4146,0.5026,0.6021,0.7280,1.0000,\
0.0000,0.0533,0.1081,0.1731,0.2436,0.3192,0.3992,0.4896,0.5920,0.7169,1.0000,\
0.0000,0.0534,0.1077,0.1681,0.2352,0.3114,0.3964,0.4895,0.5922,0.7209,1.0000,\
0.0000,0.0541,0.1090,0.1686,0.2373,0.3167,0.3990,0.4950,0.6100,0.7470,1.0000,\
0.0000,0.0494,0.0988,0.1592,0.2248,0.3000,0.3832,0.4741,0.5814,0.7120,1.0000,\
0.0000,0.0518,0.1040,0.1620,0.2263,0.3029,0.3882,0.4893,0.6000,0.7389,1.0000,\
0.0000,0.0496,0.0993,0.1574,0.2200,0.2944,0.3827,0.4771,0.5850,0.7200,1.0000,\
0.0000,0.0512,0.1027,0.1609,0.2247,0.3000,0.3914,0.4892,0.6140,0.7600,1.0000}
#endif
// ================================================================================================
// the typedefs


// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes





#endif /* SW_CONFIG_MOTPARM_TZ210XS30H_310HC_NEW_H_ */
