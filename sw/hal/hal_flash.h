//! \file       hal_flash.h
//! \brief      Contains public interface to various functions related to the FLASH module
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_FLASH_H_
#define _HAL_FLASH_H_

//! @defgroup HAL_FLASH HAL_FLASH
//! @{

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// the function prototypes


//! \brief     Sets up the FLASH.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupFlash(HAL_Handle handle);


// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_FLASH

#endif /* _HAL_FLASH_H_ */
