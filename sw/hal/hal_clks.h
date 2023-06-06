//! \file       hal_clks.h
//! \brief      Contains public interface to various functions related to the CLKS module
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_CLKS_H_
#define _HAL_CLKS_H_

//! @defgroup HAL_CLKS HAL_CLKS
//! @{

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// the defines


//! \brief Defines used in oscillator calibration functions
//! \brief Defines the scale factor for Q15 fixed point numbers (2^15)
#define FP_SCALE 32768

//! \brief Defines the quantity added to Q15 numbers before converting to integer to round the number
#define FP_ROUND FP_SCALE/2

//! \brief Defines the amount to add to Q16.15 fixed point number to shift from a fine trim range of
//! \brief (-31 to 31) to (1 to 63).  This guarantees that the trim is positive and can
//! \brief therefore be efficiently rounded
#define OSC_POSTRIM 32
#define OSC_POSTRIM_OFF FP_SCALE*OSC_POSTRIM


// ============================================================================
// the function prototypes

//! \brief The following functions return reference values stored in OTP.

//! \brief Defines the slope used to compensate oscillator 1 (fine trim steps / ADC code). Stored in fixed point Q15 format
#define getOsc1FineTrimSlope() (*(int16_t (*)(void))0x3D7E90)()

//! \brief Defines the oscillator 1 fine trim at high temp
#define getOsc1FineTrimOffset() (*(int16_t (*)(void))0x3D7E93)()

//! \brief Defines the oscillator 1 coarse trim
#define getOsc1CoarseTrim() (*(int16_t (*)(void))0x3D7E96)()

//! \brief Defines the slope used to compensate oscillator 2 (fine trim steps / ADC code). Stored
//! \brief in fixed point Q15 format.
#define getOsc2FineTrimSlope() (*(int16_t (*)(void))0x3D7E99)()

//! \brief Defines the oscillator 2 fine trim at high temp
#define getOsc2FineTrimOffset() (*(int16_t (*)(void))0x3D7E9C)()

//! \brief Defines the oscillator 2 coarse trim
#define getOsc2CoarseTrim() (*(int16_t (*)(void))0x3D7E9F)()


//! \brief      Sets up the clocks
//! \details    Sets up the micro-controller's main oscillator
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupClks(HAL_Handle handle);


//! \brief     Sets up the peripheral clocks
//! \param[in] handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupPeripheralClks(HAL_Handle handle);


//! \brief     Sets up the PLL (Phase Lock Loop)
//! \param[in] handle   The hardware abstraction layer (HAL) handle
//! \param[in] clkFreq  The clock frequency
extern void HAL_setupPll(HAL_Handle handle,const PLL_ClkFreq_e clkFreq);


//! \brief     Executes the oscillator 1 and 2 calibration functions
//! \param[in] handle     The hardware abstraction layer (HAL) handle
void HAL_OscTempComp(HAL_Handle handle);


//! \brief     Executes the oscillator 1 calibration based on input sample
//! \param[in] handle     The hardware abstraction layer (HAL) handle
void HAL_osc1Comp(HAL_Handle handle, const int16_t sensorSample);


//! \brief     Executes the oscillator 2 calibration based on input sample
//! \param[in] handle     The hardware abstraction layer (HAL) handle
void HAL_osc2Comp(HAL_Handle handle, const int16_t sensorSample);


//! \brief     Converts coarse and fine oscillator trim values into a single 16bit word value
//! \param[in] handle     The hardware abstraction layer (HAL) handle
//! \param[in] coarse     The coarse trim portion of the oscillator trim
//! \param[in] fine       The fine trim portion of the oscillator trim
//! \return    The combined trim value
uint16_t HAL_getOscTrimValue(int16_t coarse, int16_t fine);


//! \brief      Disables the watch dog
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_disableWdog(HAL_Handle handle);


// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_CLKS

#endif /* _HAL_CLKS_H_ */
