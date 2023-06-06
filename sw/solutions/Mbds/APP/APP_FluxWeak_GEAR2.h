/*
 * File: APP_FluxWeak_GEAR2.h
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

#ifndef RTW_HEADER_APP_FluxWeak_GEAR2_h_
#define RTW_HEADER_APP_FluxWeak_GEAR2_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef APP_FluxWeak_GEAR2_COMMON_INCLUDES_
# define APP_FluxWeak_GEAR2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* APP_FluxWeak_GEAR2_COMMON_INCLUDES_ */

#include "APP_FluxWeak_GEAR2_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals and states (auto storage) for system '<S48>/lpf' */
typedef struct {
  real32_T LPF_STATE;                  /* '<S50>/Discrete-Time Integrator1' */
} DW_LPF_App_T;

/* Block signals and states (auto storage) for system '<S54>/Torque' */
typedef struct {
  DW_LPF_App_T lpf;                    /* '<S132>/lpf' */
} DW_Torque_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S54>/Spd' */
typedef struct {
  real32_T Spd_D_Int;                  /* '<S127>/Discrete-Time Integrator1' */
  real32_T Spd_state;                  /* '<S127>/Discrete-Time Integrator' */
} DW_Spd_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S99>/PI' */
typedef struct {
  real32_T I_state;                    /* '<S100>/Discrete-Time Integrator1' */
} DW_PI_App_T;

/* Block signals and states (auto storage) for system '<S54>/Genrate' */
typedef struct {
  DW_PI_App_T PI;                      /* '<S99>/PI' */
} DW_Genrate_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S54>/Starter' */
typedef struct {
  DW_PI_App_T PI;                      /* '<S128>/PI' */
} DW_Starter_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S110>/Function-Call Subsystem' */
typedef struct {
  real32_T Slope_state;                /* '<S114>/Discrete-Time Integrator' */
} DW_FunctionCallSubsystem_APP__T;

/* Block signals and states (auto storage) for system '<S112>/Function-Call Subsystem2' */
typedef struct {
  real32_T N_state;                    /* '<S123>/Delay Input2' */
} DW_FunctionCallSubsystem2_APP_T;

/* Block signals and states (auto storage) for system '<S54>/Slope' */
typedef struct {
  DW_PI_App_T PI;                      /* '<S113>/PI' */
  DW_FunctionCallSubsystem2_APP_T FunctionCallSubsystem2;/* '<S112>/Function-Call Subsystem2' */
  DW_LPF_App_T lpf_a;                  /* '<S116>/lpf' */
  DW_LPF_App_T lpf;                    /* '<S117>/lpf' */
  DW_FunctionCallSubsystem_APP__T FunctionCallSubsystem;/* '<S110>/Function-Call Subsystem' */
  real32_T Merge;                      /* '<S112>/Merge' */
  real32_T SpdReqPu_out;               /* '<S70>/Chart' */
  real32_T DiscreteTimeIntegrator;     /* '<S114>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S70>/Unit Delay' */
  uint16_T Gear_start;                 /* '<S112>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S70>/Chart' */
  uint16_T GearState_start;            /* '<S70>/Chart' */
  uint16_T is_active_c19_APP_FluxWeak_GEAR;/* '<S112>/Chart' */
  uint16_T is_Gear;                    /* '<S112>/Chart' */
  uint16_T is_active_c4_APP_FluxWeak_GEAR2;/* '<S70>/Chart' */
  uint16_T is_c4_APP_FluxWeak_GEAR2;   /* '<S70>/Chart' */
  uint16_T is_move;                    /* '<S70>/Chart' */
  uint16_T is_D;                       /* '<S70>/Chart' */
  uint16_T is_R;                       /* '<S70>/Chart' */
} DW_Slope_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S54>/Sync' */
typedef struct {
  DW_PI_App_T PI;                      /* '<S130>/PI' */
} DW_Sync_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S54>/Dischg' */
typedef struct {
  boolean_T Relay_Mode;                /* '<S64>/Relay' */
} DW_Dischg_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S62>/PhaseStudy' */
typedef struct {
  real32_T StudyResult;                /* '<S83>/Chart' */
  real32_T IdRefSet;                   /* '<S83>/Chart' */
  real32_T AngleRefSet;                /* '<S83>/Chart' */
  real32_T ThetaRTHis;                 /* '<S83>/Chart' */
  real32_T ThetaDelta;                 /* '<S83>/Chart' */
  uint16_T StudyStep;                  /* '<S83>/Chart' */
  uint16_T is_active_c10_APP_FluxWeak_GEAR;/* '<S83>/Chart' */
  uint16_T is_c10_APP_FluxWeak_GEAR2;  /* '<S83>/Chart' */
  uint16_T is_Study;                   /* '<S83>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S83>/Chart' */
} DW_PhaseStudy_APP_FluxWeak_GE_T;

