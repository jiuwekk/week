/*
 * File: APP_FluxWeak_GEAR2.h
 *
 * Code generated for Simulink model 'APP_FluxWeak_GEAR2'.
 *
 * Model version                  : 2.6
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Aug 17 14:23:34 2023
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

/* Block signals and states (auto storage) for system '<S50>/lpf' */
typedef struct {
  real32_T LPF_STATE;                  /* '<S52>/Discrete-Time Integrator1' */
} DW_LPF_App_T;

/* Block signals and states (auto storage) for system '<S56>/Torque' */
typedef struct {
  DW_LPF_App_T lpf;                    /* '<S134>/lpf' */
} DW_Torque_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S56>/Spd' */
typedef struct {
  real32_T Spd_D_Int;                  /* '<S129>/Discrete-Time Integrator1' */
  real32_T Spd_state;                  /* '<S129>/Discrete-Time Integrator' */
} DW_Spd_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S101>/PI' */
typedef struct {
  real32_T I_state;                    /* '<S102>/Discrete-Time Integrator1' */
} DW_PI_App_T;

/* Block signals and states (auto storage) for system '<S56>/Genrate' */
typedef struct {
  DW_PI_App_T PI;                      /* '<S101>/PI' */
} DW_Genrate_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S56>/Starter' */
typedef struct {
  DW_PI_App_T PI;                      /* '<S130>/PI' */
} DW_Starter_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S112>/Function-Call Subsystem' */
typedef struct {
  real32_T Slope_state;                /* '<S116>/Discrete-Time Integrator' */
} DW_FunctionCallSubsystem_APP__T;

/* Block signals and states (auto storage) for system '<S114>/Function-Call Subsystem2' */
typedef struct {
  real32_T N_state;                    /* '<S125>/Delay Input2' */
} DW_FunctionCallSubsystem2_APP_T;

/* Block signals and states (auto storage) for system '<S56>/Slope' */
typedef struct {
  DW_PI_App_T PI;                      /* '<S115>/PI' */
  DW_FunctionCallSubsystem2_APP_T FunctionCallSubsystem2;/* '<S114>/Function-Call Subsystem2' */
  DW_LPF_App_T lpf_a;                  /* '<S118>/lpf' */
  DW_LPF_App_T lpf;                    /* '<S119>/lpf' */
  DW_FunctionCallSubsystem_APP__T FunctionCallSubsystem;/* '<S112>/Function-Call Subsystem' */
  real32_T Merge;                      /* '<S114>/Merge' */
  real32_T SpdReqPu_out;               /* '<S72>/Chart' */
  real32_T DiscreteTimeIntegrator;     /* '<S116>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S72>/Unit Delay' */
  uint16_T Gear_start;                 /* '<S114>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S72>/Chart' */
  uint16_T GearState_start;            /* '<S72>/Chart' */
  uint16_T is_active_c19_APP_FluxWeak_GEAR;/* '<S114>/Chart' */
  uint16_T is_Gear;                    /* '<S114>/Chart' */
  uint16_T is_active_c4_APP_FluxWeak_GEAR2;/* '<S72>/Chart' */
  uint16_T is_c4_APP_FluxWeak_GEAR2;   /* '<S72>/Chart' */
  uint16_T is_move;                    /* '<S72>/Chart' */
  uint16_T is_D;                       /* '<S72>/Chart' */
  uint16_T is_R;                       /* '<S72>/Chart' */
} DW_Slope_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S56>/Sync' */
typedef struct {
  DW_PI_App_T PI;                      /* '<S132>/PI' */
} DW_Sync_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S56>/Dischg' */
typedef struct {
  boolean_T Relay_Mode;                /* '<S66>/Relay' */
} DW_Dischg_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S64>/PhaseStudy' */
typedef struct {
  real32_T StudyResult;                /* '<S85>/Chart' */
  real32_T IdRefSet;                   /* '<S85>/Chart' */
  real32_T AngleRefSet;                /* '<S85>/Chart' */
  real32_T ThetaRTHis;                 /* '<S85>/Chart' */
  real32_T ThetaDelta;                 /* '<S85>/Chart' */
  uint16_T StudyStep;                  /* '<S85>/Chart' */
  uint16_T is_active_c10_APP_FluxWeak_GEAR;/* '<S85>/Chart' */
  uint16_T is_c10_APP_FluxWeak_GEAR2;  /* '<S85>/Chart' */
  uint16_T is_Study;                   /* '<S85>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S85>/Chart' */
} DW_PhaseStudy_APP_FluxWeak_GE_T;

