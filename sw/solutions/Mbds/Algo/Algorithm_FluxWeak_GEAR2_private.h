/*
 * File: Algorithm_FluxWeak_GEAR2_private.h
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

#ifndef RTW_HEADER_Algorithm_FluxWeak_GEAR2_private_h_
#define RTW_HEADER_Algorithm_FluxWeak_GEAR2_private_h_
#include "rtwtypes.h"
#include "Algorithm_FluxWeak_GEAR2.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFFFU) ) || ( SCHAR_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Imported (extern) states */
extern PMSM_Input_bus PMSM_Input;      /* Simulink.Signal object 'PMSM_Input' */
extern App_Output_bus App_Output;      /* Simulink.Signal object 'App_Output' */
extern Algo_Output_bus Algo_Output;    /* Simulink.Signal object 'Algo_Output' */
extern real32_T rt_hypotf_snf(real32_T u0, real32_T u1);
extern uint32_T plook_u32f_evenckan(real32_T u, real32_T bp0, real32_T bpSpace,
  uint32_T maxIndex);
extern uint32_T plook_u32ff_evenca(real32_T u, real32_T bp0, real32_T bpSpace,
  uint32_T maxIndex, real32_T *fraction);
extern real32_T intrp1d_fu32fla_pw(uint32_T bpIndex, real32_T frac, const
  real32_T table[], uint32_T maxIndex);
extern real32_T intrp2d_fu32fla_pw(const uint32_T bpIndex[], const real32_T
  frac[], const real32_T table[], uint32_T stride, const uint32_T maxIndex[]);
extern void Algorithm_FunctionCallSubsystem(void);
extern void PI_Algo_chuanlian(real32_T rtu_Err, real32_T rtu_Kp, real32_T rtu_KI,
  real32_T rtu_T, real32_T *rty_PIOut, real32_T *rty_I_State,
  DW_PI_Algo_chuanlian_T *localDW);
extern void Algorithm_FluxWeak_GE_Subsystem(real32_T rtu_IqRef, real32_T
  rtu_IdBak, real32_T rtu_IdRef, real32_T rtu_AlgoT, real32_T rtu_KCom, real32_T
  rtu_Ne_si, real32_T *rty_Out1, DW_Subsystem_Algorithm_FluxWe_T *localDW);
extern void Algorithm_FluxWeak__Subsystem_o(real32_T rtu_IqBak, real32_T
  rtu_IqRef, real32_T rtu_AlgoT, real32_T rtu_KCom, real32_T rtu_Ne_Si, real32_T
  rtu_IdRef, real32_T *rty_PI_out, DW_Subsystem_Algorithm_Flux_k_T *localDW);
extern void Algorithm_FluxWeak__dqalphabeta(real32_T rtu_d, real32_T rtu_q,
  real32_T rtu_Theta, real32_T *rty_alpha, real32_T *rty_beta);
extern void Algorithm_FluxWeak_GEAR2_IntLim(real32_T rtu_TorReq, real32_T
  rtu_Psi_fit);
extern void PI_Algo(real32_T rtu_Err, real32_T rtu_Kp, real32_T rtu_KI, real32_T
                    rtu_T, real32_T *rty_PIOut, real32_T *rty_I_State,
                    DW_PI_Algo_T *localDW);
extern void Algorithm_FluxWea_Psi_Weak_Init(real32_T *rty_PI_out);
extern void Algorithm_Flux_Psi_Weak_Disable(real32_T *rty_PI_out);
extern void Algorithm_FluxWeak_GEA_Psi_Weak(real32_T rtu_Psi_Err, real32_T
  rtu_PwmT, real32_T rtu_Psi, real32_T *rty_PI_out,
  DW_Psi_Weak_Algorithm_FluxWea_T *localDW);
extern void LPF_Algo_Init(DW_LPF_Algo_T *localDW);
extern void LPF_Algo_Reset(DW_LPF_Algo_T *localDW);
extern void LPF_Algo(real32_T rtu_u, real32_T rtu_Ts, real32_T rtu_N, real32_T
                     *rty_Out1, DW_LPF_Algo_T *localDW);
extern void Algorithm_FluxWeak_AlphaBeta2dq(real32_T rtu_ThetaE, real32_T rtu_Ia,
  real32_T rtu_Ib, real32_T *rty_Id, real32_T *rty_Iq);
extern void Algorithm_FluxWeak_GEAR2_ab_dq(real32_T rtu_ThetaE, real32_T rtu_Ia,
  real32_T rtu_Ib, real32_T *rty_Id, real32_T *rty_Iq);

#endif                                 /* RTW_HEADER_Algorithm_FluxWeak_GEAR2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
