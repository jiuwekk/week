// ================================================================================================
//! \file       LookupTable.h
//! \brief      
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017Äê6ÔÂ15ÈÕ
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _LOOKUPTABLE_H_
#define _LOOKUPTABLE_H_

//! @defgroup LOOKUPTABLE LOOKUPTABLE
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
float LookupTab_1Dxy(float xIn, const float* Tab, int32_t xMaxIndx);
float LookupTab_2Dxyz(float xIn,float yIn, const float* Tab, int32_t xMaxIndx, int32_t yMaxIndx);
float LookupTab_2Dxzy(float xIn,float zIn, const float* Tab, int32_t xMaxIndx, int32_t yMaxIndx);

// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of LOOKUPTABLE

#endif // end of _LOOKUPTABLE_H_