/* Block signals and states (auto storage) for system '<S64>/Hall' */
typedef struct {
  real32_T StudyResult;                /* '<S82>/Chart' */
  real32_T IdRefSet;                   /* '<S82>/Chart' */
  real32_T ExSpd;                      /* '<S82>/Chart' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S96>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S82>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S82>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_h;/* '<S95>/Discrete-Time Integrator' */
  uint16_T temporalCounter_i1;         /* '<S82>/Chart' */
  uint16_T is_active_c27_APP_FluxWeak_GEAR;/* '<S82>/Chart' */
  uint16_T is_c27_APP_FluxWeak_GEAR2;  /* '<S82>/Chart' */
  uint16_T is_Study;                   /* '<S82>/Chart' */
} DW_Hall_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S64>/ElecZeroStudy' */
typedef struct {
  real32_T StudyResult;                /* '<S80>/Chart' */
  real32_T IdRefSet;                   /* '<S80>/Chart' */
  real32_T IqRefSet;                   /* '<S80>/Chart' */
  real32_T AngleRefSet;                /* '<S80>/Chart' */
  real32_T CalibZeroPoint;             /* '<S80>/Chart' */
  uint16_T IdIqSetEn;                  /* '<S80>/Chart' */
  uint16_T AngleSetEn;                 /* '<S80>/Chart' */
  uint16_T StudyStep;                  /* '<S80>/Chart' */
  uint16_T ZeroStudyCnt;               /* '<S80>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S80>/Chart' */
  uint16_T is_active_c11_APP_FluxWeak_GEAR;/* '<S80>/Chart' */
  uint16_T is_c11_APP_FluxWeak_GEAR2;  /* '<S80>/Chart' */
  uint16_T is_Study;                   /* '<S80>/Chart' */
  uint16_T is_ZeroPoint1;              /* '<S80>/Chart' */
} DW_ElecZeroStudy_APP_FluxWeak_T;

/* Block signals and states (auto storage) for system '<S64>/IdqStudy' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S97>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_g;/* '<S98>/Discrete-Time Integrator' */
} DW_IdqStudy_APP_FluxWeak_GEAR_T;

/* Block signals and states (auto storage) for system '<S64>/FluxLinkage' */
typedef struct {
  real32_T CalibAng;                   /* '<S81>/Chart' */
  real32_T IsReq;                      /* '<S81>/Chart' */
  real32_T DelayInput2_DSTATE;         /* '<S89>/Delay Input2' */
  real32_T DelayInput2_DSTATE_g;       /* '<S90>/Delay Input2' */
  uint16_T temporalCounter_i1;         /* '<S81>/Chart' */
  uint16_T is_active_c9_APP_FluxWeak_GEAR2;/* '<S81>/Chart' */
  uint16_T is_AngCount;                /* '<S81>/Chart' */
  uint16_T is_work;                    /* '<S81>/Chart' */
  uint16_T is_Stop;                    /* '<S81>/Chart' */
} DW_FluxLinkage_APP_FluxWeak_G_T;

/* Block signals and states (auto storage) for system '<S64>/MtpaStudy' */
typedef struct {
  real32_T IsRef;                      /* '<S84>/Chart' */
  real32_T AngRef;                     /* '<S84>/Chart' */
  uint16_T count;                      /* '<S84>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S84>/Chart' */
  uint16_T is_active_c26_APP_FluxWeak_GEAR;/* '<S84>/Chart' */
  uint16_T is_c26_APP_FluxWeak_GEAR2;  /* '<S84>/Chart' */
  uint16_T is_Mtpa;                    /* '<S84>/Chart' */
} DW_MtpaStudy_APP_FluxWeak_GEA_T;

