//! \file       hal_spi.h
//! \brief      Contains public interface to various functions related to the SPI module
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL

#ifndef _HAL_SPI_H_
#define _HAL_SPI_H_

//! @defgroup HAL_SPI HAL_SPI
//! @{

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// the function prototypes

//! \brief     Sets up the spi peripheral
//! \param[in] spiHandle  The serial peripheral interface (SPI) object handle
extern void HAL_setupSpi(SPI_Handle spiHandle);


//! \brief     Sets up the spi peripheral
//! \param[in] spiHandle  The serial peripheral interface (SPI) object handle
static inline void HAL_WriteResolver(SPI_Handle spiHandle)
{
	SPI_write(spiHandle,0x5555);
}

//! \brief     Sets up the spi peripheral
//! \param[in] spiHandle  The serial peripheral interface (SPI) object handle
static inline uint32_t HAL_ReadResolver(SPI_Handle spiHandle)
{
	while(SPI_getRxFifoStatus(spiHandle)==SPI_FifoStatus_Empty){}
	return (SPI_read(spiHandle)&0x0FFF);
}

extern uint16_t AD2S1205_Read(SPI_Handle spiHandle); //4.145us µ≤‚
// ============================================================================

#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_SPI

#endif /* _HAL_SPI_H_ */
