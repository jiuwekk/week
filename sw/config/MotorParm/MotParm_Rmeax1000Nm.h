/*
 * MotParm_Rmeax1000Nm.h
 *
 *  Created on: 2022��7��28��
 *      Author: liuxujie
 */

#ifndef SW_CONFIG_MOTPARM_RMEAX1000NM_H_
#define SW_CONFIG_MOTPARM_RMEAX1000NM_H_

#define ELECZERO            1080       //!< ���������㣬
#define CURBASE   (2360 * SQRT2)       //!< ������ֵ(��ֵ)*0.1A
#define VOLTBASE            7000       //!< ��ѹ��ֵ*0.1V
#define SPEEDBASE           5000       //!< ת�ٻ�ֵ
#define IF                  3163       //!< ��Ч���ŵ���*0.1A(��ֵ)
#define BEMF                1292       //!< 1000rpm�����ƶ�Ӧ�ĵ�ѹ *0.1V
#define MOTPOLEPAIRS        10         //!< ���������#
#define ENCODERPOLEPAIRS    5          //!< ���伫����#
#define SWAPENCODERDIR      0          //!< ���䷽����
#define SWAPPHASE           1          //!< ������߻���
#define MTPA_K3             1.5174     //!< MTPA���3�η�ϵ��#
#define MTPA_K2             (-3.4080)  //!< MTPA���2�η�ϵ��#
#define MTPA_K1             2.6804     //!< MTPA���1�η�ϵ��#
#define MTPA_K0             0.0195     //!< MTPA���0�η�ϵ��#
#define PEAKPOWER           0          //!< �����е�������� ��0.1Kw,0=������
#define PEAKTORQUE          0          //!< ���Ť�����ƣ�  NM,0=������

#define PWM_LOW_FREQ        2000       //!< ��Ƶ��2K
#define PWM_HIGH_FREQ       5100       //!< ��Ƶ��5k �ߵ���Ȳ���Ƶ
#define PWM_LOW_FREQ_HZ     2          //!< ��Ƶ�����Hz
#define PWM_HIGH_FREQ_HZ    10         //!< ��Ƶ�����Hz �ߵ���Ȳ���Ƶ

#define KP_ID               500       //!< D��Kp����*0.001
#define KI_ID               1000       //!< D��Ki����*0.0001
#define KP_IQ               600       //!< Q��Kp����*0.001
#define KI_IQ               1000       //!< Q��Ki����*0.0001
#define KP_FW1              250        //!< IdWeak_Kp����*0.001
#define KI_FW1              58         //!< IdWeak_Ki����*0.0001
#define KP_FW2              62         //!< AngleWeak_Kp����*0.001
#define KI_FW2              15         //!< AngleWeak_Ki����*0.0001
#define FW1_REF             1.05       //!< IdWeak�ο�
#define FW2_REF             1.05       //!< AngleWeak�ο�
#define UDMAX               1.4        //!< D���ѹ���ֵ
#define UQMAX               1.4        //!< Q���ѹ���ֵ

#define DCOVERCUR           5000       //!< ĸ�߹���       0.1A
#define ACOVERCUR1          5000       //!< ���߹���1 0.1A(��ֵ)
#define ACOVERCUR2          5500       //!< ���߹���2 0.1A(��ֵ)
#define DCOVERVOLT3         7800       //!< ��ѹ��ѹ3 0.1V
#define DCOVERVOLT2         7500       //!< ��ѹ��ѹ2 0.1V
#define DCOVERVOLT1         7200       //!< ��ѹ��ѹ1 0.1V
#define DCUNDERVOLT1        2000       //!< ��ѹǷѹ1 0.1V
#define DCUNDERVOLT2        1500       //!< ��ѹǷѹ2 0.1V
#define DCUNDERVOLT3         300       //!< ��ѹǷѹ3 0.1V

#define OVERSPD1            5200       //!< ����1ת��
#define OVERSPD2            8000       //!< ����2ת��
#define KP_SPDLIMIT         4000       //!< ����Kp����*0.001
#define KI_SPDLIMIT         200        //!< ����Ki����*0.0001

#define DIRVECURLIMIT       5000       //!< ����ĸ�ߵ�������*0.1A
#define BRAKECURLIMIT       5000       //!< �ƶ�ĸ�ߵ�������*0.1A
#define KP_IDCLIMIT         500        //!< ĸ������Kp����*0.001
#define KI_IDCLIMIT         100        //!< ĸ������Ki����*0.0001


