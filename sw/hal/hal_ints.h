//! \file       hal_ints.h
//! \brief      Contains public interface to various functions related to the PIE module
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_INTS_H_
#define _HAL_INTS_H_

//! @defgroup HAL_INTS HAL_INTS
//! @{

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// the function prototypes


//! \brief      Initializes the interrupt vector table
//! \details    Points ADCINT1 to ADC_ISR
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
static inline void HAL_initIntVectorTable(HAL_Handle handle)
 {
  HAL_Obj *obj = (HAL_Obj *)handle;
  PIE_Obj *pie = (PIE_Obj *)obj->pieHandle;


  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  pie->ADCINT1 = &ADC_ISR;

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
 } // end of HAL_initIntVectorTable() function


//! \brief      Enables the debug interrupt
//! \details    The debug interrupt is used for the real-time debugger.  It is
//!             not needed if the real-time debugger is not used.  Clears
//!             bit 1 of ST1.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_enableDebugInt(HAL_Handle handle);


//! \brief      Disables global interrupts
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_disableGlobalInts(HAL_Handle handle);


//! \brief     Enables global interrupts
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_enableGlobalInts(HAL_Handle handle);


//! \brief     Sets up the PIE (Peripheral Interrupt Expansion)
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupPie(HAL_Handle handle);


// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_INTS

#endif /* _HAL_INTS_H_ */
