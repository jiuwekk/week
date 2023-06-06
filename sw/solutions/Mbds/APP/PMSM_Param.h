/*
 * File: PMSM_Param.h
 *
 * Code generated for Simulink model 'APP_FluxWeak_GEAR2'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Fri Sep 16 17:18:08 2022
 */

#ifndef RTW_HEADER_PMSM_Param_h_
#define RTW_HEADER_PMSM_Param_h_
#include "rtwtypes.h"

typedef struct {
  real32_T VoltNorm;
  real32_T SpdNorm;
  real32_T CurNorm;
  real32_T SpdFilterTime;
  real32_T LimIKp;
  real32_T LimIKi;
  real32_T MaxP;
  real32_T MaxT;
  real32_T MaxSpd;
  real32_T LimSpdKp;
  real32_T LimSpdKi;
  real32_T SpdKp;
  real32_T SpdKi;
  real32_T GenKp;
  real32_T GenKi;
  real32_T StarKp;
  real32_T StarKi;
  real32_T SlopeKp;
  real32_T SlopeKi;
  real32_T SlopeMaxT;
  real32_T SyncKp;
  real32_T SyncKi;
  real32_T DischgId;
  real32_T VsLimitVolt;
  real32_T TuneFreqCoef;
  real32_T FreqLow;
  real32_T FreqUp;
  uint16_T VWDirChg;
  real32_T MotPole;
  real32_T ZeroPoint;
  uint16_T ResolverDirChg;
  real32_T PoleRatio;
  real32_T ASCSpd;
  real32_T If;
  real32_T Bemf;
  real32_T BemfSpd;
  real32_T FW2_ref;
  real32_T FW2Kp;
  real32_T FW2Ki;
  real32_T MTPAK3;
  real32_T MTPAK2;
  real32_T MTPAK1;
  real32_T MTPAK0;
  real32_T FW1_ref;
  real32_T FW1Kp;
  real32_T FW1Ki;
  real32_T IqKp;
  real32_T IqKi;
  real32_T IdKp;
  real32_T IdKi;
  uint16_T SV5En;
  real32_T FilNarrow;
  real32_T FilDeadzone;
  real32_T ParkComp;
  real32_T IParkComp;
  real32_T OV1;
  real32_T OV2;
  real32_T OV3;
  real32_T LV1;
  real32_T LV2;
  real32_T LV3;
  real32_T OS1;
  real32_T OS2;
  real32_T MotOT1;
  real32_T MotOT2;
  real32_T MotOT3;
  real32_T InvOT1;
  real32_T InvOT2;
  real32_T InvOT3;
  real32_T OC1;
  real32_T OC2;
  real32_T DamperTimer;
  real32_T DamperGain;
  uint16_T DualRefresh;
  real32_T FLStartAng;
} PMSM_Param_bus;

#endif                                 /* RTW_HEADER_PMSM_Param_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