/* Block signals and states (auto storage) for system '<S56>/Calib' */
typedef struct {
  DW_MtpaStudy_APP_FluxWeak_GEA_T MtpaStudy;/* '<S64>/MtpaStudy' */
  DW_FluxLinkage_APP_FluxWeak_G_T FluxLinkage;/* '<S64>/FluxLinkage' */
  DW_IdqStudy_APP_FluxWeak_GEAR_T IdqStudy;/* '<S64>/IdqStudy' */
  DW_ElecZeroStudy_APP_FluxWeak_T ElecZeroStudy;/* '<S64>/ElecZeroStudy' */
  DW_Hall_APP_FluxWeak_GEAR2_T Hall;   /* '<S64>/Hall' */
  DW_PhaseStudy_APP_FluxWeak_GE_T PhaseStudy;/* '<S64>/PhaseStudy' */
  uint16_T CalibStep_start;            /* '<S64>/Chart1' */
  uint16_T is_active_c15_APP_FluxWeak_GEAR;/* '<S64>/Chart1' */
  uint16_T is_Sel_mode;                /* '<S64>/Chart1' */
} DW_Calib_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<S56>/UVW_check' */
typedef struct {
  DW_LPF_App_T lpf_c;                  /* '<S139>/lpf' */
  DW_LPF_App_T lpf_e;                  /* '<S138>/lpf' */
  DW_LPF_App_T lpf;                    /* '<S137>/lpf' */
  real32_T IdRefSet;                   /* '<S77>/Chart' */
  real32_T AngleRefSet;                /* '<S77>/Chart' */
  uint16_T IdIqSetEn;                  /* '<S77>/Chart' */
  uint16_T AngleSetEn;                 /* '<S77>/Chart' */
  uint16_T UVW_offline;                /* '<S77>/Chart' */
  uint16_T is_active_c28_APP_FluxWeak_GEAR;/* '<S77>/Chart' */
  uint16_T is_c28_APP_FluxWeak_GEAR2;  /* '<S77>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S77>/Chart' */
} DW_UVW_check_APP_FluxWeak_GEA_T;

/* Block signals and states (auto storage) for system '<S152>/Function-Call Subsystem' */
typedef struct {
  DW_PI_App_T PI;                      /* '<S154>/PI' */
} DW_FunctionCallSubsystem_AP_g_T;

