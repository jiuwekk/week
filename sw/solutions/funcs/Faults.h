// ================================================================================================
//! \file       Faults.h
//! \brief      
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017Äê5ÔÂ3ÈÕ
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _FAULTS_H_
#define _FAULTS_H_

//! @defgroup FAULTS FAULTS
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// the includes


// ================================================================================================
// the defines


// ================================================================================================
// the typedefs


// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes
extern void FaultChkSlow(void);
extern void FaultChkFast(void);
#if Modle_or_Handecode == 1
#else
extern void FaultLmtCtrl(void);
#endif
extern void AcOverCur2ErrChk(void);    //(1,1)
extern void AcOverCur1ErrChk(void);    //(1,2)
extern void DcOverCur1ErrChk(void);    //(1,3)
extern void DcOverVolt3ErrChk(void);   //(1,4)
extern void DcOverVolt21ErrChk(void);  //(1,5)(1,6)
extern void DcUnderVoltErrChk(void);   //(1,7)(1,8)(2,1)
extern void MotOverTempErrChk(void);   //(2,2)(2,3)(2,4)
extern void InvOverTempErrChk(void);   //(2,5)(2,6)(2,7)
extern void OverSpeed1ErrChk(void);    //(2,8)
extern void OverSpeed2ErrChk(void);    //(3,1)
extern void PosSensorErrChk(void);     //(3,2)
extern void MotStallErrChk(void);      //(3,3)
extern void CurSensorErrChk(void);     //(3,4)
extern void LogicPowerErrChk(void);    //(3,5)
extern void PwrMdlErrChk(void);        //(3,6)
extern void PhaseBrkErrChk(void);      //(3,7)
extern void ParErrChk(void);           //(3,8)
extern void MotTempSensorErrChk(void); //(4,1)
extern void InvTempSensorErrChk(void); //(4,2)
extern void MsgLostErrChk(void);       //(4,3)(4,4)
extern void Main_DNC_ErrChk(void);     //(4,5)
extern void PreChargeErrChk(void);     //(4,6)
extern void CanBusErrChk(void);        //(4,7)
extern void ParChangeErrChk(void);     //
extern void DisChgErrChk(void);        //

extern void IdcLmtCutBack(void);

// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of FAULTS

#endif // end of _FAULTS_H_
