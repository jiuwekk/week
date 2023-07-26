/*
 * File: PMSM_IO_bus.h
 *
 * Code generated for Simulink model 'APP_FluxWeak_GEAR2'.
 *
 * Model version                  : 2.6
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jul 25 15:05:30 2023
 */

#ifndef RTW_HEADER_PMSM_IO_bus_h_
#define RTW_HEADER_PMSM_IO_bus_h_
#include "rtwtypes.h"

typedef struct {
  real32_T Speed;
  real32_T ThetaRT;
  real32_T CurUPu;
  real32_T CurVPu;
  real32_T CurWPu;
  real32_T CurBus;
  real32_T VoltU;
  real32_T VoltV;
  real32_T VoltW;
  uint16_T PosSenFaultState1;
  uint16_T PosSenFaultState2;
  uint16_T IGBT1FaultState;
  uint16_T IGBT2FaultState;
  uint16_T IGBT3FaultState;
} AgoSample_monitor_bus;

typedef struct {
  real32_T TqReq;
  real32_T SpdReq;
  real32_T TqUpperLim;
  real32_T TqLowerLim;
  real32_T SpdUpperLim;
  real32_T SpdLowerLim;
  real32_T DrvLimCur;
  real32_T GenLimCur;
  uint16_T GateReq;
  uint16_T MainRelayState;
  uint16_T GearState;
  uint16_T ModeReq;
  uint16_T CanMsg1Lost;
  uint16_T CanMsg2Lost;
} AppComm_monitor_bus;

typedef struct {
  real32_T MotTemp1;
  real32_T MotTemp2;
  real32_T InvTemp1;
  real32_T InvTemp2;
  real32_T InvTemp3;
  real32_T VoltCap;
  real32_T VoltCap_compensate;
  uint16_T AnaInput1AD;
  uint16_T AnaInput2AD;
  uint16_T AnaInput3AD;
  uint16_T KsiSt;
  uint16_T BrkSt;
  uint16_T DrvMode;
  uint16_T Sw1InputSt;
  uint16_T Sw2InputSt;
  uint16_T Sw3InputSt;
  uint16_T ReadyFin;
  real32_T ExtTorque;
  uint16_T ElecZeroStep;
  real32_T CalibMTPATheta;
  uint16_T CalibStep;
} AppSample_monitor_bus;

typedef struct {
  real32_T Svpwm_Ta;
  real32_T Svpwm_Tb;
  real32_T Svpwm_Tc;
  uint16_T PwmWorkMode;
} IGBT_ctrl_ctrl_bus;

typedef struct {
  real32_T Id;
  real32_T Iq;
  real32_T Ud;
  real32_T Uq;
  real32_T Vs;
} Cur_loop_ctrl_bus;

typedef struct {
  real32_T LimtCoef;
  uint16_T PwmWorkMode;
  uint32_T FaultCode1;
} fault_ctrl_bus;

typedef struct {
  uint16_T RunSt;
  uint16_T ModeSt;
} state_ctrl_bus;

typedef struct {
  uint16_T KeepPowerEn;
  uint16_T DRV1_En;
  uint16_T DRV2_En;
} power_ctrl_bus;

typedef struct {
  real32_T TqMax;
  real32_T TqReal;
  real32_T ZeroPointBias;
} table_ctrl_bus;

typedef struct {
  uint32_T IGBT;
  uint32_T OC1;
  uint32_T OC2;
  uint32_T OV3;
  uint32_T LV3;
  uint32_T PosSen;
} Fault_ctrl_bus;

typedef struct {
  uint16_T AscEn;
  real32_T IdRefSet;
  real32_T IqRefSet;
  real32_T AngleRefSet;
  uint16_T IdIqSetEn;
  uint16_T AngleSetEn;
  real32_T CalibZeroPoint;
  real32_T TqReq;
  real32_T PwmFreq;
  real32_T PwmT;
  real32_T AlgoT;
} ctrl_ctrl_bus;

typedef struct {
  real32_T NmFil;
  real32_T VoltCapFil;
  real32_T CurBusFil;
  real32_T MotTemp;
  real32_T InvTemp;
  uint16_T tick;
} data_process_ctrl_bus;

typedef struct {
  AppSample_monitor_bus AppSample;
  AppComm_monitor_bus AppComm;
  AgoSample_monitor_bus AgoSample;
} PMSM_Input_bus;

typedef struct {
  data_process_ctrl_bus data_process;
  table_ctrl_bus table;
  fault_ctrl_bus fault;
  state_ctrl_bus state;
  power_ctrl_bus power;
  ctrl_ctrl_bus ctrl;
} App_Output_bus;

typedef struct {
  IGBT_ctrl_ctrl_bus IGBT_ctrl;
  Cur_loop_ctrl_bus Cur_loop;
  Fault_ctrl_bus Fault;
} Algo_Output_bus;

#endif                                 /* RTW_HEADER_PMSM_IO_bus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
