// ================================================================================================
//! \file       MainISR.h
//! \brief      包含主中断主体函数
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL
// ================================================================================================

#ifndef _MAINISR_H_
#define _MAINISR_H_

#define ISR_DBG_EN  0

//! @defgroup MAINISR MAINISR
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================

extern void  Main_ISR(void);
extern float IsMaxCalc(float n);
extern float TLinCalc(float n, float tn);
extern float TLimCalc(float n);
extern float RampFilter(float Ref,float Now,float Up,float Down);

extern float BusCurReadOm(float Vs);
extern void  BusCurCalc(void);
//extern  float ELCUCMsg[3000];
//extern uint16_t BlcdeAAACount;
//extern uint16_t ElcErrCount;
extern float ELCUCMsg[10000] ;
//extern  float CurMax ;
// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of MAINISR

#endif // end of _MAINISR_H_
