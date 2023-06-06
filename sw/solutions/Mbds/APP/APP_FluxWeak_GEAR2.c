/*
 * File: APP_FluxWeak_GEAR2.c
 *
 * Code generated for Simulink model 'APP_FluxWeak_GEAR2'.
 *
 * Model version                  : 2.02
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Mar 14 15:14:39 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "APP_FluxWeak_GEAR2.h"
#include "APP_FluxWeak_GEAR2_private.h"
//#include "intrp1d_fu32fla_pw.h"
//#include "plook_u32ff_evenca.h"
//#include "rt_hypotf_snf.h"
#define APP_FluxWeak_GEAR2_IN_Add      (1U)
#define APP_FluxWeak_GEAR2_IN_D        (1U)
#define APP_FluxWeak_GEAR2_IN_N        (2U)
#define APP_FluxWeak_GEAR2_IN_R        (2U)
#define APP_FluxWeak_GEAR2_IN_R_e      (3U)
#define APP_FluxWeak_GEAR2_IN_Sub      (2U)
#define APP_FluxWeak_GEAR2_IN_move     (1U)
#define APP_FluxWeak_GEAR2_IN_slope    (2U)
#define APP_FluxWeak_IN_NO_ACTIVE_CHILD (0U)
#define APP_FluxWe_IN_NO_ACTIVE_CHILD_j (0U)
#define APP_FluxWeak_GEAR2_IN_AddId    (1U)
#define APP_FluxWeak_GEAR2_IN_ChgAngle1 (2U)
#define APP_FluxWeak_GEAR2_IN_DecId    (3U)
#define APP_FluxWeak_GEAR2_IN_Fault    (1U)
#define APP_FluxWeak_GEAR2_IN_Fin1     (2U)
#define APP_FluxWeak_GEAR2_IN_Init     (3U)
#define APP_FluxWeak_GEAR2_IN_Study    (4U)
#define APP_FluxWeak_GEAR2_IN_Wait1    (4U)
#define APP_FluxWeak_GEAR2_IN_Wait3    (5U)
#define APP_FluxWe_IN_NO_ACTIVE_CHILD_k (0U)
#define APP_FluxWeak_GEAR2_IN_AddId1   (1U)
#define APP_FluxWeak_GEAR2_IN_Init_a   (1U)
#define APP_FluxWeak_GEAR2_IN_Stop     (2U)
#define APP_FluxWeak_GEAR2_IN_Study_m  (3U)
#define APP_FluxWeak_GEAR2_IN_Wait1_e  (2U)
#define APP_FluxWe_IN_NO_ACTIVE_CHILD_o (0U)
#define APP_FluxWeak_GEAR2_IN_AddId_c  (1U)
#define APP_FluxWeak_GEAR2_IN_AddIq    (2U)
#define APP_FluxWeak_GEAR2_IN_ClrIq    (3U)
#define APP_FluxWeak_GEAR2_IN_DecId_l  (4U)
#define APP_FluxWeak_GEAR2_IN_Fault_i  (5U)
#define APP_FluxWeak_GEAR2_IN_Fin      (1U)
#define APP_FluxWeak_GEAR2_IN_Fin1_c   (2U)
#define APP_FluxWeak_GEAR2_IN_Init_d   (1U)
#define APP_FluxWeak_GEAR2_IN_Init_du  (6U)
#define APP_FluxWeak_GEAR2_IN_SPEEDFORW (3U)
#define APP_FluxWeak_GEAR2_IN_SPEEDINV (4U)
#define APP_FluxWeak_GEAR2_IN_Study_e  (2U)
#define APP_FluxWeak_GEAR2_IN_Wait1_b  (7U)
#define APP_FluxWeak_GEAR2_IN_Wait2    (8U)
#define APP_FluxWeak_GEAR_IN_ZeroPoint0 (5U)
#define APP_FluxWeak_GEAR_IN_ZeroPoint1 (6U)
#define APP_FluxWe_IN_NO_ACTIVE_CHILD_l (0U)
#define APP_FluxWeak_GEAR2_IN_Stop_l   (1U)
#define APP_FluxWeak_GEAR2_IN_stop     (1U)
#define APP_FluxWeak_GEAR2_IN_wait     (2U)
#define APP_FluxWeak_GEAR2_IN_work     (3U)
#define APP_FluxWeak_G_IN_DecreaseValue (1U)
#define APP_FluxWeak_G_IN_increaseValue (2U)
#define APP_FluxWe_IN_NO_ACTIVE_CHILD_i (0U)
#define APP_FluxWeak_GEAR2_IN_Mtpa     (2U)
#define APP_FluxWeak_GEAR2_IN_Prepare  (3U)
#define APP_FluxWeak_GEAR2_IN_Qaxis    (4U)
#define APP_FluxWeak_GEAR_IN_FirstPoint (2U)
#define APP_FluxWeak_GEAR_IN_IsDecrease (1U)
#define APP_FluxWeak_GEAR_IN_IsIncrease (3U)
#define APP_FluxWeak_G_IN_AngleIncrease (1U)
#define APP_FluxW_IN_NO_ACTIVE_CHILD_km (0U)
#define APP_FluxWeak_GEAR2_IN_IfStudy  (2U)
#define APP_FluxWeak_GEAR2_IN_LdStudy  (4U)
#define APP_FluxWeak_GEAR2_IN_MtpaStudy (5U)
#define APP_FluxWeak_GEAR2_IN_Normal   (6U)
#define APP_FluxWeak_GEAR_IN_PhaseStudy (7U)
#define APP_FluxWeak_G_IN_ElecZeroStudy (1U)
#define APP_FluxWeak_IN_IsMax_TLinStudy (3U)
#define APP_FluxW_IN_NO_ACTIVE_CHILD_oa (0U)
#define APP_FluxWeak_GEAR2_IN_check    (1U)
#define APP_FluxWeak_GEAR2_IN_fin      (2U)
#define APP_FluxWeak_GEAR2_IN_hold     (3U)
#define APP_FluxWeak_GEAR2_IN_quitcheck (4U)
#define APP_FluxWeak_GEAR2_IN_start    (5U)
#define APP_FluxWe_IN_NO_ACTIVE_CHILD_c (0U)
#define APP_FluxWeak_GEAR2_IN_ASC      (1U)
#define APP_FluxWeak_GEAR2_IN_ConfirmHV (1U)
#define APP_FluxWeak_GEAR2_IN_Dischg   (2U)
#define APP_FluxWeak_GEAR2_IN_Genrate  (1U)
#define APP_FluxWeak_GEAR2_IN_NegSpd   (1U)
#define APP_FluxWeak_GEAR2_IN_NoPower  (2U)
#define APP_FluxWeak_GEAR2_IN_PosSpd   (2U)
#define APP_FluxWeak_GEAR2_IN_Prepare_c (1U)
#define APP_FluxWeak_GEAR2_IN_Slope    (2U)
#define APP_FluxWeak_GEAR2_IN_Spd      (3U)
#define APP_FluxWeak_GEAR2_IN_Speed    (1U)
#define APP_FluxWeak_GEAR2_IN_Starter  (4U)
#define APP_FluxWeak_GEAR2_IN_Sync     (5U)
#define APP_FluxWeak_GEAR2_IN_Torque   (2U)
#define APP_FluxWeak_GEAR2_IN_UVWcheck (1U)
#define APP_FluxWeak_GEAR2_IN_Work     (2U)
#define APP_FluxWeak_GEAR2_IN_ZeroBias (3U)
#define APP_FluxWeak_GEAR2_IN_ZreoSpd  (3U)
#define APP_FluxWeak_GEAR2_IN_appoint  (3U)
#define APP_FluxWeak_GEAR2_IN_standard (3U)
#define APP_FluxWeak_GEAR2_IN_sys_mode (2U)
#define APP_FluxWeak_GEAR2_IN_wait_c   (4U)
#define APP_FluxWeak_G_IN_WaitForDischg (3U)

const PMSM_Input_bus APP_FluxWeak_GEAR2_rtZPMSM_Input_bus = {
  {
    0.0F,                              /* MotTemp1 */
    0.0F,                              /* MotTemp2 */
    0.0F,                              /* InvTemp1 */
    0.0F,                              /* InvTemp2 */
    0.0F,                              /* InvTemp3 */
    0.0F,                              /* VoltCap */
    0.0F,                              /* VoltCap_compensate */
    0U,                                /* AnaInput1AD */
    0U,                                /* AnaInput2AD */
    0U,                                /* AnaInput3AD */
    0U,                                /* KsiSt */
    0U,                                /* BrkSt */
    0U,                                /* DrvMode */
    0U,                                /* Sw1InputSt */
    0U,                                /* Sw2InputSt */
    0U,                                /* Sw3InputSt */
    0U,                                /* ReadyFin */
    0.0F,                              /* ExtTorque */
    0U,                                /* ElecZeroStep */
    0.0F,                              /* CalibMTPATheta */
    0U                                 /* CalibStep */
  },                                   /* AppSample */

  {
    0.0F,                              /* TqReq */
    0.0F,                              /* SpdReq */
    0.0F,                              /* TqUpperLim */
    0.0F,                              /* TqLowerLim */
    0.0F,                              /* SpdUpperLim */
    0.0F,                              /* SpdLowerLim */
    0.0F,                              /* DrvLimCur */
    0.0F,                              /* GenLimCur */
    0U,                                /* GateReq */
    0U,                                /* MainRelayState */
    0U,                                /* GearState */
    0U,                                /* ModeReq */
    0U,                                /* CanMsg1Lost */
    0U                                 /* CanMsg2Lost */
  },                                   /* AppComm */

  {
    0.0F,                              /* Speed */
    0.0F,                              /* ThetaRT */
    0.0F,                              /* CurUPu */
    0.0F,                              /* CurVPu */
    0.0F,                              /* CurWPu */
    0.0F,                              /* CurBus */
    0.0F,                              /* VoltU */
    0.0F,                              /* VoltV */
    0.0F,                              /* VoltW */
    0U,                                /* PosSenFaultState1 */
    0U,                                /* PosSenFaultState2 */
    0U,                                /* IGBT1FaultState */
    0U,                                /* IGBT2FaultState */
    0U                                 /* IGBT3FaultState */
  }                                    /* AgoSample */
} ;                                    /* PMSM_Input_bus ground */

const Algo_Output_bus APP_FluxWeak_GEAR2_rtZAlgo_Output_bus = {
  {
    0.0F,                              /* Svpwm_Ta */
    0.0F,                              /* Svpwm_Tb */
    0.0F,                              /* Svpwm_Tc */
    0U                                 /* PwmWorkMode */
  },                                   /* IGBT_ctrl */

  {
    0.0F,                              /* Id */
    0.0F,                              /* Iq */
    0.0F,                              /* Ud */
    0.0F,                              /* Uq */
    0.0F                               /* Vs */
  },                                   /* Cur_loop */

  {
    0U,                                /* IGBT */
    0U,                                /* OC1 */
    0U,                                /* OC2 */
    0U,                                /* OV3 */
    0U,                                /* LV3 */
    0U                                 /* PosSen */
  }                                    /* Fault */
} ;                                    /* Algo_Output_bus ground */

const App_Output_bus APP_FluxWeak_GEAR2_rtZApp_Output_bus = {
  {
    0.0F,                              /* NmFil */
    0.0F,                              /* VoltCapFil */
    0.0F,                              /* CurBusFil */
    0.0F,                              /* MotTemp */
    0.0F,                              /* InvTemp */
    0U                                 /* tick */
  },                                   /* data_process */

  {
    0.0F,                              /* TqMax */
    0.0F,                              /* TqReal */
    0.0F                               /* ZeroPointBias */
  },                                   /* table */

  {
    0.0F,                              /* LimtCoef */
    0U,                                /* PwmWorkMode */
    0U                                 /* FaultCode1 */
  },                                   /* fault */

  {
    0U,                                /* RunSt */
    0U                                 /* ModeSt */
  },                                   /* state */

  {
    0U,                                /* KeepPowerEn */
    0U,                                /* DRV1_En */
    0U                                 /* DRV2_En */
  },                                   /* power */

  {
    0U,                                /* AscEn */
    0.0F,                              /* IdRefSet */
    0.0F,                              /* IqRefSet */
    0.0F,                              /* AngleRefSet */
    0U,                                /* IdIqSetEn */
    0U,                                /* AngleSetEn */
    0.0F,                              /* CalibZeroPoint */
    0.0F,                              /* TqReq */
    0.0F,                              /* PwmFreq */
    0.0F,                              /* PwmT */
    0.0F                               /* AlgoT */
  }                                    /* ctrl */
} ;                                    /* App_Output_bus ground */

const AppFun_inspect_bus APP_FluxWeak_GEAR2_rtZAppFun_inspect_bus = {
  0.0F,                                /* LimTP_I */
  0.0F,                                /* LimTN_I */
  0.0F,                                /* LimTP_T */
  0.0F,                                /* LimTN_T */
  0.0F,                                /* LimTP_Spd */
  0.0F,                                /* LimTN_Spd */
  0.0F,                                /* StudyResult */
  0.0F,                                /* SpdReq */
  0.0F,                                /* FaultLimTP */
  0.0F,                                /* FaultLimTN */
  0.0F,                                /* FaultCoef */
  0.0F,                                /* Us */
  0U,                                  /* StudyStep */
  0.0F                                 /* Tqreq */
} ;                                    /* AppFun_inspect_bus ground */

/* Exported block states */
PMSM_Input_bus PMSM_Input;             /* Simulink.Signal object 'PMSM_Input' */
App_Output_bus App_Output;             /* Simulink.Signal object 'App_Output' */
Algo_Output_bus Algo_Output;           /* Simulink.Signal object 'Algo_Output' */
AppFun_inspect_bus AppFun;             /* Simulink.Signal object 'AppFun' */

/* Block signals and states (auto storage) */
DW_APP_FluxWeak_GEAR2_T APP_FluxWeak_GEAR2_DW;

/* Real-time model */
RT_MODEL_APP_FluxWeak_GEAR2_T APP_FluxWeak_GEAR2_M_;
RT_MODEL_APP_FluxWeak_GEAR2_T *const APP_FluxWeak_GEAR2_M =
  &APP_FluxWeak_GEAR2_M_;

/* Forward declaration for local functions */
static real32_T APP_FluxWeak_GEAR2_Turn(real32_T x);
static void APP_Fl_enter_internal_SPEEDFORW(real32_T rtu_Data_n,
  DW_ElecZeroStudy_APP_FluxWeak_T *localDW);
static void APP_Flu_enter_internal_SPEEDINV(real32_T rtu_Data_n,
  DW_ElecZeroStudy_APP_FluxWeak_T *localDW);
static void APP_FluxWeak_GEAR2_Study(real32_T rtu_Data_n, real32_T rtu_Data_j,
  real32_T rtu_Data_o, DW_ElecZeroStudy_APP_FluxWeak_T *localDW);

/* Forward declaration for local functions */
static void APP_Flux_exit_internal_sys_mode(const real32_T
  *DiscreteTimeIntegrator1, const real32_T *DiscreteTimeIntegrator1_i);

/*
 * System initialize for atomic system:
 *    '<S48>/lpf'
 *    '<S49>/lpf'
 *    '<S132>/lpf'
 *    '<S117>/lpf'
 *    '<S116>/lpf'
 *    '<S135>/lpf'
 *    '<S136>/lpf'
 *    '<S137>/lpf'
 *    '<S179>/lpf'
 *    '<S182>/lpf'
 *    ...
 */
void LPF_App_Init(DW_LPF_App_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S50>/Discrete-Time Integrator1' */
  localDW->LPF_STATE = 0.0F;
}

/*
 * System reset for atomic system:
 *    '<S48>/lpf'
 *    '<S49>/lpf'
 *    '<S132>/lpf'
 *    '<S117>/lpf'
 *    '<S116>/lpf'
 *    '<S135>/lpf'
 *    '<S136>/lpf'
 *    '<S137>/lpf'
 *    '<S179>/lpf'
 *    '<S182>/lpf'
 *    ...
 */
void LPF_App_Reset(DW_LPF_App_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S50>/Discrete-Time Integrator1' */
  localDW->LPF_STATE = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S48>/lpf'
 *    '<S49>/lpf'
 *    '<S132>/lpf'
 *    '<S117>/lpf'
 *    '<S116>/lpf'
 *    '<S135>/lpf'
 *    '<S136>/lpf'
 *    '<S137>/lpf'
 *    '<S179>/lpf'
 *    '<S182>/lpf'
 *    ...
 */
void LPF_App(real32_T rtu_u, real32_T rtu_Ts, real32_T rtu_N, real32_T *rty_Out1,
             DW_LPF_App_T *localDW)
{
  /* DiscreteIntegrator: '<S50>/Discrete-Time Integrator1' */
  *rty_Out1 = localDW->LPF_STATE;

  /* Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator1' incorporates:
   *  Product: '<S50>/Product'
   *  Product: '<S50>/Product1'
   *  Sum: '<S50>/Sum'
   */
  localDW->LPF_STATE += (rtu_u - *rty_Out1) * rtu_N * rtu_Ts;
}

/* Output and update for Simulink Function: '<S15>/Simulink Function' */
void APP_FluxWeak_GEAR2_Lim_coef(real32_T rtu_u, real32_T rtu_up_p, real32_T
  rtu_down_p, real32_T *rty_coef)
{
  real32_T rtb_uk;

  /* Sum: '<S26>/Subtract' incorporates:
   *  SignalConversion: '<S26>/TmpSignal ConversionAtdown_pOutport1'
   *  SignalConversion: '<S26>/TmpSignal ConversionAtup_pOutport1'
   */
  rtb_uk = rtu_up_p - rtu_down_p;

  /* Sum: '<S26>/Add' incorporates:
   *  Gain: '<S26>/Gain'
   *  Product: '<S26>/Divide'
   *  Product: '<S26>/Divide1'
   *  SignalConversion: '<S26>/TmpSignal ConversionAtdown_pOutport1'
   *  SignalConversion: '<S26>/TmpSignal ConversionAtuOutport1'
   */
  rtb_uk = rtu_u / rtb_uk + rtu_down_p / -rtb_uk;

  /* Saturate: '<S26>/Saturation' */
  if (rtb_uk > 1.0F) {
    /* SignalConversion: '<S26>/TmpSignal ConversionAtcoefInport1' */
    *rty_coef = 1.0F;
  } else if (rtb_uk < 0.0F) {
    /* SignalConversion: '<S26>/TmpSignal ConversionAtcoefInport1' */
    *rty_coef = 0.0F;
  } else {
    /* SignalConversion: '<S26>/TmpSignal ConversionAtcoefInport1' */
    *rty_coef = rtb_uk;
  }

  /* End of Saturate: '<S26>/Saturation' */
}

/* Output and update for function-call system: '<S54>/Initial' */
void APP_FluxWeak_GEAR2_Initial(void)
{
  /* StateWriter: '<S66>/State Writer' incorporates:
   *  Constant: '<S66>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state = 0.0F;

  /* StateWriter: '<S66>/State Writer1' incorporates:
   *  Constant: '<S66>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Slope.lpf_a.LPF_STATE = 0.0F;

  /* StateWriter: '<S66>/State Writer2' incorporates:
   *  Constant: '<S66>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state = 0.0F;

  /* StateWriter: '<S66>/State Writer3' incorporates:
   *  Constant: '<S66>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Sync.PI.I_state = 0.0F;

  /* StateWriter: '<S66>/State Writer4' incorporates:
   *  Constant: '<S66>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Starter.PI.I_state = 0.0F;

  /* StateWriter: '<S66>/State Writer5' incorporates:
   *  Constant: '<S66>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE = 0.0F;

  /* StateWriter: '<S66>/State Writer6' incorporates:
   *  Constant: '<S66>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Spd_g.Spd_D_Int = 0.0F;

  /* StateWriter: '<S66>/State Writer7' incorporates:
   *  Constant: '<S66>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;
}

/* Output and update for function-call system: '<S54>/Update' */
void APP_FluxWeak_GEAR2_Update(const real32_T *rtu_Ctrl, real32_T rtu_Data,
  real32_T rtu_Data_d)
{
  real32_T rtb_Subtract_g;

  /* Sum: '<S76>/Subtract' */
  rtb_Subtract_g = rtu_Data - rtu_Data_d;

  /* StateWriter: '<S76>/State Writer' incorporates:
   *  Gain: '<S76>/P'
   *  Sum: '<S76>/Subtract1'
   */
  APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state = *rtu_Ctrl - PMSM_Param.GenKp *
    rtb_Subtract_g;

  /* StateWriter: '<S76>/State Writer1' incorporates:
   *  Gain: '<S76>/P1'
   *  Sum: '<S76>/Subtract2'
   */
  APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = *rtu_Ctrl - PMSM_Param.SlopeKp *
    rtb_Subtract_g;

  /* StateWriter: '<S76>/State Writer2' */
  APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state = *rtu_Ctrl;

  /* Sum: '<S76>/Subtract4' incorporates:
   *  Gain: '<S76>/P3'
   *  Sum: '<S76>/Subtract5'
   */
  APP_FluxWeak_GEAR2_DW.Sync.PI.I_state = *rtu_Ctrl - PMSM_Param.SyncKp *
    rtb_Subtract_g;

  /* StateWriter: '<S76>/State Writer4' */
  APP_FluxWeak_GEAR2_DW.Starter.PI.I_state =
    APP_FluxWeak_GEAR2_DW.Sync.PI.I_state;

  /* StateWriter: '<S76>/State Writer5' */
  APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE = *rtu_Ctrl;

  /* StateWriter: '<S76>/State Writer6' */
  APP_FluxWeak_GEAR2_DW.Slope.lpf_a.LPF_STATE = *rtu_Ctrl;
}

/* System initialize for function-call system: '<S54>/Torque' */
void APP_FluxWeak_GEAR2_Torque_Init(DW_Torque_APP_FluxWeak_GEAR2_T *localDW)
{
  /* SystemInitialize for Atomic SubSystem: '<S132>/lpf' */
  LPF_App_Init(&localDW->lpf);

  /* End of SystemInitialize for SubSystem: '<S132>/lpf' */
}

/* Output and update for function-call system: '<S54>/Torque' */
void APP_FluxWeak_GEAR2_Torque(real32_T rtu_data, uint16_T *rty_Out1, real32_T
  *rty_Out1_l, real32_T *rty_Out1_i, real32_T *rty_Out1_g, uint16_T *rty_Out1_c,
  uint16_T *rty_Out1_p, real32_T *rty_Out1_l2, real32_T *rty_Out1_gi, real32_T
  *rty_Tor, DW_Torque_APP_FluxWeak_GEAR2_T *localDW)
{
  real32_T rtb_DiscreteTimeIntegrator1_g;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_l = 0.0F;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = 0.0F;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = 0.0F;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0U;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_p = 0U;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_l2 = 0.0F;

  /* Outputs for Atomic SubSystem: '<S132>/lpf' */

  /* Constant: '<S132>/Constant' incorporates:
   *  Constant: '<S132>/Constant1'
   */
  LPF_App(rtu_data, 0.002F, 10.0F, &rtb_DiscreteTimeIntegrator1_g, &localDW->lpf);

  /* End of Outputs for SubSystem: '<S132>/lpf' */

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_gi = rtb_DiscreteTimeIntegrator1_g;

  /* SignalConversion: '<S74>/OutportBufferForTor' */
  *rty_Tor = rtb_DiscreteTimeIntegrator1_g;
}

/* Output and update for function-call system: '<S54>/Spd' */
void APP_FluxWeak_GEAR2_Spd(real32_T rtu_Data, real32_T rtu_Data_o, uint16_T
  *rty_Out1, real32_T *rty_Out1_o, real32_T *rty_Out1_p, real32_T *rty_Out1_c,
  uint16_T *rty_Out1_h, uint16_T *rty_Out1_ox, real32_T *rty_Out1_m, real32_T
  *rty_Out1_mw, real32_T *rty_Tor, DW_Spd_APP_FluxWeak_GEAR2_T *localDW)
{
  real32_T rtb_Gain_aw;
  real32_T rtb_UnitDelay_b;
  real32_T rtb_Saturation_c;

  /* Gain: '<S127>/Gain' incorporates:
   *  DiscreteIntegrator: '<S127>/Discrete-Time Integrator1'
   *  Sum: '<S127>/Sum'
   */
  rtb_Gain_aw = (0.0F - localDW->Spd_D_Int) * 0.25F;

  /* DataStoreWrite: '<S127>/Data Store Write' */
  AppFun.LimTP_T = rtb_Gain_aw;

  /* DataStoreWrite: '<S127>/Data Store Write1' incorporates:
   *  DiscreteIntegrator: '<S127>/Discrete-Time Integrator'
   */
  AppFun.LimTN_T = localDW->Spd_state;

  /* Gain: '<S71>/Norm' incorporates:
   *  Sum: '<S71>/Subtract1'
   */
  rtb_UnitDelay_b = (rtu_Data - rtu_Data_o) * 0.0001F;

  /* Gain: '<S127>/P' */
  rtb_Saturation_c = PMSM_Param.SpdKp * rtb_UnitDelay_b;

  /* DataStoreWrite: '<S127>/Data Store Write2' */
  AppFun.LimTP_Spd = rtb_Saturation_c;

  /* Switch: '<S127>/Switch' incorporates:
   *  Abs: '<S127>/Abs'
   *  Constant: '<S127>/Constant1'
   */
  if (!(fabsf(rtu_Data) > 10.0F)) {
    rtb_UnitDelay_b = 0.0F;
  }

  /* End of Switch: '<S127>/Switch' */

  /* Sum: '<S127>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S127>/Discrete-Time Integrator'
   */
  rtb_Saturation_c = (rtb_Saturation_c + localDW->Spd_state) + rtb_Gain_aw;

  /* Saturate: '<S127>/Saturation' */
  if (rtb_Saturation_c > 1.0F) {
    rtb_Saturation_c = 1.0F;
  } else {
    if (rtb_Saturation_c < -1.0F) {
      rtb_Saturation_c = -1.0F;
    }
  }

  /* End of Saturate: '<S127>/Saturation' */

  /* SignalConversion: '<S71>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S71>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_o = 0.0F;

  /* SignalConversion: '<S71>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_p = 0.0F;

  /* SignalConversion: '<S71>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0.0F;

  /* SignalConversion: '<S71>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_h = 0U;

  /* SignalConversion: '<S71>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_ox = 0U;

  /* SignalConversion: '<S71>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_m = 0.0F;

  /* SignalConversion: '<S71>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_mw = rtb_Saturation_c;

  /* SignalConversion: '<S71>/OutportBufferForTor' */
  *rty_Tor = rtb_Saturation_c;

  /* Update for DiscreteIntegrator: '<S127>/Discrete-Time Integrator1' */
  localDW->Spd_D_Int += 0.001F * rtb_Gain_aw;

  /* Update for DiscreteIntegrator: '<S127>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S127>/I'
   */
  localDW->Spd_state += PMSM_Param.SpdKi / 1000.0F * rtb_UnitDelay_b;
}

/*
 * Output and update for atomic system:
 *    '<S99>/PI'
 *    '<S128>/PI'
 *    '<S113>/PI'
 *    '<S130>/PI'
 *    '<S152>/PI'
 *    '<S158>/PI'
 */
void PI_App(real32_T rtu_Err, real32_T rtu_Kp, real32_T rtu_KI, real32_T rtu_T,
            real32_T *rty_PIOut, real32_T *rty_I_State, DW_PI_App_T *localDW)
{
  /* DiscreteIntegrator: '<S100>/Discrete-Time Integrator1' */
  *rty_I_State = localDW->I_state;

  /* Sum: '<S100>/Add' incorporates:
   *  Product: '<S100>/Product'
   */
  *rty_PIOut = rtu_Kp * rtu_Err + *rty_I_State;

  /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator1' incorporates:
   *  Product: '<S100>/Product1'
   *  Product: '<S100>/Product2'
   */
  localDW->I_state += rtu_Err * rtu_KI * rtu_T;
}

/* Output and update for function-call system: '<S54>/Genrate' */
void APP_FluxWeak_GEAR2_Genrate(real32_T rtu_Data, real32_T rtu_Data_d, uint16_T
  *rty_Out1, real32_T *rty_Out1_d, real32_T *rty_Out1_n, real32_T *rty_Out1_ni,
  uint16_T *rty_Out1_g, uint16_T *rty_Out1_h, real32_T *rty_Out1_k, real32_T
  *rty_Out1_d4, real32_T *rty_Tor, DW_Genrate_APP_FluxWeak_GEAR2_T *localDW)
{
  real32_T rtb_Add_ct;
  real32_T rtb_DiscreteTimeIntegrator1_j;

  /* SignalConversion: '<S65>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S65>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_d = 0.0F;

  /* SignalConversion: '<S65>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_n = 0.0F;

  /* SignalConversion: '<S65>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_ni = 0.0F;

  /* SignalConversion: '<S65>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = 0U;

  /* SignalConversion: '<S65>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_h = 0U;

  /* SignalConversion: '<S65>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_k = 0.0F;

  /* Outputs for Atomic SubSystem: '<S99>/PI' */

  /* Gain: '<S65>/Norm' incorporates:
   *  Constant: '<S99>/Constant'
   *  Constant: '<S99>/Constant1'
   *  Constant: '<S99>/Constant2'
   *  Sum: '<S65>/Subtract'
   */
  PI_App(0.0001F * (rtu_Data - rtu_Data_d), PMSM_Param.GenKp, PMSM_Param.GenKi,
         0.002F, &rtb_Add_ct, &rtb_DiscreteTimeIntegrator1_j, &localDW->PI);

  /* End of Outputs for SubSystem: '<S99>/PI' */

  /* Saturate: '<S99>/Saturation' */
  if (rtb_Add_ct > 0.0F) {
    rtb_Add_ct = 0.0F;
  } else {
    if (rtb_Add_ct < -1.0F) {
      rtb_Add_ct = -1.0F;
    }
  }

  /* End of Saturate: '<S99>/Saturation' */

  /* SignalConversion: '<S65>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_d4 = rtb_Add_ct;

  /* SignalConversion: '<S65>/OutportBufferForTor' */
  *rty_Tor = rtb_Add_ct;
}

/* Output and update for function-call system: '<S54>/Starter' */
void APP_FluxWeak_GEAR2_Starter(real32_T rtu_Data, real32_T rtu_Data_c, uint16_T
  *rty_Out1, real32_T *rty_Out1_c, real32_T *rty_Out1_b, real32_T *rty_Out1_bt,
  uint16_T *rty_Out1_i, uint16_T *rty_Out1_cm, real32_T *rty_Out1_p, real32_T
  *rty_Out1_e, real32_T *rty_Tor, DW_Starter_APP_FluxWeak_GEAR2_T *localDW)
{
  real32_T rtb_Add_hz;
  real32_T rtb_DiscreteTimeIntegrator1_g;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0.0F;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_b = 0.0F;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_bt = 0.0F;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = 0U;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_cm = 0U;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_p = 0.0F;

  /* Outputs for Atomic SubSystem: '<S128>/PI' */

  /* Gain: '<S72>/Norm' incorporates:
   *  Constant: '<S128>/Constant'
   *  Constant: '<S128>/Constant1'
   *  Constant: '<S128>/Constant2'
   *  Sum: '<S72>/Subtract'
   */
  PI_App(0.0001F * (rtu_Data - rtu_Data_c), PMSM_Param.StarKp, PMSM_Param.StarKi,
         0.002F, &rtb_Add_hz, &rtb_DiscreteTimeIntegrator1_g, &localDW->PI);

  /* End of Outputs for SubSystem: '<S128>/PI' */

  /* Saturate: '<S128>/Saturation' */
  if (rtb_Add_hz > 1.0F) {
    rtb_Add_hz = 1.0F;
  } else {
    if (rtb_Add_hz < 0.0F) {
      rtb_Add_hz = 0.0F;
    }
  }

  /* End of Saturate: '<S128>/Saturation' */

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_e = rtb_Add_hz;

  /* SignalConversion: '<S72>/OutportBufferForTor' */
  *rty_Tor = rtb_Add_hz;
}

/* System initialize for function-call system: '<S110>/Function-Call Subsystem' */
void APP__FunctionCallSubsystem_Init(DW_FunctionCallSubsystem_APP__T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S114>/Discrete-Time Integrator' */
  localDW->Slope_state = 0.0F;
}

/* System reset for function-call system: '<S110>/Function-Call Subsystem' */
void APP_FunctionCallSubsystem_Reset(DW_FunctionCallSubsystem_APP__T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S114>/Discrete-Time Integrator' */
  localDW->Slope_state = 0.0F;
}

/* Disable for function-call system: '<S110>/Function-Call Subsystem' */
void A_FunctionCallSubsystem_Disable(real32_T *rty_SlopeTime)
{
  /* Disable for Outport: '<S114>/SlopeTime' */
  *rty_SlopeTime = 0.0F;
}

/* Output and update for function-call system: '<S110>/Function-Call Subsystem' */
void APP_FluxW_FunctionCallSubsystem(real32_T rtu_SlopeLoopOut, uint16_T
  rtu_Gear, real32_T *rty_SlopeTime, DW_FunctionCallSubsystem_APP__T *localDW)
{
  real32_T rtb_MultiportSwitch_n;

  /* DiscreteIntegrator: '<S114>/Discrete-Time Integrator' */
  *rty_SlopeTime = localDW->Slope_state;

  /* MultiPortSwitch: '<S114>/Multiport Switch' incorporates:
   *  Constant: '<S114>/Constant'
   */
  switch (rtu_Gear) {
   case 0:
    rtb_MultiportSwitch_n = 0.0F;
    break;

   case 1:
    /* DeadZone: '<S114>/Dead Zone' */
    if (rtu_SlopeLoopOut > 0.3F) {
      rtb_MultiportSwitch_n = rtu_SlopeLoopOut - 0.3F;
    } else if (rtu_SlopeLoopOut >= -0.3F) {
      rtb_MultiportSwitch_n = 0.0F;
    } else {
      rtb_MultiportSwitch_n = rtu_SlopeLoopOut - -0.3F;
    }

    /* Signum: '<S114>/Sign' */
    if (rtb_MultiportSwitch_n < 0.0F) {
      rtb_MultiportSwitch_n = -1.0F;
    } else if (rtb_MultiportSwitch_n > 0.0F) {
      rtb_MultiportSwitch_n = 1.0F;
    } else if (rtb_MultiportSwitch_n == 0.0F) {
      rtb_MultiportSwitch_n = 0.0F;
    } else {
      rtb_MultiportSwitch_n = (rtNaNF);
    }
    break;

   default:
    /* DeadZone: '<S114>/Dead Zone' */
    if (rtu_SlopeLoopOut > 0.3F) {
      rtb_MultiportSwitch_n = rtu_SlopeLoopOut - 0.3F;
    } else if (rtu_SlopeLoopOut >= -0.3F) {
      rtb_MultiportSwitch_n = 0.0F;
    } else {
      rtb_MultiportSwitch_n = rtu_SlopeLoopOut - -0.3F;
    }

    /* Signum: '<S114>/Sign' incorporates:
     *  Gain: '<S114>/Gain'
     */
    if (rtb_MultiportSwitch_n < 0.0F) {
      rtb_MultiportSwitch_n = 1.0F;
    } else if (rtb_MultiportSwitch_n > 0.0F) {
      rtb_MultiportSwitch_n = -1.0F;
    } else if (rtb_MultiportSwitch_n == 0.0F) {
      rtb_MultiportSwitch_n = -0.0F;
    } else {
      rtb_MultiportSwitch_n = (rtNaNF);
    }
    break;
  }

  /* End of MultiPortSwitch: '<S114>/Multiport Switch' */

  /* Update for DiscreteIntegrator: '<S114>/Discrete-Time Integrator' */
  localDW->Slope_state += 0.001F * rtb_MultiportSwitch_n;
  if (localDW->Slope_state >= 100.0F) {
    localDW->Slope_state = 100.0F;
  } else {
    if (localDW->Slope_state <= 0.0F) {
      localDW->Slope_state = 0.0F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S114>/Discrete-Time Integrator' */
}

/* Output and update for function-call system: '<S112>/Function-Call Subsystem' */
void APP_Flu_FunctionCallSubsystem_o(real32_T rtu_TorReq, real32_T rtu_Spd_loop,
  real32_T *rty_Out1)
{
  real32_T rtu_TorReq_0;

  /* Saturate: '<S121>/Saturation' */
  if (rtu_TorReq > 0.0F) {
    rtu_TorReq_0 = 0.0F;
  } else if (rtu_TorReq < -1.0F) {
    rtu_TorReq_0 = -1.0F;
  } else {
    rtu_TorReq_0 = rtu_TorReq;
  }

  /* End of Saturate: '<S121>/Saturation' */

  /* MinMax: '<S121>/MinMax' incorporates:
   *  Sum: '<S121>/Add'
   */
  *rty_Out1 = fmaxf(rtu_TorReq, rtu_Spd_loop + rtu_TorReq_0);
}

/* Output and update for function-call system: '<S112>/Function-Call Subsystem2' */
void APP_Flux_FunctionCallSubsystem2(real32_T rtu_TorReq, real32_T *rty_Out1,
  DW_FunctionCallSubsystem2_APP_T *localDW)
{
  real32_T rtb_UkYk1;

  /* Sum: '<S123>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S123>/Delay Input2'
   *
   * Block description for '<S123>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S123>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_UkYk1 = rtu_TorReq - localDW->N_state;

  /* Switch: '<S125>/Switch2' incorporates:
   *  RelationalOperator: '<S125>/LowerRelop1'
   *  RelationalOperator: '<S125>/UpperRelop'
   *  Switch: '<S125>/Switch'
   */
  if (rtb_UkYk1 > 0.001F) {
    rtb_UkYk1 = 0.001F;
  } else {
    if (rtb_UkYk1 < -0.001F) {
      /* Switch: '<S125>/Switch' */
      rtb_UkYk1 = -0.001F;
    }
  }

  /* End of Switch: '<S125>/Switch2' */

  /* Sum: '<S123>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S123>/Delay Input2'
   *
   * Block description for '<S123>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S123>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->N_state += rtb_UkYk1;

  /* SignalConversion: '<S123>/OutportBufferForOut1' */
  *rty_Out1 = localDW->N_state;
}

/* Output and update for function-call system: '<S112>/Function-Call Subsystem1' */
void APP_Flux_FunctionCallSubsystem1(real32_T rtu_TorReq, real32_T rtu_Spd_loop,
  real32_T *rty_Out1)
{
  real32_T rtu_TorReq_0;

  /* Saturate: '<S122>/Saturation' */
  if (rtu_TorReq > 1.0F) {
    rtu_TorReq_0 = 1.0F;
  } else if (rtu_TorReq < 0.0F) {
    rtu_TorReq_0 = 0.0F;
  } else {
    rtu_TorReq_0 = rtu_TorReq;
  }

  /* End of Saturate: '<S122>/Saturation' */

  /* MinMax: '<S122>/MinMax1' incorporates:
   *  Sum: '<S122>/Add'
   */
  *rty_Out1 = fminf(rtu_TorReq, rtu_TorReq_0 + rtu_Spd_loop);
}

/* Output and update for function-call system: '<S112>/Initial' */
void APP_FluxWeak_GEAR2_Initial_e(const real32_T *rtu_out)
{
  /* StateWriter: '<S124>/State Writer' */
  APP_FluxWeak_GEAR2_DW.Slope.FunctionCallSubsystem2.N_state = *rtu_out;
}

/* System initialize for function-call system: '<S54>/Slope' */
void APP_FluxWeak_GEAR2_Slope_Init(DW_Slope_APP_FluxWeak_GEAR2_T *localDW)
{
  /* SystemInitialize for Atomic SubSystem: '<S117>/lpf' */
  LPF_App_Init(&localDW->lpf);

  /* End of SystemInitialize for SubSystem: '<S117>/lpf' */

  /* SystemInitialize for Atomic SubSystem: '<S116>/lpf' */
  LPF_App_Init(&localDW->lpf_a);

  /* End of SystemInitialize for SubSystem: '<S116>/lpf' */
  localDW->is_move = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
  localDW->is_D = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
  localDW->is_R = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c4_APP_FluxWeak_GEAR2 = 0U;
  localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
  localDW->SpdReqPu_out = 0.0F;

  /* SystemInitialize for Chart: '<S70>/Chart' incorporates:
   *  SubSystem: '<S110>/Function-Call Subsystem'
   */
  APP__FunctionCallSubsystem_Init(&localDW->FunctionCallSubsystem);

  /* SystemInitialize for Chart: '<S112>/Chart' */
  localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
  localDW->is_active_c19_APP_FluxWeak_GEAR = 0U;

  /* SystemInitialize for Merge: '<S112>/Merge' */
  localDW->Merge = 0.0F;
}

/* Enable for function-call system: '<S54>/Slope' */
void APP_FluxWeak_GEAR2_Slope_Enable(DW_Slope_APP_FluxWeak_GEAR2_T *localDW)
{
  /* Enable for Chart: '<S70>/Chart' */
  if ((int16_T)localDW->is_c4_APP_FluxWeak_GEAR2 == (int16_T)
      APP_FluxWeak_GEAR2_IN_slope) {
    /* SystemReset for Function Call SubSystem: '<S110>/Function-Call Subsystem' */
    APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

    /* End of SystemReset for SubSystem: '<S110>/Function-Call Subsystem' */
  }

  /* End of Enable for Chart: '<S70>/Chart' */
}

/* Disable for function-call system: '<S54>/Slope' */
void APP_FluxWeak_GEAR_Slope_Disable(DW_Slope_APP_FluxWeak_GEAR2_T *localDW)
{
  /* Disable for Chart: '<S70>/Chart' */
  if ((int16_T)localDW->is_c4_APP_FluxWeak_GEAR2 == (int16_T)
      APP_FluxWeak_GEAR2_IN_slope) {
    /* Disable for Function Call SubSystem: '<S110>/Function-Call Subsystem' */
    A_FunctionCallSubsystem_Disable(&localDW->DiscreteTimeIntegrator);

    /* End of Disable for SubSystem: '<S110>/Function-Call Subsystem' */
  }

  /* End of Disable for Chart: '<S70>/Chart' */
}

/* Output and update for function-call system: '<S54>/Slope' */
void APP_FluxWeak_GEAR2_Slope(real32_T rtu_Data, real32_T rtu_Data_a, uint16_T
  rtu_Data_j, uint16_T rtu_Data_g, real32_T rtu_Data_l, real32_T rtu_Data_i,
  uint16_T *rty_Out1, real32_T *rty_Out1_a, real32_T *rty_Out1_j, real32_T
  *rty_Out1_g, uint16_T *rty_Out1_l, uint16_T *rty_Out1_i, real32_T *rty_Out1_c,
  real32_T *rty_Out1_o, real32_T *rty_Tor, DW_Slope_APP_FluxWeak_GEAR2_T
  *localDW)
{
  real32_T rtb_DiscreteTimeIntegrator1_f;
  real32_T rtb_Gain_g;
  uint16_T GearState_prev;

  /* SignalConversion: '<S70>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S70>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_a = 0.0F;

  /* SignalConversion: '<S70>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_j = 0.0F;

  /* SignalConversion: '<S70>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = 0.0F;

  /* SignalConversion: '<S70>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_l = 0U;

  /* SignalConversion: '<S70>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = 0U;

  /* SignalConversion: '<S70>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0.0F;

  /* Outputs for Atomic SubSystem: '<S117>/lpf' */

  /* Constant: '<S117>/Constant' incorporates:
   *  Constant: '<S117>/Constant1'
   */
  LPF_App(rtu_Data, 0.002F, 1000.0F / PMSM_Param.DamperTimer,
          &rtb_DiscreteTimeIntegrator1_f, &localDW->lpf);

  /* End of Outputs for SubSystem: '<S117>/lpf' */

  /* Gain: '<S115>/Gain' incorporates:
   *  Sum: '<S115>/Sum'
   */
  rtb_Gain_g = (rtb_DiscreteTimeIntegrator1_f - rtu_Data) *
    PMSM_Param.DamperGain;

  /* Outputs for Atomic SubSystem: '<S116>/lpf' */

  /* Constant: '<S116>/Constant' incorporates:
   *  Constant: '<S116>/Constant1'
   */
  LPF_App(rtu_Data_i, 0.002F, 33.3333321F, &rtb_DiscreteTimeIntegrator1_f,
          &localDW->lpf_a);

  /* End of Outputs for SubSystem: '<S116>/lpf' */

  /* Sum: '<S111>/Add' */
  rtb_Gain_g += rtb_DiscreteTimeIntegrator1_f;

  /* Saturate: '<S111>/Saturation' */
  if (rtb_Gain_g > 1.0F) {
    rtb_Gain_g = 1.0F;
  } else {
    if (rtb_Gain_g < -1.0F) {
      rtb_Gain_g = -1.0F;
    }
  }

  /* End of Saturate: '<S111>/Saturation' */

  /* Chart: '<S70>/Chart' incorporates:
   *  UnitDelay: '<S70>/Unit Delay'
   */
  /* Gateway: implement/method/All_loop/Slope/Chart */
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  GearState_prev = localDW->GearState_start;
  localDW->GearState_start = rtu_Data_j;

  /* During: implement/method/All_loop/Slope/Chart */
  if (localDW->is_active_c4_APP_FluxWeak_GEAR2 == 0U) {
    /* Entry: implement/method/All_loop/Slope/Chart */
    localDW->is_active_c4_APP_FluxWeak_GEAR2 = 1U;

    /* Entry Internal: implement/method/All_loop/Slope/Chart */
    /* Transition: '<S109>:4' */
    localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_slope;

    /* SystemReset for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

    /* Entry 'slope': '<S109>:3' */
    APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

    /* End of SystemReset for SubSystem: '<S110>/Function-Call Subsystem' */

    /* '<S109>:3:1' SpdReqPu_out=SpdReqPu_in; */
    localDW->SpdReqPu_out = rtu_Data_l;

    /* Outputs for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

    /* '<S109>:3:3' TimeCount; */
    /* Event: '<S109>:38' */
    APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, rtu_Data_j,
      &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

    /* End of Outputs for SubSystem: '<S110>/Function-Call Subsystem' */
  } else if (localDW->is_c4_APP_FluxWeak_GEAR2 == 1U) {
    /* During 'move': '<S109>:6' */
    /* '<S109>:29:1' sf_internal_predicateOutput = ... */
    /* '<S109>:29:1' GearState==0; */
    if (rtu_Data_j == 0U) {
      /* Transition: '<S109>:29' */
      /* Exit Internal 'move': '<S109>:6' */
      /* Exit Internal 'D': '<S109>:8' */
      localDW->is_D = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
      localDW->is_move = APP_FluxWeak_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'R': '<S109>:20' */
      localDW->is_R = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
      localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_slope;

      /* SystemReset for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

      /* Entry 'slope': '<S109>:3' */
      APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

      /* End of SystemReset for SubSystem: '<S110>/Function-Call Subsystem' */

      /* '<S109>:3:1' SpdReqPu_out=SpdReqPu_in; */
      localDW->SpdReqPu_out = rtu_Data_l;

      /* Outputs for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

      /* '<S109>:3:3' TimeCount; */
      /* Event: '<S109>:38' */
      APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, 0U,
        &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

      /* End of Outputs for SubSystem: '<S110>/Function-Call Subsystem' */
    } else if (localDW->is_move == 1U) {
      /* During 'D': '<S109>:8' */
      if (localDW->is_D == 1U) {
        /* During 'Add': '<S109>:12' */
        /* Transition: '<S109>:24' */
        /* '<S109>:25:1' sf_internal_predicateOutput = ... */
        /* '<S109>:25:1' after(500,tick); */
        if (localDW->temporalCounter_i1 >= 500U) {
          /* Transition: '<S109>:25' */
          localDW->is_D = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          localDW->is_move = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_slope;

          /* SystemReset for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

          /* Entry 'slope': '<S109>:3' */
          APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

          /* End of SystemReset for SubSystem: '<S110>/Function-Call Subsystem' */

          /* '<S109>:3:1' SpdReqPu_out=SpdReqPu_in; */
          localDW->SpdReqPu_out = rtu_Data_l;

          /* Outputs for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

          /* '<S109>:3:3' TimeCount; */
          /* Event: '<S109>:38' */
          APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, rtu_Data_j,
            &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

          /* End of Outputs for SubSystem: '<S110>/Function-Call Subsystem' */
        } else {
          /* '<S109>:12:1' SpdReqPu_out=SpdReqPu_out+0.2; */
          localDW->SpdReqPu_out += 0.2F;
        }
      } else {
        /* During 'Sub': '<S109>:10' */
        /* '<S109>:14:1' sf_internal_predicateOutput = ... */
        /* '<S109>:14:1' after(500,tick); */
        if (localDW->temporalCounter_i1 >= 500U) {
          /* Transition: '<S109>:14' */
          localDW->is_D = APP_FluxWeak_GEAR2_IN_Add;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'Add': '<S109>:12' */
          /* '<S109>:12:1' SpdReqPu_out=SpdReqPu_out+0.2; */
          localDW->SpdReqPu_out += 0.2F;
        } else {
          /* '<S109>:10:1' SpdReqPu_out=SpdReqPu_out-0.2; */
          localDW->SpdReqPu_out -= 0.2F;
        }
      }
    } else {
      /* During 'R': '<S109>:20' */
      if (localDW->is_R == 1U) {
        /* During 'Add': '<S109>:19' */
        /* '<S109>:21:1' sf_internal_predicateOutput = ... */
        /* '<S109>:21:1' after(500,tick); */
        if (localDW->temporalCounter_i1 >= 500U) {
          /* Transition: '<S109>:21' */
          localDW->is_R = APP_FluxWeak_GEAR2_IN_Sub;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'Sub': '<S109>:18' */
          /* '<S109>:18:1' SpdReqPu_out=SpdReqPu_out-0.2; */
          localDW->SpdReqPu_out -= 0.2F;
        } else {
          /* '<S109>:19:1' SpdReqPu_out=SpdReqPu_out+0.2; */
          localDW->SpdReqPu_out += 0.2F;
        }
      } else {
        /* During 'Sub': '<S109>:18' */
        /* Transition: '<S109>:23' */
        /* '<S109>:25:1' sf_internal_predicateOutput = ... */
        /* '<S109>:25:1' after(500,tick); */
        if (localDW->temporalCounter_i1 >= 500U) {
          /* Transition: '<S109>:25' */
          localDW->is_R = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          localDW->is_move = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_slope;

          /* SystemReset for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

          /* Entry 'slope': '<S109>:3' */
          APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

          /* End of SystemReset for SubSystem: '<S110>/Function-Call Subsystem' */

          /* '<S109>:3:1' SpdReqPu_out=SpdReqPu_in; */
          localDW->SpdReqPu_out = rtu_Data_l;

          /* Outputs for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

          /* '<S109>:3:3' TimeCount; */
          /* Event: '<S109>:38' */
          APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, rtu_Data_j,
            &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

          /* End of Outputs for SubSystem: '<S110>/Function-Call Subsystem' */
        } else {
          /* '<S109>:18:1' SpdReqPu_out=SpdReqPu_out-0.2; */
          localDW->SpdReqPu_out -= 0.2F;
        }
      }
    }
  } else {
    /* During 'slope': '<S109>:3' */
    /* '<S109>:7:1' sf_internal_predicateOutput = ... */
    /* '<S109>:7:1' SlopeTime>5; */
    if (localDW->DiscreteTimeIntegrator > 5.0F) {
      /* Disable for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

      /* Transition: '<S109>:7' */
      /* Exit 'slope': '<S109>:3' */
      A_FunctionCallSubsystem_Disable(&localDW->DiscreteTimeIntegrator);

      /* End of Disable for SubSystem: '<S110>/Function-Call Subsystem' */
      localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_move;

      /* Entry Internal 'move': '<S109>:6' */
      /* Transition: '<S109>:9' */
      /* '<S109>:27:1' sf_internal_predicateOutput = ... */
      /* '<S109>:27:1' GearState==1; */
      if (rtu_Data_j == 1U) {
        /* Transition: '<S109>:27' */
        localDW->is_move = APP_FluxWeak_GEAR2_IN_D;

        /* Entry 'D': '<S109>:8' */
        /* 后溜 */
        /* Entry Internal 'D': '<S109>:8' */
        /* Transition: '<S109>:11' */
        localDW->is_D = APP_FluxWeak_GEAR2_IN_Sub;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'Sub': '<S109>:10' */
        /* '<S109>:10:1' SpdReqPu_out=SpdReqPu_out-0.2; */
        localDW->SpdReqPu_out -= 0.2F;
      } else {
        /* Transition: '<S109>:28' */
        localDW->is_move = APP_FluxWeak_GEAR2_IN_R;

        /* Entry 'R': '<S109>:20' */
        /* 后溜 */
        /* Entry Internal 'R': '<S109>:20' */
        /* Transition: '<S109>:17' */
        localDW->is_R = APP_FluxWeak_GEAR2_IN_Add;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'Add': '<S109>:19' */
        /* '<S109>:19:1' SpdReqPu_out=SpdReqPu_out+0.2; */
        localDW->SpdReqPu_out += 0.2F;
      }
    } else {
      /* '<S109>:36:1' sf_internal_predicateOutput = ... */
      /* '<S109>:36:1' hasChanged(GearState); */
      if (GearState_prev != localDW->GearState_start) {
        /* Disable for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

        /* Transition: '<S109>:36' */
        /* Exit 'slope': '<S109>:3' */
        A_FunctionCallSubsystem_Disable(&localDW->DiscreteTimeIntegrator);

        /* End of Disable for SubSystem: '<S110>/Function-Call Subsystem' */
        localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_slope;

        /* SystemReset for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

        /* Entry 'slope': '<S109>:3' */
        APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

        /* End of SystemReset for SubSystem: '<S110>/Function-Call Subsystem' */

        /* '<S109>:3:1' SpdReqPu_out=SpdReqPu_in; */
        localDW->SpdReqPu_out = rtu_Data_l;

        /* Outputs for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

        /* '<S109>:3:3' TimeCount; */
        /* Event: '<S109>:38' */
        APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, rtu_Data_j,
          &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

        /* End of Outputs for SubSystem: '<S110>/Function-Call Subsystem' */
      } else {
        /* '<S109>:3:1' SpdReqPu_out=SpdReqPu_in; */
        localDW->SpdReqPu_out = rtu_Data_l;

        /* Outputs for Function Call SubSystem: '<S110>/Function-Call Subsystem' */

        /* '<S109>:3:3' TimeCount; */
        /* Event: '<S109>:38' */
        APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, rtu_Data_j,
          &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

        /* End of Outputs for SubSystem: '<S110>/Function-Call Subsystem' */
      }
    }
  }

  /* End of Chart: '<S70>/Chart' */

  /* Outputs for Atomic SubSystem: '<S113>/PI' */

  /* Gain: '<S70>/Norm' incorporates:
   *  Constant: '<S113>/Constant'
   *  Constant: '<S113>/Constant1'
   *  Constant: '<S113>/Constant2'
   *  Sum: '<S70>/Subtract'
   */
  PI_App(0.0001F * (localDW->SpdReqPu_out - rtu_Data_a), PMSM_Param.SlopeKp,
         PMSM_Param.SlopeKi, 0.002F, &localDW->UnitDelay_DSTATE,
         &rtb_DiscreteTimeIntegrator1_f, &localDW->PI);

  /* End of Outputs for SubSystem: '<S113>/PI' */

  /* MultiPortSwitch: '<S113>/Multiport Switch' */
  switch (rtu_Data_j) {
   case 0:
    break;

   case 1:
    /* Saturate: '<S113>/Saturation1' */
    if (localDW->UnitDelay_DSTATE > PMSM_Param.SlopeMaxT) {
      localDW->UnitDelay_DSTATE = PMSM_Param.SlopeMaxT;
    } else {
      if (localDW->UnitDelay_DSTATE < -1.0F) {
        localDW->UnitDelay_DSTATE = -1.0F;
      }
    }

    /* End of Saturate: '<S113>/Saturation1' */
    break;

   default:
    /* Saturate: '<S113>/Saturation2' */
    if (localDW->UnitDelay_DSTATE > 1.0F) {
      localDW->UnitDelay_DSTATE = 1.0F;
    } else {
      if (localDW->UnitDelay_DSTATE < -PMSM_Param.SlopeMaxT) {
        localDW->UnitDelay_DSTATE = -PMSM_Param.SlopeMaxT;
      }
    }

    /* End of Saturate: '<S113>/Saturation2' */
    break;
  }

  /* End of MultiPortSwitch: '<S113>/Multiport Switch' */

  /* Chart: '<S112>/Chart' */
  /* Gateway: implement/method/All_loop/Slope/Tor_select/Chart */
  GearState_prev = localDW->Gear_start;
  localDW->Gear_start = rtu_Data_j;

  /* During: implement/method/All_loop/Slope/Tor_select/Chart */
  if (localDW->is_active_c19_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/Slope/Tor_select/Chart */
    localDW->is_active_c19_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/Slope/Tor_select/Chart */
    /* Transition: '<S120>:3' */
    /* Entry Internal 'Gear': '<S120>:2' */
    /* Transition: '<S120>:4' */
    /* '<S120>:7:1' sf_internal_predicateOutput = ... */
    /* '<S120>:7:1' Gear==1; */
    switch (rtu_Data_j) {
     case 1U:
      /* Transition: '<S120>:7' */
      localDW->is_Gear = APP_FluxWeak_GEAR2_IN_D;

      /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

      /* Entry 'D': '<S120>:6' */
      /* '<S120>:6:1' D_call; */
      /* Event: '<S120>:17' */
      APP_Flu_FunctionCallSubsystem_o(rtb_Gain_g, localDW->UnitDelay_DSTATE,
        &localDW->Merge);

      /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem' */
      break;

     case 2U:
      /* Transition: '<S120>:12' */
      /* '<S120>:11:1' sf_internal_predicateOutput = ... */
      /* '<S120>:11:1' Gear==2; */
      /* Transition: '<S120>:11' */
      localDW->is_Gear = APP_FluxWeak_GEAR2_IN_R_e;

      /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem1' */

      /* Entry 'R': '<S120>:8' */
      /* '<S120>:8:1' R_call; */
      /* Event: '<S120>:21' */
      APP_Flux_FunctionCallSubsystem1(rtb_Gain_g, localDW->UnitDelay_DSTATE,
        &localDW->Merge);

      /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem1' */
      break;

     default:
      /* Transition: '<S120>:14' */
      /* Transition: '<S120>:15' */
      localDW->is_Gear = APP_FluxWeak_GEAR2_IN_N;

      /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem2' */

      /* Entry 'N': '<S120>:9' */
      /* '<S120>:9:1' N_call; */
      /* Event: '<S120>:20' */
      APP_Flux_FunctionCallSubsystem2(rtb_Gain_g, &localDW->Merge,
        &localDW->FunctionCallSubsystem2);

      /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem2' */
      break;
    }
  } else {
    /* During 'Gear': '<S120>:2' */
    /* '<S120>:16:1' sf_internal_predicateOutput = ... */
    /* '<S120>:16:1' hasChanged(Gear); */
    if (GearState_prev != localDW->Gear_start) {
      /* Transition: '<S120>:16' */
      /* '<S120>:7:1' sf_internal_predicateOutput = ... */
      /* '<S120>:7:1' Gear==1; */
      switch (rtu_Data_j) {
       case 1U:
        /* Transition: '<S120>:7' */
        /* Exit Internal 'Gear': '<S120>:2' */
        switch (localDW->is_Gear) {
         case APP_FluxWeak_GEAR2_IN_D:
          /* Outputs for Function Call SubSystem: '<S112>/Initial' */

          /* Exit 'D': '<S120>:6' */
          /* '<S120>:6:1' RST_N; */
          /* Event: '<S120>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S112>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         case APP_FluxWeak_GEAR2_IN_R_e:
          /* Outputs for Function Call SubSystem: '<S112>/Initial' */

          /* Exit 'R': '<S120>:8' */
          /* '<S120>:8:1' RST_N; */
          /* Event: '<S120>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S112>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         default:
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;
        }

        localDW->is_Gear = APP_FluxWeak_GEAR2_IN_D;

        /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

        /* Entry 'D': '<S120>:6' */
        /* '<S120>:6:1' D_call; */
        /* Event: '<S120>:17' */
        APP_Flu_FunctionCallSubsystem_o(rtb_Gain_g, localDW->UnitDelay_DSTATE,
          &localDW->Merge);

        /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem' */
        break;

       case 2U:
        /* Transition: '<S120>:12' */
        /* '<S120>:11:1' sf_internal_predicateOutput = ... */
        /* '<S120>:11:1' Gear==2; */
        /* Transition: '<S120>:11' */
        /* Exit Internal 'Gear': '<S120>:2' */
        switch (localDW->is_Gear) {
         case APP_FluxWeak_GEAR2_IN_D:
          /* Outputs for Function Call SubSystem: '<S112>/Initial' */

          /* Exit 'D': '<S120>:6' */
          /* '<S120>:6:1' RST_N; */
          /* Event: '<S120>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S112>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         case APP_FluxWeak_GEAR2_IN_R_e:
          /* Outputs for Function Call SubSystem: '<S112>/Initial' */

          /* Exit 'R': '<S120>:8' */
          /* '<S120>:8:1' RST_N; */
          /* Event: '<S120>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S112>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         default:
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;
        }

        localDW->is_Gear = APP_FluxWeak_GEAR2_IN_R_e;

        /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem1' */

        /* Entry 'R': '<S120>:8' */
        /* '<S120>:8:1' R_call; */
        /* Event: '<S120>:21' */
        APP_Flux_FunctionCallSubsystem1(rtb_Gain_g, localDW->UnitDelay_DSTATE,
          &localDW->Merge);

        /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem1' */
        break;

       default:
        /* Transition: '<S120>:14' */
        /* Transition: '<S120>:15' */
        /* Exit Internal 'Gear': '<S120>:2' */
        switch (localDW->is_Gear) {
         case APP_FluxWeak_GEAR2_IN_D:
          /* Outputs for Function Call SubSystem: '<S112>/Initial' */

          /* Exit 'D': '<S120>:6' */
          /* '<S120>:6:1' RST_N; */
          /* Event: '<S120>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S112>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         case APP_FluxWeak_GEAR2_IN_R_e:
          /* Outputs for Function Call SubSystem: '<S112>/Initial' */

          /* Exit 'R': '<S120>:8' */
          /* '<S120>:8:1' RST_N; */
          /* Event: '<S120>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S112>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         default:
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;
        }

        localDW->is_Gear = APP_FluxWeak_GEAR2_IN_N;

        /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem2' */

        /* Entry 'N': '<S120>:9' */
        /* '<S120>:9:1' N_call; */
        /* Event: '<S120>:20' */
        APP_Flux_FunctionCallSubsystem2(rtb_Gain_g, &localDW->Merge,
          &localDW->FunctionCallSubsystem2);

        /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem2' */
        break;
      }
    } else {
      switch (localDW->is_Gear) {
       case APP_FluxWeak_GEAR2_IN_D:
        /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

        /* During 'D': '<S120>:6' */
        /* '<S120>:6:1' D_call; */
        /* Event: '<S120>:17' */
        APP_Flu_FunctionCallSubsystem_o(rtb_Gain_g, localDW->UnitDelay_DSTATE,
          &localDW->Merge);

        /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem' */
        break;

       case APP_FluxWeak_GEAR2_IN_N:
        /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem2' */

        /* During 'N': '<S120>:9' */
        /* '<S120>:9:1' N_call; */
        /* Event: '<S120>:20' */
        APP_Flux_FunctionCallSubsystem2(rtb_Gain_g, &localDW->Merge,
          &localDW->FunctionCallSubsystem2);

        /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem2' */
        break;

       default:
        /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem1' */

        /* During 'R': '<S120>:8' */
        /* '<S120>:8:1' R_call; */
        /* Event: '<S120>:21' */
        APP_Flux_FunctionCallSubsystem1(rtb_Gain_g, localDW->UnitDelay_DSTATE,
          &localDW->Merge);

        /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem1' */
        break;
      }
    }
  }

  /* End of Chart: '<S112>/Chart' */

  /* Switch: '<S70>/Switch' incorporates:
   *  Constant: '<S70>/Constant8'
   */
  if (rtu_Data_g != 0U) {
    rtb_DiscreteTimeIntegrator1_f = localDW->Merge;
  } else {
    rtb_DiscreteTimeIntegrator1_f = 0.0F;
  }

  /* End of Switch: '<S70>/Switch' */

  /* SignalConversion: '<S70>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_o = rtb_DiscreteTimeIntegrator1_f;

  /* SignalConversion: '<S70>/OutportBufferForTor' */
  *rty_Tor = rtb_DiscreteTimeIntegrator1_f;
}

/* Output and update for function-call system: '<S54>/Sync' */
void APP_FluxWeak_GEAR2_Sync(real32_T rtu_Data, real32_T rtu_Data_e, uint16_T
  *rty_Out1, real32_T *rty_Out1_e, real32_T *rty_Out1_g, real32_T *rty_Out1_g5,
  uint16_T *rty_Out1_c, uint16_T *rty_Out1_i, real32_T *rty_Out1_k, real32_T
  *rty_Out1_ed, real32_T *rty_Tor, DW_Sync_APP_FluxWeak_GEAR2_T *localDW)
{
  real32_T rtb_Add_j;
  real32_T rtb_DiscreteTimeIntegrator1_j;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_e = 0.0F;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = 0.0F;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g5 = 0.0F;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0U;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = 0U;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_k = 0.0F;

  /* Outputs for Atomic SubSystem: '<S130>/PI' */

  /* Gain: '<S73>/Norm' incorporates:
   *  Constant: '<S130>/Constant'
   *  Constant: '<S130>/Constant1'
   *  Constant: '<S130>/Constant2'
   *  Sum: '<S73>/Subtract'
   */
  PI_App(0.0001F * (rtu_Data - rtu_Data_e), PMSM_Param.SyncKp, PMSM_Param.SyncKi,
         0.002F, &rtb_Add_j, &rtb_DiscreteTimeIntegrator1_j, &localDW->PI);

  /* End of Outputs for SubSystem: '<S130>/PI' */

  /* Saturate: '<S130>/Saturation' */
  if (rtb_Add_j > 1.0F) {
    rtb_Add_j = 1.0F;
  } else {
    if (rtb_Add_j < -1.0F) {
      rtb_Add_j = -1.0F;
    }
  }

  /* End of Saturate: '<S130>/Saturation' */

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_ed = rtb_Add_j;

  /* SignalConversion: '<S73>/OutportBufferForTor' */
  *rty_Tor = rtb_Add_j;
}

/* Output and update for function-call system: '<S54>/Dischg' */
void APP_FluxWeak_GEAR2_Dischg(real32_T rtu_Data, uint16_T *rty_Out1, real32_T
  *rty_Out1_d, real32_T *rty_Out1_j, real32_T *rty_Out1_b, uint16_T *rty_Out1_o,
  uint16_T *rty_Out1_k, real32_T *rty_Out1_c, real32_T *rty_Out1_l,
  DW_Dischg_APP_FluxWeak_GEAR2_T *localDW)
{
  /* Relay: '<S64>/Relay' */
  if (rtu_Data >= 50.0F) {
    localDW->Relay_Mode = true;
  } else {
    if (rtu_Data <= 30.0F) {
      localDW->Relay_Mode = false;
    }
  }

  /* Switch: '<S64>/Switch' incorporates:
   *  Constant: '<S64>/Constant'
   *  Constant: '<S64>/Constant9'
   *  Relay: '<S64>/Relay'
   */
  if (localDW->Relay_Mode) {
    *rty_Out1_d = PMSM_Param.DischgId;
  } else {
    *rty_Out1_d = 0.0F;
  }

  /* End of Switch: '<S64>/Switch' */

  /* SignalConversion: '<S64>/TmpBufferAtConstant1Outport1' incorporates:
   *  Constant: '<S64>/Constant1'
   */
  *rty_Out1_j = 0.0F;

  /* SignalConversion: '<S64>/TmpBufferAtConstant2Outport1' incorporates:
   *  Constant: '<S64>/Constant2'
   */
  *rty_Out1_b = 0.0F;

  /* SignalConversion: '<S64>/TmpBufferAtConstant3Outport1' incorporates:
   *  Constant: '<S64>/Constant3'
   */
  *rty_Out1_o = 1U;

  /* SignalConversion: '<S64>/TmpBufferAtConstant4Outport1' incorporates:
   *  Constant: '<S64>/Constant4'
   */
  *rty_Out1_k = 0U;

  /* SignalConversion: '<S64>/TmpBufferAtConstant5Outport1' incorporates:
   *  Constant: '<S64>/Constant5'
   */
  *rty_Out1_l = 0.0F;

  /* SignalConversion: '<S64>/TmpBufferAtConstant6Outport1' incorporates:
   *  Constant: '<S64>/Constant6'
   */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S64>/TmpBufferAtConstant8Outport1' incorporates:
   *  Constant: '<S64>/Constant8'
   */
  *rty_Out1_c = 0.0F;
}

/* Output and update for function-call system: '<S54>/ASC' */
void APP_FluxWeak_GEAR2_ASC(uint16_T *rty_Out1, real32_T *rty_Out1_e, real32_T
  *rty_Out1_l, real32_T *rty_Out1_i, uint16_T *rty_Out1_f, uint16_T *rty_Out1_g,
  real32_T *rty_Out1_gu, real32_T *rty_Out1_k)
{
  /* SignalConversion: '<S61>/TmpBufferAtConstant1Outport1' incorporates:
   *  Constant: '<S61>/Constant1'
   */
  *rty_Out1_l = 0.0F;

  /* SignalConversion: '<S61>/TmpBufferAtConstant2Outport1' incorporates:
   *  Constant: '<S61>/Constant2'
   */
  *rty_Out1_i = 0.0F;

  /* SignalConversion: '<S61>/TmpBufferAtConstant3Outport1' incorporates:
   *  Constant: '<S61>/Constant3'
   */
  *rty_Out1_f = 0U;

  /* SignalConversion: '<S61>/TmpBufferAtConstant4Outport1' incorporates:
   *  Constant: '<S61>/Constant4'
   */
  *rty_Out1_g = 0U;

  /* SignalConversion: '<S61>/TmpBufferAtConstant5Outport1' incorporates:
   *  Constant: '<S61>/Constant5'
   */
  *rty_Out1_k = 0.0F;

  /* SignalConversion: '<S61>/TmpBufferAtConstant6Outport1' incorporates:
   *  Constant: '<S61>/Constant6'
   */
  *rty_Out1 = 1U;

  /* SignalConversion: '<S61>/TmpBufferAtConstant8Outport1' incorporates:
   *  Constant: '<S61>/Constant8'
   */
  *rty_Out1_gu = 0.0F;

  /* SignalConversion: '<S61>/TmpBufferAtConstantOutport1' incorporates:
   *  Constant: '<S61>/Constant'
   */
  *rty_Out1_e = 0.0F;
}

/* System initialize for function-call system: '<S62>/PhaseStudy' */
void APP_FluxWeak_GE_PhaseStudy_Init(DW_PhaseStudy_APP_FluxWeak_GE_T *localDW)
{
  /* SystemInitialize for Chart: '<S83>/Chart' */
  localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_j;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_APP_FluxWeak_GEAR = 0U;
  localDW->is_c10_APP_FluxWeak_GEAR2 = APP_FluxWe_IN_NO_ACTIVE_CHILD_j;
  localDW->ThetaRTHis = 0.0F;
  localDW->ThetaDelta = 0.0F;
  localDW->StudyResult = 0.0F;
  localDW->IdRefSet = 0.0F;
  localDW->AngleRefSet = 0.0F;
  localDW->StudyStep = 0U;
}

/* Output and update for function-call system: '<S62>/PhaseStudy' */
void APP_FluxWeak_GEAR2_PhaseStudy(real32_T rtu_Data, real32_T rtu_Data_g,
  uint16_T *rty_Out1, real32_T *rty_Out1_g, real32_T *rty_Out1_h, real32_T
  *rty_Out1_i, uint16_T *rty_Out1_a, uint16_T *rty_Out1_a3, real32_T
  *rty_Out1_at, real32_T *rty_Out1_gs, DW_PhaseStudy_APP_FluxWeak_GE_T *localDW)
{
  boolean_T sf_internal_predicateOutput;
  real32_T tmp;
  boolean_T guard1 = false;

  /* Chart: '<S83>/Chart' */
  /* Gateway: implement/method/All_loop/Calib/PhaseStudy/Chart */
  if (localDW->temporalCounter_i1 < 127U) {
    localDW->temporalCounter_i1 = ((int16_T)localDW->temporalCounter_i1 + 1) &
      255U;
  }

  /* During: implement/method/All_loop/Calib/PhaseStudy/Chart */
  if (localDW->is_active_c10_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/Calib/PhaseStudy/Chart */
    localDW->is_active_c10_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/Calib/PhaseStudy/Chart */
    /* Transition: '<S98>:7' */
    localDW->is_c10_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Init;

    /* Entry 'Init': '<S98>:6' */
    /* '<S98>:6:1' StudyResult = 8888; */
    localDW->StudyResult = 8888.0F;

    /* '<S98>:6:1' StudyStep=10; */
    localDW->StudyStep = 10U;
  } else {
    guard1 = false;
    switch (localDW->is_c10_APP_FluxWeak_GEAR2) {
     case APP_FluxWeak_GEAR2_IN_Fault:
      /* During 'Fault': '<S98>:10' */
      break;

     case APP_FluxWeak_GEAR2_IN_Fin1:
      /* During 'Fin1': '<S98>:185' */
      break;

     case APP_FluxWeak_GEAR2_IN_Init:
      /* During 'Init': '<S98>:6' */
      /* '<S98>:11:1' sf_internal_predicateOutput = ... */
      /* '<S98>:11:1' TqReq > 0.001; */
      if (rtu_Data_g > 0.001) {
        /* Transition: '<S98>:11' */
        localDW->is_c10_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Study;

        /* Entry 'Study': '<S98>:8' */
        /* '<S98>:8:1' StudyStep=11; */
        localDW->StudyStep = 11U;

        /* Entry Internal 'Study': '<S98>:8' */
        /* Transition: '<S98>:74' */
        localDW->is_Study = APP_FluxWeak_GEAR2_IN_AddId;

        /* Entry 'AddId': '<S98>:72' */
        /* 增加id */
        /* '<S98>:72:1' IdRefSet = IdRefSet + 0.001; */
        localDW->IdRefSet += 0.001F;
      }
      break;

     default:
      /* During 'Study': '<S98>:8' */
      switch (localDW->is_Study) {
       case APP_FluxWeak_GEAR2_IN_AddId:
        /* During 'AddId': '<S98>:72' */
        /* '<S98>:69:1' sf_internal_predicateOutput = ... */
        /* '<S98>:69:1' IdRefSet > 0.3; */
        if (localDW->IdRefSet > 0.3) {
          /* Transition: '<S98>:69' */
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_Wait1;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'Wait1': '<S98>:70' */
          /* 等 */
          /* '<S98>:70:1' IdRefSet = 0.3; */
          localDW->IdRefSet = 0.3F;
        } else {
          /* '<S98>:72:1' IdRefSet = IdRefSet + 0.001; */
          localDW->IdRefSet += 0.001F;
        }
        break;

       case APP_FluxWeak_GEAR2_IN_ChgAngle1:
        /* During 'ChgAngle1': '<S98>:73' */
        /* '<S98>:83:1' sf_internal_predicateOutput = ... */
        /* '<S98>:83:1' AngleRefSet > 1.5708; */
        if (localDW->AngleRefSet > 1.5708) {
          /* Transition: '<S98>:83' */
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_Wait3;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'Wait3': '<S98>:86' */
          /* 等 */
          /* '<S98>:86:1' AngleRefSet = 1.5708; */
          localDW->AngleRefSet = 1.5708F;
        } else {
          /* '<S98>:73:2' AngleRefSet = AngleRefSet + 0.001; */
          localDW->AngleRefSet += 0.001F;
        }
        break;

       case APP_FluxWeak_GEAR2_IN_DecId:
        /* During 'DecId': '<S98>:82' */
        /* '<S98>:85:1' sf_internal_predicateOutput = ... */
        /* '<S98>:85:1' IdRefSet < 0.002; */
        if (localDW->IdRefSet < 0.002) {
          /* Transition: '<S98>:85' */
          /* Transition: '<S98>:182' */
          /* '<S98>:182:1' IdRefSet = 0; */
          localDW->IdRefSet = 0.0F;

          /* '<S98>:98:1' sf_internal_predicateOutput = ... */
          /* '<S98>:98:1' ThetaDelta < -2048; */
          if (localDW->ThetaDelta < -2048.0F) {
            /* Transition: '<S98>:98' */
            /* Transition: '<S98>:94' */
            /* '<S98>:94:1' ThetaDelta = ThetaDelta + 4096; */
            localDW->ThetaDelta += 4096.0F;
          } else {
            /* '<S98>:95:1' sf_internal_predicateOutput = ... */
            /* '<S98>:95:1' ThetaDelta > 2048; */
            if (localDW->ThetaDelta > 2048.0F) {
              /* Transition: '<S98>:95' */
              /* Transition: '<S98>:96' */
              /* '<S98>:96:1' ThetaDelta = ThetaDelta -4096; */
              localDW->ThetaDelta -= 4096.0F;
            } else {
              /* Transition: '<S98>:90' */
            }
          }

          /* '<S98>:92:1' sf_internal_predicateOutput = ... */
          /* '<S98>:92:1' abs(ThetaDelta) < (0.3*1024 / PMSM_Param.PoleRatio); */
          if (fabsf(localDW->ThetaDelta) < 307.2F / PMSM_Param.PoleRatio) {
            /* Transition: '<S98>:92' */
            /* Transition: '<S98>:184' */
            localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_j;
            localDW->is_c10_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Fault;

            /* Entry 'Fault': '<S98>:10' */
            /* 故障 */
            /* '<S98>:10:1' StudyResult = 5555; */
            localDW->StudyResult = 5555.0F;

            /* '<S98>:10:1' IdRefSet = 0; */
            localDW->IdRefSet = 0.0F;

            /* '<S98>:10:3' StudyStep=14; */
            localDW->StudyStep = 14U;
          } else {
            /* Transition: '<S98>:89' */
            localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_j;
            localDW->is_c10_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Fin1;

            /* Entry 'Fin1': '<S98>:185' */
            /* 完成(成功) */
            /* Entry Internal 'Fin1': '<S98>:185' */
            /* Transition: '<S98>:194' */
            /* '<S98>:195:1' sf_internal_predicateOutput = ... */
            /* '<S98>:195:1' ThetaDelta>1024 /PMSM_Param.PoleRatio*0.3 && ... */
            /* '<S98>:195:1' ThetaDelta<1024 /PMSM_Param.PoleRatio*1.7; */
            tmp = 1024.0F / PMSM_Param.PoleRatio;
            if (localDW->ThetaDelta > tmp * 0.3F) {
              sf_internal_predicateOutput = (localDW->ThetaDelta < tmp * 1.7F);
            } else {
              sf_internal_predicateOutput = false;
            }

            if (sf_internal_predicateOutput) {
              /* Transition: '<S98>:195' */
              /* 角度变化量在pi/2附近 */
              /* Transition: '<S98>:196' */
              /* '<S98>:198:1' sf_internal_predicateOutput = ... */
              /* '<S98>:198:1' PMSM_Param.ResolverDirChg == 1; */
              if (PMSM_Param.ResolverDirChg == 1U) {
                /* Transition: '<S98>:198' */
                guard1 = true;
              } else {
                /* Transition: '<S98>:200' */
                /* '<S98>:200:1' StudyResult =0; */
                localDW->StudyResult = 0.0F;

                /* '<S98>:200:1' StudyStep=13; */
                localDW->StudyStep = 13U;
              }
            } else {
              /* Transition: '<S98>:197' */
              /* '<S98>:199:1' sf_internal_predicateOutput = ... */
              /* '<S98>:199:1' PMSM_Param.ResolverDirChg == 0; */
              if (PMSM_Param.ResolverDirChg == 0U) {
                /* Transition: '<S98>:199' */
                guard1 = true;
              } else {
                /* Transition: '<S98>:202' */
                /* '<S98>:202:1' StudyResult =0; */
                localDW->StudyResult = 0.0F;

                /* '<S98>:202:1' StudyStep=13; */
                localDW->StudyStep = 13U;

                /* Transition: '<S98>:204' */
                /* Transition: '<S98>:203' */
              }
            }
          }
        } else {
          /* '<S98>:82:3' IdRefSet = IdRefSet - 0.001; */
          localDW->IdRefSet -= 0.001F;
        }
        break;

       case APP_FluxWeak_GEAR2_IN_Wait1:
        /* During 'Wait1': '<S98>:70' */
        /* '<S98>:71:1' sf_internal_predicateOutput = ... */
        /* '<S98>:71:1' after(100,tick); */
        if ((int16_T)localDW->temporalCounter_i1 >= 100) {
          /* Transition: '<S98>:71' */
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_ChgAngle1;

          /* Entry 'ChgAngle1': '<S98>:73' */
          /* 改变角度 */
          /* '<S98>:73:1' ThetaRTHis = single(ThetaRT); */
          localDW->ThetaRTHis = rtu_Data;
        }
        break;

       default:
        /* During 'Wait3': '<S98>:86' */
        /* '<S98>:84:1' sf_internal_predicateOutput = ... */
        /* '<S98>:84:1' after(100,tick); */
        if ((int16_T)localDW->temporalCounter_i1 >= 100) {
          /* Transition: '<S98>:84' */
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_DecId;

          /* Entry 'DecId': '<S98>:82' */
          /* 减id */
          /* '<S98>:82:1' ThetaDelta = single(ThetaRT) - ThetaRTHis; */
          localDW->ThetaDelta = rtu_Data - localDW->ThetaRTHis;
        } else {
          /* '<S98>:86:1' AngleRefSet = 1.5708; */
          localDW->AngleRefSet = 1.5708F;
        }
        break;
      }
      break;
    }

    if (guard1) {
      /* Transition: '<S98>:201' */
      /* '<S98>:201:1' StudyResult =1; */
      localDW->StudyResult = 1.0F;

      /* '<S98>:201:1' StudyStep=12; */
      localDW->StudyStep = 12U;

      /* Transition: '<S98>:203' */
    }
  }

  /* End of Chart: '<S83>/Chart' */

  /* DataStoreWrite: '<S83>/Data Store Write' */
  AppFun.StudyResult = localDW->StudyResult;

  /* DataStoreWrite: '<S83>/Data Store Write1' */
  AppFun.StudyStep = localDW->StudyStep;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = localDW->IdRefSet;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_h = 0.0F;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = localDW->AngleRefSet;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_a = 1U;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_a3 = 1U;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_at = 0.0F;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_gs = 0.0F;
}

/* System initialize for function-call system: '<S62>/Hall' */
void APP_FluxWeak_GEAR2_Hall_Init(DW_Hall_APP_FluxWeak_GEAR2_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S94>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S80>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S80>/Chart' */
  localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_k;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c27_APP_FluxWeak_GEAR = 0U;
  localDW->is_c27_APP_FluxWeak_GEAR2 = APP_FluxWe_IN_NO_ACTIVE_CHILD_k;
  localDW->StudyResult = 0.0F;
  localDW->IdRefSet = 0.0F;
  localDW->ExSpd = 0.0F;
}

/* System reset for function-call system: '<S62>/Hall' */
void APP_FluxWeak_GEAR2_Hall_Reset(DW_Hall_APP_FluxWeak_GEAR2_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S94>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S80>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_h = 0.0F;

  /* SystemReset for Chart: '<S80>/Chart' */
  localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_k;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c27_APP_FluxWeak_GEAR = 0U;
  localDW->is_c27_APP_FluxWeak_GEAR2 = APP_FluxWe_IN_NO_ACTIVE_CHILD_k;
  localDW->StudyResult = 0.0F;
  localDW->IdRefSet = 0.0F;
  localDW->ExSpd = 0.0F;
}

/* Output and update for function-call system: '<S62>/Hall' */
void APP_FluxWeak_GEAR2_Hall(real32_T rtu_Data, uint16_T *rty_Out1, real32_T
  *rty_Out1_c, real32_T *rty_Out1_h, real32_T *rty_Out1_d, uint16_T *rty_Out1_n,
  uint16_T *rty_Out1_p, real32_T *rty_Out1_db, real32_T *rty_Out1_b,
  DW_Hall_APP_FluxWeak_GEAR2_T *localDW)
{
  /* Chart: '<S80>/Chart' */
  /* Gateway: implement/method/All_loop/Calib/Hall/Chart */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  /* During: implement/method/All_loop/Calib/Hall/Chart */
  if (localDW->is_active_c27_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/Calib/Hall/Chart */
    localDW->is_active_c27_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/Calib/Hall/Chart */
    /* Transition: '<S91>:7' */
    localDW->is_c27_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Init_a;

    /* Entry 'Init': '<S91>:6' */
    /* '<S91>:6:1' StudyResult = 8888; */
    localDW->StudyResult = 8888.0F;
  } else {
    switch (localDW->is_c27_APP_FluxWeak_GEAR2) {
     case APP_FluxWeak_GEAR2_IN_Init_a:
      localDW->StudyResult = 8888.0F;

      /* During 'Init': '<S91>:6' */
      /* '<S91>:11:1' sf_internal_predicateOutput = ... */
      /* '<S91>:11:1' TqReq > 0.01; */
      if (rtu_Data > 0.01) {
        /* Transition: '<S91>:11' */
        localDW->is_c27_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Study_m;

        /* Entry Internal 'Study': '<S91>:8' */
        /* Transition: '<S91>:212' */
        localDW->is_Study = APP_FluxWeak_GEAR2_IN_Wait1_e;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'Wait1': '<S91>:209' */
        /* 等 */
        /* '<S91>:209:1' IdRefSet = 0.3; */
        localDW->IdRefSet = 0.3F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_Stop:
      localDW->StudyResult = 7777.0F;
      localDW->IdRefSet = 0.0F;

      /* During 'Stop': '<S91>:10' */
      break;

     default:
      /* During 'Study': '<S91>:8' */
      /* '<S91>:213:1' sf_internal_predicateOutput = ... */
      /* '<S91>:213:1' abs(TqReq) <0.01; */
      if (fabsf(rtu_Data) < 0.01) {
        /* Transition: '<S91>:213' */
        /* Exit Internal 'Study': '<S91>:8' */
        localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_k;
        localDW->is_c27_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Stop;

        /* Entry 'Stop': '<S91>:10' */
        /* 停止 */
        /* '<S91>:10:1' StudyResult = 7777; */
        localDW->StudyResult = 7777.0F;

        /* '<S91>:10:1' IdRefSet = 0; */
        localDW->IdRefSet = 0.0F;
      } else if (localDW->is_Study == 1U) {
        /* During 'AddId1': '<S91>:205' */
        /* '<S91>:205:1' ExSpd = 20; */
        localDW->ExSpd = 20.0F;
      } else {
        localDW->IdRefSet = 0.3F;

        /* During 'Wait1': '<S91>:209' */
        /* '<S91>:206:1' sf_internal_predicateOutput = ... */
        /* '<S91>:206:1' after(1000,tick); */
        if (localDW->temporalCounter_i1 >= 1000U) {
          /* Transition: '<S91>:206' */
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_AddId1;

          /* Entry 'AddId1': '<S91>:205' */
          /* 增加id */
          /* '<S91>:205:1' ExSpd = 20; */
          localDW->ExSpd = 20.0F;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S80>/Chart' */

  /* DataStoreWrite: '<S80>/Data Store Write' */
  AppFun.StudyResult = localDW->StudyResult;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
   *  DiscreteIntegrator: '<S94>/Discrete-Time Integrator'
   */
  *rty_Out1_c = localDW->DiscreteTimeIntegrator_DSTATE;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_h = 0.0F;

  /* DiscreteIntegrator: '<S80>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S92>/Constant'
   *  RelationalOperator: '<S92>/Compare'
   *  UnitDelay: '<S80>/Unit Delay'
   */
  if (localDW->UnitDelay_DSTATE >= 6.28318548F) {
    localDW->DiscreteTimeIntegrator_DSTATE_i = 0.0F;
  }

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
   *  DiscreteIntegrator: '<S80>/Discrete-Time Integrator'
   */
  *rty_Out1_d = localDW->DiscreteTimeIntegrator_DSTATE_i;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_n = 1U;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_p = 1U;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_db = 0.0F;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_b = 0.0F;

  /* Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S94>/Gain'
   *  Sum: '<S94>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE += (localDW->IdRefSet -
    localDW->DiscreteTimeIntegrator_DSTATE) * 10.0F * 0.002F;

  /* Update for UnitDelay: '<S80>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S80>/Discrete-Time Integrator'
   */
  localDW->UnitDelay_DSTATE = localDW->DiscreteTimeIntegrator_DSTATE_i;

  /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_i += 0.000209439517F *
    localDW->DiscreteTimeIntegrator_DSTATE_h;

  /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S93>/Gain'
   *  Sum: '<S93>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_h += (localDW->ExSpd -
    localDW->DiscreteTimeIntegrator_DSTATE_h) * 5.0F * 0.002F;
}

/*
 * Function for Chart: '<S78>/Chart'
 * function y=Turn(x)
 */
static real32_T APP_FluxWeak_GEAR2_Turn(real32_T x)
{
  real32_T y;

  /* MATLAB Function 'Turn': '<S85>:207' */
  /* Graphical Function 'Turn': '<S85>:207' */
  /* '<S85>:213:1' sf_internal_predicateOutput = ... */
  /* '<S85>:213:1' x>=4096; */
  if (x >= 4096.0F) {
    /* '<S85>:215:1' y=x-4096; */
    y = x - 4096.0F;
  } else {
    /* '<S85>:216:1' sf_internal_predicateOutput = ... */
    /* '<S85>:216:1' x<0; */
    if (x < 0.0F) {
      /* '<S85>:218:1' y=x+4096; */
      y = x + 4096.0F;
    } else {
      /* '<S85>:217:1' y=x; */
      y = x;
    }
  }

  return y;
}

/* Function for Chart: '<S78>/Chart' */
static void APP_Fl_enter_internal_SPEEDFORW(real32_T rtu_Data_n,
  DW_ElecZeroStudy_APP_FluxWeak_T *localDW)
{
  uint16_T qY;

  /* Entry Internal 'SPEEDFORW': '<S85>:97' */
  /* Transition: '<S85>:116' */
  /* '<S85>:119:1' sf_internal_predicateOutput = ... */
  /* '<S85>:119:1' UdFil > 0.03; */
  if (rtu_Data_n > 0.03) {
    /* Transition: '<S85>:119' */
    /* Entry 'Sub1': '<S85>:124' */
    /* '<S85>:124:1' ZeroStudyCnt = 0; */
    localDW->ZeroStudyCnt = 0U;

    /* '<S85>:124:1' CalibZeroPoint = CalibZeroPoint + 4; */
    localDW->CalibZeroPoint += 4.0F;

    /* '<S85>:124:4' CalibZeroPoint=Turn(CalibZeroPoint); */
    localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn(localDW->CalibZeroPoint);

    /* '<S85>:124:5' StudyStep=21; */
    localDW->StudyStep = 21U;
  } else {
    /* Transition: '<S85>:127' */
    /* '<S85>:102:1' sf_internal_predicateOutput = ... */
    /* '<S85>:102:1' UdFil>0; */
    if (rtu_Data_n > 0.0F) {
      /* Transition: '<S85>:102' */
      /* Entry 'Sub2': '<S85>:130' */
      /* '<S85>:130:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
      qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
      if (qY < localDW->ZeroStudyCnt) {
        qY = MAX_uint16_T;
      }

      localDW->ZeroStudyCnt = qY;

      /* '<S85>:130:1' CalibZeroPoint = CalibZeroPoint + 1; */
      localDW->CalibZeroPoint++;

      /* '<S85>:130:4' CalibZeroPoint=Turn(CalibZeroPoint); */
      localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn(localDW->CalibZeroPoint);

      /* '<S85>:130:5' StudyStep=22; */
      localDW->StudyStep = 22U;
    } else {
      /* Transition: '<S85>:100' */
      /* '<S85>:121:1' sf_internal_predicateOutput = ... */
      /* '<S85>:121:1' UdFil > -0.03; */
      if (rtu_Data_n > -0.03) {
        /* Transition: '<S85>:121' */
        /* Entry 'Sub3': '<S85>:111' */
        /* '<S85>:111:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
        qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
        if (qY < localDW->ZeroStudyCnt) {
          qY = MAX_uint16_T;
        }

        localDW->ZeroStudyCnt = qY;

        /* '<S85>:111:1' CalibZeroPoint = CalibZeroPoint - 1; */
        localDW->CalibZeroPoint--;

        /* '<S85>:111:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S85>:111:5' StudyStep=22; */
        localDW->StudyStep = 22U;
      } else {
        /* Transition: '<S85>:113' */
        /* Entry 'Sub4': '<S85>:99' */
        /* '<S85>:99:1' ZeroStudyCnt = 0; */
        localDW->ZeroStudyCnt = 0U;

        /* '<S85>:99:1' CalibZeroPoint = CalibZeroPoint - 4; */
        localDW->CalibZeroPoint -= 4.0F;

        /* '<S85>:99:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S85>:99:5' StudyStep=21; */
        localDW->StudyStep = 21U;
      }
    }
  }
}

/* Function for Chart: '<S78>/Chart' */
static void APP_Flu_enter_internal_SPEEDINV(real32_T rtu_Data_n,
  DW_ElecZeroStudy_APP_FluxWeak_T *localDW)
{
  uint16_T qY;

  /* Entry Internal 'SPEEDINV': '<S85>:98' */
  /* Transition: '<S85>:96' */
  /* '<S85>:125:1' sf_internal_predicateOutput = ... */
  /* '<S85>:125:1' UdFil > 0.03; */
  if (rtu_Data_n > 0.03) {
    /* Transition: '<S85>:125' */
    /* Entry 'Sub1': '<S85>:115' */
    /* '<S85>:115:1' ZeroStudyCnt = 0; */
    localDW->ZeroStudyCnt = 0U;

    /* '<S85>:115:1' CalibZeroPoint = CalibZeroPoint - 4; */
    localDW->CalibZeroPoint -= 4.0F;

    /* '<S85>:115:4' CalibZeroPoint=Turn(CalibZeroPoint); */
    localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn(localDW->CalibZeroPoint);

    /* '<S85>:115:5' StudyStep=21; */
    localDW->StudyStep = 21U;
  } else {
    /* Transition: '<S85>:129' */
    /* '<S85>:110:1' sf_internal_predicateOutput = ... */
    /* '<S85>:110:1' UdFil>0; */
    if (rtu_Data_n > 0.0F) {
      /* Transition: '<S85>:110' */
      /* Entry 'Sub2': '<S85>:112' */
      /* '<S85>:112:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
      qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
      if (qY < localDW->ZeroStudyCnt) {
        qY = MAX_uint16_T;
      }

      localDW->ZeroStudyCnt = qY;

      /* '<S85>:112:1' CalibZeroPoint = CalibZeroPoint - 1; */
      localDW->CalibZeroPoint--;

      /* '<S85>:112:4' CalibZeroPoint=Turn(CalibZeroPoint); */
      localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn(localDW->CalibZeroPoint);

      /* '<S85>:112:5' StudyStep=22; */
      localDW->StudyStep = 22U;
    } else {
      /* Transition: '<S85>:117' */
      /* '<S85>:126:1' sf_internal_predicateOutput = ... */
      /* '<S85>:126:1' UdFil > -0.03; */
      if (rtu_Data_n > -0.03) {
        /* Transition: '<S85>:126' */
        /* Entry 'Sub3': '<S85>:103' */
        /* '<S85>:103:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
        qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
        if (qY < localDW->ZeroStudyCnt) {
          qY = MAX_uint16_T;
        }

        localDW->ZeroStudyCnt = qY;

        /* '<S85>:103:1' CalibZeroPoint = CalibZeroPoint + 1; */
        localDW->CalibZeroPoint++;

        /* '<S85>:103:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S85>:103:5' StudyStep=22; */
        localDW->StudyStep = 22U;
      } else {
        /* Transition: '<S85>:101' */
        /* Entry 'Sub4': '<S85>:128' */
        /* '<S85>:128:1' ZeroStudyCnt = 0; */
        localDW->ZeroStudyCnt = 0U;

        /* '<S85>:128:1' CalibZeroPoint = CalibZeroPoint + 4; */
        localDW->CalibZeroPoint += 4.0F;

        /* '<S85>:128:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S85>:128:5' StudyStep=21; */
        localDW->StudyStep = 21U;
      }
    }
  }
}

/* Function for Chart: '<S78>/Chart' */
static void APP_FluxWeak_GEAR2_Study(real32_T rtu_Data_n, real32_T rtu_Data_j,
  real32_T rtu_Data_o, DW_ElecZeroStudy_APP_FluxWeak_T *localDW)
{
  uint16_T qY;

  /* During 'Study': '<S85>:83' */
  switch (localDW->is_Study) {
   case APP_FluxWeak_GEAR2_IN_Fin:
    /* During 'Fin': '<S85>:133' */
    /* '<S85>:133:1' StudyResult = CalibZeroPoint; */
    localDW->StudyResult = localDW->CalibZeroPoint;

    /* '<S85>:133:1' StudyStep=23; */
    localDW->StudyStep = 23U;
    break;

   case APP_FluxWeak_GEAR2_IN_Fin1_c:
    /* During 'Fin1': '<S85>:194' */
    /* '<S85>:194:1' StudyResult = CalibZeroPoint; */
    localDW->StudyResult = localDW->CalibZeroPoint;

    /* '<S85>:194:1' StudyStep=23; */
    localDW->StudyStep = 23U;
    break;

   case APP_FluxWeak_GEAR2_IN_SPEEDFORW:
    /* Chart: '<S78>/Chart' */
    /* During 'SPEEDFORW': '<S85>:97' */
    /* '<S85>:193:1' sf_internal_predicateOutput = ... */
    /* '<S85>:193:1' abs(UdFil) < 0.01 && ZeroStudyCnt > 200; */
    if ((fabsf(rtu_Data_n) < 0.01) && (localDW->ZeroStudyCnt > 200U)) {
      /* Transition: '<S85>:193' */
      /* Exit Internal 'SPEEDFORW': '<S85>:97' */
      localDW->is_Study = APP_FluxWeak_GEAR2_IN_Fin1_c;

      /* Entry 'Fin1': '<S85>:194' */
      /* 完成 */
      /* '<S85>:194:1' StudyResult = CalibZeroPoint; */
      localDW->StudyResult = localDW->CalibZeroPoint;

      /* '<S85>:194:2' StudyStep=23; */
      localDW->StudyStep = 23U;
    } else {
      /* Transition: '<S85>:231' */
      /* '<S85>:119:1' sf_internal_predicateOutput = ... */
      /* '<S85>:119:1' UdFil > 0.03; */
      if (rtu_Data_n > 0.03) {
        /* Transition: '<S85>:119' */
        /* Exit Internal 'SPEEDFORW': '<S85>:97' */
        /* Entry 'Sub1': '<S85>:124' */
        /* '<S85>:124:1' ZeroStudyCnt = 0; */
        localDW->ZeroStudyCnt = 0U;

        /* '<S85>:124:1' CalibZeroPoint = CalibZeroPoint + 4; */
        localDW->CalibZeroPoint += 4.0F;

        /* '<S85>:124:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S85>:124:5' StudyStep=21; */
        localDW->StudyStep = 21U;
      } else {
        /* Transition: '<S85>:127' */
        /* '<S85>:102:1' sf_internal_predicateOutput = ... */
        /* '<S85>:102:1' UdFil>0; */
        if (rtu_Data_n > 0.0F) {
          /* Transition: '<S85>:102' */
          /* Exit Internal 'SPEEDFORW': '<S85>:97' */
          /* Entry 'Sub2': '<S85>:130' */
          /* '<S85>:130:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
          qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
          if (qY < localDW->ZeroStudyCnt) {
            qY = MAX_uint16_T;
          }

          localDW->ZeroStudyCnt = qY;

          /* '<S85>:130:1' CalibZeroPoint = CalibZeroPoint + 1; */
          localDW->CalibZeroPoint++;

          /* '<S85>:130:4' CalibZeroPoint=Turn(CalibZeroPoint); */
          localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
            (localDW->CalibZeroPoint);

          /* '<S85>:130:5' StudyStep=22; */
          localDW->StudyStep = 22U;
        } else {
          /* Transition: '<S85>:100' */
          /* '<S85>:121:1' sf_internal_predicateOutput = ... */
          /* '<S85>:121:1' UdFil > -0.03; */
          if (rtu_Data_n > -0.03) {
            /* Transition: '<S85>:121' */
            /* Exit Internal 'SPEEDFORW': '<S85>:97' */
            /* Entry 'Sub3': '<S85>:111' */
            /* '<S85>:111:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
            qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
            if (qY < localDW->ZeroStudyCnt) {
              qY = MAX_uint16_T;
            }

            localDW->ZeroStudyCnt = qY;

            /* '<S85>:111:1' CalibZeroPoint = CalibZeroPoint - 1; */
            localDW->CalibZeroPoint--;

            /* '<S85>:111:4' CalibZeroPoint=Turn(CalibZeroPoint); */
            localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
              (localDW->CalibZeroPoint);

            /* '<S85>:111:5' StudyStep=22; */
            localDW->StudyStep = 22U;
          } else {
            /* Transition: '<S85>:113' */
            /* Exit Internal 'SPEEDFORW': '<S85>:97' */
            /* Entry 'Sub4': '<S85>:99' */
            /* '<S85>:99:1' ZeroStudyCnt = 0; */
            localDW->ZeroStudyCnt = 0U;

            /* '<S85>:99:1' CalibZeroPoint = CalibZeroPoint - 4; */
            localDW->CalibZeroPoint -= 4.0F;

            /* '<S85>:99:4' CalibZeroPoint=Turn(CalibZeroPoint); */
            localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
              (localDW->CalibZeroPoint);

            /* '<S85>:99:5' StudyStep=21; */
            localDW->StudyStep = 21U;
          }
        }
      }
    }
    break;

   case APP_FluxWeak_GEAR2_IN_SPEEDINV:
    /* Chart: '<S78>/Chart' */
    /* During 'SPEEDINV': '<S85>:98' */
    /* '<S85>:108:1' sf_internal_predicateOutput = ... */
    /* '<S85>:108:1' abs(UdFil) < 0.01 && ZeroStudyCnt > 200; */
    if ((fabsf(rtu_Data_n) < 0.01) && (localDW->ZeroStudyCnt > 200U)) {
      /* Transition: '<S85>:108' */
      /* Exit Internal 'SPEEDINV': '<S85>:98' */
      localDW->is_Study = APP_FluxWeak_GEAR2_IN_Fin;

      /* Entry 'Fin': '<S85>:133' */
      /* 完成 */
      /* '<S85>:133:1' StudyResult = CalibZeroPoint; */
      localDW->StudyResult = localDW->CalibZeroPoint;

      /* '<S85>:133:2' StudyStep=23; */
      localDW->StudyStep = 23U;
    } else {
      /* Transition: '<S85>:236' */
      /* '<S85>:125:1' sf_internal_predicateOutput = ... */
      /* '<S85>:125:1' UdFil > 0.03; */
      if (rtu_Data_n > 0.03) {
        /* Transition: '<S85>:125' */
        /* Exit Internal 'SPEEDINV': '<S85>:98' */
        /* Entry 'Sub1': '<S85>:115' */
        /* '<S85>:115:1' ZeroStudyCnt = 0; */
        localDW->ZeroStudyCnt = 0U;

        /* '<S85>:115:1' CalibZeroPoint = CalibZeroPoint - 4; */
        localDW->CalibZeroPoint -= 4.0F;

        /* '<S85>:115:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S85>:115:5' StudyStep=21; */
        localDW->StudyStep = 21U;
      } else {
        /* Transition: '<S85>:129' */
        /* '<S85>:110:1' sf_internal_predicateOutput = ... */
        /* '<S85>:110:1' UdFil>0; */
        if (rtu_Data_n > 0.0F) {
          /* Transition: '<S85>:110' */
          /* Exit Internal 'SPEEDINV': '<S85>:98' */
          /* Entry 'Sub2': '<S85>:112' */
          /* '<S85>:112:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
          qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
          if (qY < localDW->ZeroStudyCnt) {
            qY = MAX_uint16_T;
          }

          localDW->ZeroStudyCnt = qY;

          /* '<S85>:112:1' CalibZeroPoint = CalibZeroPoint - 1; */
          localDW->CalibZeroPoint--;

          /* '<S85>:112:4' CalibZeroPoint=Turn(CalibZeroPoint); */
          localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
            (localDW->CalibZeroPoint);

          /* '<S85>:112:5' StudyStep=22; */
          localDW->StudyStep = 22U;
        } else {
          /* Transition: '<S85>:117' */
          /* '<S85>:126:1' sf_internal_predicateOutput = ... */
          /* '<S85>:126:1' UdFil > -0.03; */
          if (rtu_Data_n > -0.03) {
            /* Transition: '<S85>:126' */
            /* Exit Internal 'SPEEDINV': '<S85>:98' */
            /* Entry 'Sub3': '<S85>:103' */
            /* '<S85>:103:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
            qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
            if (qY < localDW->ZeroStudyCnt) {
              qY = MAX_uint16_T;
            }

            localDW->ZeroStudyCnt = qY;

            /* '<S85>:103:1' CalibZeroPoint = CalibZeroPoint + 1; */
            localDW->CalibZeroPoint++;

            /* '<S85>:103:4' CalibZeroPoint=Turn(CalibZeroPoint); */
            localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
              (localDW->CalibZeroPoint);

            /* '<S85>:103:5' StudyStep=22; */
            localDW->StudyStep = 22U;
          } else {
            /* Transition: '<S85>:101' */
            /* Exit Internal 'SPEEDINV': '<S85>:98' */
            /* Entry 'Sub4': '<S85>:128' */
            /* '<S85>:128:1' ZeroStudyCnt = 0; */
            localDW->ZeroStudyCnt = 0U;

            /* '<S85>:128:1' CalibZeroPoint = CalibZeroPoint + 4; */
            localDW->CalibZeroPoint += 4.0F;

            /* '<S85>:128:4' CalibZeroPoint=Turn(CalibZeroPoint); */
            localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
              (localDW->CalibZeroPoint);

            /* '<S85>:128:5' StudyStep=21; */
            localDW->StudyStep = 21U;
          }
        }
      }
    }
    break;

   case APP_FluxWeak_GEAR_IN_ZeroPoint0:
    localDW->IdIqSetEn = 1U;

    /* Chart: '<S78>/Chart' */
    /* During 'ZeroPoint0': '<S85>:89' */
    /* '<S85>:92:1' sf_internal_predicateOutput = ... */
    /* '<S85>:92:1' UsFil > 0.3; */
    if (rtu_Data_j > 0.3) {
      /* Transition: '<S85>:92' */
      /* '<S85>:107:1' sf_internal_predicateOutput = ... */
      /* '<S85>:107:1' PMSM_Param.ResolverDirChg == 1; */
      if (PMSM_Param.ResolverDirChg == 1U) {
        /* Transition: '<S85>:107' */
        localDW->is_Study = APP_FluxWeak_GEAR2_IN_SPEEDINV;

        /* Entry 'SPEEDINV': '<S85>:98' */
        /* 速度反向 */
        APP_Flu_enter_internal_SPEEDINV(rtu_Data_n, localDW);
      } else {
        /* Transition: '<S85>:109' */
        localDW->is_Study = APP_FluxWeak_GEAR2_IN_SPEEDFORW;

        /* Entry 'SPEEDFORW': '<S85>:97' */
        /* 速度正向 */
        APP_Fl_enter_internal_SPEEDFORW(rtu_Data_n, localDW);
      }
    }
    break;

   default:
    /* During 'ZeroPoint1': '<S85>:138' */
    switch (localDW->is_ZeroPoint1) {
     case APP_FluxWeak_GEAR2_IN_AddId_c:
      /* During 'AddId': '<S85>:151' */
      /* '<S85>:142:1' sf_internal_predicateOutput = ... */
      /* '<S85>:142:1' IdRefSet > 0.3; */
      if (localDW->IdRefSet > 0.3) {
        /* Transition: '<S85>:142' */
        localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_Wait1_b;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'Wait1': '<S85>:152' */
        /* 等 */
        /* '<S85>:152:1' IdRefSet = 0.3; */
        localDW->IdRefSet = 0.3F;

        /* '<S85>:152:1' StudyStep=31; */
        localDW->StudyStep = 31U;
      } else {
        /* '<S85>:151:1' IdRefSet = IdRefSet + 0.001; */
        localDW->IdRefSet += 0.001F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_AddIq:
      localDW->AngleSetEn = 0U;

      /* Chart: '<S78>/Chart' */
      /* During 'AddIq': '<S85>:154' */
      /* '<S85>:145:1' sf_internal_predicateOutput = ... */
      /* '<S85>:145:1' UsFil > 0.4 || IqRefSet > 0.3; */
      if ((rtu_Data_j > 0.4) || (localDW->IqRefSet > 0.3)) {
        /* Transition: '<S85>:145' */
        /* '<S85>:148:1' sf_internal_predicateOutput = ... */
        /* '<S85>:148:1' UsFil > 0.4; */
        if (rtu_Data_j > 0.4) {
          /* Transition: '<S85>:148' */
          localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_ClrIq;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'ClrIq': '<S85>:156' */
          /* 清除iq */
          /* '<S85>:156:1' IqRefSet = 0; */
          localDW->IqRefSet = 0.0F;
        } else {
          /* Transition: '<S85>:147' */
          localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_Wait2;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'Wait2': '<S85>:157' */
          /* 增加iq */
          /* '<S85>:157:1' IqRefSet = 0.3; */
          localDW->IqRefSet = 0.3F;
        }
      } else {
        /* '<S85>:154:3' IqRefSet = IqRefSet + 0.001; */
        localDW->IqRefSet += 0.001F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_ClrIq:
      /* During 'ClrIq': '<S85>:156' */
      /* '<S85>:105:1' sf_internal_predicateOutput = ... */
      /* '<S85>:105:1' after(100,tick); */
      if (localDW->temporalCounter_i1 >= 100U) {
        /* Transition: '<S85>:105' */
        /* '<S85>:107:1' sf_internal_predicateOutput = ... */
        /* '<S85>:107:1' PMSM_Param.ResolverDirChg == 1; */
        if (PMSM_Param.ResolverDirChg == 1U) {
          /* Transition: '<S85>:107' */
          localDW->is_ZeroPoint1 = APP_FluxWe_IN_NO_ACTIVE_CHILD_o;
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_SPEEDINV;

          /* Chart: '<S78>/Chart' */
          /* Entry 'SPEEDINV': '<S85>:98' */
          /* 速度反向 */
          APP_Flu_enter_internal_SPEEDINV(rtu_Data_n, localDW);
        } else {
          /* Transition: '<S85>:109' */
          localDW->is_ZeroPoint1 = APP_FluxWe_IN_NO_ACTIVE_CHILD_o;
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_SPEEDFORW;

          /* Chart: '<S78>/Chart' */
          /* Entry 'SPEEDFORW': '<S85>:97' */
          /* 速度正向 */
          APP_Fl_enter_internal_SPEEDFORW(rtu_Data_n, localDW);
        }
      }
      break;

     case APP_FluxWeak_GEAR2_IN_DecId_l:
      /* During 'DecId': '<S85>:153' */
      /* '<S85>:144:1' sf_internal_predicateOutput = ... */
      /* '<S85>:144:1' IdRefSet < 0.002; */
      if (localDW->IdRefSet < 0.002) {
        /* Transition: '<S85>:144' */
        localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_AddIq;

        /* Entry 'AddIq': '<S85>:154' */
        /* 增加iq */
        /* '<S85>:154:1' IdRefSet = 0; */
        localDW->IdRefSet = 0.0F;

        /* '<S85>:154:1' AngleSetEn = 0; */
        localDW->AngleSetEn = 0U;

        /* '<S85>:154:1' StudyStep=33; */
        localDW->StudyStep = 33U;
      } else {
        /* '<S85>:153:3' IdRefSet = IdRefSet - 0.001; */
        localDW->IdRefSet -= 0.001F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_Fault_i:
      /* During 'Fault': '<S85>:155' */
      /* '<S85>:155:1' IqRefSet = 0; */
      localDW->IqRefSet = 0.0F;

      /* '<S85>:155:1' StudyResult = 5555; */
      localDW->StudyResult = 5555.0F;

      /* '<S85>:155:1' StudyStep=36; */
      localDW->StudyStep = 36U;
      break;

     case APP_FluxWeak_GEAR2_IN_Init_du:
      localDW->IdIqSetEn = 1U;
      localDW->AngleSetEn = 1U;

      /* During 'Init': '<S85>:150' */
      /* Transition: '<S85>:141' */
      localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_AddId_c;

      /* Entry 'AddId': '<S85>:151' */
      /* 增加id */
      /* '<S85>:151:1' IdRefSet = IdRefSet + 0.001; */
      localDW->IdRefSet += 0.001F;
      break;

     case APP_FluxWeak_GEAR2_IN_Wait1_b:
      /* During 'Wait1': '<S85>:152' */
      /* '<S85>:143:1' sf_internal_predicateOutput = ... */
      /* '<S85>:143:1' after(100,tick); */
      if (localDW->temporalCounter_i1 >= 100U) {
        /* Transition: '<S85>:143' */
        localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_DecId_l;

        /* Chart: '<S78>/Chart' */
        /* Entry 'DecId': '<S85>:153' */
        /* 减id */
        /* '<S85>:153:1' CalibZeroPoint =single( ThetaRT); */
        localDW->CalibZeroPoint = rtu_Data_o;
      } else {
        /* '<S85>:152:1' IdRefSet = 0.3; */
        localDW->IdRefSet = 0.3F;

        /* '<S85>:152:1' StudyStep=31; */
        localDW->StudyStep = 31U;
      }
      break;

     default:
      /* During 'Wait2': '<S85>:157' */
      /* '<S85>:149:1' sf_internal_predicateOutput = ... */
      /* '<S85>:149:1' after(3000,tick); */
      if (localDW->temporalCounter_i1 >= 3000U) {
        /* Transition: '<S85>:149' */
        localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_Fault_i;

        /* Entry 'Fault': '<S85>:155' */
        /* '<S85>:155:1' IqRefSet = 0; */
        localDW->IqRefSet = 0.0F;

        /* '<S85>:155:1' StudyResult = 5555; */
        localDW->StudyResult = 5555.0F;

        /* '<S85>:155:3' StudyStep=36; */
        localDW->StudyStep = 36U;
      } else {
        /* Chart: '<S78>/Chart' */
        /* '<S85>:146:1' sf_internal_predicateOutput = ... */
        /* '<S85>:146:1' UsFil > 0.4; */
        if (rtu_Data_j > 0.4) {
          /* Transition: '<S85>:146' */
          localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_ClrIq;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'ClrIq': '<S85>:156' */
          /* 清除iq */
          /* '<S85>:156:1' IqRefSet = 0; */
          localDW->IqRefSet = 0.0F;
        } else {
          /* '<S85>:157:1' IqRefSet = 0.3; */
          localDW->IqRefSet = 0.3F;
        }
      }
      break;
    }
    break;
  }
}

/* System initialize for function-call system: '<S62>/ElecZeroStudy' */
void APP_FluxWeak_ElecZeroStudy_Init(DW_ElecZeroStudy_APP_FluxWeak_T *localDW)
{
  /* SystemInitialize for Chart: '<S78>/Chart' */
  localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_o;
  localDW->is_ZeroPoint1 = APP_FluxWe_IN_NO_ACTIVE_CHILD_o;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c11_APP_FluxWeak_GEAR = 0U;
  localDW->is_c11_APP_FluxWeak_GEAR2 = APP_FluxWe_IN_NO_ACTIVE_CHILD_o;
  localDW->ZeroStudyCnt = 0U;
  localDW->StudyResult = 0.0F;
  localDW->IdRefSet = 0.0F;
  localDW->IqRefSet = 0.0F;
  localDW->AngleRefSet = 0.0F;
  localDW->IdIqSetEn = 0U;
  localDW->AngleSetEn = 0U;
  localDW->CalibZeroPoint = 0.0F;
  localDW->StudyStep = 0U;
}

/* Output and update for function-call system: '<S62>/ElecZeroStudy' */
void APP_FluxWeak_GEAR_ElecZeroStudy(uint16_T rtu_Data, real32_T rtu_Data_b,
  real32_T rtu_Data_n, real32_T rtu_Data_j, real32_T rtu_Data_o, uint16_T
  *rty_Out1, real32_T *rty_Out1_b, real32_T *rty_Out1_n, real32_T *rty_Out1_j,
  uint16_T *rty_Out1_o, uint16_T *rty_Out1_j3, real32_T *rty_Out1_k, real32_T
  *rty_Out1_e, DW_ElecZeroStudy_APP_FluxWeak_T *localDW)
{
  /* Chart: '<S78>/Chart' */
  /* Gateway: implement/method/All_loop/Calib/ElecZeroStudy/Chart */
  if (localDW->temporalCounter_i1 < 4095U) {
    localDW->temporalCounter_i1++;
  }

  /* During: implement/method/All_loop/Calib/ElecZeroStudy/Chart */
  if (localDW->is_active_c11_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/Calib/ElecZeroStudy/Chart */
    localDW->is_active_c11_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/Calib/ElecZeroStudy/Chart */
    /* Transition: '<S85>:85' */
    localDW->is_c11_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Init_d;

    /* Entry 'Init': '<S85>:84' */
    /* 初始化 */
    /* '<S85>:84:1' CalibZeroPoint = 0; */
    localDW->CalibZeroPoint = 0.0F;

    /* '<S85>:84:1' StudyResult = 8888; */
    localDW->StudyResult = 8888.0F;

    /* '<S85>:84:3' ZeroStudyCnt = 0; */
    localDW->ZeroStudyCnt = 0U;

    /* '<S85>:84:4' IdIqSetEn = 0; */
    localDW->IdIqSetEn = 0U;

    /* '<S85>:84:5' AngleSetEn = 0; */
    localDW->AngleSetEn = 0U;

    /* '<S85>:84:5' IdRefSet = 0; */
    localDW->IdRefSet = 0.0F;

    /* '<S85>:84:6' IqRefSet = 0; */
    localDW->IqRefSet = 0.0F;

    /* '<S85>:84:7' AngleRefSet = 0; */
    localDW->AngleRefSet = 0.0F;

    /* '<S85>:84:8' StudyStep=20; */
    localDW->StudyStep = 20U;
  } else if (localDW->is_c11_APP_FluxWeak_GEAR2 == 1U) {
    localDW->IdIqSetEn = 0U;
    localDW->AngleSetEn = 0U;
    localDW->AngleRefSet = 0.0F;

    /* During 'Init': '<S85>:84' */
    /* '<S85>:86:1' sf_internal_predicateOutput = ... */
    /* '<S85>:86:1' TqReq > 0.001; */
    if (rtu_Data_b > 0.001) {
      /* Transition: '<S85>:86' */
      localDW->is_c11_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Study_e;

      /* Entry 'Study': '<S85>:83' */
      /* 学习 */
      /* Entry Internal 'Study': '<S85>:83' */
      /* Transition: '<S85>:87' */
      /* '<S85>:90:1' sf_internal_predicateOutput = ... */
      /* '<S85>:90:1' ElecZeroStep ==0; */
      if (rtu_Data == 0U) {
        /* Transition: '<S85>:90' */
        localDW->is_Study = APP_FluxWeak_GEAR_IN_ZeroPoint0;

        /* Entry 'ZeroPoint0': '<S85>:89' */
        /* 被拖 */
        /* '<S85>:89:1' IdIqSetEn = 1; */
        localDW->IdIqSetEn = 1U;
      } else {
        /* Transition: '<S85>:160' */
        localDW->is_Study = APP_FluxWeak_GEAR_IN_ZeroPoint1;

        /* Entry 'ZeroPoint1': '<S85>:138' */
        /* 被拖学习零点 */
        /* Entry Internal 'ZeroPoint1': '<S85>:138' */
        /* Transition: '<S85>:140' */
        localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_Init_du;

        /* Entry 'Init': '<S85>:150' */
        /* 初始化 */
        /* '<S85>:150:1' IdIqSetEn = 1; */
        localDW->IdIqSetEn = 1U;

        /* '<S85>:150:1' AngleSetEn = 1; */
        localDW->AngleSetEn = 1U;

        /* '<S85>:150:1' StudyStep=32; */
        localDW->StudyStep = 32U;
      }
    }
  } else {
    APP_FluxWeak_GEAR2_Study(rtu_Data_n, rtu_Data_j, rtu_Data_o, localDW);
  }

  /* End of Chart: '<S78>/Chart' */

  /* DataStoreWrite: '<S78>/Data Store Write' */
  AppFun.StudyResult = localDW->StudyResult;

  /* DataStoreWrite: '<S78>/Data Store Write1' */
  AppFun.StudyStep = localDW->StudyStep;

  /* SignalConversion: '<S78>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S78>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_b = localDW->IdRefSet;

  /* SignalConversion: '<S78>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_n = localDW->IqRefSet;

  /* SignalConversion: '<S78>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_j = localDW->AngleRefSet;

  /* SignalConversion: '<S78>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_o = localDW->IdIqSetEn;

  /* SignalConversion: '<S78>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_j3 = localDW->AngleSetEn;

  /* SignalConversion: '<S78>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_k = localDW->CalibZeroPoint;

  /* SignalConversion: '<S78>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_e = 0.0F;
}

/* System initialize for function-call system: '<S62>/IdqStudy' */
void APP_FluxWeak_GEAR_IdqStudy_Init(DW_IdqStudy_APP_FluxWeak_GEAR_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_g = 0.0F;
}

/* System reset for function-call system: '<S62>/IdqStudy' */
void APP_FluxWeak_GEA_IdqStudy_Reset(DW_IdqStudy_APP_FluxWeak_GEAR_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_g = 0.0F;
}

/* Output and update for function-call system: '<S62>/IdqStudy' */
void APP_FluxWeak_GEAR2_IdqStudy(real32_T rtu_Data, real32_T rtu_Data_p,
  uint16_T *rty_Out1, real32_T *rty_Out1_p, real32_T *rty_Out1_f, real32_T
  *rty_Out1_g, uint16_T *rty_Out1_o, uint16_T *rty_Out1_i, real32_T *rty_Out1_n,
  real32_T *rty_Out1_d, DW_IdqStudy_APP_FluxWeak_GEAR_T *localDW)
{
  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
   *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator'
   */
  *rty_Out1_p = localDW->DiscreteTimeIntegrator_DSTATE;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   */
  *rty_Out1_f = localDW->DiscreteTimeIntegrator_DSTATE_g;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = 0.0F;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_o = 1U;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = 0U;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_n = 0.0F;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_d = 0.0F;

  /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S95>/Gain'
   *  Sum: '<S95>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE += (rtu_Data -
    localDW->DiscreteTimeIntegrator_DSTATE) * 10.0F * 0.002F;

  /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S96>/Gain'
   *  Sum: '<S96>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_g += (rtu_Data_p -
    localDW->DiscreteTimeIntegrator_DSTATE_g) * 10.0F * 0.002F;
}

/* System initialize for function-call system: '<S62>/FluxLinkage' */
void APP_FluxWeak_G_FluxLinkage_Init(DW_FluxLinkage_APP_FluxWeak_G_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S87>/Delay Input2'
   *
   * Block description for '<S87>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S88>/Delay Input2'
   *
   * Block description for '<S88>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE_g = 0.0F;

  /* SystemInitialize for Chart: '<S79>/Chart' */
  localDW->is_AngCount = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->is_Stop = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->is_work = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c9_APP_FluxWeak_GEAR2 = 0U;
  localDW->CalibAng = 0.0F;
  localDW->IsReq = 0.0F;
}

/* System reset for function-call system: '<S62>/FluxLinkage' */
void APP_FluxWeak__FluxLinkage_Reset(DW_FluxLinkage_APP_FluxWeak_G_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S87>/Delay Input2'
   *
   * Block description for '<S87>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S88>/Delay Input2'
   *
   * Block description for '<S88>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE_g = 0.0F;

  /* SystemReset for Chart: '<S79>/Chart' */
  localDW->is_AngCount = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->is_Stop = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->is_work = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c9_APP_FluxWeak_GEAR2 = 0U;
  localDW->CalibAng = 0.0F;
  localDW->IsReq = 0.0F;
}

/* Output and update for function-call system: '<S62>/FluxLinkage' */
void APP_FluxWeak_GEAR2_FluxLinkage(real32_T rtu_Data, uint16_T *rty_Out1,
  real32_T *rty_Out1_n, real32_T *rty_Out1_i, real32_T *rty_Out1_a, uint16_T
  *rty_Out1_h, uint16_T *rty_Out1_k, real32_T *rty_Out1_c, real32_T *rty_Out1_im,
  DW_FluxLinkage_APP_FluxWeak_G_T *localDW)
{
  real32_T rtb_IdRefSet;
  real32_T rtb_IqRefSet;

  /* Chart: '<S79>/Chart' */
  /* Gateway: implement/method/All_loop/Calib/FluxLinkage/Chart */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  /* During: implement/method/All_loop/Calib/FluxLinkage/Chart */
  if (localDW->is_active_c9_APP_FluxWeak_GEAR2 == 0U) {
    /* Entry: implement/method/All_loop/Calib/FluxLinkage/Chart */
    localDW->is_active_c9_APP_FluxWeak_GEAR2 = 1U;

    /* Entry Internal: implement/method/All_loop/Calib/FluxLinkage/Chart */
    /* Entry Internal 'AngCount': '<S86>:4' */
    /* Transition: '<S86>:9' */
    localDW->is_AngCount = APP_FluxWeak_GEAR2_IN_wait;

    /* Entry 'wait': '<S86>:12' */
    /* '<S86>:12:1' CalibAng=0; */
    localDW->CalibAng = 0.0F;

    /* '<S86>:12:1' IsReq=0; */
    localDW->IsReq = 0.0F;

    /* Entry 'Idq': '<S86>:19' */
    /* '<S86>:19:1' IqRefSet = IsReq * cos(CalibAng); */
    rtb_IqRefSet = localDW->IsReq * cosf(localDW->CalibAng);

    /* '<S86>:19:3' IdRefSet = -abs(IsReq * sin(CalibAng)); */
    rtb_IdRefSet = -fabsf(localDW->IsReq * sinf(localDW->CalibAng));
  } else {
    /* During 'AngCount': '<S86>:4' */
    switch (localDW->is_AngCount) {
     case APP_FluxWeak_GEAR2_IN_Stop_l:
      /* During 'Stop': '<S86>:43' */
      /* '<S86>:43:1' IsReq=0; */
      localDW->IsReq = 0.0F;

      /* '<S86>:43:1' CalibAng=0; */
      localDW->CalibAng = 0.0F;
      if (localDW->is_Stop == 1U) {
        /* During 'stop': '<S86>:46' */
        /* '<S86>:50:1' sf_internal_predicateOutput = ... */
        /* '<S86>:50:1' TqReq==0; */
        if (rtu_Data == 0.0F) {
          /* Transition: '<S86>:50' */
          localDW->is_Stop = APP_FluxWeak_GEAR2_IN_wait;
        }
      } else {
        /* During 'wait': '<S86>:49' */
        /* Transition: '<S86>:54' */
        /* '<S86>:55:1' sf_internal_predicateOutput = ... */
        /* '<S86>:55:1' TqReq>0.01; */
        if (rtu_Data > 0.01) {
          /* Transition: '<S86>:55' */
          localDW->is_Stop = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
          localDW->is_AngCount = APP_FluxWeak_GEAR2_IN_wait;

          /* Entry 'wait': '<S86>:12' */
          /* '<S86>:12:1' CalibAng=0; */
          localDW->CalibAng = 0.0F;

          /* '<S86>:12:1' IsReq=0; */
          localDW->IsReq = 0.0F;
        }
      }
      break;

     case APP_FluxWeak_GEAR2_IN_wait:
      /* During 'wait': '<S86>:12' */
      /* '<S86>:13:1' sf_internal_predicateOutput = ... */
      /* '<S86>:13:1' TqReq>0.01; */
      if (rtu_Data > 0.01) {
        /* Transition: '<S86>:13' */
        /* '<S86>:13:1' CalibAng=PMSM_Param.FLStartAng/180*pi; */
        localDW->CalibAng = PMSM_Param.FLStartAng / 180.0F * 3.14159274F;

        /* '<S86>:13:2' IsReq=0; */
        localDW->IsReq = 0.0F;
        localDW->is_AngCount = APP_FluxWeak_GEAR2_IN_work;
        localDW->is_work = APP_FluxWeak_G_IN_increaseValue;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'increaseValue': '<S86>:8' */
        /* 加 */
      } else {
        /* '<S86>:12:1' CalibAng=0; */
        localDW->CalibAng = 0.0F;

        /* '<S86>:12:1' IsReq=0; */
        localDW->IsReq = 0.0F;
      }
      break;

     default:
      /* During 'work': '<S86>:56' */
      /* '<S86>:58:1' sf_internal_predicateOutput = ... */
      /* '<S86>:58:1' TqReq==0; */
      if (rtu_Data == 0.0F) {
        /* Transition: '<S86>:58' */
        /* Transition: '<S86>:59' */
        /* Exit Internal 'work': '<S86>:56' */
        localDW->is_work = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
        localDW->is_AngCount = APP_FluxWeak_GEAR2_IN_Stop_l;

        /* Entry 'Stop': '<S86>:43' */
        /* '<S86>:43:1' IsReq=0; */
        localDW->IsReq = 0.0F;

        /* '<S86>:43:1' CalibAng=0; */
        localDW->CalibAng = 0.0F;

        /* Entry Internal 'Stop': '<S86>:43' */
        /* Transition: '<S86>:52' */
        localDW->is_Stop = APP_FluxWeak_GEAR2_IN_stop;
      } else if (localDW->is_work == 1U) {
        /* During 'DecreaseValue': '<S86>:20' */
        /* '<S86>:28:1' sf_internal_predicateOutput = ... */
        /* '<S86>:28:1' after(700,tick); */
        if (localDW->temporalCounter_i1 >= 700U) {
          /* Transition: '<S86>:28' */
          /* '<S86>:30:1' sf_internal_predicateOutput = ... */
          /* '<S86>:30:1' IsReq<=0; */
          if (localDW->IsReq <= 0.0F) {
            /* Transition: '<S86>:30' */
            /* Transition: '<S86>:37' */
            /* Transition: '<S86>:44' */
            localDW->is_work = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
            localDW->is_AngCount = APP_FluxWeak_GEAR2_IN_Stop_l;

            /* Entry 'Stop': '<S86>:43' */
            /* '<S86>:43:1' IsReq=0; */
            localDW->IsReq = 0.0F;

            /* '<S86>:43:1' CalibAng=0; */
            localDW->CalibAng = 0.0F;

            /* Entry Internal 'Stop': '<S86>:43' */
            /* Transition: '<S86>:52' */
            localDW->is_Stop = APP_FluxWeak_GEAR2_IN_stop;
          } else {
            /* Transition: '<S86>:32' */
            /* Transition: '<S86>:34' */
            /* '<S86>:34:1' IsReq=IsReq-0.05; */
            localDW->IsReq -= 0.05F;

            /* Transition: '<S86>:35' */
            localDW->is_work = APP_FluxWeak_G_IN_DecreaseValue;
            localDW->temporalCounter_i1 = 0U;

            /* Entry 'DecreaseValue': '<S86>:20' */
            /* 减 */
          }
        }
      } else {
        /* During 'increaseValue': '<S86>:8' */
        /* '<S86>:18:1' sf_internal_predicateOutput = ... */
        /* '<S86>:18:1' after(700,tick); */
        if (localDW->temporalCounter_i1 >= 700U) {
          /* Transition: '<S86>:18' */
          /* '<S86>:21:1' sf_internal_predicateOutput = ... */
          /* '<S86>:21:1' IsReq>=1; */
          if (localDW->IsReq >= 1.0F) {
            /* Transition: '<S86>:21' */
            localDW->is_work = APP_FluxWeak_G_IN_DecreaseValue;
            localDW->temporalCounter_i1 = 0U;

            /* Entry 'DecreaseValue': '<S86>:20' */
            /* 减 */
          } else {
            /* Transition: '<S86>:23' */
            /* Transition: '<S86>:25' */
            /* '<S86>:25:1' IsReq=IsReq+0.05; */
            localDW->IsReq += 0.05F;

            /* Transition: '<S86>:26' */
            localDW->is_work = APP_FluxWeak_G_IN_increaseValue;
            localDW->temporalCounter_i1 = 0U;

            /* Entry 'increaseValue': '<S86>:8' */
            /* 加 */
          }
        }
      }
      break;
    }

    /* During 'Idq': '<S86>:19' */
    /* '<S86>:19:1' IqRefSet = IsReq * cos(CalibAng); */
    rtb_IqRefSet = localDW->IsReq * cosf(localDW->CalibAng);

    /* '<S86>:19:1' IdRefSet = -abs(IsReq * sin(CalibAng)); */
    rtb_IdRefSet = -fabsf(localDW->IsReq * sinf(localDW->CalibAng));
  }

  /* End of Chart: '<S79>/Chart' */

  /* Gain: '<S79>/Gain1' incorporates:
   *  DataStoreWrite: '<S79>/Data Store Write'
   */
  AppFun.StudyResult = 100.0F * localDW->IsReq;

  /* SignalConversion: '<S79>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* Sum: '<S87>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S87>/Delay Input2'
   *
   * Block description for '<S87>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S87>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_IdRefSet -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S89>/Switch2' incorporates:
   *  RelationalOperator: '<S89>/LowerRelop1'
   *  RelationalOperator: '<S89>/UpperRelop'
   *  Switch: '<S89>/Switch'
   */
  if (rtb_IdRefSet > 0.002F) {
    rtb_IdRefSet = 0.002F;
  } else {
    if (rtb_IdRefSet < -0.002F) {
      /* Switch: '<S89>/Switch' */
      rtb_IdRefSet = -0.002F;
    }
  }

  /* End of Switch: '<S89>/Switch2' */

  /* Sum: '<S87>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S87>/Delay Input2'
   *
   * Block description for '<S87>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S87>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_IdRefSet;

  /* SignalConversion: '<S79>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_n = localDW->DelayInput2_DSTATE;

  /* Sum: '<S88>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S88>/Delay Input2'
   *
   * Block description for '<S88>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S88>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_IqRefSet -= localDW->DelayInput2_DSTATE_g;

  /* Switch: '<S90>/Switch2' incorporates:
   *  RelationalOperator: '<S90>/LowerRelop1'
   *  RelationalOperator: '<S90>/UpperRelop'
   *  Switch: '<S90>/Switch'
   */
  if (rtb_IqRefSet > 0.002F) {
    rtb_IqRefSet = 0.002F;
  } else {
    if (rtb_IqRefSet < -0.002F) {
      /* Switch: '<S90>/Switch' */
      rtb_IqRefSet = -0.002F;
    }
  }

  /* End of Switch: '<S90>/Switch2' */

  /* Sum: '<S88>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S88>/Delay Input2'
   *
   * Block description for '<S88>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S88>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE_g += rtb_IqRefSet;

  /* SignalConversion: '<S79>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = localDW->DelayInput2_DSTATE_g;

  /* SignalConversion: '<S79>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_a = 0.0F;

  /* SignalConversion: '<S79>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_h = 1U;

  /* SignalConversion: '<S79>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_k = 0U;

  /* SignalConversion: '<S79>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0.0F;

  /* SignalConversion: '<S79>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_im = 0.0F;
}

/* System initialize for function-call system: '<S62>/MtpaStudy' */
void APP_FluxWeak_GEA_MtpaStudy_Init(DW_MtpaStudy_APP_FluxWeak_GEA_T *localDW)
{
  /* SystemInitialize for Chart: '<S82>/Chart' */
  localDW->is_Mtpa = APP_FluxWe_IN_NO_ACTIVE_CHILD_i;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c26_APP_FluxWeak_GEAR = 0U;
  localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWe_IN_NO_ACTIVE_CHILD_i;
  localDW->count = 0U;
  localDW->IsRef = 0.0F;
  localDW->AngRef = 0.0F;
}

/* Output and update for function-call system: '<S62>/MtpaStudy' */
void APP_FluxWeak_GEAR2_MtpaStudy(real32_T rtu_Data, real32_T rtu_Data_c,
  real32_T rtu_Data_p, uint16_T *rty_Out1, real32_T *rty_Out1_c, real32_T
  *rty_Out1_p, real32_T *rty_Out1_l, uint16_T *rty_Out1_m, uint16_T *rty_Out1_f,
  real32_T *rty_Out1_h, real32_T *rty_Out1_cv, DW_MtpaStudy_APP_FluxWeak_GEA_T
  *localDW)
{
  uint16_T qY;
  boolean_T guard1 = false;

  /* Chart: '<S82>/Chart' */
  /* Gateway: implement/method/All_loop/Calib/MtpaStudy/Chart */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  /* During: implement/method/All_loop/Calib/MtpaStudy/Chart */
  if (localDW->is_active_c26_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/Calib/MtpaStudy/Chart */
    localDW->is_active_c26_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/Calib/MtpaStudy/Chart */
    /* Transition: '<S97>:5' */
    localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Prepare;

    /* Entry 'Prepare': '<S97>:12' */
    /* '<S97>:12:1' IsRef=0; */
    localDW->IsRef = 0.0F;
  } else {
    guard1 = false;
    switch (localDW->is_c26_APP_FluxWeak_GEAR2) {
     case APP_FluxWeak_GEAR_IN_IsDecrease:
      /* During 'IsDecrease': '<S97>:46' */
      /* Transition: '<S97>:51' */
      /* '<S97>:52:1' sf_internal_predicateOutput = ... */
      /* '<S97>:52:1' IsRef<0.001; */
      if (localDW->IsRef < 0.001) {
        /* Transition: '<S97>:52' */
        localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Prepare;

        /* Entry 'Prepare': '<S97>:12' */
        /* '<S97>:12:1' IsRef=0; */
        localDW->IsRef = 0.0F;
      } else {
        /* Transition: '<S97>:54' */
        /* Transition: '<S97>:55' */
        localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR_IN_IsDecrease;

        /* Entry 'IsDecrease': '<S97>:46' */
        /* '<S97>:46:1' IsRef=IsRef-0.001; */
        localDW->IsRef -= 0.001F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_Mtpa:
      /* During 'Mtpa': '<S97>:4' */
      /* '<S97>:15:1' sf_internal_predicateOutput = ... */
      /* '<S97>:15:1' CalibTq2<0.01; */
      if (rtu_Data < 0.01) {
        /* Transition: '<S97>:15' */
        /* Exit Internal 'Mtpa': '<S97>:4' */
        localDW->is_Mtpa = APP_FluxWe_IN_NO_ACTIVE_CHILD_i;
        localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR_IN_IsDecrease;

        /* Entry 'IsDecrease': '<S97>:46' */
        /* '<S97>:46:1' IsRef=IsRef-0.001; */
        localDW->IsRef -= 0.001F;
      } else {
        switch (localDW->is_Mtpa) {
         case APP_FluxWeak_G_IN_AngleIncrease:
          /* During 'AngleIncrease': '<S97>:31' */
          /* Transition: '<S97>:64' */
          /* '<S97>:61:1' sf_internal_predicateOutput = ... */
          /* '<S97>:61:1' count<15; */
          if (localDW->count < 15U) {
            /* Transition: '<S97>:61' */
            guard1 = true;
          } else {
            /* Transition: '<S97>:67' */
            /* '<S97>:41:1' sf_internal_predicateOutput = ... */
            /* '<S97>:41:1' AngRef>=pi/2; */
            if (localDW->AngRef >= 1.5707963267948966) {
              /* Transition: '<S97>:41' */
              localDW->is_Mtpa = APP_FluxWeak_GEAR2_IN_Qaxis;
            } else {
              /* '<S97>:43:1' sf_internal_predicateOutput = ... */
              /* '<S97>:43:1' after(1000,tick); */
              if (localDW->temporalCounter_i1 >= 1000U) {
                /* Transition: '<S97>:43' */
                /* Transition: '<S97>:49' */
                /* '<S97>:49:1' count=0; */
                localDW->count = 0U;
                guard1 = true;
              }
            }
          }
          break;

         case APP_FluxWeak_GEAR_IN_FirstPoint:
          /* During 'FirstPoint': '<S97>:68' */
          /* '<S97>:69:1' sf_internal_predicateOutput = ... */
          /* '<S97>:69:1' after(1000,tick); */
          if (localDW->temporalCounter_i1 >= 1000U) {
            /* Transition: '<S97>:69' */
            localDW->is_Mtpa = APP_FluxWeak_G_IN_AngleIncrease;
            localDW->temporalCounter_i1 = 0U;

            /* Entry 'AngleIncrease': '<S97>:31' */
            /* 加角度 */
            /* '<S97>:31:1' AngRef=AngRef+0.1/180*pi; */
            localDW->AngRef += 0.00174532924F;

            /* '<S97>:31:1' count=count+1; */
            qY = localDW->count + /*MW:OvSatOk*/ 1U;
            if (qY < localDW->count) {
              qY = MAX_uint16_T;
            }

            localDW->count = qY;
          }
          break;

         case APP_FluxWeak_GEAR_IN_IsIncrease:
          /* During 'IsIncrease': '<S97>:17' */
          /* Transition: '<S97>:30' */
          /* '<S97>:32:1' sf_internal_predicateOutput = ... */
          /* '<S97>:32:1' IsRef>=TqReq; */
          if (localDW->IsRef >= rtu_Data_c) {
            /* Transition: '<S97>:32' */
            localDW->is_Mtpa = APP_FluxWeak_GEAR_IN_FirstPoint;
            localDW->temporalCounter_i1 = 0U;
          } else {
            /* Transition: '<S97>:34' */
            /* Transition: '<S97>:36' */
            /* Transition: '<S97>:37' */
            localDW->is_Mtpa = APP_FluxWeak_GEAR_IN_IsIncrease;

            /* Entry 'IsIncrease': '<S97>:17' */
            /* 加Is */
            /* '<S97>:17:1' IsRef=IsRef+0.001; */
            localDW->IsRef += 0.001F;
          }
          break;

         default:
          /* During 'Qaxis': '<S97>:23' */
          /* Transition: '<S97>:56' */
          localDW->is_Mtpa = APP_FluxWe_IN_NO_ACTIVE_CHILD_i;
          localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR_IN_IsDecrease;

          /* Entry 'IsDecrease': '<S97>:46' */
          /* '<S97>:46:1' IsRef=IsRef-0.001; */
          localDW->IsRef -= 0.001F;
          break;
        }
      }
      break;

     default:
      /* During 'Prepare': '<S97>:12' */
      /* '<S97>:13:1' sf_internal_predicateOutput = ... */
      /* '<S97>:13:1' CalibTq2>0.01; */
      if (rtu_Data > 0.01) {
        /* Transition: '<S97>:13' */
        /* '<S97>:13:1' AngRef=CalibMTPATheta; */
        localDW->AngRef = rtu_Data_p;

        /* '<S97>:13:1' count=0; */
        localDW->count = 0U;
        localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Mtpa;

        /* Entry Internal 'Mtpa': '<S97>:4' */
        /* Transition: '<S97>:18' */
        localDW->is_Mtpa = APP_FluxWeak_GEAR_IN_IsIncrease;

        /* Entry 'IsIncrease': '<S97>:17' */
        /* 加Is */
        /* '<S97>:17:1' IsRef=IsRef+0.001; */
        localDW->IsRef += 0.001F;
      } else {
        /* '<S97>:12:1' IsRef=0; */
        localDW->IsRef = 0.0F;
      }
      break;
    }

    if (guard1) {
      /* Transition: '<S97>:66' */
      /* Transition: '<S97>:47' */
      localDW->is_Mtpa = APP_FluxWeak_G_IN_AngleIncrease;
      localDW->temporalCounter_i1 = 0U;

      /* Entry 'AngleIncrease': '<S97>:31' */
      /* 加角度 */
      /* '<S97>:31:1' AngRef=AngRef+0.1/180*pi; */
      localDW->AngRef += 0.00174532924F;

      /* '<S97>:31:1' count=count+1; */
      qY = localDW->count + /*MW:OvSatOk*/ 1U;
      if (qY < localDW->count) {
        qY = MAX_uint16_T;
      }

      localDW->count = qY;
    }
  }

  /* End of Chart: '<S82>/Chart' */

  /* Gain: '<S82>/Gain1' incorporates:
   *  DataStoreWrite: '<S82>/Data Store Write'
   */
  AppFun.StudyResult = 57.2957802F * localDW->AngRef;

  /* Gain: '<S82>/Gain' incorporates:
   *  Product: '<S82>/Product'
   *  Trigonometry: '<S82>/Trigonometric Function'
   */
  *rty_Out1_c = -(localDW->IsRef * sinf(localDW->AngRef));

  /* Product: '<S82>/Product1' incorporates:
   *  Trigonometry: '<S82>/Trigonometric Function1'
   */
  *rty_Out1_p = localDW->IsRef * cosf(localDW->AngRef);

  /* SignalConversion: '<S82>/TmpBufferAtConstant2Outport1' incorporates:
   *  Constant: '<S82>/Constant2'
   */
  *rty_Out1_l = 0.0F;

  /* SignalConversion: '<S82>/TmpBufferAtConstant3Outport1' incorporates:
   *  Constant: '<S82>/Constant3'
   */
  *rty_Out1_m = 1U;

  /* SignalConversion: '<S82>/TmpBufferAtConstant4Outport1' incorporates:
   *  Constant: '<S82>/Constant4'
   */
  *rty_Out1_f = 0U;

  /* SignalConversion: '<S82>/TmpBufferAtConstant5Outport1' incorporates:
   *  Constant: '<S82>/Constant5'
   */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S82>/TmpBufferAtConstant7Outport1' incorporates:
   *  Constant: '<S82>/Constant7'
   */
  *rty_Out1_h = 0.0F;

  /* SignalConversion: '<S82>/TmpBufferAtConstant8Outport1' incorporates:
   *  Constant: '<S82>/Constant8'
   */
  *rty_Out1_cv = 0.0F;
}

/* Output and update for function-call system: '<S62>/Tlin' */
void APP_FluxWeak_GEAR2_Tlin(real32_T rtu_Data, uint16_T *rty_Out1, real32_T
  *rty_Out1_o, real32_T *rty_Out1_k, real32_T *rty_Out1_oy, uint16_T *rty_Out1_p,
  uint16_T *rty_Out1_d, real32_T *rty_Out1_km, real32_T *rty_Out1_i)
{
  /* SignalConversion: '<S84>/TmpLatchAtDataOutport1' */
  *rty_Out1_i = rtu_Data;

  /* SignalConversion: '<S84>/TmpBufferAtConstant1Outport1' incorporates:
   *  Constant: '<S84>/Constant1'
   */
  *rty_Out1_k = 0.0F;

  /* SignalConversion: '<S84>/TmpBufferAtConstant2Outport1' incorporates:
   *  Constant: '<S84>/Constant2'
   */
  *rty_Out1_oy = 0.0F;

  /* SignalConversion: '<S84>/TmpBufferAtConstant3Outport1' incorporates:
   *  Constant: '<S84>/Constant3'
   */
  *rty_Out1_p = 1U;

  /* SignalConversion: '<S84>/TmpBufferAtConstant4Outport1' incorporates:
   *  Constant: '<S84>/Constant4'
   */
  *rty_Out1_d = 0U;

  /* SignalConversion: '<S84>/TmpBufferAtConstant5Outport1' incorporates:
   *  Constant: '<S84>/Constant5'
   */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S84>/TmpBufferAtConstant7Outport1' incorporates:
   *  Constant: '<S84>/Constant7'
   */
  *rty_Out1_km = 0.0F;

  /* SignalConversion: '<S84>/TmpBufferAtConstantOutport1' incorporates:
   *  Constant: '<S84>/Constant'
   */
  *rty_Out1_o = 0.0F;
}

/* System initialize for function-call system: '<S54>/Calib' */
void APP_FluxWeak_GEAR2_Calib_Init(DW_Calib_APP_FluxWeak_GEAR2_T *localDW)
{
  localDW->is_Sel_mode = APP_FluxW_IN_NO_ACTIVE_CHILD_km;
  localDW->is_active_c15_APP_FluxWeak_GEAR = 0U;

  /* SystemInitialize for Chart: '<S62>/Chart1' incorporates:
   *  SubSystem: '<S62>/PhaseStudy'
   */
  APP_FluxWeak_GE_PhaseStudy_Init(&localDW->PhaseStudy);

  /* SystemInitialize for Chart: '<S62>/Chart1' incorporates:
   *  SubSystem: '<S62>/Hall'
   */
  APP_FluxWeak_GEAR2_Hall_Init(&localDW->Hall);

  /* SystemInitialize for Chart: '<S62>/Chart1' incorporates:
   *  SubSystem: '<S62>/ElecZeroStudy'
   */
  APP_FluxWeak_ElecZeroStudy_Init(&localDW->ElecZeroStudy);

  /* SystemInitialize for Chart: '<S62>/Chart1' incorporates:
   *  SubSystem: '<S62>/IdqStudy'
   */
  APP_FluxWeak_GEAR_IdqStudy_Init(&localDW->IdqStudy);

  /* SystemInitialize for Chart: '<S62>/Chart1' incorporates:
   *  SubSystem: '<S62>/FluxLinkage'
   */
  APP_FluxWeak_G_FluxLinkage_Init(&localDW->FluxLinkage);

  /* SystemInitialize for Chart: '<S62>/Chart1' incorporates:
   *  SubSystem: '<S62>/MtpaStudy'
   */
  APP_FluxWeak_GEA_MtpaStudy_Init(&localDW->MtpaStudy);
}

/* System reset for function-call system: '<S54>/Calib' */
void APP_FluxWeak_GEAR2_Calib_Reset(DW_Calib_APP_FluxWeak_GEAR2_T *localDW)
{
  /* SystemReset for Chart: '<S62>/Chart1' */
  localDW->is_Sel_mode = APP_FluxW_IN_NO_ACTIVE_CHILD_km;
  localDW->is_active_c15_APP_FluxWeak_GEAR = 0U;
}

/* Enable for function-call system: '<S54>/Calib' */
void APP_FluxWeak_GEAR2_Calib_Enable(DW_Calib_APP_FluxWeak_GEAR2_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S62>/Hall' */

  /* Enable for Chart: '<S62>/Chart1' */
  APP_FluxWeak_GEAR2_Hall_Reset(&localDW->Hall);

  /* End of SystemReset for SubSystem: '<S62>/Hall' */

  /* SystemReset for Function Call SubSystem: '<S62>/IdqStudy' */
  APP_FluxWeak_GEA_IdqStudy_Reset(&localDW->IdqStudy);

  /* End of SystemReset for SubSystem: '<S62>/IdqStudy' */

  /* SystemReset for Function Call SubSystem: '<S62>/FluxLinkage' */
  APP_FluxWeak__FluxLinkage_Reset(&localDW->FluxLinkage);

  /* End of SystemReset for SubSystem: '<S62>/FluxLinkage' */
}

/* Output and update for function-call system: '<S54>/Calib' */
void APP_FluxWeak_GEAR2_Calib(uint16_T rtu_Data, real32_T rtu_Data_h, real32_T
  rtu_Data_b, uint16_T rtu_Data_c, real32_T rtu_Data_g, real32_T rtu_Data_hs,
  real32_T rtu_Data_l, real32_T rtu_Data_e, uint16_T *rty_Out1, real32_T
  *rty_Out1_h, real32_T *rty_Out1_b, real32_T *rty_Out1_c, uint16_T *rty_Out1_g,
  uint16_T *rty_Out1_hs, real32_T *rty_Out1_l, real32_T *rty_Out1_e,
  DW_Calib_APP_FluxWeak_GEAR2_T *localDW)
{
  uint16_T CalibStep_prev;

  /* Chart: '<S62>/Chart1' */
  /* Gateway: implement/method/All_loop/Calib/Chart1 */
  CalibStep_prev = localDW->CalibStep_start;
  localDW->CalibStep_start = rtu_Data;

  /* During: implement/method/All_loop/Calib/Chart1 */
  if (localDW->is_active_c15_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/Calib/Chart1 */
    localDW->is_active_c15_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/Calib/Chart1 */
    /* Entry Internal 'Sel_mode': '<S77>:2' */
    /* Transition: '<S77>:23' */
    /* '<S77>:9:1' sf_internal_predicateOutput = ... */
    /* '<S77>:9:1' CalibStep==1; */
    switch (rtu_Data) {
     case 1U:
      /* Transition: '<S77>:9' */
      localDW->is_Sel_mode = APP_FluxWeak_GEAR_IN_PhaseStudy;

      /* Outputs for Function Call SubSystem: '<S62>/PhaseStudy' */

      /* Entry 'PhaseStudy': '<S77>:31' */
      /* '<S77>:31:1' PhaseStudy; */
      /* Event: '<S77>:32' */
      APP_FluxWeak_GEAR2_PhaseStudy(rtu_Data_h, rtu_Data_b, rty_Out1, rty_Out1_h,
        rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
        &localDW->PhaseStudy);

      /* End of Outputs for SubSystem: '<S62>/PhaseStudy' */
      break;

     case 2U:
      /* Transition: '<S77>:6' */
      /* '<S77>:24:1' sf_internal_predicateOutput = ... */
      /* '<S77>:24:1' CalibStep==2; */
      /* Transition: '<S77>:24' */
      localDW->is_Sel_mode = APP_FluxWeak_G_IN_ElecZeroStudy;

      /* Outputs for Function Call SubSystem: '<S62>/Hall' */

      /* Entry 'ElecZeroStudy': '<S77>:37' */
      /* '<S77>:37:1' Hall; */
      /* Event: '<S77>:55' */
      APP_FluxWeak_GEAR2_Hall(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
        rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
        &localDW->Hall);

      /* End of Outputs for SubSystem: '<S62>/Hall' */
      break;

     case 3U:
      /* Transition: '<S77>:21' */
      /* '<S77>:12:1' sf_internal_predicateOutput = ... */
      /* '<S77>:12:1' CalibStep==3; */
      /* Transition: '<S77>:12' */
      localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_IfStudy;

      /* Outputs for Function Call SubSystem: '<S62>/ElecZeroStudy' */

      /* Entry 'IfStudy': '<S77>:39' */
      /* '<S77>:39:1' ElecZeroStudy; */
      /* Event: '<S77>:49' */
      APP_FluxWeak_GEAR_ElecZeroStudy(rtu_Data_c, rtu_Data_b, rtu_Data_g,
        rtu_Data_hs, rtu_Data_h, rty_Out1, rty_Out1_h, rty_Out1_b, rty_Out1_c,
        rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e, &localDW->ElecZeroStudy);

      /* End of Outputs for SubSystem: '<S62>/ElecZeroStudy' */
      break;

     case 4U:
      /* Transition: '<S77>:22' */
      /* '<S77>:10:1' sf_internal_predicateOutput = ... */
      /* '<S77>:10:1' CalibStep==4; */
      /* Transition: '<S77>:10' */
      localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_LdStudy;

      /* Outputs for Function Call SubSystem: '<S62>/IdqStudy' */

      /* Entry 'LdStudy': '<S77>:41' */
      /* '<S77>:41:1' IdqStudy; */
      /* Event: '<S77>:50' */
      APP_FluxWeak_GEAR2_IdqStudy(rtu_Data_b, rtu_Data_l, rty_Out1, rty_Out1_h,
        rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
        &localDW->IdqStudy);

      /* End of Outputs for SubSystem: '<S62>/IdqStudy' */
      break;

     case 5U:
      /* Transition: '<S77>:27' */
      /* '<S77>:25:1' sf_internal_predicateOutput = ... */
      /* '<S77>:25:1' CalibStep==5; */
      /* Transition: '<S77>:25' */
      localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_MtpaStudy;

      /* Outputs for Function Call SubSystem: '<S62>/FluxLinkage' */

      /* Entry 'MtpaStudy': '<S77>:43' */
      /* '<S77>:43:1' FluxLinkage; */
      /* Event: '<S77>:53' */
      APP_FluxWeak_GEAR2_FluxLinkage(rtu_Data_b, rty_Out1, rty_Out1_h,
        rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
        &localDW->FluxLinkage);

      /* End of Outputs for SubSystem: '<S62>/FluxLinkage' */
      break;

     case 6U:
      /* Transition: '<S77>:13' */
      /* '<S77>:28:1' sf_internal_predicateOutput = ... */
      /* '<S77>:28:1' CalibStep==6; */
      /* Transition: '<S77>:28' */
      localDW->is_Sel_mode = APP_FluxWeak_IN_IsMax_TLinStudy;

      /* Outputs for Function Call SubSystem: '<S62>/MtpaStudy' */

      /* Entry 'IsMax_TLinStudy': '<S77>:45' */
      /* '<S77>:45:1' MTPA; */
      /* Event: '<S77>:51' */
      APP_FluxWeak_GEAR2_MtpaStudy(rtu_Data_l, rtu_Data_b, rtu_Data_e, rty_Out1,
        rty_Out1_h, rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l,
        rty_Out1_e, &localDW->MtpaStudy);

      /* End of Outputs for SubSystem: '<S62>/MtpaStudy' */
      break;

     default:
      /* Transition: '<S77>:26' */
      /* Transition: '<S77>:18' */
      localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_Normal;

      /* Outputs for Function Call SubSystem: '<S62>/Tlin' */

      /* Entry 'Normal': '<S77>:47' */
      /* '<S77>:47:1' Normal; */
      /* Event: '<S77>:54' */
      APP_FluxWeak_GEAR2_Tlin(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
        rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e);

      /* End of Outputs for SubSystem: '<S62>/Tlin' */
      break;
    }
  } else {
    /* During 'Sel_mode': '<S77>:2' */
    /* '<S77>:57:1' sf_internal_predicateOutput = ... */
    /* '<S77>:57:1' hasChanged(CalibStep); */
    if (CalibStep_prev != localDW->CalibStep_start) {
      /* Transition: '<S77>:57' */
      /* '<S77>:9:1' sf_internal_predicateOutput = ... */
      /* '<S77>:9:1' CalibStep==1; */
      switch (rtu_Data) {
       case 1U:
        /* Transition: '<S77>:9' */
        /* Exit Internal 'Sel_mode': '<S77>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_GEAR_IN_PhaseStudy;

        /* Outputs for Function Call SubSystem: '<S62>/PhaseStudy' */

        /* Entry 'PhaseStudy': '<S77>:31' */
        /* '<S77>:31:1' PhaseStudy; */
        /* Event: '<S77>:32' */
        APP_FluxWeak_GEAR2_PhaseStudy(rtu_Data_h, rtu_Data_b, rty_Out1,
          rty_Out1_h, rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs,
          rty_Out1_l, rty_Out1_e, &localDW->PhaseStudy);

        /* End of Outputs for SubSystem: '<S62>/PhaseStudy' */
        break;

       case 2U:
        /* Transition: '<S77>:6' */
        /* '<S77>:24:1' sf_internal_predicateOutput = ... */
        /* '<S77>:24:1' CalibStep==2; */
        /* Transition: '<S77>:24' */
        /* Exit Internal 'Sel_mode': '<S77>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_G_IN_ElecZeroStudy;

        /* Outputs for Function Call SubSystem: '<S62>/Hall' */

        /* Entry 'ElecZeroStudy': '<S77>:37' */
        /* '<S77>:37:1' Hall; */
        /* Event: '<S77>:55' */
        APP_FluxWeak_GEAR2_Hall(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
          rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
          &localDW->Hall);

        /* End of Outputs for SubSystem: '<S62>/Hall' */
        break;

       case 3U:
        /* Transition: '<S77>:21' */
        /* '<S77>:12:1' sf_internal_predicateOutput = ... */
        /* '<S77>:12:1' CalibStep==3; */
        /* Transition: '<S77>:12' */
        /* Exit Internal 'Sel_mode': '<S77>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_IfStudy;

        /* Outputs for Function Call SubSystem: '<S62>/ElecZeroStudy' */

        /* Entry 'IfStudy': '<S77>:39' */
        /* '<S77>:39:1' ElecZeroStudy; */
        /* Event: '<S77>:49' */
        APP_FluxWeak_GEAR_ElecZeroStudy(rtu_Data_c, rtu_Data_b, rtu_Data_g,
          rtu_Data_hs, rtu_Data_h, rty_Out1, rty_Out1_h, rty_Out1_b, rty_Out1_c,
          rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
          &localDW->ElecZeroStudy);

        /* End of Outputs for SubSystem: '<S62>/ElecZeroStudy' */
        break;

       case 4U:
        /* Transition: '<S77>:22' */
        /* '<S77>:10:1' sf_internal_predicateOutput = ... */
        /* '<S77>:10:1' CalibStep==4; */
        /* Transition: '<S77>:10' */
        /* Exit Internal 'Sel_mode': '<S77>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_LdStudy;

        /* Outputs for Function Call SubSystem: '<S62>/IdqStudy' */

        /* Entry 'LdStudy': '<S77>:41' */
        /* '<S77>:41:1' IdqStudy; */
        /* Event: '<S77>:50' */
        APP_FluxWeak_GEAR2_IdqStudy(rtu_Data_b, rtu_Data_l, rty_Out1, rty_Out1_h,
          rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l,
          rty_Out1_e, &localDW->IdqStudy);

        /* End of Outputs for SubSystem: '<S62>/IdqStudy' */
        break;

       case 5U:
        /* Transition: '<S77>:27' */
        /* '<S77>:25:1' sf_internal_predicateOutput = ... */
        /* '<S77>:25:1' CalibStep==5; */
        /* Transition: '<S77>:25' */
        /* Exit Internal 'Sel_mode': '<S77>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_MtpaStudy;

        /* Outputs for Function Call SubSystem: '<S62>/FluxLinkage' */

        /* Entry 'MtpaStudy': '<S77>:43' */
        /* '<S77>:43:1' FluxLinkage; */
        /* Event: '<S77>:53' */
        APP_FluxWeak_GEAR2_FluxLinkage(rtu_Data_b, rty_Out1, rty_Out1_h,
          rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l,
          rty_Out1_e, &localDW->FluxLinkage);

        /* End of Outputs for SubSystem: '<S62>/FluxLinkage' */
        break;

       case 6U:
        /* Transition: '<S77>:13' */
        /* '<S77>:28:1' sf_internal_predicateOutput = ... */
        /* '<S77>:28:1' CalibStep==6; */
        /* Transition: '<S77>:28' */
        /* Exit Internal 'Sel_mode': '<S77>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_IN_IsMax_TLinStudy;

        /* Outputs for Function Call SubSystem: '<S62>/MtpaStudy' */

        /* Entry 'IsMax_TLinStudy': '<S77>:45' */
        /* '<S77>:45:1' MTPA; */
        /* Event: '<S77>:51' */
        APP_FluxWeak_GEAR2_MtpaStudy(rtu_Data_l, rtu_Data_b, rtu_Data_e,
          rty_Out1, rty_Out1_h, rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs,
          rty_Out1_l, rty_Out1_e, &localDW->MtpaStudy);

        /* End of Outputs for SubSystem: '<S62>/MtpaStudy' */
        break;

       default:
        /* Transition: '<S77>:26' */
        /* Transition: '<S77>:18' */
        /* Exit Internal 'Sel_mode': '<S77>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_Normal;

        /* Outputs for Function Call SubSystem: '<S62>/Tlin' */

        /* Entry 'Normal': '<S77>:47' */
        /* '<S77>:47:1' Normal; */
        /* Event: '<S77>:54' */
        APP_FluxWeak_GEAR2_Tlin(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
          rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e);

        /* End of Outputs for SubSystem: '<S62>/Tlin' */
        break;
      }
    } else {
      switch (localDW->is_Sel_mode) {
       case APP_FluxWeak_G_IN_ElecZeroStudy:
        /* Outputs for Function Call SubSystem: '<S62>/Hall' */

        /* During 'ElecZeroStudy': '<S77>:37' */
        /* '<S77>:37:1' Hall; */
        /* Event: '<S77>:55' */
        APP_FluxWeak_GEAR2_Hall(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
          rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
          &localDW->Hall);

        /* End of Outputs for SubSystem: '<S62>/Hall' */
        break;

       case APP_FluxWeak_GEAR2_IN_IfStudy:
        /* Outputs for Function Call SubSystem: '<S62>/ElecZeroStudy' */

        /* During 'IfStudy': '<S77>:39' */
        /* '<S77>:39:1' ElecZeroStudy; */
        /* Event: '<S77>:49' */
        APP_FluxWeak_GEAR_ElecZeroStudy(rtu_Data_c, rtu_Data_b, rtu_Data_g,
          rtu_Data_hs, rtu_Data_h, rty_Out1, rty_Out1_h, rty_Out1_b, rty_Out1_c,
          rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
          &localDW->ElecZeroStudy);

        /* End of Outputs for SubSystem: '<S62>/ElecZeroStudy' */
        break;

       case APP_FluxWeak_IN_IsMax_TLinStudy:
        /* Outputs for Function Call SubSystem: '<S62>/MtpaStudy' */

        /* During 'IsMax_TLinStudy': '<S77>:45' */
        /* '<S77>:45:1' MTPA; */
        /* Event: '<S77>:51' */
        APP_FluxWeak_GEAR2_MtpaStudy(rtu_Data_l, rtu_Data_b, rtu_Data_e,
          rty_Out1, rty_Out1_h, rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs,
          rty_Out1_l, rty_Out1_e, &localDW->MtpaStudy);

        /* End of Outputs for SubSystem: '<S62>/MtpaStudy' */
        break;

       case APP_FluxWeak_GEAR2_IN_LdStudy:
        /* Outputs for Function Call SubSystem: '<S62>/IdqStudy' */

        /* During 'LdStudy': '<S77>:41' */
        /* '<S77>:41:1' IdqStudy; */
        /* Event: '<S77>:50' */
        APP_FluxWeak_GEAR2_IdqStudy(rtu_Data_b, rtu_Data_l, rty_Out1, rty_Out1_h,
          rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l,
          rty_Out1_e, &localDW->IdqStudy);

        /* End of Outputs for SubSystem: '<S62>/IdqStudy' */
        break;

       case APP_FluxWeak_GEAR2_IN_MtpaStudy:
        /* Outputs for Function Call SubSystem: '<S62>/FluxLinkage' */

        /* During 'MtpaStudy': '<S77>:43' */
        /* '<S77>:43:1' FluxLinkage; */
        /* Event: '<S77>:53' */
        APP_FluxWeak_GEAR2_FluxLinkage(rtu_Data_b, rty_Out1, rty_Out1_h,
          rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l,
          rty_Out1_e, &localDW->FluxLinkage);

        /* End of Outputs for SubSystem: '<S62>/FluxLinkage' */
        break;

       case APP_FluxWeak_GEAR2_IN_Normal:
        /* Outputs for Function Call SubSystem: '<S62>/Tlin' */

        /* During 'Normal': '<S77>:47' */
        /* '<S77>:47:1' Normal; */
        /* Event: '<S77>:54' */
        APP_FluxWeak_GEAR2_Tlin(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
          rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e);

        /* End of Outputs for SubSystem: '<S62>/Tlin' */
        break;

       default:
        /* Outputs for Function Call SubSystem: '<S62>/PhaseStudy' */

        /* During 'PhaseStudy': '<S77>:31' */
        /* '<S77>:31:1' PhaseStudy; */
        /* Event: '<S77>:32' */
        APP_FluxWeak_GEAR2_PhaseStudy(rtu_Data_h, rtu_Data_b, rty_Out1,
          rty_Out1_h, rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs,
          rty_Out1_l, rty_Out1_e, &localDW->PhaseStudy);

        /* End of Outputs for SubSystem: '<S62>/PhaseStudy' */
        break;
      }
    }
  }

  /* End of Chart: '<S62>/Chart1' */
}

/* Output and update for function-call system: '<S54>/Initial_D' */
void APP_FluxWeak_GEAR2_Initial_D(void)
{
  /* StateWriter: '<S67>/State Writer4' incorporates:
   *  Constant: '<S67>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Spd_g.Spd_D_Int = 0.0F;
}

/* System initialize for function-call system: '<S54>/UVW_check' */
void APP_FluxWeak_GEA_UVW_check_Init(DW_UVW_check_APP_FluxWeak_GEA_T *localDW)
{
  /* SystemInitialize for Atomic SubSystem: '<S135>/lpf' */
  LPF_App_Init(&localDW->lpf);

  /* End of SystemInitialize for SubSystem: '<S135>/lpf' */

  /* SystemInitialize for Atomic SubSystem: '<S136>/lpf' */
  LPF_App_Init(&localDW->lpf_e);

  /* End of SystemInitialize for SubSystem: '<S136>/lpf' */

  /* SystemInitialize for Atomic SubSystem: '<S137>/lpf' */
  LPF_App_Init(&localDW->lpf_c);

  /* End of SystemInitialize for SubSystem: '<S137>/lpf' */

  /* SystemInitialize for Chart: '<S75>/Chart' */
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c28_APP_FluxWeak_GEAR = 0U;
  localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxW_IN_NO_ACTIVE_CHILD_oa;
  localDW->IdRefSet = 0.0F;
  localDW->AngleRefSet = 0.0F;
  localDW->IdIqSetEn = 1U;
  localDW->AngleSetEn = 1U;
  localDW->UVW_offline = 0U;
}

/* System reset for function-call system: '<S54>/UVW_check' */
void APP_FluxWeak_GE_UVW_check_Reset(DW_UVW_check_APP_FluxWeak_GEA_T *localDW)
{
  /* SystemReset for Atomic SubSystem: '<S135>/lpf' */
  LPF_App_Reset(&localDW->lpf);

  /* End of SystemReset for SubSystem: '<S135>/lpf' */

  /* SystemReset for Atomic SubSystem: '<S136>/lpf' */
  LPF_App_Reset(&localDW->lpf_e);

  /* End of SystemReset for SubSystem: '<S136>/lpf' */

  /* SystemReset for Atomic SubSystem: '<S137>/lpf' */
  LPF_App_Reset(&localDW->lpf_c);

  /* End of SystemReset for SubSystem: '<S137>/lpf' */

  /* SystemReset for Chart: '<S75>/Chart' */
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c28_APP_FluxWeak_GEAR = 0U;
  localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxW_IN_NO_ACTIVE_CHILD_oa;
  localDW->IdRefSet = 0.0F;
  localDW->AngleRefSet = 0.0F;
  localDW->IdIqSetEn = 1U;
  localDW->AngleSetEn = 1U;
  localDW->UVW_offline = 0U;
}

/* Output and update for function-call system: '<S54>/UVW_check' */
void APP_FluxWeak_GEAR2_UVW_check(real32_T rtu_Data, real32_T rtu_Data_l,
  real32_T rtu_Data_h, uint16_T *rty_UVWCheckOut, real32_T *rty_UVWCheckOut_l,
  real32_T *rty_UVWCheckOut_h, real32_T *rty_UVWCheckOut_p, uint16_T
  *rty_UVWCheckOut_j, uint16_T *rty_UVWCheckOut_b, real32_T *rty_UVWCheckOut_a,
  real32_T *rty_UVWCheckOut_b3, uint16_T *rty_UVWFault,
  DW_UVW_check_APP_FluxWeak_GEA_T *localDW)
{
  real32_T rtb_DiscreteTimeIntegrator1_hl;
  real32_T rtb_DiscreteTimeIntegrator1_p;
  real32_T rtb_DiscreteTimeIntegrator1_l;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut = 0U;

  /* Outputs for Atomic SubSystem: '<S135>/lpf' */

  /* Abs: '<S75>/Abs' incorporates:
   *  Constant: '<S135>/Constant'
   *  Constant: '<S135>/Constant1'
   */
  LPF_App(fabsf(rtu_Data), 0.002F, 20.0F, &rtb_DiscreteTimeIntegrator1_hl,
          &localDW->lpf);

  /* End of Outputs for SubSystem: '<S135>/lpf' */

  /* Outputs for Atomic SubSystem: '<S136>/lpf' */

  /* Abs: '<S75>/Abs1' incorporates:
   *  Constant: '<S136>/Constant'
   *  Constant: '<S136>/Constant1'
   */
  LPF_App(fabsf(rtu_Data_l), 0.002F, 20.0F, &rtb_DiscreteTimeIntegrator1_p,
          &localDW->lpf_e);

  /* End of Outputs for SubSystem: '<S136>/lpf' */

  /* Outputs for Atomic SubSystem: '<S137>/lpf' */

  /* Abs: '<S75>/Abs2' incorporates:
   *  Constant: '<S137>/Constant'
   *  Constant: '<S137>/Constant1'
   */
  LPF_App(fabsf(rtu_Data_h), 0.002F, 20.0F, &rtb_DiscreteTimeIntegrator1_l,
          &localDW->lpf_c);

  /* End of Outputs for SubSystem: '<S137>/lpf' */

  /* Chart: '<S75>/Chart' */
  /* Gateway: implement/method/All_loop/UVW_check/Chart */
  if (localDW->temporalCounter_i1 < 127U) {
    localDW->temporalCounter_i1 = ((int16_T)localDW->temporalCounter_i1 + 1) &
      255U;
  }

  /* During: implement/method/All_loop/UVW_check/Chart */
  if (localDW->is_active_c28_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/UVW_check/Chart */
    localDW->is_active_c28_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/UVW_check/Chart */
    /* Transition: '<S134>:5' */
    localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_start;

    /* Entry 'start': '<S134>:6' */
    /* '<S134>:6:1' IdIqSetEn=1; */
    localDW->IdIqSetEn = 1U;

    /* '<S134>:6:1' AngleSetEn =1 ; */
    localDW->AngleSetEn = 1U;

    /* '<S134>:6:1' IdRefSet=IdRefSet+0.006; */
    localDW->IdRefSet += 0.006F;

    /* '<S134>:6:4' AngleRefSet=0; */
    localDW->AngleRefSet = 0.0F;
  } else {
    switch (localDW->is_c28_APP_FluxWeak_GEAR2) {
     case APP_FluxWeak_GEAR2_IN_check:
      /* During 'check': '<S134>:13' */
      /* Transition: '<S134>:27' */
      localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_quitcheck;

      /* Entry 'quitcheck': '<S134>:26' */
      /* '<S134>:26:1' IdIqSetEn=1; */
      localDW->IdIqSetEn = 1U;

      /* '<S134>:26:1' AngleSetEn =1 ; */
      localDW->AngleSetEn = 1U;

      /* '<S134>:26:1' IdRefSet=IdRefSet-0.006; */
      localDW->IdRefSet -= 0.006F;

      /* '<S134>:26:4' AngleRefSet=0; */
      localDW->AngleRefSet = 0.0F;
      break;

     case APP_FluxWeak_GEAR2_IN_fin:
      /* During 'fin': '<S134>:28' */
      break;

     case APP_FluxWeak_GEAR2_IN_hold:
      /* During 'hold': '<S134>:11' */
      /* '<S134>:14:1' sf_internal_predicateOutput = ... */
      /* '<S134>:14:1' after(100,tick); */
      if ((int16_T)localDW->temporalCounter_i1 >= 100) {
        /* Transition: '<S134>:14' */
        localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_check;

        /* Entry Internal 'check': '<S134>:13' */
        /* Transition: '<S134>:16' */
        /* '<S134>:18:1' sf_internal_predicateOutput = ... */
        /* '<S134>:18:1' CurU>0.15 && CurV>0.075 && CurW>0.075; */
        if ((rtb_DiscreteTimeIntegrator1_hl > 0.15) &&
            (rtb_DiscreteTimeIntegrator1_p > 0.075) &&
            (rtb_DiscreteTimeIntegrator1_l > 0.075)) {
          /* Transition: '<S134>:18' */
          /* Transition: '<S134>:21' */
          /* '<S134>:21:1' UVW_offline=0; */
          localDW->UVW_offline = 0U;

          /* Transition: '<S134>:24' */
        } else {
          /* Transition: '<S134>:22' */
          /* '<S134>:22:1' UVW_offline=1; */
          localDW->UVW_offline = 1U;
        }
      } else {
        /* '<S134>:11:1' IdIqSetEn=1; */
        localDW->IdIqSetEn = 1U;

        /* '<S134>:11:1' AngleSetEn =1 ; */
        localDW->AngleSetEn = 1U;

        /* '<S134>:11:1' IdRefSet=0.3; */
        localDW->IdRefSet = 0.3F;

        /* '<S134>:11:3' AngleRefSet=0; */
        localDW->AngleRefSet = 0.0F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_quitcheck:
      /* During 'quitcheck': '<S134>:26' */
      /* '<S134>:29:1' sf_internal_predicateOutput = ... */
      /* '<S134>:29:1' IdRefSet<0.01; */
      if (localDW->IdRefSet < 0.01) {
        /* Transition: '<S134>:29' */
        localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_fin;

        /* Entry 'fin': '<S134>:28' */
        /* '<S134>:28:1' IdIqSetEn=0; */
        localDW->IdIqSetEn = 0U;

        /* '<S134>:28:1' AngleSetEn =0 ; */
        localDW->AngleSetEn = 0U;

        /* '<S134>:28:1' IdRefSet=0; */
        localDW->IdRefSet = 0.0F;

        /* '<S134>:28:3' AngleRefSet=0; */
        localDW->AngleRefSet = 0.0F;
      } else {
        /* '<S134>:26:1' IdIqSetEn=1; */
        localDW->IdIqSetEn = 1U;

        /* '<S134>:26:1' AngleSetEn =1 ; */
        localDW->AngleSetEn = 1U;

        /* '<S134>:26:1' IdRefSet=IdRefSet-0.006; */
        localDW->IdRefSet -= 0.006F;

        /* '<S134>:26:4' AngleRefSet=0; */
        localDW->AngleRefSet = 0.0F;
      }
      break;

     default:
      /* During 'start': '<S134>:6' */
      /* '<S134>:12:1' sf_internal_predicateOutput = ... */
      /* '<S134>:12:1' IdRefSet>=0.3; */
      if (localDW->IdRefSet >= 0.3) {
        /* Transition: '<S134>:12' */
        localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_hold;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'hold': '<S134>:11' */
        /* '<S134>:11:1' IdIqSetEn=1; */
        localDW->IdIqSetEn = 1U;

        /* '<S134>:11:1' AngleSetEn =1 ; */
        localDW->AngleSetEn = 1U;

        /* '<S134>:11:1' IdRefSet=0.3; */
        localDW->IdRefSet = 0.3F;

        /* '<S134>:11:3' AngleRefSet=0; */
        localDW->AngleRefSet = 0.0F;
      } else {
        /* '<S134>:6:1' IdIqSetEn=1; */
        localDW->IdIqSetEn = 1U;

        /* '<S134>:6:1' AngleSetEn =1 ; */
        localDW->AngleSetEn = 1U;

        /* '<S134>:6:1' IdRefSet=IdRefSet+0.006; */
        localDW->IdRefSet += 0.006F;

        /* '<S134>:6:4' AngleRefSet=0; */
        localDW->AngleRefSet = 0.0F;
      }
      break;
    }
  }

  /* End of Chart: '<S75>/Chart' */

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_l = localDW->IdRefSet;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_h = 0.0F;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_p = localDW->AngleRefSet;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_j = localDW->IdIqSetEn;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_b = localDW->AngleSetEn;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_a = 0.0F;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_b3 = 0.0F;

  /* SignalConversion: '<S75>/OutportBufferForUVWFault' */
  *rty_UVWFault = localDW->UVW_offline;
}

/*
 * Output and update for function-call system:
 *    '<S150>/Lim_state'
 *    '<S156>/Lim_state'
 */
void APP_FluxWeak_GEAR2_Lim_state(void)
{
  /* Saturate: '<S153>/Saturation' incorporates:
   *  StateReader: '<S153>/State Reader'
   */
  if (APP_FluxWeak_GEAR2_DW.sf_Chart_lj.FunctionCallSubsystem.PI.I_state > 1.0F)
  {
    /* StateWriter: '<S153>/State Writer' */
    APP_FluxWeak_GEAR2_DW.sf_Chart_lj.FunctionCallSubsystem.PI.I_state = 1.0F;
  } else {
    if (APP_FluxWeak_GEAR2_DW.sf_Chart_lj.FunctionCallSubsystem.PI.I_state <
        0.0F) {
      /* StateWriter: '<S153>/State Writer' */
      APP_FluxWeak_GEAR2_DW.sf_Chart_lj.FunctionCallSubsystem.PI.I_state = 0.0F;
    }
  }

  /* End of Saturate: '<S153>/Saturation' */
}

/*
 * System initialize for function-call system:
 *    '<S150>/Function-Call Subsystem'
 *    '<S156>/Function-Call Subsystem'
 */
void AP_FunctionCallSubsystem_a_Init(real32_T *rty_PIOut)
{
  /* SystemInitialize for Outport: '<S152>/PIOut' */
  *rty_PIOut = 1.0F;
}

/*
 * Output and update for function-call system:
 *    '<S150>/Function-Call Subsystem'
 *    '<S156>/Function-Call Subsystem'
 */
void APP_Flu_FunctionCallSubsystem_p(real32_T rtu_Err, real32_T *rty_PIOut,
  DW_FunctionCallSubsystem_AP_g_T *localDW)
{
  real32_T rtb_DiscreteTimeIntegrator1_n;

  /* Outputs for Atomic SubSystem: '<S152>/PI' */

  /* Constant: '<S152>/Constant' incorporates:
   *  Constant: '<S152>/Constant1'
   *  Constant: '<S152>/Constant2'
   */
  PI_App(rtu_Err, PMSM_Param.LimIKp, PMSM_Param.LimIKi, 0.002F, rty_PIOut,
         &rtb_DiscreteTimeIntegrator1_n, &localDW->PI);

  /* End of Outputs for SubSystem: '<S152>/PI' */
}

/*
 * System initialize for atomic system:
 *    '<S150>/Chart'
 *    '<S156>/Chart'
 */
void APP_FluxWeak_GEAR2_Chart_Init(real32_T *rty_0,
  DW_Chart_APP_FluxWeak_GEAR2_T *localDW)
{
  localDW->is_active_c25_APP_FluxWeak_GEAR = 0U;

  /* SystemInitialize for Function Call SubSystem: '<S150>/Function-Call Subsystem' */
  AP_FunctionCallSubsystem_a_Init(rty_0);

  /* End of SystemInitialize for SubSystem: '<S150>/Function-Call Subsystem' */
}

/*
 * System reset for atomic system:
 *    '<S150>/Chart'
 *    '<S156>/Chart'
 */
void APP_FluxWeak_GEAR2_Chart_Reset(DW_Chart_APP_FluxWeak_GEAR2_T *localDW)
{
  localDW->is_active_c25_APP_FluxWeak_GEAR = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S150>/Chart'
 *    '<S156>/Chart'
 */
void APP_FluxWeak_GEAR2_Chart(real32_T rtu_0, real32_T *rty_0,
  DW_Chart_APP_FluxWeak_GEAR2_T *localDW)
{
  /* Chart: '<S150>/Chart' */
  /* Gateway: implement/method/Lim&Fault/LimI/LimChg/PI/Chart */
  /* During: implement/method/Lim&Fault/LimI/LimChg/PI/Chart */
  if (localDW->is_active_c25_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/Lim&Fault/LimI/LimChg/PI/Chart */
    localDW->is_active_c25_APP_FluxWeak_GEAR = 1U;

    /* Outputs for Function Call SubSystem: '<S150>/Function-Call Subsystem' */

    /* Entry Internal: implement/method/Lim&Fault/LimI/LimChg/PI/Chart */
    /* Transition: '<S151>:2' */
    /* Entry 'NV_weak_call': '<S151>:1' */
    /* '<S151>:1:1' PI_call; */
    /* Event: '<S151>:4' */
    APP_Flu_FunctionCallSubsystem_p(rtu_0, rty_0,
      &localDW->FunctionCallSubsystem);

    /* End of Outputs for SubSystem: '<S150>/Function-Call Subsystem' */

    /* Outputs for Function Call SubSystem: '<S150>/Lim_state' */

    /* '<S151>:1:1' IntLim_nv; */
    /* Event: '<S151>:3' */
    APP_FluxWeak_GEAR2_Lim_state();

    /* End of Outputs for SubSystem: '<S150>/Lim_state' */
  } else {
    /* Outputs for Function Call SubSystem: '<S150>/Function-Call Subsystem' */

    /* During 'NV_weak_call': '<S151>:1' */
    /* '<S151>:1:1' PI_call; */
    /* Event: '<S151>:4' */
    APP_Flu_FunctionCallSubsystem_p(rtu_0, rty_0,
      &localDW->FunctionCallSubsystem);

    /* End of Outputs for SubSystem: '<S150>/Function-Call Subsystem' */

    /* Outputs for Function Call SubSystem: '<S150>/Lim_state' */

    /* '<S151>:1:1' IntLim_nv; */
    /* Event: '<S151>:3' */
    APP_FluxWeak_GEAR2_Lim_state();

    /* End of Outputs for SubSystem: '<S150>/Lim_state' */
  }

  /* End of Chart: '<S150>/Chart' */
}

/* Output and update for Simulink Function: '<S10>/Simulink Function2' */
void APP_FluxWeak_GEAR2_n2MaxT(real32_T rtu_Psi, real32_T *rty_Tmax)
{
  uint32_T bpIdx;
  real32_T frac;

  /* Lookup_n-D: '<S59>/table' incorporates:
   *  SignalConversion: '<S59>/TmpSignal ConversionAtPsiOutport1'
   */
  bpIdx = plook_u32ff_evenca(rtu_Psi, 0.165408403F, 0.013502717F, 49UL, &frac);

  /* SignalConversion: '<S59>/TmpSignal ConversionAtTmaxInport1' incorporates:
   *  Lookup_n-D: '<S59>/table'
   */
  *rty_Tmax = intrp1d_fu32fla_pw(bpIdx, frac, rtCP_table_tableData_f, 49UL);
}

/* Function for Chart: '<S54>/Chart' */
static void APP_Flux_exit_internal_sys_mode(const real32_T
  *DiscreteTimeIntegrator1, const real32_T *DiscreteTimeIntegrator1_i)
{
  /* Exit Internal 'sys_mode': '<S63>:7' */
  switch (APP_FluxWeak_GEAR2_DW.is_sys_mode) {
   case APP_FluxWeak_GEAR2_IN_Speed:
    /* Exit Internal 'Speed': '<S63>:5' */
    APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;

    /* Outputs for Function Call SubSystem: '<S54>/Update' */

    /* Exit 'Speed': '<S63>:5' */
    /* '<S63>:5:1' Update; */
    /* Event: '<S63>:13' */
    APP_FluxWeak_GEAR2_Update(&APP_FluxWeak_GEAR2_DW.Merge1,
      *DiscreteTimeIntegrator1_i, *DiscreteTimeIntegrator1);

    /* End of Outputs for SubSystem: '<S54>/Update' */

    /* Outputs for Function Call SubSystem: '<S54>/Initial_D' */

    /* '<S63>:5:1' Initial_D  */
    /* Event: '<S63>:85' */
    APP_FluxWeak_GEAR2_Initial_D();

    /* End of Outputs for SubSystem: '<S54>/Initial_D' */
    APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    break;

   case APP_FluxWeak_GEAR2_IN_Torque:
    /* Outputs for Function Call SubSystem: '<S54>/Update' */

    /* Exit 'Torque': '<S63>:3' */
    /* '<S63>:3:1' Update; */
    /* Event: '<S63>:13' */
    APP_FluxWeak_GEAR2_Update(&APP_FluxWeak_GEAR2_DW.Merge1,
      *DiscreteTimeIntegrator1_i, *DiscreteTimeIntegrator1);

    /* End of Outputs for SubSystem: '<S54>/Update' */

    /* Outputs for Function Call SubSystem: '<S54>/Initial_D' */

    /* '<S63>:3:1' Initial_D  */
    /* Event: '<S63>:85' */
    APP_FluxWeak_GEAR2_Initial_D();

    /* End of Outputs for SubSystem: '<S54>/Initial_D' */
    APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    break;

   case APP_FluxWeak_GEAR2_IN_appoint:
    /* Exit Internal 'appoint': '<S63>:6' */
    APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;

    /* Outputs for Function Call SubSystem: '<S54>/Initial' */

    /* Exit 'appoint': '<S63>:6' */
    /* '<S63>:6:1' Initial; */
    /* Event: '<S63>:12' */
    APP_FluxWeak_GEAR2_Initial();

    /* End of Outputs for SubSystem: '<S54>/Initial' */
    APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    break;
  }
}

/* Model step function */
void APP_FluxWeak_GEAR2_step(void)
{
  uint16_T ii;
  uint32_T bpIdx;
  real32_T rtb_InvTemp;
  real32_T rtb_BusConversion_InsertedFor_0;
  real32_T rtb_DiscreteTimeIntegrator1;
  real32_T rtb_Psi_i;
  uint16_T rtb_UVWoffline;
  int16_T rtb_LogicalOperator;
  real32_T rtb_DeadZone;
  real32_T rtb_Saturation1_i;
  real32_T rtb_Divide_p;
  real32_T rtb_Saturation1;
  boolean_T rtb_MultiportSwitch;
  boolean_T rtb_LogicalOperator_f;
  real32_T rtb_Switch_nd[2];
  real32_T rtb_InvCoef;
  real32_T rtb_TmpSignalConversionAtSFunct[3];
  real32_T rtb_Switch_b;
  real32_T DiscreteTimeIntegrator1;
  real32_T DiscreteTimeIntegrator1_i4;
  real32_T Vs;
  real32_T DiscreteTimeIntegrator1_i;
  int16_T i;
  uint16_T qY;

  /* Outputs for Atomic SubSystem: '<S188>/lpf' */

  /* DataStoreRead: '<Root>/Data Store Read' incorporates:
   *  Constant: '<S179>/Constant'
   *  Constant: '<S179>/Constant1'
   *  Constant: '<S188>/Constant'
   *  Constant: '<S188>/Constant1'
   */
  LPF_App(PMSM_Input.AgoSample.Speed, 0.002F, 1000.0F / PMSM_Param.SpdFilterTime,
          &DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.lpf);

  /* End of Outputs for SubSystem: '<S188>/lpf' */

  /* Outputs for Atomic SubSystem: '<S179>/lpf' */
  LPF_App(PMSM_Input.AppSample.VoltCap, 0.002F, 10.0F,
          &DiscreteTimeIntegrator1_i4, &APP_FluxWeak_GEAR2_DW.lpf_c);

  /* End of Outputs for SubSystem: '<S179>/lpf' */

  /* Lookup_n-D: '<S175>/1-D Lookup Table' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read2'
   */
  bpIdx = plook_u32ff_evenca(Algo_Output.Cur_loop.Vs, 1.0F, 0.0078125F, 128UL,
    &rtb_Divide_p);

  /* Saturate: '<S175>/Saturation' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read2'
   */
  if (Algo_Output.Cur_loop.Vs > 5.0F) {
    rtb_InvTemp = 5.0F;
  } else if (Algo_Output.Cur_loop.Vs < 1.0F) {
    rtb_InvTemp = 1.0F;
  } else {
    rtb_InvTemp = Algo_Output.Cur_loop.Vs;
  }

  /* End of Saturate: '<S175>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S189>/lpf' */

  /* Gain: '<S175>/Gain4' incorporates:
   *  Constant: '<S189>/Constant'
   *  Constant: '<S189>/Constant1'
   *  DataStoreRead: '<Root>/Data Store Read2'
   *  Lookup_n-D: '<S175>/1-D Lookup Table'
   *  Product: '<S175>/Divide1'
   *  Product: '<S175>/Product'
   *  Product: '<S175>/Product1'
   *  Product: '<S175>/Product2'
   *  Sum: '<S175>/Add'
   */
  LPF_App(PMSM_Param.CurNorm * 1.22474492F * ((Algo_Output.Cur_loop.Ud *
            Algo_Output.Cur_loop.Id + Algo_Output.Cur_loop.Uq *
            Algo_Output.Cur_loop.Iq) * (intrp1d_fu32fla_pw(bpIdx, rtb_Divide_p,
             rtCP_uDLookupTable_tableData, 128UL) / rtb_InvTemp)), 0.002F, 5.0F,
          &rtb_DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.lpf_p);

  /* End of Outputs for SubSystem: '<S189>/lpf' */

  /* MinMax: '<S194>/Min1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   */
  rtb_InvTemp = fmaxf(fmaxf(PMSM_Input.AppSample.InvTemp1,
    PMSM_Input.AppSample.InvTemp2), PMSM_Input.AppSample.InvTemp3);

  /* Chart: '<S173>/Chart' */
  /* Gateway: inputdata_process/Filter&Normalization/Subsystem/Chart */
  /* During: inputdata_process/Filter&Normalization/Subsystem/Chart */
  /* Entry Internal: inputdata_process/Filter&Normalization/Subsystem/Chart */
  /* Transition: '<S178>:2' */
  /* '<S178>:5:1' sf_internal_predicateOutput = ... */
  /* '<S178>:5:1' tick>=10; */
  if (APP_FluxWeak_GEAR2_DW.tick >= 10U) {
    /* Transition: '<S178>:5' */
    /* Transition: '<S178>:7' */
    /* '<S178>:7:1' tick=1; */
    APP_FluxWeak_GEAR2_DW.tick = 1U;

    /* Transition: '<S178>:10' */
  } else {
    /* Transition: '<S178>:9' */
    /* '<S178>:9:1' tick=tick+1; */
    qY = APP_FluxWeak_GEAR2_DW.tick + /*MW:OvSatOk*/ 1U;
    if (qY < APP_FluxWeak_GEAR2_DW.tick) {
      qY = MAX_uint16_T;
    }

    APP_FluxWeak_GEAR2_DW.tick = qY;
  }

  /* End of Chart: '<S173>/Chart' */

  /* BusCreator: '<S4>/BusConversion_InsertedFor_Bus Creator_at_inport_0' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   *  MinMax: '<S194>/Min'
   */
  rtb_BusConversion_InsertedFor_0 = fmaxf(PMSM_Input.AppSample.MotTemp1,
    PMSM_Input.AppSample.MotTemp2);
  qY = APP_FluxWeak_GEAR2_DW.tick;

  /* Chart: '<S1>/Chart' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   */
  APP_FluxWeak_GEAR2_DW.chartAbsoluteTimeCounter++;
  rtb_MultiportSwitch = (APP_FluxWeak_GEAR2_DW.ModeSt == 6U);
  if (!(rtb_MultiportSwitch && APP_FluxWeak_GEAR2_DW.condWasTrueLastTime_1)) {
    APP_FluxWeak_GEAR2_DW.durationLastReferenceTick_1 =
      APP_FluxWeak_GEAR2_DW.chartAbsoluteTimeCounter;
  }

  APP_FluxWeak_GEAR2_DW.condWasTrueLastTime_1 = rtb_MultiportSwitch;

  /* Gateway: StateMachine/Chart */
  /* During: StateMachine/Chart */
  if (APP_FluxWeak_GEAR2_DW.is_active_c3_APP_FluxWeak_GEAR2 == 0U) {
    /* Entry: StateMachine/Chart */
    APP_FluxWeak_GEAR2_DW.chartAbsoluteTimeCounter = 0;
    APP_FluxWeak_GEAR2_DW.is_active_c3_APP_FluxWeak_GEAR2 = 1U;

    /* Entry Internal: StateMachine/Chart */
    /* Transition: '<S5>:10' */
    APP_FluxWeak_GEAR2_DW.is_c3_APP_FluxWeak_GEAR2 =
      APP_FluxWeak_GEAR2_IN_ZeroBias;

    /* Entry 'ZeroBias': '<S5>:9' */
    /* 校准零偏 */
  } else {
    switch (APP_FluxWeak_GEAR2_DW.is_c3_APP_FluxWeak_GEAR2) {
     case APP_FluxWeak_GEAR2_IN_Prepare_c:
      APP_FluxWeak_GEAR2_DW.RunSt = 1U;

      /* During 'Prepare': '<S5>:11' */
      switch (APP_FluxWeak_GEAR2_DW.is_Prepare) {
       case APP_FluxWeak_GEAR2_IN_ConfirmHV:
        /* During 'ConfirmHV': '<S5>:13' */
        /* '<S5>:16:1' sf_internal_predicateOutput = ... */
        /* '<S5>:16:1' KsiSt && MainRelayState; */
        if ((PMSM_Input.AppSample.KsiSt != 0U) &&
            (PMSM_Input.AppComm.MainRelayState != 0U)) {
          /* Transition: '<S5>:16' */
          APP_FluxWeak_GEAR2_DW.is_Prepare = APP_FluxWeak_GEAR2_IN_wait_c;

          /* Entry 'wait': '<S5>:15' */
          /* 等待开管 */
          /* '<S5>:15:1' FaultSt=1; */
          APP_FluxWeak_GEAR2_DW.FaultSt = 1U;
        }
        break;

       case APP_FluxWeak_GEAR2_IN_NoPower:
        /* During 'NoPower': '<S5>:59' */
        /* '<S5>:62:1' sf_internal_predicateOutput = ... */
        /* '<S5>:62:1' KsiSt; */
        if (PMSM_Input.AppSample.KsiSt != 0U) {
          /* Transition: '<S5>:62' */
          /* Transition: '<S5>:64' */
          /* Transition: '<S5>:65' */
          APP_FluxWeak_GEAR2_DW.is_Prepare = APP_FluxWeak_GEAR2_IN_ConfirmHV;

          /* Entry 'ConfirmHV': '<S5>:13' */
          /* 确认高压 */
        }
        break;

       case APP_FluxWeak_G_IN_WaitForDischg:
        /* During 'WaitForDischg': '<S5>:51' */
        /* Transition: '<S5>:57' */
        /* '<S5>:18:1' sf_internal_predicateOutput = ... */
        /* '<S5>:18:1' GateReq; */
        if (PMSM_Input.AppComm.GateReq != 0U) {
          /* Transition: '<S5>:18' */
          APP_FluxWeak_GEAR2_DW.is_Prepare = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
          APP_FluxWeak_GEAR2_DW.durationLastReferenceTick_1 =
            APP_FluxWeak_GEAR2_DW.chartAbsoluteTimeCounter;
          APP_FluxWeak_GEAR2_DW.is_c3_APP_FluxWeak_GEAR2 =
            APP_FluxWeak_GEAR2_IN_Work;

          /* Entry 'Work': '<S5>:66' */
          /* '<S5>:66:1' RunSt =2; */
          APP_FluxWeak_GEAR2_DW.RunSt = 2U;

          /* Entry Internal 'Work': '<S5>:66' */
          /* Transition: '<S5>:70' */
          /* Entry 'Updata': '<S5>:76' */
          /* '<S5>:76:1' ModeSt=ModeReq; */
          APP_FluxWeak_GEAR2_DW.ModeSt = PMSM_Input.AppComm.ModeReq;
          APP_FluxWeak_GEAR2_DW.condWasTrueLastTime_1 =
            (APP_FluxWeak_GEAR2_DW.ModeSt == 6U);
        }
        break;

       default:
        APP_FluxWeak_GEAR2_DW.FaultSt = 1U;

        /* During 'wait': '<S5>:15' */
        /* Transition: '<S5>:58' */
        /* '<S5>:18:1' sf_internal_predicateOutput = ... */
        /* '<S5>:18:1' GateReq; */
        if (PMSM_Input.AppComm.GateReq != 0U) {
          /* Transition: '<S5>:18' */
          APP_FluxWeak_GEAR2_DW.is_Prepare = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
          APP_FluxWeak_GEAR2_DW.durationLastReferenceTick_1 =
            APP_FluxWeak_GEAR2_DW.chartAbsoluteTimeCounter;
          APP_FluxWeak_GEAR2_DW.is_c3_APP_FluxWeak_GEAR2 =
            APP_FluxWeak_GEAR2_IN_Work;

          /* Entry 'Work': '<S5>:66' */
          /* '<S5>:66:1' RunSt =2; */
          APP_FluxWeak_GEAR2_DW.RunSt = 2U;

          /* Entry Internal 'Work': '<S5>:66' */
          /* Transition: '<S5>:70' */
          /* Entry 'Updata': '<S5>:76' */
          /* '<S5>:76:1' ModeSt=ModeReq; */
          APP_FluxWeak_GEAR2_DW.ModeSt = PMSM_Input.AppComm.ModeReq;
          APP_FluxWeak_GEAR2_DW.condWasTrueLastTime_1 =
            (APP_FluxWeak_GEAR2_DW.ModeSt == 6U);
        }
        break;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_Work:
      APP_FluxWeak_GEAR2_DW.RunSt = 2U;

      /* During 'Work': '<S5>:66' */
      /* '<S5>:35:1' sf_internal_predicateOutput = ... */
      /* '<S5>:35:1' duration(ModeSt==6,sec)>3; */
      rtb_MultiportSwitch = (APP_FluxWeak_GEAR2_DW.ModeSt == 6U);
      if (!(rtb_MultiportSwitch && APP_FluxWeak_GEAR2_DW.condWasTrueLastTime_1))
      {
        APP_FluxWeak_GEAR2_DW.durationLastReferenceTick_1 =
          APP_FluxWeak_GEAR2_DW.chartAbsoluteTimeCounter;
      }

      APP_FluxWeak_GEAR2_DW.condWasTrueLastTime_1 = rtb_MultiportSwitch;
      if (APP_FluxWeak_GEAR2_DW.chartAbsoluteTimeCounter -
          APP_FluxWeak_GEAR2_DW.durationLastReferenceTick_1 > 1500) {
        /* Transition: '<S5>:35' */
        /* Exit Internal 'Work': '<S5>:66' */
        APP_FluxWeak_GEAR2_DW.is_c3_APP_FluxWeak_GEAR2 =
          APP_FluxWeak_GEAR2_IN_Prepare_c;

        /* Entry 'Prepare': '<S5>:11' */
        /* '<S5>:11:1' RunSt=1; */
        APP_FluxWeak_GEAR2_DW.RunSt = 1U;
        APP_FluxWeak_GEAR2_DW.is_Prepare = APP_FluxWeak_GEAR2_IN_NoPower;
      } else {
        /* '<S5>:50:1' sf_internal_predicateOutput = ... */
        /* '<S5>:50:1' ~GateReq && Speed<=PMSM_Param.ASCSpd; */
        if ((!(PMSM_Input.AppComm.GateReq != 0U)) && (PMSM_Input.AgoSample.Speed
             <= PMSM_Param.ASCSpd)) {
          /* Transition: '<S5>:50' */
          /* '<S5>:55:1' sf_internal_predicateOutput = ... */
          /* '<S5>:55:1' ~KsiSt; */
          if (!(PMSM_Input.AppSample.KsiSt != 0U)) {
            /* Transition: '<S5>:55' */
            /* Exit Internal 'Work': '<S5>:66' */
            APP_FluxWeak_GEAR2_DW.is_c3_APP_FluxWeak_GEAR2 =
              APP_FluxWeak_GEAR2_IN_Prepare_c;

            /* Entry 'Prepare': '<S5>:11' */
            /* '<S5>:11:1' RunSt=1; */
            APP_FluxWeak_GEAR2_DW.RunSt = 1U;
            APP_FluxWeak_GEAR2_DW.is_Prepare = APP_FluxWeak_G_IN_WaitForDischg;
          } else {
            /* Transition: '<S5>:54' */
            /* Exit Internal 'Work': '<S5>:66' */
            APP_FluxWeak_GEAR2_DW.is_c3_APP_FluxWeak_GEAR2 =
              APP_FluxWeak_GEAR2_IN_Prepare_c;

            /* Entry 'Prepare': '<S5>:11' */
            /* '<S5>:11:1' RunSt=1; */
            APP_FluxWeak_GEAR2_DW.RunSt = 1U;
            APP_FluxWeak_GEAR2_DW.is_Prepare = APP_FluxWeak_GEAR2_IN_ConfirmHV;

            /* Entry 'ConfirmHV': '<S5>:13' */
            /* 确认高压 */
          }
        } else {
          /* During 'Updata': '<S5>:76' */
          /* Transition: '<S5>:73' */
          /* '<S5>:72:1' sf_internal_predicateOutput = ... */
          /* '<S5>:72:1' ModeReq~=6; */
          if ((PMSM_Input.AppComm.ModeReq != 6U) ||
              ((!(PMSM_Input.AppComm.MainRelayState != 0U)) && (fabsf
                (PMSM_Input.AgoSample.Speed) < 1500.0F))) {
            /* Transition: '<S5>:72' */
            /* Transition: '<S5>:71' */
            /* Transition: '<S5>:74' */
            /* Transition: '<S5>:75' */
            /* Entry 'Updata': '<S5>:76' */
            /* '<S5>:76:1' ModeSt=ModeReq; */
            APP_FluxWeak_GEAR2_DW.ModeSt = PMSM_Input.AppComm.ModeReq;
            rtb_MultiportSwitch = (APP_FluxWeak_GEAR2_DW.ModeSt == 6U);
            if (!(rtb_MultiportSwitch &&
                  APP_FluxWeak_GEAR2_DW.condWasTrueLastTime_1)) {
              APP_FluxWeak_GEAR2_DW.durationLastReferenceTick_1 =
                APP_FluxWeak_GEAR2_DW.chartAbsoluteTimeCounter;
            }

            APP_FluxWeak_GEAR2_DW.condWasTrueLastTime_1 = rtb_MultiportSwitch;
          } else {
            /* '<S5>:74:1' sf_internal_predicateOutput = ... */
            /* '<S5>:74:1' ~MainRelayState && abs(Speed)<1500; */
          }
        }
      }
      break;

     default:
      /* During 'ZeroBias': '<S5>:9' */
      /* '<S5>:12:1' sf_internal_predicateOutput = ... */
      /* '<S5>:12:1' ReadyFin; */
      if (PMSM_Input.AppSample.ReadyFin != 0U) {
        /* Transition: '<S5>:12' */
        APP_FluxWeak_GEAR2_DW.is_c3_APP_FluxWeak_GEAR2 =
          APP_FluxWeak_GEAR2_IN_Prepare_c;

        /* Entry 'Prepare': '<S5>:11' */
        /* '<S5>:11:1' RunSt=1; */
        APP_FluxWeak_GEAR2_DW.RunSt = 1U;

        /* Entry Internal 'Prepare': '<S5>:11' */
        /* Transition: '<S5>:14' */
        APP_FluxWeak_GEAR2_DW.is_Prepare = APP_FluxWeak_GEAR2_IN_ConfirmHV;

        /* Entry 'ConfirmHV': '<S5>:13' */
        /* 确认高压 */
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* Outputs for Atomic SubSystem: '<S182>/lpf' */

  /* DataStoreRead: '<Root>/Data Store Read' incorporates:
   *  Constant: '<S182>/Constant'
   *  Constant: '<S182>/Constant1'
   */
  LPF_App(PMSM_Input.AppComm.SpdReq, 0.002F, 1.0F, &DiscreteTimeIntegrator1_i,
          &APP_FluxWeak_GEAR2_DW.lpf_pi);

  /* End of Outputs for SubSystem: '<S182>/lpf' */

  /* Abs: '<S175>/Abs2' incorporates:
   *  Gain: '<S175>/Gain9'
   */
  rtb_Psi_i = fabsf(PMSM_Param.MotPole * 2.0F * 3.14159274F / 60.0F *
                    DiscreteTimeIntegrator1);

  /* Saturate: '<S175>/Saturation1' */
  if (rtb_Psi_i > 1.0E+6F) {
    rtb_Psi_i = 1.0E+6F;
  } else {
    if (rtb_Psi_i < 10.0F) {
      rtb_Psi_i = 10.0F;
    }
  }

  /* End of Saturate: '<S175>/Saturation1' */

  /* Product: '<S175>/Divide2' incorporates:
   *  Gain: '<S175>/Gain8'
   */
  rtb_Psi_i = 0.577350259F * DiscreteTimeIntegrator1_i4 / rtb_Psi_i;

  /* Math: '<S177>/Math Function1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read2'
   */
  Vs = rt_hypotf_snf(Algo_Output.Cur_loop.Ud, Algo_Output.Cur_loop.Uq);

  /* Outputs for Enabled SubSystem: '<S2>/Fault' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (APP_FluxWeak_GEAR2_DW.FaultSt > 0U) {
    /* Outputs for Atomic SubSystem: '<S8>/judgment' */
    /* Outputs for Enabled SubSystem: '<S15>/Block' incorporates:
     *  EnablePort: '<S17>/Enable'
     */
    /* RelationalOperator: '<S19>/Compare' incorporates:
     *  Constant: '<S19>/Constant'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 2U) {
      /* Abs: '<S17>/Abs' */
      rtb_Switch_b = fabsf(DiscreteTimeIntegrator1);

      /* MultiPortSwitch: '<S33>/Multiport Switch' incorporates:
       *  Abs: '<S33>/Abs1'
       *  Abs: '<S33>/Abs2'
       *  Constant: '<S33>/Constant'
       *  Constant: '<S33>/Constant1'
       *  Constant: '<S33>/Constant2'
       *  Constant: '<S33>/Constant3'
       *  Constant: '<S34>/Constant'
       *  Constant: '<S35>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read'
       *  RelationalOperator: '<S34>/Compare'
       *  RelationalOperator: '<S35>/Compare'
       */
      switch (APP_FluxWeak_GEAR2_DW.ModeSt) {
       case 0:
        rtb_MultiportSwitch = (fabsf(PMSM_Input.AppComm.TqReq) <= 0.05F);
        break;

       case 1:
        rtb_MultiportSwitch = (fabsf(DiscreteTimeIntegrator1_i) <= 10.0F);
        break;

       case 2:
        rtb_MultiportSwitch = true;
        break;

       case 3:
        rtb_MultiportSwitch = true;
        break;

       case 4:
        rtb_MultiportSwitch = true;
        break;

       default:
        rtb_MultiportSwitch = true;
        break;
      }

      /* End of MultiPortSwitch: '<S33>/Multiport Switch' */

      /* Chart: '<S17>/Chart' incorporates:
       *  Abs: '<S17>/Abs'
       *  DataStoreRead: '<Root>/Data Store Read2'
       *  Math: '<S177>/Math Function'
       */
      /* Gateway: implement/Fault/judgment/Block/Chart */
      /* During: implement/Fault/judgment/Block/Chart */
      /* Entry Internal: implement/Fault/judgment/Block/Chart */
      /* Transition: '<S31>:6' */
      /* '<S31>:17:1' sf_internal_predicateOutput = ... */
      /* '<S31>:17:1' Spd>200 || LowReq; */
      if ((rtb_Switch_b > 200.0F) || rtb_MultiportSwitch) {
        /* Transition: '<S31>:17' */
        /* Transition: '<S31>:19' */
        /* '<S31>:19:1' BlockState=0; */
        APP_FluxWeak_GEAR2_DW.BlockState = 0.0F;

        /* Transition: '<S31>:20' */
        /* Transition: '<S31>:12' */
      } else {
        /* Transition: '<S31>:15' */
        /* '<S31>:8:1' sf_internal_predicateOutput = ... */
        /* '<S31>:8:1' Spd<=10; */
        if (rtb_Switch_b <= 10.0F) {
          /* Transition: '<S31>:8' */
          /* Transition: '<S31>:10' */
          /* '<S31>:10:1' BlockState=BlockState+Is*0.02; */
          APP_FluxWeak_GEAR2_DW.BlockState += rt_hypotf_snf
            (Algo_Output.Cur_loop.Id, Algo_Output.Cur_loop.Iq) * 0.02F;

          /* Transition: '<S31>:12' */
        } else {
          /* Transition: '<S31>:13' */
        }
      }

      /* End of Chart: '<S17>/Chart' */

      /* RelationalOperator: '<S32>/Compare' incorporates:
       *  Constant: '<S32>/Constant'
       */
      APP_FluxWeak_GEAR2_DW.Compare = (APP_FluxWeak_GEAR2_DW.BlockState > 2.0F);
    }

    /* End of RelationalOperator: '<S19>/Compare' */
    /* End of Outputs for SubSystem: '<S15>/Block' */

    /* SignalConversion: '<S15>/BusConversion_InsertedFor_Fault_App_at_inport_0' incorporates:
     *  UnitDelay: '<S2>/Unit Delay'
     */
    rtb_UVWoffline = APP_FluxWeak_GEAR2_DW.UnitDelay_DSTATE;

    /* Logic: '<S18>/Logical Operator' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    rtb_LogicalOperator = ((PMSM_Input.AppComm.CanMsg1Lost != 0U) ||
      (PMSM_Input.AppComm.CanMsg2Lost != 0U));

    /* RelationalOperator: '<S20>/Compare' incorporates:
     *  Constant: '<S20>/Constant'
     */
    rtb_MultiportSwitch = (APP_FluxWeak_GEAR2_DW.tick == 3U);

    /* Outputs for Enabled SubSystem: '<S15>/DisChg' incorporates:
     *  EnablePort: '<S25>/Enable'
     */
    /* RelationalOperator: '<S24>/Compare' incorporates:
     *  Constant: '<S24>/Constant'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 7U) {
      /* Chart: '<S25>/Chart1' incorporates:
       *  Constant: '<S37>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read'
       *  RelationalOperator: '<S37>/Compare'
       */
      /* Gateway: implement/Fault/judgment/DisChg/Chart1 */
      /* During: implement/Fault/judgment/DisChg/Chart1 */
      /* Entry Internal: implement/Fault/judgment/DisChg/Chart1 */
      /* Transition: '<S36>:4' */
      /* '<S36>:14:1' sf_internal_predicateOutput = ... */
      /* '<S36>:14:1' ~ChgMode; */
      if (!(PMSM_Input.AppComm.ModeReq == 6U)) {
        /* Transition: '<S36>:14' */
        /* Transition: '<S36>:16' */
        /* '<S36>:16:1' DisChg_time=0; */
        APP_FluxWeak_GEAR2_DW.DisChg_time = 0.0F;

        /* SignalConversion: '<S25>/OutportBufferForDisChg' */
        /* '<S36>:16:1' ChgCode=0; */
        APP_FluxWeak_GEAR2_DW.OutportBufferForDisChg = 0UL;

        /* Transition: '<S36>:31' */
        /* Transition: '<S36>:32' */
        /* Transition: '<S36>:33' */
      } else {
        /* Transition: '<S36>:18' */
        /* '<S36>:20:1' sf_internal_predicateOutput = ... */
        /* '<S36>:20:1' VoltCap>=36; */
        if (DiscreteTimeIntegrator1_i4 >= 36.0F) {
          /* Transition: '<S36>:20' */
          /* Transition: '<S36>:22' */
          /* '<S36>:22:1' DisChg_time=DisChg_time+0.001; */
          APP_FluxWeak_GEAR2_DW.DisChg_time += 0.001F;

          /* '<S36>:25:1' sf_internal_predicateOutput = ... */
          /* '<S36>:25:1' DisChg_time>=5; */
          if (APP_FluxWeak_GEAR2_DW.DisChg_time >= 5.0F) {
            /* SignalConversion: '<S25>/OutportBufferForDisChg' */
            /* Transition: '<S36>:25' */
            /* Transition: '<S36>:30' */
            /* '<S36>:30:1' ChgCode=1; */
            APP_FluxWeak_GEAR2_DW.OutportBufferForDisChg = 1UL;

            /* Transition: '<S36>:32' */
            /* Transition: '<S36>:33' */
          } else {
            /* SignalConversion: '<S25>/OutportBufferForDisChg' */
            /* Transition: '<S36>:27' */
            /* '<S36>:27:1' ChgCode=0; */
            APP_FluxWeak_GEAR2_DW.OutportBufferForDisChg = 0UL;

            /* Transition: '<S36>:33' */
          }
        } else {
          /* Transition: '<S36>:34' */
          /* '<S36>:34:1' DisChg_time=0; */
          APP_FluxWeak_GEAR2_DW.DisChg_time = 0.0F;

          /* SignalConversion: '<S25>/OutportBufferForDisChg' */
          /* '<S36>:34:1' ChgCode=0; */
          APP_FluxWeak_GEAR2_DW.OutportBufferForDisChg = 0UL;
        }
      }

      /* End of Chart: '<S25>/Chart1' */
    }

    /* End of RelationalOperator: '<S24>/Compare' */
    /* End of Outputs for SubSystem: '<S15>/DisChg' */

    /* Outputs for Enabled SubSystem: '<S15>/Spd' incorporates:
     *  EnablePort: '<S27>/Enable'
     */
    /* RelationalOperator: '<S21>/Compare' incorporates:
     *  Constant: '<S21>/Constant'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 4U) {
      /* Abs: '<S27>/Abs' */
      rtb_Switch_b = fabsf(DiscreteTimeIntegrator1);

      /* Chart: '<S27>/Chart1' incorporates:
       *  Abs: '<S27>/Abs'
       */
      /* Gateway: implement/Fault/judgment/Spd/Chart1 */
      /* During: implement/Fault/judgment/Spd/Chart1 */
      /* Entry Internal: implement/Fault/judgment/Spd/Chart1 */
      /* Transition: '<S38>:15' */
      /* '<S38>:17:1' sf_internal_predicateOutput = ... */
      /* '<S38>:17:1' SpdCode(2); */
      if ((APP_FluxWeak_GEAR2_DW.SpdCode_o[1] != 0UL) || (!(rtb_Switch_b >
            PMSM_Param.OS2))) {
        /* Transition: '<S38>:17' */
        /* Transition: '<S38>:78' */
        /* Transition: '<S38>:79' */
        /* Transition: '<S38>:51' */
        /* '<S38>:66:1' sf_internal_predicateOutput = ... */
        /* '<S38>:66:1' SpdCode(1); */
        if (APP_FluxWeak_GEAR2_DW.SpdCode_o[0] != 0UL) {
          /* Transition: '<S38>:66' */
          /* '<S38>:68:1' sf_internal_predicateOutput = ... */
          /* '<S38>:68:1' NmFil<=PMSM_Param.OS1-100; */
          if (rtb_Switch_b <= PMSM_Param.OS1 - 100.0F) {
            /* Transition: '<S38>:68' */
            /* Transition: '<S38>:70' */
            /* '<S38>:70:1' SpdCode(1)=0; */
            APP_FluxWeak_GEAR2_DW.SpdCode_o[0] = 0UL;

            /* Transition: '<S38>:72' */
            /* Transition: '<S38>:76' */
            /* Transition: '<S38>:45' */
          } else {
            /* Transition: '<S38>:73' */
            /* Transition: '<S38>:76' */
            /* Transition: '<S38>:45' */
          }
        } else {
          /* Transition: '<S38>:52' */
          /* '<S38>:40:1' sf_internal_predicateOutput = ... */
          /* '<S38>:40:1' NmFil>PMSM_Param.OS1; */
          if (rtb_Switch_b > PMSM_Param.OS1) {
            /* Transition: '<S38>:40' */
            /* Transition: '<S38>:42' */
            /* '<S38>:42:1' SpdCode(1)=1; */
            APP_FluxWeak_GEAR2_DW.SpdCode_o[0] = 1UL;

            /* Transition: '<S38>:45' */
          } else {
            /* Transition: '<S38>:44' */
          }
        }
      } else {
        /* Transition: '<S38>:21' */
        /* '<S38>:33:1' sf_internal_predicateOutput = ... */
        /* '<S38>:33:1' NmFil>PMSM_Param.OS2; */
        /* Transition: '<S38>:33' */
        /* Transition: '<S38>:35' */
        /* '<S38>:35:1' SpdCode(1)=0; */
        APP_FluxWeak_GEAR2_DW.SpdCode_o[0] = 0UL;

        /* '<S38>:35:1' SpdCode(2)=1; */
        APP_FluxWeak_GEAR2_DW.SpdCode_o[1] = 1UL;

        /* Transition: '<S38>:75' */
        /* Transition: '<S38>:72' */
        /* Transition: '<S38>:76' */
        /* Transition: '<S38>:45' */
      }

      /* End of Chart: '<S27>/Chart1' */

      /* SignalConversion: '<S27>/BusConversion_InsertedFor_Spd_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.SpdCode[0] = APP_FluxWeak_GEAR2_DW.SpdCode_o[0];
      APP_FluxWeak_GEAR2_DW.SpdCode[1] = APP_FluxWeak_GEAR2_DW.SpdCode_o[1];

      /* Logic: '<S27>/Logical Operator' */
      rtb_LogicalOperator_f = !(APP_FluxWeak_GEAR2_DW.SpdCode_o[0] != 0UL);

      /* RateLimiter: '<S27>/Rate Limiter' incorporates:
       *  DataTypeConversion: '<S27>/Data Type Conversion'
       */
      rtb_Switch_b = (real32_T)rtb_LogicalOperator_f -
        APP_FluxWeak_GEAR2_DW.PrevY;
      if (rtb_Switch_b > 0.002F) {
        APP_FluxWeak_GEAR2_DW.PrevY += 0.002F;
      } else if (rtb_Switch_b < -0.002F) {
        APP_FluxWeak_GEAR2_DW.PrevY += -0.002F;
      } else {
        APP_FluxWeak_GEAR2_DW.PrevY = rtb_LogicalOperator_f;
      }

      /* End of RateLimiter: '<S27>/Rate Limiter' */

      /* Switch: '<S27>/Switch' incorporates:
       *  Constant: '<S27>/Constant'
       *  Constant: '<S27>/Constant1'
       *  Gain: '<S27>/Gain1'
       */
      if (DiscreteTimeIntegrator1 >= 0.0F) {
        rtb_Switch_nd[0] = APP_FluxWeak_GEAR2_DW.PrevY;
        rtb_Switch_nd[1] = -1.0F;
      } else {
        rtb_Switch_nd[0] = 1.0F;
        rtb_Switch_nd[1] = -APP_FluxWeak_GEAR2_DW.PrevY;
      }

      /* End of Switch: '<S27>/Switch' */

      /* SignalConversion: '<S27>/BusConversion_InsertedFor_Spd_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.OSLimTP = rtb_Switch_nd[0];

      /* SignalConversion: '<S27>/BusConversion_InsertedFor_Spd_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.OSLimTN = rtb_Switch_nd[1];
    }

    /* End of RelationalOperator: '<S21>/Compare' */
    /* End of Outputs for SubSystem: '<S15>/Spd' */

    /* Outputs for Enabled SubSystem: '<S15>/TempSensor' incorporates:
     *  EnablePort: '<S29>/Enable'
     */
    /* RelationalOperator: '<S22>/Compare' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S48>/Constant'
     *  Constant: '<S48>/Constant1'
     *  Constant: '<S49>/Constant'
     *  Constant: '<S49>/Constant1'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 5U) {
      /* Logic: '<S29>/Logical Operator1' incorporates:
       *  Constant: '<S43>/Constant'
       *  Constant: '<S44>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read'
       *  RelationalOperator: '<S43>/Compare'
       *  RelationalOperator: '<S44>/Compare'
       */
      APP_FluxWeak_GEAR2_DW.LogicalOperator1[0] = (uint32_T)
        ((PMSM_Input.AppSample.MotTemp1 < -50.0F) ||
         (PMSM_Input.AppSample.MotTemp1 > 180.0F));
      APP_FluxWeak_GEAR2_DW.LogicalOperator1[1] = (uint32_T)
        ((PMSM_Input.AppSample.MotTemp2 < -50.0F) ||
         (PMSM_Input.AppSample.MotTemp2 > 180.0F));

      /* SignalConversion: '<S40>/TmpSignal ConversionAt SFunction Inport2' incorporates:
       *  Chart: '<S29>/Chart1'
       *  DataStoreRead: '<Root>/Data Store Read'
       */
      rtb_Switch_nd[0] = PMSM_Input.AppSample.MotTemp1;
      rtb_Switch_nd[1] = PMSM_Input.AppSample.MotTemp2;

      /* Chart: '<S29>/Chart1' */
      /* Gateway: implement/Fault/judgment/TempSensor/Chart1 */
      /* During: implement/Fault/judgment/TempSensor/Chart1 */
      /* Entry Internal: implement/Fault/judgment/TempSensor/Chart1 */
      /* Transition: '<S40>:26' */
      /* Transition: '<S40>:29' */
      /* '<S40>:29:1' ii=1; */
      /* '<S40>:27:1' sf_internal_predicateOutput = ... */
      /* '<S40>:27:1' ii<3; */
      for (ii = 1U; (int16_T)ii < 3; ii++) {
        /* Transition: '<S40>:27' */
        /* '<S40>:40:1' sf_internal_predicateOutput = ... */
        /* '<S40>:40:1' id(ii); */
        i = (int16_T)ii - 1;
        if (APP_FluxWeak_GEAR2_DW.LogicalOperator1[i] != 0UL) {
          /* Transition: '<S40>:40' */
          /* Transition: '<S40>:42' */
          /* '<S40>:42:1' out(ii)=-50; */
          APP_FluxWeak_GEAR2_DW.out_e[i] = -50.0F;

          /* Transition: '<S40>:44' */
        } else {
          /* Transition: '<S40>:43' */
          /* '<S40>:43:1' out(ii)=Temp(ii); */
          APP_FluxWeak_GEAR2_DW.out_e[i] = rtb_Switch_nd[i];
        }

        /* Transition: '<S40>:30' */
        /* '<S40>:30:1' ii=ii+1; */
      }

      /* Logic: '<S29>/Logical Operator2' incorporates:
       *  Constant: '<S45>/Constant'
       *  Constant: '<S46>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read'
       *  RelationalOperator: '<S45>/Compare'
       *  RelationalOperator: '<S46>/Compare'
       */
      /* Transition: '<S40>:31' */
      APP_FluxWeak_GEAR2_DW.LogicalOperator2[0] = (uint32_T)
        ((PMSM_Input.AppSample.InvTemp1 < -50.0F) ||
         (PMSM_Input.AppSample.InvTemp1 > 120.0F));
      APP_FluxWeak_GEAR2_DW.LogicalOperator2[1] = (uint32_T)
        ((PMSM_Input.AppSample.InvTemp2 < -50.0F) ||
         (PMSM_Input.AppSample.InvTemp2 > 120.0F));
      APP_FluxWeak_GEAR2_DW.LogicalOperator2[2] = (uint32_T)
        ((PMSM_Input.AppSample.InvTemp3 < -50.0F) ||
         (PMSM_Input.AppSample.InvTemp3 > 120.0F));

      /* SignalConversion: '<S41>/TmpSignal ConversionAt SFunction Inport2' incorporates:
       *  Chart: '<S29>/Chart2'
       *  DataStoreRead: '<Root>/Data Store Read'
       */
      rtb_TmpSignalConversionAtSFunct[0] = PMSM_Input.AppSample.InvTemp1;
      rtb_TmpSignalConversionAtSFunct[1] = PMSM_Input.AppSample.InvTemp2;
      rtb_TmpSignalConversionAtSFunct[2] = PMSM_Input.AppSample.InvTemp3;

      /* Chart: '<S29>/Chart2' */
      /* Gateway: implement/Fault/judgment/TempSensor/Chart2 */
      /* During: implement/Fault/judgment/TempSensor/Chart2 */
      /* Entry Internal: implement/Fault/judgment/TempSensor/Chart2 */
      /* Transition: '<S41>:26' */
      /* Transition: '<S41>:29' */
      /* '<S41>:29:1' ii=1; */
      /* '<S41>:27:1' sf_internal_predicateOutput = ... */
      /* '<S41>:27:1' ii<4; */
      for (ii = 1U; (int16_T)ii < 4; ii++) {
        /* Transition: '<S41>:27' */
        /* '<S41>:40:1' sf_internal_predicateOutput = ... */
        /* '<S41>:40:1' id(ii); */
        i = (int16_T)ii - 1;
        if (APP_FluxWeak_GEAR2_DW.LogicalOperator2[i] != 0UL) {
          /* Transition: '<S41>:40' */
          /* Transition: '<S41>:42' */
          /* '<S41>:42:1' out(ii)=-50; */
          APP_FluxWeak_GEAR2_DW.out[i] = -50.0F;

          /* Transition: '<S41>:44' */
        } else {
          /* Transition: '<S41>:43' */
          /* '<S41>:43:1' out(ii)=Temp(ii); */
          APP_FluxWeak_GEAR2_DW.out[i] = rtb_TmpSignalConversionAtSFunct[i];
        }

        /* Transition: '<S41>:30' */
        /* '<S41>:30:1' ii=ii+1; */
      }

      /* Switch: '<S29>/Switch' incorporates:
       *  Constant: '<S29>/Constant4'
       *  Constant: '<S47>/Constant'
       *  MinMax: '<S29>/MinMax2'
       *  RelationalOperator: '<S47>/Compare'
       *  Sum: '<S29>/Sum of Elements'
       */
      /* Transition: '<S41>:31' */
      if (APP_FluxWeak_GEAR2_DW.LogicalOperator1[0] +
          APP_FluxWeak_GEAR2_DW.LogicalOperator1[1] == 2UL) {
        rtb_Switch_b = 200.0F;
      } else {
        rtb_Switch_b = fmaxf(APP_FluxWeak_GEAR2_DW.out_e[0],
                             APP_FluxWeak_GEAR2_DW.out_e[1L]);
      }

      /* End of Switch: '<S29>/Switch' */

      /* Outputs for Atomic SubSystem: '<S48>/lpf' */
      LPF_App(rtb_Switch_b, 0.02F, 10.0F,
              &APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c,
              &APP_FluxWeak_GEAR2_DW.lpf_e);

      /* End of Outputs for SubSystem: '<S48>/lpf' */

      /* Switch: '<S29>/Switch1' incorporates:
       *  Constant: '<S29>/Constant7'
       *  Constant: '<S42>/Constant'
       *  Constant: '<S48>/Constant'
       *  Constant: '<S48>/Constant1'
       *  MinMax: '<S29>/MinMax1'
       *  RelationalOperator: '<S42>/Compare'
       *  Sum: '<S29>/Sum of Elements1'
       */
      if ((APP_FluxWeak_GEAR2_DW.LogicalOperator2[0] +
           APP_FluxWeak_GEAR2_DW.LogicalOperator2[1]) +
          APP_FluxWeak_GEAR2_DW.LogicalOperator2[2] == 3UL) {
        rtb_Switch_b = 200.0F;
      } else {
        rtb_Switch_b = fmaxf(fmaxf(APP_FluxWeak_GEAR2_DW.out[0],
          APP_FluxWeak_GEAR2_DW.out[1L]), APP_FluxWeak_GEAR2_DW.out[2L]);
      }

      /* End of Switch: '<S29>/Switch1' */

      /* Outputs for Atomic SubSystem: '<S49>/lpf' */
      LPF_App(rtb_Switch_b, 0.02F, 10.0F,
              &APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a,
              &APP_FluxWeak_GEAR2_DW.lpf_i);

      /* End of Outputs for SubSystem: '<S49>/lpf' */
    }

    /* End of RelationalOperator: '<S22>/Compare' */
    /* End of Outputs for SubSystem: '<S15>/TempSensor' */

    /* Outputs for Enabled SubSystem: '<S15>/Temp' incorporates:
     *  EnablePort: '<S28>/Enable'
     */
    /* RelationalOperator: '<S23>/Compare' incorporates:
     *  Constant: '<S23>/Constant'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 6U) {
      /* Chart: '<S28>/Chart' */
      /* Gateway: implement/Fault/judgment/Temp/Chart */
      /* During: implement/Fault/judgment/Temp/Chart */
      /* Entry Internal: implement/Fault/judgment/Temp/Chart */
      /* Transition: '<S39>:54' */
      /* '<S39>:56:1' sf_internal_predicateOutput = ... */
      /* '<S39>:56:1' TempCode(3); */
      if (APP_FluxWeak_GEAR2_DW.TempCode_g[2] == 0UL) {
        /* Transition: '<S39>:60' */
        /* '<S39>:62:1' sf_internal_predicateOutput = ... */
        /* '<S39>:62:1' MotTemp>PMSM_Param.MotOT3; */
        if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c > PMSM_Param.MotOT3)
        {
          /* Transition: '<S39>:62' */
          /* Transition: '<S39>:64' */
          /* '<S39>:64:1' TempCode(1)=0; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[0] = 0UL;

          /* '<S39>:64:1' TempCode(2)=0; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[1] = 0UL;

          /* '<S39>:64:1' TempCode(3)=1; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[2] = 1UL;

          /* 电机三级 */
          /* Transition: '<S39>:78' */
          /* Transition: '<S39>:79' */
          /* Transition: '<S39>:80' */
        } else {
          /* Transition: '<S39>:66' */
          /* '<S39>:68:1' sf_internal_predicateOutput = ... */
          /* '<S39>:68:1' MotTemp>PMSM_Param.MotOT2; */
          if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c >
              PMSM_Param.MotOT2) {
            /* Transition: '<S39>:68' */
            /* Transition: '<S39>:70' */
            /* '<S39>:70:1' TempCode(1)=0; */
            APP_FluxWeak_GEAR2_DW.TempCode_g[0] = 0UL;

            /* '<S39>:70:1' TempCode(2)=1; */
            APP_FluxWeak_GEAR2_DW.TempCode_g[1] = 1UL;

            /* 电机二级 */
            /* Transition: '<S39>:79' */
            /* Transition: '<S39>:80' */
          } else {
            /* Transition: '<S39>:72' */
            /* '<S39>:74:1' sf_internal_predicateOutput = ... */
            /* '<S39>:74:1' MotTemp>PMSM_Param.MotOT1; */
            if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c >
                PMSM_Param.MotOT1) {
              /* Transition: '<S39>:74' */
              /* Transition: '<S39>:76' */
              /* '<S39>:76:1' TempCode(1)=1; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[0] = 1UL;

              /* '<S39>:76:1' TempCode(2)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[1] = 0UL;

              /* 电机一级 */
              /* Transition: '<S39>:80' */
            } else {
              /* Transition: '<S39>:81' */
              /* '<S39>:81:1' TempCode(1)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[0] = 0UL;

              /* '<S39>:81:1' TempCode(2)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[1] = 0UL;
            }
          }
        }
      } else {
        /* Transition: '<S39>:56' */
        /* Transition: '<S39>:58' */
        /* Transition: '<S39>:113' */
      }

      /* Transition: '<S39>:112' */
      /* '<S39>:83:1' sf_internal_predicateOutput = ... */
      /* '<S39>:83:1' TempCode(6); */
      if (APP_FluxWeak_GEAR2_DW.TempCode_g[5] == 0UL) {
        /* Transition: '<S39>:87' */
        /* '<S39>:97:1' sf_internal_predicateOutput = ... */
        /* '<S39>:97:1' InvTemp>PMSM_Param.InvOT3; */
        if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a > PMSM_Param.InvOT3)
        {
          /* Transition: '<S39>:97' */
          /* Transition: '<S39>:94' */
          /* '<S39>:94:1' TempCode(4)=0; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[3] = 0UL;

          /* '<S39>:94:1' TempCode(5)=0; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[4] = 0UL;

          /* '<S39>:94:1' TempCode(6)=1; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[5] = 1UL;

          /* 控制器三级 */
          /* Transition: '<S39>:103' */
          /* Transition: '<S39>:86' */
          /* Transition: '<S39>:110' */
        } else {
          /* Transition: '<S39>:98' */
          /* '<S39>:89:1' sf_internal_predicateOutput = ... */
          /* '<S39>:89:1' InvTemp>PMSM_Param.InvOT2; */
          if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a >
              PMSM_Param.InvOT2) {
            /* Transition: '<S39>:89' */
            /* Transition: '<S39>:100' */
            /* '<S39>:100:1' TempCode(4)=0; */
            APP_FluxWeak_GEAR2_DW.TempCode_g[3] = 0UL;

            /* '<S39>:100:1' TempCode(5)=1; */
            APP_FluxWeak_GEAR2_DW.TempCode_g[4] = 1UL;

            /* 控制器二级 */
            /* Transition: '<S39>:86' */
            /* Transition: '<S39>:110' */
          } else {
            /* Transition: '<S39>:85' */
            /* '<S39>:105:1' sf_internal_predicateOutput = ... */
            /* '<S39>:105:1' InvTemp>PMSM_Param.InvOT1; */
            if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a >
                PMSM_Param.InvOT1) {
              /* Transition: '<S39>:105' */
              /* Transition: '<S39>:104' */
              /* '<S39>:104:1' TempCode(4)=1; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[3] = 1UL;

              /* '<S39>:104:1' TempCode(5)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[4] = 0UL;

              /* 控制器一级 */
              /* Transition: '<S39>:110' */
            } else {
              /* Transition: '<S39>:111' */
              /* '<S39>:111:1' TempCode(4)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[3] = 0UL;

              /* '<S39>:111:1' TempCode(5)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[4] = 0UL;
            }
          }
        }
      } else {
        /* Transition: '<S39>:83' */
        /* Transition: '<S39>:106' */
        /* Transition: '<S39>:114' */
      }

      /* End of Chart: '<S28>/Chart' */

      /* SignalConversion: '<S28>/BusConversion_InsertedFor_Temp_at_inport_0' */
      for (i = 0; i < 6; i++) {
        APP_FluxWeak_GEAR2_DW.TempCode[i] = APP_FluxWeak_GEAR2_DW.TempCode_g[i];
      }

      /* End of SignalConversion: '<S28>/BusConversion_InsertedFor_Temp_at_inport_0' */

      /* FunctionCaller: '<S28>/Function Caller' incorporates:
       *  Constant: '<S28>/Constant'
       *  Constant: '<S28>/Constant1'
       */
      APP_FluxWeak_GEAR2_Lim_coef
        (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c, PMSM_Param.MotOT1,
         PMSM_Param.MotOT2, &rtb_InvCoef);

      /* SignalConversion: '<S28>/BusConversion_InsertedFor_Temp_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.MotCoef = rtb_InvCoef;

      /* FunctionCaller: '<S28>/Function Caller1' incorporates:
       *  Constant: '<S28>/Constant2'
       *  Constant: '<S28>/Constant3'
       */
      APP_FluxWeak_GEAR2_Lim_coef
        (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a, PMSM_Param.InvOT1,
         PMSM_Param.InvOT2, &rtb_InvCoef);

      /* SignalConversion: '<S28>/BusConversion_InsertedFor_Temp_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.InvCoef = rtb_InvCoef;
    }

    /* End of RelationalOperator: '<S23>/Compare' */
    /* End of Outputs for SubSystem: '<S15>/Temp' */

    /* Outputs for Enabled SubSystem: '<S15>/Volt' incorporates:
     *  EnablePort: '<S30>/Enable'
     */
    if (rtb_MultiportSwitch) {
      /* Chart: '<S30>/Chart3' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read'
       */
      /* Gateway: implement/Fault/judgment/Volt/Chart3 */
      /* During: implement/Fault/judgment/Volt/Chart3 */
      /* Entry Internal: implement/Fault/judgment/Volt/Chart3 */
      /* Transition: '<S52>:39' */
      /* '<S52>:41:1' sf_internal_predicateOutput = ... */
      /* '<S52>:41:1' VoltCapFil<PMSM_Param.OV1; */
      if (DiscreteTimeIntegrator1_i4 < PMSM_Param.OV1) {
        /* Transition: '<S52>:41' */
        /* Transition: '<S52>:43' */
        /* '<S52>:43:1' Chg_coef=1; */
        rtb_InvCoef = 1.0F;

        /* '<S52>:43:1' VoltCode(1)=0; */
        APP_FluxWeak_GEAR2_DW.VoltCode_m[0] = 0UL;

        /* '<S52>:43:1' VoltCode(2)=0; */
        APP_FluxWeak_GEAR2_DW.VoltCode_m[1] = 0UL;

        /* '<S52>:65:1' sf_internal_predicateOutput = ... */
        /* '<S52>:65:1' ~MainRelayState; */
        if (PMSM_Input.AppComm.MainRelayState != 0U) {
          /* Transition: '<S52>:67' */
          /* '<S52>:69:1' sf_internal_predicateOutput = ... */
          /* '<S52>:69:1' VoltCapFil<PMSM_Param.LV2; */
          if (DiscreteTimeIntegrator1_i4 < PMSM_Param.LV2) {
            /* Transition: '<S52>:69' */
            /* Transition: '<S52>:71' */
            /* '<S52>:71:1' VoltCode(3)=0; */
            APP_FluxWeak_GEAR2_DW.VoltCode_m[2] = 0UL;

            /* '<S52>:71:1' VoltCode(4)=1; */
            APP_FluxWeak_GEAR2_DW.VoltCode_m[3] = 1UL;

            /* '<S52>:71:1' DisChg_coef=0; */
            APP_FluxWeak_GEAR2_DW.DisChg_coef = 0.0F;

            /* 欠压2 */
            /* Transition: '<S52>:81' */
            /* Transition: '<S52>:82' */
          } else {
            /* '<S52>:73:1' sf_internal_predicateOutput = ... */
            /* '<S52>:73:1' VoltCapFil<PMSM_Param.LV1; */
            if (DiscreteTimeIntegrator1_i4 < PMSM_Param.LV1) {
              /* Transition: '<S52>:73' */
              /* Transition: '<S52>:75' */
              /* '<S52>:75:1' VoltCode(3)=1; */
              APP_FluxWeak_GEAR2_DW.VoltCode_m[2] = 1UL;

              /* '<S52>:75:1' VoltCode(4)=0; */
              APP_FluxWeak_GEAR2_DW.VoltCode_m[3] = 0UL;

              /* '<S52>:75:1' DisChg_coef=Lim_coef(VoltCapFil,PMSM_Param.LV1,PMSM_Param.LV2); */
              APP_FluxWeak_GEAR2_Lim_coef(DiscreteTimeIntegrator1_i4,
                PMSM_Param.LV1, PMSM_Param.LV2,
                &APP_FluxWeak_GEAR2_DW.DisChg_coef);

              /* 欠压1 */
            } else {
              /* Transition: '<S52>:79' */
              /* '<S52>:79:1' DisChg_coef=1; */
              APP_FluxWeak_GEAR2_DW.DisChg_coef = 1.0F;

              /* '<S52>:79:1' VoltCode(3)=0; */
              APP_FluxWeak_GEAR2_DW.VoltCode_m[2] = 0UL;

              /* '<S52>:79:1' VoltCode(4)=0; */
              APP_FluxWeak_GEAR2_DW.VoltCode_m[3] = 0UL;

              /* Transition: '<S52>:82' */
            }
          }
        } else {
          /* Transition: '<S52>:65' */
          /* Transition: '<S52>:77' */
          /* Transition: '<S52>:80' */
          /* Transition: '<S52>:81' */
          /* Transition: '<S52>:82' */
        }

        /* Transition: '<S52>:83' */
      } else {
        /* Transition: '<S52>:45' */
        /* '<S52>:45:1' DisChg_coef=1; */
        APP_FluxWeak_GEAR2_DW.DisChg_coef = 1.0F;

        /* '<S52>:45:1' VoltCode(3)=0; */
        APP_FluxWeak_GEAR2_DW.VoltCode_m[2] = 0UL;

        /* '<S52>:45:1' VoltCode(4)=0; */
        APP_FluxWeak_GEAR2_DW.VoltCode_m[3] = 0UL;

        /* '<S52>:47:1' sf_internal_predicateOutput = ... */
        /* '<S52>:47:1' VoltCapFil>PMSM_Param.OV2; */
        if (DiscreteTimeIntegrator1_i4 > PMSM_Param.OV2) {
          /* Transition: '<S52>:47' */
          /* Transition: '<S52>:49' */
          /* '<S52>:49:1' VoltCode(1)=0; */
          APP_FluxWeak_GEAR2_DW.VoltCode_m[0] = 0UL;

          /* '<S52>:49:1' VoltCode(2)=1; */
          APP_FluxWeak_GEAR2_DW.VoltCode_m[1] = 1UL;

          /* '<S52>:49:1' Chg_coef=0; */
          rtb_InvCoef = 0.0F;

          /* 过压2 */
          /* Transition: '<S52>:53' */
        } else {
          /* Transition: '<S52>:51' */
          /* '<S52>:51:1' VoltCode(1)=1; */
          APP_FluxWeak_GEAR2_DW.VoltCode_m[0] = 1UL;

          /* '<S52>:51:1' VoltCode(2)=0; */
          APP_FluxWeak_GEAR2_DW.VoltCode_m[1] = 0UL;

          /* '<S52>:51:1' Chg_coef=Lim_coef(VoltCapFil,PMSM_Param.OV1,PMSM_Param.OV2); */
          APP_FluxWeak_GEAR2_Lim_coef(DiscreteTimeIntegrator1_i4, PMSM_Param.OV1,
            PMSM_Param.OV2, &rtb_InvCoef);

          /* 过压1 */
        }

        /* Transition: '<S52>:56' */
      }

      /* End of Chart: '<S30>/Chart3' */

      /* SignalConversion: '<S30>/BusConversion_InsertedFor_Volt_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.VoltCode[0] = APP_FluxWeak_GEAR2_DW.VoltCode_m[0];
      APP_FluxWeak_GEAR2_DW.VoltCode[1] = APP_FluxWeak_GEAR2_DW.VoltCode_m[1];
      APP_FluxWeak_GEAR2_DW.VoltCode[2] = APP_FluxWeak_GEAR2_DW.VoltCode_m[2];
      APP_FluxWeak_GEAR2_DW.VoltCode[3] = APP_FluxWeak_GEAR2_DW.VoltCode_m[3];

      /* Relay: '<S30>/Relay' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read'
       */
      if (PMSM_Input.AgoSample.Speed >= 20.0F) {
        APP_FluxWeak_GEAR2_DW.Relay_Mode = true;
      } else {
        if (PMSM_Input.AgoSample.Speed <= -20.0F) {
          APP_FluxWeak_GEAR2_DW.Relay_Mode = false;
        }
      }

      /* End of Relay: '<S30>/Relay' */

      /* SignalConversion: '<S30>/BusConversion_InsertedFor_Volt_at_inport_0' incorporates:
       *  Switch: '<S30>/Switch'
       */
      APP_FluxWeak_GEAR2_DW.OVLimTP_g = APP_FluxWeak_GEAR2_DW.DisChg_coef;

      /* SignalConversion: '<S30>/BusConversion_InsertedFor_Volt_at_inport_0' incorporates:
       *  Gain: '<S30>/Gain'
       *  Switch: '<S30>/Switch'
       */
      APP_FluxWeak_GEAR2_DW.OVLimTN_m = -rtb_InvCoef;
    }

    /* End of Outputs for SubSystem: '<S15>/Volt' */
    /* End of Outputs for SubSystem: '<S8>/judgment' */

    /* Outputs for Enabled SubSystem: '<S8>/Act' incorporates:
     *  EnablePort: '<S11>/Enable'
     */
    /* RelationalOperator: '<S13>/Compare' incorporates:
     *  Constant: '<S13>/Constant'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 9U) {
      /* MinMax: '<S11>/MinMax1' */
      APP_FluxWeak_GEAR2_DW.FaultLimTP = fminf(APP_FluxWeak_GEAR2_DW.OVLimTP_g,
        APP_FluxWeak_GEAR2_DW.OSLimTP);

      /* DataStoreWrite: '<S11>/Data Store Write' */
      AppFun.FaultLimTP = APP_FluxWeak_GEAR2_DW.FaultLimTP;

      /* MinMax: '<S11>/MinMax2' */
      APP_FluxWeak_GEAR2_DW.FaultLimTN = fmaxf(APP_FluxWeak_GEAR2_DW.OVLimTN_m,
        APP_FluxWeak_GEAR2_DW.OSLimTN);

      /* DataStoreWrite: '<S11>/Data Store Write1' */
      AppFun.FaultLimTN = APP_FluxWeak_GEAR2_DW.FaultLimTN;

      /* Logic: '<S11>/Logical Operator' */
      rtb_MultiportSwitch = !(APP_FluxWeak_GEAR2_DW.Compare ||
        (APP_FluxWeak_GEAR2_DW.TempCode[1] != 0UL) ||
        (APP_FluxWeak_GEAR2_DW.TempCode[2] != 0UL) ||
        (APP_FluxWeak_GEAR2_DW.TempCode[4] != 0UL) ||
        (APP_FluxWeak_GEAR2_DW.TempCode[5] != 0UL) || ((uint16_T)
        rtb_LogicalOperator != 0U));

      /* RateLimiter: '<S11>/Rate Limiter' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion'
       */
      rtb_Switch_b = (real32_T)rtb_MultiportSwitch -
        APP_FluxWeak_GEAR2_DW.PrevY_i;
      if (rtb_Switch_b > 0.002F) {
        APP_FluxWeak_GEAR2_DW.PrevY_i += 0.002F;
      } else if (rtb_Switch_b < -0.002F) {
        APP_FluxWeak_GEAR2_DW.PrevY_i += -0.002F;
      } else {
        APP_FluxWeak_GEAR2_DW.PrevY_i = rtb_MultiportSwitch;
      }

      /* End of RateLimiter: '<S11>/Rate Limiter' */

      /* DataStoreWrite: '<S11>/Data Store Write2' */
      AppFun.FaultCoef = APP_FluxWeak_GEAR2_DW.PrevY_i;

      /* Chart: '<S11>/Chart' */
      /* Gateway: implement/Fault/Act/Chart */
      /* During: implement/Fault/Act/Chart */
      /* Entry Internal: implement/Fault/Act/Chart */
      /* Transition: '<S16>:7' */
      /* '<S16>:8:1' sf_internal_predicateOutput = ... */
      /* '<S16>:8:1' ASCReq; */
      if (APP_FluxWeak_GEAR2_DW.SpdCode[1] != 0UL) {
        /* SignalConversion: '<S11>/OutportBufferForPwmWorkMode' */
        /* Transition: '<S16>:8' */
        /* Transition: '<S16>:10' */
        /* '<S16>:10:1' PwmWorkMode=2; */
        APP_FluxWeak_GEAR2_DW.OutportBufferForPwmWorkMode = 2U;

        /* Transition: '<S16>:15' */
        /* Transition: '<S16>:14' */
      } else {
        /* Transition: '<S16>:9' */
        /* '<S16>:11:1' sf_internal_predicateOutput = ... */
        /* '<S16>:11:1' CloseReq; */
        if (rtb_UVWoffline != 0U) {
          /* SignalConversion: '<S11>/OutportBufferForPwmWorkMode' */
          /* Transition: '<S16>:11' */
          /* Transition: '<S16>:13' */
          /* '<S16>:13:1' PwmWorkMode=0; */
          APP_FluxWeak_GEAR2_DW.OutportBufferForPwmWorkMode = 0U;

          /* Transition: '<S16>:14' */
        } else {
          /* SignalConversion: '<S11>/OutportBufferForPwmWorkMode' */
          /* Transition: '<S16>:12' */
          /* '<S16>:12:1' PwmWorkMode=1; */
          APP_FluxWeak_GEAR2_DW.OutportBufferForPwmWorkMode = 1U;
        }
      }

      /* End of Chart: '<S11>/Chart' */

      /* MinMax: '<S11>/MinMax' */
      /* Transition: '<S16>:16' */
      APP_FluxWeak_GEAR2_DW.MinMax = fminf(fminf(APP_FluxWeak_GEAR2_DW.PrevY_i,
        APP_FluxWeak_GEAR2_DW.MotCoef), APP_FluxWeak_GEAR2_DW.InvCoef);
    }

    /* End of RelationalOperator: '<S13>/Compare' */
    /* End of Outputs for SubSystem: '<S8>/Act' */

    /* SignalConversion: '<S8>/BusConversion_InsertedFor_Fault_at_inport_0' */
    APP_FluxWeak_GEAR2_DW.LimtCoef = APP_FluxWeak_GEAR2_DW.MinMax;

    /* SignalConversion: '<S8>/BusConversion_InsertedFor_Fault_at_inport_0' */
    APP_FluxWeak_GEAR2_DW.PwmWorkMode =
      APP_FluxWeak_GEAR2_DW.OutportBufferForPwmWorkMode;

    /* SignalConversion: '<S8>/BusConversion_InsertedFor_Fault_at_inport_0' */
    APP_FluxWeak_GEAR2_DW.OVLimTP = APP_FluxWeak_GEAR2_DW.FaultLimTP;

    /* SignalConversion: '<S8>/BusConversion_InsertedFor_Fault_at_inport_0' */
    APP_FluxWeak_GEAR2_DW.OVLimTN = APP_FluxWeak_GEAR2_DW.FaultLimTN;

    /* Outputs for Enabled SubSystem: '<S8>/Code' incorporates:
     *  EnablePort: '<S12>/Enable'
     */
    /* RelationalOperator: '<S14>/Compare' incorporates:
     *  Constant: '<S14>/Constant'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 8U) {
      /* S-Function (sfix_bitop): '<S12>/Bitwise Operator' incorporates:
       *  ArithShift: '<S12>/Shift Arithmetic1'
       *  ArithShift: '<S12>/Shift Arithmetic10'
       *  ArithShift: '<S12>/Shift Arithmetic11'
       *  ArithShift: '<S12>/Shift Arithmetic12'
       *  ArithShift: '<S12>/Shift Arithmetic13'
       *  ArithShift: '<S12>/Shift Arithmetic14'
       *  ArithShift: '<S12>/Shift Arithmetic15'
       *  ArithShift: '<S12>/Shift Arithmetic16'
       *  ArithShift: '<S12>/Shift Arithmetic17'
       *  ArithShift: '<S12>/Shift Arithmetic18'
       *  ArithShift: '<S12>/Shift Arithmetic19'
       *  ArithShift: '<S12>/Shift Arithmetic2'
       *  ArithShift: '<S12>/Shift Arithmetic20'
       *  ArithShift: '<S12>/Shift Arithmetic21'
       *  ArithShift: '<S12>/Shift Arithmetic22'
       *  ArithShift: '<S12>/Shift Arithmetic23'
       *  ArithShift: '<S12>/Shift Arithmetic24'
       *  ArithShift: '<S12>/Shift Arithmetic25'
       *  ArithShift: '<S12>/Shift Arithmetic26'
       *  ArithShift: '<S12>/Shift Arithmetic3'
       *  ArithShift: '<S12>/Shift Arithmetic4'
       *  ArithShift: '<S12>/Shift Arithmetic5'
       *  ArithShift: '<S12>/Shift Arithmetic6'
       *  ArithShift: '<S12>/Shift Arithmetic7'
       *  ArithShift: '<S12>/Shift Arithmetic8'
       *  ArithShift: '<S12>/Shift Arithmetic9'
       *  DataStoreRead: '<Root>/Data Store Read2'
       *  DataTypeConversion: '<S12>/Data Type Conversion'
       *  DataTypeConversion: '<S12>/Data Type Conversion1'
       */
      APP_FluxWeak_GEAR2_DW.BitwiseOperator = APP_FluxWeak_GEAR2_DW.VoltCode[0] <<
        1U | APP_FluxWeak_GEAR2_DW.Compare | APP_FluxWeak_GEAR2_DW.VoltCode[1] <<
        2U | APP_FluxWeak_GEAR2_DW.VoltCode[2] << 3U |
        APP_FluxWeak_GEAR2_DW.VoltCode[3] << 4U | APP_FluxWeak_GEAR2_DW.SpdCode
        [0] << 5U | APP_FluxWeak_GEAR2_DW.SpdCode[1] << 6U |
        APP_FluxWeak_GEAR2_DW.TempCode[0] << 7U |
        APP_FluxWeak_GEAR2_DW.TempCode[1] << 8U |
        APP_FluxWeak_GEAR2_DW.TempCode[2] << 9U |
        APP_FluxWeak_GEAR2_DW.TempCode[3] << 10U |
        APP_FluxWeak_GEAR2_DW.TempCode[4] << 11U |
        APP_FluxWeak_GEAR2_DW.TempCode[5] << 12U |
        APP_FluxWeak_GEAR2_DW.LogicalOperator1[0] << 13U |
        APP_FluxWeak_GEAR2_DW.LogicalOperator1[1] << 14U |
        APP_FluxWeak_GEAR2_DW.LogicalOperator2[0] << 15U |
        APP_FluxWeak_GEAR2_DW.LogicalOperator2[1] << 16U |
        APP_FluxWeak_GEAR2_DW.LogicalOperator2[2] << 17U | (uint32_T)
        rtb_LogicalOperator << 18U |
        APP_FluxWeak_GEAR2_DW.OutportBufferForDisChg << 19U |
        Algo_Output.Fault.IGBT << 20U | Algo_Output.Fault.OC1 << 21U |
        Algo_Output.Fault.OC2 << 22U | Algo_Output.Fault.OV3 << 23U |
        Algo_Output.Fault.LV3 << 24U | Algo_Output.Fault.PosSen << 25U |
        (uint32_T)rtb_UVWoffline << 26U;
    }

    /* End of RelationalOperator: '<S14>/Compare' */
    /* End of Outputs for SubSystem: '<S8>/Code' */

    /* SignalConversion: '<S8>/BusConversion_InsertedFor_Fault_at_inport_0' */
    APP_FluxWeak_GEAR2_DW.FaultCode1 = APP_FluxWeak_GEAR2_DW.BitwiseOperator;
  }

  /* End of Outputs for SubSystem: '<S2>/Fault' */

  /* Outputs for Enabled SubSystem: '<S2>/method' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (APP_FluxWeak_GEAR2_DW.RunSt == 2U) {
    if (!APP_FluxWeak_GEAR2_DW.method_MODE) {
      /* SystemReset for Atomic SubSystem: '<S142>/LimDrv' */

      /* SystemReset for Chart: '<S156>/Chart' */
      APP_FluxWeak_GEAR2_Chart_Reset(&APP_FluxWeak_GEAR2_DW.sf_Chart_c);

      /* End of SystemReset for SubSystem: '<S142>/LimDrv' */

      /* SystemReset for Atomic SubSystem: '<S142>/LimChg' */

      /* SystemReset for Chart: '<S150>/Chart' */
      APP_FluxWeak_GEAR2_Chart_Reset(&APP_FluxWeak_GEAR2_DW.sf_Chart_lj);

      /* End of SystemReset for SubSystem: '<S142>/LimChg' */

      /* SystemReset for Chart: '<S142>/Chart1' */
      APP_FluxWeak_GEAR2_DW.is_active_c20_APP_FluxWeak_GEAR = 0U;
      APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
        APP_FluxWe_IN_NO_ACTIVE_CHILD_c;

      /* SystemReset for Chart: '<S54>/Chart' */
      APP_FluxWeak_GEAR2_DW.temporalCounter_i1 = 0U;
      APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
      APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
      APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
      APP_FluxWeak_GEAR2_DW.is_active_c2_APP_FluxWeak_GEAR2 = 0U;
      APP_FluxWeak_GEAR2_DW.is_c2_APP_FluxWeak_GEAR2 =
        APP_FluxWe_IN_NO_ACTIVE_CHILD_c;

      /* Enable for Chart: '<S54>/Chart' incorporates:
       *  SubSystem: '<S54>/Slope'
       */
      APP_FluxWeak_GEAR2_Slope_Enable(&APP_FluxWeak_GEAR2_DW.Slope);

      /* SystemReset for Function Call SubSystem: '<S54>/Calib' */
      APP_FluxWeak_GEAR2_Calib_Reset(&APP_FluxWeak_GEAR2_DW.Calib);

      /* End of SystemReset for SubSystem: '<S54>/Calib' */

      /* Enable for Chart: '<S54>/Chart' incorporates:
       *  SubSystem: '<S54>/Calib'
       */
      APP_FluxWeak_GEAR2_Calib_Enable(&APP_FluxWeak_GEAR2_DW.Calib);
      if ((int16_T)APP_FluxWeak_GEAR2_DW.is_c2_APP_FluxWeak_GEAR2 == (int16_T)
          APP_FluxWeak_GEAR2_IN_UVWcheck) {
        /* SystemReset for Function Call SubSystem: '<S54>/UVW_check' */
        APP_FluxWeak_GE_UVW_check_Reset(&APP_FluxWeak_GEAR2_DW.UVW_check);

        /* End of SystemReset for SubSystem: '<S54>/UVW_check' */
      }

      APP_FluxWeak_GEAR2_DW.method_MODE = true;
    }

    /* Gain: '<S141>/Gain' */
    rtb_InvCoef = -APP_FluxWeak_GEAR2_DW.LimtCoef;

    /* DeadZone: '<S142>/Dead Zone' */
    if (DiscreteTimeIntegrator1 > 20.0F) {
      rtb_DeadZone = DiscreteTimeIntegrator1 - 20.0F;
    } else if (DiscreteTimeIntegrator1 >= -20.0F) {
      rtb_DeadZone = 0.0F;
    } else {
      rtb_DeadZone = DiscreteTimeIntegrator1 - -20.0F;
    }

    /* End of DeadZone: '<S142>/Dead Zone' */

    /* Outputs for Atomic SubSystem: '<S142>/LimDrv' */
    /* Abs: '<S155>/Abs' */
    rtb_Saturation1_i = fabsf(DiscreteTimeIntegrator1);

    /* Lookup_n-D: '<S155>/table' incorporates:
     *  Abs: '<S155>/Abs'
     */
    bpIdx = plook_u32ff_evenca(rtb_Saturation1_i, 1000.0F, 500.0F, 7UL,
      &rtb_Divide_p);
    rtb_Switch_b = intrp1d_fu32fla_pw(bpIdx, rtb_Divide_p,
      rtCP_table_tableData_o, 7UL);

    /* Saturate: '<S155>/Saturation1' incorporates:
     *  Abs: '<S155>/Abs'
     */
    if (rtb_Saturation1_i > 100000.0F) {
      rtb_Saturation1_i = 100000.0F;
    } else {
      if (rtb_Saturation1_i < 1.0F) {
        rtb_Saturation1_i = 1.0F;
      }
    }

    /* End of Saturate: '<S155>/Saturation1' */

    /* Product: '<S155>/Divide' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     *  Gain: '<S155>/Gain'
     *  Product: '<S155>/Product'
     */
    rtb_Divide_p = DiscreteTimeIntegrator1_i4 * PMSM_Input.AppComm.DrvLimCur *
      9.55F * rtb_Switch_b / rtb_Saturation1_i;

    /* FunctionCaller: '<S155>/Function Caller' */
    APP_FluxWeak_GEAR2_n2MaxT(rtb_Psi_i, &rtb_Switch_b);

    /* Product: '<S155>/Divide1' */
    rtb_Switch_b = rtb_Divide_p / rtb_Switch_b;

    /* Saturate: '<S155>/Saturation' */
    if (rtb_Switch_b > 1.0F) {
      rtb_Switch_b = 1.0F;
    } else {
      if (rtb_Switch_b < 0.0F) {
        rtb_Switch_b = 0.0F;
      }
    }

    /* End of Saturate: '<S155>/Saturation' */

    /* Chart: '<S156>/Chart' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     *  Sum: '<S148>/Sum'
     */
    APP_FluxWeak_GEAR2_Chart(PMSM_Input.AppComm.DrvLimCur -
      rtb_DiscreteTimeIntegrator1, &rtb_Divide_p,
      &APP_FluxWeak_GEAR2_DW.sf_Chart_c);

    /* Sum: '<S148>/Add' */
    rtb_Switch_b += rtb_Divide_p;

    /* Saturate: '<S148>/Saturation' */
    if (rtb_Switch_b > 1.0F) {
      rtb_Switch_b = 1.0F;
    } else {
      if (rtb_Switch_b < 0.0F) {
        rtb_Switch_b = 0.0F;
      }
    }

    /* End of Saturate: '<S148>/Saturation' */
    /* End of Outputs for SubSystem: '<S142>/LimDrv' */

    /* Outputs for Atomic SubSystem: '<S142>/LimChg' */
    /* Abs: '<S147>/Abs' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    rtb_Saturation1_i = fabsf(PMSM_Input.AppComm.GenLimCur);

    /* Abs: '<S149>/Abs' */
    rtb_Saturation1 = fabsf(DiscreteTimeIntegrator1);

    /* Lookup_n-D: '<S149>/table' incorporates:
     *  Abs: '<S149>/Abs'
     */
    bpIdx = plook_u32ff_evenca(rtb_Saturation1, 1400.0F, 200.0F, 2UL,
      &rtb_Divide_p);
    rtb_Divide_p = intrp1d_fu32fla_pw(bpIdx, rtb_Divide_p, rtCP_table_tableData,
      2UL);

    /* Saturate: '<S149>/Saturation1' incorporates:
     *  Abs: '<S149>/Abs'
     */
    if (rtb_Saturation1 > 100000.0F) {
      rtb_Saturation1 = 100000.0F;
    } else {
      if (rtb_Saturation1 < 1.0F) {
        rtb_Saturation1 = 1.0F;
      }
    }

    /* End of Saturate: '<S149>/Saturation1' */

    /* Product: '<S149>/Divide' incorporates:
     *  Gain: '<S149>/Gain'
     *  Product: '<S149>/Product'
     */
    rtb_Saturation1 = DiscreteTimeIntegrator1_i4 * rtb_Saturation1_i * 9.55F /
      rtb_Divide_p / rtb_Saturation1;

    /* FunctionCaller: '<S149>/Function Caller' */
    APP_FluxWeak_GEAR2_n2MaxT(rtb_Psi_i, &rtb_Divide_p);

    /* Product: '<S149>/Divide1' */
    rtb_Divide_p = rtb_Saturation1 / rtb_Divide_p;

    /* Saturate: '<S149>/Saturation' */
    if (rtb_Divide_p > 1.0F) {
      rtb_Divide_p = 1.0F;
    } else {
      if (rtb_Divide_p < 0.0F) {
        rtb_Divide_p = 0.0F;
      }
    }

    /* End of Saturate: '<S149>/Saturation' */

    /* Chart: '<S150>/Chart' incorporates:
     *  Abs: '<S147>/Abs1'
     *  Sum: '<S147>/Sum'
     */
    APP_FluxWeak_GEAR2_Chart(rtb_Saturation1_i - fabsf
      (rtb_DiscreteTimeIntegrator1), &rtb_Saturation1,
      &APP_FluxWeak_GEAR2_DW.sf_Chart_lj);

    /* Sum: '<S147>/Add' */
    rtb_Divide_p += rtb_Saturation1;

    /* Saturate: '<S147>/Saturation' */
    if (rtb_Divide_p > 1.0F) {
      rtb_Divide_p = 1.0F;
    } else {
      if (rtb_Divide_p < 0.0F) {
        rtb_Divide_p = 0.0F;
      }
    }

    /* End of Saturate: '<S147>/Saturation' */
    /* End of Outputs for SubSystem: '<S142>/LimChg' */

    /* Chart: '<S142>/Chart1' */
    /* Gateway: implement/method/Lim&Fault/LimI/Chart1 */
    /* During: implement/method/Lim&Fault/LimI/Chart1 */
    if (APP_FluxWeak_GEAR2_DW.is_active_c20_APP_FluxWeak_GEAR == 0U) {
      /* Entry: implement/method/Lim&Fault/LimI/Chart1 */
      APP_FluxWeak_GEAR2_DW.is_active_c20_APP_FluxWeak_GEAR = 1U;

      /* Entry Internal: implement/method/Lim&Fault/LimI/Chart1 */
      /* Transition: '<S146>:7' */
      APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
        APP_FluxWeak_GEAR2_IN_ZreoSpd;

      /* Entry 'ZreoSpd': '<S146>:6' */
      /* '<S146>:6:1' LimTP_I = DrvLimit; */
      rtb_DeadZone = rtb_Switch_b;

      /* '<S146>:6:1' LimTN_I = -DrvLimit; */
      rtb_Divide_p = -rtb_Switch_b;
    } else {
      switch (APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2) {
       case APP_FluxWeak_GEAR2_IN_NegSpd:
        /* During 'NegSpd': '<S146>:20' */
        /* '<S146>:22:1' sf_internal_predicateOutput = ... */
        /* '<S146>:22:1' Spd >= 0; */
        if (rtb_DeadZone >= 0.0F) {
          /* Transition: '<S146>:22' */
          APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
            APP_FluxWeak_GEAR2_IN_ZreoSpd;

          /* Entry 'ZreoSpd': '<S146>:6' */
          /* '<S146>:6:1' LimTP_I = DrvLimit; */
          rtb_DeadZone = rtb_Switch_b;

          /* '<S146>:6:1' LimTN_I = -DrvLimit; */
          rtb_Divide_p = -rtb_Switch_b;
        } else {
          /* '<S146>:20:1' LimTP_I = ChgLimit; */
          rtb_DeadZone = rtb_Divide_p;

          /* '<S146>:20:1' LimTN_I = -DrvLimit; */
          rtb_Divide_p = -rtb_Switch_b;
        }
        break;

       case APP_FluxWeak_GEAR2_IN_PosSpd:
        /* During 'PosSpd': '<S146>:18' */
        /* '<S146>:19:1' sf_internal_predicateOutput = ... */
        /* '<S146>:19:1' Spd <= 0; */
        if (rtb_DeadZone <= 0.0F) {
          /* Transition: '<S146>:19' */
          APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
            APP_FluxWeak_GEAR2_IN_ZreoSpd;

          /* Entry 'ZreoSpd': '<S146>:6' */
          /* '<S146>:6:1' LimTP_I = DrvLimit; */
          rtb_DeadZone = rtb_Switch_b;

          /* '<S146>:6:1' LimTN_I = -DrvLimit; */
          rtb_Divide_p = -rtb_Switch_b;
        } else {
          /* '<S146>:18:1' LimTP_I = DrvLimit; */
          rtb_DeadZone = rtb_Switch_b;

          /* '<S146>:18:1' LimTN_I = -ChgLimit; */
          rtb_Divide_p = -rtb_Divide_p;
        }
        break;

       default:
        /* During 'ZreoSpd': '<S146>:6' */
        /* '<S146>:17:1' sf_internal_predicateOutput = ... */
        /* '<S146>:17:1' Spd > 0; */
        if (rtb_DeadZone > 0.0F) {
          /* Transition: '<S146>:17' */
          APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
            APP_FluxWeak_GEAR2_IN_PosSpd;

          /* Entry 'PosSpd': '<S146>:18' */
          /* '<S146>:18:1' LimTP_I = DrvLimit; */
          rtb_DeadZone = rtb_Switch_b;

          /* '<S146>:18:1' LimTN_I = -ChgLimit; */
          rtb_Divide_p = -rtb_Divide_p;
        } else {
          /* '<S146>:21:1' sf_internal_predicateOutput = ... */
          /* '<S146>:21:1' Spd < 0; */
          if (rtb_DeadZone < 0.0F) {
            /* Transition: '<S146>:21' */
            APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
              APP_FluxWeak_GEAR2_IN_NegSpd;

            /* Entry 'NegSpd': '<S146>:20' */
            /* '<S146>:20:1' LimTP_I = ChgLimit; */
            rtb_DeadZone = rtb_Divide_p;

            /* '<S146>:20:1' LimTN_I = -DrvLimit; */
            rtb_Divide_p = -rtb_Switch_b;
          } else {
            /* '<S146>:6:1' LimTP_I = DrvLimit; */
            rtb_DeadZone = rtb_Switch_b;

            /* '<S146>:6:1' LimTN_I = -DrvLimit; */
            rtb_Divide_p = -rtb_Switch_b;
          }
        }
        break;
      }
    }

    /* End of Chart: '<S142>/Chart1' */

    /* MinMax: '<S141>/MinMax2' */
    rtb_InvCoef = fmaxf(fmaxf(rtb_InvCoef, rtb_Divide_p),
                        APP_FluxWeak_GEAR2_DW.OVLimTN);

    /* MinMax: '<S141>/MinMax1' */
    rtb_Saturation1_i = fminf(fminf(APP_FluxWeak_GEAR2_DW.OVLimTP, rtb_DeadZone),
      APP_FluxWeak_GEAR2_DW.LimtCoef);

    /* Chart: '<S54>/Chart' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     *  DataStoreRead: '<Root>/Data Store Read2'
     */
    /* Gateway: implement/method/All_loop/Chart */
    if (APP_FluxWeak_GEAR2_DW.temporalCounter_i1 < 255U) {
      APP_FluxWeak_GEAR2_DW.temporalCounter_i1 = ((int16_T)
        APP_FluxWeak_GEAR2_DW.temporalCounter_i1 + 1) & 255U;
    }

    rtb_UVWoffline = APP_FluxWeak_GEAR2_DW.ModeSt_start;
    APP_FluxWeak_GEAR2_DW.ModeSt_start = APP_FluxWeak_GEAR2_DW.ModeSt;

    /* During: implement/method/All_loop/Chart */
    if (APP_FluxWeak_GEAR2_DW.is_active_c2_APP_FluxWeak_GEAR2 == 0U) {
      /* Entry: implement/method/All_loop/Chart */
      APP_FluxWeak_GEAR2_DW.is_active_c2_APP_FluxWeak_GEAR2 = 1U;

      /* Outputs for Function Call SubSystem: '<S54>/Initial' */

      /* Entry Internal: implement/method/All_loop/Chart */
      /* Transition: '<S63>:84' */
      /* '<S63>:84:1' Initial; */
      /* Event: '<S63>:12' */
      APP_FluxWeak_GEAR2_Initial();

      /* End of Outputs for SubSystem: '<S54>/Initial' */
      APP_FluxWeak_GEAR2_DW.is_c2_APP_FluxWeak_GEAR2 =
        APP_FluxWeak_GEAR2_IN_UVWcheck;
      APP_FluxWeak_GEAR2_DW.temporalCounter_i1 = 0U;

      /* SystemReset for Function Call SubSystem: '<S54>/UVW_check' */

      /* Entry 'UVWcheck': '<S63>:86' */
      APP_FluxWeak_GE_UVW_check_Reset(&APP_FluxWeak_GEAR2_DW.UVW_check);

      /* End of SystemReset for SubSystem: '<S54>/UVW_check' */

      /* Outputs for Function Call SubSystem: '<S54>/UVW_check' */

      /* '<S63>:86:1' UVWcheck; */
      /* Event: '<S63>:87' */
      APP_FluxWeak_GEAR2_UVW_check(PMSM_Input.AgoSample.CurUPu,
        PMSM_Input.AgoSample.CurVPu, PMSM_Input.AgoSample.CurWPu,
        &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
        &APP_FluxWeak_GEAR2_DW.IqRefSet_m, &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
        &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d, &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
        &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
        &APP_FluxWeak_GEAR2_DW.OutportBufferForUVWFault,
        &APP_FluxWeak_GEAR2_DW.UVW_check);

      /* End of Outputs for SubSystem: '<S54>/UVW_check' */
    } else if (APP_FluxWeak_GEAR2_DW.is_c2_APP_FluxWeak_GEAR2 == 1U) {
      /* During 'UVWcheck': '<S63>:86' */
      /* '<S63>:88:1' sf_internal_predicateOutput = ... */
      /* '<S63>:88:1' after(250,tick); */
      if ((int16_T)APP_FluxWeak_GEAR2_DW.temporalCounter_i1 >= 250) {
        /* Transition: '<S63>:88' */
        /* Exit 'UVWcheck': '<S63>:86' */
        APP_FluxWeak_GEAR2_DW.is_c2_APP_FluxWeak_GEAR2 =
          APP_FluxWeak_GEAR2_IN_sys_mode;

        /* Outputs for Function Call SubSystem: '<S54>/Initial' */

        /* Entry Internal 'sys_mode': '<S63>:7' */
        /* Transition: '<S63>:4' */
        /* '<S63>:4:1' Initial; */
        /* Event: '<S63>:12' */
        APP_FluxWeak_GEAR2_Initial();

        /* End of Outputs for SubSystem: '<S54>/Initial' */

        /* '<S63>:9:1' sf_internal_predicateOutput = ... */
        /* '<S63>:9:1' ModeSt==0; */
        switch (APP_FluxWeak_GEAR2_DW.ModeSt) {
         case 0U:
          /* Transition: '<S63>:9' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Torque;

          /* Outputs for Function Call SubSystem: '<S54>/Torque' */

          /* Entry 'Torque': '<S63>:3' */
          /* '<S63>:3:1' Torque; */
          /* Event: '<S63>:10' */
          APP_FluxWeak_GEAR2_Torque(PMSM_Input.AppComm.TqReq,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Torque);

          /* End of Outputs for SubSystem: '<S54>/Torque' */
          break;

         case 1U:
          /* Transition: '<S63>:36' */
          /* '<S63>:37:1' sf_internal_predicateOutput = ... */
          /* '<S63>:37:1' ModeSt==1; */
          /* Transition: '<S63>:37' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Spd;

          /* Outputs for Function Call SubSystem: '<S54>/Spd' */

          /* Entry 'Spd': '<S63>:14' */
          /* '<S63>:14:1' Spd; */
          /* Event: '<S63>:16' */
          APP_FluxWeak_GEAR2_Spd(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Spd_g);

          /* End of Outputs for SubSystem: '<S54>/Spd' */
          break;

         case 2U:
          /* Transition: '<S63>:38' */
          /* '<S63>:39:1' sf_internal_predicateOutput = ... */
          /* '<S63>:39:1' ModeSt==2; */
          /* Transition: '<S63>:39' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Genrate;

          /* Outputs for Function Call SubSystem: '<S54>/Genrate' */

          /* Entry 'Genrate': '<S63>:18' */
          /* '<S63>:18:1' Genrate; */
          /* Event: '<S63>:19' */
          APP_FluxWeak_GEAR2_Genrate(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Genrate);

          /* End of Outputs for SubSystem: '<S54>/Genrate' */
          break;

         case 3U:
          /* Transition: '<S63>:76' */
          /* '<S63>:77:1' sf_internal_predicateOutput = ... */
          /* '<S63>:77:1' ModeSt==3; */
          /* Transition: '<S63>:77' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Starter;

          /* Outputs for Function Call SubSystem: '<S54>/Starter' */

          /* Entry 'Starter': '<S63>:72' */
          /* '<S63>:72:1' Starter; */
          /* Event: '<S63>:74' */
          APP_FluxWeak_GEAR2_Starter(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Starter);

          /* End of Outputs for SubSystem: '<S54>/Starter' */
          break;

         case 4U:
          /* Transition: '<S63>:40' */
          /* '<S63>:41:1' sf_internal_predicateOutput = ... */
          /* '<S63>:41:1' ModeSt==4; */
          /* Transition: '<S63>:41' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Slope;

          /* Outputs for Function Call SubSystem: '<S54>/Slope' */

          /* Entry 'Slope': '<S63>:20' */
          /* '<S63>:20:1' Slope; */
          /* Event: '<S63>:21' */
          APP_FluxWeak_GEAR2_Slope(PMSM_Input.AgoSample.Speed,
            DiscreteTimeIntegrator1, PMSM_Input.AppComm.GearState,
            PMSM_Input.AppSample.KsiSt, DiscreteTimeIntegrator1_i,
            PMSM_Input.AppComm.TqReq, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Slope);

          /* End of Outputs for SubSystem: '<S54>/Slope' */
          break;

         case 5U:
          /* Transition: '<S63>:43' */
          /* '<S63>:42:1' sf_internal_predicateOutput = ... */
          /* '<S63>:42:1' ModeSt==5; */
          /* Transition: '<S63>:42' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Sync;

          /* Outputs for Function Call SubSystem: '<S54>/Sync' */

          /* Entry 'Sync': '<S63>:22' */
          /* '<S63>:22:1' Sync; */
          /* Event: '<S63>:23' */
          APP_FluxWeak_GEAR2_Sync(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Sync);

          /* End of Outputs for SubSystem: '<S54>/Sync' */
          break;

         case 6U:
          /* Transition: '<S63>:44' */
          /* '<S63>:45:1' sf_internal_predicateOutput = ... */
          /* '<S63>:45:1' ModeSt==6; */
          /* Transition: '<S63>:45' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_Dischg;

          /* Outputs for Function Call SubSystem: '<S54>/Dischg' */

          /* Entry 'Dischg': '<S63>:25' */
          /* '<S63>:25:1' Dischg; */
          /* Event: '<S63>:27' */
          APP_FluxWeak_GEAR2_Dischg(DiscreteTimeIntegrator1_i4,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Dischg);

          /* End of Outputs for SubSystem: '<S54>/Dischg' */
          break;

         case 7U:
          /* Transition: '<S63>:46' */
          /* '<S63>:50:1' sf_internal_predicateOutput = ... */
          /* '<S63>:50:1' ModeSt==7; */
          /* Transition: '<S63>:50' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_ASC;

          /* Outputs for Function Call SubSystem: '<S54>/ASC' */

          /* Entry 'ASC': '<S63>:48' */
          /* '<S63>:48:1' ASC; */
          /* Event: '<S63>:49' */
          APP_FluxWeak_GEAR2_ASC(&APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b);

          /* End of Outputs for SubSystem: '<S54>/ASC' */
          break;

         default:
          /* Transition: '<S63>:52' */
          /* Transition: '<S63>:53' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_standard;

          /* Outputs for Function Call SubSystem: '<S54>/Calib' */

          /* Entry 'standard': '<S63>:28' */
          /* 标定 */
          /* '<S63>:28:1' Calib; */
          /* Event: '<S63>:29' */
          APP_FluxWeak_GEAR2_Calib(PMSM_Input.AppSample.CalibStep,
            PMSM_Input.AgoSample.ThetaRT, PMSM_Input.AppComm.TqReq,
            PMSM_Input.AppSample.ElecZeroStep, Algo_Output.Cur_loop.Ud, Vs,
            PMSM_Input.AppSample.ExtTorque, PMSM_Input.AppSample.CalibMTPATheta,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Calib);

          /* End of Outputs for SubSystem: '<S54>/Calib' */
          break;
        }
      } else {
        /* Outputs for Function Call SubSystem: '<S54>/UVW_check' */

        /* '<S63>:86:1' UVWcheck; */
        /* Event: '<S63>:87' */
        APP_FluxWeak_GEAR2_UVW_check(PMSM_Input.AgoSample.CurUPu,
          PMSM_Input.AgoSample.CurVPu, PMSM_Input.AgoSample.CurWPu,
          &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
          &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
          &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
          &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
          &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
          &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
          &APP_FluxWeak_GEAR2_DW.OutportBufferForUVWFault,
          &APP_FluxWeak_GEAR2_DW.UVW_check);

        /* End of Outputs for SubSystem: '<S54>/UVW_check' */
      }
    } else {
      /* Outputs for Function Call SubSystem: '<S54>/IntLim' */
      /* Switch: '<S106>/Switch2' incorporates:
       *  RelationalOperator: '<S106>/LowerRelop1'
       *  RelationalOperator: '<S106>/UpperRelop'
       *  StateReader: '<S68>/State Reader1'
       *  Switch: '<S106>/Switch'
       */
      /* During 'sys_mode': '<S63>:7' */
      /* '<S63>:7:1' IntLim; */
      /* Event: '<S63>:78' */
      if (APP_FluxWeak_GEAR2_DW.Slope.PI.I_state > rtb_Saturation1_i) {
        rtb_Switch_b = rtb_Saturation1_i;
      } else if (APP_FluxWeak_GEAR2_DW.Slope.PI.I_state < rtb_InvCoef) {
        /* Switch: '<S106>/Switch' */
        rtb_Switch_b = rtb_InvCoef;
      } else {
        rtb_Switch_b = APP_FluxWeak_GEAR2_DW.Slope.PI.I_state;
      }

      /* End of Switch: '<S106>/Switch2' */

      /* Saturate: '<S68>/Saturation2' */
      if (rtb_Switch_b > PMSM_Param.SlopeMaxT) {
        rtb_Switch_b = PMSM_Param.SlopeMaxT;
      } else {
        if (rtb_Switch_b < -PMSM_Param.SlopeMaxT) {
          rtb_Switch_b = -PMSM_Param.SlopeMaxT;
        }
      }

      /* End of Saturate: '<S68>/Saturation2' */

      /* Chart: '<S68>/Chart' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read'
       */
      /* Gateway: implement/method/All_loop/IntLim/Chart */
      /* During: implement/method/All_loop/IntLim/Chart */
      /* Entry Internal: implement/method/All_loop/IntLim/Chart */
      /* Transition: '<S101>:4' */
      /* '<S101>:5:1' sf_internal_predicateOutput = ... */
      /* '<S101>:5:1' Gear==1; */
      switch (PMSM_Input.AppComm.GearState) {
       case 1U:
        /* Transition: '<S101>:5' */
        /* Transition: '<S101>:7' */
        /* '<S101>:7:1' out=max(0,In); */
        if (0.0F > rtb_Switch_b) {
          /* StateWriter: '<S68>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;
        } else if (rtIsNaNF(rtb_Switch_b)) {
          /* StateWriter: '<S68>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;
        } else {
          /* StateWriter: '<S68>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = rtb_Switch_b;
        }

        /* Transition: '<S101>:12' */
        /* Transition: '<S101>:11' */
        break;

       case 2U:
        /* Transition: '<S101>:6' */
        /* '<S101>:8:1' sf_internal_predicateOutput = ... */
        /* '<S101>:8:1' Gear==2; */
        /* Transition: '<S101>:8' */
        /* Transition: '<S101>:10' */
        /* '<S101>:10:1' out=min(0,In); */
        if (0.0F < rtb_Switch_b) {
          /* StateWriter: '<S68>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;

          /* Transition: '<S101>:11' */
        } else if (rtIsNaNF(rtb_Switch_b)) {
          /* StateWriter: '<S68>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;

          /* Transition: '<S101>:11' */
        } else {
          /* StateWriter: '<S68>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = rtb_Switch_b;

          /* Transition: '<S101>:11' */
        }
        break;

       default:
        /* StateWriter: '<S68>/State Writer1' */
        /* Transition: '<S101>:9' */
        /* '<S101>:9:1' out=0; */
        APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;
        break;
      }

      /* End of Chart: '<S68>/Chart' */

      /* Switch: '<S105>/Switch2' incorporates:
       *  RelationalOperator: '<S105>/LowerRelop1'
       *  RelationalOperator: '<S105>/UpperRelop'
       *  StateReader: '<S68>/State Reader2'
       *  Switch: '<S105>/Switch'
       */
      /* Transition: '<S101>:13' */
      if (APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state > rtb_Saturation1_i) {
        rtb_Switch_b = rtb_Saturation1_i;
      } else if (APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state < rtb_InvCoef) {
        /* Switch: '<S105>/Switch' */
        rtb_Switch_b = rtb_InvCoef;
      } else {
        rtb_Switch_b = APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state;
      }

      /* End of Switch: '<S105>/Switch2' */

      /* Saturate: '<S68>/Saturation3' */
      if (rtb_Switch_b > 1.0F) {
        rtb_Switch_b = 1.0F;
      } else {
        if (rtb_Switch_b < -1.0F) {
          rtb_Switch_b = -1.0F;
        }
      }

      /* End of Saturate: '<S68>/Saturation3' */

      /* Switch: '<S68>/Switch' incorporates:
       *  Abs: '<S68>/Abs'
       */
      if (fabsf(DiscreteTimeIntegrator1_i) > 10.0F) {
        /* StateWriter: '<S68>/State Writer2' */
        APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state = rtb_Switch_b;
      } else {
        /* StateWriter: '<S68>/State Writer2' incorporates:
         *  Gain: '<S68>/N'
         *  Gain: '<S68>/Ts'
         *  Sum: '<S68>/Subtract'
         */
        APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state = rtb_Switch_b - 20.0F *
          rtb_Switch_b * 0.002F;
      }

      /* End of Switch: '<S68>/Switch' */

      /* Switch: '<S104>/Switch2' incorporates:
       *  RelationalOperator: '<S104>/LowerRelop1'
       *  RelationalOperator: '<S104>/UpperRelop'
       *  StateReader: '<S68>/State Reader3'
       *  Switch: '<S104>/Switch'
       */
      if (APP_FluxWeak_GEAR2_DW.Sync.PI.I_state > rtb_Saturation1_i) {
        /* StateWriter: '<S68>/State Writer3' */
        APP_FluxWeak_GEAR2_DW.Sync.PI.I_state = rtb_Saturation1_i;
      } else {
        if (APP_FluxWeak_GEAR2_DW.Sync.PI.I_state < rtb_InvCoef) {
          /* Switch: '<S104>/Switch' incorporates:
           *  StateWriter: '<S68>/State Writer3'
           */
          APP_FluxWeak_GEAR2_DW.Sync.PI.I_state = rtb_InvCoef;
        }
      }

      /* End of Switch: '<S104>/Switch2' */

      /* Switch: '<S103>/Switch2' incorporates:
       *  RelationalOperator: '<S103>/LowerRelop1'
       *  RelationalOperator: '<S103>/UpperRelop'
       *  StateReader: '<S68>/State Reader4'
       *  Switch: '<S103>/Switch'
       */
      if (APP_FluxWeak_GEAR2_DW.Starter.PI.I_state > rtb_Saturation1_i) {
        rtb_Switch_b = rtb_Saturation1_i;
      } else if (APP_FluxWeak_GEAR2_DW.Starter.PI.I_state < rtb_InvCoef) {
        /* Switch: '<S103>/Switch' */
        rtb_Switch_b = rtb_InvCoef;
      } else {
        rtb_Switch_b = APP_FluxWeak_GEAR2_DW.Starter.PI.I_state;
      }

      /* End of Switch: '<S103>/Switch2' */

      /* Saturate: '<S68>/Saturation1' */
      if (rtb_Switch_b > 1.0F) {
        /* StateWriter: '<S68>/State Writer4' */
        APP_FluxWeak_GEAR2_DW.Starter.PI.I_state = 1.0F;
      } else if (rtb_Switch_b < 0.0F) {
        /* StateWriter: '<S68>/State Writer4' */
        APP_FluxWeak_GEAR2_DW.Starter.PI.I_state = 0.0F;
      } else {
        /* StateWriter: '<S68>/State Writer4' */
        APP_FluxWeak_GEAR2_DW.Starter.PI.I_state = rtb_Switch_b;
      }

      /* End of Saturate: '<S68>/Saturation1' */

      /* Switch: '<S102>/Switch2' incorporates:
       *  RelationalOperator: '<S102>/LowerRelop1'
       *  RelationalOperator: '<S102>/UpperRelop'
       *  StateReader: '<S68>/State Reader5'
       *  Switch: '<S102>/Switch'
       */
      if (APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE > rtb_Saturation1_i) {
        /* StateWriter: '<S68>/State Writer5' */
        APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE = rtb_Saturation1_i;
      } else {
        if (APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE < rtb_InvCoef) {
          /* Switch: '<S102>/Switch' incorporates:
           *  StateWriter: '<S68>/State Writer5'
           */
          APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE = rtb_InvCoef;
        }
      }

      /* End of Switch: '<S102>/Switch2' */

      /* Switch: '<S107>/Switch2' incorporates:
       *  RelationalOperator: '<S107>/LowerRelop1'
       *  RelationalOperator: '<S107>/UpperRelop'
       *  StateReader: '<S68>/State Reader'
       *  Switch: '<S107>/Switch'
       */
      if (APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state > rtb_Saturation1_i) {
        rtb_Switch_b = rtb_Saturation1_i;
      } else if (APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state < rtb_InvCoef) {
        /* Switch: '<S107>/Switch' */
        rtb_Switch_b = rtb_InvCoef;
      } else {
        rtb_Switch_b = APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state;
      }

      /* End of Switch: '<S107>/Switch2' */

      /* Saturate: '<S68>/Saturation' */
      if (rtb_Switch_b > 0.0F) {
        /* StateWriter: '<S68>/State Writer6' */
        APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state = 0.0F;
      } else if (rtb_Switch_b < -1.0F) {
        /* StateWriter: '<S68>/State Writer6' */
        APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state = -1.0F;
      } else {
        /* StateWriter: '<S68>/State Writer6' */
        APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state = rtb_Switch_b;
      }

      /* End of Saturate: '<S68>/Saturation' */
      /* End of Outputs for SubSystem: '<S54>/IntLim' */
      /* '<S63>:57:1' sf_internal_predicateOutput = ... */
      /* '<S63>:57:1' hasChanged (ModeSt); */
      if (rtb_UVWoffline != APP_FluxWeak_GEAR2_DW.ModeSt_start) {
        /* Transition: '<S63>:57' */
        /* '<S63>:9:1' sf_internal_predicateOutput = ... */
        /* '<S63>:9:1' ModeSt==0; */
        switch (APP_FluxWeak_GEAR2_DW.ModeSt) {
         case 0U:
          /* Transition: '<S63>:9' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Torque;

          /* Outputs for Function Call SubSystem: '<S54>/Torque' */

          /* Entry 'Torque': '<S63>:3' */
          /* '<S63>:3:1' Torque; */
          /* Event: '<S63>:10' */
          APP_FluxWeak_GEAR2_Torque(PMSM_Input.AppComm.TqReq,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Torque);

          /* End of Outputs for SubSystem: '<S54>/Torque' */
          break;

         case 1U:
          /* Transition: '<S63>:36' */
          /* '<S63>:37:1' sf_internal_predicateOutput = ... */
          /* '<S63>:37:1' ModeSt==1; */
          /* Transition: '<S63>:37' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Spd;

          /* Outputs for Function Call SubSystem: '<S54>/Spd' */

          /* Entry 'Spd': '<S63>:14' */
          /* '<S63>:14:1' Spd; */
          /* Event: '<S63>:16' */
          APP_FluxWeak_GEAR2_Spd(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Spd_g);

          /* End of Outputs for SubSystem: '<S54>/Spd' */
          break;

         case 2U:
          /* Transition: '<S63>:38' */
          /* '<S63>:39:1' sf_internal_predicateOutput = ... */
          /* '<S63>:39:1' ModeSt==2; */
          /* Transition: '<S63>:39' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Genrate;

          /* Outputs for Function Call SubSystem: '<S54>/Genrate' */

          /* Entry 'Genrate': '<S63>:18' */
          /* '<S63>:18:1' Genrate; */
          /* Event: '<S63>:19' */
          APP_FluxWeak_GEAR2_Genrate(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Genrate);

          /* End of Outputs for SubSystem: '<S54>/Genrate' */
          break;

         case 3U:
          /* Transition: '<S63>:76' */
          /* '<S63>:77:1' sf_internal_predicateOutput = ... */
          /* '<S63>:77:1' ModeSt==3; */
          /* Transition: '<S63>:77' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Starter;

          /* Outputs for Function Call SubSystem: '<S54>/Starter' */

          /* Entry 'Starter': '<S63>:72' */
          /* '<S63>:72:1' Starter; */
          /* Event: '<S63>:74' */
          APP_FluxWeak_GEAR2_Starter(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Starter);

          /* End of Outputs for SubSystem: '<S54>/Starter' */
          break;

         case 4U:
          /* Transition: '<S63>:40' */
          /* '<S63>:41:1' sf_internal_predicateOutput = ... */
          /* '<S63>:41:1' ModeSt==4; */
          /* Transition: '<S63>:41' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Slope;

          /* Outputs for Function Call SubSystem: '<S54>/Slope' */

          /* Entry 'Slope': '<S63>:20' */
          /* '<S63>:20:1' Slope; */
          /* Event: '<S63>:21' */
          APP_FluxWeak_GEAR2_Slope(PMSM_Input.AgoSample.Speed,
            DiscreteTimeIntegrator1, PMSM_Input.AppComm.GearState,
            PMSM_Input.AppSample.KsiSt, DiscreteTimeIntegrator1_i,
            PMSM_Input.AppComm.TqReq, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Slope);

          /* End of Outputs for SubSystem: '<S54>/Slope' */
          break;

         case 5U:
          /* Transition: '<S63>:43' */
          /* '<S63>:42:1' sf_internal_predicateOutput = ... */
          /* '<S63>:42:1' ModeSt==5; */
          /* Transition: '<S63>:42' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Sync;

          /* Outputs for Function Call SubSystem: '<S54>/Sync' */

          /* Entry 'Sync': '<S63>:22' */
          /* '<S63>:22:1' Sync; */
          /* Event: '<S63>:23' */
          APP_FluxWeak_GEAR2_Sync(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Sync);

          /* End of Outputs for SubSystem: '<S54>/Sync' */
          break;

         case 6U:
          /* Transition: '<S63>:44' */
          /* '<S63>:45:1' sf_internal_predicateOutput = ... */
          /* '<S63>:45:1' ModeSt==6; */
          /* Transition: '<S63>:45' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_Dischg;

          /* Outputs for Function Call SubSystem: '<S54>/Dischg' */

          /* Entry 'Dischg': '<S63>:25' */
          /* '<S63>:25:1' Dischg; */
          /* Event: '<S63>:27' */
          APP_FluxWeak_GEAR2_Dischg(DiscreteTimeIntegrator1_i4,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Dischg);

          /* End of Outputs for SubSystem: '<S54>/Dischg' */
          break;

         case 7U:
          /* Transition: '<S63>:46' */
          /* '<S63>:50:1' sf_internal_predicateOutput = ... */
          /* '<S63>:50:1' ModeSt==7; */
          /* Transition: '<S63>:50' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_ASC;

          /* Outputs for Function Call SubSystem: '<S54>/ASC' */

          /* Entry 'ASC': '<S63>:48' */
          /* '<S63>:48:1' ASC; */
          /* Event: '<S63>:49' */
          APP_FluxWeak_GEAR2_ASC(&APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b);

          /* End of Outputs for SubSystem: '<S54>/ASC' */
          break;

         default:
          /* Transition: '<S63>:52' */
          /* Transition: '<S63>:53' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_standard;

          /* Outputs for Function Call SubSystem: '<S54>/Calib' */

          /* Entry 'standard': '<S63>:28' */
          /* 标定 */
          /* '<S63>:28:1' Calib; */
          /* Event: '<S63>:29' */
          APP_FluxWeak_GEAR2_Calib(PMSM_Input.AppSample.CalibStep,
            PMSM_Input.AgoSample.ThetaRT, PMSM_Input.AppComm.TqReq,
            PMSM_Input.AppSample.ElecZeroStep, Algo_Output.Cur_loop.Ud, Vs,
            PMSM_Input.AppSample.ExtTorque, PMSM_Input.AppSample.CalibMTPATheta,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Calib);

          /* End of Outputs for SubSystem: '<S54>/Calib' */
          break;
        }
      } else {
        switch (APP_FluxWeak_GEAR2_DW.is_sys_mode) {
         case APP_FluxWeak_GEAR2_IN_Speed:
          /* During 'Speed': '<S63>:5' */
          switch (APP_FluxWeak_GEAR2_DW.is_Speed) {
           case APP_FluxWeak_GEAR2_IN_Genrate:
            /* Outputs for Function Call SubSystem: '<S54>/Genrate' */

            /* During 'Genrate': '<S63>:18' */
            /* '<S63>:18:1' Genrate; */
            /* Event: '<S63>:19' */
            APP_FluxWeak_GEAR2_Genrate(DiscreteTimeIntegrator1_i,
              DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
              &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Genrate);

            /* End of Outputs for SubSystem: '<S54>/Genrate' */
            break;

           case APP_FluxWeak_GEAR2_IN_Slope:
            /* Outputs for Function Call SubSystem: '<S54>/Slope' */

            /* During 'Slope': '<S63>:20' */
            /* '<S63>:20:1' Slope; */
            /* Event: '<S63>:21' */
            APP_FluxWeak_GEAR2_Slope(PMSM_Input.AgoSample.Speed,
              DiscreteTimeIntegrator1, PMSM_Input.AppComm.GearState,
              PMSM_Input.AppSample.KsiSt, DiscreteTimeIntegrator1_i,
              PMSM_Input.AppComm.TqReq, &APP_FluxWeak_GEAR2_DW.AscEn_l,
              &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Slope);

            /* End of Outputs for SubSystem: '<S54>/Slope' */
            break;

           case APP_FluxWeak_GEAR2_IN_Spd:
            /* Outputs for Function Call SubSystem: '<S54>/Spd' */

            /* During 'Spd': '<S63>:14' */
            /* '<S63>:14:1' Spd; */
            /* Event: '<S63>:16' */
            APP_FluxWeak_GEAR2_Spd(DiscreteTimeIntegrator1_i,
              DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
              &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Spd_g);

            /* End of Outputs for SubSystem: '<S54>/Spd' */
            break;

           case APP_FluxWeak_GEAR2_IN_Starter:
            /* Outputs for Function Call SubSystem: '<S54>/Starter' */

            /* During 'Starter': '<S63>:72' */
            /* '<S63>:72:1' Starter; */
            /* Event: '<S63>:74' */
            APP_FluxWeak_GEAR2_Starter(DiscreteTimeIntegrator1_i,
              DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
              &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Starter);

            /* End of Outputs for SubSystem: '<S54>/Starter' */
            break;

           default:
            /* Outputs for Function Call SubSystem: '<S54>/Sync' */

            /* During 'Sync': '<S63>:22' */
            /* '<S63>:22:1' Sync; */
            /* Event: '<S63>:23' */
            APP_FluxWeak_GEAR2_Sync(DiscreteTimeIntegrator1_i,
              DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
              &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Sync);

            /* End of Outputs for SubSystem: '<S54>/Sync' */
            break;
          }
          break;

         case APP_FluxWeak_GEAR2_IN_Torque:
          /* Outputs for Function Call SubSystem: '<S54>/Torque' */

          /* During 'Torque': '<S63>:3' */
          /* '<S63>:3:1' Torque; */
          /* Event: '<S63>:10' */
          APP_FluxWeak_GEAR2_Torque(PMSM_Input.AppComm.TqReq,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Torque);

          /* End of Outputs for SubSystem: '<S54>/Torque' */
          break;

         default:
          /* During 'appoint': '<S63>:6' */
          switch (APP_FluxWeak_GEAR2_DW.is_appoint) {
           case APP_FluxWeak_GEAR2_IN_ASC:
            /* Outputs for Function Call SubSystem: '<S54>/ASC' */

            /* During 'ASC': '<S63>:48' */
            /* '<S63>:48:1' ASC; */
            /* Event: '<S63>:49' */
            APP_FluxWeak_GEAR2_ASC(&APP_FluxWeak_GEAR2_DW.AscEn_l,
              &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b);

            /* End of Outputs for SubSystem: '<S54>/ASC' */
            break;

           case APP_FluxWeak_GEAR2_IN_Dischg:
            /* Outputs for Function Call SubSystem: '<S54>/Dischg' */

            /* During 'Dischg': '<S63>:25' */
            /* '<S63>:25:1' Dischg; */
            /* Event: '<S63>:27' */
            APP_FluxWeak_GEAR2_Dischg(DiscreteTimeIntegrator1_i4,
              &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Dischg);

            /* End of Outputs for SubSystem: '<S54>/Dischg' */
            break;

           default:
            /* Outputs for Function Call SubSystem: '<S54>/Calib' */

            /* During 'standard': '<S63>:28' */
            /* '<S63>:28:1' Calib; */
            /* Event: '<S63>:29' */
            APP_FluxWeak_GEAR2_Calib(PMSM_Input.AppSample.CalibStep,
              PMSM_Input.AgoSample.ThetaRT, PMSM_Input.AppComm.TqReq,
              PMSM_Input.AppSample.ElecZeroStep, Algo_Output.Cur_loop.Ud, Vs,
              PMSM_Input.AppSample.ExtTorque,
              PMSM_Input.AppSample.CalibMTPATheta,
              &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Calib);

            /* End of Outputs for SubSystem: '<S54>/Calib' */
            break;
          }
          break;
        }
      }
    }

    /* End of Chart: '<S54>/Chart' */

    /* DataStoreWrite: '<S69>/Data Store Write2' */
    AppFun.Tqreq = rtb_Switch_b;

    /* Switch: '<S108>/Switch2' incorporates:
     *  RelationalOperator: '<S108>/LowerRelop1'
     *  RelationalOperator: '<S108>/UpperRelop'
     *  Switch: '<S108>/Switch'
     */
    if (rtb_Switch_b > rtb_Saturation1_i) {
      rtb_Switch_b = rtb_Saturation1_i;
    } else {
      if (rtb_Switch_b < rtb_InvCoef) {
        /* Switch: '<S108>/Switch' */
        rtb_Switch_b = rtb_InvCoef;
      }
    }

    /* End of Switch: '<S108>/Switch2' */

    /* DataStoreWrite: '<S142>/Data Store Write' */
    AppFun.LimTP_I = rtb_DeadZone;

    /* DataStoreWrite: '<S142>/Data Store Write1' */
    AppFun.LimTN_I = rtb_Divide_p;

    /* Gain: '<S164>/Gain1' incorporates:
     *  Abs: '<S164>/Abs'
     */
    rtb_InvCoef = PMSM_Param.TuneFreqCoef * fabsf(DiscreteTimeIntegrator1);

    /* Saturate: '<S164>/Saturation' */
    if (rtb_InvCoef > PMSM_Param.FreqUp) {
      rtb_InvCoef = PMSM_Param.FreqUp;
    } else {
      if (rtb_InvCoef < PMSM_Param.FreqLow) {
        rtb_InvCoef = PMSM_Param.FreqLow;
      }
    }

    /* End of Saturate: '<S164>/Saturation' */

    /* Product: '<S165>/Divide' incorporates:
     *  Constant: '<S165>/Constant'
     */
    APP_FluxWeak_GEAR2_DW.PwmT = 1.0F / rtb_InvCoef;

    /* Switch: '<S165>/Switch3' incorporates:
     *  Constant: '<S165>/Constant4'
     */
    if (PMSM_Param.DualRefresh != 0U) {
      /* SignalConversion: '<S10>/BusConversion_InsertedFor_Ctrl_at_inport_0' incorporates:
       *  Gain: '<S165>/Gain'
       */
      APP_FluxWeak_GEAR2_DW.AlgoT = 0.5F * APP_FluxWeak_GEAR2_DW.PwmT;
    } else {
      /* SignalConversion: '<S10>/BusConversion_InsertedFor_Ctrl_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.AlgoT = APP_FluxWeak_GEAR2_DW.PwmT;
    }

    /* End of Switch: '<S165>/Switch3' */

    /* SignalConversion: '<S10>/BusConversion_InsertedFor_Ctrl_at_inport_0' */
    /* Gateway: implement/method/Req2Is&&Spd2f/Req2Is/Chart */
    /* During: implement/method/Req2Is&&Spd2f/Req2Is/Chart */
    /* Entry Internal: implement/method/Req2Is&&Spd2f/Req2Is/Chart */
    /* Transition: '<S170>:5' */
    /* '<S170>:8:1' sf_internal_predicateOutput = ... */
    /* '<S170>:8:1' ModeReq == 8; */
    APP_FluxWeak_GEAR2_DW.TqReq_k = rtb_Switch_b;

    /* SignalConversion: '<S10>/BusConversion_InsertedFor_Ctrl_at_inport_0' */
    APP_FluxWeak_GEAR2_DW.PwmFreq = rtb_InvCoef;

    /* FunctionCaller: '<S60>/Function Caller' */
    APP_FluxWeak_GEAR2_n2MaxT(rtb_Psi_i, &APP_FluxWeak_GEAR2_DW.TqMax);

    /* Product: '<S60>/Product' */
    APP_FluxWeak_GEAR2_DW.TqReal = APP_FluxWeak_GEAR2_DW.TqMax * rtb_Switch_b;

    /* SignalConversion: '<S60>/TmpBufferAtConstantOutport1' incorporates:
     *  Constant: '<S60>/Constant'
     */
    APP_FluxWeak_GEAR2_DW.ZeroPointBias = 0.0F;
  } else {
    if (APP_FluxWeak_GEAR2_DW.method_MODE) {
      /* Disable for Chart: '<S54>/Chart' incorporates:
       *  SubSystem: '<S54>/Slope'
       */
      APP_FluxWeak_GEAR_Slope_Disable(&APP_FluxWeak_GEAR2_DW.Slope);

      /* Disable for Outport: '<S10>/Table' */
      APP_FluxWeak_GEAR2_DW.TqMax = 0.0F;
      APP_FluxWeak_GEAR2_DW.TqReal = 0.0F;
      APP_FluxWeak_GEAR2_DW.ZeroPointBias = 0.0F;

      /* Disable for Outport: '<S10>/Ctrl' */
      APP_FluxWeak_GEAR2_DW.AscEn_l = 0U;
      APP_FluxWeak_GEAR2_DW.IdRefSet_i = 0.0F;
      APP_FluxWeak_GEAR2_DW.IqRefSet_m = 0.0F;
      APP_FluxWeak_GEAR2_DW.AngleRefSet_e = 0.0F;
      APP_FluxWeak_GEAR2_DW.IdIqSetEn_d = 0U;
      APP_FluxWeak_GEAR2_DW.AngleSetEn_c = 0U;
      APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f = 0.0F;
      APP_FluxWeak_GEAR2_DW.TqReq_k = 0.0F;
      APP_FluxWeak_GEAR2_DW.PwmFreq = 5000.0F;
      APP_FluxWeak_GEAR2_DW.PwmT = 0.0002F;
      APP_FluxWeak_GEAR2_DW.AlgoT = 0.0002F;
      APP_FluxWeak_GEAR2_DW.method_MODE = false;
    }
  }

  /* End of RelationalOperator: '<S7>/Compare' */
  /* End of Outputs for SubSystem: '<S2>/method' */

  /* BusCreator: '<S4>/Bus Creator' incorporates:
   *  BusCreator: '<S4>/BusConversion_InsertedFor_Bus Creator_at_inport_0'
   *  BusCreator: '<S4>/BusConversion_InsertedFor_Bus Creator_at_inport_1'
   *  BusCreator: '<S4>/BusConversion_InsertedFor_Bus Creator_at_inport_2'
   *  BusCreator: '<S4>/BusConversion_InsertedFor_Bus Creator_at_inport_3'
   *  BusCreator: '<S4>/BusConversion_InsertedFor_Bus Creator_at_inport_4'
   *  BusCreator: '<S4>/BusConversion_InsertedFor_Bus Creator_at_inport_5'
   *  Constant: '<S53>/Constant'
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  DataStoreWrite: '<Root>/Data Store Write1'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  RelationalOperator: '<S53>/Compare'
   */
  App_Output.data_process.NmFil = DiscreteTimeIntegrator1;
  App_Output.data_process.VoltCapFil = DiscreteTimeIntegrator1_i4;
  App_Output.data_process.CurBusFil = rtb_DiscreteTimeIntegrator1;
  App_Output.data_process.MotTemp = rtb_BusConversion_InsertedFor_0;
  App_Output.data_process.InvTemp = rtb_InvTemp;
  App_Output.data_process.tick = qY;
  App_Output.table.TqMax = APP_FluxWeak_GEAR2_DW.TqMax;
  App_Output.table.TqReal = APP_FluxWeak_GEAR2_DW.TqReal;
  App_Output.table.ZeroPointBias = APP_FluxWeak_GEAR2_DW.ZeroPointBias;
  App_Output.fault.LimtCoef = APP_FluxWeak_GEAR2_DW.LimtCoef;
  App_Output.fault.PwmWorkMode = APP_FluxWeak_GEAR2_DW.PwmWorkMode;
  App_Output.fault.FaultCode1 = APP_FluxWeak_GEAR2_DW.FaultCode1;
  App_Output.state.RunSt = APP_FluxWeak_GEAR2_DW.RunSt;
  App_Output.state.ModeSt = APP_FluxWeak_GEAR2_DW.ModeSt;
  App_Output.power.KeepPowerEn = 1U;
  App_Output.power.DRV1_En = (uint16_T)(APP_FluxWeak_GEAR2_DW.RunSt == 2U);
  App_Output.power.DRV2_En = 1U;
  App_Output.ctrl.AscEn = APP_FluxWeak_GEAR2_DW.AscEn_l;
  App_Output.ctrl.IdRefSet = APP_FluxWeak_GEAR2_DW.IdRefSet_i;
  App_Output.ctrl.IqRefSet = APP_FluxWeak_GEAR2_DW.IqRefSet_m;
  App_Output.ctrl.AngleRefSet = APP_FluxWeak_GEAR2_DW.AngleRefSet_e;
  App_Output.ctrl.IdIqSetEn = APP_FluxWeak_GEAR2_DW.IdIqSetEn_d;
  App_Output.ctrl.AngleSetEn = APP_FluxWeak_GEAR2_DW.AngleSetEn_c;
  App_Output.ctrl.CalibZeroPoint = APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f;
  App_Output.ctrl.TqReq = APP_FluxWeak_GEAR2_DW.TqReq_k;
  App_Output.ctrl.PwmFreq = APP_FluxWeak_GEAR2_DW.PwmFreq;
  App_Output.ctrl.PwmT = APP_FluxWeak_GEAR2_DW.PwmT;
  App_Output.ctrl.AlgoT = APP_FluxWeak_GEAR2_DW.AlgoT;

  /* DataStoreWrite: '<S177>/Data Store Write2' */
  AppFun.Us = Vs;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  APP_FluxWeak_GEAR2_DW.UnitDelay_DSTATE =
    APP_FluxWeak_GEAR2_DW.OutportBufferForUVWFault;
}

/* Model initialize function */
void APP_FluxWeak_GEAR2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(APP_FluxWeak_GEAR2_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&APP_FluxWeak_GEAR2_DW, 0,
                sizeof(DW_APP_FluxWeak_GEAR2_T));

  /* exported global states */
  PMSM_Input = APP_FluxWeak_GEAR2_rtZPMSM_Input_bus;
  App_Output = APP_FluxWeak_GEAR2_rtZApp_Output_bus;
  Algo_Output = APP_FluxWeak_GEAR2_rtZAlgo_Output_bus;
  AppFun = APP_FluxWeak_GEAR2_rtZAppFun_inspect_bus;

  {
    real32_T Add;
    int16_T i;

    /* Start for DataStoreMemory: '<Root>/App_Output' */
    App_Output = rtCP_App_Output_InitialValue;

    /* SystemInitialize for Atomic SubSystem: '<S188>/lpf' */
    LPF_App_Init(&APP_FluxWeak_GEAR2_DW.lpf);

    /* End of SystemInitialize for SubSystem: '<S188>/lpf' */

    /* SystemInitialize for Atomic SubSystem: '<S179>/lpf' */
    LPF_App_Init(&APP_FluxWeak_GEAR2_DW.lpf_c);

    /* End of SystemInitialize for SubSystem: '<S179>/lpf' */

    /* SystemInitialize for Atomic SubSystem: '<S189>/lpf' */
    LPF_App_Init(&APP_FluxWeak_GEAR2_DW.lpf_p);

    /* End of SystemInitialize for SubSystem: '<S189>/lpf' */

    /* SystemInitialize for Chart: '<S173>/Chart' */
    APP_FluxWeak_GEAR2_DW.tick = 0U;

    /* SystemInitialize for Chart: '<S1>/Chart' */
    APP_FluxWeak_GEAR2_DW.is_Prepare = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    APP_FluxWeak_GEAR2_DW.is_active_c3_APP_FluxWeak_GEAR2 = 0U;
    APP_FluxWeak_GEAR2_DW.is_c3_APP_FluxWeak_GEAR2 =
      APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    APP_FluxWeak_GEAR2_DW.RunSt = 0U;
    APP_FluxWeak_GEAR2_DW.FaultSt = 0U;
    APP_FluxWeak_GEAR2_DW.ModeSt = 0U;
    APP_FluxWeak_GEAR2_DW.chartAbsoluteTimeCounter = 0;

    /* SystemInitialize for Atomic SubSystem: '<S182>/lpf' */
    LPF_App_Init(&APP_FluxWeak_GEAR2_DW.lpf_pi);

    /* End of SystemInitialize for SubSystem: '<S182>/lpf' */

    /* SystemInitialize for Enabled SubSystem: '<S2>/Fault' */
    /* SystemInitialize for Atomic SubSystem: '<S8>/judgment' */
    /* SystemInitialize for Enabled SubSystem: '<S15>/Block' */
    /* SystemInitialize for Chart: '<S17>/Chart' */
    APP_FluxWeak_GEAR2_DW.BlockState = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S15>/Block' */

    /* SystemInitialize for Enabled SubSystem: '<S15>/DisChg' */
    /* SystemInitialize for Chart: '<S25>/Chart1' */
    APP_FluxWeak_GEAR2_DW.DisChg_time = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S15>/DisChg' */

    /* SystemInitialize for Enabled SubSystem: '<S15>/Spd' */
    /* InitializeConditions for RateLimiter: '<S27>/Rate Limiter' */
    APP_FluxWeak_GEAR2_DW.PrevY = 1.0F;

    /* SystemInitialize for Chart: '<S27>/Chart1' */
    APP_FluxWeak_GEAR2_DW.SpdCode_o[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.SpdCode_o[1] = 0UL;

    /* SystemInitialize for Outport: '<S27>/Spd' */
    APP_FluxWeak_GEAR2_DW.SpdCode[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.SpdCode[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.OSLimTP = 1.0F;
    APP_FluxWeak_GEAR2_DW.OSLimTN = -1.0F;

    /* End of SystemInitialize for SubSystem: '<S15>/Spd' */

    /* SystemInitialize for Enabled SubSystem: '<S15>/TempSensor' */
    /* SystemInitialize for Chart: '<S29>/Chart1' */
    APP_FluxWeak_GEAR2_DW.out_e[0] = 0.0F;
    APP_FluxWeak_GEAR2_DW.out_e[1] = 0.0F;

    /* SystemInitialize for Chart: '<S29>/Chart2' */
    APP_FluxWeak_GEAR2_DW.out[0] = 0.0F;
    APP_FluxWeak_GEAR2_DW.out[1] = 0.0F;
    APP_FluxWeak_GEAR2_DW.out[2] = 0.0F;

    /* SystemInitialize for Atomic SubSystem: '<S48>/lpf' */
    LPF_App_Init(&APP_FluxWeak_GEAR2_DW.lpf_e);

    /* End of SystemInitialize for SubSystem: '<S48>/lpf' */

    /* SystemInitialize for Atomic SubSystem: '<S49>/lpf' */
    LPF_App_Init(&APP_FluxWeak_GEAR2_DW.lpf_i);

    /* End of SystemInitialize for SubSystem: '<S49>/lpf' */

    /* SystemInitialize for Outport: '<S29>/TempSensor' */
    APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c = 24.0F;
    APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a = 24.0F;
    APP_FluxWeak_GEAR2_DW.LogicalOperator1[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.LogicalOperator1[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.LogicalOperator2[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.LogicalOperator2[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.LogicalOperator2[2] = 0UL;

    /* End of SystemInitialize for SubSystem: '<S15>/TempSensor' */

    /* SystemInitialize for Enabled SubSystem: '<S15>/Temp' */
    /* SystemInitialize for Chart: '<S28>/Chart' */
    APP_FluxWeak_GEAR2_DW.TempCode_g[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.TempCode_g[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.TempCode_g[2] = 0UL;
    APP_FluxWeak_GEAR2_DW.TempCode_g[3] = 0UL;
    APP_FluxWeak_GEAR2_DW.TempCode_g[4] = 0UL;
    APP_FluxWeak_GEAR2_DW.TempCode_g[5] = 0UL;

    /* SystemInitialize for Outport: '<S28>/Temp' */
    for (i = 0; i < 6; i++) {
      APP_FluxWeak_GEAR2_DW.TempCode[i] = 0UL;
    }

    APP_FluxWeak_GEAR2_DW.MotCoef = 1.0F;
    APP_FluxWeak_GEAR2_DW.InvCoef = 1.0F;

    /* End of SystemInitialize for Outport: '<S28>/Temp' */
    /* End of SystemInitialize for SubSystem: '<S15>/Temp' */

    /* SystemInitialize for Enabled SubSystem: '<S15>/Volt' */
    /* SystemInitialize for Chart: '<S30>/Chart3' */
    APP_FluxWeak_GEAR2_DW.VoltCode_m[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode_m[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode_m[2] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode_m[3] = 0UL;
    APP_FluxWeak_GEAR2_DW.DisChg_coef = 1.0F;

    /* SystemInitialize for Outport: '<S30>/Volt' */
    APP_FluxWeak_GEAR2_DW.VoltCode[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode[2] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode[3] = 0UL;
    APP_FluxWeak_GEAR2_DW.OVLimTP_g = 1.0F;
    APP_FluxWeak_GEAR2_DW.OVLimTN_m = -1.0F;

    /* End of SystemInitialize for SubSystem: '<S15>/Volt' */
    /* End of SystemInitialize for SubSystem: '<S8>/judgment' */

    /* SystemInitialize for Enabled SubSystem: '<S8>/Act' */
    /* InitializeConditions for RateLimiter: '<S11>/Rate Limiter' */
    APP_FluxWeak_GEAR2_DW.PrevY_i = 1.0F;

    /* SystemInitialize for Outport: '<S11>/LimtTorCoef' */
    APP_FluxWeak_GEAR2_DW.MinMax = 1.0F;

    /* SystemInitialize for Outport: '<S11>/OVLimTP' */
    APP_FluxWeak_GEAR2_DW.FaultLimTP = 1.0F;

    /* SystemInitialize for Outport: '<S11>/OVLimTN' */
    APP_FluxWeak_GEAR2_DW.FaultLimTN = -1.0F;

    /* End of SystemInitialize for SubSystem: '<S8>/Act' */

    /* SystemInitialize for Outport: '<S8>/Fault' */
    APP_FluxWeak_GEAR2_DW.LimtCoef = 1.0F;
    APP_FluxWeak_GEAR2_DW.PwmWorkMode = 1U;
    APP_FluxWeak_GEAR2_DW.OVLimTP = 1.0F;
    APP_FluxWeak_GEAR2_DW.OVLimTN = -1.0F;
    APP_FluxWeak_GEAR2_DW.FaultCode1 = 0UL;

    /* End of SystemInitialize for SubSystem: '<S2>/Fault' */

    /* SystemInitialize for Enabled SubSystem: '<S2>/method' */

    /* SystemInitialize for Atomic SubSystem: '<S142>/LimDrv' */

    /* SystemInitialize for Chart: '<S156>/Chart' */
    APP_FluxWeak_GEAR2_Chart_Init(&Add, &APP_FluxWeak_GEAR2_DW.sf_Chart_c);

    /* End of SystemInitialize for SubSystem: '<S142>/LimDrv' */

    /* SystemInitialize for Atomic SubSystem: '<S142>/LimChg' */

    /* SystemInitialize for Chart: '<S150>/Chart' */
    APP_FluxWeak_GEAR2_Chart_Init(&Add, &APP_FluxWeak_GEAR2_DW.sf_Chart_lj);

    /* End of SystemInitialize for SubSystem: '<S142>/LimChg' */

    /* SystemInitialize for Chart: '<S142>/Chart1' */
    APP_FluxWeak_GEAR2_DW.is_active_c20_APP_FluxWeak_GEAR = 0U;
    APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
      APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    APP_FluxWeak_GEAR2_DW.temporalCounter_i1 = 0U;
    APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    APP_FluxWeak_GEAR2_DW.is_active_c2_APP_FluxWeak_GEAR2 = 0U;
    APP_FluxWeak_GEAR2_DW.is_c2_APP_FluxWeak_GEAR2 =
      APP_FluxWe_IN_NO_ACTIVE_CHILD_c;

    /* SystemInitialize for Chart: '<S54>/Chart' incorporates:
     *  SubSystem: '<S54>/Torque'
     */
    APP_FluxWeak_GEAR2_Torque_Init(&APP_FluxWeak_GEAR2_DW.Torque);

    /* SystemInitialize for Chart: '<S54>/Chart' incorporates:
     *  SubSystem: '<S54>/Slope'
     */
    APP_FluxWeak_GEAR2_Slope_Init(&APP_FluxWeak_GEAR2_DW.Slope);

    /* SystemInitialize for Chart: '<S54>/Chart' incorporates:
     *  SubSystem: '<S54>/Calib'
     */
    APP_FluxWeak_GEAR2_Calib_Init(&APP_FluxWeak_GEAR2_DW.Calib);

    /* SystemInitialize for Chart: '<S54>/Chart' incorporates:
     *  SubSystem: '<S54>/UVW_check'
     */
    APP_FluxWeak_GEA_UVW_check_Init(&APP_FluxWeak_GEAR2_DW.UVW_check);

    /* SystemInitialize for Merge: '<S54>/Merge1' */
    APP_FluxWeak_GEAR2_DW.Merge1 = 0.0F;

    /* SystemInitialize for Outport: '<S10>/Table' */
    APP_FluxWeak_GEAR2_DW.TqMax = 0.0F;
    APP_FluxWeak_GEAR2_DW.TqReal = 0.0F;
    APP_FluxWeak_GEAR2_DW.ZeroPointBias = 0.0F;

    /* SystemInitialize for Outport: '<S10>/Ctrl' */
    APP_FluxWeak_GEAR2_DW.AscEn_l = 0U;
    APP_FluxWeak_GEAR2_DW.IdRefSet_i = 0.0F;
    APP_FluxWeak_GEAR2_DW.IqRefSet_m = 0.0F;
    APP_FluxWeak_GEAR2_DW.AngleRefSet_e = 0.0F;
    APP_FluxWeak_GEAR2_DW.IdIqSetEn_d = 0U;
    APP_FluxWeak_GEAR2_DW.AngleSetEn_c = 0U;
    APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f = 0.0F;
    APP_FluxWeak_GEAR2_DW.TqReq_k = 0.0F;
    APP_FluxWeak_GEAR2_DW.PwmFreq = 5000.0F;
    APP_FluxWeak_GEAR2_DW.PwmT = 0.0002F;
    APP_FluxWeak_GEAR2_DW.AlgoT = 0.0002F;

    /* End of SystemInitialize for SubSystem: '<S2>/method' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