/* Block signals and states (auto storage) for system '<S62>/Hall' */
typedef struct {
  real32_T StudyResult;                /* '<S80>/Chart' */
  real32_T IdRefSet;                   /* '<S80>/Chart' */
  real32_T ExSpd;                      /* '<S80>/Chart' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S94>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S80>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S80>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S93>/Discrete-Time Integrator' */
  uint16_T temporalCounter_i1;         /* '<S80>/Chart' */
  uint16_T is_active_c27_APP_FluxWeak_GEAR;/* '<S80>/Chart' */
  uint16_T is_c27_APP_FluxWeak_GEAR2;  /* '<S80>/Chart' */
  uint16_T is_Study;                   /* '<S80>/Chart' */
} DW_Hall_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S62>/ElecZeroStudy' */
typedef struct {
  real32_T StudyResult;                /* '<S78>/Chart' */
  real32_T IdRefSet;                   /* '<S78>/Chart' */
  real32_T IqRefSet;                   /* '<S78>/Chart' */
  real32_T AngleRefSet;                /* '<S78>/Chart' */
  real32_T CalibZeroPoint;             /* '<S78>/Chart' */
  uint16_T IdIqSetEn;                  /* '<S78>/Chart' */
  uint16_T AngleSetEn;                 /* '<S78>/Chart' */
  uint16_T StudyStep;                  /* '<S78>/Chart' */
  uint16_T ZeroStudyCnt;               /* '<S78>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S78>/Chart' */
  uint16_T is_active_c11_APP_FluxWeak_GEAR;/* '<S78>/Chart' */
  uint16_T is_c11_APP_FluxWeak_GEAR2;  /* '<S78>/Chart' */
  uint16_T is_Study;                   /* '<S78>/Chart' */
  uint16_T is_ZeroPoint1;              /* '<S78>/Chart' */
} DW_ElecZeroStudy_APP_FluxWeak_T;

/* Block signals and states (auto storage) for system '<S62>/IdqStudy' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S95>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S96>/Discrete-Time Integrator' */
} DW_IdqStudy_APP_FluxWeak_GEAR_T;

/* Block signals and states (auto storage) for system '<S62>/FluxLinkage' */
typedef struct {
  real32_T CalibAng;                   /* '<S79>/Chart' */
  real32_T IsReq;                      /* '<S79>/Chart' */
  real32_T DelayInput2_DSTATE;         /* '<S87>/Delay Input2' */
  real32_T DelayInput2_DSTATE_g;       /* '<S88>/Delay Input2' */
  uint16_T temporalCounter_i1;         /* '<S79>/Chart' */
  uint16_T is_active_c9_APP_FluxWeak_GEAR2;/* '<S79>/Chart' */
  uint16_T is_AngCount;                /* '<S79>/Chart' */
  uint16_T is_work;                    /* '<S79>/Chart' */
  uint16_T is_Stop;                    /* '<S79>/Chart' */
} DW_FluxLinkage_APP_FluxWeak_G_T;

