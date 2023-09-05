/*
 * File: APP_FluxWeak_GEAR2.c
 *
 * Code generated for Simulink model 'APP_FluxWeak_GEAR2'.
 *
 * Model version                  : 2.13
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Aug 29 15:47:44 2023
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
 *    '<S50>/lpf'
 *    '<S51>/lpf'
 *    '<S134>/lpf'
 *    '<S119>/lpf'
 *    '<S118>/lpf'
 *    '<S137>/lpf'
 *    '<S138>/lpf'
 *    '<S139>/lpf'
 *    '<S179>/lpf'
 *    '<S182>/lpf'
 *    ...
 */
void LPF_App_Init(DW_LPF_App_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S52>/Discrete-Time Integrator1' */
  localDW->LPF_STATE = 0.0F;
}

/*
 * System reset for atomic system:
 *    '<S50>/lpf'
 *    '<S51>/lpf'
 *    '<S134>/lpf'
 *    '<S119>/lpf'
 *    '<S118>/lpf'
 *    '<S137>/lpf'
 *    '<S138>/lpf'
 *    '<S139>/lpf'
 *    '<S179>/lpf'
 *    '<S182>/lpf'
 *    ...
 */
void LPF_App_Reset(DW_LPF_App_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S52>/Discrete-Time Integrator1' */
  localDW->LPF_STATE = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S50>/lpf'
 *    '<S51>/lpf'
 *    '<S134>/lpf'
 *    '<S119>/lpf'
 *    '<S118>/lpf'
 *    '<S137>/lpf'
 *    '<S138>/lpf'
 *    '<S139>/lpf'
 *    '<S179>/lpf'
 *    '<S182>/lpf'
 *    ...
 */
void LPF_App(real32_T rtu_u, real32_T rtu_Ts, real32_T rtu_N, real32_T *rty_Out1,
             DW_LPF_App_T *localDW)
{
  /* DiscreteIntegrator: '<S52>/Discrete-Time Integrator1' */
  *rty_Out1 = localDW->LPF_STATE;

  /* Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator1' incorporates:
   *  Product: '<S52>/Product'
   *  Product: '<S52>/Product1'
   *  Sum: '<S52>/Sum'
   */
  localDW->LPF_STATE += (rtu_u - *rty_Out1) * rtu_N * rtu_Ts;
}

/* Output and update for Simulink Function: '<S15>/Simulink Function' */
void APP_FluxWeak_GEAR2_Lim_coef(real32_T rtu_u, real32_T rtu_up_p, real32_T
  rtu_down_p, real32_T *rty_coef)
{
  real32_T rtb_uk;

  /* Sum: '<S28>/Subtract' incorporates:
   *  SignalConversion: '<S28>/TmpSignal ConversionAtdown_pOutport1'
   *  SignalConversion: '<S28>/TmpSignal ConversionAtup_pOutport1'
   */
  rtb_uk = rtu_up_p - rtu_down_p;

  /* Sum: '<S28>/Add' incorporates:
   *  Gain: '<S28>/Gain'
   *  Product: '<S28>/Divide'
   *  Product: '<S28>/Divide1'
   *  SignalConversion: '<S28>/TmpSignal ConversionAtdown_pOutport1'
   *  SignalConversion: '<S28>/TmpSignal ConversionAtuOutport1'
   */
  rtb_uk = rtu_u / rtb_uk + rtu_down_p / -rtb_uk;

  /* Saturate: '<S28>/Saturation' */
  if (rtb_uk > 1.0F) {
    /* SignalConversion: '<S28>/TmpSignal ConversionAtcoefInport1' */
    *rty_coef = 1.0F;
  } else if (rtb_uk < 0.0F) {
    /* SignalConversion: '<S28>/TmpSignal ConversionAtcoefInport1' */
    *rty_coef = 0.0F;
  } else {
    /* SignalConversion: '<S28>/TmpSignal ConversionAtcoefInport1' */
    *rty_coef = rtb_uk;
  }

  /* End of Saturate: '<S28>/Saturation' */
}

/* Output and update for function-call system: '<S56>/Initial' */
void APP_FluxWeak_GEAR2_Initial(void)
{
  /* StateWriter: '<S68>/State Writer' incorporates:
   *  Constant: '<S68>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state = 0.0F;

  /* StateWriter: '<S68>/State Writer1' incorporates:
   *  Constant: '<S68>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Slope.lpf_a.LPF_STATE = 0.0F;

  /* StateWriter: '<S68>/State Writer2' incorporates:
   *  Constant: '<S68>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state = 0.0F;

  /* StateWriter: '<S68>/State Writer3' incorporates:
   *  Constant: '<S68>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Sync.PI.I_state = 0.0F;

  /* StateWriter: '<S68>/State Writer4' incorporates:
   *  Constant: '<S68>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Starter.PI.I_state = 0.0F;

  /* StateWriter: '<S68>/State Writer5' incorporates:
   *  Constant: '<S68>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE = 0.0F;

  /* StateWriter: '<S68>/State Writer6' incorporates:
   *  Constant: '<S68>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Spd_g.Spd_D_Int = 0.0F;

  /* StateWriter: '<S68>/State Writer7' incorporates:
   *  Constant: '<S68>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;
}

/* Output and update for function-call system: '<S56>/Update' */
void APP_FluxWeak_GEAR2_Update(const real32_T *rtu_Ctrl, real32_T rtu_Data,
  real32_T rtu_Data_d)
{
  real32_T rtb_Subtract_g;

  /* Sum: '<S78>/Subtract' */
  rtb_Subtract_g = rtu_Data - rtu_Data_d;

  /* StateWriter: '<S78>/State Writer' incorporates:
   *  Gain: '<S78>/P'
   *  Sum: '<S78>/Subtract1'
   */
  APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state = *rtu_Ctrl - PMSM_Param.GenKp *
    rtb_Subtract_g;

  /* StateWriter: '<S78>/State Writer1' incorporates:
   *  Gain: '<S78>/P1'
   *  Sum: '<S78>/Subtract2'
   */
  APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = *rtu_Ctrl - PMSM_Param.SlopeKp *
    rtb_Subtract_g;

  /* StateWriter: '<S78>/State Writer2' */
  APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state = *rtu_Ctrl;

  /* Sum: '<S78>/Subtract4' incorporates:
   *  Gain: '<S78>/P3'
   *  Sum: '<S78>/Subtract5'
   */
  APP_FluxWeak_GEAR2_DW.Sync.PI.I_state = *rtu_Ctrl - PMSM_Param.SyncKp *
    rtb_Subtract_g;

  /* StateWriter: '<S78>/State Writer4' */
  APP_FluxWeak_GEAR2_DW.Starter.PI.I_state =
    APP_FluxWeak_GEAR2_DW.Sync.PI.I_state;

  /* StateWriter: '<S78>/State Writer5' */
  APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE = *rtu_Ctrl;

  /* StateWriter: '<S78>/State Writer6' */
  APP_FluxWeak_GEAR2_DW.Slope.lpf_a.LPF_STATE = *rtu_Ctrl;
}

/* System initialize for function-call system: '<S56>/Torque' */
void APP_FluxWeak_GEAR2_Torque_Init(DW_Torque_APP_FluxWeak_GEAR2_T *localDW)
{
  /* SystemInitialize for Atomic SubSystem: '<S134>/lpf' */
  LPF_App_Init(&localDW->lpf);

  /* End of SystemInitialize for SubSystem: '<S134>/lpf' */
}

/* Output and update for function-call system: '<S56>/Torque' */
void APP_FluxWeak_GEAR2_Torque(real32_T rtu_data, uint16_T *rty_Out1, real32_T
  *rty_Out1_l, real32_T *rty_Out1_i, real32_T *rty_Out1_g, uint16_T *rty_Out1_c,
  uint16_T *rty_Out1_p, real32_T *rty_Out1_l2, real32_T *rty_Out1_gi, real32_T
  *rty_Tor, DW_Torque_APP_FluxWeak_GEAR2_T *localDW)
{
  real32_T rtb_DiscreteTimeIntegrator1_g;

  /* SignalConversion: '<S76>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S76>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_l = 0.0F;

  /* SignalConversion: '<S76>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = 0.0F;

  /* SignalConversion: '<S76>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = 0.0F;

  /* SignalConversion: '<S76>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0U;

  /* SignalConversion: '<S76>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_p = 0U;

  /* SignalConversion: '<S76>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_l2 = 0.0F;

  /* Outputs for Atomic SubSystem: '<S134>/lpf' */

  /* Constant: '<S134>/Constant' incorporates:
   *  Constant: '<S134>/Constant1'
   */
  LPF_App(rtu_data, 0.002F, 10.0F, &rtb_DiscreteTimeIntegrator1_g, &localDW->lpf);

  /* End of Outputs for SubSystem: '<S134>/lpf' */

  /* SignalConversion: '<S76>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_gi = rtb_DiscreteTimeIntegrator1_g;

  /* SignalConversion: '<S76>/OutportBufferForTor' */
  *rty_Tor = rtb_DiscreteTimeIntegrator1_g;
}

/* Output and update for function-call system: '<S56>/Spd' */
void APP_FluxWeak_GEAR2_Spd(real32_T rtu_Data, real32_T rtu_Data_o, uint16_T
  *rty_Out1, real32_T *rty_Out1_o, real32_T *rty_Out1_p, real32_T *rty_Out1_c,
  uint16_T *rty_Out1_h, uint16_T *rty_Out1_ox, real32_T *rty_Out1_m, real32_T
  *rty_Out1_mw, real32_T *rty_Tor, DW_Spd_APP_FluxWeak_GEAR2_T *localDW)
{
  real32_T rtb_Gain_aw;
  real32_T rtb_UnitDelay_b;
  real32_T rtb_Saturation_c;

  /* Gain: '<S129>/Gain' incorporates:
   *  DiscreteIntegrator: '<S129>/Discrete-Time Integrator1'
   *  Sum: '<S129>/Sum'
   */
  rtb_Gain_aw = (0.0F - localDW->Spd_D_Int) * 0.25F;

  /* DataStoreWrite: '<S129>/Data Store Write' */
  AppFun.LimTP_T = rtb_Gain_aw;

  /* DataStoreWrite: '<S129>/Data Store Write1' incorporates:
   *  DiscreteIntegrator: '<S129>/Discrete-Time Integrator'
   */
  AppFun.LimTN_T = localDW->Spd_state;

  /* Gain: '<S73>/Norm' incorporates:
   *  Sum: '<S73>/Subtract1'
   */
  rtb_UnitDelay_b = (rtu_Data - rtu_Data_o) * 0.0001F;

  /* Gain: '<S129>/P' */
  rtb_Saturation_c = PMSM_Param.SpdKp * rtb_UnitDelay_b;

  /* DataStoreWrite: '<S129>/Data Store Write2' */
  AppFun.LimTP_Spd = rtb_Saturation_c;

  /* Switch: '<S129>/Switch' incorporates:
   *  Abs: '<S129>/Abs'
   *  Constant: '<S129>/Constant1'
   */
  if (!(fabsf(rtu_Data) > 10.0F)) {
    rtb_UnitDelay_b = 0.0F;
  }

  /* End of Switch: '<S129>/Switch' */

  /* Sum: '<S129>/Sum3' incorporates:
   *  DiscreteIntegrator: '<S129>/Discrete-Time Integrator'
   */
  rtb_Saturation_c = (rtb_Saturation_c + localDW->Spd_state) + rtb_Gain_aw;

  /* Saturate: '<S129>/Saturation' */
  if (rtb_Saturation_c > 1.0F) {
    rtb_Saturation_c = 1.0F;
  } else {
    if (rtb_Saturation_c < -1.0F) {
      rtb_Saturation_c = -1.0F;
    }
  }

  /* End of Saturate: '<S129>/Saturation' */

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_o = 0.0F;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_p = 0.0F;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0.0F;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_h = 0U;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_ox = 0U;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_m = 0.0F;

  /* SignalConversion: '<S73>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_mw = rtb_Saturation_c;

  /* SignalConversion: '<S73>/OutportBufferForTor' */
  *rty_Tor = rtb_Saturation_c;

  /* Update for DiscreteIntegrator: '<S129>/Discrete-Time Integrator1' */
  localDW->Spd_D_Int += 0.001F * rtb_Gain_aw;

  /* Update for DiscreteIntegrator: '<S129>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S129>/I'
   */
  localDW->Spd_state += PMSM_Param.SpdKi / 1000.0F * rtb_UnitDelay_b;
}

/*
 * Output and update for atomic system:
 *    '<S101>/PI'
 *    '<S130>/PI'
 *    '<S115>/PI'
 *    '<S132>/PI'
 *    '<S154>/PI'
 *    '<S160>/PI'
 */
void PI_App(real32_T rtu_Err, real32_T rtu_Kp, real32_T rtu_KI, real32_T rtu_T,
            real32_T *rty_PIOut, real32_T *rty_I_State, DW_PI_App_T *localDW)
{
  /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
  *rty_I_State = localDW->I_state;

  /* Sum: '<S102>/Add' incorporates:
   *  Product: '<S102>/Product'
   */
  *rty_PIOut = rtu_Kp * rtu_Err + *rty_I_State;

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' incorporates:
   *  Product: '<S102>/Product1'
   *  Product: '<S102>/Product2'
   */
  localDW->I_state += rtu_Err * rtu_KI * rtu_T;
}

/* Output and update for function-call system: '<S56>/Genrate' */
void APP_FluxWeak_GEAR2_Genrate(real32_T rtu_Data, real32_T rtu_Data_d, uint16_T
  *rty_Out1, real32_T *rty_Out1_d, real32_T *rty_Out1_n, real32_T *rty_Out1_ni,
  uint16_T *rty_Out1_g, uint16_T *rty_Out1_h, real32_T *rty_Out1_k, real32_T
  *rty_Out1_d4, real32_T *rty_Tor, DW_Genrate_APP_FluxWeak_GEAR2_T *localDW)
{
  real32_T rtb_Add_a;
  real32_T rtb_DiscreteTimeIntegrator1_j;

  /* SignalConversion: '<S67>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S67>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_d = 0.0F;

  /* SignalConversion: '<S67>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_n = 0.0F;

  /* SignalConversion: '<S67>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_ni = 0.0F;

  /* SignalConversion: '<S67>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = 0U;

  /* SignalConversion: '<S67>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_h = 0U;

  /* SignalConversion: '<S67>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_k = 0.0F;

  /* Outputs for Atomic SubSystem: '<S101>/PI' */

  /* Gain: '<S67>/Norm' incorporates:
   *  Constant: '<S101>/Constant'
   *  Constant: '<S101>/Constant1'
   *  Constant: '<S101>/Constant2'
   *  Sum: '<S67>/Subtract'
   */
  PI_App(0.0001F * (rtu_Data - rtu_Data_d), PMSM_Param.GenKp, PMSM_Param.GenKi,
         0.002F, &rtb_Add_a, &rtb_DiscreteTimeIntegrator1_j, &localDW->PI);

  /* End of Outputs for SubSystem: '<S101>/PI' */

  /* Saturate: '<S101>/Saturation' */
  if (rtb_Add_a > 0.0F) {
    rtb_Add_a = 0.0F;
  } else {
    if (rtb_Add_a < -1.0F) {
      rtb_Add_a = -1.0F;
    }
  }

  /* End of Saturate: '<S101>/Saturation' */

  /* SignalConversion: '<S67>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_d4 = rtb_Add_a;

  /* SignalConversion: '<S67>/OutportBufferForTor' */
  *rty_Tor = rtb_Add_a;
}

/* Output and update for function-call system: '<S56>/Starter' */
void APP_FluxWeak_GEAR2_Starter(real32_T rtu_Data, real32_T rtu_Data_c, uint16_T
  *rty_Out1, real32_T *rty_Out1_c, real32_T *rty_Out1_b, real32_T *rty_Out1_bt,
  uint16_T *rty_Out1_i, uint16_T *rty_Out1_cm, real32_T *rty_Out1_p, real32_T
  *rty_Out1_e, real32_T *rty_Tor, DW_Starter_APP_FluxWeak_GEAR2_T *localDW)
{
  real32_T rtb_Add_b;
  real32_T rtb_DiscreteTimeIntegrator1_g;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0.0F;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_b = 0.0F;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_bt = 0.0F;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = 0U;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_cm = 0U;

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_p = 0.0F;

  /* Outputs for Atomic SubSystem: '<S130>/PI' */

  /* Gain: '<S74>/Norm' incorporates:
   *  Constant: '<S130>/Constant'
   *  Constant: '<S130>/Constant1'
   *  Constant: '<S130>/Constant2'
   *  Sum: '<S74>/Subtract'
   */
  PI_App(0.0001F * (rtu_Data - rtu_Data_c), PMSM_Param.StarKp, PMSM_Param.StarKi,
         0.002F, &rtb_Add_b, &rtb_DiscreteTimeIntegrator1_g, &localDW->PI);

  /* End of Outputs for SubSystem: '<S130>/PI' */

  /* Saturate: '<S130>/Saturation' */
  if (rtb_Add_b > 1.0F) {
    rtb_Add_b = 1.0F;
  } else {
    if (rtb_Add_b < 0.0F) {
      rtb_Add_b = 0.0F;
    }
  }

  /* End of Saturate: '<S130>/Saturation' */

  /* SignalConversion: '<S74>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_e = rtb_Add_b;

  /* SignalConversion: '<S74>/OutportBufferForTor' */
  *rty_Tor = rtb_Add_b;
}

/* System initialize for function-call system: '<S112>/Function-Call Subsystem' */
void APP__FunctionCallSubsystem_Init(DW_FunctionCallSubsystem_APP__T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' */
  localDW->Slope_state = 0.0F;
}

/* System reset for function-call system: '<S112>/Function-Call Subsystem' */
void APP_FunctionCallSubsystem_Reset(DW_FunctionCallSubsystem_APP__T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' */
  localDW->Slope_state = 0.0F;
}

/* Disable for function-call system: '<S112>/Function-Call Subsystem' */
void A_FunctionCallSubsystem_Disable(real32_T *rty_SlopeTime)
{
  /* Disable for Outport: '<S116>/SlopeTime' */
  *rty_SlopeTime = 0.0F;
}

/* Output and update for function-call system: '<S112>/Function-Call Subsystem' */
void APP_FluxW_FunctionCallSubsystem(real32_T rtu_SlopeLoopOut, uint16_T
  rtu_Gear, real32_T *rty_SlopeTime, DW_FunctionCallSubsystem_APP__T *localDW)
{
  real32_T rtb_MultiportSwitch_n;

  /* DiscreteIntegrator: '<S116>/Discrete-Time Integrator' */
  *rty_SlopeTime = localDW->Slope_state;

  /* MultiPortSwitch: '<S116>/Multiport Switch' incorporates:
   *  Constant: '<S116>/Constant'
   */
  switch (rtu_Gear) {
   case 0:
    rtb_MultiportSwitch_n = 0.0F;
    break;

   case 1:
    /* DeadZone: '<S116>/Dead Zone' */
    if (rtu_SlopeLoopOut > 0.3F) {
      rtb_MultiportSwitch_n = rtu_SlopeLoopOut - 0.3F;
    } else if (rtu_SlopeLoopOut >= -0.3F) {
      rtb_MultiportSwitch_n = 0.0F;
    } else {
      rtb_MultiportSwitch_n = rtu_SlopeLoopOut - -0.3F;
    }

    /* Signum: '<S116>/Sign' */
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
    /* DeadZone: '<S116>/Dead Zone' */
    if (rtu_SlopeLoopOut > 0.3F) {
      rtb_MultiportSwitch_n = rtu_SlopeLoopOut - 0.3F;
    } else if (rtu_SlopeLoopOut >= -0.3F) {
      rtb_MultiportSwitch_n = 0.0F;
    } else {
      rtb_MultiportSwitch_n = rtu_SlopeLoopOut - -0.3F;
    }

    /* Signum: '<S116>/Sign' incorporates:
     *  Gain: '<S116>/Gain'
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

  /* End of MultiPortSwitch: '<S116>/Multiport Switch' */

  /* Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' */
  localDW->Slope_state += 0.001F * rtb_MultiportSwitch_n;
  if (localDW->Slope_state >= 100.0F) {
    localDW->Slope_state = 100.0F;
  } else {
    if (localDW->Slope_state <= 0.0F) {
      localDW->Slope_state = 0.0F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' */
}

/* Output and update for function-call system: '<S114>/Function-Call Subsystem' */
void APP_Flu_FunctionCallSubsystem_o(real32_T rtu_TorReq, real32_T rtu_Spd_loop,
  real32_T *rty_Out1)
{
  /* MinMax: '<S123>/MinMax' */
  *rty_Out1 = fmaxf(rtu_TorReq, rtu_Spd_loop);
}

/* Output and update for function-call system: '<S114>/Function-Call Subsystem2' */
void APP_Flux_FunctionCallSubsystem2(real32_T *rty_Out1,
  DW_FunctionCallSubsystem2_APP_T *localDW)
{
  real32_T tmp;

  /* Switch: '<S127>/Switch2' incorporates:
   *  Constant: '<S125>/Constant2'
   *  RelationalOperator: '<S127>/LowerRelop1'
   *  RelationalOperator: '<S127>/UpperRelop'
   *  Sum: '<S125>/Difference Inputs1'
   *  Switch: '<S127>/Switch'
   *  UnitDelay: '<S125>/Delay Input2'
   *
   * Block description for '<S125>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S125>/Delay Input2':
   *
   *  Store in Global RAM
   */
  if ((real32_T)(0.0 - localDW->N_state) > 0.001F) {
    tmp = 0.001F;
  } else if ((real32_T)(0.0 - localDW->N_state) < -0.001F) {
    /* Switch: '<S127>/Switch' */
    tmp = -0.001F;
  } else {
    tmp = (real32_T)(0.0 - localDW->N_state);
  }

  /* End of Switch: '<S127>/Switch2' */

  /* Sum: '<S125>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S125>/Delay Input2'
   *
   * Block description for '<S125>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S125>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->N_state += tmp;

  /* SignalConversion: '<S125>/OutportBufferForOut1' */
  *rty_Out1 = localDW->N_state;
}

/* Output and update for function-call system: '<S114>/Function-Call Subsystem1' */
void APP_Flux_FunctionCallSubsystem1(real32_T rtu_TorReq, real32_T rtu_Spd_loop,
  real32_T *rty_Out1)
{
  /* MinMax: '<S124>/MinMax1' */
  *rty_Out1 = fminf(rtu_TorReq, rtu_Spd_loop);
}

/* Output and update for function-call system: '<S114>/Initial' */
void APP_FluxWeak_GEAR2_Initial_e(const real32_T *rtu_out)
{
  /* StateWriter: '<S126>/State Writer' */
  APP_FluxWeak_GEAR2_DW.Slope.FunctionCallSubsystem2.N_state = *rtu_out;
}

/* System initialize for function-call system: '<S56>/Slope' */
void APP_FluxWeak_GEAR2_Slope_Init(DW_Slope_APP_FluxWeak_GEAR2_T *localDW)
{
  /* SystemInitialize for Atomic SubSystem: '<S119>/lpf' */
  LPF_App_Init(&localDW->lpf);

  /* End of SystemInitialize for SubSystem: '<S119>/lpf' */

  /* SystemInitialize for Atomic SubSystem: '<S118>/lpf' */
  LPF_App_Init(&localDW->lpf_a);

  /* End of SystemInitialize for SubSystem: '<S118>/lpf' */
  localDW->is_move = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
  localDW->is_D = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
  localDW->is_R = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c4_APP_FluxWeak_GEAR2 = 0U;
  localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
  localDW->SpdReqPu_out = 0.0F;

  /* SystemInitialize for Chart: '<S72>/Chart' incorporates:
   *  SubSystem: '<S112>/Function-Call Subsystem'
   */
  APP__FunctionCallSubsystem_Init(&localDW->FunctionCallSubsystem);

  /* SystemInitialize for Chart: '<S114>/Chart' */
  localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
  localDW->is_active_c19_APP_FluxWeak_GEAR = 0U;

  /* SystemInitialize for Merge: '<S114>/Merge' */
  localDW->Merge = 0.0F;
}

/* Enable for function-call system: '<S56>/Slope' */
void APP_FluxWeak_GEAR2_Slope_Enable(DW_Slope_APP_FluxWeak_GEAR2_T *localDW)
{
  /* Enable for Chart: '<S72>/Chart' */
  if ((int16_T)localDW->is_c4_APP_FluxWeak_GEAR2 == (int16_T)
      APP_FluxWeak_GEAR2_IN_slope) {
    /* SystemReset for Function Call SubSystem: '<S112>/Function-Call Subsystem' */
    APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

    /* End of SystemReset for SubSystem: '<S112>/Function-Call Subsystem' */
  }

  /* End of Enable for Chart: '<S72>/Chart' */
}

/* Disable for function-call system: '<S56>/Slope' */
void APP_FluxWeak_GEAR_Slope_Disable(DW_Slope_APP_FluxWeak_GEAR2_T *localDW)
{
  /* Disable for Chart: '<S72>/Chart' */
  if ((int16_T)localDW->is_c4_APP_FluxWeak_GEAR2 == (int16_T)
      APP_FluxWeak_GEAR2_IN_slope) {
    /* Disable for Function Call SubSystem: '<S112>/Function-Call Subsystem' */
    A_FunctionCallSubsystem_Disable(&localDW->DiscreteTimeIntegrator);

    /* End of Disable for SubSystem: '<S112>/Function-Call Subsystem' */
  }

  /* End of Disable for Chart: '<S72>/Chart' */
}

/* Output and update for function-call system: '<S56>/Slope' */
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

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_a = 0.0F;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_j = 0.0F;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = 0.0F;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_l = 0U;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = 0U;

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0.0F;

  /* Outputs for Atomic SubSystem: '<S119>/lpf' */

  /* Constant: '<S119>/Constant' incorporates:
   *  Constant: '<S119>/Constant1'
   */
  LPF_App(rtu_Data, 0.002F, 1000.0F / PMSM_Param.DamperTimer,
          &rtb_DiscreteTimeIntegrator1_f, &localDW->lpf);

  /* End of Outputs for SubSystem: '<S119>/lpf' */

  /* Gain: '<S117>/Gain' incorporates:
   *  Sum: '<S117>/Sum'
   */
  rtb_Gain_g = (rtb_DiscreteTimeIntegrator1_f - rtu_Data) * 0.0F;

  /* Outputs for Atomic SubSystem: '<S118>/lpf' */

  /* Constant: '<S118>/Constant' incorporates:
   *  Constant: '<S118>/Constant1'
   */
  LPF_App(rtu_Data_i, 0.002F, 33.3333321F, &rtb_DiscreteTimeIntegrator1_f,
          &localDW->lpf_a);

  /* End of Outputs for SubSystem: '<S118>/lpf' */

  /* Sum: '<S113>/Add' */
  rtb_Gain_g += rtb_DiscreteTimeIntegrator1_f;

  /* Saturate: '<S113>/Saturation' */
  if (rtb_Gain_g > 1.0F) {
    rtb_Gain_g = 1.0F;
  } else {
    if (rtb_Gain_g < -1.0F) {
      rtb_Gain_g = -1.0F;
    }
  }

  /* End of Saturate: '<S113>/Saturation' */

  /* Chart: '<S72>/Chart' incorporates:
   *  UnitDelay: '<S72>/Unit Delay'
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
    /* Transition: '<S111>:4' */
    localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_slope;

    /* SystemReset for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

    /* Entry 'slope': '<S111>:3' */
    APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

    /* End of SystemReset for SubSystem: '<S112>/Function-Call Subsystem' */

    /* '<S111>:3:1' SpdReqPu_out=SpdReqPu_in; */
    localDW->SpdReqPu_out = rtu_Data_l;

    /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

    /* '<S111>:3:3' TimeCount; */
    /* Event: '<S111>:38' */
    APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, rtu_Data_j,
      &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

    /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem' */
  } else if (localDW->is_c4_APP_FluxWeak_GEAR2 == 1U) {
    /* During 'move': '<S111>:6' */
    /* '<S111>:29:1' sf_internal_predicateOutput = ... */
    /* '<S111>:29:1' GearState==0; */
    if (rtu_Data_j == 0U) {
      /* Transition: '<S111>:29' */
      /* Exit Internal 'move': '<S111>:6' */
      /* Exit Internal 'D': '<S111>:8' */
      localDW->is_D = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
      localDW->is_move = APP_FluxWeak_IN_NO_ACTIVE_CHILD;

      /* Exit Internal 'R': '<S111>:20' */
      localDW->is_R = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
      localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_slope;

      /* SystemReset for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

      /* Entry 'slope': '<S111>:3' */
      APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

      /* End of SystemReset for SubSystem: '<S112>/Function-Call Subsystem' */

      /* '<S111>:3:1' SpdReqPu_out=SpdReqPu_in; */
      localDW->SpdReqPu_out = rtu_Data_l;

      /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

      /* '<S111>:3:3' TimeCount; */
      /* Event: '<S111>:38' */
      APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, 0U,
        &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

      /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem' */
    } else if (localDW->is_move == 1U) {
      /* During 'D': '<S111>:8' */
      if (localDW->is_D == 1U) {
        /* During 'Add': '<S111>:12' */
        /* Transition: '<S111>:24' */
        /* '<S111>:25:1' sf_internal_predicateOutput = ... */
        /* '<S111>:25:1' after(500,tick); */
        if (localDW->temporalCounter_i1 >= 500U) {
          /* Transition: '<S111>:25' */
          localDW->is_D = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          localDW->is_move = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_slope;

          /* SystemReset for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

          /* Entry 'slope': '<S111>:3' */
          APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

          /* End of SystemReset for SubSystem: '<S112>/Function-Call Subsystem' */

          /* '<S111>:3:1' SpdReqPu_out=SpdReqPu_in; */
          localDW->SpdReqPu_out = rtu_Data_l;

          /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

          /* '<S111>:3:3' TimeCount; */
          /* Event: '<S111>:38' */
          APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, rtu_Data_j,
            &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

          /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem' */
        } else {
          /* '<S111>:12:1' SpdReqPu_out=SpdReqPu_out+0.2; */
          localDW->SpdReqPu_out += 0.2F;
        }
      } else {
        /* During 'Sub': '<S111>:10' */
        /* '<S111>:14:1' sf_internal_predicateOutput = ... */
        /* '<S111>:14:1' after(500,tick); */
        if (localDW->temporalCounter_i1 >= 500U) {
          /* Transition: '<S111>:14' */
          localDW->is_D = APP_FluxWeak_GEAR2_IN_Add;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'Add': '<S111>:12' */
          /* '<S111>:12:1' SpdReqPu_out=SpdReqPu_out+0.2; */
          localDW->SpdReqPu_out += 0.2F;
        } else {
          /* '<S111>:10:1' SpdReqPu_out=SpdReqPu_out-0.2; */
          localDW->SpdReqPu_out -= 0.2F;
        }
      }
    } else {
      /* During 'R': '<S111>:20' */
      if (localDW->is_R == 1U) {
        /* During 'Add': '<S111>:19' */
        /* '<S111>:21:1' sf_internal_predicateOutput = ... */
        /* '<S111>:21:1' after(500,tick); */
        if (localDW->temporalCounter_i1 >= 500U) {
          /* Transition: '<S111>:21' */
          localDW->is_R = APP_FluxWeak_GEAR2_IN_Sub;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'Sub': '<S111>:18' */
          /* '<S111>:18:1' SpdReqPu_out=SpdReqPu_out-0.2; */
          localDW->SpdReqPu_out -= 0.2F;
        } else {
          /* '<S111>:19:1' SpdReqPu_out=SpdReqPu_out+0.2; */
          localDW->SpdReqPu_out += 0.2F;
        }
      } else {
        /* During 'Sub': '<S111>:18' */
        /* Transition: '<S111>:23' */
        /* '<S111>:25:1' sf_internal_predicateOutput = ... */
        /* '<S111>:25:1' after(500,tick); */
        if (localDW->temporalCounter_i1 >= 500U) {
          /* Transition: '<S111>:25' */
          localDW->is_R = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          localDW->is_move = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_slope;

          /* SystemReset for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

          /* Entry 'slope': '<S111>:3' */
          APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

          /* End of SystemReset for SubSystem: '<S112>/Function-Call Subsystem' */

          /* '<S111>:3:1' SpdReqPu_out=SpdReqPu_in; */
          localDW->SpdReqPu_out = rtu_Data_l;

          /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

          /* '<S111>:3:3' TimeCount; */
          /* Event: '<S111>:38' */
          APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, rtu_Data_j,
            &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

          /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem' */
        } else {
          /* '<S111>:18:1' SpdReqPu_out=SpdReqPu_out-0.2; */
          localDW->SpdReqPu_out -= 0.2F;
        }
      }
    }
  } else {
    /* During 'slope': '<S111>:3' */
    /* '<S111>:7:1' sf_internal_predicateOutput = ... */
    /* '<S111>:7:1' SlopeTime>5; */
    if (localDW->DiscreteTimeIntegrator > 5.0F) {
      /* Disable for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

      /* Transition: '<S111>:7' */
      /* Exit 'slope': '<S111>:3' */
      A_FunctionCallSubsystem_Disable(&localDW->DiscreteTimeIntegrator);

      /* End of Disable for SubSystem: '<S112>/Function-Call Subsystem' */
      localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_move;

      /* Entry Internal 'move': '<S111>:6' */
      /* Transition: '<S111>:9' */
      /* '<S111>:27:1' sf_internal_predicateOutput = ... */
      /* '<S111>:27:1' GearState==1; */
      if (rtu_Data_j == 1U) {
        /* Transition: '<S111>:27' */
        localDW->is_move = APP_FluxWeak_GEAR2_IN_D;

        /* Entry 'D': '<S111>:8' */
        /* 后溜 */
        /* Entry Internal 'D': '<S111>:8' */
        /* Transition: '<S111>:11' */
        localDW->is_D = APP_FluxWeak_GEAR2_IN_Sub;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'Sub': '<S111>:10' */
        /* '<S111>:10:1' SpdReqPu_out=SpdReqPu_out-0.2; */
        localDW->SpdReqPu_out -= 0.2F;
      } else {
        /* Transition: '<S111>:28' */
        localDW->is_move = APP_FluxWeak_GEAR2_IN_R;

        /* Entry 'R': '<S111>:20' */
        /* 后溜 */
        /* Entry Internal 'R': '<S111>:20' */
        /* Transition: '<S111>:17' */
        localDW->is_R = APP_FluxWeak_GEAR2_IN_Add;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'Add': '<S111>:19' */
        /* '<S111>:19:1' SpdReqPu_out=SpdReqPu_out+0.2; */
        localDW->SpdReqPu_out += 0.2F;
      }
    } else {
      /* '<S111>:36:1' sf_internal_predicateOutput = ... */
      /* '<S111>:36:1' hasChanged(GearState); */
      if (GearState_prev != localDW->GearState_start) {
        /* Disable for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

        /* Transition: '<S111>:36' */
        /* Exit 'slope': '<S111>:3' */
        A_FunctionCallSubsystem_Disable(&localDW->DiscreteTimeIntegrator);

        /* End of Disable for SubSystem: '<S112>/Function-Call Subsystem' */
        localDW->is_c4_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_slope;

        /* SystemReset for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

        /* Entry 'slope': '<S111>:3' */
        APP_FunctionCallSubsystem_Reset(&localDW->FunctionCallSubsystem);

        /* End of SystemReset for SubSystem: '<S112>/Function-Call Subsystem' */

        /* '<S111>:3:1' SpdReqPu_out=SpdReqPu_in; */
        localDW->SpdReqPu_out = rtu_Data_l;

        /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

        /* '<S111>:3:3' TimeCount; */
        /* Event: '<S111>:38' */
        APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, rtu_Data_j,
          &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

        /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem' */
      } else {
        /* '<S111>:3:1' SpdReqPu_out=SpdReqPu_in; */
        localDW->SpdReqPu_out = rtu_Data_l;

        /* Outputs for Function Call SubSystem: '<S112>/Function-Call Subsystem' */

        /* '<S111>:3:3' TimeCount; */
        /* Event: '<S111>:38' */
        APP_FluxW_FunctionCallSubsystem(localDW->UnitDelay_DSTATE, rtu_Data_j,
          &localDW->DiscreteTimeIntegrator, &localDW->FunctionCallSubsystem);

        /* End of Outputs for SubSystem: '<S112>/Function-Call Subsystem' */
      }
    }
  }

  /* End of Chart: '<S72>/Chart' */

  /* Outputs for Atomic SubSystem: '<S115>/PI' */

  /* Gain: '<S72>/Norm' incorporates:
   *  Constant: '<S115>/Constant'
   *  Constant: '<S115>/Constant1'
   *  Constant: '<S115>/Constant2'
   *  Sum: '<S72>/Subtract'
   */
  PI_App(0.0001F * (localDW->SpdReqPu_out - rtu_Data_a), PMSM_Param.SlopeKp,
         PMSM_Param.SlopeKi, 0.002F, &localDW->UnitDelay_DSTATE,
         &rtb_DiscreteTimeIntegrator1_f, &localDW->PI);

  /* End of Outputs for SubSystem: '<S115>/PI' */

  /* MultiPortSwitch: '<S115>/Multiport Switch' */
  switch (rtu_Data_j) {
   case 0:
    break;

   case 1:
    /* Saturate: '<S115>/Saturation1' */
    if (localDW->UnitDelay_DSTATE > PMSM_Param.SlopeMaxT) {
      localDW->UnitDelay_DSTATE = PMSM_Param.SlopeMaxT;
    } else {
      if (localDW->UnitDelay_DSTATE < 0.0F) {
        localDW->UnitDelay_DSTATE = 0.0F;
      }
    }

    /* End of Saturate: '<S115>/Saturation1' */
    break;

   default:
    /* Saturate: '<S115>/Saturation2' */
    if (localDW->UnitDelay_DSTATE > 0.0F) {
      localDW->UnitDelay_DSTATE = 0.0F;
    } else {
      if (localDW->UnitDelay_DSTATE < -PMSM_Param.SlopeMaxT) {
        localDW->UnitDelay_DSTATE = -PMSM_Param.SlopeMaxT;
      }
    }

    /* End of Saturate: '<S115>/Saturation2' */
    break;
  }

  /* End of MultiPortSwitch: '<S115>/Multiport Switch' */

  /* Chart: '<S114>/Chart' */
  /* Gateway: implement/method/All_loop/Slope/Tor_select/Chart */
  GearState_prev = localDW->Gear_start;
  localDW->Gear_start = rtu_Data_j;

  /* During: implement/method/All_loop/Slope/Tor_select/Chart */
  if (localDW->is_active_c19_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/Slope/Tor_select/Chart */
    localDW->is_active_c19_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/Slope/Tor_select/Chart */
    /* Transition: '<S122>:3' */
    /* Entry Internal 'Gear': '<S122>:2' */
    /* Transition: '<S122>:4' */
    /* '<S122>:7:1' sf_internal_predicateOutput = ... */
    /* '<S122>:7:1' Gear==1; */
    switch (rtu_Data_j) {
     case 1U:
      /* Transition: '<S122>:7' */
      localDW->is_Gear = APP_FluxWeak_GEAR2_IN_D;

      /* Outputs for Function Call SubSystem: '<S114>/Function-Call Subsystem' */

      /* Entry 'D': '<S122>:6' */
      /* '<S122>:6:1' D_call; */
      /* Event: '<S122>:17' */
      APP_Flu_FunctionCallSubsystem_o(rtb_Gain_g, localDW->UnitDelay_DSTATE,
        &localDW->Merge);

      /* End of Outputs for SubSystem: '<S114>/Function-Call Subsystem' */
      break;

     case 2U:
      /* Transition: '<S122>:12' */
      /* '<S122>:11:1' sf_internal_predicateOutput = ... */
      /* '<S122>:11:1' Gear==2; */
      /* Transition: '<S122>:11' */
      localDW->is_Gear = APP_FluxWeak_GEAR2_IN_R_e;

      /* Outputs for Function Call SubSystem: '<S114>/Function-Call Subsystem1' */

      /* Entry 'R': '<S122>:8' */
      /* '<S122>:8:1' R_call; */
      /* Event: '<S122>:21' */
      APP_Flux_FunctionCallSubsystem1(rtb_Gain_g, localDW->UnitDelay_DSTATE,
        &localDW->Merge);

      /* End of Outputs for SubSystem: '<S114>/Function-Call Subsystem1' */
      break;

     default:
      /* Transition: '<S122>:14' */
      /* Transition: '<S122>:15' */
      localDW->is_Gear = APP_FluxWeak_GEAR2_IN_N;

      /* Outputs for Function Call SubSystem: '<S114>/Function-Call Subsystem2' */

      /* Entry 'N': '<S122>:9' */
      /* '<S122>:9:1' N_call; */
      /* Event: '<S122>:20' */
      APP_Flux_FunctionCallSubsystem2(&localDW->Merge,
        &localDW->FunctionCallSubsystem2);

      /* End of Outputs for SubSystem: '<S114>/Function-Call Subsystem2' */
      break;
    }
  } else {
    /* During 'Gear': '<S122>:2' */
    /* '<S122>:16:1' sf_internal_predicateOutput = ... */
    /* '<S122>:16:1' hasChanged(Gear); */
    if (GearState_prev != localDW->Gear_start) {
      /* Transition: '<S122>:16' */
      /* '<S122>:7:1' sf_internal_predicateOutput = ... */
      /* '<S122>:7:1' Gear==1; */
      switch (rtu_Data_j) {
       case 1U:
        /* Transition: '<S122>:7' */
        /* Exit Internal 'Gear': '<S122>:2' */
        switch (localDW->is_Gear) {
         case APP_FluxWeak_GEAR2_IN_D:
          /* Outputs for Function Call SubSystem: '<S114>/Initial' */

          /* Exit 'D': '<S122>:6' */
          /* '<S122>:6:1' RST_N; */
          /* Event: '<S122>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S114>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         case APP_FluxWeak_GEAR2_IN_R_e:
          /* Outputs for Function Call SubSystem: '<S114>/Initial' */

          /* Exit 'R': '<S122>:8' */
          /* '<S122>:8:1' RST_N; */
          /* Event: '<S122>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S114>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         default:
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;
        }

        localDW->is_Gear = APP_FluxWeak_GEAR2_IN_D;

        /* Outputs for Function Call SubSystem: '<S114>/Function-Call Subsystem' */

        /* Entry 'D': '<S122>:6' */
        /* '<S122>:6:1' D_call; */
        /* Event: '<S122>:17' */
        APP_Flu_FunctionCallSubsystem_o(rtb_Gain_g, localDW->UnitDelay_DSTATE,
          &localDW->Merge);

        /* End of Outputs for SubSystem: '<S114>/Function-Call Subsystem' */
        break;

       case 2U:
        /* Transition: '<S122>:12' */
        /* '<S122>:11:1' sf_internal_predicateOutput = ... */
        /* '<S122>:11:1' Gear==2; */
        /* Transition: '<S122>:11' */
        /* Exit Internal 'Gear': '<S122>:2' */
        switch (localDW->is_Gear) {
         case APP_FluxWeak_GEAR2_IN_D:
          /* Outputs for Function Call SubSystem: '<S114>/Initial' */

          /* Exit 'D': '<S122>:6' */
          /* '<S122>:6:1' RST_N; */
          /* Event: '<S122>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S114>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         case APP_FluxWeak_GEAR2_IN_R_e:
          /* Outputs for Function Call SubSystem: '<S114>/Initial' */

          /* Exit 'R': '<S122>:8' */
          /* '<S122>:8:1' RST_N; */
          /* Event: '<S122>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S114>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         default:
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;
        }

        localDW->is_Gear = APP_FluxWeak_GEAR2_IN_R_e;

        /* Outputs for Function Call SubSystem: '<S114>/Function-Call Subsystem1' */

        /* Entry 'R': '<S122>:8' */
        /* '<S122>:8:1' R_call; */
        /* Event: '<S122>:21' */
        APP_Flux_FunctionCallSubsystem1(rtb_Gain_g, localDW->UnitDelay_DSTATE,
          &localDW->Merge);

        /* End of Outputs for SubSystem: '<S114>/Function-Call Subsystem1' */
        break;

       default:
        /* Transition: '<S122>:14' */
        /* Transition: '<S122>:15' */
        /* Exit Internal 'Gear': '<S122>:2' */
        switch (localDW->is_Gear) {
         case APP_FluxWeak_GEAR2_IN_D:
          /* Outputs for Function Call SubSystem: '<S114>/Initial' */

          /* Exit 'D': '<S122>:6' */
          /* '<S122>:6:1' RST_N; */
          /* Event: '<S122>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S114>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         case APP_FluxWeak_GEAR2_IN_R_e:
          /* Outputs for Function Call SubSystem: '<S114>/Initial' */

          /* Exit 'R': '<S122>:8' */
          /* '<S122>:8:1' RST_N; */
          /* Event: '<S122>:19' */
          APP_FluxWeak_GEAR2_Initial_e(&localDW->Merge);

          /* End of Outputs for SubSystem: '<S114>/Initial' */
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;

         default:
          localDW->is_Gear = APP_FluxWeak_IN_NO_ACTIVE_CHILD;
          break;
        }

        localDW->is_Gear = APP_FluxWeak_GEAR2_IN_N;

        /* Outputs for Function Call SubSystem: '<S114>/Function-Call Subsystem2' */

        /* Entry 'N': '<S122>:9' */
        /* '<S122>:9:1' N_call; */
        /* Event: '<S122>:20' */
        APP_Flux_FunctionCallSubsystem2(&localDW->Merge,
          &localDW->FunctionCallSubsystem2);

        /* End of Outputs for SubSystem: '<S114>/Function-Call Subsystem2' */
        break;
      }
    } else {
      switch (localDW->is_Gear) {
       case APP_FluxWeak_GEAR2_IN_D:
        /* Outputs for Function Call SubSystem: '<S114>/Function-Call Subsystem' */

        /* During 'D': '<S122>:6' */
        /* '<S122>:6:1' D_call; */
        /* Event: '<S122>:17' */
        APP_Flu_FunctionCallSubsystem_o(rtb_Gain_g, localDW->UnitDelay_DSTATE,
          &localDW->Merge);

        /* End of Outputs for SubSystem: '<S114>/Function-Call Subsystem' */
        break;

       case APP_FluxWeak_GEAR2_IN_N:
        /* Outputs for Function Call SubSystem: '<S114>/Function-Call Subsystem2' */

        /* During 'N': '<S122>:9' */
        /* '<S122>:9:1' N_call; */
        /* Event: '<S122>:20' */
        APP_Flux_FunctionCallSubsystem2(&localDW->Merge,
          &localDW->FunctionCallSubsystem2);

        /* End of Outputs for SubSystem: '<S114>/Function-Call Subsystem2' */
        break;

       default:
        /* Outputs for Function Call SubSystem: '<S114>/Function-Call Subsystem1' */

        /* During 'R': '<S122>:8' */
        /* '<S122>:8:1' R_call; */
        /* Event: '<S122>:21' */
        APP_Flux_FunctionCallSubsystem1(rtb_Gain_g, localDW->UnitDelay_DSTATE,
          &localDW->Merge);

        /* End of Outputs for SubSystem: '<S114>/Function-Call Subsystem1' */
        break;
      }
    }
  }

  /* End of Chart: '<S114>/Chart' */

  /* Switch: '<S72>/Switch' incorporates:
   *  Constant: '<S72>/Constant8'
   */
  if (rtu_Data_g != 0U) {
    rtb_DiscreteTimeIntegrator1_f = localDW->Merge;
  } else {
    rtb_DiscreteTimeIntegrator1_f = 0.0F;
  }

  /* End of Switch: '<S72>/Switch' */

  /* SignalConversion: '<S72>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_o = rtb_DiscreteTimeIntegrator1_f;

  /* SignalConversion: '<S72>/OutportBufferForTor' */
  *rty_Tor = rtb_DiscreteTimeIntegrator1_f;
}

/* Output and update for function-call system: '<S56>/Sync' */
void APP_FluxWeak_GEAR2_Sync(real32_T rtu_Data, real32_T rtu_Data_e, uint16_T
  *rty_Out1, real32_T *rty_Out1_e, real32_T *rty_Out1_g, real32_T *rty_Out1_g5,
  uint16_T *rty_Out1_c, uint16_T *rty_Out1_i, real32_T *rty_Out1_k, real32_T
  *rty_Out1_ed, real32_T *rty_Tor, DW_Sync_APP_FluxWeak_GEAR2_T *localDW)
{
  real32_T rtb_Add_n;
  real32_T rtb_DiscreteTimeIntegrator1_j;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_e = 0.0F;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = 0.0F;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g5 = 0.0F;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0U;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = 0U;

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_k = 0.0F;

  /* Outputs for Atomic SubSystem: '<S132>/PI' */

  /* Gain: '<S75>/Norm' incorporates:
   *  Constant: '<S132>/Constant'
   *  Constant: '<S132>/Constant1'
   *  Constant: '<S132>/Constant2'
   *  Sum: '<S75>/Subtract'
   */
  PI_App(0.0001F * (rtu_Data - rtu_Data_e), PMSM_Param.SyncKp, PMSM_Param.SyncKi,
         0.002F, &rtb_Add_n, &rtb_DiscreteTimeIntegrator1_j, &localDW->PI);

  /* End of Outputs for SubSystem: '<S132>/PI' */

  /* Saturate: '<S132>/Saturation' */
  if (rtb_Add_n > 1.0F) {
    rtb_Add_n = 1.0F;
  } else {
    if (rtb_Add_n < -1.0F) {
      rtb_Add_n = -1.0F;
    }
  }

  /* End of Saturate: '<S132>/Saturation' */

  /* SignalConversion: '<S75>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_ed = rtb_Add_n;

  /* SignalConversion: '<S75>/OutportBufferForTor' */
  *rty_Tor = rtb_Add_n;
}

/* Output and update for function-call system: '<S56>/Dischg' */
void APP_FluxWeak_GEAR2_Dischg(real32_T rtu_Data, uint16_T *rty_Out1, real32_T
  *rty_Out1_d, real32_T *rty_Out1_j, real32_T *rty_Out1_b, uint16_T *rty_Out1_o,
  uint16_T *rty_Out1_k, real32_T *rty_Out1_c, real32_T *rty_Out1_l,
  DW_Dischg_APP_FluxWeak_GEAR2_T *localDW)
{
  /* Relay: '<S66>/Relay' */
  if (rtu_Data >= 50.0F) {
    localDW->Relay_Mode = true;
  } else {
    if (rtu_Data <= 30.0F) {
      localDW->Relay_Mode = false;
    }
  }

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S66>/Constant'
   *  Constant: '<S66>/Constant9'
   *  Relay: '<S66>/Relay'
   */
  if (localDW->Relay_Mode) {
    *rty_Out1_d = PMSM_Param.DischgId;
  } else {
    *rty_Out1_d = 0.0F;
  }

  /* End of Switch: '<S66>/Switch' */

  /* SignalConversion: '<S66>/TmpBufferAtConstant1Outport1' incorporates:
   *  Constant: '<S66>/Constant1'
   */
  *rty_Out1_j = 0.0F;

  /* SignalConversion: '<S66>/TmpBufferAtConstant2Outport1' incorporates:
   *  Constant: '<S66>/Constant2'
   */
  *rty_Out1_b = 0.0F;

  /* SignalConversion: '<S66>/TmpBufferAtConstant3Outport1' incorporates:
   *  Constant: '<S66>/Constant3'
   */
  *rty_Out1_o = 1U;

  /* SignalConversion: '<S66>/TmpBufferAtConstant4Outport1' incorporates:
   *  Constant: '<S66>/Constant4'
   */
  *rty_Out1_k = 0U;

  /* SignalConversion: '<S66>/TmpBufferAtConstant5Outport1' incorporates:
   *  Constant: '<S66>/Constant5'
   */
  *rty_Out1_l = 0.0F;

  /* SignalConversion: '<S66>/TmpBufferAtConstant6Outport1' incorporates:
   *  Constant: '<S66>/Constant6'
   */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S66>/TmpBufferAtConstant8Outport1' incorporates:
   *  Constant: '<S66>/Constant8'
   */
  *rty_Out1_c = 0.0F;
}

/* Output and update for function-call system: '<S56>/ASC' */
void APP_FluxWeak_GEAR2_ASC(uint16_T *rty_Out1, real32_T *rty_Out1_e, real32_T
  *rty_Out1_l, real32_T *rty_Out1_i, uint16_T *rty_Out1_f, uint16_T *rty_Out1_g,
  real32_T *rty_Out1_gu, real32_T *rty_Out1_k)
{
  /* SignalConversion: '<S63>/TmpBufferAtConstant1Outport1' incorporates:
   *  Constant: '<S63>/Constant1'
   */
  *rty_Out1_l = 0.0F;

  /* SignalConversion: '<S63>/TmpBufferAtConstant2Outport1' incorporates:
   *  Constant: '<S63>/Constant2'
   */
  *rty_Out1_i = 0.0F;

  /* SignalConversion: '<S63>/TmpBufferAtConstant3Outport1' incorporates:
   *  Constant: '<S63>/Constant3'
   */
  *rty_Out1_f = 0U;

  /* SignalConversion: '<S63>/TmpBufferAtConstant4Outport1' incorporates:
   *  Constant: '<S63>/Constant4'
   */
  *rty_Out1_g = 0U;

  /* SignalConversion: '<S63>/TmpBufferAtConstant5Outport1' incorporates:
   *  Constant: '<S63>/Constant5'
   */
  *rty_Out1_k = 0.0F;

  /* SignalConversion: '<S63>/TmpBufferAtConstant6Outport1' incorporates:
   *  Constant: '<S63>/Constant6'
   */
  *rty_Out1 = 1U;

  /* SignalConversion: '<S63>/TmpBufferAtConstant8Outport1' incorporates:
   *  Constant: '<S63>/Constant8'
   */
  *rty_Out1_gu = 0.0F;

  /* SignalConversion: '<S63>/TmpBufferAtConstantOutport1' incorporates:
   *  Constant: '<S63>/Constant'
   */
  *rty_Out1_e = 0.0F;
}

/* System initialize for function-call system: '<S64>/PhaseStudy' */
void APP_FluxWeak_GE_PhaseStudy_Init(DW_PhaseStudy_APP_FluxWeak_GE_T *localDW)
{
  /* SystemInitialize for Chart: '<S85>/Chart' */
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

/* Output and update for function-call system: '<S64>/PhaseStudy' */
void APP_FluxWeak_GEAR2_PhaseStudy(real32_T rtu_Data, real32_T rtu_Data_g,
  uint16_T *rty_Out1, real32_T *rty_Out1_g, real32_T *rty_Out1_h, real32_T
  *rty_Out1_i, uint16_T *rty_Out1_a, uint16_T *rty_Out1_a3, real32_T
  *rty_Out1_at, real32_T *rty_Out1_gs, DW_PhaseStudy_APP_FluxWeak_GE_T *localDW)
{
  boolean_T sf_internal_predicateOutput;
  real32_T tmp;
  boolean_T guard1 = false;

  /* Chart: '<S85>/Chart' */
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
    /* Transition: '<S100>:7' */
    localDW->is_c10_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Init;

    /* Entry 'Init': '<S100>:6' */
    /* '<S100>:6:1' StudyResult = 8888; */
    localDW->StudyResult = 8888.0F;

    /* '<S100>:6:1' StudyStep=10; */
    localDW->StudyStep = 10U;
  } else {
    guard1 = false;
    switch (localDW->is_c10_APP_FluxWeak_GEAR2) {
     case APP_FluxWeak_GEAR2_IN_Fault:
      /* During 'Fault': '<S100>:10' */
      break;

     case APP_FluxWeak_GEAR2_IN_Fin1:
      /* During 'Fin1': '<S100>:185' */
      break;

     case APP_FluxWeak_GEAR2_IN_Init:
      /* During 'Init': '<S100>:6' */
      /* '<S100>:11:1' sf_internal_predicateOutput = ... */
      /* '<S100>:11:1' TqReq > 0.001; */
      if (rtu_Data_g > 0.001) {
        /* Transition: '<S100>:11' */
        localDW->is_c10_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Study;

        /* Entry 'Study': '<S100>:8' */
        /* '<S100>:8:1' StudyStep=11; */
        localDW->StudyStep = 11U;

        /* Entry Internal 'Study': '<S100>:8' */
        /* Transition: '<S100>:74' */
        localDW->is_Study = APP_FluxWeak_GEAR2_IN_AddId;

        /* Entry 'AddId': '<S100>:72' */
        /* 增加id */
        /* '<S100>:72:1' IdRefSet = IdRefSet + 0.001; */
        localDW->IdRefSet += 0.001F;
      }
      break;

     default:
      /* During 'Study': '<S100>:8' */
      switch (localDW->is_Study) {
       case APP_FluxWeak_GEAR2_IN_AddId:
        /* During 'AddId': '<S100>:72' */
        /* '<S100>:69:1' sf_internal_predicateOutput = ... */
        /* '<S100>:69:1' IdRefSet > 0.3; */
        if (localDW->IdRefSet > 0.3) {
          /* Transition: '<S100>:69' */
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_Wait1;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'Wait1': '<S100>:70' */
          /* 等 */
          /* '<S100>:70:1' IdRefSet = 0.3; */
          localDW->IdRefSet = 0.3F;
        } else {
          /* '<S100>:72:1' IdRefSet = IdRefSet + 0.001; */
          localDW->IdRefSet += 0.001F;
        }
        break;

       case APP_FluxWeak_GEAR2_IN_ChgAngle1:
        /* During 'ChgAngle1': '<S100>:73' */
        /* '<S100>:83:1' sf_internal_predicateOutput = ... */
        /* '<S100>:83:1' AngleRefSet > 1.5708; */
        if (localDW->AngleRefSet > 1.5708) {
          /* Transition: '<S100>:83' */
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_Wait3;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'Wait3': '<S100>:86' */
          /* 等 */
          /* '<S100>:86:1' AngleRefSet = 1.5708; */
          localDW->AngleRefSet = 1.5708F;
        } else {
          /* '<S100>:73:2' AngleRefSet = AngleRefSet + 0.001; */
          localDW->AngleRefSet += 0.001F;
        }
        break;

       case APP_FluxWeak_GEAR2_IN_DecId:
        /* During 'DecId': '<S100>:82' */
        /* '<S100>:85:1' sf_internal_predicateOutput = ... */
        /* '<S100>:85:1' IdRefSet < 0.002; */
        if (localDW->IdRefSet < 0.002) {
          /* Transition: '<S100>:85' */
          /* Transition: '<S100>:182' */
          /* '<S100>:182:1' IdRefSet = 0; */
          localDW->IdRefSet = 0.0F;

          /* '<S100>:98:1' sf_internal_predicateOutput = ... */
          /* '<S100>:98:1' ThetaDelta < -2048; */
          if (localDW->ThetaDelta < -2048.0F) {
            /* Transition: '<S100>:98' */
            /* Transition: '<S100>:94' */
            /* '<S100>:94:1' ThetaDelta = ThetaDelta + 4096; */
            localDW->ThetaDelta += 4096.0F;
          } else {
            /* '<S100>:95:1' sf_internal_predicateOutput = ... */
            /* '<S100>:95:1' ThetaDelta > 2048; */
            if (localDW->ThetaDelta > 2048.0F) {
              /* Transition: '<S100>:95' */
              /* Transition: '<S100>:96' */
              /* '<S100>:96:1' ThetaDelta = ThetaDelta -4096; */
              localDW->ThetaDelta -= 4096.0F;
            } else {
              /* Transition: '<S100>:90' */
            }
          }

          /* '<S100>:92:1' sf_internal_predicateOutput = ... */
          /* '<S100>:92:1' abs(ThetaDelta) < (0.3*1024 / PMSM_Param.PoleRatio); */
          if (fabsf(localDW->ThetaDelta) < 307.2F / PMSM_Param.PoleRatio) {
            /* Transition: '<S100>:92' */
            /* Transition: '<S100>:184' */
            localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_j;
            localDW->is_c10_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Fault;

            /* Entry 'Fault': '<S100>:10' */
            /* 故障 */
            /* '<S100>:10:1' StudyResult = 5555; */
            localDW->StudyResult = 5555.0F;

            /* '<S100>:10:1' IdRefSet = 0; */
            localDW->IdRefSet = 0.0F;

            /* '<S100>:10:3' StudyStep=14; */
            localDW->StudyStep = 14U;
          } else {
            /* Transition: '<S100>:89' */
            localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_j;
            localDW->is_c10_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Fin1;

            /* Entry 'Fin1': '<S100>:185' */
            /* 完成(成功) */
            /* Entry Internal 'Fin1': '<S100>:185' */
            /* Transition: '<S100>:194' */
            /* '<S100>:195:1' sf_internal_predicateOutput = ... */
            /* '<S100>:195:1' ThetaDelta>1024 /PMSM_Param.PoleRatio*0.3 && ... */
            /* '<S100>:195:1' ThetaDelta<1024 /PMSM_Param.PoleRatio*1.7; */
            tmp = 1024.0F / PMSM_Param.PoleRatio;
            if (localDW->ThetaDelta > tmp * 0.3F) {
              sf_internal_predicateOutput = (localDW->ThetaDelta < tmp * 1.7F);
            } else {
              sf_internal_predicateOutput = false;
            }

            if (sf_internal_predicateOutput) {
              /* Transition: '<S100>:195' */
              /* 角度变化量在pi/2附近 */
              /* Transition: '<S100>:196' */
              /* '<S100>:198:1' sf_internal_predicateOutput = ... */
              /* '<S100>:198:1' PMSM_Param.ResolverDirChg == 1; */
              if (PMSM_Param.ResolverDirChg == 1U) {
                /* Transition: '<S100>:198' */
                guard1 = true;
              } else {
                /* Transition: '<S100>:200' */
                /* '<S100>:200:1' StudyResult =0; */
                localDW->StudyResult = 0.0F;

                /* '<S100>:200:1' StudyStep=13; */
                localDW->StudyStep = 13U;
              }
            } else {
              /* Transition: '<S100>:197' */
              /* '<S100>:199:1' sf_internal_predicateOutput = ... */
              /* '<S100>:199:1' PMSM_Param.ResolverDirChg == 0; */
              if (PMSM_Param.ResolverDirChg == 0U) {
                /* Transition: '<S100>:199' */
                guard1 = true;
              } else {
                /* Transition: '<S100>:202' */
                /* '<S100>:202:1' StudyResult =0; */
                localDW->StudyResult = 0.0F;

                /* '<S100>:202:1' StudyStep=13; */
                localDW->StudyStep = 13U;

                /* Transition: '<S100>:204' */
                /* Transition: '<S100>:203' */
              }
            }
          }
        } else {
          /* '<S100>:82:3' IdRefSet = IdRefSet - 0.001; */
          localDW->IdRefSet -= 0.001F;
        }
        break;

       case APP_FluxWeak_GEAR2_IN_Wait1:
        /* During 'Wait1': '<S100>:70' */
        /* '<S100>:71:1' sf_internal_predicateOutput = ... */
        /* '<S100>:71:1' after(100,tick); */
        if ((int16_T)localDW->temporalCounter_i1 >= 100) {
          /* Transition: '<S100>:71' */
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_ChgAngle1;

          /* Entry 'ChgAngle1': '<S100>:73' */
          /* 改变角度 */
          /* '<S100>:73:1' ThetaRTHis = single(ThetaRT); */
          localDW->ThetaRTHis = rtu_Data;
        }
        break;

       default:
        /* During 'Wait3': '<S100>:86' */
        /* '<S100>:84:1' sf_internal_predicateOutput = ... */
        /* '<S100>:84:1' after(100,tick); */
        if ((int16_T)localDW->temporalCounter_i1 >= 100) {
          /* Transition: '<S100>:84' */
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_DecId;

          /* Entry 'DecId': '<S100>:82' */
          /* 减id */
          /* '<S100>:82:1' ThetaDelta = single(ThetaRT) - ThetaRTHis; */
          localDW->ThetaDelta = rtu_Data - localDW->ThetaRTHis;
        } else {
          /* '<S100>:86:1' AngleRefSet = 1.5708; */
          localDW->AngleRefSet = 1.5708F;
        }
        break;
      }
      break;
    }

    if (guard1) {
      /* Transition: '<S100>:201' */
      /* '<S100>:201:1' StudyResult =1; */
      localDW->StudyResult = 1.0F;

      /* '<S100>:201:1' StudyStep=12; */
      localDW->StudyStep = 12U;

      /* Transition: '<S100>:203' */
    }
  }

  /* End of Chart: '<S85>/Chart' */

  /* DataStoreWrite: '<S85>/Data Store Write' */
  AppFun.StudyResult = localDW->StudyResult;

  /* DataStoreWrite: '<S85>/Data Store Write1' */
  AppFun.StudyStep = localDW->StudyStep;

  /* SignalConversion: '<S85>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S85>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = localDW->IdRefSet;

  /* SignalConversion: '<S85>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_h = 0.0F;

  /* SignalConversion: '<S85>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = localDW->AngleRefSet;

  /* SignalConversion: '<S85>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_a = 1U;

  /* SignalConversion: '<S85>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_a3 = 1U;

  /* SignalConversion: '<S85>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_at = 0.0F;

  /* SignalConversion: '<S85>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_gs = 0.0F;
}

/* System initialize for function-call system: '<S64>/Hall' */
void APP_FluxWeak_GEAR2_Hall_Init(DW_Hall_APP_FluxWeak_GEAR2_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S82>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S82>/Chart' */
  localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_k;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c27_APP_FluxWeak_GEAR = 0U;
  localDW->is_c27_APP_FluxWeak_GEAR2 = APP_FluxWe_IN_NO_ACTIVE_CHILD_k;
  localDW->StudyResult = 0.0F;
  localDW->IdRefSet = 0.0F;
  localDW->ExSpd = 0.0F;
}

/* System reset for function-call system: '<S64>/Hall' */
void APP_FluxWeak_GEAR2_Hall_Reset(DW_Hall_APP_FluxWeak_GEAR2_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S82>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_h = 0.0F;

  /* SystemReset for Chart: '<S82>/Chart' */
  localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_k;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c27_APP_FluxWeak_GEAR = 0U;
  localDW->is_c27_APP_FluxWeak_GEAR2 = APP_FluxWe_IN_NO_ACTIVE_CHILD_k;
  localDW->StudyResult = 0.0F;
  localDW->IdRefSet = 0.0F;
  localDW->ExSpd = 0.0F;
}

/* Output and update for function-call system: '<S64>/Hall' */
void APP_FluxWeak_GEAR2_Hall(real32_T rtu_Data, uint16_T *rty_Out1, real32_T
  *rty_Out1_c, real32_T *rty_Out1_h, real32_T *rty_Out1_d, uint16_T *rty_Out1_n,
  uint16_T *rty_Out1_p, real32_T *rty_Out1_db, real32_T *rty_Out1_b,
  DW_Hall_APP_FluxWeak_GEAR2_T *localDW)
{
  /* Chart: '<S82>/Chart' */
  /* Gateway: implement/method/All_loop/Calib/Hall/Chart */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  /* During: implement/method/All_loop/Calib/Hall/Chart */
  if (localDW->is_active_c27_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/Calib/Hall/Chart */
    localDW->is_active_c27_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/Calib/Hall/Chart */
    /* Transition: '<S93>:7' */
    localDW->is_c27_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Init_a;

    /* Entry 'Init': '<S93>:6' */
    /* '<S93>:6:1' StudyResult = 8888; */
    localDW->StudyResult = 8888.0F;
  } else {
    switch (localDW->is_c27_APP_FluxWeak_GEAR2) {
     case APP_FluxWeak_GEAR2_IN_Init_a:
      localDW->StudyResult = 8888.0F;

      /* During 'Init': '<S93>:6' */
      /* '<S93>:11:1' sf_internal_predicateOutput = ... */
      /* '<S93>:11:1' TqReq > 0.01; */
      if (rtu_Data > 0.01) {
        /* Transition: '<S93>:11' */
        localDW->is_c27_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Study_m;

        /* Entry Internal 'Study': '<S93>:8' */
        /* Transition: '<S93>:212' */
        localDW->is_Study = APP_FluxWeak_GEAR2_IN_Wait1_e;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'Wait1': '<S93>:209' */
        /* 等 */
        /* '<S93>:209:1' IdRefSet = 0.3; */
        localDW->IdRefSet = 0.3F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_Stop:
      localDW->StudyResult = 7777.0F;
      localDW->IdRefSet = 0.0F;

      /* During 'Stop': '<S93>:10' */
      break;

     default:
      /* During 'Study': '<S93>:8' */
      /* '<S93>:213:1' sf_internal_predicateOutput = ... */
      /* '<S93>:213:1' abs(TqReq) <0.01; */
      if (fabsf(rtu_Data) < 0.01) {
        /* Transition: '<S93>:213' */
        /* Exit Internal 'Study': '<S93>:8' */
        localDW->is_Study = APP_FluxWe_IN_NO_ACTIVE_CHILD_k;
        localDW->is_c27_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Stop;

        /* Entry 'Stop': '<S93>:10' */
        /* 停止 */
        /* '<S93>:10:1' StudyResult = 7777; */
        localDW->StudyResult = 7777.0F;

        /* '<S93>:10:1' IdRefSet = 0; */
        localDW->IdRefSet = 0.0F;
      } else if (localDW->is_Study == 1U) {
        /* During 'AddId1': '<S93>:205' */
        /* '<S93>:205:1' ExSpd = 20; */
        localDW->ExSpd = 20.0F;
      } else {
        localDW->IdRefSet = 0.3F;

        /* During 'Wait1': '<S93>:209' */
        /* '<S93>:206:1' sf_internal_predicateOutput = ... */
        /* '<S93>:206:1' after(1000,tick); */
        if (localDW->temporalCounter_i1 >= 1000U) {
          /* Transition: '<S93>:206' */
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_AddId1;

          /* Entry 'AddId1': '<S93>:205' */
          /* 增加id */
          /* '<S93>:205:1' ExSpd = 20; */
          localDW->ExSpd = 20.0F;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S82>/Chart' */

  /* DataStoreWrite: '<S82>/Data Store Write' */
  AppFun.StudyResult = localDW->StudyResult;

  /* SignalConversion: '<S82>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S82>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   */
  *rty_Out1_c = localDW->DiscreteTimeIntegrator_DSTATE;

  /* SignalConversion: '<S82>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_h = 0.0F;

  /* DiscreteIntegrator: '<S82>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S94>/Constant'
   *  RelationalOperator: '<S94>/Compare'
   *  UnitDelay: '<S82>/Unit Delay'
   */
  if (localDW->UnitDelay_DSTATE >= 6.28318548F) {
    localDW->DiscreteTimeIntegrator_DSTATE_i = 0.0F;
  }

  /* SignalConversion: '<S82>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
   *  DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
   */
  *rty_Out1_d = localDW->DiscreteTimeIntegrator_DSTATE_i;

  /* SignalConversion: '<S82>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_n = 1U;

  /* SignalConversion: '<S82>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_p = 1U;

  /* SignalConversion: '<S82>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_db = 0.0F;

  /* SignalConversion: '<S82>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_b = 0.0F;

  /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S96>/Gain'
   *  Sum: '<S96>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE += (localDW->IdRefSet -
    localDW->DiscreteTimeIntegrator_DSTATE) * 10.0F * 0.002F;

  /* Update for UnitDelay: '<S82>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
   */
  localDW->UnitDelay_DSTATE = localDW->DiscreteTimeIntegrator_DSTATE_i;

  /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_i += 0.000209439517F *
    localDW->DiscreteTimeIntegrator_DSTATE_h;

  /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S95>/Gain'
   *  Sum: '<S95>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_h += (localDW->ExSpd -
    localDW->DiscreteTimeIntegrator_DSTATE_h) * 5.0F * 0.002F;
}

/*
 * Function for Chart: '<S80>/Chart'
 * function y=Turn(x)
 */
static real32_T APP_FluxWeak_GEAR2_Turn(real32_T x)
{
  real32_T y;

  /* MATLAB Function 'Turn': '<S87>:207' */
  /* Graphical Function 'Turn': '<S87>:207' */
  /* '<S87>:213:1' sf_internal_predicateOutput = ... */
  /* '<S87>:213:1' x>=4096; */
  if (x >= 4096.0F) {
    /* '<S87>:215:1' y=x-4096; */
    y = x - 4096.0F;
  } else {
    /* '<S87>:216:1' sf_internal_predicateOutput = ... */
    /* '<S87>:216:1' x<0; */
    if (x < 0.0F) {
      /* '<S87>:218:1' y=x+4096; */
      y = x + 4096.0F;
    } else {
      /* '<S87>:217:1' y=x; */
      y = x;
    }
  }

  return y;
}

/* Function for Chart: '<S80>/Chart' */
static void APP_Fl_enter_internal_SPEEDFORW(real32_T rtu_Data_n,
  DW_ElecZeroStudy_APP_FluxWeak_T *localDW)
{
  uint16_T qY;

  /* Entry Internal 'SPEEDFORW': '<S87>:97' */
  /* Transition: '<S87>:116' */
  /* '<S87>:119:1' sf_internal_predicateOutput = ... */
  /* '<S87>:119:1' UdFil > 0.03; */
  if (rtu_Data_n > 0.03) {
    /* Transition: '<S87>:119' */
    /* Entry 'Sub1': '<S87>:124' */
    /* '<S87>:124:1' ZeroStudyCnt = 0; */
    localDW->ZeroStudyCnt = 0U;

    /* '<S87>:124:1' CalibZeroPoint = CalibZeroPoint + 4; */
    localDW->CalibZeroPoint += 4.0F;

    /* '<S87>:124:4' CalibZeroPoint=Turn(CalibZeroPoint); */
    localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn(localDW->CalibZeroPoint);

    /* '<S87>:124:5' StudyStep=21; */
    localDW->StudyStep = 21U;
  } else {
    /* Transition: '<S87>:127' */
    /* '<S87>:102:1' sf_internal_predicateOutput = ... */
    /* '<S87>:102:1' UdFil>0; */
    if (rtu_Data_n > 0.0F) {
      /* Transition: '<S87>:102' */
      /* Entry 'Sub2': '<S87>:130' */
      /* '<S87>:130:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
      qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
      if (qY < localDW->ZeroStudyCnt) {
        qY = MAX_uint16_T;
      }

      localDW->ZeroStudyCnt = qY;

      /* '<S87>:130:1' CalibZeroPoint = CalibZeroPoint + 1; */
      localDW->CalibZeroPoint++;

      /* '<S87>:130:4' CalibZeroPoint=Turn(CalibZeroPoint); */
      localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn(localDW->CalibZeroPoint);

      /* '<S87>:130:5' StudyStep=22; */
      localDW->StudyStep = 22U;
    } else {
      /* Transition: '<S87>:100' */
      /* '<S87>:121:1' sf_internal_predicateOutput = ... */
      /* '<S87>:121:1' UdFil > -0.03; */
      if (rtu_Data_n > -0.03) {
        /* Transition: '<S87>:121' */
        /* Entry 'Sub3': '<S87>:111' */
        /* '<S87>:111:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
        qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
        if (qY < localDW->ZeroStudyCnt) {
          qY = MAX_uint16_T;
        }

        localDW->ZeroStudyCnt = qY;

        /* '<S87>:111:1' CalibZeroPoint = CalibZeroPoint - 1; */
        localDW->CalibZeroPoint--;

        /* '<S87>:111:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S87>:111:5' StudyStep=22; */
        localDW->StudyStep = 22U;
      } else {
        /* Transition: '<S87>:113' */
        /* Entry 'Sub4': '<S87>:99' */
        /* '<S87>:99:1' ZeroStudyCnt = 0; */
        localDW->ZeroStudyCnt = 0U;

        /* '<S87>:99:1' CalibZeroPoint = CalibZeroPoint - 4; */
        localDW->CalibZeroPoint -= 4.0F;

        /* '<S87>:99:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S87>:99:5' StudyStep=21; */
        localDW->StudyStep = 21U;
      }
    }
  }
}

/* Function for Chart: '<S80>/Chart' */
static void APP_Flu_enter_internal_SPEEDINV(real32_T rtu_Data_n,
  DW_ElecZeroStudy_APP_FluxWeak_T *localDW)
{
  uint16_T qY;

  /* Entry Internal 'SPEEDINV': '<S87>:98' */
  /* Transition: '<S87>:96' */
  /* '<S87>:125:1' sf_internal_predicateOutput = ... */
  /* '<S87>:125:1' UdFil > 0.03; */
  if (rtu_Data_n > 0.03) {
    /* Transition: '<S87>:125' */
    /* Entry 'Sub1': '<S87>:115' */
    /* '<S87>:115:1' ZeroStudyCnt = 0; */
    localDW->ZeroStudyCnt = 0U;

    /* '<S87>:115:1' CalibZeroPoint = CalibZeroPoint - 4; */
    localDW->CalibZeroPoint -= 4.0F;

    /* '<S87>:115:4' CalibZeroPoint=Turn(CalibZeroPoint); */
    localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn(localDW->CalibZeroPoint);

    /* '<S87>:115:5' StudyStep=21; */
    localDW->StudyStep = 21U;
  } else {
    /* Transition: '<S87>:129' */
    /* '<S87>:110:1' sf_internal_predicateOutput = ... */
    /* '<S87>:110:1' UdFil>0; */
    if (rtu_Data_n > 0.0F) {
      /* Transition: '<S87>:110' */
      /* Entry 'Sub2': '<S87>:112' */
      /* '<S87>:112:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
      qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
      if (qY < localDW->ZeroStudyCnt) {
        qY = MAX_uint16_T;
      }

      localDW->ZeroStudyCnt = qY;

      /* '<S87>:112:1' CalibZeroPoint = CalibZeroPoint - 1; */
      localDW->CalibZeroPoint--;

      /* '<S87>:112:4' CalibZeroPoint=Turn(CalibZeroPoint); */
      localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn(localDW->CalibZeroPoint);

      /* '<S87>:112:5' StudyStep=22; */
      localDW->StudyStep = 22U;
    } else {
      /* Transition: '<S87>:117' */
      /* '<S87>:126:1' sf_internal_predicateOutput = ... */
      /* '<S87>:126:1' UdFil > -0.03; */
      if (rtu_Data_n > -0.03) {
        /* Transition: '<S87>:126' */
        /* Entry 'Sub3': '<S87>:103' */
        /* '<S87>:103:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
        qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
        if (qY < localDW->ZeroStudyCnt) {
          qY = MAX_uint16_T;
        }

        localDW->ZeroStudyCnt = qY;

        /* '<S87>:103:1' CalibZeroPoint = CalibZeroPoint + 1; */
        localDW->CalibZeroPoint++;

        /* '<S87>:103:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S87>:103:5' StudyStep=22; */
        localDW->StudyStep = 22U;
      } else {
        /* Transition: '<S87>:101' */
        /* Entry 'Sub4': '<S87>:128' */
        /* '<S87>:128:1' ZeroStudyCnt = 0; */
        localDW->ZeroStudyCnt = 0U;

        /* '<S87>:128:1' CalibZeroPoint = CalibZeroPoint + 4; */
        localDW->CalibZeroPoint += 4.0F;

        /* '<S87>:128:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S87>:128:5' StudyStep=21; */
        localDW->StudyStep = 21U;
      }
    }
  }
}

/* Function for Chart: '<S80>/Chart' */
static void APP_FluxWeak_GEAR2_Study(real32_T rtu_Data_n, real32_T rtu_Data_j,
  real32_T rtu_Data_o, DW_ElecZeroStudy_APP_FluxWeak_T *localDW)
{
  uint16_T qY;

  /* During 'Study': '<S87>:83' */
  switch (localDW->is_Study) {
   case APP_FluxWeak_GEAR2_IN_Fin:
    /* During 'Fin': '<S87>:133' */
    /* '<S87>:133:1' StudyResult = CalibZeroPoint; */
    localDW->StudyResult = localDW->CalibZeroPoint;

    /* '<S87>:133:1' StudyStep=23; */
    localDW->StudyStep = 23U;
    break;

   case APP_FluxWeak_GEAR2_IN_Fin1_c:
    /* During 'Fin1': '<S87>:194' */
    /* '<S87>:194:1' StudyResult = CalibZeroPoint; */
    localDW->StudyResult = localDW->CalibZeroPoint;

    /* '<S87>:194:1' StudyStep=23; */
    localDW->StudyStep = 23U;
    break;

   case APP_FluxWeak_GEAR2_IN_SPEEDFORW:
    /* Chart: '<S80>/Chart' */
    /* During 'SPEEDFORW': '<S87>:97' */
    /* '<S87>:193:1' sf_internal_predicateOutput = ... */
    /* '<S87>:193:1' abs(UdFil) < 0.01 && ZeroStudyCnt > 200; */
    if ((fabsf(rtu_Data_n) < 0.01) && (localDW->ZeroStudyCnt > 200U)) {
      /* Transition: '<S87>:193' */
      /* Exit Internal 'SPEEDFORW': '<S87>:97' */
      localDW->is_Study = APP_FluxWeak_GEAR2_IN_Fin1_c;

      /* Entry 'Fin1': '<S87>:194' */
      /* 完成 */
      /* '<S87>:194:1' StudyResult = CalibZeroPoint; */
      localDW->StudyResult = localDW->CalibZeroPoint;

      /* '<S87>:194:2' StudyStep=23; */
      localDW->StudyStep = 23U;
    } else {
      /* Transition: '<S87>:231' */
      /* '<S87>:119:1' sf_internal_predicateOutput = ... */
      /* '<S87>:119:1' UdFil > 0.03; */
      if (rtu_Data_n > 0.03) {
        /* Transition: '<S87>:119' */
        /* Exit Internal 'SPEEDFORW': '<S87>:97' */
        /* Entry 'Sub1': '<S87>:124' */
        /* '<S87>:124:1' ZeroStudyCnt = 0; */
        localDW->ZeroStudyCnt = 0U;

        /* '<S87>:124:1' CalibZeroPoint = CalibZeroPoint + 4; */
        localDW->CalibZeroPoint += 4.0F;

        /* '<S87>:124:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S87>:124:5' StudyStep=21; */
        localDW->StudyStep = 21U;
      } else {
        /* Transition: '<S87>:127' */
        /* '<S87>:102:1' sf_internal_predicateOutput = ... */
        /* '<S87>:102:1' UdFil>0; */
        if (rtu_Data_n > 0.0F) {
          /* Transition: '<S87>:102' */
          /* Exit Internal 'SPEEDFORW': '<S87>:97' */
          /* Entry 'Sub2': '<S87>:130' */
          /* '<S87>:130:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
          qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
          if (qY < localDW->ZeroStudyCnt) {
            qY = MAX_uint16_T;
          }

          localDW->ZeroStudyCnt = qY;

          /* '<S87>:130:1' CalibZeroPoint = CalibZeroPoint + 1; */
          localDW->CalibZeroPoint++;

          /* '<S87>:130:4' CalibZeroPoint=Turn(CalibZeroPoint); */
          localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
            (localDW->CalibZeroPoint);

          /* '<S87>:130:5' StudyStep=22; */
          localDW->StudyStep = 22U;
        } else {
          /* Transition: '<S87>:100' */
          /* '<S87>:121:1' sf_internal_predicateOutput = ... */
          /* '<S87>:121:1' UdFil > -0.03; */
          if (rtu_Data_n > -0.03) {
            /* Transition: '<S87>:121' */
            /* Exit Internal 'SPEEDFORW': '<S87>:97' */
            /* Entry 'Sub3': '<S87>:111' */
            /* '<S87>:111:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
            qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
            if (qY < localDW->ZeroStudyCnt) {
              qY = MAX_uint16_T;
            }

            localDW->ZeroStudyCnt = qY;

            /* '<S87>:111:1' CalibZeroPoint = CalibZeroPoint - 1; */
            localDW->CalibZeroPoint--;

            /* '<S87>:111:4' CalibZeroPoint=Turn(CalibZeroPoint); */
            localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
              (localDW->CalibZeroPoint);

            /* '<S87>:111:5' StudyStep=22; */
            localDW->StudyStep = 22U;
          } else {
            /* Transition: '<S87>:113' */
            /* Exit Internal 'SPEEDFORW': '<S87>:97' */
            /* Entry 'Sub4': '<S87>:99' */
            /* '<S87>:99:1' ZeroStudyCnt = 0; */
            localDW->ZeroStudyCnt = 0U;

            /* '<S87>:99:1' CalibZeroPoint = CalibZeroPoint - 4; */
            localDW->CalibZeroPoint -= 4.0F;

            /* '<S87>:99:4' CalibZeroPoint=Turn(CalibZeroPoint); */
            localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
              (localDW->CalibZeroPoint);

            /* '<S87>:99:5' StudyStep=21; */
            localDW->StudyStep = 21U;
          }
        }
      }
    }
    break;

   case APP_FluxWeak_GEAR2_IN_SPEEDINV:
    /* Chart: '<S80>/Chart' */
    /* During 'SPEEDINV': '<S87>:98' */
    /* '<S87>:108:1' sf_internal_predicateOutput = ... */
    /* '<S87>:108:1' abs(UdFil) < 0.01 && ZeroStudyCnt > 200; */
    if ((fabsf(rtu_Data_n) < 0.01) && (localDW->ZeroStudyCnt > 200U)) {
      /* Transition: '<S87>:108' */
      /* Exit Internal 'SPEEDINV': '<S87>:98' */
      localDW->is_Study = APP_FluxWeak_GEAR2_IN_Fin;

      /* Entry 'Fin': '<S87>:133' */
      /* 完成 */
      /* '<S87>:133:1' StudyResult = CalibZeroPoint; */
      localDW->StudyResult = localDW->CalibZeroPoint;

      /* '<S87>:133:2' StudyStep=23; */
      localDW->StudyStep = 23U;
    } else {
      /* Transition: '<S87>:236' */
      /* '<S87>:125:1' sf_internal_predicateOutput = ... */
      /* '<S87>:125:1' UdFil > 0.03; */
      if (rtu_Data_n > 0.03) {
        /* Transition: '<S87>:125' */
        /* Exit Internal 'SPEEDINV': '<S87>:98' */
        /* Entry 'Sub1': '<S87>:115' */
        /* '<S87>:115:1' ZeroStudyCnt = 0; */
        localDW->ZeroStudyCnt = 0U;

        /* '<S87>:115:1' CalibZeroPoint = CalibZeroPoint - 4; */
        localDW->CalibZeroPoint -= 4.0F;

        /* '<S87>:115:4' CalibZeroPoint=Turn(CalibZeroPoint); */
        localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
          (localDW->CalibZeroPoint);

        /* '<S87>:115:5' StudyStep=21; */
        localDW->StudyStep = 21U;
      } else {
        /* Transition: '<S87>:129' */
        /* '<S87>:110:1' sf_internal_predicateOutput = ... */
        /* '<S87>:110:1' UdFil>0; */
        if (rtu_Data_n > 0.0F) {
          /* Transition: '<S87>:110' */
          /* Exit Internal 'SPEEDINV': '<S87>:98' */
          /* Entry 'Sub2': '<S87>:112' */
          /* '<S87>:112:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
          qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
          if (qY < localDW->ZeroStudyCnt) {
            qY = MAX_uint16_T;
          }

          localDW->ZeroStudyCnt = qY;

          /* '<S87>:112:1' CalibZeroPoint = CalibZeroPoint - 1; */
          localDW->CalibZeroPoint--;

          /* '<S87>:112:4' CalibZeroPoint=Turn(CalibZeroPoint); */
          localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
            (localDW->CalibZeroPoint);

          /* '<S87>:112:5' StudyStep=22; */
          localDW->StudyStep = 22U;
        } else {
          /* Transition: '<S87>:117' */
          /* '<S87>:126:1' sf_internal_predicateOutput = ... */
          /* '<S87>:126:1' UdFil > -0.03; */
          if (rtu_Data_n > -0.03) {
            /* Transition: '<S87>:126' */
            /* Exit Internal 'SPEEDINV': '<S87>:98' */
            /* Entry 'Sub3': '<S87>:103' */
            /* '<S87>:103:1' ZeroStudyCnt = ZeroStudyCnt + 1; */
            qY = localDW->ZeroStudyCnt + /*MW:OvSatOk*/ 1U;
            if (qY < localDW->ZeroStudyCnt) {
              qY = MAX_uint16_T;
            }

            localDW->ZeroStudyCnt = qY;

            /* '<S87>:103:1' CalibZeroPoint = CalibZeroPoint + 1; */
            localDW->CalibZeroPoint++;

            /* '<S87>:103:4' CalibZeroPoint=Turn(CalibZeroPoint); */
            localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
              (localDW->CalibZeroPoint);

            /* '<S87>:103:5' StudyStep=22; */
            localDW->StudyStep = 22U;
          } else {
            /* Transition: '<S87>:101' */
            /* Exit Internal 'SPEEDINV': '<S87>:98' */
            /* Entry 'Sub4': '<S87>:128' */
            /* '<S87>:128:1' ZeroStudyCnt = 0; */
            localDW->ZeroStudyCnt = 0U;

            /* '<S87>:128:1' CalibZeroPoint = CalibZeroPoint + 4; */
            localDW->CalibZeroPoint += 4.0F;

            /* '<S87>:128:4' CalibZeroPoint=Turn(CalibZeroPoint); */
            localDW->CalibZeroPoint = APP_FluxWeak_GEAR2_Turn
              (localDW->CalibZeroPoint);

            /* '<S87>:128:5' StudyStep=21; */
            localDW->StudyStep = 21U;
          }
        }
      }
    }
    break;

   case APP_FluxWeak_GEAR_IN_ZeroPoint0:
    localDW->IdIqSetEn = 1U;

    /* Chart: '<S80>/Chart' */
    /* During 'ZeroPoint0': '<S87>:89' */
    /* '<S87>:92:1' sf_internal_predicateOutput = ... */
    /* '<S87>:92:1' UsFil > 0.3; */
    if (rtu_Data_j > 0.3) {
      /* Transition: '<S87>:92' */
      /* '<S87>:107:1' sf_internal_predicateOutput = ... */
      /* '<S87>:107:1' PMSM_Param.ResolverDirChg == 1; */
      if (PMSM_Param.ResolverDirChg == 1U) {
        /* Transition: '<S87>:107' */
        localDW->is_Study = APP_FluxWeak_GEAR2_IN_SPEEDINV;

        /* Entry 'SPEEDINV': '<S87>:98' */
        /* 速度反向 */
        APP_Flu_enter_internal_SPEEDINV(rtu_Data_n, localDW);
      } else {
        /* Transition: '<S87>:109' */
        localDW->is_Study = APP_FluxWeak_GEAR2_IN_SPEEDFORW;

        /* Entry 'SPEEDFORW': '<S87>:97' */
        /* 速度正向 */
        APP_Fl_enter_internal_SPEEDFORW(rtu_Data_n, localDW);
      }
    }
    break;

   default:
    /* During 'ZeroPoint1': '<S87>:138' */
    switch (localDW->is_ZeroPoint1) {
     case APP_FluxWeak_GEAR2_IN_AddId_c:
      /* During 'AddId': '<S87>:151' */
      /* '<S87>:142:1' sf_internal_predicateOutput = ... */
      /* '<S87>:142:1' IdRefSet > 0.3; */
      if (localDW->IdRefSet > 0.3) {
        /* Transition: '<S87>:142' */
        localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_Wait1_b;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'Wait1': '<S87>:152' */
        /* 等 */
        /* '<S87>:152:1' IdRefSet = 0.3; */
        localDW->IdRefSet = 0.3F;

        /* '<S87>:152:1' StudyStep=31; */
        localDW->StudyStep = 31U;
      } else {
        /* '<S87>:151:1' IdRefSet = IdRefSet + 0.001; */
        localDW->IdRefSet += 0.001F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_AddIq:
      localDW->AngleSetEn = 0U;

      /* Chart: '<S80>/Chart' */
      /* During 'AddIq': '<S87>:154' */
      /* '<S87>:145:1' sf_internal_predicateOutput = ... */
      /* '<S87>:145:1' UsFil > 0.4 || IqRefSet > 0.3; */
      if ((rtu_Data_j > 0.4) || (localDW->IqRefSet > 0.3)) {
        /* Transition: '<S87>:145' */
        /* '<S87>:148:1' sf_internal_predicateOutput = ... */
        /* '<S87>:148:1' UsFil > 0.4; */
        if (rtu_Data_j > 0.4) {
          /* Transition: '<S87>:148' */
          localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_ClrIq;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'ClrIq': '<S87>:156' */
          /* 清除iq */
          /* '<S87>:156:1' IqRefSet = 0; */
          localDW->IqRefSet = 0.0F;
        } else {
          /* Transition: '<S87>:147' */
          localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_Wait2;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'Wait2': '<S87>:157' */
          /* 增加iq */
          /* '<S87>:157:1' IqRefSet = 0.3; */
          localDW->IqRefSet = 0.3F;
        }
      } else {
        /* '<S87>:154:3' IqRefSet = IqRefSet + 0.001; */
        localDW->IqRefSet += 0.001F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_ClrIq:
      /* During 'ClrIq': '<S87>:156' */
      /* '<S87>:105:1' sf_internal_predicateOutput = ... */
      /* '<S87>:105:1' after(100,tick); */
      if (localDW->temporalCounter_i1 >= 100U) {
        /* Transition: '<S87>:105' */
        /* '<S87>:107:1' sf_internal_predicateOutput = ... */
        /* '<S87>:107:1' PMSM_Param.ResolverDirChg == 1; */
        if (PMSM_Param.ResolverDirChg == 1U) {
          /* Transition: '<S87>:107' */
          localDW->is_ZeroPoint1 = APP_FluxWe_IN_NO_ACTIVE_CHILD_o;
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_SPEEDINV;

          /* Chart: '<S80>/Chart' */
          /* Entry 'SPEEDINV': '<S87>:98' */
          /* 速度反向 */
          APP_Flu_enter_internal_SPEEDINV(rtu_Data_n, localDW);
        } else {
          /* Transition: '<S87>:109' */
          localDW->is_ZeroPoint1 = APP_FluxWe_IN_NO_ACTIVE_CHILD_o;
          localDW->is_Study = APP_FluxWeak_GEAR2_IN_SPEEDFORW;

          /* Chart: '<S80>/Chart' */
          /* Entry 'SPEEDFORW': '<S87>:97' */
          /* 速度正向 */
          APP_Fl_enter_internal_SPEEDFORW(rtu_Data_n, localDW);
        }
      }
      break;

     case APP_FluxWeak_GEAR2_IN_DecId_l:
      /* During 'DecId': '<S87>:153' */
      /* '<S87>:144:1' sf_internal_predicateOutput = ... */
      /* '<S87>:144:1' IdRefSet < 0.002; */
      if (localDW->IdRefSet < 0.002) {
        /* Transition: '<S87>:144' */
        localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_AddIq;

        /* Entry 'AddIq': '<S87>:154' */
        /* 增加iq */
        /* '<S87>:154:1' IdRefSet = 0; */
        localDW->IdRefSet = 0.0F;

        /* '<S87>:154:1' AngleSetEn = 0; */
        localDW->AngleSetEn = 0U;

        /* '<S87>:154:1' StudyStep=33; */
        localDW->StudyStep = 33U;
      } else {
        /* '<S87>:153:3' IdRefSet = IdRefSet - 0.001; */
        localDW->IdRefSet -= 0.001F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_Fault_i:
      /* During 'Fault': '<S87>:155' */
      /* '<S87>:155:1' IqRefSet = 0; */
      localDW->IqRefSet = 0.0F;

      /* '<S87>:155:1' StudyResult = 5555; */
      localDW->StudyResult = 5555.0F;

      /* '<S87>:155:1' StudyStep=36; */
      localDW->StudyStep = 36U;
      break;

     case APP_FluxWeak_GEAR2_IN_Init_du:
      localDW->IdIqSetEn = 1U;
      localDW->AngleSetEn = 1U;

      /* During 'Init': '<S87>:150' */
      /* Transition: '<S87>:141' */
      localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_AddId_c;

      /* Entry 'AddId': '<S87>:151' */
      /* 增加id */
      /* '<S87>:151:1' IdRefSet = IdRefSet + 0.001; */
      localDW->IdRefSet += 0.001F;
      break;

     case APP_FluxWeak_GEAR2_IN_Wait1_b:
      /* During 'Wait1': '<S87>:152' */
      /* '<S87>:143:1' sf_internal_predicateOutput = ... */
      /* '<S87>:143:1' after(100,tick); */
      if (localDW->temporalCounter_i1 >= 100U) {
        /* Transition: '<S87>:143' */
        localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_DecId_l;

        /* Chart: '<S80>/Chart' */
        /* Entry 'DecId': '<S87>:153' */
        /* 减id */
        /* '<S87>:153:1' CalibZeroPoint =single( ThetaRT); */
        localDW->CalibZeroPoint = rtu_Data_o;
      } else {
        /* '<S87>:152:1' IdRefSet = 0.3; */
        localDW->IdRefSet = 0.3F;

        /* '<S87>:152:1' StudyStep=31; */
        localDW->StudyStep = 31U;
      }
      break;

     default:
      /* During 'Wait2': '<S87>:157' */
      /* '<S87>:149:1' sf_internal_predicateOutput = ... */
      /* '<S87>:149:1' after(3000,tick); */
      if (localDW->temporalCounter_i1 >= 3000U) {
        /* Transition: '<S87>:149' */
        localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_Fault_i;

        /* Entry 'Fault': '<S87>:155' */
        /* '<S87>:155:1' IqRefSet = 0; */
        localDW->IqRefSet = 0.0F;

        /* '<S87>:155:1' StudyResult = 5555; */
        localDW->StudyResult = 5555.0F;

        /* '<S87>:155:3' StudyStep=36; */
        localDW->StudyStep = 36U;
      } else {
        /* Chart: '<S80>/Chart' */
        /* '<S87>:146:1' sf_internal_predicateOutput = ... */
        /* '<S87>:146:1' UsFil > 0.4; */
        if (rtu_Data_j > 0.4) {
          /* Transition: '<S87>:146' */
          localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_ClrIq;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'ClrIq': '<S87>:156' */
          /* 清除iq */
          /* '<S87>:156:1' IqRefSet = 0; */
          localDW->IqRefSet = 0.0F;
        } else {
          /* '<S87>:157:1' IqRefSet = 0.3; */
          localDW->IqRefSet = 0.3F;
        }
      }
      break;
    }
    break;
  }
}

/* System initialize for function-call system: '<S64>/ElecZeroStudy' */
void APP_FluxWeak_ElecZeroStudy_Init(DW_ElecZeroStudy_APP_FluxWeak_T *localDW)
{
  /* SystemInitialize for Chart: '<S80>/Chart' */
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

/* Output and update for function-call system: '<S64>/ElecZeroStudy' */
void APP_FluxWeak_GEAR_ElecZeroStudy(uint16_T rtu_Data, real32_T rtu_Data_b,
  real32_T rtu_Data_n, real32_T rtu_Data_j, real32_T rtu_Data_o, uint16_T
  *rty_Out1, real32_T *rty_Out1_b, real32_T *rty_Out1_n, real32_T *rty_Out1_j,
  uint16_T *rty_Out1_o, uint16_T *rty_Out1_j3, real32_T *rty_Out1_k, real32_T
  *rty_Out1_e, DW_ElecZeroStudy_APP_FluxWeak_T *localDW)
{
  /* Chart: '<S80>/Chart' */
  /* Gateway: implement/method/All_loop/Calib/ElecZeroStudy/Chart */
  if (localDW->temporalCounter_i1 < 4095U) {
    localDW->temporalCounter_i1++;
  }

  /* During: implement/method/All_loop/Calib/ElecZeroStudy/Chart */
  if (localDW->is_active_c11_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/Calib/ElecZeroStudy/Chart */
    localDW->is_active_c11_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/Calib/ElecZeroStudy/Chart */
    /* Transition: '<S87>:85' */
    localDW->is_c11_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Init_d;

    /* Entry 'Init': '<S87>:84' */
    /* 初始化 */
    /* '<S87>:84:1' CalibZeroPoint = 0; */
    localDW->CalibZeroPoint = 0.0F;

    /* '<S87>:84:1' StudyResult = 8888; */
    localDW->StudyResult = 8888.0F;

    /* '<S87>:84:3' ZeroStudyCnt = 0; */
    localDW->ZeroStudyCnt = 0U;

    /* '<S87>:84:4' IdIqSetEn = 0; */
    localDW->IdIqSetEn = 0U;

    /* '<S87>:84:5' AngleSetEn = 0; */
    localDW->AngleSetEn = 0U;

    /* '<S87>:84:5' IdRefSet = 0; */
    localDW->IdRefSet = 0.0F;

    /* '<S87>:84:6' IqRefSet = 0; */
    localDW->IqRefSet = 0.0F;

    /* '<S87>:84:7' AngleRefSet = 0; */
    localDW->AngleRefSet = 0.0F;

    /* '<S87>:84:8' StudyStep=20; */
    localDW->StudyStep = 20U;
  } else if (localDW->is_c11_APP_FluxWeak_GEAR2 == 1U) {
    localDW->IdIqSetEn = 0U;
    localDW->AngleSetEn = 0U;
    localDW->AngleRefSet = 0.0F;

    /* During 'Init': '<S87>:84' */
    /* '<S87>:86:1' sf_internal_predicateOutput = ... */
    /* '<S87>:86:1' TqReq > 0.001; */
    if (rtu_Data_b > 0.001) {
      /* Transition: '<S87>:86' */
      localDW->is_c11_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Study_e;

      /* Entry 'Study': '<S87>:83' */
      /* 学习 */
      /* Entry Internal 'Study': '<S87>:83' */
      /* Transition: '<S87>:87' */
      /* '<S87>:90:1' sf_internal_predicateOutput = ... */
      /* '<S87>:90:1' ElecZeroStep ==0; */
      if (rtu_Data == 0U) {
        /* Transition: '<S87>:90' */
        localDW->is_Study = APP_FluxWeak_GEAR_IN_ZeroPoint0;

        /* Entry 'ZeroPoint0': '<S87>:89' */
        /* 被拖 */
        /* '<S87>:89:1' IdIqSetEn = 1; */
        localDW->IdIqSetEn = 1U;
      } else {
        /* Transition: '<S87>:160' */
        localDW->is_Study = APP_FluxWeak_GEAR_IN_ZeroPoint1;

        /* Entry 'ZeroPoint1': '<S87>:138' */
        /* 被拖学习零点 */
        /* Entry Internal 'ZeroPoint1': '<S87>:138' */
        /* Transition: '<S87>:140' */
        localDW->is_ZeroPoint1 = APP_FluxWeak_GEAR2_IN_Init_du;

        /* Entry 'Init': '<S87>:150' */
        /* 初始化 */
        /* '<S87>:150:1' IdIqSetEn = 1; */
        localDW->IdIqSetEn = 1U;

        /* '<S87>:150:1' AngleSetEn = 1; */
        localDW->AngleSetEn = 1U;

        /* '<S87>:150:1' StudyStep=32; */
        localDW->StudyStep = 32U;
      }
    }
  } else {
    APP_FluxWeak_GEAR2_Study(rtu_Data_n, rtu_Data_j, rtu_Data_o, localDW);
  }

  /* End of Chart: '<S80>/Chart' */

  /* DataStoreWrite: '<S80>/Data Store Write' */
  AppFun.StudyResult = localDW->StudyResult;

  /* DataStoreWrite: '<S80>/Data Store Write1' */
  AppFun.StudyStep = localDW->StudyStep;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_b = localDW->IdRefSet;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_n = localDW->IqRefSet;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_j = localDW->AngleRefSet;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_o = localDW->IdIqSetEn;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_j3 = localDW->AngleSetEn;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_k = localDW->CalibZeroPoint;

  /* SignalConversion: '<S80>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_e = 0.0F;
}

/* System initialize for function-call system: '<S64>/IdqStudy' */
void APP_FluxWeak_GEAR_IdqStudy_Init(DW_IdqStudy_APP_FluxWeak_GEAR_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_g = 0.0F;
}

/* System reset for function-call system: '<S64>/IdqStudy' */
void APP_FluxWeak_GEA_IdqStudy_Reset(DW_IdqStudy_APP_FluxWeak_GEAR_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE_g = 0.0F;
}

/* Output and update for function-call system: '<S64>/IdqStudy' */
void APP_FluxWeak_GEAR2_IdqStudy(real32_T rtu_Data, real32_T rtu_Data_p,
  uint16_T *rty_Out1, real32_T *rty_Out1_p, real32_T *rty_Out1_f, real32_T
  *rty_Out1_g, uint16_T *rty_Out1_o, uint16_T *rty_Out1_i, real32_T *rty_Out1_n,
  real32_T *rty_Out1_d, DW_IdqStudy_APP_FluxWeak_GEAR_T *localDW)
{
  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  *rty_Out1_p = localDW->DiscreteTimeIntegrator_DSTATE;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
   *  DiscreteIntegrator: '<S98>/Discrete-Time Integrator'
   */
  *rty_Out1_f = localDW->DiscreteTimeIntegrator_DSTATE_g;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_g = 0.0F;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_o = 1U;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = 0U;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_n = 0.0F;

  /* SignalConversion: '<S83>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_d = 0.0F;

  /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S97>/Gain'
   *  Sum: '<S97>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE += (rtu_Data -
    localDW->DiscreteTimeIntegrator_DSTATE) * 10.0F * 0.002F;

  /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S98>/Gain'
   *  Sum: '<S98>/Sum'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_g += (rtu_Data_p -
    localDW->DiscreteTimeIntegrator_DSTATE_g) * 10.0F * 0.002F;
}

/* System initialize for function-call system: '<S64>/FluxLinkage' */
void APP_FluxWeak_G_FluxLinkage_Init(DW_FluxLinkage_APP_FluxWeak_G_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S89>/Delay Input2'
   *
   * Block description for '<S89>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S90>/Delay Input2'
   *
   * Block description for '<S90>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE_g = 0.0F;

  /* SystemInitialize for Chart: '<S81>/Chart' */
  localDW->is_AngCount = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->is_Stop = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->is_work = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c9_APP_FluxWeak_GEAR2 = 0U;
  localDW->CalibAng = 0.0F;
  localDW->IsReq = 0.0F;
}

/* System reset for function-call system: '<S64>/FluxLinkage' */
void APP_FluxWeak__FluxLinkage_Reset(DW_FluxLinkage_APP_FluxWeak_G_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S89>/Delay Input2'
   *
   * Block description for '<S89>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S90>/Delay Input2'
   *
   * Block description for '<S90>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE_g = 0.0F;

  /* SystemReset for Chart: '<S81>/Chart' */
  localDW->is_AngCount = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->is_Stop = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->is_work = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c9_APP_FluxWeak_GEAR2 = 0U;
  localDW->CalibAng = 0.0F;
  localDW->IsReq = 0.0F;
}

/* Output and update for function-call system: '<S64>/FluxLinkage' */
void APP_FluxWeak_GEAR2_FluxLinkage(real32_T rtu_Data, uint16_T *rty_Out1,
  real32_T *rty_Out1_n, real32_T *rty_Out1_i, real32_T *rty_Out1_a, uint16_T
  *rty_Out1_h, uint16_T *rty_Out1_k, real32_T *rty_Out1_c, real32_T *rty_Out1_im,
  DW_FluxLinkage_APP_FluxWeak_G_T *localDW)
{
  real32_T rtb_IdRefSet;
  real32_T rtb_IqRefSet;

  /* Chart: '<S81>/Chart' */
  /* Gateway: implement/method/All_loop/Calib/FluxLinkage/Chart */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  /* During: implement/method/All_loop/Calib/FluxLinkage/Chart */
  if (localDW->is_active_c9_APP_FluxWeak_GEAR2 == 0U) {
    /* Entry: implement/method/All_loop/Calib/FluxLinkage/Chart */
    localDW->is_active_c9_APP_FluxWeak_GEAR2 = 1U;

    /* Entry Internal: implement/method/All_loop/Calib/FluxLinkage/Chart */
    /* Entry Internal 'AngCount': '<S88>:4' */
    /* Transition: '<S88>:9' */
    localDW->is_AngCount = APP_FluxWeak_GEAR2_IN_wait;

    /* Entry 'wait': '<S88>:12' */
    /* '<S88>:12:1' CalibAng=0; */
    localDW->CalibAng = 0.0F;

    /* '<S88>:12:1' IsReq=0; */
    localDW->IsReq = 0.0F;

    /* Entry 'Idq': '<S88>:19' */
    /* '<S88>:19:1' IqRefSet = IsReq * cos(CalibAng); */
    rtb_IqRefSet = localDW->IsReq * cosf(localDW->CalibAng);

    /* '<S88>:19:3' IdRefSet = -abs(IsReq * sin(CalibAng)); */
    rtb_IdRefSet = -fabsf(localDW->IsReq * sinf(localDW->CalibAng));
  } else {
    /* During 'AngCount': '<S88>:4' */
    switch (localDW->is_AngCount) {
     case APP_FluxWeak_GEAR2_IN_Stop_l:
      /* During 'Stop': '<S88>:43' */
      /* '<S88>:43:1' IsReq=0; */
      localDW->IsReq = 0.0F;

      /* '<S88>:43:1' CalibAng=0; */
      localDW->CalibAng = 0.0F;
      if (localDW->is_Stop == 1U) {
        /* During 'stop': '<S88>:46' */
        /* '<S88>:50:1' sf_internal_predicateOutput = ... */
        /* '<S88>:50:1' TqReq==0; */
        if (rtu_Data == 0.0F) {
          /* Transition: '<S88>:50' */
          localDW->is_Stop = APP_FluxWeak_GEAR2_IN_wait;
        }
      } else {
        /* During 'wait': '<S88>:49' */
        /* Transition: '<S88>:54' */
        /* '<S88>:55:1' sf_internal_predicateOutput = ... */
        /* '<S88>:55:1' TqReq>0.01; */
        if (rtu_Data > 0.01) {
          /* Transition: '<S88>:55' */
          localDW->is_Stop = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
          localDW->is_AngCount = APP_FluxWeak_GEAR2_IN_wait;

          /* Entry 'wait': '<S88>:12' */
          /* '<S88>:12:1' CalibAng=0; */
          localDW->CalibAng = 0.0F;

          /* '<S88>:12:1' IsReq=0; */
          localDW->IsReq = 0.0F;
        }
      }
      break;

     case APP_FluxWeak_GEAR2_IN_wait:
      /* During 'wait': '<S88>:12' */
      /* '<S88>:13:1' sf_internal_predicateOutput = ... */
      /* '<S88>:13:1' TqReq>0.01; */
      if (rtu_Data > 0.01) {
        /* Transition: '<S88>:13' */
        /* '<S88>:13:1' CalibAng=PMSM_Param.FLStartAng/180*pi; */
        localDW->CalibAng = PMSM_Param.FLStartAng / 180.0F * 3.14159274F;

        /* '<S88>:13:2' IsReq=0; */
        localDW->IsReq = 0.0F;
        localDW->is_AngCount = APP_FluxWeak_GEAR2_IN_work;
        localDW->is_work = APP_FluxWeak_G_IN_increaseValue;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'increaseValue': '<S88>:8' */
        /* 加 */
      } else {
        /* '<S88>:12:1' CalibAng=0; */
        localDW->CalibAng = 0.0F;

        /* '<S88>:12:1' IsReq=0; */
        localDW->IsReq = 0.0F;
      }
      break;

     default:
      /* During 'work': '<S88>:56' */
      /* '<S88>:58:1' sf_internal_predicateOutput = ... */
      /* '<S88>:58:1' TqReq==0; */
      if (rtu_Data == 0.0F) {
        /* Transition: '<S88>:58' */
        /* Transition: '<S88>:59' */
        /* Exit Internal 'work': '<S88>:56' */
        localDW->is_work = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
        localDW->is_AngCount = APP_FluxWeak_GEAR2_IN_Stop_l;

        /* Entry 'Stop': '<S88>:43' */
        /* '<S88>:43:1' IsReq=0; */
        localDW->IsReq = 0.0F;

        /* '<S88>:43:1' CalibAng=0; */
        localDW->CalibAng = 0.0F;

        /* Entry Internal 'Stop': '<S88>:43' */
        /* Transition: '<S88>:52' */
        localDW->is_Stop = APP_FluxWeak_GEAR2_IN_stop;
      } else if (localDW->is_work == 1U) {
        /* During 'DecreaseValue': '<S88>:20' */
        /* '<S88>:28:1' sf_internal_predicateOutput = ... */
        /* '<S88>:28:1' after(700,tick); */
        if (localDW->temporalCounter_i1 >= 700U) {
          /* Transition: '<S88>:28' */
          /* '<S88>:30:1' sf_internal_predicateOutput = ... */
          /* '<S88>:30:1' IsReq<=0; */
          if (localDW->IsReq <= 0.0F) {
            /* Transition: '<S88>:30' */
            /* Transition: '<S88>:37' */
            /* Transition: '<S88>:44' */
            localDW->is_work = APP_FluxWe_IN_NO_ACTIVE_CHILD_l;
            localDW->is_AngCount = APP_FluxWeak_GEAR2_IN_Stop_l;

            /* Entry 'Stop': '<S88>:43' */
            /* '<S88>:43:1' IsReq=0; */
            localDW->IsReq = 0.0F;

            /* '<S88>:43:1' CalibAng=0; */
            localDW->CalibAng = 0.0F;

            /* Entry Internal 'Stop': '<S88>:43' */
            /* Transition: '<S88>:52' */
            localDW->is_Stop = APP_FluxWeak_GEAR2_IN_stop;
          } else {
            /* Transition: '<S88>:32' */
            /* Transition: '<S88>:34' */
            /* '<S88>:34:1' IsReq=IsReq-0.05; */
            localDW->IsReq -= 0.05F;

            /* Transition: '<S88>:35' */
            localDW->is_work = APP_FluxWeak_G_IN_DecreaseValue;
            localDW->temporalCounter_i1 = 0U;

            /* Entry 'DecreaseValue': '<S88>:20' */
            /* 减 */
          }
        }
      } else {
        /* During 'increaseValue': '<S88>:8' */
        /* '<S88>:18:1' sf_internal_predicateOutput = ... */
        /* '<S88>:18:1' after(700,tick); */
        if (localDW->temporalCounter_i1 >= 700U) {
          /* Transition: '<S88>:18' */
          /* '<S88>:21:1' sf_internal_predicateOutput = ... */
          /* '<S88>:21:1' IsReq>=1; */
          if (localDW->IsReq >= 1.0F) {
            /* Transition: '<S88>:21' */
            localDW->is_work = APP_FluxWeak_G_IN_DecreaseValue;
            localDW->temporalCounter_i1 = 0U;

            /* Entry 'DecreaseValue': '<S88>:20' */
            /* 减 */
          } else {
            /* Transition: '<S88>:23' */
            /* Transition: '<S88>:25' */
            /* '<S88>:25:1' IsReq=IsReq+0.05; */
            localDW->IsReq += 0.05F;

            /* Transition: '<S88>:26' */
            localDW->is_work = APP_FluxWeak_G_IN_increaseValue;
            localDW->temporalCounter_i1 = 0U;

            /* Entry 'increaseValue': '<S88>:8' */
            /* 加 */
          }
        }
      }
      break;
    }

    /* During 'Idq': '<S88>:19' */
    /* '<S88>:19:1' IqRefSet = IsReq * cos(CalibAng); */
    rtb_IqRefSet = localDW->IsReq * cosf(localDW->CalibAng);

    /* '<S88>:19:1' IdRefSet = -abs(IsReq * sin(CalibAng)); */
    rtb_IdRefSet = -fabsf(localDW->IsReq * sinf(localDW->CalibAng));
  }

  /* End of Chart: '<S81>/Chart' */

  /* Gain: '<S81>/Gain1' incorporates:
   *  DataStoreWrite: '<S81>/Data Store Write'
   */
  AppFun.StudyResult = 100.0F * localDW->IsReq;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1 = 0U;

  /* Sum: '<S89>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S89>/Delay Input2'
   *
   * Block description for '<S89>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S89>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_IdRefSet -= localDW->DelayInput2_DSTATE;

  /* Switch: '<S91>/Switch2' incorporates:
   *  RelationalOperator: '<S91>/LowerRelop1'
   *  RelationalOperator: '<S91>/UpperRelop'
   *  Switch: '<S91>/Switch'
   */
  if (rtb_IdRefSet > 0.002F) {
    rtb_IdRefSet = 0.002F;
  } else {
    if (rtb_IdRefSet < -0.002F) {
      /* Switch: '<S91>/Switch' */
      rtb_IdRefSet = -0.002F;
    }
  }

  /* End of Switch: '<S91>/Switch2' */

  /* Sum: '<S89>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S89>/Delay Input2'
   *
   * Block description for '<S89>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S89>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE += rtb_IdRefSet;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_n = localDW->DelayInput2_DSTATE;

  /* Sum: '<S90>/Difference Inputs1' incorporates:
   *  UnitDelay: '<S90>/Delay Input2'
   *
   * Block description for '<S90>/Difference Inputs1':
   *
   *  Add in CPU
   *
   * Block description for '<S90>/Delay Input2':
   *
   *  Store in Global RAM
   */
  rtb_IqRefSet -= localDW->DelayInput2_DSTATE_g;

  /* Switch: '<S92>/Switch2' incorporates:
   *  RelationalOperator: '<S92>/LowerRelop1'
   *  RelationalOperator: '<S92>/UpperRelop'
   *  Switch: '<S92>/Switch'
   */
  if (rtb_IqRefSet > 0.002F) {
    rtb_IqRefSet = 0.002F;
  } else {
    if (rtb_IqRefSet < -0.002F) {
      /* Switch: '<S92>/Switch' */
      rtb_IqRefSet = -0.002F;
    }
  }

  /* End of Switch: '<S92>/Switch2' */

  /* Sum: '<S90>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S90>/Delay Input2'
   *
   * Block description for '<S90>/Difference Inputs2':
   *
   *  Add in CPU
   *
   * Block description for '<S90>/Delay Input2':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput2_DSTATE_g += rtb_IqRefSet;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_i = localDW->DelayInput2_DSTATE_g;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_a = 0.0F;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_h = 1U;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_k = 0U;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_c = 0.0F;

  /* SignalConversion: '<S81>/BusConversion_InsertedFor_Out1_at_inport_0' */
  *rty_Out1_im = 0.0F;
}

/* System initialize for function-call system: '<S64>/MtpaStudy' */
void APP_FluxWeak_GEA_MtpaStudy_Init(DW_MtpaStudy_APP_FluxWeak_GEA_T *localDW)
{
  /* SystemInitialize for Chart: '<S84>/Chart' */
  localDW->is_Mtpa = APP_FluxWe_IN_NO_ACTIVE_CHILD_i;
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c26_APP_FluxWeak_GEAR = 0U;
  localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWe_IN_NO_ACTIVE_CHILD_i;
  localDW->count = 0U;
  localDW->IsRef = 0.0F;
  localDW->AngRef = 0.0F;
}

/* Output and update for function-call system: '<S64>/MtpaStudy' */
void APP_FluxWeak_GEAR2_MtpaStudy(real32_T rtu_Data, real32_T rtu_Data_c,
  real32_T rtu_Data_p, uint16_T *rty_Out1, real32_T *rty_Out1_c, real32_T
  *rty_Out1_p, real32_T *rty_Out1_l, uint16_T *rty_Out1_m, uint16_T *rty_Out1_f,
  real32_T *rty_Out1_h, real32_T *rty_Out1_cv, DW_MtpaStudy_APP_FluxWeak_GEA_T
  *localDW)
{
  uint16_T qY;
  boolean_T guard1 = false;

  /* Chart: '<S84>/Chart' */
  /* Gateway: implement/method/All_loop/Calib/MtpaStudy/Chart */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  /* During: implement/method/All_loop/Calib/MtpaStudy/Chart */
  if (localDW->is_active_c26_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/Calib/MtpaStudy/Chart */
    localDW->is_active_c26_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/Calib/MtpaStudy/Chart */
    /* Transition: '<S99>:5' */
    localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Prepare;

    /* Entry 'Prepare': '<S99>:12' */
    /* '<S99>:12:1' IsRef=0; */
    localDW->IsRef = 0.0F;
  } else {
    guard1 = false;
    switch (localDW->is_c26_APP_FluxWeak_GEAR2) {
     case APP_FluxWeak_GEAR_IN_IsDecrease:
      /* During 'IsDecrease': '<S99>:46' */
      /* Transition: '<S99>:51' */
      /* '<S99>:52:1' sf_internal_predicateOutput = ... */
      /* '<S99>:52:1' IsRef<0.001; */
      if (localDW->IsRef < 0.001) {
        /* Transition: '<S99>:52' */
        localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Prepare;

        /* Entry 'Prepare': '<S99>:12' */
        /* '<S99>:12:1' IsRef=0; */
        localDW->IsRef = 0.0F;
      } else {
        /* Transition: '<S99>:54' */
        /* Transition: '<S99>:55' */
        localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR_IN_IsDecrease;

        /* Entry 'IsDecrease': '<S99>:46' */
        /* '<S99>:46:1' IsRef=IsRef-0.001; */
        localDW->IsRef -= 0.001F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_Mtpa:
      /* During 'Mtpa': '<S99>:4' */
      /* '<S99>:15:1' sf_internal_predicateOutput = ... */
      /* '<S99>:15:1' CalibTq2<0.01; */
      if (rtu_Data < 0.01) {
        /* Transition: '<S99>:15' */
        /* Exit Internal 'Mtpa': '<S99>:4' */
        localDW->is_Mtpa = APP_FluxWe_IN_NO_ACTIVE_CHILD_i;
        localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR_IN_IsDecrease;

        /* Entry 'IsDecrease': '<S99>:46' */
        /* '<S99>:46:1' IsRef=IsRef-0.001; */
        localDW->IsRef -= 0.001F;
      } else {
        switch (localDW->is_Mtpa) {
         case APP_FluxWeak_G_IN_AngleIncrease:
          /* During 'AngleIncrease': '<S99>:31' */
          /* Transition: '<S99>:64' */
          /* '<S99>:61:1' sf_internal_predicateOutput = ... */
          /* '<S99>:61:1' count<15; */
          if (localDW->count < 15U) {
            /* Transition: '<S99>:61' */
            guard1 = true;
          } else {
            /* Transition: '<S99>:67' */
            /* '<S99>:41:1' sf_internal_predicateOutput = ... */
            /* '<S99>:41:1' AngRef>=pi/2; */
            if (localDW->AngRef >= 1.5707963267948966) {
              /* Transition: '<S99>:41' */
              localDW->is_Mtpa = APP_FluxWeak_GEAR2_IN_Qaxis;
            } else {
              /* '<S99>:43:1' sf_internal_predicateOutput = ... */
              /* '<S99>:43:1' after(1000,tick); */
              if (localDW->temporalCounter_i1 >= 1000U) {
                /* Transition: '<S99>:43' */
                /* Transition: '<S99>:49' */
                /* '<S99>:49:1' count=0; */
                localDW->count = 0U;
                guard1 = true;
              }
            }
          }
          break;

         case APP_FluxWeak_GEAR_IN_FirstPoint:
          /* During 'FirstPoint': '<S99>:68' */
          /* '<S99>:69:1' sf_internal_predicateOutput = ... */
          /* '<S99>:69:1' after(1000,tick); */
          if (localDW->temporalCounter_i1 >= 1000U) {
            /* Transition: '<S99>:69' */
            localDW->is_Mtpa = APP_FluxWeak_G_IN_AngleIncrease;
            localDW->temporalCounter_i1 = 0U;

            /* Entry 'AngleIncrease': '<S99>:31' */
            /* 加角度 */
            /* '<S99>:31:1' AngRef=AngRef+0.1/180*pi; */
            localDW->AngRef += 0.00174532924F;

            /* '<S99>:31:1' count=count+1; */
            qY = localDW->count + /*MW:OvSatOk*/ 1U;
            if (qY < localDW->count) {
              qY = MAX_uint16_T;
            }

            localDW->count = qY;
          }
          break;

         case APP_FluxWeak_GEAR_IN_IsIncrease:
          /* During 'IsIncrease': '<S99>:17' */
          /* Transition: '<S99>:30' */
          /* '<S99>:32:1' sf_internal_predicateOutput = ... */
          /* '<S99>:32:1' IsRef>=TqReq; */
          if (localDW->IsRef >= rtu_Data_c) {
            /* Transition: '<S99>:32' */
            localDW->is_Mtpa = APP_FluxWeak_GEAR_IN_FirstPoint;
            localDW->temporalCounter_i1 = 0U;
          } else {
            /* Transition: '<S99>:34' */
            /* Transition: '<S99>:36' */
            /* Transition: '<S99>:37' */
            localDW->is_Mtpa = APP_FluxWeak_GEAR_IN_IsIncrease;

            /* Entry 'IsIncrease': '<S99>:17' */
            /* 加Is */
            /* '<S99>:17:1' IsRef=IsRef+0.001; */
            localDW->IsRef += 0.001F;
          }
          break;

         default:
          /* During 'Qaxis': '<S99>:23' */
          /* Transition: '<S99>:56' */
          localDW->is_Mtpa = APP_FluxWe_IN_NO_ACTIVE_CHILD_i;
          localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR_IN_IsDecrease;

          /* Entry 'IsDecrease': '<S99>:46' */
          /* '<S99>:46:1' IsRef=IsRef-0.001; */
          localDW->IsRef -= 0.001F;
          break;
        }
      }
      break;

     default:
      /* During 'Prepare': '<S99>:12' */
      /* '<S99>:13:1' sf_internal_predicateOutput = ... */
      /* '<S99>:13:1' CalibTq2>0.01; */
      if (rtu_Data > 0.01) {
        /* Transition: '<S99>:13' */
        /* '<S99>:13:1' AngRef=CalibMTPATheta; */
        localDW->AngRef = rtu_Data_p;

        /* '<S99>:13:1' count=0; */
        localDW->count = 0U;
        localDW->is_c26_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_Mtpa;

        /* Entry Internal 'Mtpa': '<S99>:4' */
        /* Transition: '<S99>:18' */
        localDW->is_Mtpa = APP_FluxWeak_GEAR_IN_IsIncrease;

        /* Entry 'IsIncrease': '<S99>:17' */
        /* 加Is */
        /* '<S99>:17:1' IsRef=IsRef+0.001; */
        localDW->IsRef += 0.001F;
      } else {
        /* '<S99>:12:1' IsRef=0; */
        localDW->IsRef = 0.0F;
      }
      break;
    }

    if (guard1) {
      /* Transition: '<S99>:66' */
      /* Transition: '<S99>:47' */
      localDW->is_Mtpa = APP_FluxWeak_G_IN_AngleIncrease;
      localDW->temporalCounter_i1 = 0U;

      /* Entry 'AngleIncrease': '<S99>:31' */
      /* 加角度 */
      /* '<S99>:31:1' AngRef=AngRef+0.1/180*pi; */
      localDW->AngRef += 0.00174532924F;

      /* '<S99>:31:1' count=count+1; */
      qY = localDW->count + /*MW:OvSatOk*/ 1U;
      if (qY < localDW->count) {
        qY = MAX_uint16_T;
      }

      localDW->count = qY;
    }
  }

  /* End of Chart: '<S84>/Chart' */

  /* Gain: '<S84>/Gain1' incorporates:
   *  DataStoreWrite: '<S84>/Data Store Write'
   */
  AppFun.StudyResult = 57.2957802F * localDW->AngRef;

  /* Gain: '<S84>/Gain' incorporates:
   *  Product: '<S84>/Product'
   *  Trigonometry: '<S84>/Trigonometric Function'
   */
  *rty_Out1_c = -(localDW->IsRef * sinf(localDW->AngRef));

  /* Product: '<S84>/Product1' incorporates:
   *  Trigonometry: '<S84>/Trigonometric Function1'
   */
  *rty_Out1_p = localDW->IsRef * cosf(localDW->AngRef);

  /* SignalConversion: '<S84>/TmpBufferAtConstant2Outport1' incorporates:
   *  Constant: '<S84>/Constant2'
   */
  *rty_Out1_l = 0.0F;

  /* SignalConversion: '<S84>/TmpBufferAtConstant3Outport1' incorporates:
   *  Constant: '<S84>/Constant3'
   */
  *rty_Out1_m = 1U;

  /* SignalConversion: '<S84>/TmpBufferAtConstant4Outport1' incorporates:
   *  Constant: '<S84>/Constant4'
   */
  *rty_Out1_f = 0U;

  /* SignalConversion: '<S84>/TmpBufferAtConstant5Outport1' incorporates:
   *  Constant: '<S84>/Constant5'
   */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S84>/TmpBufferAtConstant7Outport1' incorporates:
   *  Constant: '<S84>/Constant7'
   */
  *rty_Out1_h = 0.0F;

  /* SignalConversion: '<S84>/TmpBufferAtConstant8Outport1' incorporates:
   *  Constant: '<S84>/Constant8'
   */
  *rty_Out1_cv = 0.0F;
}

/* Output and update for function-call system: '<S64>/Tlin' */
void APP_FluxWeak_GEAR2_Tlin(real32_T rtu_Data, uint16_T *rty_Out1, real32_T
  *rty_Out1_o, real32_T *rty_Out1_k, real32_T *rty_Out1_oy, uint16_T *rty_Out1_p,
  uint16_T *rty_Out1_d, real32_T *rty_Out1_km, real32_T *rty_Out1_i)
{
  /* SignalConversion: '<S86>/TmpLatchAtDataOutport1' */
  *rty_Out1_i = rtu_Data;

  /* SignalConversion: '<S86>/TmpBufferAtConstant1Outport1' incorporates:
   *  Constant: '<S86>/Constant1'
   */
  *rty_Out1_k = 0.0F;

  /* SignalConversion: '<S86>/TmpBufferAtConstant2Outport1' incorporates:
   *  Constant: '<S86>/Constant2'
   */
  *rty_Out1_oy = 0.0F;

  /* SignalConversion: '<S86>/TmpBufferAtConstant3Outport1' incorporates:
   *  Constant: '<S86>/Constant3'
   */
  *rty_Out1_p = 1U;

  /* SignalConversion: '<S86>/TmpBufferAtConstant4Outport1' incorporates:
   *  Constant: '<S86>/Constant4'
   */
  *rty_Out1_d = 0U;

  /* SignalConversion: '<S86>/TmpBufferAtConstant5Outport1' incorporates:
   *  Constant: '<S86>/Constant5'
   */
  *rty_Out1 = 0U;

  /* SignalConversion: '<S86>/TmpBufferAtConstant7Outport1' incorporates:
   *  Constant: '<S86>/Constant7'
   */
  *rty_Out1_km = 0.0F;

  /* SignalConversion: '<S86>/TmpBufferAtConstantOutport1' incorporates:
   *  Constant: '<S86>/Constant'
   */
  *rty_Out1_o = 0.0F;
}

/* System initialize for function-call system: '<S56>/Calib' */
void APP_FluxWeak_GEAR2_Calib_Init(DW_Calib_APP_FluxWeak_GEAR2_T *localDW)
{
  localDW->is_Sel_mode = APP_FluxW_IN_NO_ACTIVE_CHILD_km;
  localDW->is_active_c15_APP_FluxWeak_GEAR = 0U;

  /* SystemInitialize for Chart: '<S64>/Chart1' incorporates:
   *  SubSystem: '<S64>/PhaseStudy'
   */
  APP_FluxWeak_GE_PhaseStudy_Init(&localDW->PhaseStudy);

  /* SystemInitialize for Chart: '<S64>/Chart1' incorporates:
   *  SubSystem: '<S64>/Hall'
   */
  APP_FluxWeak_GEAR2_Hall_Init(&localDW->Hall);

  /* SystemInitialize for Chart: '<S64>/Chart1' incorporates:
   *  SubSystem: '<S64>/ElecZeroStudy'
   */
  APP_FluxWeak_ElecZeroStudy_Init(&localDW->ElecZeroStudy);

  /* SystemInitialize for Chart: '<S64>/Chart1' incorporates:
   *  SubSystem: '<S64>/IdqStudy'
   */
  APP_FluxWeak_GEAR_IdqStudy_Init(&localDW->IdqStudy);

  /* SystemInitialize for Chart: '<S64>/Chart1' incorporates:
   *  SubSystem: '<S64>/FluxLinkage'
   */
  APP_FluxWeak_G_FluxLinkage_Init(&localDW->FluxLinkage);

  /* SystemInitialize for Chart: '<S64>/Chart1' incorporates:
   *  SubSystem: '<S64>/MtpaStudy'
   */
  APP_FluxWeak_GEA_MtpaStudy_Init(&localDW->MtpaStudy);
}

/* System reset for function-call system: '<S56>/Calib' */
void APP_FluxWeak_GEAR2_Calib_Reset(DW_Calib_APP_FluxWeak_GEAR2_T *localDW)
{
  /* SystemReset for Chart: '<S64>/Chart1' */
  localDW->is_Sel_mode = APP_FluxW_IN_NO_ACTIVE_CHILD_km;
  localDW->is_active_c15_APP_FluxWeak_GEAR = 0U;
}

/* Enable for function-call system: '<S56>/Calib' */
void APP_FluxWeak_GEAR2_Calib_Enable(DW_Calib_APP_FluxWeak_GEAR2_T *localDW)
{
  /* SystemReset for Function Call SubSystem: '<S64>/Hall' */

  /* Enable for Chart: '<S64>/Chart1' */
  APP_FluxWeak_GEAR2_Hall_Reset(&localDW->Hall);

  /* End of SystemReset for SubSystem: '<S64>/Hall' */

  /* SystemReset for Function Call SubSystem: '<S64>/IdqStudy' */
  APP_FluxWeak_GEA_IdqStudy_Reset(&localDW->IdqStudy);

  /* End of SystemReset for SubSystem: '<S64>/IdqStudy' */

  /* SystemReset for Function Call SubSystem: '<S64>/FluxLinkage' */
  APP_FluxWeak__FluxLinkage_Reset(&localDW->FluxLinkage);

  /* End of SystemReset for SubSystem: '<S64>/FluxLinkage' */
}

/* Output and update for function-call system: '<S56>/Calib' */
void APP_FluxWeak_GEAR2_Calib(uint16_T rtu_Data, real32_T rtu_Data_h, real32_T
  rtu_Data_b, uint16_T rtu_Data_c, real32_T rtu_Data_g, real32_T rtu_Data_hs,
  real32_T rtu_Data_l, real32_T rtu_Data_e, uint16_T *rty_Out1, real32_T
  *rty_Out1_h, real32_T *rty_Out1_b, real32_T *rty_Out1_c, uint16_T *rty_Out1_g,
  uint16_T *rty_Out1_hs, real32_T *rty_Out1_l, real32_T *rty_Out1_e,
  DW_Calib_APP_FluxWeak_GEAR2_T *localDW)
{
  uint16_T CalibStep_prev;

  /* Chart: '<S64>/Chart1' */
  /* Gateway: implement/method/All_loop/Calib/Chart1 */
  CalibStep_prev = localDW->CalibStep_start;
  localDW->CalibStep_start = rtu_Data;

  /* During: implement/method/All_loop/Calib/Chart1 */
  if (localDW->is_active_c15_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/All_loop/Calib/Chart1 */
    localDW->is_active_c15_APP_FluxWeak_GEAR = 1U;

    /* Entry Internal: implement/method/All_loop/Calib/Chart1 */
    /* Entry Internal 'Sel_mode': '<S79>:2' */
    /* Transition: '<S79>:23' */
    /* '<S79>:9:1' sf_internal_predicateOutput = ... */
    /* '<S79>:9:1' CalibStep==1; */
    switch (rtu_Data) {
     case 1U:
      /* Transition: '<S79>:9' */
      localDW->is_Sel_mode = APP_FluxWeak_GEAR_IN_PhaseStudy;

      /* Outputs for Function Call SubSystem: '<S64>/PhaseStudy' */

      /* Entry 'PhaseStudy': '<S79>:31' */
      /* '<S79>:31:1' PhaseStudy; */
      /* Event: '<S79>:32' */
      APP_FluxWeak_GEAR2_PhaseStudy(rtu_Data_h, rtu_Data_b, rty_Out1, rty_Out1_h,
        rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
        &localDW->PhaseStudy);

      /* End of Outputs for SubSystem: '<S64>/PhaseStudy' */
      break;

     case 2U:
      /* Transition: '<S79>:6' */
      /* '<S79>:24:1' sf_internal_predicateOutput = ... */
      /* '<S79>:24:1' CalibStep==2; */
      /* Transition: '<S79>:24' */
      localDW->is_Sel_mode = APP_FluxWeak_G_IN_ElecZeroStudy;

      /* Outputs for Function Call SubSystem: '<S64>/Hall' */

      /* Entry 'ElecZeroStudy': '<S79>:37' */
      /* '<S79>:37:1' Hall; */
      /* Event: '<S79>:55' */
      APP_FluxWeak_GEAR2_Hall(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
        rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
        &localDW->Hall);

      /* End of Outputs for SubSystem: '<S64>/Hall' */
      break;

     case 3U:
      /* Transition: '<S79>:21' */
      /* '<S79>:12:1' sf_internal_predicateOutput = ... */
      /* '<S79>:12:1' CalibStep==3; */
      /* Transition: '<S79>:12' */
      localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_IfStudy;

      /* Outputs for Function Call SubSystem: '<S64>/ElecZeroStudy' */

      /* Entry 'IfStudy': '<S79>:39' */
      /* '<S79>:39:1' ElecZeroStudy; */
      /* Event: '<S79>:49' */
      APP_FluxWeak_GEAR_ElecZeroStudy(rtu_Data_c, rtu_Data_b, rtu_Data_g,
        rtu_Data_hs, rtu_Data_h, rty_Out1, rty_Out1_h, rty_Out1_b, rty_Out1_c,
        rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e, &localDW->ElecZeroStudy);

      /* End of Outputs for SubSystem: '<S64>/ElecZeroStudy' */
      break;

     case 4U:
      /* Transition: '<S79>:22' */
      /* '<S79>:10:1' sf_internal_predicateOutput = ... */
      /* '<S79>:10:1' CalibStep==4; */
      /* Transition: '<S79>:10' */
      localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_LdStudy;

      /* Outputs for Function Call SubSystem: '<S64>/IdqStudy' */

      /* Entry 'LdStudy': '<S79>:41' */
      /* '<S79>:41:1' IdqStudy; */
      /* Event: '<S79>:50' */
      APP_FluxWeak_GEAR2_IdqStudy(rtu_Data_b, rtu_Data_l, rty_Out1, rty_Out1_h,
        rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
        &localDW->IdqStudy);

      /* End of Outputs for SubSystem: '<S64>/IdqStudy' */
      break;

     case 5U:
      /* Transition: '<S79>:27' */
      /* '<S79>:25:1' sf_internal_predicateOutput = ... */
      /* '<S79>:25:1' CalibStep==5; */
      /* Transition: '<S79>:25' */
      localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_MtpaStudy;

      /* Outputs for Function Call SubSystem: '<S64>/FluxLinkage' */

      /* Entry 'MtpaStudy': '<S79>:43' */
      /* '<S79>:43:1' FluxLinkage; */
      /* Event: '<S79>:53' */
      APP_FluxWeak_GEAR2_FluxLinkage(rtu_Data_b, rty_Out1, rty_Out1_h,
        rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
        &localDW->FluxLinkage);

      /* End of Outputs for SubSystem: '<S64>/FluxLinkage' */
      break;

     case 6U:
      /* Transition: '<S79>:13' */
      /* '<S79>:28:1' sf_internal_predicateOutput = ... */
      /* '<S79>:28:1' CalibStep==6; */
      /* Transition: '<S79>:28' */
      localDW->is_Sel_mode = APP_FluxWeak_IN_IsMax_TLinStudy;

      /* Outputs for Function Call SubSystem: '<S64>/MtpaStudy' */

      /* Entry 'IsMax_TLinStudy': '<S79>:45' */
      /* '<S79>:45:1' MTPA; */
      /* Event: '<S79>:51' */
      APP_FluxWeak_GEAR2_MtpaStudy(rtu_Data_l, rtu_Data_b, rtu_Data_e, rty_Out1,
        rty_Out1_h, rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l,
        rty_Out1_e, &localDW->MtpaStudy);

      /* End of Outputs for SubSystem: '<S64>/MtpaStudy' */
      break;

     default:
      /* Transition: '<S79>:26' */
      /* Transition: '<S79>:18' */
      localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_Normal;

      /* Outputs for Function Call SubSystem: '<S64>/Tlin' */

      /* Entry 'Normal': '<S79>:47' */
      /* '<S79>:47:1' Normal; */
      /* Event: '<S79>:54' */
      APP_FluxWeak_GEAR2_Tlin(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
        rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e);

      /* End of Outputs for SubSystem: '<S64>/Tlin' */
      break;
    }
  } else {
    /* During 'Sel_mode': '<S79>:2' */
    /* '<S79>:57:1' sf_internal_predicateOutput = ... */
    /* '<S79>:57:1' hasChanged(CalibStep); */
    if (CalibStep_prev != localDW->CalibStep_start) {
      /* Transition: '<S79>:57' */
      /* '<S79>:9:1' sf_internal_predicateOutput = ... */
      /* '<S79>:9:1' CalibStep==1; */
      switch (rtu_Data) {
       case 1U:
        /* Transition: '<S79>:9' */
        /* Exit Internal 'Sel_mode': '<S79>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_GEAR_IN_PhaseStudy;

        /* Outputs for Function Call SubSystem: '<S64>/PhaseStudy' */

        /* Entry 'PhaseStudy': '<S79>:31' */
        /* '<S79>:31:1' PhaseStudy; */
        /* Event: '<S79>:32' */
        APP_FluxWeak_GEAR2_PhaseStudy(rtu_Data_h, rtu_Data_b, rty_Out1,
          rty_Out1_h, rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs,
          rty_Out1_l, rty_Out1_e, &localDW->PhaseStudy);

        /* End of Outputs for SubSystem: '<S64>/PhaseStudy' */
        break;

       case 2U:
        /* Transition: '<S79>:6' */
        /* '<S79>:24:1' sf_internal_predicateOutput = ... */
        /* '<S79>:24:1' CalibStep==2; */
        /* Transition: '<S79>:24' */
        /* Exit Internal 'Sel_mode': '<S79>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_G_IN_ElecZeroStudy;

        /* Outputs for Function Call SubSystem: '<S64>/Hall' */

        /* Entry 'ElecZeroStudy': '<S79>:37' */
        /* '<S79>:37:1' Hall; */
        /* Event: '<S79>:55' */
        APP_FluxWeak_GEAR2_Hall(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
          rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
          &localDW->Hall);

        /* End of Outputs for SubSystem: '<S64>/Hall' */
        break;

       case 3U:
        /* Transition: '<S79>:21' */
        /* '<S79>:12:1' sf_internal_predicateOutput = ... */
        /* '<S79>:12:1' CalibStep==3; */
        /* Transition: '<S79>:12' */
        /* Exit Internal 'Sel_mode': '<S79>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_IfStudy;

        /* Outputs for Function Call SubSystem: '<S64>/ElecZeroStudy' */

        /* Entry 'IfStudy': '<S79>:39' */
        /* '<S79>:39:1' ElecZeroStudy; */
        /* Event: '<S79>:49' */
        APP_FluxWeak_GEAR_ElecZeroStudy(rtu_Data_c, rtu_Data_b, rtu_Data_g,
          rtu_Data_hs, rtu_Data_h, rty_Out1, rty_Out1_h, rty_Out1_b, rty_Out1_c,
          rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
          &localDW->ElecZeroStudy);

        /* End of Outputs for SubSystem: '<S64>/ElecZeroStudy' */
        break;

       case 4U:
        /* Transition: '<S79>:22' */
        /* '<S79>:10:1' sf_internal_predicateOutput = ... */
        /* '<S79>:10:1' CalibStep==4; */
        /* Transition: '<S79>:10' */
        /* Exit Internal 'Sel_mode': '<S79>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_LdStudy;

        /* Outputs for Function Call SubSystem: '<S64>/IdqStudy' */

        /* Entry 'LdStudy': '<S79>:41' */
        /* '<S79>:41:1' IdqStudy; */
        /* Event: '<S79>:50' */
        APP_FluxWeak_GEAR2_IdqStudy(rtu_Data_b, rtu_Data_l, rty_Out1, rty_Out1_h,
          rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l,
          rty_Out1_e, &localDW->IdqStudy);

        /* End of Outputs for SubSystem: '<S64>/IdqStudy' */
        break;

       case 5U:
        /* Transition: '<S79>:27' */
        /* '<S79>:25:1' sf_internal_predicateOutput = ... */
        /* '<S79>:25:1' CalibStep==5; */
        /* Transition: '<S79>:25' */
        /* Exit Internal 'Sel_mode': '<S79>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_MtpaStudy;

        /* Outputs for Function Call SubSystem: '<S64>/FluxLinkage' */

        /* Entry 'MtpaStudy': '<S79>:43' */
        /* '<S79>:43:1' FluxLinkage; */
        /* Event: '<S79>:53' */
        APP_FluxWeak_GEAR2_FluxLinkage(rtu_Data_b, rty_Out1, rty_Out1_h,
          rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l,
          rty_Out1_e, &localDW->FluxLinkage);

        /* End of Outputs for SubSystem: '<S64>/FluxLinkage' */
        break;

       case 6U:
        /* Transition: '<S79>:13' */
        /* '<S79>:28:1' sf_internal_predicateOutput = ... */
        /* '<S79>:28:1' CalibStep==6; */
        /* Transition: '<S79>:28' */
        /* Exit Internal 'Sel_mode': '<S79>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_IN_IsMax_TLinStudy;

        /* Outputs for Function Call SubSystem: '<S64>/MtpaStudy' */

        /* Entry 'IsMax_TLinStudy': '<S79>:45' */
        /* '<S79>:45:1' MTPA; */
        /* Event: '<S79>:51' */
        APP_FluxWeak_GEAR2_MtpaStudy(rtu_Data_l, rtu_Data_b, rtu_Data_e,
          rty_Out1, rty_Out1_h, rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs,
          rty_Out1_l, rty_Out1_e, &localDW->MtpaStudy);

        /* End of Outputs for SubSystem: '<S64>/MtpaStudy' */
        break;

       default:
        /* Transition: '<S79>:26' */
        /* Transition: '<S79>:18' */
        /* Exit Internal 'Sel_mode': '<S79>:2' */
        localDW->is_Sel_mode = APP_FluxWeak_GEAR2_IN_Normal;

        /* Outputs for Function Call SubSystem: '<S64>/Tlin' */

        /* Entry 'Normal': '<S79>:47' */
        /* '<S79>:47:1' Normal; */
        /* Event: '<S79>:54' */
        APP_FluxWeak_GEAR2_Tlin(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
          rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e);

        /* End of Outputs for SubSystem: '<S64>/Tlin' */
        break;
      }
    } else {
      switch (localDW->is_Sel_mode) {
       case APP_FluxWeak_G_IN_ElecZeroStudy:
        /* Outputs for Function Call SubSystem: '<S64>/Hall' */

        /* During 'ElecZeroStudy': '<S79>:37' */
        /* '<S79>:37:1' Hall; */
        /* Event: '<S79>:55' */
        APP_FluxWeak_GEAR2_Hall(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
          rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
          &localDW->Hall);

        /* End of Outputs for SubSystem: '<S64>/Hall' */
        break;

       case APP_FluxWeak_GEAR2_IN_IfStudy:
        /* Outputs for Function Call SubSystem: '<S64>/ElecZeroStudy' */

        /* During 'IfStudy': '<S79>:39' */
        /* '<S79>:39:1' ElecZeroStudy; */
        /* Event: '<S79>:49' */
        APP_FluxWeak_GEAR_ElecZeroStudy(rtu_Data_c, rtu_Data_b, rtu_Data_g,
          rtu_Data_hs, rtu_Data_h, rty_Out1, rty_Out1_h, rty_Out1_b, rty_Out1_c,
          rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e,
          &localDW->ElecZeroStudy);

        /* End of Outputs for SubSystem: '<S64>/ElecZeroStudy' */
        break;

       case APP_FluxWeak_IN_IsMax_TLinStudy:
        /* Outputs for Function Call SubSystem: '<S64>/MtpaStudy' */

        /* During 'IsMax_TLinStudy': '<S79>:45' */
        /* '<S79>:45:1' MTPA; */
        /* Event: '<S79>:51' */
        APP_FluxWeak_GEAR2_MtpaStudy(rtu_Data_l, rtu_Data_b, rtu_Data_e,
          rty_Out1, rty_Out1_h, rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs,
          rty_Out1_l, rty_Out1_e, &localDW->MtpaStudy);

        /* End of Outputs for SubSystem: '<S64>/MtpaStudy' */
        break;

       case APP_FluxWeak_GEAR2_IN_LdStudy:
        /* Outputs for Function Call SubSystem: '<S64>/IdqStudy' */

        /* During 'LdStudy': '<S79>:41' */
        /* '<S79>:41:1' IdqStudy; */
        /* Event: '<S79>:50' */
        APP_FluxWeak_GEAR2_IdqStudy(rtu_Data_b, rtu_Data_l, rty_Out1, rty_Out1_h,
          rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l,
          rty_Out1_e, &localDW->IdqStudy);

        /* End of Outputs for SubSystem: '<S64>/IdqStudy' */
        break;

       case APP_FluxWeak_GEAR2_IN_MtpaStudy:
        /* Outputs for Function Call SubSystem: '<S64>/FluxLinkage' */

        /* During 'MtpaStudy': '<S79>:43' */
        /* '<S79>:43:1' FluxLinkage; */
        /* Event: '<S79>:53' */
        APP_FluxWeak_GEAR2_FluxLinkage(rtu_Data_b, rty_Out1, rty_Out1_h,
          rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l,
          rty_Out1_e, &localDW->FluxLinkage);

        /* End of Outputs for SubSystem: '<S64>/FluxLinkage' */
        break;

       case APP_FluxWeak_GEAR2_IN_Normal:
        /* Outputs for Function Call SubSystem: '<S64>/Tlin' */

        /* During 'Normal': '<S79>:47' */
        /* '<S79>:47:1' Normal; */
        /* Event: '<S79>:54' */
        APP_FluxWeak_GEAR2_Tlin(rtu_Data_b, rty_Out1, rty_Out1_h, rty_Out1_b,
          rty_Out1_c, rty_Out1_g, rty_Out1_hs, rty_Out1_l, rty_Out1_e);

        /* End of Outputs for SubSystem: '<S64>/Tlin' */
        break;

       default:
        /* Outputs for Function Call SubSystem: '<S64>/PhaseStudy' */

        /* During 'PhaseStudy': '<S79>:31' */
        /* '<S79>:31:1' PhaseStudy; */
        /* Event: '<S79>:32' */
        APP_FluxWeak_GEAR2_PhaseStudy(rtu_Data_h, rtu_Data_b, rty_Out1,
          rty_Out1_h, rty_Out1_b, rty_Out1_c, rty_Out1_g, rty_Out1_hs,
          rty_Out1_l, rty_Out1_e, &localDW->PhaseStudy);

        /* End of Outputs for SubSystem: '<S64>/PhaseStudy' */
        break;
      }
    }
  }

  /* End of Chart: '<S64>/Chart1' */
}

/* Output and update for function-call system: '<S56>/Initial_D' */
void APP_FluxWeak_GEAR2_Initial_D(void)
{
  /* StateWriter: '<S69>/State Writer4' incorporates:
   *  Constant: '<S69>/Constant'
   */
  APP_FluxWeak_GEAR2_DW.Spd_g.Spd_D_Int = 0.0F;
}

/* System initialize for function-call system: '<S56>/UVW_check' */
void APP_FluxWeak_GEA_UVW_check_Init(DW_UVW_check_APP_FluxWeak_GEA_T *localDW)
{
  /* SystemInitialize for Atomic SubSystem: '<S137>/lpf' */
  LPF_App_Init(&localDW->lpf);

  /* End of SystemInitialize for SubSystem: '<S137>/lpf' */

  /* SystemInitialize for Atomic SubSystem: '<S138>/lpf' */
  LPF_App_Init(&localDW->lpf_e);

  /* End of SystemInitialize for SubSystem: '<S138>/lpf' */

  /* SystemInitialize for Atomic SubSystem: '<S139>/lpf' */
  LPF_App_Init(&localDW->lpf_c);

  /* End of SystemInitialize for SubSystem: '<S139>/lpf' */

  /* SystemInitialize for Chart: '<S77>/Chart' */
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c28_APP_FluxWeak_GEAR = 0U;
  localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxW_IN_NO_ACTIVE_CHILD_oa;
  localDW->IdRefSet = 0.0F;
  localDW->AngleRefSet = 0.0F;
  localDW->IdIqSetEn = 1U;
  localDW->AngleSetEn = 1U;
  localDW->UVW_offline = 0U;
}

/* System reset for function-call system: '<S56>/UVW_check' */
void APP_FluxWeak_GE_UVW_check_Reset(DW_UVW_check_APP_FluxWeak_GEA_T *localDW)
{
  /* SystemReset for Atomic SubSystem: '<S137>/lpf' */
  LPF_App_Reset(&localDW->lpf);

  /* End of SystemReset for SubSystem: '<S137>/lpf' */

  /* SystemReset for Atomic SubSystem: '<S138>/lpf' */
  LPF_App_Reset(&localDW->lpf_e);

  /* End of SystemReset for SubSystem: '<S138>/lpf' */

  /* SystemReset for Atomic SubSystem: '<S139>/lpf' */
  LPF_App_Reset(&localDW->lpf_c);

  /* End of SystemReset for SubSystem: '<S139>/lpf' */

  /* SystemReset for Chart: '<S77>/Chart' */
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c28_APP_FluxWeak_GEAR = 0U;
  localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxW_IN_NO_ACTIVE_CHILD_oa;
  localDW->IdRefSet = 0.0F;
  localDW->AngleRefSet = 0.0F;
  localDW->IdIqSetEn = 1U;
  localDW->AngleSetEn = 1U;
  localDW->UVW_offline = 0U;
}

/* Output and update for function-call system: '<S56>/UVW_check' */
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

  /* SignalConversion: '<S77>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut = 0U;

  /* Outputs for Atomic SubSystem: '<S137>/lpf' */

  /* Abs: '<S77>/Abs' incorporates:
   *  Constant: '<S137>/Constant'
   *  Constant: '<S137>/Constant1'
   */
  LPF_App(fabsf(rtu_Data), 0.002F, 10.0F, &rtb_DiscreteTimeIntegrator1_hl,
          &localDW->lpf);

  /* End of Outputs for SubSystem: '<S137>/lpf' */

  /* Outputs for Atomic SubSystem: '<S138>/lpf' */

  /* Abs: '<S77>/Abs1' incorporates:
   *  Constant: '<S138>/Constant'
   *  Constant: '<S138>/Constant1'
   */
  LPF_App(fabsf(rtu_Data_l), 0.002F, 10.0F, &rtb_DiscreteTimeIntegrator1_p,
          &localDW->lpf_e);

  /* End of Outputs for SubSystem: '<S138>/lpf' */

  /* Outputs for Atomic SubSystem: '<S139>/lpf' */

  /* Abs: '<S77>/Abs2' incorporates:
   *  Constant: '<S139>/Constant'
   *  Constant: '<S139>/Constant1'
   */
  LPF_App(fabsf(rtu_Data_h), 0.002F, 10.0F, &rtb_DiscreteTimeIntegrator1_l,
          &localDW->lpf_c);

  /* End of Outputs for SubSystem: '<S139>/lpf' */

  /* Chart: '<S77>/Chart' */
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
    /* Transition: '<S136>:5' */
    localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_start;

    /* Entry 'start': '<S136>:6' */
    /* '<S136>:6:1' IdIqSetEn=1; */
    localDW->IdIqSetEn = 1U;

    /* '<S136>:6:1' AngleSetEn =1 ; */
    localDW->AngleSetEn = 1U;

    /* '<S136>:6:1' IdRefSet=IdRefSet+0.001; */
    localDW->IdRefSet += 0.001F;

    /* '<S136>:6:4' AngleRefSet=0; */
    localDW->AngleRefSet = 0.0F;
  } else {
    switch (localDW->is_c28_APP_FluxWeak_GEAR2) {
     case APP_FluxWeak_GEAR2_IN_check:
      /* During 'check': '<S136>:13' */
      /* Transition: '<S136>:27' */
      localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_quitcheck;

      /* Entry 'quitcheck': '<S136>:26' */
      /* '<S136>:26:1' IdIqSetEn=1; */
      localDW->IdIqSetEn = 1U;

      /* '<S136>:26:1' AngleSetEn =1 ; */
      localDW->AngleSetEn = 1U;

      /* '<S136>:26:1' IdRefSet=IdRefSet-0.001; */
      localDW->IdRefSet -= 0.001F;

      /* '<S136>:26:4' AngleRefSet=0; */
      localDW->AngleRefSet = 0.0F;
      break;

     case APP_FluxWeak_GEAR2_IN_fin:
      /* During 'fin': '<S136>:28' */
      break;

     case APP_FluxWeak_GEAR2_IN_hold:
      /* During 'hold': '<S136>:11' */
      /* '<S136>:14:1' sf_internal_predicateOutput = ... */
      /* '<S136>:14:1' after(100,tick); */
      if ((int16_T)localDW->temporalCounter_i1 >= 100) {
        /* Transition: '<S136>:14' */
        localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_check;

        /* Entry Internal 'check': '<S136>:13' */
        /* Transition: '<S136>:16' */
        /* '<S136>:18:1' sf_internal_predicateOutput = ... */
        /* '<S136>:18:1' CurU>0.025 && CurV>0.0125 && CurW>0.0125; */
        if ((rtb_DiscreteTimeIntegrator1_hl > 0.025) &&
            (rtb_DiscreteTimeIntegrator1_p > 0.0125) &&
            (rtb_DiscreteTimeIntegrator1_l > 0.0125)) {
          /* Transition: '<S136>:18' */
          /* Transition: '<S136>:21' */
          /* '<S136>:21:1' UVW_offline=0; */
          localDW->UVW_offline = 0U;

          /* Transition: '<S136>:24' */
        } else {
          /* Transition: '<S136>:22' */
          /* '<S136>:22:1' UVW_offline=1; */
          localDW->UVW_offline = 1U;
        }
      } else {
        /* '<S136>:11:1' IdIqSetEn=1; */
        localDW->IdIqSetEn = 1U;

        /* '<S136>:11:1' AngleSetEn =1 ; */
        localDW->AngleSetEn = 1U;

        /* '<S136>:11:1' IdRefSet=0.05; */
        localDW->IdRefSet = 0.05F;

        /* '<S136>:11:3' AngleRefSet=0; */
        localDW->AngleRefSet = 0.0F;
      }
      break;

     case APP_FluxWeak_GEAR2_IN_quitcheck:
      /* During 'quitcheck': '<S136>:26' */
      /* '<S136>:29:1' sf_internal_predicateOutput = ... */
      /* '<S136>:29:1' IdRefSet<0.01; */
      if (localDW->IdRefSet < 0.01) {
        /* Transition: '<S136>:29' */
        localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_fin;

        /* Entry 'fin': '<S136>:28' */
        /* '<S136>:28:1' IdIqSetEn=0; */
        localDW->IdIqSetEn = 0U;

        /* '<S136>:28:1' AngleSetEn =0 ; */
        localDW->AngleSetEn = 0U;

        /* '<S136>:28:1' IdRefSet=0; */
        localDW->IdRefSet = 0.0F;

        /* '<S136>:28:3' AngleRefSet=0; */
        localDW->AngleRefSet = 0.0F;
      } else {
        /* '<S136>:26:1' IdIqSetEn=1; */
        localDW->IdIqSetEn = 1U;

        /* '<S136>:26:1' AngleSetEn =1 ; */
        localDW->AngleSetEn = 1U;

        /* '<S136>:26:1' IdRefSet=IdRefSet-0.001; */
        localDW->IdRefSet -= 0.001F;

        /* '<S136>:26:4' AngleRefSet=0; */
        localDW->AngleRefSet = 0.0F;
      }
      break;

     default:
      /* During 'start': '<S136>:6' */
      /* '<S136>:12:1' sf_internal_predicateOutput = ... */
      /* '<S136>:12:1' IdRefSet>=0.05; */
      if (localDW->IdRefSet >= 0.05) {
        /* Transition: '<S136>:12' */
        localDW->is_c28_APP_FluxWeak_GEAR2 = APP_FluxWeak_GEAR2_IN_hold;
        localDW->temporalCounter_i1 = 0U;

        /* Entry 'hold': '<S136>:11' */
        /* '<S136>:11:1' IdIqSetEn=1; */
        localDW->IdIqSetEn = 1U;

        /* '<S136>:11:1' AngleSetEn =1 ; */
        localDW->AngleSetEn = 1U;

        /* '<S136>:11:1' IdRefSet=0.05; */
        localDW->IdRefSet = 0.05F;

        /* '<S136>:11:3' AngleRefSet=0; */
        localDW->AngleRefSet = 0.0F;
      } else {
        /* '<S136>:6:1' IdIqSetEn=1; */
        localDW->IdIqSetEn = 1U;

        /* '<S136>:6:1' AngleSetEn =1 ; */
        localDW->AngleSetEn = 1U;

        /* '<S136>:6:1' IdRefSet=IdRefSet+0.001; */
        localDW->IdRefSet += 0.001F;

        /* '<S136>:6:4' AngleRefSet=0; */
        localDW->AngleRefSet = 0.0F;
      }
      break;
    }
  }

  /* End of Chart: '<S77>/Chart' */

  /* SignalConversion: '<S77>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_l = localDW->IdRefSet;

  /* SignalConversion: '<S77>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_h = 0.0F;

  /* SignalConversion: '<S77>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_p = localDW->AngleRefSet;

  /* SignalConversion: '<S77>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_j = localDW->IdIqSetEn;

  /* SignalConversion: '<S77>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_b = localDW->AngleSetEn;

  /* SignalConversion: '<S77>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_a = 0.0F;

  /* SignalConversion: '<S77>/BusConversion_InsertedFor_UVWCheckOut_at_inport_0' */
  *rty_UVWCheckOut_b3 = 0.0F;

  /* SignalConversion: '<S77>/OutportBufferForUVWFault' */
  *rty_UVWFault = localDW->UVW_offline;
}

/*
 * Output and update for function-call system:
 *    '<S152>/Lim_state'
 *    '<S158>/Lim_state'
 */
void APP_FluxWeak_GEAR2_Lim_state(void)
{
  /* Saturate: '<S155>/Saturation' incorporates:
   *  StateReader: '<S155>/State Reader'
   */
  if (APP_FluxWeak_GEAR2_DW.sf_Chart_lj.FunctionCallSubsystem.PI.I_state > 1.0F)
  {
    /* StateWriter: '<S155>/State Writer' */
    APP_FluxWeak_GEAR2_DW.sf_Chart_lj.FunctionCallSubsystem.PI.I_state = 1.0F;
  } else {
    if (APP_FluxWeak_GEAR2_DW.sf_Chart_lj.FunctionCallSubsystem.PI.I_state <
        0.0F) {
      /* StateWriter: '<S155>/State Writer' */
      APP_FluxWeak_GEAR2_DW.sf_Chart_lj.FunctionCallSubsystem.PI.I_state = 0.0F;
    }
  }

  /* End of Saturate: '<S155>/Saturation' */
}

/*
 * System initialize for function-call system:
 *    '<S152>/Function-Call Subsystem'
 *    '<S158>/Function-Call Subsystem'
 */
void AP_FunctionCallSubsystem_a_Init(real32_T *rty_PIOut)
{
  /* SystemInitialize for Outport: '<S154>/PIOut' */
  *rty_PIOut = 1.0F;
}

/*
 * Output and update for function-call system:
 *    '<S152>/Function-Call Subsystem'
 *    '<S158>/Function-Call Subsystem'
 */
void APP_Flu_FunctionCallSubsystem_p(real32_T rtu_Err, real32_T *rty_PIOut,
  DW_FunctionCallSubsystem_AP_g_T *localDW)
{
  real32_T rtb_DiscreteTimeIntegrator1_n;

  /* Outputs for Atomic SubSystem: '<S154>/PI' */

  /* Constant: '<S154>/Constant' incorporates:
   *  Constant: '<S154>/Constant1'
   *  Constant: '<S154>/Constant2'
   */
  PI_App(rtu_Err, PMSM_Param.LimIKp, PMSM_Param.LimIKi, 0.002F, rty_PIOut,
         &rtb_DiscreteTimeIntegrator1_n, &localDW->PI);

  /* End of Outputs for SubSystem: '<S154>/PI' */
}

/*
 * System initialize for atomic system:
 *    '<S152>/Chart'
 *    '<S158>/Chart'
 */
void APP_FluxWeak_GEAR2_Chart_Init(real32_T *rty_0,
  DW_Chart_APP_FluxWeak_GEAR2_T *localDW)
{
  localDW->is_active_c25_APP_FluxWeak_GEAR = 0U;

  /* SystemInitialize for Function Call SubSystem: '<S152>/Function-Call Subsystem' */
  AP_FunctionCallSubsystem_a_Init(rty_0);

  /* End of SystemInitialize for SubSystem: '<S152>/Function-Call Subsystem' */
}

/*
 * System reset for atomic system:
 *    '<S152>/Chart'
 *    '<S158>/Chart'
 */
void APP_FluxWeak_GEAR2_Chart_Reset(DW_Chart_APP_FluxWeak_GEAR2_T *localDW)
{
  localDW->is_active_c25_APP_FluxWeak_GEAR = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S152>/Chart'
 *    '<S158>/Chart'
 */
void APP_FluxWeak_GEAR2_Chart(real32_T rtu_0, real32_T *rty_0,
  DW_Chart_APP_FluxWeak_GEAR2_T *localDW)
{
  /* Chart: '<S152>/Chart' */
  /* Gateway: implement/method/Lim&Fault/LimI/LimChg/PI/Chart */
  /* During: implement/method/Lim&Fault/LimI/LimChg/PI/Chart */
  if (localDW->is_active_c25_APP_FluxWeak_GEAR == 0U) {
    /* Entry: implement/method/Lim&Fault/LimI/LimChg/PI/Chart */
    localDW->is_active_c25_APP_FluxWeak_GEAR = 1U;

    /* Outputs for Function Call SubSystem: '<S152>/Function-Call Subsystem' */

    /* Entry Internal: implement/method/Lim&Fault/LimI/LimChg/PI/Chart */
    /* Transition: '<S153>:2' */
    /* Entry 'NV_weak_call': '<S153>:1' */
    /* '<S153>:1:1' PI_call; */
    /* Event: '<S153>:4' */
    APP_Flu_FunctionCallSubsystem_p(rtu_0, rty_0,
      &localDW->FunctionCallSubsystem);

    /* End of Outputs for SubSystem: '<S152>/Function-Call Subsystem' */

    /* Outputs for Function Call SubSystem: '<S152>/Lim_state' */

    /* '<S153>:1:1' IntLim_nv; */
    /* Event: '<S153>:3' */
    APP_FluxWeak_GEAR2_Lim_state();

    /* End of Outputs for SubSystem: '<S152>/Lim_state' */
  } else {
    /* Outputs for Function Call SubSystem: '<S152>/Function-Call Subsystem' */

    /* During 'NV_weak_call': '<S153>:1' */
    /* '<S153>:1:1' PI_call; */
    /* Event: '<S153>:4' */
    APP_Flu_FunctionCallSubsystem_p(rtu_0, rty_0,
      &localDW->FunctionCallSubsystem);

    /* End of Outputs for SubSystem: '<S152>/Function-Call Subsystem' */

    /* Outputs for Function Call SubSystem: '<S152>/Lim_state' */

    /* '<S153>:1:1' IntLim_nv; */
    /* Event: '<S153>:3' */
    APP_FluxWeak_GEAR2_Lim_state();

    /* End of Outputs for SubSystem: '<S152>/Lim_state' */
  }

  /* End of Chart: '<S152>/Chart' */
}

/* Output and update for Simulink Function: '<S10>/Simulink Function2' */
void APP_FluxWeak_GEAR2_n2MaxT(real32_T rtu_Psi, real32_T *rty_Tmax)
{
  uint32_T bpIdx;
  real32_T frac;

  /* Lookup_n-D: '<S61>/table' incorporates:
   *  SignalConversion: '<S61>/TmpSignal ConversionAtPsiOutport1'
   */
  bpIdx = plook_u32ff_evenca(rtu_Psi, 0.165408403F, 0.013502717F, 49UL, &frac);

  /* SignalConversion: '<S61>/TmpSignal ConversionAtTmaxInport1' incorporates:
   *  Lookup_n-D: '<S61>/table'
   */
  *rty_Tmax = intrp1d_fu32fla_pw(bpIdx, frac, rtCP_table_tableData_f, 49UL);
}

/* Function for Chart: '<S56>/Chart' */
static void APP_Flux_exit_internal_sys_mode(const real32_T
  *DiscreteTimeIntegrator1, const real32_T *DiscreteTimeIntegrator1_i)
{
  /* Exit Internal 'sys_mode': '<S65>:7' */
  switch (APP_FluxWeak_GEAR2_DW.is_sys_mode) {
   case APP_FluxWeak_GEAR2_IN_Speed:
    /* Exit Internal 'Speed': '<S65>:5' */
    APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;

    /* Outputs for Function Call SubSystem: '<S56>/Update' */

    /* Exit 'Speed': '<S65>:5' */
    /* '<S65>:5:1' Update; */
    /* Event: '<S65>:13' */
    APP_FluxWeak_GEAR2_Update(&APP_FluxWeak_GEAR2_DW.Merge1,
      *DiscreteTimeIntegrator1_i, *DiscreteTimeIntegrator1);

    /* End of Outputs for SubSystem: '<S56>/Update' */

    /* Outputs for Function Call SubSystem: '<S56>/Initial_D' */

    /* '<S65>:5:1' Initial_D  */
    /* Event: '<S65>:85' */
    APP_FluxWeak_GEAR2_Initial_D();

    /* End of Outputs for SubSystem: '<S56>/Initial_D' */
    APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    break;

   case APP_FluxWeak_GEAR2_IN_Torque:
    /* Outputs for Function Call SubSystem: '<S56>/Update' */

    /* Exit 'Torque': '<S65>:3' */
    /* '<S65>:3:1' Update; */
    /* Event: '<S65>:13' */
    APP_FluxWeak_GEAR2_Update(&APP_FluxWeak_GEAR2_DW.Merge1,
      *DiscreteTimeIntegrator1_i, *DiscreteTimeIntegrator1);

    /* End of Outputs for SubSystem: '<S56>/Update' */

    /* Outputs for Function Call SubSystem: '<S56>/Initial_D' */

    /* '<S65>:3:2' Initial_D  */
    /* Event: '<S65>:85' */
    APP_FluxWeak_GEAR2_Initial_D();

    /* End of Outputs for SubSystem: '<S56>/Initial_D' */
    APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    break;

   case APP_FluxWeak_GEAR2_IN_appoint:
    /* Exit Internal 'appoint': '<S65>:6' */
    APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;

    /* Outputs for Function Call SubSystem: '<S56>/Initial' */

    /* Exit 'appoint': '<S65>:6' */
    /* '<S65>:6:1' Initial; */
    /* Event: '<S65>:12' */
    APP_FluxWeak_GEAR2_Initial();

    /* End of Outputs for SubSystem: '<S56>/Initial' */
    APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
    break;
  }
}

/* Model step function */
void APP_FluxWeak_GEAR2_step(void)
{
  uint16_T ii;
  uint32_T bpIdx;
  real32_T rtb_BusConversion_InsertedFor_0;
  real32_T rtb_DiscreteTimeIntegrator1;
  real32_T rtb_MotTemp;
  real32_T rtb_Psi_i;
  uint16_T rtb_UVWoffline;
  int16_T rtb_LogicalOperator;
  real32_T rtb_Add_j;
  real32_T rtb_Divide_p;
  real32_T rtb_Abs_l;
  real32_T rtb_Divide_o;
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
    rtb_MotTemp = 5.0F;
  } else if (Algo_Output.Cur_loop.Vs < 1.0F) {
    rtb_MotTemp = 1.0F;
  } else {
    rtb_MotTemp = Algo_Output.Cur_loop.Vs;
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
             rtCP_uDLookupTable_tableData, 128UL) / rtb_MotTemp)), 0.002F, 5.0F,
          &rtb_DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.lpf_p);

  /* End of Outputs for SubSystem: '<S189>/lpf' */

  /* MinMax: '<S194>/Min' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   */
  rtb_MotTemp = fmaxf(PMSM_Input.AppSample.MotTemp1,
                      PMSM_Input.AppSample.MotTemp2);

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
   *  MinMax: '<S194>/Min1'
   */
  rtb_BusConversion_InsertedFor_0 = fmaxf(fmaxf(PMSM_Input.AppSample.InvTemp1,
    PMSM_Input.AppSample.InvTemp2), PMSM_Input.AppSample.InvTemp3);
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
     *  EnablePort: '<S19>/Enable'
     */
    /* RelationalOperator: '<S21>/Compare' incorporates:
     *  Constant: '<S21>/Constant'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 2U) {
      /* Abs: '<S19>/Abs' */
      rtb_Switch_b = fabsf(DiscreteTimeIntegrator1);

      /* MultiPortSwitch: '<S35>/Multiport Switch' incorporates:
       *  Abs: '<S35>/Abs1'
       *  Abs: '<S35>/Abs2'
       *  Constant: '<S35>/Constant'
       *  Constant: '<S35>/Constant1'
       *  Constant: '<S35>/Constant3'
       *  Constant: '<S36>/Constant'
       *  Constant: '<S37>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read'
       *  RelationalOperator: '<S36>/Compare'
       *  RelationalOperator: '<S37>/Compare'
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
        rtb_MultiportSwitch = (fabsf(PMSM_Input.AppComm.TqReq) <= 0.05F);
        break;

       default:
        rtb_MultiportSwitch = true;
        break;
      }

      /* End of MultiPortSwitch: '<S35>/Multiport Switch' */

      /* Chart: '<S19>/Chart' incorporates:
       *  Abs: '<S19>/Abs'
       *  DataStoreRead: '<Root>/Data Store Read2'
       *  Math: '<S177>/Math Function'
       */
      /* Gateway: implement/Fault/judgment/Block/Chart */
      /* During: implement/Fault/judgment/Block/Chart */
      /* Entry Internal: implement/Fault/judgment/Block/Chart */
      /* Transition: '<S33>:6' */
      /* '<S33>:17:1' sf_internal_predicateOutput = ... */
      /* '<S33>:17:1' Spd>200 || LowReq; */
      if ((rtb_Switch_b > 200.0F) || rtb_MultiportSwitch) {
        /* Transition: '<S33>:17' */
        /* Transition: '<S33>:19' */
        /* '<S33>:19:1' BlockState=0; */
        APP_FluxWeak_GEAR2_DW.BlockState = 0.0F;

        /* Transition: '<S33>:20' */
        /* Transition: '<S33>:12' */
      } else {
        /* Transition: '<S33>:15' */
        /* '<S33>:8:1' sf_internal_predicateOutput = ... */
        /* '<S33>:8:1' Spd<=10; */
        if (rtb_Switch_b <= 10.0F) {
          /* Transition: '<S33>:8' */
          /* Transition: '<S33>:10' */
          /* '<S33>:10:1' BlockState=BlockState+Is*0.02; */
          APP_FluxWeak_GEAR2_DW.BlockState += rt_hypotf_snf
            (Algo_Output.Cur_loop.Id, Algo_Output.Cur_loop.Iq) * 0.02F;

          /* Transition: '<S33>:12' */
        } else {
          /* Transition: '<S33>:13' */
        }
      }

      /* End of Chart: '<S19>/Chart' */

      /* RelationalOperator: '<S34>/Compare' incorporates:
       *  Constant: '<S34>/Constant'
       */
      APP_FluxWeak_GEAR2_DW.Compare = (APP_FluxWeak_GEAR2_DW.BlockState > 2.0F);
    }

    /* End of RelationalOperator: '<S21>/Compare' */
    /* End of Outputs for SubSystem: '<S15>/Block' */

    /* SignalConversion: '<S15>/BusConversion_InsertedFor_Fault_App_at_inport_0' incorporates:
     *  UnitDelay: '<S2>/Unit Delay'
     */
    rtb_UVWoffline = APP_FluxWeak_GEAR2_DW.UnitDelay_DSTATE;

    /* Logic: '<S20>/Logical Operator' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    rtb_LogicalOperator = ((PMSM_Input.AppComm.CanMsg1Lost != 0U) ||
      (PMSM_Input.AppComm.CanMsg2Lost != 0U));

    /* RelationalOperator: '<S22>/Compare' incorporates:
     *  Constant: '<S22>/Constant'
     */
    rtb_MultiportSwitch = (APP_FluxWeak_GEAR2_DW.tick == 3U);

    /* Outputs for Enabled SubSystem: '<S15>/DisChg' incorporates:
     *  EnablePort: '<S27>/Enable'
     */
    /* RelationalOperator: '<S26>/Compare' incorporates:
     *  Constant: '<S26>/Constant'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 7U) {
      /* Chart: '<S27>/Chart1' incorporates:
       *  Constant: '<S39>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read'
       *  RelationalOperator: '<S39>/Compare'
       */
      /* Gateway: implement/Fault/judgment/DisChg/Chart1 */
      /* During: implement/Fault/judgment/DisChg/Chart1 */
      /* Entry Internal: implement/Fault/judgment/DisChg/Chart1 */
      /* Transition: '<S38>:4' */
      /* '<S38>:14:1' sf_internal_predicateOutput = ... */
      /* '<S38>:14:1' ~ChgMode; */
      if (!(PMSM_Input.AppComm.ModeReq == 6U)) {
        /* Transition: '<S38>:14' */
        /* Transition: '<S38>:16' */
        /* '<S38>:16:1' DisChg_time=0; */
        APP_FluxWeak_GEAR2_DW.DisChg_time = 0.0F;

        /* SignalConversion: '<S27>/OutportBufferForDisChg' */
        /* '<S38>:16:1' ChgCode=0; */
        APP_FluxWeak_GEAR2_DW.OutportBufferForDisChg = 0UL;

        /* Transition: '<S38>:31' */
        /* Transition: '<S38>:32' */
        /* Transition: '<S38>:33' */
      } else {
        /* Transition: '<S38>:18' */
        /* '<S38>:20:1' sf_internal_predicateOutput = ... */
        /* '<S38>:20:1' VoltCap>=36; */
        if (DiscreteTimeIntegrator1_i4 >= 36.0F) {
          /* Transition: '<S38>:20' */
          /* Transition: '<S38>:22' */
          /* '<S38>:22:1' DisChg_time=DisChg_time+0.02; */
          APP_FluxWeak_GEAR2_DW.DisChg_time += 0.02F;

          /* '<S38>:25:1' sf_internal_predicateOutput = ... */
          /* '<S38>:25:1' DisChg_time>=5; */
          if (APP_FluxWeak_GEAR2_DW.DisChg_time >= 5.0F) {
            /* SignalConversion: '<S27>/OutportBufferForDisChg' */
            /* Transition: '<S38>:25' */
            /* Transition: '<S38>:30' */
            /* '<S38>:30:1' ChgCode=1; */
            APP_FluxWeak_GEAR2_DW.OutportBufferForDisChg = 1UL;

            /* Transition: '<S38>:32' */
            /* Transition: '<S38>:33' */
          } else {
            /* SignalConversion: '<S27>/OutportBufferForDisChg' */
            /* Transition: '<S38>:27' */
            /* '<S38>:27:1' ChgCode=0; */
            APP_FluxWeak_GEAR2_DW.OutportBufferForDisChg = 0UL;

            /* Transition: '<S38>:33' */
          }
        } else {
          /* Transition: '<S38>:34' */
          /* '<S38>:34:1' DisChg_time=0; */
          APP_FluxWeak_GEAR2_DW.DisChg_time = 0.0F;

          /* SignalConversion: '<S27>/OutportBufferForDisChg' */
          /* '<S38>:34:1' ChgCode=0; */
          APP_FluxWeak_GEAR2_DW.OutportBufferForDisChg = 0UL;
        }
      }

      /* End of Chart: '<S27>/Chart1' */
    }

    /* End of RelationalOperator: '<S26>/Compare' */
    /* End of Outputs for SubSystem: '<S15>/DisChg' */

    /* Outputs for Enabled SubSystem: '<S15>/Spd' incorporates:
     *  EnablePort: '<S29>/Enable'
     */
    /* RelationalOperator: '<S23>/Compare' incorporates:
     *  Constant: '<S23>/Constant'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 4U) {
      /* Abs: '<S29>/Abs' */
      rtb_Switch_b = fabsf(DiscreteTimeIntegrator1);

      /* Chart: '<S29>/Chart1' incorporates:
       *  Abs: '<S29>/Abs'
       */
      /* Gateway: implement/Fault/judgment/Spd/Chart1 */
      /* During: implement/Fault/judgment/Spd/Chart1 */
      /* Entry Internal: implement/Fault/judgment/Spd/Chart1 */
      /* Transition: '<S40>:15' */
      /* '<S40>:17:1' sf_internal_predicateOutput = ... */
      /* '<S40>:17:1' SpdCode(2); */
      if ((APP_FluxWeak_GEAR2_DW.SpdCode_o[1] != 0UL) || (!(rtb_Switch_b >
            PMSM_Param.OS2))) {
        /* Transition: '<S40>:17' */
        /* Transition: '<S40>:78' */
        /* Transition: '<S40>:79' */
        /* Transition: '<S40>:51' */
        /* '<S40>:66:1' sf_internal_predicateOutput = ... */
        /* '<S40>:66:1' SpdCode(1); */
        if (APP_FluxWeak_GEAR2_DW.SpdCode_o[0] != 0UL) {
          /* Transition: '<S40>:66' */
          /* '<S40>:68:1' sf_internal_predicateOutput = ... */
          /* '<S40>:68:1' NmFil<=PMSM_Param.OS1-100; */
          if (rtb_Switch_b <= PMSM_Param.OS1 - 100.0F) {
            /* Transition: '<S40>:68' */
            /* Transition: '<S40>:70' */
            /* '<S40>:70:1' SpdCode(1)=0; */
            APP_FluxWeak_GEAR2_DW.SpdCode_o[0] = 0UL;

            /* Transition: '<S40>:72' */
            /* Transition: '<S40>:76' */
            /* Transition: '<S40>:45' */
          } else {
            /* Transition: '<S40>:73' */
            /* Transition: '<S40>:76' */
            /* Transition: '<S40>:45' */
          }
        } else {
          /* Transition: '<S40>:52' */
          /* '<S40>:40:1' sf_internal_predicateOutput = ... */
          /* '<S40>:40:1' NmFil>PMSM_Param.OS1; */
          if (rtb_Switch_b > PMSM_Param.OS1) {
            /* Transition: '<S40>:40' */
            /* Transition: '<S40>:42' */
            /* '<S40>:42:1' SpdCode(1)=1; */
            APP_FluxWeak_GEAR2_DW.SpdCode_o[0] = 1UL;

            /* Transition: '<S40>:45' */
          } else {
            /* Transition: '<S40>:44' */
          }
        }
      } else {
        /* Transition: '<S40>:21' */
        /* '<S40>:33:1' sf_internal_predicateOutput = ... */
        /* '<S40>:33:1' NmFil>PMSM_Param.OS2; */
        /* Transition: '<S40>:33' */
        /* Transition: '<S40>:35' */
        /* '<S40>:35:1' SpdCode(1)=0; */
        APP_FluxWeak_GEAR2_DW.SpdCode_o[0] = 0UL;

        /* '<S40>:35:1' SpdCode(2)=1; */
        APP_FluxWeak_GEAR2_DW.SpdCode_o[1] = 1UL;

        /* Transition: '<S40>:75' */
        /* Transition: '<S40>:72' */
        /* Transition: '<S40>:76' */
        /* Transition: '<S40>:45' */
      }

      /* End of Chart: '<S29>/Chart1' */

      /* SignalConversion: '<S29>/BusConversion_InsertedFor_Spd_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.SpdCode[0] = APP_FluxWeak_GEAR2_DW.SpdCode_o[0];
      APP_FluxWeak_GEAR2_DW.SpdCode[1] = APP_FluxWeak_GEAR2_DW.SpdCode_o[1];

      /* Logic: '<S29>/Logical Operator' */
      rtb_LogicalOperator_f = !(APP_FluxWeak_GEAR2_DW.SpdCode_o[0] != 0UL);

      /* RateLimiter: '<S29>/Rate Limiter' incorporates:
       *  DataTypeConversion: '<S29>/Data Type Conversion'
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

      /* End of RateLimiter: '<S29>/Rate Limiter' */

      /* Switch: '<S29>/Switch' incorporates:
       *  Constant: '<S29>/Constant'
       *  Constant: '<S29>/Constant1'
       *  Gain: '<S29>/Gain1'
       */
      if (DiscreteTimeIntegrator1 >= 0.0F) {
        rtb_Switch_nd[0] = APP_FluxWeak_GEAR2_DW.PrevY;
        rtb_Switch_nd[1] = -1.0F;
      } else {
        rtb_Switch_nd[0] = 1.0F;
        rtb_Switch_nd[1] = -APP_FluxWeak_GEAR2_DW.PrevY;
      }

      /* End of Switch: '<S29>/Switch' */

      /* SignalConversion: '<S29>/BusConversion_InsertedFor_Spd_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.OSLimTP = rtb_Switch_nd[0];

      /* SignalConversion: '<S29>/BusConversion_InsertedFor_Spd_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.OSLimTN = rtb_Switch_nd[1];
    }

    /* End of RelationalOperator: '<S23>/Compare' */
    /* End of Outputs for SubSystem: '<S15>/Spd' */

    /* Outputs for Enabled SubSystem: '<S15>/TempSensor' incorporates:
     *  EnablePort: '<S31>/Enable'
     */
    /* RelationalOperator: '<S24>/Compare' incorporates:
     *  Constant: '<S24>/Constant'
     *  Constant: '<S50>/Constant'
     *  Constant: '<S50>/Constant1'
     *  Constant: '<S51>/Constant'
     *  Constant: '<S51>/Constant1'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 5U) {
      /* Logic: '<S31>/Logical Operator1' incorporates:
       *  Constant: '<S45>/Constant'
       *  Constant: '<S46>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read'
       *  RelationalOperator: '<S45>/Compare'
       *  RelationalOperator: '<S46>/Compare'
       */
      APP_FluxWeak_GEAR2_DW.LogicalOperator1[0] = (uint32_T)
        ((PMSM_Input.AppSample.MotTemp1 < -50.0F) ||
         (PMSM_Input.AppSample.MotTemp1 > 180.0F));
      APP_FluxWeak_GEAR2_DW.LogicalOperator1[1] = (uint32_T)
        ((PMSM_Input.AppSample.MotTemp2 < -50.0F) ||
         (PMSM_Input.AppSample.MotTemp2 > 180.0F));

      /* SignalConversion: '<S42>/TmpSignal ConversionAt SFunction Inport2' incorporates:
       *  Chart: '<S31>/Chart1'
       *  DataStoreRead: '<Root>/Data Store Read'
       */
      rtb_Switch_nd[0] = PMSM_Input.AppSample.MotTemp1;
      rtb_Switch_nd[1] = PMSM_Input.AppSample.MotTemp2;

      /* Chart: '<S31>/Chart1' */
      /* Gateway: implement/Fault/judgment/TempSensor/Chart1 */
      /* During: implement/Fault/judgment/TempSensor/Chart1 */
      /* Entry Internal: implement/Fault/judgment/TempSensor/Chart1 */
      /* Transition: '<S42>:26' */
      /* Transition: '<S42>:29' */
      /* '<S42>:29:1' ii=1; */
      /* '<S42>:27:1' sf_internal_predicateOutput = ... */
      /* '<S42>:27:1' ii<3; */
      for (ii = 1U; (int16_T)ii < 3; ii++) {
        /* Transition: '<S42>:27' */
        /* '<S42>:40:1' sf_internal_predicateOutput = ... */
        /* '<S42>:40:1' id(ii); */
        i = (int16_T)ii - 1;
        if (APP_FluxWeak_GEAR2_DW.LogicalOperator1[i] != 0UL) {
          /* Transition: '<S42>:40' */
          /* Transition: '<S42>:42' */
          /* '<S42>:42:1' out(ii)=-50; */
          APP_FluxWeak_GEAR2_DW.out_e[i] = -50.0F;

          /* Transition: '<S42>:44' */
        } else {
          /* Transition: '<S42>:43' */
          /* '<S42>:43:1' out(ii)=Temp(ii); */
          APP_FluxWeak_GEAR2_DW.out_e[i] = rtb_Switch_nd[i];
        }

        /* Transition: '<S42>:30' */
        /* '<S42>:30:1' ii=ii+1; */
      }

      /* Logic: '<S31>/Logical Operator2' incorporates:
       *  Constant: '<S47>/Constant'
       *  Constant: '<S48>/Constant'
       *  DataStoreRead: '<Root>/Data Store Read'
       *  RelationalOperator: '<S47>/Compare'
       *  RelationalOperator: '<S48>/Compare'
       */
      /* Transition: '<S42>:31' */
      APP_FluxWeak_GEAR2_DW.LogicalOperator2[0] = (uint32_T)
        ((PMSM_Input.AppSample.InvTemp1 < -50.0F) ||
         (PMSM_Input.AppSample.InvTemp1 > 120.0F));
      APP_FluxWeak_GEAR2_DW.LogicalOperator2[1] = (uint32_T)
        ((PMSM_Input.AppSample.InvTemp2 < -50.0F) ||
         (PMSM_Input.AppSample.InvTemp2 > 120.0F));
      APP_FluxWeak_GEAR2_DW.LogicalOperator2[2] = (uint32_T)
        ((PMSM_Input.AppSample.InvTemp3 < -50.0F) ||
         (PMSM_Input.AppSample.InvTemp3 > 120.0F));

      /* SignalConversion: '<S43>/TmpSignal ConversionAt SFunction Inport2' incorporates:
       *  Chart: '<S31>/Chart2'
       *  DataStoreRead: '<Root>/Data Store Read'
       */
      rtb_TmpSignalConversionAtSFunct[0] = PMSM_Input.AppSample.InvTemp1;
      rtb_TmpSignalConversionAtSFunct[1] = PMSM_Input.AppSample.InvTemp2;
      rtb_TmpSignalConversionAtSFunct[2] = PMSM_Input.AppSample.InvTemp3;

      /* Chart: '<S31>/Chart2' */
      /* Gateway: implement/Fault/judgment/TempSensor/Chart2 */
      /* During: implement/Fault/judgment/TempSensor/Chart2 */
      /* Entry Internal: implement/Fault/judgment/TempSensor/Chart2 */
      /* Transition: '<S43>:26' */
      /* Transition: '<S43>:29' */
      /* '<S43>:29:1' ii=1; */
      /* '<S43>:27:1' sf_internal_predicateOutput = ... */
      /* '<S43>:27:1' ii<4; */
      for (ii = 1U; (int16_T)ii < 4; ii++) {
        /* Transition: '<S43>:27' */
        /* '<S43>:40:1' sf_internal_predicateOutput = ... */
        /* '<S43>:40:1' id(ii); */
        i = (int16_T)ii - 1;
        if (APP_FluxWeak_GEAR2_DW.LogicalOperator2[i] != 0UL) {
          /* Transition: '<S43>:40' */
          /* Transition: '<S43>:42' */
          /* '<S43>:42:1' out(ii)=-50; */
          APP_FluxWeak_GEAR2_DW.out[i] = -50.0F;

          /* Transition: '<S43>:44' */
        } else {
          /* Transition: '<S43>:43' */
          /* '<S43>:43:1' out(ii)=Temp(ii); */
          APP_FluxWeak_GEAR2_DW.out[i] = rtb_TmpSignalConversionAtSFunct[i];
        }

        /* Transition: '<S43>:30' */
        /* '<S43>:30:1' ii=ii+1; */
      }

      /* Switch: '<S31>/Switch' incorporates:
       *  Constant: '<S31>/Constant4'
       *  Constant: '<S49>/Constant'
       *  MinMax: '<S31>/MinMax2'
       *  RelationalOperator: '<S49>/Compare'
       *  Sum: '<S31>/Sum of Elements'
       */
      /* Transition: '<S43>:31' */
      if (APP_FluxWeak_GEAR2_DW.LogicalOperator1[0] +
          APP_FluxWeak_GEAR2_DW.LogicalOperator1[1] == 2UL) {
        rtb_Switch_b = 200.0F;
      } else {
        rtb_Switch_b = fmaxf(APP_FluxWeak_GEAR2_DW.out_e[0],
                             APP_FluxWeak_GEAR2_DW.out_e[1L]);
      }

      /* End of Switch: '<S31>/Switch' */

      /* Outputs for Atomic SubSystem: '<S50>/lpf' */
      LPF_App(rtb_Switch_b, 0.02F, 10.0F,
              &APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c,
              &APP_FluxWeak_GEAR2_DW.lpf_e);

      /* End of Outputs for SubSystem: '<S50>/lpf' */

      /* Switch: '<S31>/Switch1' incorporates:
       *  Constant: '<S31>/Constant7'
       *  Constant: '<S44>/Constant'
       *  Constant: '<S50>/Constant'
       *  Constant: '<S50>/Constant1'
       *  MinMax: '<S31>/MinMax1'
       *  RelationalOperator: '<S44>/Compare'
       *  Sum: '<S31>/Sum of Elements1'
       */
      if ((APP_FluxWeak_GEAR2_DW.LogicalOperator2[0] +
           APP_FluxWeak_GEAR2_DW.LogicalOperator2[1]) +
          APP_FluxWeak_GEAR2_DW.LogicalOperator2[2] == 3UL) {
        rtb_Switch_b = 200.0F;
      } else {
        rtb_Switch_b = fmaxf(fmaxf(APP_FluxWeak_GEAR2_DW.out[0],
          APP_FluxWeak_GEAR2_DW.out[1L]), APP_FluxWeak_GEAR2_DW.out[2L]);
      }

      /* End of Switch: '<S31>/Switch1' */

      /* Outputs for Atomic SubSystem: '<S51>/lpf' */
      LPF_App(rtb_Switch_b, 0.02F, 10.0F,
              &APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a,
              &APP_FluxWeak_GEAR2_DW.lpf_i);

      /* End of Outputs for SubSystem: '<S51>/lpf' */
    }

    /* End of RelationalOperator: '<S24>/Compare' */
    /* End of Outputs for SubSystem: '<S15>/TempSensor' */

    /* Outputs for Enabled SubSystem: '<S15>/Temp' incorporates:
     *  EnablePort: '<S30>/Enable'
     */
    /* RelationalOperator: '<S25>/Compare' incorporates:
     *  Constant: '<S25>/Constant'
     */
    if (APP_FluxWeak_GEAR2_DW.tick == 6U) {
      /* Chart: '<S30>/Chart' */
      /* Gateway: implement/Fault/judgment/Temp/Chart */
      /* During: implement/Fault/judgment/Temp/Chart */
      /* Entry Internal: implement/Fault/judgment/Temp/Chart */
      /* Transition: '<S41>:54' */
      /* '<S41>:56:1' sf_internal_predicateOutput = ... */
      /* '<S41>:56:1' TempCode(3); */
      if (APP_FluxWeak_GEAR2_DW.TempCode_g[2] == 0UL) {
        /* Transition: '<S41>:60' */
        /* '<S41>:62:1' sf_internal_predicateOutput = ... */
        /* '<S41>:62:1' MotTemp>PMSM_Param.MotOT3; */
        if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c > PMSM_Param.MotOT3)
        {
          /* Transition: '<S41>:62' */
          /* Transition: '<S41>:64' */
          /* '<S41>:64:1' TempCode(1)=0; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[0] = 0UL;

          /* '<S41>:64:1' TempCode(2)=0; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[1] = 0UL;

          /* '<S41>:64:1' TempCode(3)=1; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[2] = 1UL;

          /* 电机三级 */
          /* Transition: '<S41>:78' */
          /* Transition: '<S41>:79' */
          /* Transition: '<S41>:80' */
        } else {
          /* Transition: '<S41>:66' */
          /* '<S41>:68:1' sf_internal_predicateOutput = ... */
          /* '<S41>:68:1' MotTemp>PMSM_Param.MotOT2; */
          if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c >
              PMSM_Param.MotOT2) {
            /* Transition: '<S41>:68' */
            /* Transition: '<S41>:70' */
            /* '<S41>:70:1' TempCode(1)=0; */
            APP_FluxWeak_GEAR2_DW.TempCode_g[0] = 0UL;

            /* '<S41>:70:1' TempCode(2)=1; */
            APP_FluxWeak_GEAR2_DW.TempCode_g[1] = 1UL;

            /* 电机二级 */
            /* Transition: '<S41>:79' */
            /* Transition: '<S41>:80' */
          } else {
            /* Transition: '<S41>:72' */
            /* '<S41>:74:1' sf_internal_predicateOutput = ... */
            /* '<S41>:74:1' MotTemp>PMSM_Param.MotOT1; */
            if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c >
                PMSM_Param.MotOT1) {
              /* Transition: '<S41>:74' */
              /* Transition: '<S41>:76' */
              /* '<S41>:76:1' TempCode(1)=1; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[0] = 1UL;

              /* '<S41>:76:1' TempCode(2)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[1] = 0UL;

              /* 电机一级 */
              /* Transition: '<S41>:80' */
            } else {
              /* Transition: '<S41>:81' */
              /* '<S41>:81:1' TempCode(1)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[0] = 0UL;

              /* '<S41>:81:1' TempCode(2)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[1] = 0UL;
            }
          }
        }
      } else {
        /* Transition: '<S41>:56' */
        /* Transition: '<S41>:58' */
        /* Transition: '<S41>:113' */
      }

      /* Transition: '<S41>:112' */
      /* '<S41>:83:1' sf_internal_predicateOutput = ... */
      /* '<S41>:83:1' TempCode(6); */
      if (APP_FluxWeak_GEAR2_DW.TempCode_g[5] == 0UL) {
        /* Transition: '<S41>:87' */
        /* '<S41>:97:1' sf_internal_predicateOutput = ... */
        /* '<S41>:97:1' InvTemp>PMSM_Param.InvOT3; */
        if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a > PMSM_Param.InvOT3)
        {
          /* Transition: '<S41>:97' */
          /* Transition: '<S41>:94' */
          /* '<S41>:94:1' TempCode(4)=0; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[3] = 0UL;

          /* '<S41>:94:1' TempCode(5)=0; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[4] = 0UL;

          /* '<S41>:94:1' TempCode(6)=1; */
          APP_FluxWeak_GEAR2_DW.TempCode_g[5] = 1UL;

          /* 控制器三级 */
          /* Transition: '<S41>:103' */
          /* Transition: '<S41>:86' */
          /* Transition: '<S41>:110' */
        } else {
          /* Transition: '<S41>:98' */
          /* '<S41>:89:1' sf_internal_predicateOutput = ... */
          /* '<S41>:89:1' InvTemp>PMSM_Param.InvOT2; */
          if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a >
              PMSM_Param.InvOT2) {
            /* Transition: '<S41>:89' */
            /* Transition: '<S41>:100' */
            /* '<S41>:100:1' TempCode(4)=0; */
            APP_FluxWeak_GEAR2_DW.TempCode_g[3] = 0UL;

            /* '<S41>:100:1' TempCode(5)=1; */
            APP_FluxWeak_GEAR2_DW.TempCode_g[4] = 1UL;

            /* 控制器二级 */
            /* Transition: '<S41>:86' */
            /* Transition: '<S41>:110' */
          } else {
            /* Transition: '<S41>:85' */
            /* '<S41>:105:1' sf_internal_predicateOutput = ... */
            /* '<S41>:105:1' InvTemp>PMSM_Param.InvOT1; */
            if (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a >
                PMSM_Param.InvOT1) {
              /* Transition: '<S41>:105' */
              /* Transition: '<S41>:104' */
              /* '<S41>:104:1' TempCode(4)=1; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[3] = 1UL;

              /* '<S41>:104:1' TempCode(5)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[4] = 0UL;

              /* 控制器一级 */
              /* Transition: '<S41>:110' */
            } else {
              /* Transition: '<S41>:111' */
              /* '<S41>:111:1' TempCode(4)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[3] = 0UL;

              /* '<S41>:111:1' TempCode(5)=0; */
              APP_FluxWeak_GEAR2_DW.TempCode_g[4] = 0UL;
            }
          }
        }
      } else {
        /* Transition: '<S41>:83' */
        /* Transition: '<S41>:106' */
        /* Transition: '<S41>:114' */
      }

      /* End of Chart: '<S30>/Chart' */

      /* SignalConversion: '<S30>/BusConversion_InsertedFor_Temp_at_inport_0' */
      for (i = 0; i < 6; i++) {
        APP_FluxWeak_GEAR2_DW.TempCode[i] = APP_FluxWeak_GEAR2_DW.TempCode_g[i];
      }

      /* End of SignalConversion: '<S30>/BusConversion_InsertedFor_Temp_at_inport_0' */

      /* FunctionCaller: '<S30>/Function Caller' incorporates:
       *  Constant: '<S30>/Constant'
       *  Constant: '<S30>/Constant1'
       */
      APP_FluxWeak_GEAR2_Lim_coef
        (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c, PMSM_Param.MotOT1,
         PMSM_Param.MotOT2, &rtb_InvCoef);

      /* SignalConversion: '<S30>/BusConversion_InsertedFor_Temp_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.MotCoef = rtb_InvCoef;

      /* FunctionCaller: '<S30>/Function Caller1' incorporates:
       *  Constant: '<S30>/Constant2'
       *  Constant: '<S30>/Constant3'
       */
      APP_FluxWeak_GEAR2_Lim_coef
        (APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a, PMSM_Param.InvOT1,
         PMSM_Param.InvOT2, &rtb_InvCoef);

      /* SignalConversion: '<S30>/BusConversion_InsertedFor_Temp_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.InvCoef = rtb_InvCoef;
    }

    /* End of RelationalOperator: '<S25>/Compare' */
    /* End of Outputs for SubSystem: '<S15>/Temp' */

    /* Outputs for Enabled SubSystem: '<S15>/Volt' incorporates:
     *  EnablePort: '<S32>/Enable'
     */
    if (rtb_MultiportSwitch) {
      /* Chart: '<S32>/Chart3' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read'
       */
      /* Gateway: implement/Fault/judgment/Volt/Chart3 */
      /* During: implement/Fault/judgment/Volt/Chart3 */
      /* Entry Internal: implement/Fault/judgment/Volt/Chart3 */
      /* Transition: '<S54>:39' */
      /* '<S54>:41:1' sf_internal_predicateOutput = ... */
      /* '<S54>:41:1' VoltCapFil<PMSM_Param.OV1; */
      if (DiscreteTimeIntegrator1_i4 < PMSM_Param.OV1) {
        /* Transition: '<S54>:41' */
        /* Transition: '<S54>:43' */
        /* '<S54>:43:1' Chg_coef=1; */
        rtb_InvCoef = 1.0F;

        /* '<S54>:43:1' VoltCode(1)=0; */
        APP_FluxWeak_GEAR2_DW.VoltCode_m[0] = 0UL;

        /* '<S54>:43:1' VoltCode(2)=0; */
        APP_FluxWeak_GEAR2_DW.VoltCode_m[1] = 0UL;

        /* '<S54>:65:1' sf_internal_predicateOutput = ... */
        /* '<S54>:65:1' ~MainRelayState; */
        if (PMSM_Input.AppComm.MainRelayState != 0U) {
          /* Transition: '<S54>:67' */
          /* '<S54>:69:1' sf_internal_predicateOutput = ... */
          /* '<S54>:69:1' VoltCapFil<PMSM_Param.LV2; */
          if (DiscreteTimeIntegrator1_i4 < PMSM_Param.LV2) {
            /* Transition: '<S54>:69' */
            /* Transition: '<S54>:71' */
            /* '<S54>:71:1' VoltCode(3)=0; */
            APP_FluxWeak_GEAR2_DW.VoltCode_m[2] = 0UL;

            /* '<S54>:71:1' VoltCode(4)=1; */
            APP_FluxWeak_GEAR2_DW.VoltCode_m[3] = 1UL;

            /* '<S54>:71:1' DisChg_coef=0; */
            APP_FluxWeak_GEAR2_DW.DisChg_coef = 0.0F;

            /* 欠压2 */
            /* Transition: '<S54>:81' */
            /* Transition: '<S54>:82' */
          } else {
            /* '<S54>:73:1' sf_internal_predicateOutput = ... */
            /* '<S54>:73:1' VoltCapFil<PMSM_Param.LV1; */
            if (DiscreteTimeIntegrator1_i4 < PMSM_Param.LV1) {
              /* Transition: '<S54>:73' */
              /* Transition: '<S54>:75' */
              /* '<S54>:75:1' VoltCode(3)=1; */
              APP_FluxWeak_GEAR2_DW.VoltCode_m[2] = 1UL;

              /* '<S54>:75:1' VoltCode(4)=0; */
              APP_FluxWeak_GEAR2_DW.VoltCode_m[3] = 0UL;

              /* '<S54>:75:1' DisChg_coef=Lim_coef(VoltCapFil,PMSM_Param.LV1,PMSM_Param.LV2); */
              APP_FluxWeak_GEAR2_Lim_coef(DiscreteTimeIntegrator1_i4,
                PMSM_Param.LV1, PMSM_Param.LV2,
                &APP_FluxWeak_GEAR2_DW.DisChg_coef);

              /* 欠压1 */
            } else {
              /* Transition: '<S54>:79' */
              /* '<S54>:79:1' DisChg_coef=1; */
              APP_FluxWeak_GEAR2_DW.DisChg_coef = 1.0F;

              /* '<S54>:79:1' VoltCode(3)=0; */
              APP_FluxWeak_GEAR2_DW.VoltCode_m[2] = 0UL;

              /* '<S54>:79:1' VoltCode(4)=0; */
              APP_FluxWeak_GEAR2_DW.VoltCode_m[3] = 0UL;

              /* Transition: '<S54>:82' */
            }
          }
        } else {
          /* Transition: '<S54>:65' */
          /* Transition: '<S54>:77' */
          /* Transition: '<S54>:80' */
          /* Transition: '<S54>:81' */
          /* Transition: '<S54>:82' */
        }

        /* Transition: '<S54>:83' */
      } else {
        /* Transition: '<S54>:45' */
        /* '<S54>:45:1' DisChg_coef=1; */
        APP_FluxWeak_GEAR2_DW.DisChg_coef = 1.0F;

        /* '<S54>:45:1' VoltCode(3)=0; */
        APP_FluxWeak_GEAR2_DW.VoltCode_m[2] = 0UL;

        /* '<S54>:45:1' VoltCode(4)=0; */
        APP_FluxWeak_GEAR2_DW.VoltCode_m[3] = 0UL;

        /* '<S54>:47:1' sf_internal_predicateOutput = ... */
        /* '<S54>:47:1' VoltCapFil>PMSM_Param.OV2; */
        if (DiscreteTimeIntegrator1_i4 > PMSM_Param.OV2) {
          /* Transition: '<S54>:47' */
          /* Transition: '<S54>:49' */
          /* '<S54>:49:1' VoltCode(1)=0; */
          APP_FluxWeak_GEAR2_DW.VoltCode_m[0] = 0UL;

          /* '<S54>:49:1' VoltCode(2)=1; */
          APP_FluxWeak_GEAR2_DW.VoltCode_m[1] = 1UL;

          /* '<S54>:49:1' Chg_coef=0; */
          rtb_InvCoef = 0.0F;

          /* 过压2 */
          /* Transition: '<S54>:53' */
        } else {
          /* Transition: '<S54>:51' */
          /* '<S54>:51:1' VoltCode(1)=1; */
          APP_FluxWeak_GEAR2_DW.VoltCode_m[0] = 1UL;

          /* '<S54>:51:1' VoltCode(2)=0; */
          APP_FluxWeak_GEAR2_DW.VoltCode_m[1] = 0UL;

          /* '<S54>:51:1' Chg_coef=Lim_coef(VoltCapFil,PMSM_Param.OV1,PMSM_Param.OV2); */
          APP_FluxWeak_GEAR2_Lim_coef(DiscreteTimeIntegrator1_i4, PMSM_Param.OV1,
            PMSM_Param.OV2, &rtb_InvCoef);

          /* 过压1 */
        }

        /* Transition: '<S54>:56' */
      }

      /* End of Chart: '<S32>/Chart3' */

      /* SignalConversion: '<S32>/BusConversion_InsertedFor_Volt_at_inport_0' */
      APP_FluxWeak_GEAR2_DW.VoltCode[0] = APP_FluxWeak_GEAR2_DW.VoltCode_m[0];
      APP_FluxWeak_GEAR2_DW.VoltCode[1] = APP_FluxWeak_GEAR2_DW.VoltCode_m[1];
      APP_FluxWeak_GEAR2_DW.VoltCode[2] = APP_FluxWeak_GEAR2_DW.VoltCode_m[2];
      APP_FluxWeak_GEAR2_DW.VoltCode[3] = APP_FluxWeak_GEAR2_DW.VoltCode_m[3];

      /* Relay: '<S32>/Relay' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read'
       */
      if (PMSM_Input.AgoSample.Speed >= 20.0F) {
        APP_FluxWeak_GEAR2_DW.Relay_Mode = true;
      } else {
        if (PMSM_Input.AgoSample.Speed <= -20.0F) {
          APP_FluxWeak_GEAR2_DW.Relay_Mode = false;
        }
      }

      /* End of Relay: '<S32>/Relay' */

      /* SignalConversion: '<S32>/BusConversion_InsertedFor_Volt_at_inport_0' incorporates:
       *  Switch: '<S32>/Switch'
       */
      APP_FluxWeak_GEAR2_DW.OVLimTP_g = APP_FluxWeak_GEAR2_DW.DisChg_coef;

      /* SignalConversion: '<S32>/BusConversion_InsertedFor_Volt_at_inport_0' incorporates:
       *  Gain: '<S32>/Gain'
       *  Switch: '<S32>/Switch'
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

      /* Sum: '<S17>/Difference Inputs1' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion'
       *  Logic: '<S11>/Logical Operator'
       *  UnitDelay: '<S17>/Delay Input2'
       *
       * Block description for '<S17>/Difference Inputs1':
       *
       *  Add in CPU
       *
       * Block description for '<S17>/Delay Input2':
       *
       *  Store in Global RAM
       */
      rtb_InvCoef = (real32_T)!(APP_FluxWeak_GEAR2_DW.Compare ||
        (APP_FluxWeak_GEAR2_DW.TempCode[1] != 0UL) ||
        (APP_FluxWeak_GEAR2_DW.TempCode[2] != 0UL) ||
        (APP_FluxWeak_GEAR2_DW.TempCode[4] != 0UL) ||
        (APP_FluxWeak_GEAR2_DW.TempCode[5] != 0UL) || ((uint16_T)
        rtb_LogicalOperator != 0U)) - APP_FluxWeak_GEAR2_DW.DelayInput2_DSTATE;

      /* Switch: '<S18>/Switch2' incorporates:
       *  RelationalOperator: '<S18>/LowerRelop1'
       *  RelationalOperator: '<S18>/UpperRelop'
       *  Switch: '<S18>/Switch'
       */
      if (rtb_InvCoef > 0.02F) {
        rtb_InvCoef = 0.02F;
      } else {
        if (rtb_InvCoef < -0.02F) {
          /* Switch: '<S18>/Switch' */
          rtb_InvCoef = -0.02F;
        }
      }

      /* End of Switch: '<S18>/Switch2' */

      /* Sum: '<S17>/Difference Inputs2' incorporates:
       *  UnitDelay: '<S17>/Delay Input2'
       *
       * Block description for '<S17>/Difference Inputs2':
       *
       *  Add in CPU
       *
       * Block description for '<S17>/Delay Input2':
       *
       *  Store in Global RAM
       */
      APP_FluxWeak_GEAR2_DW.DelayInput2_DSTATE += rtb_InvCoef;

      /* DataStoreWrite: '<S11>/Data Store Write2' incorporates:
       *  UnitDelay: '<S17>/Delay Input2'
       *
       * Block description for '<S17>/Delay Input2':
       *
       *  Store in Global RAM
       */
      AppFun.FaultCoef = APP_FluxWeak_GEAR2_DW.DelayInput2_DSTATE;

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

      /* MinMax: '<S11>/MinMax' incorporates:
       *  UnitDelay: '<S17>/Delay Input2'
       *
       * Block description for '<S17>/Delay Input2':
       *
       *  Store in Global RAM
       */
      /* Transition: '<S16>:16' */
      APP_FluxWeak_GEAR2_DW.MinMax = fminf(fminf
        (APP_FluxWeak_GEAR2_DW.DelayInput2_DSTATE, APP_FluxWeak_GEAR2_DW.MotCoef),
        APP_FluxWeak_GEAR2_DW.InvCoef);
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
      /* SystemReset for Atomic SubSystem: '<S144>/LimDrv' */

      /* SystemReset for Chart: '<S158>/Chart' */
      APP_FluxWeak_GEAR2_Chart_Reset(&APP_FluxWeak_GEAR2_DW.sf_Chart_c);

      /* End of SystemReset for SubSystem: '<S144>/LimDrv' */

      /* SystemReset for Atomic SubSystem: '<S144>/LimChg' */

      /* SystemReset for Chart: '<S152>/Chart' */
      APP_FluxWeak_GEAR2_Chart_Reset(&APP_FluxWeak_GEAR2_DW.sf_Chart_lj);

      /* End of SystemReset for SubSystem: '<S144>/LimChg' */

      /* SystemReset for Chart: '<S144>/Chart1' */
      APP_FluxWeak_GEAR2_DW.is_active_c20_APP_FluxWeak_GEAR = 0U;
      APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
        APP_FluxWe_IN_NO_ACTIVE_CHILD_c;

      /* SystemReset for Chart: '<S56>/Chart' */
      APP_FluxWeak_GEAR2_DW.temporalCounter_i1 = 0U;
      APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
      APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
      APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWe_IN_NO_ACTIVE_CHILD_c;
      APP_FluxWeak_GEAR2_DW.is_active_c2_APP_FluxWeak_GEAR2 = 0U;
      APP_FluxWeak_GEAR2_DW.is_c2_APP_FluxWeak_GEAR2 =
        APP_FluxWe_IN_NO_ACTIVE_CHILD_c;

      /* Enable for Chart: '<S56>/Chart' incorporates:
       *  SubSystem: '<S56>/Slope'
       */
      APP_FluxWeak_GEAR2_Slope_Enable(&APP_FluxWeak_GEAR2_DW.Slope);

      /* SystemReset for Function Call SubSystem: '<S56>/Calib' */
      APP_FluxWeak_GEAR2_Calib_Reset(&APP_FluxWeak_GEAR2_DW.Calib);

      /* End of SystemReset for SubSystem: '<S56>/Calib' */

      /* Enable for Chart: '<S56>/Chart' incorporates:
       *  SubSystem: '<S56>/Calib'
       */
      APP_FluxWeak_GEAR2_Calib_Enable(&APP_FluxWeak_GEAR2_DW.Calib);
      if ((int16_T)APP_FluxWeak_GEAR2_DW.is_c2_APP_FluxWeak_GEAR2 == (int16_T)
          APP_FluxWeak_GEAR2_IN_UVWcheck) {
        /* SystemReset for Function Call SubSystem: '<S56>/UVW_check' */
        APP_FluxWeak_GE_UVW_check_Reset(&APP_FluxWeak_GEAR2_DW.UVW_check);

        /* End of SystemReset for SubSystem: '<S56>/UVW_check' */
      }

      APP_FluxWeak_GEAR2_DW.method_MODE = true;
    }

    /* Gain: '<S143>/Gain' */
    rtb_InvCoef = -APP_FluxWeak_GEAR2_DW.LimtCoef;

    /* DeadZone: '<S144>/Dead Zone' */
    if (DiscreteTimeIntegrator1 > 20.0F) {
      rtb_Switch_b = DiscreteTimeIntegrator1 - 20.0F;
    } else if (DiscreteTimeIntegrator1 >= -20.0F) {
      rtb_Switch_b = 0.0F;
    } else {
      rtb_Switch_b = DiscreteTimeIntegrator1 - -20.0F;
    }

    /* End of DeadZone: '<S144>/Dead Zone' */

    /* Outputs for Atomic SubSystem: '<S144>/LimDrv' */
    /* Abs: '<S157>/Abs' */
    rtb_Abs_l = fabsf(DiscreteTimeIntegrator1);

    /* Lookup_n-D: '<S157>/table' incorporates:
     *  Abs: '<S157>/Abs'
     */
    bpIdx = plook_u32ff_evenca(rtb_Abs_l, 1000.0F, 500.0F, 7UL, &rtb_Divide_p);
    rtb_Add_j = intrp1d_fu32fla_pw(bpIdx, rtb_Divide_p, rtCP_table_tableData_o,
      7UL);

    /* Saturate: '<S157>/Saturation1' incorporates:
     *  Abs: '<S157>/Abs'
     */
    if (rtb_Abs_l > 100000.0F) {
      rtb_Abs_l = 100000.0F;
    } else {
      if (rtb_Abs_l < 1.0F) {
        rtb_Abs_l = 1.0F;
      }
    }

    /* End of Saturate: '<S157>/Saturation1' */

    /* Product: '<S157>/Divide' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     *  Gain: '<S157>/Gain'
     *  Product: '<S157>/Product'
     */
    rtb_Divide_p = DiscreteTimeIntegrator1_i4 * PMSM_Input.AppComm.DrvLimCur *
      9.55F * rtb_Add_j / rtb_Abs_l;

    /* FunctionCaller: '<S157>/Function Caller' */
    APP_FluxWeak_GEAR2_n2MaxT(rtb_Psi_i, &rtb_Add_j);

    /* Product: '<S157>/Divide1' */
    rtb_Add_j = rtb_Divide_p / rtb_Add_j;

    /* Chart: '<S158>/Chart' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     *  Sum: '<S150>/Sum'
     */
    APP_FluxWeak_GEAR2_Chart(PMSM_Input.AppComm.DrvLimCur -
      rtb_DiscreteTimeIntegrator1, &rtb_Divide_p,
      &APP_FluxWeak_GEAR2_DW.sf_Chart_c);

    /* Saturate: '<S157>/Saturation' */
    if (rtb_Add_j > 1.0F) {
      rtb_Add_j = 1.0F;
    } else {
      if (rtb_Add_j < 0.0F) {
        rtb_Add_j = 0.0F;
      }
    }

    /* End of Saturate: '<S157>/Saturation' */

    /* Sum: '<S150>/Add' */
    rtb_Add_j += rtb_Divide_p;

    /* Saturate: '<S150>/Saturation' */
    if (rtb_Add_j > 1.0F) {
      rtb_Add_j = 1.0F;
    } else {
      if (rtb_Add_j < 0.0F) {
        rtb_Add_j = 0.0F;
      }
    }

    /* End of Saturate: '<S150>/Saturation' */
    /* End of Outputs for SubSystem: '<S144>/LimDrv' */

    /* Outputs for Atomic SubSystem: '<S144>/LimChg' */
    /* Abs: '<S149>/Abs' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read'
     */
    rtb_Abs_l = fabsf(PMSM_Input.AppComm.GenLimCur);

    /* Abs: '<S151>/Abs' */
    rtb_Divide_o = fabsf(DiscreteTimeIntegrator1);

    /* Lookup_n-D: '<S151>/table' incorporates:
     *  Abs: '<S151>/Abs'
     */
    bpIdx = plook_u32ff_evenca(rtb_Divide_o, 1400.0F, 200.0F, 2UL, &rtb_Divide_p);
    rtb_Divide_p = intrp1d_fu32fla_pw(bpIdx, rtb_Divide_p, rtCP_table_tableData,
      2UL);

    /* Saturate: '<S151>/Saturation1' incorporates:
     *  Abs: '<S151>/Abs'
     */
    if (rtb_Divide_o > 100000.0F) {
      rtb_Divide_o = 100000.0F;
    } else {
      if (rtb_Divide_o < 1.0F) {
        rtb_Divide_o = 1.0F;
      }
    }

    /* End of Saturate: '<S151>/Saturation1' */

    /* Product: '<S151>/Divide' incorporates:
     *  Gain: '<S151>/Gain'
     *  Product: '<S151>/Product'
     */
    rtb_Divide_o = DiscreteTimeIntegrator1_i4 * rtb_Abs_l * 9.55F / rtb_Divide_p
      / rtb_Divide_o;

    /* FunctionCaller: '<S151>/Function Caller' */
    APP_FluxWeak_GEAR2_n2MaxT(rtb_Psi_i, &rtb_Divide_p);

    /* Product: '<S151>/Divide1' */
    rtb_Divide_p = rtb_Divide_o / rtb_Divide_p;

    /* Chart: '<S152>/Chart' incorporates:
     *  Abs: '<S149>/Abs1'
     *  Sum: '<S149>/Sum'
     */
    APP_FluxWeak_GEAR2_Chart(rtb_Abs_l - fabsf(rtb_DiscreteTimeIntegrator1),
      &rtb_Divide_o, &APP_FluxWeak_GEAR2_DW.sf_Chart_lj);

    /* Saturate: '<S151>/Saturation' */
    if (rtb_Divide_p > 1.0F) {
      rtb_Divide_p = 1.0F;
    } else {
      if (rtb_Divide_p < 0.0F) {
        rtb_Divide_p = 0.0F;
      }
    }

    /* End of Saturate: '<S151>/Saturation' */

    /* Sum: '<S149>/Add' */
    rtb_Abs_l = rtb_Divide_p + rtb_Divide_o;

    /* Saturate: '<S149>/Saturation' */
    if (rtb_Abs_l > 1.0F) {
      rtb_Abs_l = 1.0F;
    } else {
      if (rtb_Abs_l < 0.0F) {
        rtb_Abs_l = 0.0F;
      }
    }

    /* End of Saturate: '<S149>/Saturation' */
    /* End of Outputs for SubSystem: '<S144>/LimChg' */

    /* Chart: '<S144>/Chart1' */
    /* Gateway: implement/method/Lim&Fault/LimI/Chart1 */
    /* During: implement/method/Lim&Fault/LimI/Chart1 */
    if (APP_FluxWeak_GEAR2_DW.is_active_c20_APP_FluxWeak_GEAR == 0U) {
      /* Entry: implement/method/Lim&Fault/LimI/Chart1 */
      APP_FluxWeak_GEAR2_DW.is_active_c20_APP_FluxWeak_GEAR = 1U;

      /* Entry Internal: implement/method/Lim&Fault/LimI/Chart1 */
      /* Transition: '<S148>:7' */
      APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
        APP_FluxWeak_GEAR2_IN_ZreoSpd;

      /* Entry 'ZreoSpd': '<S148>:6' */
      /* '<S148>:6:1' LimTP_I = DrvLimit; */
      rtb_Divide_p = rtb_Add_j;

      /* '<S148>:6:1' LimTN_I = -DrvLimit; */
      rtb_Add_j = -rtb_Add_j;
    } else {
      switch (APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2) {
       case APP_FluxWeak_GEAR2_IN_NegSpd:
        /* During 'NegSpd': '<S148>:20' */
        /* '<S148>:22:1' sf_internal_predicateOutput = ... */
        /* '<S148>:22:1' Spd >= 0; */
        if (rtb_Switch_b >= 0.0F) {
          /* Transition: '<S148>:22' */
          APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
            APP_FluxWeak_GEAR2_IN_ZreoSpd;

          /* Entry 'ZreoSpd': '<S148>:6' */
          /* '<S148>:6:1' LimTP_I = DrvLimit; */
          rtb_Divide_p = rtb_Add_j;

          /* '<S148>:6:1' LimTN_I = -DrvLimit; */
          rtb_Add_j = -rtb_Add_j;
        } else {
          /* '<S148>:20:1' LimTP_I = ChgLimit; */
          rtb_Divide_p = rtb_Abs_l;

          /* '<S148>:20:1' LimTN_I = -DrvLimit; */
          rtb_Add_j = -rtb_Add_j;
        }
        break;

       case APP_FluxWeak_GEAR2_IN_PosSpd:
        /* During 'PosSpd': '<S148>:18' */
        /* '<S148>:19:1' sf_internal_predicateOutput = ... */
        /* '<S148>:19:1' Spd <= 0; */
        if (rtb_Switch_b <= 0.0F) {
          /* Transition: '<S148>:19' */
          APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
            APP_FluxWeak_GEAR2_IN_ZreoSpd;

          /* Entry 'ZreoSpd': '<S148>:6' */
          /* '<S148>:6:1' LimTP_I = DrvLimit; */
          rtb_Divide_p = rtb_Add_j;

          /* '<S148>:6:1' LimTN_I = -DrvLimit; */
          rtb_Add_j = -rtb_Add_j;
        } else {
          /* '<S148>:18:1' LimTP_I = DrvLimit; */
          rtb_Divide_p = rtb_Add_j;

          /* '<S148>:18:1' LimTN_I = -ChgLimit; */
          rtb_Add_j = -rtb_Abs_l;
        }
        break;

       default:
        /* During 'ZreoSpd': '<S148>:6' */
        /* '<S148>:17:1' sf_internal_predicateOutput = ... */
        /* '<S148>:17:1' Spd > 0; */
        if (rtb_Switch_b > 0.0F) {
          /* Transition: '<S148>:17' */
          APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
            APP_FluxWeak_GEAR2_IN_PosSpd;

          /* Entry 'PosSpd': '<S148>:18' */
          /* '<S148>:18:1' LimTP_I = DrvLimit; */
          rtb_Divide_p = rtb_Add_j;

          /* '<S148>:18:1' LimTN_I = -ChgLimit; */
          rtb_Add_j = -rtb_Abs_l;
        } else {
          /* '<S148>:21:1' sf_internal_predicateOutput = ... */
          /* '<S148>:21:1' Spd < 0; */
          if (rtb_Switch_b < 0.0F) {
            /* Transition: '<S148>:21' */
            APP_FluxWeak_GEAR2_DW.is_c20_APP_FluxWeak_GEAR2 =
              APP_FluxWeak_GEAR2_IN_NegSpd;

            /* Entry 'NegSpd': '<S148>:20' */
            /* '<S148>:20:1' LimTP_I = ChgLimit; */
            rtb_Divide_p = rtb_Abs_l;

            /* '<S148>:20:1' LimTN_I = -DrvLimit; */
            rtb_Add_j = -rtb_Add_j;
          } else {
            /* '<S148>:6:1' LimTP_I = DrvLimit; */
            rtb_Divide_p = rtb_Add_j;

            /* '<S148>:6:1' LimTN_I = -DrvLimit; */
            rtb_Add_j = -rtb_Add_j;
          }
        }
        break;
      }
    }

    /* End of Chart: '<S144>/Chart1' */

    /* MinMax: '<S143>/MinMax2' */
    rtb_InvCoef = fmaxf(fmaxf(rtb_InvCoef, rtb_Add_j),
                        APP_FluxWeak_GEAR2_DW.OVLimTN);

    /* MinMax: '<S143>/MinMax1' */
    rtb_Abs_l = fminf(fminf(APP_FluxWeak_GEAR2_DW.OVLimTP, rtb_Divide_p),
                      APP_FluxWeak_GEAR2_DW.LimtCoef);

    /* Chart: '<S56>/Chart' incorporates:
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

      /* Outputs for Function Call SubSystem: '<S56>/Initial' */

      /* Entry Internal: implement/method/All_loop/Chart */
      /* Transition: '<S65>:84' */
      /* '<S65>:84:1' Initial; */
      /* Event: '<S65>:12' */
      APP_FluxWeak_GEAR2_Initial();

      /* End of Outputs for SubSystem: '<S56>/Initial' */
      APP_FluxWeak_GEAR2_DW.is_c2_APP_FluxWeak_GEAR2 =
        APP_FluxWeak_GEAR2_IN_UVWcheck;
      APP_FluxWeak_GEAR2_DW.temporalCounter_i1 = 0U;

      /* SystemReset for Function Call SubSystem: '<S56>/UVW_check' */

      /* Entry 'UVWcheck': '<S65>:86' */
      APP_FluxWeak_GE_UVW_check_Reset(&APP_FluxWeak_GEAR2_DW.UVW_check);

      /* End of SystemReset for SubSystem: '<S56>/UVW_check' */

      /* Outputs for Function Call SubSystem: '<S56>/UVW_check' */

      /* '<S65>:86:1' UVWcheck; */
      /* Event: '<S65>:87' */
      APP_FluxWeak_GEAR2_UVW_check(PMSM_Input.AgoSample.CurUPu,
        PMSM_Input.AgoSample.CurVPu, PMSM_Input.AgoSample.CurWPu,
        &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
        &APP_FluxWeak_GEAR2_DW.IqRefSet_m, &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
        &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d, &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
        &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
        &APP_FluxWeak_GEAR2_DW.OutportBufferForUVWFault,
        &APP_FluxWeak_GEAR2_DW.UVW_check);

      /* End of Outputs for SubSystem: '<S56>/UVW_check' */
    } else if (APP_FluxWeak_GEAR2_DW.is_c2_APP_FluxWeak_GEAR2 == 1U) {
      /* During 'UVWcheck': '<S65>:86' */
      /* '<S65>:88:1' sf_internal_predicateOutput = ... */
      /* '<S65>:88:1' after(250,tick); */
      if ((int16_T)APP_FluxWeak_GEAR2_DW.temporalCounter_i1 >= 250) {
        /* Transition: '<S65>:88' */
        /* Exit 'UVWcheck': '<S65>:86' */
        APP_FluxWeak_GEAR2_DW.is_c2_APP_FluxWeak_GEAR2 =
          APP_FluxWeak_GEAR2_IN_sys_mode;

        /* Outputs for Function Call SubSystem: '<S56>/Initial' */

        /* Entry Internal 'sys_mode': '<S65>:7' */
        /* Transition: '<S65>:4' */
        /* '<S65>:4:1' Initial; */
        /* Event: '<S65>:12' */
        APP_FluxWeak_GEAR2_Initial();

        /* End of Outputs for SubSystem: '<S56>/Initial' */

        /* '<S65>:9:1' sf_internal_predicateOutput = ... */
        /* '<S65>:9:1' ModeSt==0; */
        switch (APP_FluxWeak_GEAR2_DW.ModeSt) {
         case 0U:
          /* Transition: '<S65>:9' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Torque;

          /* Outputs for Function Call SubSystem: '<S56>/Torque' */

          /* Entry 'Torque': '<S65>:3' */
          /* '<S65>:3:1' Torque; */
          /* Event: '<S65>:10' */
          APP_FluxWeak_GEAR2_Torque(PMSM_Input.AppComm.TqReq,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Torque);

          /* End of Outputs for SubSystem: '<S56>/Torque' */
          break;

         case 1U:
          /* Transition: '<S65>:36' */
          /* '<S65>:37:1' sf_internal_predicateOutput = ... */
          /* '<S65>:37:1' ModeSt==1; */
          /* Transition: '<S65>:37' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Spd;

          /* Outputs for Function Call SubSystem: '<S56>/Spd' */

          /* Entry 'Spd': '<S65>:14' */
          /* '<S65>:14:1' Spd; */
          /* Event: '<S65>:16' */
          APP_FluxWeak_GEAR2_Spd(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Spd_g);

          /* End of Outputs for SubSystem: '<S56>/Spd' */
          break;

         case 2U:
          /* Transition: '<S65>:38' */
          /* '<S65>:39:1' sf_internal_predicateOutput = ... */
          /* '<S65>:39:1' ModeSt==2; */
          /* Transition: '<S65>:39' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Genrate;

          /* Outputs for Function Call SubSystem: '<S56>/Genrate' */

          /* Entry 'Genrate': '<S65>:18' */
          /* '<S65>:18:1' Genrate; */
          /* Event: '<S65>:19' */
          APP_FluxWeak_GEAR2_Genrate(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Genrate);

          /* End of Outputs for SubSystem: '<S56>/Genrate' */
          break;

         case 3U:
          /* Transition: '<S65>:76' */
          /* '<S65>:77:1' sf_internal_predicateOutput = ... */
          /* '<S65>:77:1' ModeSt==3; */
          /* Transition: '<S65>:77' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Starter;

          /* Outputs for Function Call SubSystem: '<S56>/Starter' */

          /* Entry 'Starter': '<S65>:72' */
          /* '<S65>:72:1' Starter; */
          /* Event: '<S65>:74' */
          APP_FluxWeak_GEAR2_Starter(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Starter);

          /* End of Outputs for SubSystem: '<S56>/Starter' */
          break;

         case 4U:
          /* Transition: '<S65>:40' */
          /* '<S65>:41:1' sf_internal_predicateOutput = ... */
          /* '<S65>:41:1' ModeSt==4; */
          /* Transition: '<S65>:41' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Slope;

          /* Outputs for Function Call SubSystem: '<S56>/Slope' */

          /* Entry 'Slope': '<S65>:20' */
          /* '<S65>:20:1' Slope; */
          /* Event: '<S65>:21' */
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

          /* End of Outputs for SubSystem: '<S56>/Slope' */
          break;

         case 5U:
          /* Transition: '<S65>:43' */
          /* '<S65>:42:1' sf_internal_predicateOutput = ... */
          /* '<S65>:42:1' ModeSt==5; */
          /* Transition: '<S65>:42' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Sync;

          /* Outputs for Function Call SubSystem: '<S56>/Sync' */

          /* Entry 'Sync': '<S65>:22' */
          /* '<S65>:22:1' Sync; */
          /* Event: '<S65>:23' */
          APP_FluxWeak_GEAR2_Sync(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Sync);

          /* End of Outputs for SubSystem: '<S56>/Sync' */
          break;

         case 6U:
          /* Transition: '<S65>:44' */
          /* '<S65>:45:1' sf_internal_predicateOutput = ... */
          /* '<S65>:45:1' ModeSt==6; */
          /* Transition: '<S65>:45' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_Dischg;

          /* Outputs for Function Call SubSystem: '<S56>/Dischg' */

          /* Entry 'Dischg': '<S65>:25' */
          /* '<S65>:25:1' Dischg; */
          /* Event: '<S65>:27' */
          APP_FluxWeak_GEAR2_Dischg(DiscreteTimeIntegrator1_i4,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Dischg);

          /* End of Outputs for SubSystem: '<S56>/Dischg' */
          break;

         case 7U:
          /* Transition: '<S65>:46' */
          /* '<S65>:50:1' sf_internal_predicateOutput = ... */
          /* '<S65>:50:1' ModeSt==7; */
          /* Transition: '<S65>:50' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_ASC;

          /* Outputs for Function Call SubSystem: '<S56>/ASC' */

          /* Entry 'ASC': '<S65>:48' */
          /* '<S65>:48:1' ASC; */
          /* Event: '<S65>:49' */
          APP_FluxWeak_GEAR2_ASC(&APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b);

          /* End of Outputs for SubSystem: '<S56>/ASC' */
          break;

         default:
          /* Transition: '<S65>:52' */
          /* Transition: '<S65>:53' */
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_standard;

          /* Outputs for Function Call SubSystem: '<S56>/Calib' */

          /* Entry 'standard': '<S65>:28' */
          /* 标定 */
          /* '<S65>:28:1' Calib; */
          /* Event: '<S65>:29' */
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

          /* End of Outputs for SubSystem: '<S56>/Calib' */
          break;
        }
      } else {
        /* Outputs for Function Call SubSystem: '<S56>/UVW_check' */

        /* '<S65>:86:1' UVWcheck; */
        /* Event: '<S65>:87' */
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

        /* End of Outputs for SubSystem: '<S56>/UVW_check' */
      }
    } else {
      /* Outputs for Function Call SubSystem: '<S56>/IntLim' */
      /* Switch: '<S108>/Switch2' incorporates:
       *  RelationalOperator: '<S108>/LowerRelop1'
       *  RelationalOperator: '<S108>/UpperRelop'
       *  StateReader: '<S70>/State Reader1'
       *  Switch: '<S108>/Switch'
       */
      /* During 'sys_mode': '<S65>:7' */
      /* '<S65>:7:1' IntLim; */
      /* Event: '<S65>:78' */
      if (APP_FluxWeak_GEAR2_DW.Slope.PI.I_state > rtb_Abs_l) {
        rtb_Switch_b = rtb_Abs_l;
      } else if (APP_FluxWeak_GEAR2_DW.Slope.PI.I_state < rtb_InvCoef) {
        /* Switch: '<S108>/Switch' */
        rtb_Switch_b = rtb_InvCoef;
      } else {
        rtb_Switch_b = APP_FluxWeak_GEAR2_DW.Slope.PI.I_state;
      }

      /* End of Switch: '<S108>/Switch2' */

      /* Saturate: '<S70>/Saturation2' */
      if (rtb_Switch_b > PMSM_Param.SlopeMaxT) {
        rtb_Switch_b = PMSM_Param.SlopeMaxT;
      } else {
        if (rtb_Switch_b < -PMSM_Param.SlopeMaxT) {
          rtb_Switch_b = -PMSM_Param.SlopeMaxT;
        }
      }

      /* End of Saturate: '<S70>/Saturation2' */

      /* Chart: '<S70>/Chart' incorporates:
       *  DataStoreRead: '<Root>/Data Store Read'
       */
      /* Gateway: implement/method/All_loop/IntLim/Chart */
      /* During: implement/method/All_loop/IntLim/Chart */
      /* Entry Internal: implement/method/All_loop/IntLim/Chart */
      /* Transition: '<S103>:4' */
      /* '<S103>:5:1' sf_internal_predicateOutput = ... */
      /* '<S103>:5:1' Gear==1; */
      switch (PMSM_Input.AppComm.GearState) {
       case 1U:
        /* Transition: '<S103>:5' */
        /* Transition: '<S103>:7' */
        /* '<S103>:7:1' out=max(0,In); */
        if (0.0F > rtb_Switch_b) {
          /* StateWriter: '<S70>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;
        } else if (rtIsNaNF(rtb_Switch_b)) {
          /* StateWriter: '<S70>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;
        } else {
          /* StateWriter: '<S70>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = rtb_Switch_b;
        }

        /* Transition: '<S103>:12' */
        /* Transition: '<S103>:11' */
        break;

       case 2U:
        /* Transition: '<S103>:6' */
        /* '<S103>:8:1' sf_internal_predicateOutput = ... */
        /* '<S103>:8:1' Gear==2; */
        /* Transition: '<S103>:8' */
        /* Transition: '<S103>:10' */
        /* '<S103>:10:1' out=min(0,In); */
        if (0.0F < rtb_Switch_b) {
          /* StateWriter: '<S70>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;

          /* Transition: '<S103>:11' */
        } else if (rtIsNaNF(rtb_Switch_b)) {
          /* StateWriter: '<S70>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;

          /* Transition: '<S103>:11' */
        } else {
          /* StateWriter: '<S70>/State Writer1' */
          APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = rtb_Switch_b;

          /* Transition: '<S103>:11' */
        }
        break;

       default:
        /* StateWriter: '<S70>/State Writer1' */
        /* Transition: '<S103>:9' */
        /* '<S103>:9:1' out=0; */
        APP_FluxWeak_GEAR2_DW.Slope.PI.I_state = 0.0F;
        break;
      }

      /* End of Chart: '<S70>/Chart' */

      /* Switch: '<S107>/Switch2' incorporates:
       *  RelationalOperator: '<S107>/LowerRelop1'
       *  RelationalOperator: '<S107>/UpperRelop'
       *  StateReader: '<S70>/State Reader2'
       *  Switch: '<S107>/Switch'
       */
      /* Transition: '<S103>:13' */
      if (APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state > rtb_Abs_l) {
        rtb_Switch_b = rtb_Abs_l;
      } else if (APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state < rtb_InvCoef) {
        /* Switch: '<S107>/Switch' */
        rtb_Switch_b = rtb_InvCoef;
      } else {
        rtb_Switch_b = APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state;
      }

      /* End of Switch: '<S107>/Switch2' */

      /* Saturate: '<S70>/Saturation3' */
      if (rtb_Switch_b > 1.0F) {
        rtb_Switch_b = 1.0F;
      } else {
        if (rtb_Switch_b < -1.0F) {
          rtb_Switch_b = -1.0F;
        }
      }

      /* End of Saturate: '<S70>/Saturation3' */

      /* Switch: '<S70>/Switch' incorporates:
       *  Abs: '<S70>/Abs'
       */
      if (fabsf(DiscreteTimeIntegrator1_i) > 10.0F) {
        /* StateWriter: '<S70>/State Writer2' */
        APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state = rtb_Switch_b;
      } else {
        /* StateWriter: '<S70>/State Writer2' incorporates:
         *  Gain: '<S70>/N'
         *  Gain: '<S70>/Ts'
         *  Sum: '<S70>/Subtract'
         */
        APP_FluxWeak_GEAR2_DW.Spd_g.Spd_state = rtb_Switch_b - 20.0F *
          rtb_Switch_b * 0.002F;
      }

      /* End of Switch: '<S70>/Switch' */

      /* Switch: '<S106>/Switch2' incorporates:
       *  RelationalOperator: '<S106>/LowerRelop1'
       *  RelationalOperator: '<S106>/UpperRelop'
       *  StateReader: '<S70>/State Reader3'
       *  Switch: '<S106>/Switch'
       */
      if (APP_FluxWeak_GEAR2_DW.Sync.PI.I_state > rtb_Abs_l) {
        /* StateWriter: '<S70>/State Writer3' */
        APP_FluxWeak_GEAR2_DW.Sync.PI.I_state = rtb_Abs_l;
      } else {
        if (APP_FluxWeak_GEAR2_DW.Sync.PI.I_state < rtb_InvCoef) {
          /* Switch: '<S106>/Switch' incorporates:
           *  StateWriter: '<S70>/State Writer3'
           */
          APP_FluxWeak_GEAR2_DW.Sync.PI.I_state = rtb_InvCoef;
        }
      }

      /* End of Switch: '<S106>/Switch2' */

      /* Switch: '<S105>/Switch2' incorporates:
       *  RelationalOperator: '<S105>/LowerRelop1'
       *  RelationalOperator: '<S105>/UpperRelop'
       *  StateReader: '<S70>/State Reader4'
       *  Switch: '<S105>/Switch'
       */
      if (APP_FluxWeak_GEAR2_DW.Starter.PI.I_state > rtb_Abs_l) {
        rtb_Switch_b = rtb_Abs_l;
      } else if (APP_FluxWeak_GEAR2_DW.Starter.PI.I_state < rtb_InvCoef) {
        /* Switch: '<S105>/Switch' */
        rtb_Switch_b = rtb_InvCoef;
      } else {
        rtb_Switch_b = APP_FluxWeak_GEAR2_DW.Starter.PI.I_state;
      }

      /* End of Switch: '<S105>/Switch2' */

      /* Saturate: '<S70>/Saturation1' */
      if (rtb_Switch_b > 1.0F) {
        /* StateWriter: '<S70>/State Writer4' */
        APP_FluxWeak_GEAR2_DW.Starter.PI.I_state = 1.0F;
      } else if (rtb_Switch_b < 0.0F) {
        /* StateWriter: '<S70>/State Writer4' */
        APP_FluxWeak_GEAR2_DW.Starter.PI.I_state = 0.0F;
      } else {
        /* StateWriter: '<S70>/State Writer4' */
        APP_FluxWeak_GEAR2_DW.Starter.PI.I_state = rtb_Switch_b;
      }

      /* End of Saturate: '<S70>/Saturation1' */

      /* Switch: '<S104>/Switch2' incorporates:
       *  RelationalOperator: '<S104>/LowerRelop1'
       *  RelationalOperator: '<S104>/UpperRelop'
       *  StateReader: '<S70>/State Reader5'
       *  Switch: '<S104>/Switch'
       */
      if (APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE > rtb_Abs_l) {
        /* StateWriter: '<S70>/State Writer5' */
        APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE = rtb_Abs_l;
      } else {
        if (APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE < rtb_InvCoef) {
          /* Switch: '<S104>/Switch' incorporates:
           *  StateWriter: '<S70>/State Writer5'
           */
          APP_FluxWeak_GEAR2_DW.Torque.lpf.LPF_STATE = rtb_InvCoef;
        }
      }

      /* End of Switch: '<S104>/Switch2' */

      /* Switch: '<S109>/Switch2' incorporates:
       *  RelationalOperator: '<S109>/LowerRelop1'
       *  RelationalOperator: '<S109>/UpperRelop'
       *  StateReader: '<S70>/State Reader'
       *  Switch: '<S109>/Switch'
       */
      if (APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state > rtb_Abs_l) {
        rtb_Switch_b = rtb_Abs_l;
      } else if (APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state < rtb_InvCoef) {
        /* Switch: '<S109>/Switch' */
        rtb_Switch_b = rtb_InvCoef;
      } else {
        rtb_Switch_b = APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state;
      }

      /* End of Switch: '<S109>/Switch2' */

      /* Saturate: '<S70>/Saturation' */
      if (rtb_Switch_b > 0.0F) {
        /* StateWriter: '<S70>/State Writer6' */
        APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state = 0.0F;
      } else if (rtb_Switch_b < -1.0F) {
        /* StateWriter: '<S70>/State Writer6' */
        APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state = -1.0F;
      } else {
        /* StateWriter: '<S70>/State Writer6' */
        APP_FluxWeak_GEAR2_DW.Genrate.PI.I_state = rtb_Switch_b;
      }

      /* End of Saturate: '<S70>/Saturation' */
      /* End of Outputs for SubSystem: '<S56>/IntLim' */
      /* '<S65>:57:1' sf_internal_predicateOutput = ... */
      /* '<S65>:57:1' hasChanged (ModeSt); */
      if (rtb_UVWoffline != APP_FluxWeak_GEAR2_DW.ModeSt_start) {
        /* Transition: '<S65>:57' */
        /* '<S65>:9:1' sf_internal_predicateOutput = ... */
        /* '<S65>:9:1' ModeSt==0; */
        switch (APP_FluxWeak_GEAR2_DW.ModeSt) {
         case 0U:
          /* Transition: '<S65>:9' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Torque;

          /* Outputs for Function Call SubSystem: '<S56>/Torque' */

          /* Entry 'Torque': '<S65>:3' */
          /* '<S65>:3:1' Torque; */
          /* Event: '<S65>:10' */
          APP_FluxWeak_GEAR2_Torque(PMSM_Input.AppComm.TqReq,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Torque);

          /* End of Outputs for SubSystem: '<S56>/Torque' */
          break;

         case 1U:
          /* Transition: '<S65>:36' */
          /* '<S65>:37:1' sf_internal_predicateOutput = ... */
          /* '<S65>:37:1' ModeSt==1; */
          /* Transition: '<S65>:37' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Spd;

          /* Outputs for Function Call SubSystem: '<S56>/Spd' */

          /* Entry 'Spd': '<S65>:14' */
          /* '<S65>:14:1' Spd; */
          /* Event: '<S65>:16' */
          APP_FluxWeak_GEAR2_Spd(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Spd_g);

          /* End of Outputs for SubSystem: '<S56>/Spd' */
          break;

         case 2U:
          /* Transition: '<S65>:38' */
          /* '<S65>:39:1' sf_internal_predicateOutput = ... */
          /* '<S65>:39:1' ModeSt==2; */
          /* Transition: '<S65>:39' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Genrate;

          /* Outputs for Function Call SubSystem: '<S56>/Genrate' */

          /* Entry 'Genrate': '<S65>:18' */
          /* '<S65>:18:1' Genrate; */
          /* Event: '<S65>:19' */
          APP_FluxWeak_GEAR2_Genrate(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Genrate);

          /* End of Outputs for SubSystem: '<S56>/Genrate' */
          break;

         case 3U:
          /* Transition: '<S65>:76' */
          /* '<S65>:77:1' sf_internal_predicateOutput = ... */
          /* '<S65>:77:1' ModeSt==3; */
          /* Transition: '<S65>:77' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Starter;

          /* Outputs for Function Call SubSystem: '<S56>/Starter' */

          /* Entry 'Starter': '<S65>:72' */
          /* '<S65>:72:1' Starter; */
          /* Event: '<S65>:74' */
          APP_FluxWeak_GEAR2_Starter(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Starter);

          /* End of Outputs for SubSystem: '<S56>/Starter' */
          break;

         case 4U:
          /* Transition: '<S65>:40' */
          /* '<S65>:41:1' sf_internal_predicateOutput = ... */
          /* '<S65>:41:1' ModeSt==4; */
          /* Transition: '<S65>:41' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Slope;

          /* Outputs for Function Call SubSystem: '<S56>/Slope' */

          /* Entry 'Slope': '<S65>:20' */
          /* '<S65>:20:1' Slope; */
          /* Event: '<S65>:21' */
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

          /* End of Outputs for SubSystem: '<S56>/Slope' */
          break;

         case 5U:
          /* Transition: '<S65>:43' */
          /* '<S65>:42:1' sf_internal_predicateOutput = ... */
          /* '<S65>:42:1' ModeSt==5; */
          /* Transition: '<S65>:42' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_Speed;
          APP_FluxWeak_GEAR2_DW.is_Speed = APP_FluxWeak_GEAR2_IN_Sync;

          /* Outputs for Function Call SubSystem: '<S56>/Sync' */

          /* Entry 'Sync': '<S65>:22' */
          /* '<S65>:22:1' Sync; */
          /* Event: '<S65>:23' */
          APP_FluxWeak_GEAR2_Sync(DiscreteTimeIntegrator1_i,
            DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Sync);

          /* End of Outputs for SubSystem: '<S56>/Sync' */
          break;

         case 6U:
          /* Transition: '<S65>:44' */
          /* '<S65>:45:1' sf_internal_predicateOutput = ... */
          /* '<S65>:45:1' ModeSt==6; */
          /* Transition: '<S65>:45' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_Dischg;

          /* Outputs for Function Call SubSystem: '<S56>/Dischg' */

          /* Entry 'Dischg': '<S65>:25' */
          /* '<S65>:25:1' Dischg; */
          /* Event: '<S65>:27' */
          APP_FluxWeak_GEAR2_Dischg(DiscreteTimeIntegrator1_i4,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Dischg);

          /* End of Outputs for SubSystem: '<S56>/Dischg' */
          break;

         case 7U:
          /* Transition: '<S65>:46' */
          /* '<S65>:50:1' sf_internal_predicateOutput = ... */
          /* '<S65>:50:1' ModeSt==7; */
          /* Transition: '<S65>:50' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_ASC;

          /* Outputs for Function Call SubSystem: '<S56>/ASC' */

          /* Entry 'ASC': '<S65>:48' */
          /* '<S65>:48:1' ASC; */
          /* Event: '<S65>:49' */
          APP_FluxWeak_GEAR2_ASC(&APP_FluxWeak_GEAR2_DW.AscEn_l,
            &APP_FluxWeak_GEAR2_DW.IdRefSet_i, &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b);

          /* End of Outputs for SubSystem: '<S56>/ASC' */
          break;

         default:
          /* Transition: '<S65>:52' */
          /* Transition: '<S65>:53' */
          APP_Flux_exit_internal_sys_mode(&DiscreteTimeIntegrator1,
            &DiscreteTimeIntegrator1_i);
          APP_FluxWeak_GEAR2_DW.is_sys_mode = APP_FluxWeak_GEAR2_IN_appoint;
          APP_FluxWeak_GEAR2_DW.is_appoint = APP_FluxWeak_GEAR2_IN_standard;

          /* Outputs for Function Call SubSystem: '<S56>/Calib' */

          /* Entry 'standard': '<S65>:28' */
          /* 标定 */
          /* '<S65>:28:1' Calib; */
          /* Event: '<S65>:29' */
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

          /* End of Outputs for SubSystem: '<S56>/Calib' */
          break;
        }
      } else {
        switch (APP_FluxWeak_GEAR2_DW.is_sys_mode) {
         case APP_FluxWeak_GEAR2_IN_Speed:
          /* During 'Speed': '<S65>:5' */
          switch (APP_FluxWeak_GEAR2_DW.is_Speed) {
           case APP_FluxWeak_GEAR2_IN_Genrate:
            /* Outputs for Function Call SubSystem: '<S56>/Genrate' */

            /* During 'Genrate': '<S65>:18' */
            /* '<S65>:18:1' Genrate; */
            /* Event: '<S65>:19' */
            APP_FluxWeak_GEAR2_Genrate(DiscreteTimeIntegrator1_i,
              DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
              &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Genrate);

            /* End of Outputs for SubSystem: '<S56>/Genrate' */
            break;

           case APP_FluxWeak_GEAR2_IN_Slope:
            /* Outputs for Function Call SubSystem: '<S56>/Slope' */

            /* During 'Slope': '<S65>:20' */
            /* '<S65>:20:1' Slope; */
            /* Event: '<S65>:21' */
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

            /* End of Outputs for SubSystem: '<S56>/Slope' */
            break;

           case APP_FluxWeak_GEAR2_IN_Spd:
            /* Outputs for Function Call SubSystem: '<S56>/Spd' */

            /* During 'Spd': '<S65>:14' */
            /* '<S65>:14:1' Spd; */
            /* Event: '<S65>:16' */
            APP_FluxWeak_GEAR2_Spd(DiscreteTimeIntegrator1_i,
              DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
              &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Spd_g);

            /* End of Outputs for SubSystem: '<S56>/Spd' */
            break;

           case APP_FluxWeak_GEAR2_IN_Starter:
            /* Outputs for Function Call SubSystem: '<S56>/Starter' */

            /* During 'Starter': '<S65>:72' */
            /* '<S65>:72:1' Starter; */
            /* Event: '<S65>:74' */
            APP_FluxWeak_GEAR2_Starter(DiscreteTimeIntegrator1_i,
              DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
              &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Starter);

            /* End of Outputs for SubSystem: '<S56>/Starter' */
            break;

           default:
            /* Outputs for Function Call SubSystem: '<S56>/Sync' */

            /* During 'Sync': '<S65>:22' */
            /* '<S65>:22:1' Sync; */
            /* Event: '<S65>:23' */
            APP_FluxWeak_GEAR2_Sync(DiscreteTimeIntegrator1_i,
              DiscreteTimeIntegrator1, &APP_FluxWeak_GEAR2_DW.AscEn_l,
              &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Sync);

            /* End of Outputs for SubSystem: '<S56>/Sync' */
            break;
          }
          break;

         case APP_FluxWeak_GEAR2_IN_Torque:
          /* Outputs for Function Call SubSystem: '<S56>/Torque' */

          /* During 'Torque': '<S65>:3' */
          /* '<S65>:3:1' Torque; */
          /* Event: '<S65>:10' */
          APP_FluxWeak_GEAR2_Torque(PMSM_Input.AppComm.TqReq,
            &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
            &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
            &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
            &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
            &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
            &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
            &APP_FluxWeak_GEAR2_DW.Merge1, &APP_FluxWeak_GEAR2_DW.Torque);

          /* End of Outputs for SubSystem: '<S56>/Torque' */
          break;

         default:
          /* During 'appoint': '<S65>:6' */
          switch (APP_FluxWeak_GEAR2_DW.is_appoint) {
           case APP_FluxWeak_GEAR2_IN_ASC:
            /* Outputs for Function Call SubSystem: '<S56>/ASC' */

            /* During 'ASC': '<S65>:48' */
            /* '<S65>:48:1' ASC; */
            /* Event: '<S65>:49' */
            APP_FluxWeak_GEAR2_ASC(&APP_FluxWeak_GEAR2_DW.AscEn_l,
              &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b);

            /* End of Outputs for SubSystem: '<S56>/ASC' */
            break;

           case APP_FluxWeak_GEAR2_IN_Dischg:
            /* Outputs for Function Call SubSystem: '<S56>/Dischg' */

            /* During 'Dischg': '<S65>:25' */
            /* '<S65>:25:1' Dischg; */
            /* Event: '<S65>:27' */
            APP_FluxWeak_GEAR2_Dischg(DiscreteTimeIntegrator1_i4,
              &APP_FluxWeak_GEAR2_DW.AscEn_l, &APP_FluxWeak_GEAR2_DW.IdRefSet_i,
              &APP_FluxWeak_GEAR2_DW.IqRefSet_m,
              &APP_FluxWeak_GEAR2_DW.AngleRefSet_e,
              &APP_FluxWeak_GEAR2_DW.IdIqSetEn_d,
              &APP_FluxWeak_GEAR2_DW.AngleSetEn_c,
              &APP_FluxWeak_GEAR2_DW.CalibZeroPoint_f, &rtb_Switch_b,
              &APP_FluxWeak_GEAR2_DW.Dischg);

            /* End of Outputs for SubSystem: '<S56>/Dischg' */
            break;

           default:
            /* Outputs for Function Call SubSystem: '<S56>/Calib' */

            /* During 'standard': '<S65>:28' */
            /* '<S65>:28:1' Calib; */
            /* Event: '<S65>:29' */
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

            /* End of Outputs for SubSystem: '<S56>/Calib' */
            break;
          }
          break;
        }
      }
    }

    /* End of Chart: '<S56>/Chart' */

    /* DataStoreWrite: '<S71>/Data Store Write2' */
    AppFun.Tqreq = rtb_Switch_b;

    /* Switch: '<S110>/Switch2' incorporates:
     *  RelationalOperator: '<S110>/LowerRelop1'
     *  RelationalOperator: '<S110>/UpperRelop'
     *  Switch: '<S110>/Switch'
     */
    if (rtb_Switch_b > rtb_Abs_l) {
      rtb_Switch_b = rtb_Abs_l;
    } else {
      if (rtb_Switch_b < rtb_InvCoef) {
        /* Switch: '<S110>/Switch' */
        rtb_Switch_b = rtb_InvCoef;
      }
    }

    /* End of Switch: '<S110>/Switch2' */

    /* DataStoreWrite: '<S144>/Data Store Write' */
    AppFun.LimTP_I = rtb_Divide_p;

    /* DataStoreWrite: '<S144>/Data Store Write1' */
    AppFun.LimTN_I = rtb_Add_j;

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

    /* FunctionCaller: '<S62>/Function Caller' */
    APP_FluxWeak_GEAR2_n2MaxT(rtb_Psi_i, &APP_FluxWeak_GEAR2_DW.TqMax);

    /* Product: '<S62>/Product' */
    APP_FluxWeak_GEAR2_DW.TqReal = APP_FluxWeak_GEAR2_DW.TqMax * rtb_Switch_b;

    /* SignalConversion: '<S62>/TmpBufferAtConstantOutport1' incorporates:
     *  Constant: '<S62>/Constant'
     */
    APP_FluxWeak_GEAR2_DW.ZeroPointBias = 0.0F;
  } else {
    if (APP_FluxWeak_GEAR2_DW.method_MODE) {
      /* Disable for Chart: '<S56>/Chart' incorporates:
       *  SubSystem: '<S56>/Slope'
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
   *  Constant: '<S55>/Constant'
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  DataStoreWrite: '<Root>/Data Store Write1'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  RelationalOperator: '<S55>/Compare'
   */
  App_Output.data_process.NmFil = DiscreteTimeIntegrator1;
  App_Output.data_process.VoltCapFil = DiscreteTimeIntegrator1_i4;
  App_Output.data_process.CurBusFil = rtb_DiscreteTimeIntegrator1;
  App_Output.data_process.MotTemp = rtb_MotTemp;
  App_Output.data_process.InvTemp = rtb_BusConversion_InsertedFor_0;
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
    /* SystemInitialize for Chart: '<S19>/Chart' */
    APP_FluxWeak_GEAR2_DW.BlockState = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S15>/Block' */

    /* SystemInitialize for Enabled SubSystem: '<S15>/DisChg' */
    /* SystemInitialize for Chart: '<S27>/Chart1' */
    APP_FluxWeak_GEAR2_DW.DisChg_time = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S15>/DisChg' */

    /* SystemInitialize for Enabled SubSystem: '<S15>/Spd' */
    /* InitializeConditions for RateLimiter: '<S29>/Rate Limiter' */
    APP_FluxWeak_GEAR2_DW.PrevY = 1.0F;

    /* SystemInitialize for Chart: '<S29>/Chart1' */
    APP_FluxWeak_GEAR2_DW.SpdCode_o[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.SpdCode_o[1] = 0UL;

    /* SystemInitialize for Outport: '<S29>/Spd' */
    APP_FluxWeak_GEAR2_DW.SpdCode[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.SpdCode[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.OSLimTP = 1.0F;
    APP_FluxWeak_GEAR2_DW.OSLimTN = -1.0F;

    /* End of SystemInitialize for SubSystem: '<S15>/Spd' */

    /* SystemInitialize for Enabled SubSystem: '<S15>/TempSensor' */
    /* SystemInitialize for Chart: '<S31>/Chart1' */
    APP_FluxWeak_GEAR2_DW.out_e[0] = 0.0F;
    APP_FluxWeak_GEAR2_DW.out_e[1] = 0.0F;

    /* SystemInitialize for Chart: '<S31>/Chart2' */
    APP_FluxWeak_GEAR2_DW.out[0] = 0.0F;
    APP_FluxWeak_GEAR2_DW.out[1] = 0.0F;
    APP_FluxWeak_GEAR2_DW.out[2] = 0.0F;

    /* SystemInitialize for Atomic SubSystem: '<S50>/lpf' */
    LPF_App_Init(&APP_FluxWeak_GEAR2_DW.lpf_e);

    /* End of SystemInitialize for SubSystem: '<S50>/lpf' */

    /* SystemInitialize for Atomic SubSystem: '<S51>/lpf' */
    LPF_App_Init(&APP_FluxWeak_GEAR2_DW.lpf_i);

    /* End of SystemInitialize for SubSystem: '<S51>/lpf' */

    /* SystemInitialize for Outport: '<S31>/TempSensor' */
    APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_c = 24.0F;
    APP_FluxWeak_GEAR2_DW.DiscreteTimeIntegrator1_a = 24.0F;
    APP_FluxWeak_GEAR2_DW.LogicalOperator1[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.LogicalOperator1[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.LogicalOperator2[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.LogicalOperator2[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.LogicalOperator2[2] = 0UL;

    /* End of SystemInitialize for SubSystem: '<S15>/TempSensor' */

    /* SystemInitialize for Enabled SubSystem: '<S15>/Temp' */
    /* SystemInitialize for Chart: '<S30>/Chart' */
    APP_FluxWeak_GEAR2_DW.TempCode_g[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.TempCode_g[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.TempCode_g[2] = 0UL;
    APP_FluxWeak_GEAR2_DW.TempCode_g[3] = 0UL;
    APP_FluxWeak_GEAR2_DW.TempCode_g[4] = 0UL;
    APP_FluxWeak_GEAR2_DW.TempCode_g[5] = 0UL;

    /* SystemInitialize for Outport: '<S30>/Temp' */
    for (i = 0; i < 6; i++) {
      APP_FluxWeak_GEAR2_DW.TempCode[i] = 0UL;
    }

    APP_FluxWeak_GEAR2_DW.MotCoef = 1.0F;
    APP_FluxWeak_GEAR2_DW.InvCoef = 1.0F;

    /* End of SystemInitialize for Outport: '<S30>/Temp' */
    /* End of SystemInitialize for SubSystem: '<S15>/Temp' */

    /* SystemInitialize for Enabled SubSystem: '<S15>/Volt' */
    /* SystemInitialize for Chart: '<S32>/Chart3' */
    APP_FluxWeak_GEAR2_DW.VoltCode_m[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode_m[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode_m[2] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode_m[3] = 0UL;
    APP_FluxWeak_GEAR2_DW.DisChg_coef = 1.0F;

    /* SystemInitialize for Outport: '<S32>/Volt' */
    APP_FluxWeak_GEAR2_DW.VoltCode[0] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode[1] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode[2] = 0UL;
    APP_FluxWeak_GEAR2_DW.VoltCode[3] = 0UL;
    APP_FluxWeak_GEAR2_DW.OVLimTP_g = 1.0F;
    APP_FluxWeak_GEAR2_DW.OVLimTN_m = -1.0F;

    /* End of SystemInitialize for SubSystem: '<S15>/Volt' */
    /* End of SystemInitialize for SubSystem: '<S8>/judgment' */

    /* SystemInitialize for Enabled SubSystem: '<S8>/Act' */
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

    /* SystemInitialize for Atomic SubSystem: '<S144>/LimDrv' */

    /* SystemInitialize for Chart: '<S158>/Chart' */
    APP_FluxWeak_GEAR2_Chart_Init(&Add, &APP_FluxWeak_GEAR2_DW.sf_Chart_c);

    /* End of SystemInitialize for SubSystem: '<S144>/LimDrv' */

    /* SystemInitialize for Atomic SubSystem: '<S144>/LimChg' */

    /* SystemInitialize for Chart: '<S152>/Chart' */
    APP_FluxWeak_GEAR2_Chart_Init(&Add, &APP_FluxWeak_GEAR2_DW.sf_Chart_lj);

    /* End of SystemInitialize for SubSystem: '<S144>/LimChg' */

    /* SystemInitialize for Chart: '<S144>/Chart1' */
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

    /* SystemInitialize for Chart: '<S56>/Chart' incorporates:
     *  SubSystem: '<S56>/Torque'
     */
    APP_FluxWeak_GEAR2_Torque_Init(&APP_FluxWeak_GEAR2_DW.Torque);

    /* SystemInitialize for Chart: '<S56>/Chart' incorporates:
     *  SubSystem: '<S56>/Slope'
     */
    APP_FluxWeak_GEAR2_Slope_Init(&APP_FluxWeak_GEAR2_DW.Slope);

    /* SystemInitialize for Chart: '<S56>/Chart' incorporates:
     *  SubSystem: '<S56>/Calib'
     */
    APP_FluxWeak_GEAR2_Calib_Init(&APP_FluxWeak_GEAR2_DW.Calib);

    /* SystemInitialize for Chart: '<S56>/Chart' incorporates:
     *  SubSystem: '<S56>/UVW_check'
     */
    APP_FluxWeak_GEA_UVW_check_Init(&APP_FluxWeak_GEAR2_DW.UVW_check);

    /* SystemInitialize for Merge: '<S56>/Merge1' */
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
