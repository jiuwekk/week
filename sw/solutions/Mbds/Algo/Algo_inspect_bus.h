/*
 * File: Algo_inspect_bus.h
 *
 * Code generated for Simulink model 'Algorithm_FluxWeak_GEAR2'.
 *
 * Model version                  : 2.02
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Sep 21 16:02:48 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Algo_inspect_bus_h_
#define RTW_HEADER_Algo_inspect_bus_h_
#include "rtwtypes.h"

typedef struct {
  real32_T ThetaRawE;
  real32_T ThetaRawM;
  real32_T Angle_park;
  real32_T Angle_Ipark;
  real32_T Spd_E;
  real32_T IdRef;
  real32_T IqRef;
  real32_T PI_Id_Ui;
  real32_T PI_Iq_Ui;
  real32_T Ipark_Alpha;
  real32_T Ipark_Beta;
  real32_T Psi_whole;
  real32_T Psi_Weak;
  real32_T PsiWeak_Ui;
  real32_T IsRef;
  real32_T TorReq;
} AlgoFun_inspect_bus;

#endif                                 /* RTW_HEADER_Algo_inspect_bus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