/* Block signals and states (auto storage) for system '<S62>/MtpaStudy' */
typedef struct {
  real32_T IsRef;                      /* '<S82>/Chart' */
  real32_T AngRef;                     /* '<S82>/Chart' */
  uint16_T count;                      /* '<S82>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S82>/Chart' */
  uint16_T is_active_c26_APP_FluxWeak_GEAR;/* '<S82>/Chart' */
  uint16_T is_c26_APP_FluxWeak_GEAR2;  /* '<S82>/Chart' */
  uint16_T is_Mtpa;                    /* '<S82>/Chart' */
} DW_MtpaStudy_APP_FluxWeak_GEA_T;

/* Block signals and states (auto storage) for system '<S54>/Calib' */
typedef struct {
  DW_MtpaStudy_APP_FluxWeak_GEA_T MtpaStudy;/* '<S62>/MtpaStudy' */
  DW_FluxLinkage_APP_FluxWeak_G_T FluxLinkage;/* '<S62>/FluxLinkage' */
  DW_IdqStudy_APP_FluxWeak_GEAR_T IdqStudy;/* '<S62>/IdqStudy' */
  DW_ElecZeroStudy_APP_FluxWeak_T ElecZeroStudy;/* '<S62>/ElecZeroStudy' */
  DW_Hall_APP_FluxWeak_GEAR2_T Hall;   /* '<S62>/Hall' */
  DW_PhaseStudy_APP_FluxWeak_GE_T PhaseStudy;/* '<S62>/PhaseStudy' */
  uint16_T CalibStep_start;            /* '<S62>/Chart1' */
  uint16_T is_active_c15_APP_FluxWeak_GEAR;/* '<S62>/Chart1' */
  uint16_T is_Sel_mode;                /* '<S62>/Chart1' */
} DW_Calib_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S54>/UVW_check' */
typedef struct {
  DW_LPF_App_T lpf_c;                  /* '<S137>/lpf' */
  DW_LPF_App_T lpf_e;                  /* '<S136>/lpf' */
  DW_LPF_App_T lpf;                    /* '<S135>/lpf' */
  real32_T IdRefSet;                   /* '<S75>/Chart' */
  real32_T AngleRefSet;                /* '<S75>/Chart' */
  uint16_T IdIqSetEn;                  /* '<S75>/Chart' */
  uint16_T AngleSetEn;                 /* '<S75>/Chart' */
  uint16_T UVW_offline;                /* '<S75>/Chart' */
  uint16_T is_active_c28_APP_FluxWeak_GEAR;/* '<S75>/Chart' */
  uint16_T is_c28_APP_FluxWeak_GEAR2;  /* '<S75>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S75>/Chart' */
} DW_UVW_check_APP_FluxWeak_GEA_T;

/* Block signals and states (auto storage) for system '<S150>/Function-Call Subsystem' */
typedef struct {
  DW_PI_App_T PI;                      /* '<S152>/PI' */
} DW_FunctionCallSubsystem_AP_g_T;

