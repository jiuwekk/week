// ================================================================================================
//! \file       MainLoop.h
//! \brief      包含主循环主体函数
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL
// ================================================================================================

#ifndef _MAINLOOP_H_
#define _MAINLOOP_H_

//! @defgroup MAINLOOP MAINLOOP
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================
// the function prototypes

extern uint32_t TotalRunTimePwrOn; //!< [0.1s]   总运行时间,上电时刻
extern uint32_t TotalRunTime     ; //!< [0.1s]   总运行时间
extern uint32_t SingleRunTime    ; //!< [0.1s]   单次运行时间

//! \brief 主循环函数，周期性被调用，调用周期
extern  void Main_Loop(void);
#if Modle_or_Handecode == 1
#else
extern  void Mot_Ctrl(void);
extern  void Mot_ZeroTorqueMod(void);
extern  void Mot_TorqeMod(void);
extern  void Mot_SpeedMod(void);
extern  void Mot_SlopeMod(void);
extern  void Mot_ActiveDischargeMod(void);
extern void PwmChangeFreq(void);
extern void IdcLimit(void);
extern void Lpf_MainLoop(void);
extern void TqMaxOutLimit(void);
extern void IsRefCalc(void);
#endif


extern  void ParmRefresh(void);
extern  void LEDFlash(void);
extern  void RunTime(void);

extern void AscCondJudeg(void);

extern void MbdAppCommInput(void);
extern void MbdAppOut(void);
extern void MbdFaultToBsw(void);
extern void MbdAppSampInput(void);
// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of MAINLOOP

#endif // end of _MAINLOOP_H_
