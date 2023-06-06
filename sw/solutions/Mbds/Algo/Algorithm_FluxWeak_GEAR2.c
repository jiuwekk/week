/*
 * File: Algorithm_FluxWeak_GEAR2.c
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

#include "Algorithm_FluxWeak_GEAR2.h"
#include "Algorithm_FluxWeak_GEAR2_private.h"

const AlgoFun_inspect_bus Algorithm_FluxWeak_GEAR2_rtZAlgoFun_inspect_bus = {
  0.0F,                                /* ThetaRawE */
  0.0F,                                /* ThetaRawM */
  0.0F,                                /* Angle_park */
  0.0F,                                /* Angle_Ipark */
  0.0F,                                /* Spd_E */
  0.0F,                                /* IdRef */
  0.0F,                                /* IqRef */
  0.0F,                                /* PI_Id_Ui */
  0.0F,                                /* PI_Iq_Ui */
  0.0F,                                /* Ipark_Alpha */
  0.0F,                                /* Ipark_Beta */
  0.0F,                                /* Psi_whole */
  0.0F,                                /* Psi_Weak */
  0.0F,                                /* PsiWeak_Ui */
  0.0F,                                /* IsRef */
  0.0F                                 /* TorReq */
} ;                                    /* AlgoFun_inspect_bus ground */

/* Exported block states */
AlgoFun_inspect_bus AlgoFun;           /* Simulink.Signal object 'AlgoFun' */

/* Block signals and states (auto storage) */
DW_Algorithm_FluxWeak_GEAR2_T Algorithm_FluxWeak_GEAR2_DW;

/* Real-time model */
RT_MODEL_Algorithm_FluxWeak_G_T Algorithm_FluxWeak_GEAR2_M_;
RT_MODEL_Algorithm_FluxWeak_G_T *const Algorithm_FluxWeak_GEAR2_M =
  &Algorithm_FluxWeak_GEAR2_M_;
