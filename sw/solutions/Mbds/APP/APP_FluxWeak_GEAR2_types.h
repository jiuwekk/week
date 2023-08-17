/*
 * File: APP_FluxWeak_GEAR2_types.h
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

#ifndef RTW_HEADER_APP_FluxWeak_GEAR2_types_h_
#define RTW_HEADER_APP_FluxWeak_GEAR2_types_h_
#include "rtwtypes.h"
#include "PMSM_IO_bus.h"
#include "PMSM_Param.h"
#include "App_inspect_bus.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_0dIFsaqwgsOE09z6RqQvYF_
#define DEFINED_TYPEDEF_FOR_struct_0dIFsaqwgsOE09z6RqQvYF_

typedef struct {
  uint32_T SpdCode[2];
  real32_T OSLimTP;
  real32_T OSLimTN;
} struct_0dIFsaqwgsOE09z6RqQvYF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_lUbhpEbrfBjnhsD61iEgkH_
#define DEFINED_TYPEDEF_FOR_struct_lUbhpEbrfBjnhsD61iEgkH_

typedef struct {
  uint32_T TempCode[6];
  real32_T MotCoef;
  real32_T InvCoef;
} struct_lUbhpEbrfBjnhsD61iEgkH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_GerdNmw3BaSDTJ1X81gJd_
#define DEFINED_TYPEDEF_FOR_struct_GerdNmw3BaSDTJ1X81gJd_

typedef struct {
  real32_T MotTemp;
  real32_T InvTemp;
  uint32_T Code[5];
} struct_GerdNmw3BaSDTJ1X81gJd;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Otvt4JWz9eDbvhSDOhbWNF_
#define DEFINED_TYPEDEF_FOR_struct_Otvt4JWz9eDbvhSDOhbWNF_

typedef struct {
  uint32_T VoltCode[4];
  real32_T OVLimTP;
  real32_T OVLimTN;
} struct_Otvt4JWz9eDbvhSDOhbWNF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_3AFNM7LuHTT5ESbiZT5kDF_
#define DEFINED_TYPEDEF_FOR_struct_3AFNM7LuHTT5ESbiZT5kDF_

typedef struct {
  real32_T LimtCoef;
  uint16_T PwmWorkMode;
  real32_T OVLimTP;
  real32_T OVLimTN;
  uint32_T FaultCode1;
} struct_3AFNM7LuHTT5ESbiZT5kDF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_hirn2xlQ0qYwA5W5dbxqaD_
#define DEFINED_TYPEDEF_FOR_struct_hirn2xlQ0qYwA5W5dbxqaD_

typedef struct {
  uint16_T AscEn;
  real32_T IdRefSet;
  real32_T IqRefSet;
  real32_T AngleRefSet;
  uint16_T IdIqSetEn;
  uint16_T AngleSetEn;
  real32_T TqReq;
  real32_T PwmFreq;
  real32_T PwmT;
  real32_T AlgoT;
} struct_hirn2xlQ0qYwA5W5dbxqaD;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_APP_FluxWeak_GEAR2_T RT_MODEL_APP_FluxWeak_GEAR2_T;

#endif                                 /* RTW_HEADER_APP_FluxWeak_GEAR2_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
