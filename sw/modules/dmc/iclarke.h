// ================================================================================================
//! \file       iclarke.h
//! \brief      
//! \author     jiangkun
//! \version    1.0.0
//! \date       2017Äê4ÔÂ5ÈÕ
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _ICLARKE_H_
#define _ICLARKE_H_

//! @defgroup ICLARKE ICLARKE
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// the includes


// ================================================================================================
// the defines
#define ICLARKE_DEFAULTS {  0,\
                            0,\
                            0,\
                            0,\
                            0,\
                            (void (*)(long))park_calc }

// ================================================================================================
// the typedefs

typedef struct {  float  Alpha;         //!< [in] stationary alpha-axis stator variable
                  float  Beta;          //!< [in] stationary beta-axis stator variable
                  float  A;             //!< [out] stationary A stator variable
                  float  B;             //!< [out] stationary B stator variable
                  float  C;             //!< [out] stationary C stator variable
                  void  (*calc)();      //!< Pointer to calculation function
               }ICLARKE;
// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes


//! \brief     iclarke calc
//! \param[in] v        Handle to ICLARKE object
extern void iclarke_calc(ICLARKE* v);

// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of ICLARKE

#endif // end of _ICLARKE_H_
