// ================================================================================================
//! \file       hal_i2c.c
//! \brief      Contains various functions related to the I2C object
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017年3月23日
//! \copyright  SANTROLL.
// ================================================================================================


I2C_Handle I2C_init(void *pMemory,const size_t numBytes)
{
  if(numBytes < sizeof(I2C_Obj))
    return((I2C_Handle)NULL);

  return((I2C_Handle)pMemory);
} // end of I2C_init() function


void HAL_setupI2C(I2C_Handle Handle)
{
	I2C_Prescaler(Handle, I2C_IPSC);    //!< Prescaler - need 7-12 MHz on module clk
	I2C_clkLowTime(Handle, I2C_ICCL);   //!< NOTE: must be non zero
	I2C_clkHighTime(Handle, I2C_ICCH);  //!< NOTE: must be non zero

	I2C_OwnAdd(Handle, I2C_OWN_ADD);
	I2C_SlvAdd(Handle, I2C_SLV_ADD);

	Handle->I2CIER.all = 0x0000;		//!< Disable I2C interrupt requests
	Handle->I2CFFTX.all = 0x6040;		//!< Enable FIFO mode and TXFIFO,clear TXFFINT
	Handle->I2CFFRX.all = 0x2044;		//!< Enable RXFIFO, clear RXFFINT
	Handle->I2CMDR.all = 0x0020;
	Handle->I2CEMDR.all = 0x0000;
}


