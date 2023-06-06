//! \file       hal_adc.h
//! \brief      Contains public interface to various functions related to the ADC module
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_ADC_H_
#define _HAL_ADC_H_

//! @defgroup HAL_ADC HAL_ADC
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ============================================================================
// the includes


// ============================================================================
// the defines


// ============================================================================
// the typedefs


// ============================================================================
// the globals


// ============================================================================
// the function prototypes

//! \brief Defines the ADC reading of temperature sensor at reference temperature for compensation
#define getRefTempOffset() (*(int16_t (*)(void))0x3D7EA2)()


//! \brief     Gets the ADC delay value
//! \param[in] handle     The hardware abstraction layer (HAL) handle
//! \param[in] socNumber  The ADC SOC number
//! \return    The ADC delay value
static inline ADC_SocSampleDelay_e HAL_getAdcSocSampleDelay(HAL_Handle handle,
                                                            const ADC_SocNumber_e socNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  return(ADC_getSocSampleDelay(obj->adcHandle,socNumber));
} // end of HAL_getAdcSocSampleDelay() function


//! \brief     Sets the ADC SOC sample delay value
//! \param[in] handle       The hardware abstraction layer (HAL) handle
//! \param[in] socNumber    The SOC number
//! \param[in] sampleDelay  The delay value for the ADC
static inline void HAL_setAdcSocSampleDelay(HAL_Handle handle,
                                            const ADC_SocNumber_e socNumber,
                                            const ADC_SocSampleDelay_e sampleDelay)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  ADC_setSocSampleDelay(obj->adcHandle,socNumber,sampleDelay);

  return;
} // end of HAL_setAdcSocSampleDelay() function


//! \brief     Acknowledges an interrupt from the ADC so that another ADC interrupt can
//!            happen again.
//! \param[in] handle     The hardware abstraction layer (HAL) handle
//! \param[in] intNumber  The interrupt number
static inline void HAL_acqAdcInt(HAL_Handle handle,const ADC_IntNumber_e intNumber)
{
  HAL_Obj *obj = (HAL_Obj *)handle;


  // clear the ADC interrupt flag
  ADC_clearIntFlag(obj->adcHandle,intNumber);


  // Acknowledge interrupt from PIE group 10
  PIE_clearInt(obj->pieHandle,PIE_GroupNumber_10);

  return;
} // end of HAL_acqAdcInt() function


//! \brief      Enables the ADC interrupts
//! \details    Enables the ADC interrupt in the PIE, and CPU.  Enables the
//!             interrupt to be sent from the ADC peripheral.
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_enableAdcInts(HAL_Handle handle);


//! \brief     Selects the analog channel used for calibration
//! \param[in] handle      The hardware abstraction layer (HAL) handle
//! \param[in] chanNumber  The channel number
void HAL_AdcCalChanSelect(HAL_Handle handle, const ADC_SocChanNumber_e chanNumber);


//! \brief     Reads the converted value from the selected calibration channel
//! \param[in] handle     The hardware abstraction layer (HAL) handle
//! \return    The converted value
uint16_t HAL_AdcCalConversion(HAL_Handle handle);


//! \brief     Executes the offset calibration of the ADC
//! \param[in] handle     The hardware abstraction layer (HAL) handle
void HAL_AdcOffsetSelfCal(HAL_Handle handle);


//! \brief      Sets up the ADCs (Analog to Digital Converters)
//! \param[in]  handle  The hardware abstraction layer (HAL) handle
extern void HAL_setupAdcs(HAL_Handle handle);


extern interrupt void ADC_ISR(void);


// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_ADC

#endif /* _HAL_ADC_H_ */
