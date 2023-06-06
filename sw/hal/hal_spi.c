//! \file       hal_spi.c
//! \brief      Contains various functions related to the SPI object
//! \author     sunyanjun
//! \version    1.0
//! \date       2017.03.21
//! \copyright  SANTROLL


#if EVCBD_ID == 0x08 || EVCBD_ID == 0x09 || EVCBD_ID == 0x0D
void HAL_setupSpi(SPI_Handle spiHandle)
{
      SPI_reset(spiHandle);
      SPI_setClkPolarity(spiHandle,SPI_ClkPolarity_OutputFallingEdge_InputRisingEdge);
      SPI_disableLoopBack(spiHandle);

      SPI_setCharLength(spiHandle,SPI_CharLength_16_Bits);

      SPI_setMode(spiHandle,SPI_Mode_Master);
      SPI_setClkPhase(spiHandle,SPI_ClkPhase_Normal);
      SPI_enableTx(spiHandle);

      SPI_enableChannels(spiHandle);
      SPI_enableTxFifoEnh(spiHandle);
      SPI_enableTxFifo(spiHandle);
      SPI_setTxDelay(spiHandle,0);
      SPI_clearTxFifoInt(spiHandle);
      SPI_enableRxFifo(spiHandle);

      SPI_setBaudRate(spiHandle,(SPI_BaudRate_e)(0x0000));

      SPI_setSuspend(spiHandle,SPI_TxSuspend_free);
      SPI_enable(spiHandle);
  return;
}
// end of HAL_setupSpiA() function
uint16_t AD2S1205_Read(SPI_Handle spiHandle) //4.145us实测
{
     static uint16_t  RDC_Data=0;
    //实测3.785us 硬件SPI 5.625MHZ 手册说明需要配置IO
     asm(" EALLOW");
     RDC_SAMPLE_L(halHandle);
     RDC_RD_L(halHandle);
     asm(" EDIS");
     SPI_write(spiHandle,0x5555);
     while(SPI_getRxFifoStatus(spiHandle)==SPI_FifoStatus_Empty){}
     RDC_Data= SPI_read(spiHandle);
     asm(" EALLOW");
     RDC_RD_H(halHandle);
     RDC_SAMPLE_H(halHandle);
     asm(" EDIS");
     return (RDC_Data);

//     asm(" EALLOW");
//     halHandle->gpioHandle->GPBCLEAR = (uint32_t)1 << (7);  //GPIO50 RDC_SAMPLE_L(halHandle);
//     halHandle->gpioHandle->GPBCLEAR = (uint32_t)1 << (18); //GPIO12 RDC_RD_L(halHandle);
//     asm(" EDIS");
//     SPI_write(spiHandle,0x5555);
//     while(SPI_getRxFifoStatus(spiHandle)==SPI_FifoStatus_Empty){}
//     RDC_Data= SPI_read(spiHandle);
//     asm(" EALLOW");
//     halHandle->gpioHandle->GPBSET = (uint32_t)1 << (18);       // RDC_RD_H(halHandle);
//     halHandle->gpioHandle->GPBSET = (uint32_t)1 << (7);        // RDC_SAMPLE_H(halHandle);
//     asm(" EDIS");
//     return (RDC_Data);

}
#else
void HAL_setupSpi(SPI_Handle spiHandle)
{
  SPI_reset(spiHandle);
  SPI_setClkPolarity(spiHandle,SPI_ClkPolarity_OutputFallingEdge_InputRisingEdge);
  SPI_disableLoopBack(spiHandle);
  SPI_setCharLength(spiHandle,SPI_CharLength_12_Bits);
  SPI_setMode(spiHandle,SPI_Mode_Master);
  SPI_setClkPhase(spiHandle,SPI_ClkPhase_Normal);
  SPI_enableTx(spiHandle);
  SPI_enableChannels(spiHandle);
  SPI_enableTxFifoEnh(spiHandle);
  SPI_enableTxFifo(spiHandle);
  SPI_setTxDelay(spiHandle,0);
  SPI_clearTxFifoInt(spiHandle);
  SPI_enableRxFifo(spiHandle);
  SPI_setBaudRate(spiHandle,(SPI_BaudRate_e)(0x000B));
  SPI_setSuspend(spiHandle,SPI_TxSuspend_free);
  SPI_enable(spiHandle);

  return;
}  // end of HAL_setupSpiA() function
#endif