/* Block signals and states (auto storage) for system '<S150>/Chart' */
typedef struct {
  DW_FunctionCallSubsystem_AP_g_T FunctionCallSubsystem;/* '<S150>/Function-Call Subsystem' */
  uint16_T is_active_c25_APP_FluxWeak_GEAR;/* '<S150>/Chart' */
} DW_Chart_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  DW_LPF_App_T lpf_p;                  /* '<S189>/lpf' */
  DW_LPF_App_T lpf;                    /* '<S188>/lpf' */
  DW_LPF_App_T lpf_pi;                 /* '<S182>/lpf' */
  DW_LPF_App_T lpf_c;                  /* '<S179>/lpf' */
  DW_Chart_APP_FluxWeak_GEAR2_T sf_Chart_c;/* '<S156>/Chart' */
  DW_Chart_APP_FluxWeak_GEAR2_T sf_Chart_lj;/* '<S150>/Chart' */
  DW_UVW_check_APP_FluxWeak_GEA_T UVW_check;/* '<S54>/UVW_check' */
  DW_Calib_APP_FluxWeak_GEAR2_T Calib; /* '<S54>/Calib' */
  DW_Dischg_APP_FluxWeak_GEAR2_T Dischg;/* '<S54>/Dischg' */
  DW_Sync_APP_FluxWeak_GEAR2_T Sync;   /* '<S54>/Sync' */
  DW_Slope_APP_FluxWeak_GEAR2_T Slope; /* '<S54>/Slope' */
  DW_Starter_APP_FluxWeak_GEAR2_T Starter;/* '<S54>/Starter' */
  DW_Genrate_APP_FluxWeak_GEAR2_T Genrate;/* '<S54>/Genrate' */
  DW_Spd_APP_FluxWeak_GEAR2_T Spd_g;   /* '<S54>/Spd' */
  DW_Torque_APP_FluxWeak_GEAR2_T Torque;/* '<S54>/Torque' */
  DW_LPF_App_T lpf_i;                  /* '<S49>/lpf' */
  DW_LPF_App_T lpf_e;                  /* '<S48>/lpf' */
  real32_T out[3];                     /* '<S29>/Chart2' */
  real32_T out_e[2];                   /* '<S29>/Chart1' */
  real32_T Merge1;                     /* '<S54>/Merge1' */
  real32_T IdRefSet_i;
  real32_T AlgoT;
  real32_T IqRefSet_m;
  real32_T AngleRefSet_e;
  real32_T CalibZeroPoint_f;
  real32_T TqReq_k;
  real32_T PwmFreq;
  real32_T PwmT;
  real32_T TqMax;                      /* '<S60>/Function Caller' */
  real32_T TqReal;                     /* '<S60>/Product' */
  real32_T ZeroPointBias;              /* '<S60>/Constant' */
  real32_T LimtCoef;
  real32_T OVLimTP;
  real32_T OVLimTN;
  real32_T OVLimTP_g;
  real32_T OVLimTN_m;
  real32_T DisChg_coef;                /* '<S30>/Chart3' */
  real32_T DiscreteTimeIntegrator1_a;  /* '<S51>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_c;  /* '<S50>/Discrete-Time Integrator1' */
  real32_T MotCoef;
  real32_T InvCoef;
  real32_T OSLimTP;
  real32_T OSLimTN;
  real32_T BlockState;                 /* '<S17>/Chart' */
  real32_T FaultLimTP;                 /* '<S11>/MinMax1' */
  real32_T FaultLimTN;                 /* '<S11>/MinMax2' */
  real32_T MinMax;                     /* '<S11>/MinMax' */
  real32_T PrevY;                      /* '<S27>/Rate Limiter' */
  real32_T DisChg_time;                /* '<S25>/Chart1' */
  real32_T PrevY_i;                    /* '<S11>/Rate Limiter' */
  uint32_T VoltCode[4];
  uint32_T VoltCode_m[4];              /* '<S30>/Chart3' */
  uint32_T LogicalOperator1[2];        /* '<S29>/Logical Operator1' */
  uint32_T LogicalOperator2[3];        /* '<S29>/Logical Operator2' */
  uint32_T TempCode[6];
  uint32_T TempCode_g[6];              /* '<S28>/Chart' */
  uint32_T SpdCode[2];
  uint32_T SpdCode_o[2];               /* '<S27>/Chart1' */
  uint32_T FaultCode1;
  uint32_T OutportBufferForDisChg;     /* '<S25>/Chart1' */
  uint32_T BitwiseOperator;            /* '<S12>/Bitwise Operator' */
  int16_T chartAbsoluteTimeCounter;    /* '<S1>/Chart' */
  int16_T durationLastReferenceTick_1; /* '<S1>/Chart' */
  uint16_T tick;                       /* '<S173>/Chart' */
  uint16_T AscEn_l;
  uint16_T IdIqSetEn_d;
  uint16_T AngleSetEn_c;
  uint16_T OutportBufferForUVWFault;   /* '<S75>/Chart' */
  uint16_T PwmWorkMode;
  uint16_T OutportBufferForPwmWorkMode;/* '<S11>/Chart' */
  uint16_T RunSt;                      /* '<S1>/Chart' */
  uint16_T FaultSt;                    /* '<S1>/Chart' */
  uint16_T ModeSt;                     /* '<S1>/Chart' */
  uint16_T UnitDelay_DSTATE;           /* '<S2>/Unit Delay' */
  uint16_T ModeSt_start;               /* '<S54>/Chart' */
  uint16_T is_active_c20_APP_FluxWeak_GEAR;/* '<S142>/Chart1' */
  uint16_T is_c20_APP_FluxWeak_GEAR2;  /* '<S142>/Chart1' */
  uint16_T is_active_c2_APP_FluxWeak_GEAR2;/* '<S54>/Chart' */
  uint16_T is_c2_APP_FluxWeak_GEAR2;   /* '<S54>/Chart' */
  uint16_T is_sys_mode;                /* '<S54>/Chart' */
  uint16_T is_Speed;                   /* '<S54>/Chart' */
  uint16_T is_appoint;                 /* '<S54>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S54>/Chart' */
  uint16_T is_active_c3_APP_FluxWeak_GEAR2;/* '<S1>/Chart' */
  uint16_T is_c3_APP_FluxWeak_GEAR2;   /* '<S1>/Chart' */
  uint16_T is_Prepare;                 /* '<S1>/Chart' */
  boolean_T Compare;                   /* '<S32>/Compare' */
  boolean_T Relay_Mode;                /* '<S30>/Relay' */
  boolean_T condWasTrueLastTime_1;     /* '<S1>/Chart' */
  boolean_T method_MODE;               /* '<S2>/method' */
} DW_APP_FluxWeak_GEAR2_T;