uint32_T plook_u32f_evenckan(real32_T u, real32_T bp0, real32_T bpSpace,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  real32_T fbpIndex;

  /* Prelookup - Index only
     Index Search method: 'even'
     Interpolation method: 'Use nearest'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0UL;
  } else {
    fbpIndex = (u - bp0) * (1.0F / bpSpace);
    if (fbpIndex < maxIndex) {
      bpIndex = (uint32_T)fbpIndex;
      if (((real32_T)(bpIndex + 1UL) * bpSpace + bp0) - u <= u - ((real32_T)
           bpIndex * bpSpace + bp0)) {
        bpIndex++;
      }
    } else {
      bpIndex = maxIndex;
    }
  }

  return bpIndex;
}

uint32_T plook_u32ff_evenca(real32_T u, real32_T bp0, real32_T bpSpace, uint32_T
  maxIndex, real32_T *fraction)
{
  uint32_T bpIndex;
  real32_T invSpc;
  real32_T fbpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0UL;
    *fraction = 0.0F;
  } else {
    invSpc = 1.0F / bpSpace;
    fbpIndex = (u - bp0) * invSpc;
    if (fbpIndex < maxIndex) {
      bpIndex = (uint32_T)fbpIndex;
      *fraction = (u - ((real32_T)bpIndex * bpSpace + bp0)) * invSpc;
    } else {
      bpIndex = maxIndex;
      *fraction = 0.0F;
    }
  }

  return bpIndex;
}

real32_T intrp1d_fu32fla_pw(uint32_T bpIndex, real32_T frac, const real32_T
  table[], uint32_T maxIndex)
{
  real32_T y;

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (bpIndex == maxIndex) {
    y = table[bpIndex];
  } else {
    y = (table[bpIndex + 1UL] - table[bpIndex]) * frac + table[bpIndex];
  }

  return y;
}

real32_T intrp2d_fu32fla_pw(const uint32_T bpIndex[], const real32_T frac[],
  const real32_T table[], uint32_T stride, const uint32_T maxIndex[])
{
  real32_T y;
  real32_T yR_1d;
  uint32_T offset_1d;

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  offset_1d = bpIndex[1UL] * stride + bpIndex[0UL];
  if (bpIndex[0UL] == maxIndex[0UL]) {
    y = table[offset_1d];
  } else {
    y = (table[offset_1d + 1UL] - table[offset_1d]) * frac[0UL] +
      table[offset_1d];
  }

  if (bpIndex[1UL] == maxIndex[1UL]) {
  } else {
    offset_1d += stride;
    if (bpIndex[0UL] == maxIndex[0UL]) {
      yR_1d = table[offset_1d];
    } else {
      yR_1d = (table[offset_1d + 1UL] - table[offset_1d]) * frac[0UL] +
        table[offset_1d];
    }

    y += (yR_1d - y) * frac[1UL];
  }

  return y;
}

/*
 * Output and update for function-call system:
 *    '<S30>/Function-Call Subsystem'
 *    '<S31>/Function-Call Subsystem'
 */
void Algorithm_FunctionCallSubsystem(void)
{
  /* Saturate: '<S35>/Saturation' incorporates:
   *  StateReader: '<S35>/State Reader'
   */
  if (Algorithm_FluxWeak_GEAR2_DW.Subsystem.PI.I_state > 5.0F) {
    /* StateWriter: '<S35>/State Writer' */
    Algorithm_FluxWeak_GEAR2_DW.Subsystem.PI.I_state = 5.0F;
  } else {
    if (Algorithm_FluxWeak_GEAR2_DW.Subsystem.PI.I_state < -5.0F) {
      /* StateWriter: '<S35>/State Writer' */
      Algorithm_FluxWeak_GEAR2_DW.Subsystem.PI.I_state = -5.0F;
    }
  }

  /* End of Saturate: '<S35>/Saturation' */
}

/*
 * Output and update for atomic system:
 *    '<S36>/PI'
 *    '<S42>/PI'
 */
void PI_Algo_chuanlian(real32_T rtu_Err, real32_T rtu_Kp, real32_T rtu_KI,
  real32_T rtu_T, real32_T *rty_PIOut, real32_T *rty_I_State,
  DW_PI_Algo_chuanlian_T *localDW)
{
  real32_T rtb_Product1_f;

  /* Product: '<S38>/Product' */
  rtb_Product1_f = rtu_Kp * rtu_Err;

  /* DiscreteIntegrator: '<S38>/Discrete-Time Integrator1' */
  *rty_I_State = localDW->I_state;

  /* Sum: '<S38>/Add' */
  *rty_PIOut = rtb_Product1_f + *rty_I_State;

  /* Product: '<S38>/Product1' */
  rtb_Product1_f *= rtu_KI;

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator1' incorporates:
   *  Product: '<S38>/Product2'
   */
  localDW->I_state += rtb_Product1_f * rtu_T;
}

/* Output and update for function-call system: '<S30>/Subsystem' */
void Algorithm_FluxWeak_GE_Subsystem(real32_T rtu_IqRef, real32_T rtu_IdBak,
  real32_T rtu_IdRef, real32_T rtu_AlgoT, real32_T rtu_KCom, real32_T rtu_Ne_si,
  real32_T *rty_Out1, DW_Subsystem_Algorithm_FluxWe_T *localDW)
{
  real32_T rtb_DiscreteTimeIntegrator1;
  real32_T rtb_Add_c1;

  /* Outputs for Atomic SubSystem: '<S36>/PI' */

  /* Sum: '<S36>/Add' incorporates:
   *  Constant: '<S36>/Constant'
   *  Constant: '<S36>/Constant1'
   */
  PI_Algo_chuanlian(rtu_IdRef - rtu_IdBak, PMSM_Param.IdKp, PMSM_Param.IdKi *
                    1000.0F, rtu_AlgoT, &rtb_Add_c1,
                    &rtb_DiscreteTimeIntegrator1, &localDW->PI);

  /* End of Outputs for SubSystem: '<S36>/PI' */

  /* DataStoreWrite: '<S36>/Data Store Write1' */
  AlgoFun.PI_Id_Ui = rtb_DiscreteTimeIntegrator1;

  /* Product: '<S39>/Product1' incorporates:
   *  Constant: '<S39>/Udc_base'
   *  Gain: '<S39>/Gain1'
   *  Gain: '<S39>/Lq'
   *  Product: '<S39>/Divide'
   */
  rtb_DiscreteTimeIntegrator1 = PMSM_Param.CurNorm * 1.414F * rtu_IqRef *
    0.0022F / 346.410156F * rtu_Ne_si;

  /* DataStoreWrite: '<S36>/Data Store Write2' */
  AlgoFun.Ipark_Beta = rtb_DiscreteTimeIntegrator1;

  /* Product: '<S36>/Product' incorporates:
   *  Sum: '<S36>/Add1'
   */
  rtb_Add_c1 = (rtb_Add_c1 - rtb_DiscreteTimeIntegrator1) * rtu_KCom;

  /* Saturate: '<S36>/Saturation' */
  if (rtb_Add_c1 > 1.5F) {
    *rty_Out1 = 1.5F;
  } else if (rtb_Add_c1 < -1.5F) {
    *rty_Out1 = -1.5F;
  } else {
    *rty_Out1 = rtb_Add_c1;
  }

  /* End of Saturate: '<S36>/Saturation' */
}

/* Output and update for function-call system: '<S31>/Subsystem' */
void Algorithm_FluxWeak__Subsystem_o(real32_T rtu_IqBak, real32_T rtu_IqRef,
  real32_T rtu_AlgoT, real32_T rtu_KCom, real32_T rtu_Ne_Si, real32_T rtu_IdRef,
  real32_T *rty_PI_out, DW_Subsystem_Algorithm_Flux_k_T *localDW)
{
  real32_T rtb_DiscreteTimeIntegrator1;
  real32_T rtb_Add_p;

  /* Outputs for Atomic SubSystem: '<S42>/PI' */

  /* Sum: '<S42>/Add' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S42>/Constant1'
   */
  PI_Algo_chuanlian(rtu_IqRef - rtu_IqBak, PMSM_Param.IqKp, PMSM_Param.IqKi *
                    1000.0F, rtu_AlgoT, &rtb_Add_p, &rtb_DiscreteTimeIntegrator1,
                    &localDW->PI);

  /* End of Outputs for SubSystem: '<S42>/PI' */

  /* DataStoreWrite: '<S42>/Data Store Write1' */
  AlgoFun.PI_Iq_Ui = rtb_DiscreteTimeIntegrator1;

  /* Product: '<S45>/Product1' incorporates:
   *  Bias: '<S45>/Psi_f'
   *  Constant: '<S45>/Udc_base'
   *  Gain: '<S45>/Gain1'
   *  Gain: '<S45>/Ld'
   *  Product: '<S45>/Divide'
   */
  rtb_DiscreteTimeIntegrator1 = (PMSM_Param.CurNorm * 1.414F * rtu_IdRef *
    0.0011F + 0.29F) / 346.410156F * rtu_Ne_Si;

  /* DataStoreWrite: '<S42>/Data Store Write2' */
  AlgoFun.Ipark_Alpha = rtb_DiscreteTimeIntegrator1;

  /* Product: '<S42>/Product' incorporates:
   *  Sum: '<S42>/Add1'
   */
  rtb_Add_p = (rtb_DiscreteTimeIntegrator1 + rtb_Add_p) * rtu_KCom;

  /* Saturate: '<S42>/Saturation' */
  if (rtb_Add_p > 1.5F) {
    *rty_PI_out = 1.5F;
  } else if (rtb_Add_p < -1.5F) {
    *rty_PI_out = -1.5F;
  } else {
    *rty_PI_out = rtb_Add_p;
  }

  /* End of Saturate: '<S42>/Saturation' */
}

/* Output and update for atomic system: '<S18>/dq--alphabeta' */
void Algorithm_FluxWeak__dqalphabeta(real32_T rtu_d, real32_T rtu_q, real32_T
  rtu_Theta, real32_T *rty_alpha, real32_T *rty_beta)
{
  real32_T rtb_u;
  real32_T rtb_u_l;

  /* Trigonometry: '<S47>/1' */
  rtb_u = sinf(rtu_Theta);

  /* Trigonometry: '<S47>/2' */
  rtb_u_l = cosf(rtu_Theta);

  /* Sum: '<S47>/Add1' incorporates:
   *  Product: '<S47>/Product2'
   *  Product: '<S47>/Product3'
   */
  *rty_alpha = rtu_d * rtb_u_l - rtb_u * rtu_q;

  /* Sum: '<S47>/Add2' incorporates:
   *  Product: '<S47>/Product'
   *  Product: '<S47>/Product1'
   */
  *rty_beta = rtu_d * rtb_u + rtu_q * rtb_u_l;
}

/* Output and update for function-call system: '<S52>/IntLim' */
void Algorithm_FluxWeak_GEAR2_IntLim(real32_T rtu_TorReq, real32_T rtu_Psi_fit)
{
  real32_T rtb_Switch2_h;

  /* Lookup_n-D: '<S55>/Psi_compensate_max' */
  rtb_Switch2_h =
    Algorithm_FluxWeak_GEAR2_ConstP.Psi_compensate_max_tableData[plook_u32f_evenckan
    (rtu_TorReq, 0.0F, 71.4285736F, 14UL) * 50UL + plook_u32f_evenckan
    (rtu_Psi_fit, 0.088F, 0.0126061216F, 49UL)];

  /* Switch: '<S57>/Switch2' incorporates:
   *  Lookup_n-D: '<S55>/Psi_compensate_max'
   *  RelationalOperator: '<S57>/LowerRelop1'
   *  StateReader: '<S55>/State Reader1'
   */
  if (!(Algorithm_FluxWeak_GEAR2_DW.Psi_Weak.PI.I_state >
        Algorithm_FluxWeak_GEAR2_ConstP.Psi_compensate_max_tableData[plook_u32f_evenckan
        (rtu_TorReq, 0.0F, 71.4285736F, 14UL) * 50UL + plook_u32f_evenckan
        (rtu_Psi_fit, 0.088F, 0.0126061216F, 49UL)])) {
    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S55>/Constant'
     *  RelationalOperator: '<S57>/UpperRelop'
     */
    if (Algorithm_FluxWeak_GEAR2_DW.Psi_Weak.PI.I_state < -1.0F) {
      rtb_Switch2_h = -1.0F;
    } else {
      rtb_Switch2_h = Algorithm_FluxWeak_GEAR2_DW.Psi_Weak.PI.I_state;
    }

    /* End of Switch: '<S57>/Switch' */
  }

  /* End of Switch: '<S57>/Switch2' */

  /* StateWriter: '<S55>/State Writer1' */
  Algorithm_FluxWeak_GEAR2_DW.Psi_Weak.PI.I_state = rtb_Switch2_h;
}

/* Output and update for atomic system: '<S56>/PI' */
void PI_Algo(real32_T rtu_Err, real32_T rtu_Kp, real32_T rtu_KI, real32_T rtu_T,
             real32_T *rty_PIOut, real32_T *rty_I_State, DW_PI_Algo_T *localDW)
{
  /* DiscreteIntegrator: '<S58>/Discrete-Time Integrator1' */
  *rty_I_State = localDW->I_state;

  /* Sum: '<S58>/Add' incorporates:
   *  Product: '<S58>/Product'
   */
  *rty_PIOut = rtu_Kp * rtu_Err + *rty_I_State;

  /* Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator1' incorporates:
   *  Product: '<S58>/Product1'
   *  Product: '<S58>/Product2'
   */
  localDW->I_state += rtu_Err * rtu_KI * rtu_T;
}

/* System initialize for function-call system: '<S52>/Psi_Weak' */
void Algorithm_FluxWea_Psi_Weak_Init(real32_T *rty_PI_out)
{
  /* SystemInitialize for Outport: '<S56>/PI_out' */
  *rty_PI_out = 2000.0F;
}

/* Disable for function-call system: '<S52>/Psi_Weak' */
void Algorithm_Flux_Psi_Weak_Disable(real32_T *rty_PI_out)
{
  /* Disable for Outport: '<S56>/PI_out' */
  *rty_PI_out = 2000.0F;
}

/* Output and update for function-call system: '<S52>/Psi_Weak' */
void Algorithm_FluxWeak_GEA_Psi_Weak(real32_T rtu_Psi_Err, real32_T rtu_PwmT,
  real32_T rtu_Psi, real32_T *rty_PI_out, DW_Psi_Weak_Algorithm_FluxWea_T
  *localDW)
{
  real32_T rtb_DiscreteTimeIntegrator1;
  real32_T rtb_Add_p;
  real32_T u0;

  /* Bias: '<S56>/Bias' incorporates:
   *  Gain: '<S56>/Gain'
   */
  u0 = -15.4125F * rtu_Psi + 5.5985F;

  /* Saturate: '<S56>/Saturation' */
  if (u0 > 2.2F) {
    u0 = 2.2F;
  } else {
    if (u0 < 0.5F) {
      u0 = 0.5F;
    }
  }

  /* End of Saturate: '<S56>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S56>/PI' */

  /* Product: '<S56>/Product' incorporates:
   *  Constant: '<S56>/Constant'
   *  Constant: '<S56>/Constant1'
   */
  PI_Algo(rtu_Psi_Err, PMSM_Param.FW1Kp * u0, PMSM_Param.FW1Ki, rtu_PwmT,
          &rtb_Add_p, &rtb_DiscreteTimeIntegrator1, &localDW->PI);

  /* End of Outputs for SubSystem: '<S56>/PI' */

  /* DataStoreWrite: '<S56>/Data Store Write1' */
  AlgoFun.PsiWeak_Ui = rtb_DiscreteTimeIntegrator1;

  /* Saturate: '<S56>/Saturation1' */
  if (rtb_Add_p > 1.0F) {
    *rty_PI_out = 1.0F;
  } else if (rtb_Add_p < -1.0F) {
    *rty_PI_out = -1.0F;
  } else {
    *rty_PI_out = rtb_Add_p;
  }

  /* End of Saturate: '<S56>/Saturation1' */
}

/* System initialize for atomic system: '<S50>/lpf1' */
void LPF_Algo_Init(DW_LPF_Algo_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' */
  localDW->LPF_STATE = 0.0F;
}

/* System reset for atomic system: '<S50>/lpf1' */
void LPF_Algo_Reset(DW_LPF_Algo_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' */
  localDW->LPF_STATE = 0.0F;
}

/* Output and update for atomic system: '<S50>/lpf1' */
void LPF_Algo(real32_T rtu_u, real32_T rtu_Ts, real32_T rtu_N, real32_T
              *rty_Out1, DW_LPF_Algo_T *localDW)
{
  /* DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' */
  *rty_Out1 = localDW->LPF_STATE;

  /* Update for DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' incorporates:
   *  Product: '<S53>/Product'
   *  Product: '<S53>/Product1'
   *  Sum: '<S53>/Sum'
   */
  localDW->LPF_STATE += (rtu_u - *rty_Out1) * rtu_N * rtu_Ts;
}

/* Output and update for atomic system: '<S76>/AlphaBeta2dq' */
void Algorithm_FluxWeak_AlphaBeta2dq(real32_T rtu_ThetaE, real32_T rtu_Ia,
  real32_T rtu_Ib, real32_T *rty_Id, real32_T *rty_Iq)
{
  real32_T rtb_Cos;
  real32_T rtb_Product1_fz;
  real32_T rtb_Product4;

  /* Trigonometry: '<S78>/Cos' */
  rtb_Cos = cosf(rtu_ThetaE);

  /* Trigonometry: '<S78>/Sin' */
  rtb_Product1_fz = sinf(rtu_ThetaE);

  /* Product: '<S78>/Product4' incorporates:
   *  Constant: '<S78>/Constant'
   *  Gain: '<S78>/Gain'
   *  Sum: '<S78>/Add2'
   */
  rtb_Product4 = (2.0F * rtu_Ib + rtu_Ia) * 0.577350259F;

  /* Sum: '<S78>/Add' incorporates:
   *  Product: '<S78>/Product'
   *  Product: '<S78>/Product2'
   */
  *rty_Id = rtu_Ia * rtb_Cos + rtb_Product1_fz * rtb_Product4;

  /* Product: '<S78>/Product1' */
  rtb_Product1_fz *= rtu_Ia;

  /* Sum: '<S78>/Add1' incorporates:
   *  Product: '<S78>/Product3'
   */
  *rty_Iq = rtb_Cos * rtb_Product4 - rtb_Product1_fz;
}

/* Output and update for atomic system: '<S75>/ab_dq' */
void Algorithm_FluxWeak_GEAR2_ab_dq(real32_T rtu_ThetaE, real32_T rtu_Ia,
  real32_T rtu_Ib, real32_T *rty_Id, real32_T *rty_Iq)
{
  /* Outputs for Atomic SubSystem: '<S76>/AlphaBeta2dq' */
  Algorithm_FluxWeak_AlphaBeta2dq(rtu_ThetaE, rtu_Ia, rtu_Ib, rty_Id, rty_Iq);

  /* End of Outputs for SubSystem: '<S76>/AlphaBeta2dq' */
}

real32_T rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T a;
  a = fabsf(u0);
  y = fabsf(u1);
  if (a < y) {
    a /= y;
    y *= sqrtf(a * a + 1.0F);
  } else if (a > y) {
    y /= a;
    y = sqrtf(y * y + 1.0F) * a;
  } else {
    if (!rtIsNaNF(y)) {
      y = a * 1.41421354F;
    }
  }

  return y;
}