/* Block signals and states (auto storage) for system '<S152>/Chart' */
typedef struct {
  DW_FunctionCallSubsystem_AP_g_T FunctionCallSubsystem;/* '<S152>/Function-Call Subsystem' */
  uint16_T is_active_c25_APP_FluxWeak_GEAR;/* '<S152>/Chart' */
} DW_Chart_APP_FluxWeak_GEAR2_T;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  DW_LPF_App_T lpf_p;                  /* '<S189>/lpf' */
  DW_LPF_App_T lpf;                    /* '<S188>/lpf' */
  DW_LPF_App_T lpf_pi;                 /* '<S182>/lpf' */
  DW_LPF_App_T lpf_c;                  /* '<S179>/lpf' */
  DW_Chart_APP_FluxWeak_GEAR2_T sf_Chart_c;/* '<S158>/Chart' */
  DW_Chart_APP_FluxWeak_GEAR2_T sf_Chart_lj;/* '<S152>/Chart' */
  DW_UVW_check_APP_FluxWeak_GEA_T UVW_check;/* '<S56>/UVW_check' */
  DW_Calib_APP_FluxWeak_GEAR2_T Calib; /* '<S56>/Calib' */
  DW_Dischg_APP_FluxWeak_GEAR2_T Dischg;/* '<S56>/Dischg' */
  DW_Sync_APP_FluxWeak_GEAR2_T Sync;   /* '<S56>/Sync' */
  DW_Slope_APP_FluxWeak_GEAR2_T Slope; /* '<S56>/Slope' */
  DW_Starter_APP_FluxWeak_GEAR2_T Starter;/* '<S56>/Starter' */
  DW_Genrate_APP_FluxWeak_GEAR2_T Genrate;/* '<S56>/Genrate' */
  DW_Spd_APP_FluxWeak_GEAR2_T Spd_g;   /* '<S56>/Spd' */
  DW_Torque_APP_FluxWeak_GEAR2_T Torque;/* '<S56>/Torque' */
  DW_LPF_App_T lpf_i;                  /* '<S51>/lpf' */
  DW_LPF_App_T lpf_e;                  /* '<S50>/lpf' */
  real32_T out[3];                     /* '<S31>/Chart2' */
  real32_T out_e[2];                   /* '<S31>/Chart1' */
  real32_T Merge1;                     /* '<S56>/Merge1' */
  real32_T IdRefSet_i;
  real32_T AlgoT;
  real32_T IqRefSet_m;
  real32_T AngleRefSet_e;
  real32_T CalibZeroPoint_f;
  real32_T TqReq_k;
  real32_T PwmFreq;
  real32_T PwmT;
  real32_T TqMax;                      /* '<S62>/Function Caller' */
  real32_T TqReal;                     /* '<S62>/Product' */
  real32_T ZeroPointBias;              /* '<S62>/Constant' */
  real32_T LimtCoef;
  real32_T OVLimTP;
  real32_T OVLimTN;
  real32_T OVLimTP_g;
  real32_T OVLimTN_m;
  real32_T DisChg_coef;                /* '<S32>/Chart3' */
  real32_T DiscreteTimeIntegrator1_a;  /* '<S53>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator1_c;  /* '<S52>/Discrete-Time Integrator1' */
  real32_T MotCoef;
  real32_T InvCoef;
  real32_T OSLimTP;
  real32_T OSLimTN;
  real32_T BlockState;                 /* '<S19>/Chart' */
  real32_T FaultLimTP;                 /* '<S11>/MinMax1' */
  real32_T FaultLimTN;                 /* '<S11>/MinMax2' */
  real32_T MinMax;                     /* '<S11>/MinMax' */
  real32_T DelayInput2_DSTATE;         /* '<S17>/Delay Input2' */
  real32_T PrevY;                      /* '<S29>/Rate Limiter' */
  real32_T DisChg_time;                /* '<S27>/Chart1' */
  uint32_T VoltCode[4];
  uint32_T VoltCode_m[4];              /* '<S32>/Chart3' */
  uint32_T LogicalOperator1[2];        /* '<S31>/Logical Operator1' */
  uint32_T LogicalOperator2[3];        /* '<S31>/Logical Operator2' */
  uint32_T TempCode[6];
  uint32_T TempCode_g[6];              /* '<S30>/Chart' */
  uint32_T SpdCode[2];
  uint32_T SpdCode_o[2];               /* '<S29>/Chart1' */
  uint32_T FaultCode1;
  uint32_T OutportBufferForDisChg;     /* '<S27>/Chart1' */
  uint32_T BitwiseOperator;            /* '<S12>/Bitwise Operator' */
  int16_T chartAbsoluteTimeCounter;    /* '<S1>/Chart' */
  int16_T durationLastReferenceTick_1; /* '<S1>/Chart' */
  uint16_T tick;                       /* '<S173>/Chart' */
  uint16_T AscEn_l;
  uint16_T IdIqSetEn_d;
  uint16_T AngleSetEn_c;
  uint16_T OutportBufferForUVWFault;   /* '<S77>/Chart' */
  uint16_T PwmWorkMode;
  uint16_T OutportBufferForPwmWorkMode;/* '<S11>/Chart' */
  uint16_T RunSt;                      /* '<S1>/Chart' */
  uint16_T FaultSt;                    /* '<S1>/Chart' */
  uint16_T ModeSt;                     /* '<S1>/Chart' */
  uint16_T UnitDelay_DSTATE;           /* '<S2>/Unit Delay' */
  uint16_T ModeSt_start;               /* '<S56>/Chart' */
  uint16_T is_active_c20_APP_FluxWeak_GEAR;/* '<S144>/Chart1' */
  uint16_T is_c20_APP_FluxWeak_GEAR2;  /* '<S144>/Chart1' */
  uint16_T is_active_c2_APP_FluxWeak_GEAR2;/* '<S56>/Chart' */
  uint16_T is_c2_APP_FluxWeak_GEAR2;   /* '<S56>/Chart' */
  uint16_T is_sys_mode;                /* '<S56>/Chart' */
  uint16_T is_Speed;                   /* '<S56>/Chart' */
  uint16_T is_appoint;                 /* '<S56>/Chart' */
  uint16_T temporalCounter_i1;         /* '<S56>/Chart' */
  uint16_T is_active_c3_APP_FluxWeak_GEAR2;/* '<S1>/Chart' */
  uint16_T is_c3_APP_FluxWeak_GEAR2;   /* '<S1>/Chart' */
  uint16_T is_Prepare;                 /* '<S1>/Chart' */
  boolean_T Compare;                   /* '<S34>/Compare' */
  boolean_T Relay_Mode;                /* '<S32>/Relay' */
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
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Propagation' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Propagation' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S92>/Data Type Propagation' : Unused code path elimination
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
 * Block '<S109>/Data Type Duplicate' : Unused code path elimination
 * Block '<S109>/Data Type Propagation' : Unused code path elimination
 * Block '<S110>/Data Type Duplicate' : Unused code path elimination
 * Block '<S110>/Data Type Propagation' : Unused code path elimination
 * Block '<S127>/Data Type Duplicate' : Unused code path elimination
 * Block '<S127>/Data Type Propagation' : Unused code path elimination
 * Block '<S78>/P2' : Unused code path elimination
 * Block '<S169>/Product' : Unused code path elimination
 * Block '<S12>/Shift Arithmetic' : Eliminated trivial shift
 * Block '<S2>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S129>/Gain2' : Eliminated nontunable gain of 1
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
 * '<S17>'  : 'APP_FluxWeak_GEAR2/implement/Fault/Act/rate_lim'
 * '<S18>'  : 'APP_FluxWeak_GEAR2/implement/Fault/Act/rate_lim/Saturation Dynamic'
 * '<S19>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block'
 * '<S20>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Can'
 * '<S21>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant'
 * '<S22>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant1'
 * '<S23>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant2'
 * '<S24>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant3'
 * '<S25>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant4'
 * '<S26>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Compare To Constant5'
 * '<S27>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/DisChg'
 * '<S28>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Simulink Function'
 * '<S29>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Spd'
 * '<S30>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Temp'
 * '<S31>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor'
 * '<S32>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Volt'
 * '<S33>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block/Chart'
 * '<S34>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block/Compare To Constant1'
 * '<S35>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block/Subsystem'
 * '<S36>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block/Subsystem/Compare To Constant1'
 * '<S37>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Block/Subsystem/Compare To Constant2'
 * '<S38>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/DisChg/Chart1'
 * '<S39>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/DisChg/Compare To Constant'
 * '<S40>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Spd/Chart1'
 * '<S41>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Temp/Chart'
 * '<S42>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Chart1'
 * '<S43>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Chart2'
 * '<S44>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant1'
 * '<S45>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant2'
 * '<S46>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant3'
 * '<S47>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant4'
 * '<S48>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant5'
 * '<S49>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/Compare To Constant6'
 * '<S50>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/LPF_100ms'
 * '<S51>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/LPF_100ms1'
 * '<S52>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/LPF_100ms/lpf'
 * '<S53>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/TempSensor/LPF_100ms1/lpf'
 * '<S54>'  : 'APP_FluxWeak_GEAR2/implement/Fault/judgment/Volt/Chart3'
 * '<S55>'  : 'APP_FluxWeak_GEAR2/implement/Power/Compare To Constant'
 * '<S56>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop'
 * '<S57>'  : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault'
 * '<S58>'  : 'APP_FluxWeak_GEAR2/implement/method/Req2Is&&Spd2f'
 * '<S59>'  : 'APP_FluxWeak_GEAR2/implement/method/Simulink Function'
 * '<S60>'  : 'APP_FluxWeak_GEAR2/implement/method/Simulink Function1'
 * '<S61>'  : 'APP_FluxWeak_GEAR2/implement/method/Simulink Function2'
 * '<S62>'  : 'APP_FluxWeak_GEAR2/implement/method/Table '
 * '<S63>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/ASC'
 * '<S64>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib'
 * '<S65>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Chart'
 * '<S66>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Dischg'
 * '<S67>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Genrate'
 * '<S68>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Initial'
 * '<S69>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Initial_D'
 * '<S70>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim'
 * '<S71>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/LimAct'
 * '<S72>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope'
 * '<S73>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Spd'
 * '<S74>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Starter'
 * '<S75>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Sync'
 * '<S76>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Torque'
 * '<S77>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check'
 * '<S78>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Update'
 * '<S79>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Chart1'
 * '<S80>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/ElecZeroStudy'
 * '<S81>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage'
 * '<S82>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Hall'
 * '<S83>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/IdqStudy'
 * '<S84>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/MtpaStudy'
 * '<S85>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/PhaseStudy'
 * '<S86>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Tlin'
 * '<S87>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/ElecZeroStudy/Chart'
 * '<S88>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage/Chart'
 * '<S89>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage/RateLim'
 * '<S90>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage/RateLim1'
 * '<S91>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage/RateLim/Saturation Dynamic'
 * '<S92>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/FluxLinkage/RateLim1/Saturation Dynamic'
 * '<S93>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Hall/Chart'
 * '<S94>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Hall/Compare To Constant'
 * '<S95>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Hall/Inertia1'
 * '<S96>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/Hall/Inertia2'
 * '<S97>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/IdqStudy/Inertia1'
 * '<S98>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/IdqStudy/Inertia2'
 * '<S99>'  : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/MtpaStudy/Chart'
 * '<S100>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Calib/PhaseStudy/Chart'
 * '<S101>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Genrate/Subsystem3'
 * '<S102>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Genrate/Subsystem3/PI'
 * '<S103>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Chart'
 * '<S104>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic'
 * '<S105>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic1'
 * '<S106>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic2'
 * '<S107>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic3'
 * '<S108>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic4'
 * '<S109>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/IntLim/Saturation Dynamic5'
 * '<S110>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/LimAct/Saturation Dynamic'
 * '<S111>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Chart'
 * '<S112>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/SlopeTimer'
 * '<S113>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop'
 * '<S114>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select'
 * '<S115>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/spd_loop'
 * '<S116>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/SlopeTimer/Function-Call Subsystem'
 * '<S117>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop/Damper'
 * '<S118>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop/LPF'
 * '<S119>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop/Damper/LPF'
 * '<S120>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop/Damper/LPF/lpf'
 * '<S121>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_loop/LPF/lpf'
 * '<S122>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Chart'
 * '<S123>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Function-Call Subsystem'
 * '<S124>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Function-Call Subsystem1'
 * '<S125>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Function-Call Subsystem2'
 * '<S126>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Initial'
 * '<S127>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/Tor_select/Function-Call Subsystem2/Saturation Dynamic'
 * '<S128>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Slope/spd_loop/PI'
 * '<S129>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Spd/Subsystem3'
 * '<S130>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Starter/Subsystem3'
 * '<S131>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Starter/Subsystem3/PI'
 * '<S132>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Sync/Subsystem3'
 * '<S133>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Sync/Subsystem3/PI'
 * '<S134>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Torque/LPF'
 * '<S135>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/Torque/LPF/lpf'
 * '<S136>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/Chart'
 * '<S137>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_100ms'
 * '<S138>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_100ms1'
 * '<S139>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_100ms2'
 * '<S140>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_100ms/lpf'
 * '<S141>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_100ms1/lpf'
 * '<S142>' : 'APP_FluxWeak_GEAR2/implement/method/All_loop/UVW_check/LPF_100ms2/lpf'
 * '<S143>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/Fault'
 * '<S144>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI'
 * '<S145>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimSpd'
 * '<S146>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimT&P'
 * '<S147>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/Chart'
 * '<S148>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/Chart1'
 * '<S149>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg'
 * '<S150>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv'
 * '<S151>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/Feedforward'
 * '<S152>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/PI'
 * '<S153>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/PI/Chart'
 * '<S154>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/PI/Function-Call Subsystem'
 * '<S155>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/PI/Lim_state'
 * '<S156>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimChg/PI/Function-Call Subsystem/PI'
 * '<S157>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/Feedforward'
 * '<S158>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/PI'
 * '<S159>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/PI/Chart'
 * '<S160>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/PI/Function-Call Subsystem'
 * '<S161>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/PI/Lim_state'
 * '<S162>' : 'APP_FluxWeak_GEAR2/implement/method/Lim&Fault/LimI/LimDrv/PI/Function-Call Subsystem/PI'
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