/* Real-time Model Data Structure */
struct tag_RTM_APP_FluxWeak_GEAR2_T {
  const char_T * volatile errorStatus;
};

/* Block signals and states (auto storage) */
extern DW_APP_FluxWeak_GEAR2_T APP_FluxWeak_GEAR2_DW;

/* External data declarations for dependent source files */
extern const PMSM_Input_bus APP_FluxWeak_GEAR2_rtZPMSM_Input_bus;/* PMSM_Input_bus ground */
extern const Algo_Output_bus APP_FluxWeak_GEAR2_rtZAlgo_Output_bus;/* Algo_Output_bus ground */
extern const App_Output_bus APP_FluxWeak_GEAR2_rtZApp_Output_bus;/* App_Output_bus ground */
extern const AppFun_inspect_bus APP_FluxWeak_GEAR2_rtZAppFun_inspect_bus;/* AppFun_inspect_bus ground */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern PMSM_Input_bus PMSM_Input;      /* Simulink.Signal object 'PMSM_Input' */
extern App_Output_bus App_Output;      /* Simulink.Signal object 'App_Output' */
extern Algo_Output_bus Algo_Output;    /* Simulink.Signal object 'Algo_Output' */
extern AppFun_inspect_bus AppFun;      /* Simulink.Signal object 'AppFun' */

/* Model entry point functions */
extern void APP_FluxWeak_GEAR2_initialize(void);
extern void APP_FluxWeak_GEAR2_step(void);

/* Real-time Model object */
extern RT_MODEL_APP_FluxWeak_GEAR2_T *const APP_FluxWeak_GEAR2_M;

/* Exported data declaration */

