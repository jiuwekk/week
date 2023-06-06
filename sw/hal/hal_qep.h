//! \file       hal_qep.h
//! \brief      Contains public interface to various functions related to the QEP module
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_QEP_H_
#define _HAL_QEP_H_

//! @defgroup HAL_QEP HAL_QEP
//! @{

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// the defines

#define EQEP_CAPTURE_PERIOD    3		//Unit,ms;
#define EQEP_QCPRD             (EQEP_CAPTURE_PERIOD * HAL_SYSTEM_FREQ_MHz * 1000.0L)
#define EQEP_SPEED_MAX         (60.0*1000.0/EQEP_CAPTURE_PERIOD)


// ============================================================================
// the typedefs

typedef struct
{
	float   Lines;      //!< [in]     ת��תһȦ����������������������������

	float   Speedrpm;   //!< [out]    �����еת��
	int32_t Direction;  //!< [out]    �����ת����

	int32_t TurnMax;    //!< [inner]  ת��תһȦ�������������ɼ���λ�������������ı�Ƶ
	int32_t PosMax;     //!< [inner]  ת��ת��Ȧ�������������ɼ���λ�������������ı�Ƶ
	float   K;          //!< [inner]  ת�ٻ���ϵ��
	int32_t Pos;        //!< [inner]
	int32_t PosOld;     //!< [inner]
	int32_t PosDelta;   //!< [inner]

	void     (*SpeedMeasMInit)(); //!< Pointer to obj init function
	void     (*SpeedMeasM)();	  //!< Pointer to the Speed Cal function
}SPEED_MEAS_M;
#define SPEED_MEAS_QEP_DEFAULTS { 0,0,0,0,0,0,0,0,0,\
		                         (void (*)(long))SpeedMeasMInit,\
                                 (void (*)(long))SpeedMeasM}


//! \brief Enumeration for the QEP setup
//!
typedef enum
{
  HAL_Qep_QEP1=0,  //!< Select QEP1
  HAL_Qep_QEP2=1   //!< Select QEP2
} HAL_QepSelect_e;


// ============================================================================
// the function prototypes

//! \brief Reads status register
//! \param[in] qepHandle        Handle to QEP object
//! \return                     Status register value
inline uint16_t QEP_get_status (QEP_Handle qepHandle, const QEP_qepsts_e qepsts)
{
  return((qepHandle->QEPSTS&qepsts)>0);
} // end of QEP_read_status () function

//! \brief     Returns the maximum position count from QEP
//! \param[in] qepHandle        Handle to QEP object
//! \return    the maximum position count from QEP
static inline uint32_t HAL_getQepPosnMaximum(QEP_Handle Handle)
{
	return Handle->QPOSMAX;
}


//! \brief     Sets up the QEP peripheral
//! \param[in] qepHandle        Handle to QEP object
extern void HAL_setupQEP(QEP_Handle Handle);


//! \brief     Speed Object Init
//! \param[in] qepHandle        Handle to QEP object
//! \param[in] spdHandle        Handle to Speed object
extern void SpeedMeasMInit(QEP_Handle qepHandle,SPEED_MEAS_M* spdHandle);


//! \brief     Speed Measure Via QEP [Max1.420us@90MHz]
//! \param[in] qepHandle        Handle to QEP object
//! \param[in] spdHandle        Handle to Speed object
extern void SpeedMeasM(QEP_Handle qepHandle,SPEED_MEAS_M* spdHandle);


// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_QEP

#endif /* _HAL_QEP_H_ */