#define KP_SPDM0            8000       //!< �ٶ�ģʽ0Kp����*0.001
#define KI_SPDM0            200        //!< �ٶ�ģʽ0Ki����*0.0001
#define KP_SPDM1            1000       //!< �ٶ�ģʽ1Kp����*0.001
#define KI_SPDM1            100        //!< �ٶ�ģʽ1Ki����*0.0001
#define KP_SPDM2            1000       //!< �ٶ�ģʽ2Kp����*0.001
#define KI_SPDM2            100        //!< �ٶ�ģʽ2Ki����*0.0001

#define PT100_1             0          //!< PT100_1 0==>û��
#define PT100_2             0          //!< PT100_2 0==>û��

#define TABNSTART           600       //!< ������Ա���ת����ʼֵrpm
#define TABNEND             4000       //!< ������Ա���ת�����ֵrpm
#define TABNNUM             18         //!< ������Ա���ת�ٵ���
#define TABNREFU            1500       //!< �ⶨ���Ա�ʱ�ĵ�ѹ0.1V
#define TABNREFCUR     (3000 * SQRT2)  //!< ������Ա�ʱ�ĵ���0.1A
#define TABYNUM             11         //!< ���Ա���ά������


#define TM_TAB {508.0,490.0,406.0,334.7,278.0,238.0,206.0,181.3,159.6,142.0,\
                129.0,117.0,107.5, 99.0, 91.0, 83.6, 78.0, 73.0}

#define ISM_TAB {\
        1.0000, 1.0000, 1.0000, 0.9120, 0.8000, 0.7000, 0.6100, 0.5400, 0.4850, 0.4400, \
        0.4000, 0.3650, 0.3380, 0.3120, 0.2900, 0.2700, 0.2550, 0.2400}

#define TLIN_TAB  {\
        0.0000,0.1065,0.2036,0.2950,0.3857,0.4774,0.5708,0.6689,0.7720,0.8816,1.0000,\
        0.0000,0.1031,0.1969,0.2871,0.3750,0.4648,0.5566,0.6500,0.7500,0.8619,1.0000,\
        0.0000,0.0869,0.1673,0.2472,0.3302,0.4181,0.5086,0.6058,0.7141,0.8380,1.0000,\
        0.0000,0.0826,0.1653,0.2483,0.3311,0.4132,0.4959,0.5837,0.6804,0.7951,1.0000,\
        0.0000,0.0662,0.1368,0.2124,0.2904,0.3709,0.4556,0.5453,0.6438,0.7629,1.0000,\
        0.0000,0.0601,0.1226,0.1898,0.2623,0.3420,0.4289,0.5192,0.6215,0.7475,1.0000,\
        0.0000,0.0549,0.1117,0.1771,0.2496,0.3280,0.4117,0.5046,0.6105,0.7397,1.0000,\
        0.0000,0.0548,0.1106,0.1712,0.2393,0.3158,0.3990,0.4943,0.6010,0.7372,1.0000,\
        0.0000,0.0499,0.0997,0.1611,0.2270,0.3010,0.3846,0.4789,0.5879,0.7246,1.0000,\
        0.0000,0.0490,0.0979,0.1567,0.2193,0.2914,0.3744,0.4683,0.5738,0.7100,1.0000,\
        0.0000,0.0489,0.0977,0.1557,0.2165,0.2851,0.3669,0.4617,0.5714,0.7087,1.0000,\
        0.0000,0.0468,0.0936,0.1488,0.2068,0.2795,0.3609,0.4543,0.5627,0.7050,1.0000,\
        0.0000,0.0467,0.0935,0.1487,0.2067,0.2783,0.3595,0.4523,0.5636,0.6993,1.0000,\
        0.0000,0.0495,0.0990,0.1519,0.2066,0.2788,0.3603,0.4530,0.5650,0.7151,1.0000,\
        0.0000,0.0455,0.0910,0.1471,0.2067,0.2741,0.3533,0.4420,0.5508,0.6983,1.0000,\
        0.0000,0.0464,0.0929,0.1495,0.2090,0.2748,0.3516,0.4419,0.5512,0.6900,1.0000,\
        0.0000,0.0473,0.0945,0.1493,0.2057,0.2691,0.3435,0.4338,0.5429,0.6894,1.0000,\
        0.0000,0.0456,0.0912,0.1454,0.2020,0.2750,0.3511,0.4380,0.5483,0.6894,1.0000}
// ================================================================================================
// the typedefs


// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes






#endif /* SW_CONFIG_MOTPARM_RMEAX1000NM_H_ */