/* Declaration for custom storage class: ExportToFile */
extern PMSM_Param_bus PMSM_Param;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Constant1' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S89>/Data Type Propagation' : Unused code path elimination
 * Block '<S90>/Data Type Duplicate' : Unused code path elimination
 * Block '<S90>/Data Type Propagation' : Unused code path elimination
 * Block '<S102>/Data Type Duplicate' : Unused code path elimination
 * Block '<S102>/Data Type Propagation' : Unused code path elimination
 * Block '<S103>/Data Type Duplicate' : Unused code path elimination
 * Block '<S103>/Data Type Propagation' : Unused code path elimination
 * Block '<S104>/Data Type Duplicate' : Unused code path elimination
 * Block '<S104>/Data Type Propagation' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/Data Type Propagation' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Data Type Propagation' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/Data Type Propagation' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/Data Type Propagation' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Data Type Propagation' : Unused code path elimination
 * Block '<S76>/P2' : Unused code path elimination
 * Block '<S169>/Product' : Unused code path elimination
 * Block '<S12>/Shift Arithmetic' : Eliminated trivial shift
 * Block '<S2>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S127>/Gain2' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'APP_FluxWeak_GEAR2'
 * '<S1>'   : 'APP_FluxWeak_GEAR2/StateMachine'
 * '<S2>'   : 'APP_FluxWeak_GEAR2/implement'
 * '<S3>'   : 'APP_FluxWeak_GEAR2/inputdata_process'
 * '<S4>'   : 'APP_FluxWeak_GEAR2/outputdata_process'
 * '<S5>'   : 'APP_FluxWeak_GEAR2/StateMachine/Chart'
 * '<S6>'   : 'APP_FluxWeak_GEAR2/StateMachine/Chart2'
 * '<S7>'   : 'APP_FluxWeak_GEAR2/implement/Compare To Constant'
 * '<S8>'   : 'APP_FluxWeak_GEAR2/implement/Fault'
 * '<S9>'   : 'APP_FluxWeak_GEAR2/implement/Power'
 * '<S10>'  : 'APP_FluxWeak_GEAR2/implement/method'
 * '<S11>'  : 'APP_FluxWeak_GEAR2/implement/Fault/Act'
 * '<S12>'  : 'APP_FluxWeak_GEAR2/implement/Fault/Code'
 * '<S13>'  : 'APP_FluxWeak_GEAR2/implement/Fault/Compare To Constant1'
 * '<S14>'  : 'APP_FluxWeak_GEAR2/implement/Fault/Compare To Constant5'
 * '<S15>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment'
 * '<S16>'  : 'APP_FluxWeak_GEAR2/implement/Fault/Act/Chart'
 * '<S17>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block'
 * '<S18>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Can'
 * '<S19>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant'
 * '<S20>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant1'
 * '<S21>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant2'
 * '<S22>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant3'
 * '<S23>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant4'
 * '<S24>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant5'
 * '<S25>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/DisChg'
 * '<S26>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Simulink Function'
 * '<S27>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Spd'
 * '<S28>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Temp'
 * '<S29>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor'
 * '<S30>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Volt'
 * '<S31>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block/Chart'
 * '<S32>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block/Compare To Constant1'
 * '<S33>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block/Subsystem'
 * '<S34>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block/Subsystem/Compare To Constant1'
 * '<S35>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block/Subsystem/Compare To Constant2'
 * '<S36>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/DisChg/Chart1'
 * '<S37>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/DisChg/Compare To Constant'
 * '<S38>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Spd/Chart1'
 * '<S39>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Temp/Chart'
 * '<S40>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Chart1'
 * '<S41>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Chart2'
 * '<S42>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant1'
 * '<S43>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant2'
 * '<S44>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant3'
 * '<S45>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant4'
 * '<S46>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant5'
 * '<S47>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant6'
 * '<S48>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/LPF_100ms'
 * '<S49>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/LPF_100ms1'
 * '<S50>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/LPF_100ms/lpf'
 * '<S51>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/LPF_100ms1/lpf'
 * '<S52>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Volt/Chart3'
 * '<S53>'  : 'APP_FluxWeak_GEAR2/implement/Power/Compare To Constant'
 * '<S54>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop'
 * '<S55>'  : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault'
 * '<S56>'  : 'APP_FluxWeak_GEAR2/implement/method/Req2Is&&Spd2f'
 * '<S57>'  : 'APP_FluxWeak_GEAR2/implement/method/Simulink Function'
 * '<S58>'  : 'APP_FluxWeak_GEAR2/implement/method/Simulink Function1'
 * '<S59>'  : 'APP_FluxWeak_GEAR2/implement/method/Simulink Function2'
 * '<S60>'  : 'APP_FluxWeak_GEAR2/implement/method/Table '
 * '<S61>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/ASC'
 * '<S62>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib'
 * '<S63>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Chart'
 * '<S64>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Dischg'
 * '<S65>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Genrate'
 * '<S66>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Initial'
 * '<S67>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Initial_D'
 * '<S68>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim'
 * '<S69>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/LimAct'
 * '<S70>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope'
 * '<S71>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Spd'
 * '<S72>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Starter'
 * '<S73>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Sync'
 * '<S74>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Torque'
 * '<S75>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check'
 * '<S76>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Update'
 * '<S77>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Chart1'
 * '<S78>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/ElecZeroStudy'
 * '<S79>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage'
 * '<S80>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Hall'
 * '<S81>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/IdqStudy'
 * '<S82>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/MtpaStudy'
 * '<S83>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/PhaseStudy'
 * '<S84>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Tlin'
 * '<S85>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/ElecZeroStudy/Chart'
 * '<S86>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage/Chart'
 * '<S87>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage/RateLim'
 * '<S88>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage/RateLim1'
 * '<S89>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage/RateLim/Saturation Dynamic'
 * '<S90>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage/RateLim1/Saturation Dynamic'
 * '<S91>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Hall/Chart'
 * '<S92>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Hall/Compare To Constant'
 * '<S93>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Hall/Inertia1'
 * '<S94>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Hall/Inertia2'
 * '<S95>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/IdqStudy/Inertia1'
 * '<S96>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/IdqStudy/Inertia2'
 * '<S97>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/MtpaStudy/Chart'
 * '<S98>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/PhaseStudy/Chart'
 * '<S99>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Genrate/Subsystem3'
 * '<S100>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Genrate/Subsystem3/PI'
 * '<S101>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Chart'
 * '<S102>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic'
 * '<S103>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic1'
 * '<S104>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic2'
 * '<S105>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic3'
 * '<S106>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic4'
 * '<S107>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic5'
 * '<S108>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/LimAct/Saturation Dynamic'
 * '<S109>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Chart'
 * '<S110>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/SlopeTimer'
 * '<S111>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop'
 * '<S112>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select'
 * '<S113>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/spd_loop'
 * '<S114>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/SlopeTimer/Function-Call Subsystem'
 * '<S115>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop/Damper'
 * '<S116>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop/LPF'
 * '<S117>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop/Damper/LPF'
 * '<S118>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop/Damper/LPF/lpf'
 * '<S119>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop/LPF/lpf'
 * '<S120>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Chart'
 * '<S121>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Function-Call Subsystem'
 * '<S122>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Function-Call Subsystem1'
 * '<S123>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Function-Call Subsystem2'
 * '<S124>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Initial'
 * '<S125>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Function-Call Subsystem2/Saturation Dynamic'
 * '<S126>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/spd_loop/PI'
 * '<S127>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Spd/Subsystem3'
 * '<S128>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Starter/Subsystem3'
 * '<S129>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Starter/Subsystem3/PI'
 * '<S130>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Sync/Subsystem3'
 * '<S131>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Sync/Subsystem3/PI'
 * '<S132>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Torque/LPF'
 * '<S133>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Torque/LPF/lpf'
 * '<S134>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/Chart'
 * '<S135>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_50ms'
 * '<S136>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_50ms1'
 * '<S137>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_50ms2'
 * '<S138>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_50ms/lpf'
 * '<S139>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_50ms1/lpf'
 * '<S140>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_50ms2/lpf'
 * '<S141>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/Fault'
 * '<S142>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI'
 * '<S143>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimSpd'
 * '<S144>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimT&P'
 * '<S145>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/Chart'
 * '<S146>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/Chart1'
 * '<S147>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg'
 * '<S148>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv'
 * '<S149>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/Feedforward'
 * '<S150>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/PI'
 * '<S151>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/PI/Chart'
 * '<S152>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/PI/Function-Call Subsystem'
 * '<S153>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/PI/Lim_state'
 * '<S154>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/PI/Function-Call Subsystem/PI'
 * '<S155>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/Feedforward'
 * '<S156>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/PI'
 * '<S157>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/PI/Chart'
 * '<S158>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/PI/Function-Call Subsystem'
 * '<S159>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/PI/Lim_state'
 * '<S160>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/PI/Function-Call Subsystem/PI'
 * '<S161>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimSpd/Compare To Constant'
 * '<S162>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimSpd/Compare To Constant1'
 * '<S163>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimSpd/Subsystem3'
 * '<S164>' : 'APP_FluxWeak_GEAR2/implement/method/Req2Is&&Spd2f/Freq'
 * '<S165>' : 'APP_FluxWeak_GEAR2/implement/method/Req2Is&&Spd2f/Period'
 * '<S166>' : 'APP_FluxWeak_GEAR2/implement/method/Req2Is&&Spd2f/Req2Is'
 * '<S167>' : 'APP_FluxWeak_GEAR2/implement/method/Req2Is&&Spd2f/Freq/RandNum'
 * '<S168>' : 'APP_FluxWeak_GEAR2/implement/method/Req2Is&&Spd2f/Req2Is/Calib_Ismax'
 * '<S169>' : 'APP_FluxWeak_GEAR2/implement/method/Req2Is&&Spd2f/Req2Is/Calib_Tlin'
 * '<S170>' : 'APP_FluxWeak_GEAR2/implement/method/Req2Is&&Spd2f/Req2Is/Chart'
 * '<S171>' : 'APP_FluxWeak_GEAR2/implement/method/Req2Is&&Spd2f/Req2Is/NoCalib'
 * '<S172>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization'
 * '<S173>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem'
 * '<S174>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem1'
 * '<S175>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem2'
 * '<S176>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem3'
 * '<S177>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem4'
 * '<S178>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem/Chart'
 * '<S179>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem/LPF_100ms'
 * '<S180>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem/LPF_100ms/lpf'
 * '<S181>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem1/LPF_100ms'
 * '<S182>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem1/LPF_300ms'
 * '<S183>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem1/inertia 500ms '
 * '<S184>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem1/LPF_100ms/lpf'
 * '<S185>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem1/LPF_300ms/lpf'
 * '<S186>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem1/inertia 500ms /Chart'
 * '<S187>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem1/inertia 500ms /RateLim'
 * '<S188>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem2/LPF'
 * '<S189>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem2/LPF_200ms'
 * '<S190>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem2/LPF/lpf'
 * '<S191>' : 'APP_FluxWeak_GEAR2/inputdata_process/Filter&Normalization/Subsystem2/LPF_200ms/lpf'
 * '<S192>' : 'APP_FluxWeak_GEAR2/outputdata_process/Subsystem'
 * '<S193>' : 'APP_FluxWeak_GEAR2/outputdata_process/Subsystem1'
 * '<S194>' : 'APP_FluxWeak_GEAR2/outputdata_process/data_process'
 */
#endif                                 /* RTW_HEADER_APP_FluxWeak_GEAR2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