void I2C_Stateflow(I2C_Handle Handle, I2CMSG *Msg)
{
	static int16_t Step  = 0;   //!< 当前读写操作的步骤;
	static int16_t Timer = 0;	//!< 读写超时定时器;
	static int16_t Index = 0;	//!< 当前字节在Buffer中的下标

	//-------------------------------------------------------------------------
	//空闲
	if(Msg->State == I2C_STATE_IDLE)
	{
		Step = 0;
		Handle->I2CSTR.bit.NACK = 1;
	}

	//-------------------------------------------------------------------------
	//读状态,曾试过的字节数:1,2,4,5,8,9,16,17,31,32
	else if(Msg->State == I2C_STATE_READING)
	{
		if(Handle->I2CSTR.bit.NACK == 1)
		{
			Step = 0;
			Msg->State = I2C_STATE_IDLE;
			Msg->ReadStatus = I2C_FAIL;
			Handle->I2CSTR.bit.NACK = 1;
		}
		else
		{
			if(Step == 0)
			{
				Step++;
				Timer = 0;
				Index = 0;
				Handle->I2CDXR = EEPROM_WR_CONTROL_BYTE;
				Handle->I2CDXR = Msg->HighAddr;
				Handle->I2CDXR = Msg->LowAddr;
				Handle->I2CCNT = 3;
				Handle->I2CMDR.all = 0x6E28;
			}
			else if(Step == 1)
			{
				Step++;
				Handle->I2CFFRX.bit.RXFFINTCLR = 1;
				Handle->I2CSAR = (EEPROM_RD_CONTROL_BYTE>>1);
				Handle->I2CCNT = Msg->ValidBytes;
				Handle->I2CFFRX.bit.RXFFIL = (Msg->ValidBytes > 3)?4:Msg->ValidBytes;
				Handle->I2CMDR.all = 0x6C20;
			}
			else if(Step == 2)
			{
				if(Handle->I2CFFRX.bit.RXFFINT)
				{
					Timer = 0;
					Handle->I2CFFRX.bit.RXFFINTCLR = 1;
					if(Index >= Msg->ValidBytes)
					{
						Step = 0;
						Msg->State = I2C_STATE_IDLE;
						Msg->ReadStatus = I2C_SUCCESS;
					}
					else if(Index >= (Msg->ValidBytes - 4))
					{
						while(Index < Msg->ValidBytes)
						{
							Msg->Buffer[Index++] = Handle->I2CDRR;
						}
					}
					else
					{
						Msg->Buffer[Index++] = Handle->I2CDRR;
						Msg->Buffer[Index++] = Handle->I2CDRR;
						Msg->Buffer[Index++] = Handle->I2CDRR;
						Msg->Buffer[Index++] = Handle->I2CDRR;
						Handle->I2CFFRX.bit.RXFFIL = (Msg->ValidBytes - Index)>3?4:(Msg->ValidBytes - Index);
						Handle->I2CMDR.all = 0x4C20;
					}
				}
				else
				{
					if(Timer < 2)
					{
						Timer++;
					}
					else
					{
						Step = 0;
						Msg->State = I2C_STATE_IDLE;
						Msg->ReadStatus = I2C_FAIL;
					}
				}
			}
		}
	}

	//-------------------------------------------------------------------------
	//写状态,曾试过的字节数: 1,2,4,5,8,9,16,17,31,32
	else if(Msg->State == I2C_STATE_WRITING)
	{
		if(Handle->I2CSTR.bit.NACK == 1)
		{
			Step = 0;
			Msg->State = I2C_STATE_IDLE;
			Msg->WriteStatus = I2C_FAIL;
			Handle->I2CSTR.bit.NACK = 1;
		}
		else
		{
			if(Step == 0)
			{
				Step++;
				Timer = 0;
				Index = 0;
				Handle->I2CFFTX.bit.TXFFINTCLR = 1;
				Handle->I2CDXR = EEPROM_WR_CONTROL_BYTE;
				Handle->I2CDXR = Msg->HighAddr;
				Handle->I2CDXR = Msg->LowAddr;
				Handle->I2CCNT = Msg->ValidBytes + 3;
				Handle->I2CMDR.all = 0x6E28;
			}
			else if(Step == 1)
			{
				if(Handle->I2CFFTX.bit.TXFFINT)
				{
					Timer = 0;
					Handle->I2CFFTX.bit.TXFFINTCLR = 1;
					if(Index >= Msg->ValidBytes)
					{
						Step = 0;
						Msg->State = I2C_STATE_IDLE;
						Msg->WriteStatus = I2C_SUCCESS;
					}
					else if(Index >= (Msg->ValidBytes - 4))
					{
						while(Index < Msg->ValidBytes)
						{
							Handle->I2CDXR = Msg->Buffer[Index++];
						}
						Handle->I2CMDR.all = 0x4E28;
					}
					else
					{
						Handle->I2CDXR = Msg->Buffer[Index++];
						Handle->I2CDXR = Msg->Buffer[Index++];
						Handle->I2CDXR = Msg->Buffer[Index++];
						Handle->I2CDXR = Msg->Buffer[Index++];
						Handle->I2CMDR.all = 0x4E28;
					}
				}
				else
				{
					if(Timer < 2)
					{
						Timer++;
					}
					else
					{
						Step = 0;
						Msg->State = I2C_STATE_IDLE;
						Msg->WriteStatus = I2C_FAIL;
					}
				}
			}
		}
	}

	//-------------------------------------------------------------------------
	//未知状态
	else
	{
		Step = 0;
		Msg->State = I2C_STATE_IDLE;
	}
}


void I2C_EEProm_Reset(GPIO_Handle gpioHandle)
{
	GPIO_setMode(gpioHandle,M1_I2C_SDA_GPIO,(GPIO_Mode_e)0);
	GPIO_setMode(gpioHandle,M1_I2C_SCL_GPIO,(GPIO_Mode_e)0);

	GPIO_setHigh(gpioHandle,M1_I2C_SDA_GPIO);
	GPIO_setHigh(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SDA_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SDA_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SDA_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SCL_GPIO);
	Delay_us(1);GPIO_toggle(gpioHandle,M1_I2C_SDA_GPIO);

	GPIO_setMode(gpioHandle,M1_I2C_SDA_GPIO,M1_I2C_SDA_MODE);
	GPIO_setMode(gpioHandle,M1_I2C_SCL_GPIO,M1_I2C_SCL_MODE);
}
// ================================================================================================
// end of hal_i2c.c
