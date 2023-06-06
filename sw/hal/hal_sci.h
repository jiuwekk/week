//! \file       hal_sci.h
//! \brief      Contains public interface to various functions related to the SCI module
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_SCI_H_
#define _HAL_SCI_H_

//! @defgroup HAL_SCI HAL_SCI
//! @{

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// the typedefs

typedef enum
{
	SCI_BAUDRATES_300 = 9374,
	SCI_BAUDRATES_600 = 4687,
	SCI_BAUDRATES_1200 = 2343,
	SCI_BAUDRATES_2400 = 1171,
	SCI_BAUDRATES_4800 = 585,
	SCI_BAUDRATES_9600 = 292,
	SCI_BAUDRATES_19200 = 145,
	SCI_BAUDRATES_38400 = 72,
	SCI_BAUDRATES_43000 = 64,
	SCI_BAUDRATES_56000 = 49,
	SCI_BAUDRATES_57600 = 48,
	SCI_BAUDRATES_115200 = 23
}SCI_BAUDRATES_e;

typedef enum
{
	SCI_MODULE_A = 0,
	SCI_MODULE_B = 1
}SCI_MODULE_e;


// ============================================================================
// the function prototypes

//! \brief     Sets up the sci peripheral
//! \param[in] spiHandle  The serial peripheral interface (SCI) object handle
extern void HAL_setupSci(SCI_Handle sciHandle);

// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_SCI

#endif /* _HAL_SCI_H_ */