/* Model step function */
void AgoCall(void)
{
  uint32_T bpIdx;
  uint32_T bpIndices[2];
  uint32_T bpIndices_0[2];
  int16_T rtb_IGBT;
  boolean_T rtb_Switch_e;
  real32_T rtb_Svpwm_Ta;
  int16_T rtb_PosSen;
  boolean_T rtb_Switch1;
  real32_T rtb_Subtract;
  real32_T rtb_ParkCompTheta;
  real32_T rtb_IParkCompTheta;
  real32_T rtb_Gain4_a;
  real32_T rtb_Gain_cy[2];
  uint16_T rtb_Add_g;
  real32_T rtb_MultiportSwitch[2];
  real32_T rtb_Iq_Table;
  real32_T rtb_Add_p;
  real32_T Add;
  real32_T Add1;
  real32_T Abs;
  real32_T Saturation1;
  real32_T Switch;
  real32_T rtb_cur_uvw_pu_idx_1;
  real32_T rtb_cur_uvw_pu_idx_2;
  int16_T u;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_AgoCall_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Logic: '<S9>/Logical Operator1' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read1'
   */
  rtb_IGBT = ((PMSM_Input.AgoSample.IGBT1FaultState != 0U) ||
              (PMSM_Input.AgoSample.IGBT2FaultState != 0U) ||
              (PMSM_Input.AgoSample.IGBT3FaultState != 0U));

  /* Switch: '<S86>/Switch' incorporates:
   *  Constant: '<S86>/SwapPhase'
   *  DataStoreRead: '<S1>/Data Store Read1'
   */
  if (PMSM_Param.VWDirChg != 0U) {
    rtb_cur_uvw_pu_idx_1 = PMSM_Input.AgoSample.CurWPu;
    rtb_cur_uvw_pu_idx_2 = PMSM_Input.AgoSample.CurVPu;
  } else {
    rtb_cur_uvw_pu_idx_1 = PMSM_Input.AgoSample.CurVPu;
    rtb_cur_uvw_pu_idx_2 = PMSM_Input.AgoSample.CurWPu;
  }

  /* End of Switch: '<S86>/Switch' */

  /* MinMax: '<S9>/MinMax' incorporates:
   *  Abs: '<S9>/Abs'
   *  DataStoreRead: '<S1>/Data Store Read1'
   */
  Saturation1 = fmaxf(fmaxf(fabsf(PMSM_Input.AgoSample.CurUPu), fabsf
    (rtb_cur_uvw_pu_idx_1)), fabsf(rtb_cur_uvw_pu_idx_2));

  /* Chart: '<S9>/OverCur2' incorporates:
   *  MinMax: '<S9>/MinMax'
   */
  /* Gateway: Function-Call
     Subsystem/Fault/jugment/OverCur2 */
  /* During: Function-Call
     Subsystem/Fault/jugment/OverCur2 */
  /* Entry Internal: Function-Call
     Subsystem/Fault/jugment/OverCur2 */
  /* Transition: '<S14>:42' */
  /* '<S14>:64:1' sf_internal_predicateOutput = ... */
  /* '<S14>:64:1' OC2_fault; */
  if (Algorithm_FluxWeak_GEAR2_DW.OC2_fault == 0UL) {
    /* Transition: '<S14>:65' */
    /* '<S14>:44:1' sf_internal_predicateOutput = ... */
    /* '<S14>:44:1' Max_Cur_uvw_pu>PMSM_Param.OC2; */
    if (Saturation1 > PMSM_Param.OC2) {
      /* Transition: '<S14>:44' */
      /* Transition: '<S14>:46' */
      /* '<S14>:46:1' OC2_num=OC2_num+1; */
      rtb_Add_g = Algorithm_FluxWeak_GEAR2_DW.OC2_num + /*MW:OvSatOk*/ 1U;
      if (rtb_Add_g < Algorithm_FluxWeak_GEAR2_DW.OC2_num) {
        rtb_Add_g = MAX_uint16_T;
      }

      Algorithm_FluxWeak_GEAR2_DW.OC2_num = rtb_Add_g;

      /* Transition: '<S14>:49' */
    } else {
      /* Transition: '<S14>:50' */
      /* '<S14>:50:1' OC2_num=0; */
      Algorithm_FluxWeak_GEAR2_DW.OC2_num = 0U;
    }

    /* Transition: '<S14>:52' */
    /* '<S14>:54:1' sf_internal_predicateOutput = ... */
    /* '<S14>:54:1' OC2_num>=3; */
    if (Algorithm_FluxWeak_GEAR2_DW.OC2_num >= 3U) {
      /* Transition: '<S14>:54' */
      /* Transition: '<S14>:56' */
      /* '<S14>:56:1' OC2_fault=1; */
      Algorithm_FluxWeak_GEAR2_DW.OC2_fault = 1UL;

      /* Transition: '<S14>:58' */
    } else {
      /* Transition: '<S14>:59' */
    }
  } else {
    /* Transition: '<S14>:64' */
    /* Transition: '<S14>:69' */
    /* Transition: '<S14>:70' */
    /* Transition: '<S14>:58' */
  }

  /* End of Chart: '<S9>/OverCur2' */

  /* Chart: '<S9>/OverVolt3' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read1'
   */
  /* Transition: '<S14>:61' */
  /* Gateway: Function-Call
     Subsystem/Fault/jugment/OverVolt3 */
  /* During: Function-Call
     Subsystem/Fault/jugment/OverVolt3 */
  /* Entry Internal: Function-Call
     Subsystem/Fault/jugment/OverVolt3 */
  /* Transition: '<S15>:33' */
  /* '<S15>:46:1' sf_internal_predicateOutput = ... */
  /* '<S15>:46:1' OV3_fault; */
  if (Algorithm_FluxWeak_GEAR2_DW.OV3_fault == 0UL) {
    /* Transition: '<S15>:42' */
    /* '<S15>:35:1' sf_internal_predicateOutput = ... */
    /* '<S15>:35:1' Volt>PMSM_Param.OV3; */
    if (PMSM_Input.AppSample.VoltCap > PMSM_Param.OV3) {
      /* Transition: '<S15>:35' */
      /* Transition: '<S15>:38' */
      /* '<S15>:38:1' OV3_fault=1; */
      Algorithm_FluxWeak_GEAR2_DW.OV3_fault = 1UL;

      /* Transition: '<S15>:39' */
    } else {
      /* Transition: '<S15>:40' */
    }

    /* Transition: '<S15>:44' */
  } else {
    /* Transition: '<S15>:46' */
    /* Transition: '<S15>:48' */
    /* Transition: '<S15>:49' */
  }

  /* End of Chart: '<S9>/OverVolt3' */

  /* Logic: '<S8>/Logical Operator1' */
  rtb_Switch_e = (((uint16_T)rtb_IGBT != 0U) ||
                  (Algorithm_FluxWeak_GEAR2_DW.OC2_fault != 0UL) ||
                  (Algorithm_FluxWeak_GEAR2_DW.OV3_fault != 0UL));

  /* Abs: '<S8>/Abs' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read1'
   */
  rtb_Svpwm_Ta = fabsf(PMSM_Input.AgoSample.Speed);

  /* Relay: '<S8>/Relay1' */
  if (rtb_Svpwm_Ta >= PMSM_Param.ASCSpd) {
    Algorithm_FluxWeak_GEAR2_DW.Relay1_Mode = true;
  } else {
    if (rtb_Svpwm_Ta <= 500.0F) {
      Algorithm_FluxWeak_GEAR2_DW.Relay1_Mode = false;
    }
  }

  /* Switch: '<S8>/Switch1' incorporates:
   *  Relay: '<S8>/Relay1'
   */
  rtb_Switch1 = (Algorithm_FluxWeak_GEAR2_DW.Relay1_Mode && rtb_Switch_e);

  /* Logic: '<S9>/Logical Operator3' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read1'
   */
  rtb_PosSen = ((PMSM_Input.AgoSample.PosSenFaultState1 != 0U) ||
                (PMSM_Input.AgoSample.PosSenFaultState2 != 0U));

  /* Switch: '<S8>/Switch' incorporates:
   *  Relay: '<S8>/Relay1'
   */
  rtb_Switch_e = ((!Algorithm_FluxWeak_GEAR2_DW.Relay1_Mode) && rtb_Switch_e);

  /* Chart: '<S5>/Chart' incorporates:
   *  Constant: '<S84>/Constant'
   *  Constant: '<S85>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read2'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Logic: '<S5>/Logical Operator1'
   *  Logic: '<S5>/Logical Operator2'
   *  Logic: '<S8>/Logical Operator4'
   *  RelationalOperator: '<S84>/Compare'
   *  RelationalOperator: '<S85>/Compare'
   */
  /* Gateway: Function-Call
     Subsystem/State/Chart */
  /* During: Function-Call
     Subsystem/State/Chart */
  /* Entry Internal: Function-Call
     Subsystem/State/Chart */
  /* Transition: '<S82>:49' */
  /* '<S82>:18:1' sf_internal_predicateOutput = ... */
  /* '<S82>:18:1' AscEn; */
  if (rtb_Switch1 || ((uint16_T)rtb_PosSen != 0U) || (App_Output.ctrl.AscEn !=
       0U) || (App_Output.fault.PwmWorkMode == 2U)) {
    /* Transition: '<S82>:18' */
    /* Transition: '<S82>:35' */
    /* Asc */
    /* '<S82>:35:1' state = 3; */
    Algorithm_FluxWeak_GEAR2_DW.AlgoState = 3;

    /* Transition: '<S82>:43' */
    /* Transition: '<S82>:55' */
    /* Transition: '<S82>:85' */
  } else {
    /* Transition: '<S82>:20' */
    /* '<S82>:22:1' sf_internal_predicateOutput = ... */
    /* '<S82>:22:1' OtherErr; */
    if ((App_Output.fault.PwmWorkMode == 0U) || rtb_Switch_e) {
      /* Transition: '<S82>:22' */
      /* Transition: '<S82>:37' */
      /* OffLine */
      /* '<S82>:37:1' state = 2; */
      Algorithm_FluxWeak_GEAR2_DW.AlgoState = 2;

      /* Transition: '<S82>:55' */
      /* Transition: '<S82>:85' */
    } else {
      /* Transition: '<S82>:51' */
      /* '<S82>:82:1' sf_internal_predicateOutput = ... */
      /* '<S82>:82:1'  APPEn; */
      if (App_Output.power.DRV1_En != 0U) {
        /* Transition: '<S82>:82' */
        /* Transition: '<S82>:84' */
        /* Online */
        /* '<S82>:84:1' state =  1; */
        Algorithm_FluxWeak_GEAR2_DW.AlgoState = 1;

        /* Transition: '<S82>:85' */
      } else {
        /* Transition: '<S82>:24' */
        /* Idle */
        /* '<S82>:24:1' state =  0; */
        Algorithm_FluxWeak_GEAR2_DW.AlgoState = 0;
      }
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* Gain: '<S86>/Gain1' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read1'
   *  Gain: '<S86>/Gain2'
   */
  rtb_Svpwm_Ta = PMSM_Param.MotPole * PMSM_Input.AgoSample.Speed * 0.104719758F;

  /* Saturate: '<S86>/Saturation' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read1'
   */
  if (PMSM_Input.AppSample.VoltCap_compensate > 5.0F) {
    rtb_cur_uvw_pu_idx_2 = 5.0F;
  } else if (PMSM_Input.AppSample.VoltCap_compensate < 0.0001F) {
    rtb_cur_uvw_pu_idx_2 = 0.0001F;
  } else {
    rtb_cur_uvw_pu_idx_2 = PMSM_Input.AppSample.VoltCap_compensate;
  }

  /* End of Saturate: '<S86>/Saturation' */

  /* Switch: '<S86>/Switch4' incorporates:
   *  Constant: '<S86>/Constant3'
   *  Constant: '<S90>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read1'
   *  DataStoreRead: '<S1>/Data Store Read2'
   *  RelationalOperator: '<S90>/Compare'
   *  Sum: '<S86>/Add1'
   */
  if (PMSM_Input.AppSample.CalibStep == 3U) {
    Switch = App_Output.ctrl.CalibZeroPoint;
  } else {
    Switch = PMSM_Param.ZeroPoint + App_Output.table.ZeroPointBias;
  }

  /* End of Switch: '<S86>/Switch4' */

  /* Sum: '<S86>/Subtract' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read1'
   */
  rtb_Subtract = PMSM_Input.AgoSample.ThetaRT - Switch;

  /* Switch: '<S86>/Switch2' incorporates:
   *  Bias: '<S86>/Bias1'
   *  Constant: '<S89>/Constant'
   *  RelationalOperator: '<S89>/Compare'
   */
  if (rtb_Subtract < 0.0F) {
    rtb_Subtract += 4095.0F;
  }

  /* End of Switch: '<S86>/Switch2' */

  /* Switch: '<S86>/Switch1' incorporates:
   *  Constant: '<S86>/Constant'
   *  Constant: '<S86>/Constant1'
   *  Sum: '<S86>/Add'
   */
  if (PMSM_Param.ResolverDirChg != 0U) {
    rtb_Subtract = 4095.0F - rtb_Subtract;
  }

  /* End of Switch: '<S86>/Switch1' */

  /* Gain: '<S86>/Gain3' incorporates:
   *  Gain: '<S86>/Gain4'
   */
  rtb_Subtract = PMSM_Param.PoleRatio * rtb_Subtract * 0.00153435534F;

  /* Switch: '<S74>/Switch1' incorporates:
   *  Constant: '<S74>/Constant3'
   *  DataStoreRead: '<S1>/Data Store Read2'
   *  Gain: '<S74>/Gain'
   *  Product: '<S74>/Product'
   *  Sum: '<S74>/Add'
   */
  if (App_Output.ctrl.AngleSetEn != 0U) {
    rtb_ParkCompTheta = App_Output.ctrl.AngleRefSet;
  } else {
    rtb_ParkCompTheta = rtb_Subtract - 1.0E-6F * PMSM_Param.ParkComp *
      rtb_Svpwm_Ta;
  }

  /* End of Switch: '<S74>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S75>/ab_dq' */

  /* DataStoreRead: '<S1>/Data Store Read1' */
  Algorithm_FluxWeak_GEAR2_ab_dq(rtb_ParkCompTheta, PMSM_Input.AgoSample.CurUPu,
    rtb_cur_uvw_pu_idx_1, &Add, &Add1);

  /* End of Outputs for SubSystem: '<S75>/ab_dq' */

  /* Switch: '<S74>/Switch2' incorporates:
   *  Constant: '<S74>/Constant4'
   *  DataStoreRead: '<S1>/Data Store Read2'
   *  Product: '<S74>/Product1'
   *  Sum: '<S74>/Add1'
   */
  if (App_Output.ctrl.AngleSetEn != 0U) {
    rtb_IParkCompTheta = App_Output.ctrl.AngleRefSet;
  } else {
    rtb_IParkCompTheta = rtb_Svpwm_Ta * App_Output.ctrl.PwmT *
      PMSM_Param.IParkComp + rtb_Subtract;
  }

  /* End of Switch: '<S74>/Switch2' */

  /* Chart: '<S9>/OverCur1' incorporates:
   *  MinMax: '<S9>/MinMax'
   */
  /* Gateway: Function-Call
     Subsystem/Fault/jugment/OverCur1 */
  /* During: Function-Call
     Subsystem/Fault/jugment/OverCur1 */
  /* Entry Internal: Function-Call
     Subsystem/Fault/jugment/OverCur1 */
  /* Transition: '<S13>:42' */
  /* '<S13>:64:1' sf_internal_predicateOutput = ... */
  /* '<S13>:64:1' OC1_fault; */
  if (Algorithm_FluxWeak_GEAR2_DW.OC1_fault != 0UL) {
    /* Transition: '<S13>:64' */
    /* '<S13>:67:1' sf_internal_predicateOutput = ... */
    /* '<S13>:67:1' Max_Cur_uvw_pu<PMSM_Param.OC1/2; */
    if (Saturation1 < PMSM_Param.OC1 / 2.0F) {
      /* Transition: '<S13>:67' */
      /* Transition: '<S13>:72' */
      /* '<S13>:72:1' OC1_fault=0; */
      Algorithm_FluxWeak_GEAR2_DW.OC1_fault = 0UL;

      /* '<S13>:72:1' OC1_num=0; */
      Algorithm_FluxWeak_GEAR2_DW.OC1_num = 0U;

      /* Transition: '<S13>:73' */
    } else {
      /* Transition: '<S13>:69' */
    }

    /* Transition: '<S13>:70' */
    /* Transition: '<S13>:58' */
  } else {
    /* Transition: '<S13>:65' */
    /* '<S13>:44:1' sf_internal_predicateOutput = ... */
    /* '<S13>:44:1' Max_Cur_uvw_pu>PMSM_Param.OC1; */
    if (Saturation1 > PMSM_Param.OC1) {
      /* Transition: '<S13>:44' */
      /* Transition: '<S13>:46' */
      /* '<S13>:46:1' OC1_num=OC1_num+1; */
      rtb_Add_g = Algorithm_FluxWeak_GEAR2_DW.OC1_num + /*MW:OvSatOk*/ 1U;
      if (rtb_Add_g < Algorithm_FluxWeak_GEAR2_DW.OC1_num) {
        rtb_Add_g = MAX_uint16_T;
      }

      Algorithm_FluxWeak_GEAR2_DW.OC1_num = rtb_Add_g;

      /* Transition: '<S13>:49' */
    } else {
      /* Transition: '<S13>:50' */
      /* '<S13>:50:1' OC1_num=0; */
      Algorithm_FluxWeak_GEAR2_DW.OC1_num = 0U;
    }

    /* Transition: '<S13>:52' */
    /* '<S13>:54:1' sf_internal_predicateOutput = ... */
    /* '<S13>:54:1' OC1_num>=3; */
    if (Algorithm_FluxWeak_GEAR2_DW.OC1_num >= 3U) {
      /* Transition: '<S13>:54' */
      /* Transition: '<S13>:56' */
      /* '<S13>:56:1' OC1_fault=1; */
      Algorithm_FluxWeak_GEAR2_DW.OC1_fault = 1UL;

      /* Transition: '<S13>:58' */
    } else {
      /* Transition: '<S13>:59' */
    }
  }

  /* End of Chart: '<S9>/OverCur1' */

  /* Chart: '<S9>/LowVolt3' incorporates:
   *  DataStoreRead: '<S1>/Data Store Read1'
   */
  /* Transition: '<S13>:61' */
  /* Gateway: Function-Call
     Subsystem/Fault/jugment/LowVolt3 */
  /* During: Function-Call
     Subsystem/Fault/jugment/LowVolt3 */
  /* Entry Internal: Function-Call
     Subsystem/Fault/jugment/LowVolt3 */
  /* Transition: '<S12>:33' */
  /* '<S12>:35:1' sf_internal_predicateOutput = ... */
  /* '<S12>:35:1' LV3_fault; */
  if (Algorithm_FluxWeak_GEAR2_DW.LV3_fault != 0UL) {
    /* Transition: '<S12>:35' */
    /* '<S12>:52:1' sf_internal_predicateOutput = ... */
    /* '<S12>:52:1' ~MainRelayState; */
    if (!(PMSM_Input.AppComm.MainRelayState != 0U)) {
      /* Transition: '<S12>:52' */
      /* Transition: '<S12>:56' */
      /* '<S12>:56:1' LV3_fault=0; */
      Algorithm_FluxWeak_GEAR2_DW.LV3_fault = 0UL;

      /* Transition: '<S12>:57' */
    } else {
      /* Transition: '<S12>:53' */
    }

    /* Transition: '<S12>:54' */
    /* Transition: '<S12>:49' */
    /* Transition: '<S12>:45' */
  } else {
    /* Transition: '<S12>:37' */
    /* '<S12>:39:1' sf_internal_predicateOutput = ... */
    /* '<S12>:39:1' MainRelayState; */
    if ((PMSM_Input.AppComm.MainRelayState != 0U) &&
        (PMSM_Input.AppSample.VoltCap < PMSM_Param.LV3)) {
      /* Transition: '<S12>:39' */
      /* '<S12>:41:1' sf_internal_predicateOutput = ... */
      /* '<S12>:41:1' Volt<PMSM_Param.LV3; */
      /* Transition: '<S12>:41' */
      /* Transition: '<S12>:48' */
      /* '<S12>:48:1' LV3_fault=1; */
      Algorithm_FluxWeak_GEAR2_DW.LV3_fault = 1UL;

      /* Transition: '<S12>:49' */
      /* Transition: '<S12>:45' */
    } else {
      /* Transition: '<S12>:46' */
      /* Transition: '<S12>:44' */
      /* Transition: '<S12>:45' */
    }
  }

  /* End of Chart: '<S9>/LowVolt3' */

  /* Chart: '<S10>/Chart' incorporates:
   *  Logic: '<S8>/Logical Operator3'
   */
  /* Gateway: Function-Call
     Subsystem/Fault/Act/LimUpRate/Chart */
  /* During: Function-Call
     Subsystem/Fault/Act/LimUpRate/Chart */
  /* Entry Internal: Function-Call
     Subsystem/Fault/Act/LimUpRate/Chart */
  /* Transition: '<S11>:3' */
  /* '<S11>:5:1' sf_internal_predicateOutput = ... */
  /* '<S11>:5:1' fault; */
  if ((Algorithm_FluxWeak_GEAR2_DW.OC1_fault != 0UL) ||
      (Algorithm_FluxWeak_GEAR2_DW.LV3_fault != 0UL)) {
    /* Transition: '<S11>:5' */
    /* Transition: '<S11>:7' */
    /* '<S11>:7:1' Coef=0; */
    Algorithm_FluxWeak_GEAR2_DW.Coef = 0.0F;

    /* Transition: '<S11>:15' */
    /* Transition: '<S11>:17' */
  } else {
    /* Transition: '<S11>:10' */
    /* '<S11>:12:1' sf_internal_predicateOutput = ... */
    /* '<S11>:12:1' Coef>=1; */
    if (Algorithm_FluxWeak_GEAR2_DW.Coef >= 1.0F) {
      /* Transition: '<S11>:12' */
      /* Transition: '<S11>:14' */
      /* '<S11>:14:1' Coef=1; */
      Algorithm_FluxWeak_GEAR2_DW.Coef = 1.0F;

      /* Transition: '<S11>:17' */
    } else {
      /* Transition: '<S11>:18' */
      /* '<S11>:18:1' Coef=Coef+0.0001; */
      Algorithm_FluxWeak_GEAR2_DW.Coef += 0.0001F;
    }
  }

  /* End of Chart: '<S10>/Chart' */

  /* Outputs for Enabled SubSystem: '<S1>/IsCtrl' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* RelationalOperator: '<S83>/Compare' incorporates:
   *  Constant: '<S50>/1ms'
   *  Constant: '<S83>/Constant'
   *  DataStoreRead: '<S1>/Data Store Read2'
   *  Gain: '<S50>/Gain'
   *  Product: '<S50>/Divide'
   */
  if (Algorithm_FluxWeak_GEAR2_DW.AlgoState == 1) {
    if (!Algorithm_FluxWeak_GEAR2_DW.IsCtrl_MODE) {
      /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
      Algorithm_FluxWeak_GEAR2_DW.UnitDelay_DSTATE = 0.0F;

      /* SystemReset for Atomic SubSystem: '<S50>/lpf1' */
      LPF_Algo_Reset(&Algorithm_FluxWeak_GEAR2_DW.lpf1);

      /* End of SystemReset for SubSystem: '<S50>/lpf1' */

      /* SystemReset for Chart: '<S52>/Chart' */
      Algorithm_FluxWeak_GEAR2_DW.is_active_c3_Algorithm_FluxWeak = 0U;

      /* SystemReset for Chart: '<S30>/Chart' */
      Algorithm_FluxWeak_GEAR2_DW.is_active_c2_Algorithm_FluxWeak = 0U;

      /* SystemReset for Chart: '<S31>/Chart' */
      Algorithm_FluxWeak_GEAR2_DW.is_active_c1_Algorithm_FluxWeak = 0U;
      Algorithm_FluxWeak_GEAR2_DW.IsCtrl_MODE = true;
    }

    /* Abs: '<S50>/Abs2' */
    Saturation1 = fabsf(rtb_Svpwm_Ta);

    /* Saturate: '<S50>/Saturation1' */
    if (Saturation1 > 1.0E+6F) {
      Saturation1 = 1.0E+6F;
    } else {
      if (Saturation1 < 10.0F) {
        Saturation1 = 10.0F;
      }
    }

    /* End of Saturate: '<S50>/Saturation1' */

    /* Saturate: '<S50>/Saturation' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read1'
     */
    if (PMSM_Input.AppSample.VoltCap > 1000.0F) {
      Switch = 1000.0F;
    } else if (PMSM_Input.AppSample.VoltCap < 10.0F) {
      Switch = 10.0F;
    } else {
      Switch = PMSM_Input.AppSample.VoltCap;
    }

    /* End of Saturate: '<S50>/Saturation' */

    /* Outputs for Atomic SubSystem: '<S50>/lpf1' */
    LPF_Algo(1.0F / Saturation1 * (0.577350259F * Switch), App_Output.ctrl.AlgoT,
             1000.0F, &rtb_cur_uvw_pu_idx_1, &Algorithm_FluxWeak_GEAR2_DW.lpf1);

    /* End of Outputs for SubSystem: '<S50>/lpf1' */

    /* Lookup_n-D: '<S52>/1-D Lookup Table' incorporates:
     *  Constant: '<S50>/1ms'
     *  DataStoreRead: '<S1>/Data Store Read2'
     *  Gain: '<S50>/Gain'
     *  Product: '<S50>/Divide'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    bpIdx = plook_u32ff_evenca(Algorithm_FluxWeak_GEAR2_DW.UnitDelay_DSTATE,
      0.0F, 0.0100502511F, 199UL, &rtb_Iq_Table);

    /* Gain: '<S50>/Gain4' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read2'
     *  Product: '<S50>/Product'
     */
    rtb_Gain4_a = App_Output.ctrl.TqReq * Algorithm_FluxWeak_GEAR2_DW.Coef *
      1000.0F;

    /* Abs: '<S50>/Abs' */
    Abs = fabsf(rtb_Gain4_a);

    /* Chart: '<S52>/Chart' incorporates:
     *  Constant: '<S52>/Constant'
     *  DataStoreRead: '<S1>/Data Store Read2'
     *  Lookup_n-D: '<S52>/1-D Lookup Table'
     *  Product: '<S52>/Product'
     *  Sum: '<S52>/Add'
     */
    /* Gateway: Function-Call
       Subsystem/IsCtrl/FieldWeak
     / fieldweak/PsiWeak/Chart */
    /* During: Function-Call
       Subsystem/IsCtrl/FieldWeak
     / fieldweak/PsiWeak/Chart */
    if (Algorithm_FluxWeak_GEAR2_DW.is_active_c3_Algorithm_FluxWeak == 0U) {
      /* Entry: Function-Call
         Subsystem/IsCtrl/FieldWeak
       / fieldweak/PsiWeak/Chart */
      Algorithm_FluxWeak_GEAR2_DW.is_active_c3_Algorithm_FluxWeak = 1U;

      /* Outputs for Function Call SubSystem: '<S52>/Psi_Weak' */

      /* Entry Internal: Function-Call
         Subsystem/IsCtrl/FieldWeak
       / fieldweak/PsiWeak/Chart */
      /* Transition: '<S54>:2' */
      /* Entry 'NV_weak_call': '<S54>:1' */
      /* '<S54>:1:1' NV_weak_call; */
      /* Event: '<S54>:4' */
      Algorithm_FluxWeak_GEA_Psi_Weak(rtb_cur_uvw_pu_idx_1 * (PMSM_Param.FW1_ref
        - intrp1d_fu32fla_pw(bpIdx, rtb_Iq_Table,
        Algorithm_FluxWeak_GEAR2_ConstP.uDLookupTable_tableData, 199UL)),
        App_Output.ctrl.AlgoT, rtb_cur_uvw_pu_idx_1, &Saturation1,
        &Algorithm_FluxWeak_GEAR2_DW.Psi_Weak);

      /* End of Outputs for SubSystem: '<S52>/Psi_Weak' */

      /* Outputs for Function Call SubSystem: '<S52>/IntLim' */

      /* '<S54>:1:1' IntLim_nv; */
      /* Event: '<S54>:3' */
      Algorithm_FluxWeak_GEAR2_IntLim(Abs, rtb_cur_uvw_pu_idx_1);

      /* End of Outputs for SubSystem: '<S52>/IntLim' */
    } else {
      /* Outputs for Function Call SubSystem: '<S52>/Psi_Weak' */

      /* During 'NV_weak_call': '<S54>:1' */
      /* '<S54>:1:1' NV_weak_call; */
      /* Event: '<S54>:4' */
      Algorithm_FluxWeak_GEA_Psi_Weak(rtb_cur_uvw_pu_idx_1 * (PMSM_Param.FW1_ref
        - intrp1d_fu32fla_pw(bpIdx, rtb_Iq_Table,
        Algorithm_FluxWeak_GEAR2_ConstP.uDLookupTable_tableData, 199UL)),
        App_Output.ctrl.AlgoT, rtb_cur_uvw_pu_idx_1, &Saturation1,
        &Algorithm_FluxWeak_GEAR2_DW.Psi_Weak);

      /* End of Outputs for SubSystem: '<S52>/Psi_Weak' */

      /* Outputs for Function Call SubSystem: '<S52>/IntLim' */

      /* '<S54>:1:1' IntLim_nv; */
      /* Event: '<S54>:3' */
      Algorithm_FluxWeak_GEAR2_IntLim(Abs, rtb_cur_uvw_pu_idx_1);

      /* End of Outputs for SubSystem: '<S52>/IntLim' */
    }

    /* End of Chart: '<S52>/Chart' */

    /* Sum: '<S50>/Add' */
    rtb_Add_p = Saturation1 + rtb_cur_uvw_pu_idx_1;

    /* Switch: '<S32>/Switch' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read2'
     *  Product: '<S50>/Product1'
     */
    if (App_Output.ctrl.IdIqSetEn != 0U) {
      Switch = App_Output.ctrl.IqRefSet;
    } else {
      /* Lookup_n-D: '<S50>/Iq_Table' */
      bpIdx = plook_u32ff_evenca(rtb_Add_p, 0.088F, 0.0126061216F, 49UL,
        &rtb_Iq_Table);
      rtb_MultiportSwitch[0UL] = rtb_Iq_Table;
      bpIndices[0UL] = bpIdx;
      bpIdx = plook_u32ff_evenca(Abs, 0.0F, 71.4285736F, 14UL, &rtb_Iq_Table);
      rtb_MultiportSwitch[1UL] = rtb_Iq_Table;
      bpIndices[1UL] = bpIdx;
      rtb_Iq_Table = intrp2d_fu32fla_pw(bpIndices, rtb_MultiportSwitch,
        Algorithm_FluxWeak_GEAR2_ConstP.Iq_Table_tableData, 50UL,
        Algorithm_FluxWeak_GEAR2_ConstP.pooled16);

      /* DataTypeConversion: '<S50>/Data Type Conversion' */
      Switch = floorf(rtb_Gain4_a);
      if (rtIsNaNF(Switch) || rtIsInfF(Switch)) {
        Switch = 0.0F;
      } else {
        Switch = fmodf(Switch, 65536.0F);
      }

      u = Switch < 0.0F ? -(int16_T)(uint16_T)-Switch : (int16_T)(uint16_T)
        Switch;

      /* End of DataTypeConversion: '<S50>/Data Type Conversion' */

      /* Signum: '<S50>/Sign' */
      if (u < 0) {
        u = -1;
      } else {
        u = (u > 0);
      }

      /* End of Signum: '<S50>/Sign' */
      Switch = rtb_Iq_Table * (real32_T)u;
    }

    /* End of Switch: '<S32>/Switch' */

    /* DataStoreWrite: '<S32>/Data Store Write1' */
    AlgoFun.IqRef = Switch;

    /* Switch: '<S33>/Switch' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read2'
     */
    if (App_Output.ctrl.IdIqSetEn != 0U) {
      Abs = App_Output.ctrl.IdRefSet;
    } else {
      /* Lookup_n-D: '<S50>/Id_Table' */
      bpIdx = plook_u32ff_evenca(rtb_Add_p, 0.088F, 0.0126061216F, 49UL,
        &rtb_Iq_Table);
      rtb_Gain_cy[0UL] = rtb_Iq_Table;
      bpIndices_0[0UL] = bpIdx;
      bpIdx = plook_u32ff_evenca(Abs, 0.0F, 71.4285736F, 14UL, &rtb_Iq_Table);
      rtb_Gain_cy[1UL] = rtb_Iq_Table;
      bpIndices_0[1UL] = bpIdx;
      Abs = intrp2d_fu32fla_pw(bpIndices_0, rtb_Gain_cy,
        Algorithm_FluxWeak_GEAR2_ConstP.Id_Table_tableData, 50UL,
        Algorithm_FluxWeak_GEAR2_ConstP.pooled16);
    }

    /* End of Switch: '<S33>/Switch' */

    /* DataStoreWrite: '<S33>/Data Store Write2' */
    AlgoFun.IdRef = Abs;

    /* Chart: '<S30>/Chart' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read2'
     */
    /* Gateway: Function-Call
       Subsystem/IsCtrl/CurrentLoop1/IdLoop/Chart */
    /* During: Function-Call
       Subsystem/IsCtrl/CurrentLoop1/IdLoop/Chart */
    if (Algorithm_FluxWeak_GEAR2_DW.is_active_c2_Algorithm_FluxWeak == 0U) {
      /* Entry: Function-Call
         Subsystem/IsCtrl/CurrentLoop1/IdLoop/Chart */
      Algorithm_FluxWeak_GEAR2_DW.is_active_c2_Algorithm_FluxWeak = 1U;

      /* Outputs for Function Call SubSystem: '<S30>/Subsystem' */

      /* Entry Internal: Function-Call
         Subsystem/IsCtrl/CurrentLoop1/IdLoop/Chart */
      /* Transition: '<S34>:2' */
      /* Entry 'NV_weak_call': '<S34>:1' */
      /* '<S34>:1:1' PI_call; */
      /* Event: '<S34>:4' */
      Algorithm_FluxWeak_GE_Subsystem(Switch, Add, Abs, App_Output.ctrl.AlgoT,
        rtb_cur_uvw_pu_idx_2, rtb_Svpwm_Ta,
        &Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUd,
        &Algorithm_FluxWeak_GEAR2_DW.Subsystem);

      /* End of Outputs for SubSystem: '<S30>/Subsystem' */

      /* Outputs for Function Call SubSystem: '<S30>/Function-Call Subsystem' */

      /* '<S34>:1:1' IntLim; */
      /* Event: '<S34>:3' */
      Algorithm_FunctionCallSubsystem();

      /* End of Outputs for SubSystem: '<S30>/Function-Call Subsystem' */
    } else {
      /* Outputs for Function Call SubSystem: '<S30>/Subsystem' */

      /* During 'NV_weak_call': '<S34>:1' */
      /* '<S34>:1:1' PI_call; */
      /* Event: '<S34>:4' */
      Algorithm_FluxWeak_GE_Subsystem(Switch, Add, Abs, App_Output.ctrl.AlgoT,
        rtb_cur_uvw_pu_idx_2, rtb_Svpwm_Ta,
        &Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUd,
        &Algorithm_FluxWeak_GEAR2_DW.Subsystem);

      /* End of Outputs for SubSystem: '<S30>/Subsystem' */

      /* Outputs for Function Call SubSystem: '<S30>/Function-Call Subsystem' */

      /* '<S34>:1:1' IntLim; */
      /* Event: '<S34>:3' */
      Algorithm_FunctionCallSubsystem();

      /* End of Outputs for SubSystem: '<S30>/Function-Call Subsystem' */
    }

    /* End of Chart: '<S30>/Chart' */

    /* Chart: '<S31>/Chart' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read2'
     */
    /* Gateway: Function-Call
       Subsystem/IsCtrl/CurrentLoop1/IqLoop/Chart */
    /* During: Function-Call
       Subsystem/IsCtrl/CurrentLoop1/IqLoop/Chart */
    if (Algorithm_FluxWeak_GEAR2_DW.is_active_c1_Algorithm_FluxWeak == 0U) {
      /* Entry: Function-Call
         Subsystem/IsCtrl/CurrentLoop1/IqLoop/Chart */
      Algorithm_FluxWeak_GEAR2_DW.is_active_c1_Algorithm_FluxWeak = 1U;

      /* Outputs for Function Call SubSystem: '<S31>/Subsystem' */

      /* Entry Internal: Function-Call
         Subsystem/IsCtrl/CurrentLoop1/IqLoop/Chart */
      /* Transition: '<S40>:2' */
      /* Entry 'NV_weak_call': '<S40>:1' */
      /* '<S40>:1:1' PI_call; */
      /* Event: '<S40>:4' */
      Algorithm_FluxWeak__Subsystem_o(Add1, Switch, App_Output.ctrl.AlgoT,
        rtb_cur_uvw_pu_idx_2, rtb_Svpwm_Ta, Abs,
        &Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUq,
        &Algorithm_FluxWeak_GEAR2_DW.Subsystem_o);

      /* End of Outputs for SubSystem: '<S31>/Subsystem' */

      /* Outputs for Function Call SubSystem: '<S31>/Function-Call Subsystem' */

      /* '<S40>:1:1' IntLim; */
      /* Event: '<S40>:3' */
      Algorithm_FunctionCallSubsystem();

      /* End of Outputs for SubSystem: '<S31>/Function-Call Subsystem' */
    } else {
      /* Outputs for Function Call SubSystem: '<S31>/Subsystem' */

      /* During 'NV_weak_call': '<S40>:1' */
      /* '<S40>:1:1' PI_call; */
      /* Event: '<S40>:4' */
      Algorithm_FluxWeak__Subsystem_o(Add1, Switch, App_Output.ctrl.AlgoT,
        rtb_cur_uvw_pu_idx_2, rtb_Svpwm_Ta, Abs,
        &Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUq,
        &Algorithm_FluxWeak_GEAR2_DW.Subsystem_o);

      /* End of Outputs for SubSystem: '<S31>/Subsystem' */

      /* Outputs for Function Call SubSystem: '<S31>/Function-Call Subsystem' */

      /* '<S40>:1:1' IntLim; */
      /* Event: '<S40>:3' */
      Algorithm_FunctionCallSubsystem();

      /* End of Outputs for SubSystem: '<S31>/Function-Call Subsystem' */
    }

    /* End of Chart: '<S31>/Chart' */

    /* DataStoreWrite: '<S50>/Data Store Write2' */
    AlgoFun.Psi_whole = rtb_cur_uvw_pu_idx_1;

    /* DataStoreWrite: '<S50>/Data Store Write3' */
    AlgoFun.TorReq = rtb_Gain4_a;

    /* DataStoreWrite: '<S52>/Data Store Write2' */
    AlgoFun.Psi_Weak = Saturation1;

    /* Outputs for Atomic SubSystem: '<S18>/dq--alphabeta' */
    Algorithm_FluxWeak__dqalphabeta
      (Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUd,
       Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUq, rtb_IParkCompTheta,
       &rtb_cur_uvw_pu_idx_2, &rtb_Svpwm_Ta);

    /* End of Outputs for SubSystem: '<S18>/dq--alphabeta' */

    /* Math: '<S3>/Math Function' */
    Algorithm_FluxWeak_GEAR2_DW.Vs = rt_hypotf_snf
      (Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUd,
       Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUq);

    /* Gain: '<S64>/sqrt3' */
    rtb_cur_uvw_pu_idx_2 *= 1.73205078F;

    /* Sum: '<S64>/Add' */
    Switch = rtb_cur_uvw_pu_idx_2 + rtb_Svpwm_Ta;

    /* Sum: '<S64>/Subtract' */
    rtb_cur_uvw_pu_idx_2 = rtb_Svpwm_Ta - rtb_cur_uvw_pu_idx_2;

    /* Gain: '<S64>/Gain' */
    rtb_Gain_cy[0] = 0.5F * Switch;
    rtb_Gain_cy[1] = 0.5F * rtb_cur_uvw_pu_idx_2;

    /* Sum: '<S65>/Add' incorporates:
     *  Constant: '<S69>/Constant'
     *  Constant: '<S70>/Constant'
     *  Constant: '<S71>/Constant'
     *  Gain: '<S65>/Gain'
     *  Gain: '<S65>/Gain1'
     *  RelationalOperator: '<S69>/Compare'
     *  RelationalOperator: '<S70>/Compare'
     *  RelationalOperator: '<S71>/Compare'
     */
    rtb_Add_g = (((uint16_T)(rtb_Gain_cy[0] < 0.0F) << 2U) + (rtb_Svpwm_Ta >
      0.0F)) + ((uint16_T)(rtb_Gain_cy[1] < 0.0F) << 1U);

    /* MultiPortSwitch: '<S66>/Multiport Switch' incorporates:
     *  Gain: '<S66>/Gain'
     */
    switch (rtb_Add_g) {
     case 1:
      rtb_MultiportSwitch[0] = rtb_Gain_cy[1];
      rtb_MultiportSwitch[1] = rtb_Gain_cy[0];
      break;

     case 2:
      rtb_MultiportSwitch[0] = rtb_Gain_cy[0];
      rtb_MultiportSwitch[1] = -rtb_Svpwm_Ta;
      break;

     case 3:
      rtb_MultiportSwitch[0] = -rtb_Gain_cy[1];
      rtb_MultiportSwitch[1] = rtb_Svpwm_Ta;
      break;

     case 4:
      rtb_MultiportSwitch[0] = -rtb_Svpwm_Ta;
      rtb_MultiportSwitch[1] = rtb_Gain_cy[1];
      break;

     case 5:
      rtb_MultiportSwitch[0] = rtb_Svpwm_Ta;
      rtb_MultiportSwitch[1] = -rtb_Gain_cy[0];
      break;

     default:
      rtb_MultiportSwitch[0] = -rtb_Gain_cy[0];
      rtb_MultiportSwitch[1] = -rtb_Gain_cy[1];
      break;
    }

    /* End of MultiPortSwitch: '<S66>/Multiport Switch' */

    /* Sum: '<S66>/Sum of Elements' */
    Switch = rtb_MultiportSwitch[0] + rtb_MultiportSwitch[1];

    /* Chart: '<S72>/Chart' */
    /* Gateway: Function-Call
       Subsystem/IsCtrl/SVPWM/SVPWM/Subsystem2/Overmodulation/Chart */
    /* During: Function-Call
       Subsystem/IsCtrl/SVPWM/SVPWM/Subsystem2/Overmodulation/Chart */
    /* Entry Internal: Function-Call
       Subsystem/IsCtrl/SVPWM/SVPWM/Subsystem2/Overmodulation/Chart */
    /* Transition: '<S73>:6' */
    /* '<S73>:7:1' sf_internal_predicateOutput = ... */
    /* '<S73>:7:1' T1>T2 && T1>=1; */
    if ((rtb_MultiportSwitch[0] > rtb_MultiportSwitch[1]) &&
        (rtb_MultiportSwitch[0] >= 1.0F)) {
      /* Transition: '<S73>:7' */
      /* Transition: '<S73>:9' */
      /* '<S73>:9:1' T1out=1; */
      rtb_Svpwm_Ta = 1.0F;

      /* '<S73>:9:1' T2out=0; */
      rtb_cur_uvw_pu_idx_2 = 0.0F;

      /* Transition: '<S73>:14' */
      /* Transition: '<S73>:13' */
    } else {
      /* Transition: '<S73>:8' */
      /* '<S73>:10:1' sf_internal_predicateOutput = ... */
      /* '<S73>:10:1' T1<=T2 && T2>=1; */
      if ((rtb_MultiportSwitch[0] <= rtb_MultiportSwitch[1]) &&
          (rtb_MultiportSwitch[1] >= 1.0F)) {
        /* Transition: '<S73>:10' */
        /* Transition: '<S73>:12' */
        /* '<S73>:12:1' T1out=0; */
        rtb_Svpwm_Ta = 0.0F;

        /* '<S73>:12:1' T2out=1; */
        rtb_cur_uvw_pu_idx_2 = 1.0F;

        /* Transition: '<S73>:13' */
      } else {
        /* Saturate: '<S66>/Saturation' incorporates:
         *  Sum: '<S66>/Sum of Elements'
         */
        /* Transition: '<S73>:11' */
        /* '<S73>:11:1' T1out=T1/SUM; */
        if (Switch > 10000.0F) {
          rtb_Svpwm_Ta = 10000.0F;
        } else if (Switch < 0.1F) {
          rtb_Svpwm_Ta = 0.1F;
        } else {
          rtb_Svpwm_Ta = Switch;
        }

        /* End of Saturate: '<S66>/Saturation' */
        rtb_Svpwm_Ta = rtb_MultiportSwitch[0] / rtb_Svpwm_Ta;

        /* '<S73>:11:1' T2out=1-T1out; */
        rtb_cur_uvw_pu_idx_2 = 1.0F - rtb_Svpwm_Ta;
      }
    }

    /* End of Chart: '<S72>/Chart' */

    /* Switch: '<S66>/Switch' incorporates:
     *  Sum: '<S66>/Sum of Elements'
     */
    /* Transition: '<S73>:15' */
    if (Switch > 1.0F) {
      rtb_Gain_cy[0] = rtb_Svpwm_Ta;
      rtb_Gain_cy[1] = rtb_cur_uvw_pu_idx_2;
    } else {
      rtb_Gain_cy[0] = rtb_MultiportSwitch[0];
      rtb_Gain_cy[1] = rtb_MultiportSwitch[1];
    }

    /* End of Switch: '<S66>/Switch' */

    /* Sum: '<S66>/Sum of Elements1' incorporates:
     *  Sum: '<S67>/Sum of Elements2'
     */
    rtb_Svpwm_Ta = rtb_Gain_cy[0] + rtb_Gain_cy[1];

    /* Gain: '<S66>/Gain2' incorporates:
     *  Constant: '<S66>/Constant1'
     *  Sum: '<S66>/Subtract1'
     *  Sum: '<S66>/Sum of Elements1'
     */
    rtb_cur_uvw_pu_idx_2 = (1.0F - rtb_Svpwm_Ta) * 0.5F;

    /* MultiPortSwitch: '<S67>/Multiport Switch' incorporates:
     *  Sum: '<S67>/Sum of Elements1'
     *  Sum: '<S67>/Sum of Elements2'
     */
    switch (rtb_Add_g) {
     case 1:
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[0] = rtb_Gain_cy[1] +
        rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[1] = (rtb_Gain_cy[0] + rtb_Gain_cy[1])
        + rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[2] = rtb_cur_uvw_pu_idx_2;
      break;

     case 2:
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[0] = (rtb_Gain_cy[0] + rtb_Gain_cy[1])
        + rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[1] = rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[2] = rtb_Gain_cy[1] +
        rtb_cur_uvw_pu_idx_2;
      break;

     case 3:
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[0] = (rtb_Gain_cy[0] + rtb_Gain_cy[1])
        + rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[1] = rtb_Gain_cy[1] +
        rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[2] = rtb_cur_uvw_pu_idx_2;
      break;

     case 4:
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[0] = rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[1] = rtb_Gain_cy[1] +
        rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[2] = (rtb_Gain_cy[0] + rtb_Gain_cy[1])
        + rtb_cur_uvw_pu_idx_2;
      break;

     case 5:
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[0] = rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[1] = (rtb_Gain_cy[0] + rtb_Gain_cy[1])
        + rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[2] = rtb_Gain_cy[1] +
        rtb_cur_uvw_pu_idx_2;
      break;

     default:
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[0] = rtb_Gain_cy[1] +
        rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[1] = rtb_cur_uvw_pu_idx_2;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[2] = rtb_Svpwm_Ta +
        rtb_cur_uvw_pu_idx_2;
      break;
    }

    /* End of MultiPortSwitch: '<S67>/Multiport Switch' */

    /* Sum: '<S63>/Subtract1' incorporates:
     *  Constant: '<S63>/Constant11'
     */
    Algorithm_FluxWeak_GEAR2_DW.Subtract1[0] = 1.0F -
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[0];
    Algorithm_FluxWeak_GEAR2_DW.Subtract1[1] = 1.0F -
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[1];
    Algorithm_FluxWeak_GEAR2_DW.Subtract1[2] = 1.0F -
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[2];

    /* Update for UnitDelay: '<S3>/Unit Delay' */
    Algorithm_FluxWeak_GEAR2_DW.UnitDelay_DSTATE =
      Algorithm_FluxWeak_GEAR2_DW.Vs;
  } else {
    if (Algorithm_FluxWeak_GEAR2_DW.IsCtrl_MODE) {
      /* Disable for Chart: '<S52>/Chart' incorporates:
       *  SubSystem: '<S52>/Psi_Weak'
       */
      Algorithm_Flux_Psi_Weak_Disable(&Saturation1);

      /* Disable for Outport: '<S3>/Tcom' */
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[0] = 1.0F;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[1] = 1.0F;
      Algorithm_FluxWeak_GEAR2_DW.Subtract1[2] = 1.0F;

      /* Disable for Outport: '<S3>/Ud' */
      Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUd = 0.0F;

      /* Disable for Outport: '<S3>/Uq' */
      Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUq = 0.0F;

      /* Disable for Outport: '<S3>/Us' */
      Algorithm_FluxWeak_GEAR2_DW.Vs = 0.0F;
      Algorithm_FluxWeak_GEAR2_DW.IsCtrl_MODE = false;
    }
  }

  /* End of RelationalOperator: '<S83>/Compare' */
  /* End of Outputs for SubSystem: '<S1>/IsCtrl' */

  /* Switch: '<S103>/Switch' incorporates:
   *  Constant: '<S103>/SwapPhase'
   */
  if (PMSM_Param.VWDirChg != 0U) {
    rtb_cur_uvw_pu_idx_1 = Algorithm_FluxWeak_GEAR2_DW.Subtract1[2];
    rtb_cur_uvw_pu_idx_2 = Algorithm_FluxWeak_GEAR2_DW.Subtract1[1];
  } else {
    rtb_cur_uvw_pu_idx_1 = Algorithm_FluxWeak_GEAR2_DW.Subtract1[1];
    rtb_cur_uvw_pu_idx_2 = Algorithm_FluxWeak_GEAR2_DW.Subtract1[2];
  }

  /* MultiPortSwitch: '<S7>/Multiport Switch1' incorporates:
   *  Constant: '<S102>/Constant'
   *  Constant: '<S102>/Constant1'
   *  Constant: '<S102>/Constant2'
   *  Constant: '<S102>/Constant4'
   *  Constant: '<S103>/Constant4'
   *  Constant: '<S98>/Constant'
   *  Constant: '<S98>/Constant1'
   *  Constant: '<S98>/Constant2'
   *  Constant: '<S98>/Constant4'
   *  Switch: '<S103>/Switch'
   */
  switch (Algorithm_FluxWeak_GEAR2_DW.AlgoState) {
   case 0:
    rtb_Svpwm_Ta = 0.5F;
    break;

   case 1:
    rtb_Svpwm_Ta = Algorithm_FluxWeak_GEAR2_DW.Subtract1[0];
    break;

   case 2:
    rtb_Svpwm_Ta = 0.5F;
    break;

   default:
    rtb_Svpwm_Ta = 1.0F;
    break;
  }

  switch (Algorithm_FluxWeak_GEAR2_DW.AlgoState) {
   case 0:
    rtb_cur_uvw_pu_idx_1 = 0.5F;
    break;

   case 1:
    break;

   case 2:
    rtb_cur_uvw_pu_idx_1 = 0.5F;
    break;

   default:
    rtb_cur_uvw_pu_idx_1 = 1.0F;
    break;
  }

  switch (Algorithm_FluxWeak_GEAR2_DW.AlgoState) {
   case 0:
    rtb_cur_uvw_pu_idx_2 = 0.5F;
    break;

   case 1:
    break;

   case 2:
    rtb_cur_uvw_pu_idx_2 = 0.5F;
    break;

   default:
    rtb_cur_uvw_pu_idx_2 = 1.0F;
    break;
  }

  switch (Algorithm_FluxWeak_GEAR2_DW.AlgoState) {
   case 0:
    rtb_Add_g = 0U;
    break;

   case 1:
    rtb_Add_g = 1U;
    break;

   case 2:
    rtb_Add_g = 0U;
    break;

   default:
    rtb_Add_g = 2U;
    break;
  }

  /* End of MultiPortSwitch: '<S7>/Multiport Switch1' */

  /* DataStoreWrite: '<S1>/Data Store Write2' incorporates:
   *  BusCreator: '<S7>/BusConversion_InsertedFor_Bus Creator2_at_inport_0'
   *  BusCreator: '<S7>/BusConversion_InsertedFor_Bus Creator2_at_inport_1'
   *  BusCreator: '<S7>/BusConversion_InsertedFor_Bus Creator2_at_inport_2'
   */
  Algo_Output.IGBT_ctrl.Svpwm_Ta = rtb_Svpwm_Ta;
  Algo_Output.IGBT_ctrl.Svpwm_Tb = rtb_cur_uvw_pu_idx_1;
  Algo_Output.IGBT_ctrl.Svpwm_Tc = rtb_cur_uvw_pu_idx_2;
  Algo_Output.IGBT_ctrl.PwmWorkMode = rtb_Add_g;
  Algo_Output.Cur_loop.Id = Add;
  Algo_Output.Cur_loop.Iq = Add1;
  Algo_Output.Cur_loop.Ud = Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUd;
  Algo_Output.Cur_loop.Uq = Algorithm_FluxWeak_GEAR2_DW.OutportBufferForUq;
  Algo_Output.Cur_loop.Vs = Algorithm_FluxWeak_GEAR2_DW.Vs;
  Algo_Output.Fault.IGBT = (uint32_T)rtb_IGBT;
  Algo_Output.Fault.OC1 = Algorithm_FluxWeak_GEAR2_DW.OC1_fault;
  Algo_Output.Fault.OC2 = Algorithm_FluxWeak_GEAR2_DW.OC2_fault;
  Algo_Output.Fault.OV3 = Algorithm_FluxWeak_GEAR2_DW.OV3_fault;
  Algo_Output.Fault.LV3 = Algorithm_FluxWeak_GEAR2_DW.LV3_fault;
  Algo_Output.Fault.PosSen = (uint32_T)rtb_PosSen;

  /* DataStoreWrite: '<S74>/Data Store Write1' */
  AlgoFun.Angle_park = rtb_ParkCompTheta;

  /* DataStoreWrite: '<S74>/Data Store Write2' */
  AlgoFun.Angle_Ipark = rtb_IParkCompTheta;

  /* DataStoreWrite: '<S86>/Data Store Write1' */
  AlgoFun.ThetaRawE = rtb_Subtract;

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_AgoCall_at_outport_1' */
}

/* Model initialize function */
void Algorithm_FluxWeak_GEAR2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Algorithm_FluxWeak_GEAR2_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Algorithm_FluxWeak_GEAR2_DW, 0,
                sizeof(DW_Algorithm_FluxWeak_GEAR2_T));

  /* exported global states */
  AlgoFun = Algorithm_FluxWeak_GEAR2_rtZAlgoFun_inspect_bus;

  {
    real32_T Saturation1;

    /* Start for DataStoreMemory: '<Root>/App_Output' */
    App_Output = Algorithm_FluxWeak_GEAR2_ConstP.App_Output_InitialValue;

    /* SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_AgoCall_at_outport_1' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    /* SystemInitialize for Chart: '<S9>/OverCur2' */
    Algorithm_FluxWeak_GEAR2_DW.OC2_num = 0U;
    Algorithm_FluxWeak_GEAR2_DW.OC2_fault = 0UL;

    /* SystemInitialize for Chart: '<S9>/OverVolt3' */
    Algorithm_FluxWeak_GEAR2_DW.OV3_fault = 0UL;

    /* SystemInitialize for Chart: '<S5>/Chart' */
    Algorithm_FluxWeak_GEAR2_DW.AlgoState = 0;

    /* SystemInitialize for Chart: '<S9>/OverCur1' */
    Algorithm_FluxWeak_GEAR2_DW.OC1_num = 0U;
    Algorithm_FluxWeak_GEAR2_DW.OC1_fault = 0UL;

    /* SystemInitialize for Chart: '<S9>/LowVolt3' */
    Algorithm_FluxWeak_GEAR2_DW.LV3_fault = 0UL;

    /* SystemInitialize for Chart: '<S10>/Chart' */
    Algorithm_FluxWeak_GEAR2_DW.Coef = 1.0F;

    /* SystemInitialize for Enabled SubSystem: '<S1>/IsCtrl' */
    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    Algorithm_FluxWeak_GEAR2_DW.UnitDelay_DSTATE = 0.0F;

    /* SystemInitialize for Atomic SubSystem: '<S50>/lpf1' */
    LPF_Algo_Init(&Algorithm_FluxWeak_GEAR2_DW.lpf1);

    /* End of SystemInitialize for SubSystem: '<S50>/lpf1' */
    Algorithm_FluxWeak_GEAR2_DW.is_active_c3_Algorithm_FluxWeak = 0U;

    /* SystemInitialize for Chart: '<S52>/Chart' incorporates:
     *  SubSystem: '<S52>/Psi_Weak'
     */
    Algorithm_FluxWea_Psi_Weak_Init(&Saturation1);

    /* SystemInitialize for Chart: '<S30>/Chart' */
    Algorithm_FluxWeak_GEAR2_DW.is_active_c2_Algorithm_FluxWeak = 0U;

    /* SystemInitialize for Chart: '<S31>/Chart' */
    Algorithm_FluxWeak_GEAR2_DW.is_active_c1_Algorithm_FluxWeak = 0U;

    /* SystemInitialize for Outport: '<S3>/Tcom' */
    Algorithm_FluxWeak_GEAR2_DW.Subtract1[0] = 1.0F;
    Algorithm_FluxWeak_GEAR2_DW.Subtract1[1] = 1.0F;
    Algorithm_FluxWeak_GEAR2_DW.Subtract1[2] = 1.0F;

    /* End of SystemInitialize for SubSystem: '<S1>/IsCtrl' */
    /* End of SystemInitialize for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_AgoCall_at_outport_1' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
