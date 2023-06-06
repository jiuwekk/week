// ================================================================================================
//! \file       hal_i2c.h
//! \brief      Contains public interface to various functions related to the I2C module
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017年3月23日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _HAL_I2C_H_
#define _HAL_I2C_H_

//! @defgroup HAL_I2C HAL_I2C
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// the includes


// ================================================================================================
// the defines

//! \brief Defines the base address of the I2C registers
#define I2CA_BASE_ADDR           (0x00007900)

//-----------------------------------------------------------------------------
// I2C configurations

#define I2C_IPSC                (8)			//!< Module-clock = SYSCLKOUT1_FREQ/(IPSC + 1);
#define I2C_DELAY				(5)			//!< d=7 if IPSC==0, d=6 if IPSC==1, d=5 if IPSC>1;
#define I2C_ICCL				(7)			//!< Mask-clock-low-time  = (ICCL + d)*T_module;
#define I2C_ICCH				(8)			//!< Mask-clock-high-time = (ICCH + d)*T_module;
#define I2C_MASK_CLK			(400000)	//!< Unit:Hz, Mask-clock = SYSCLKOUT1_FREQ/(IPSC + 1)/(ICCL + d + ICCH + d)

#define I2C_SLV_ADD             (0x0000)    //!< Slave Address
#define I2C_OWN_ADD             (0x0000)    //!< Own Address

//-----------------------------------------------------------------------------
//! I2C EEPROM 读写命令
typedef enum
{
	I2C_STATE_IDLE    = 0x0000,  //!< 无论成功失败，读写读写操作完成命令，
	I2C_STATE_WRITING = 0x0001,  //!< 写使能命令，写完成后，状态机会修改该命令为I2C_STATE_IDLE
	I2C_STATE_READING = 0x0002   //!< 读使能命令，读完成后，状态机会修改该命令为I2C_STATE_IDLE
}I2C_CMD_e;

//! I2C EEPROM 读写操作结果
typedef enum
{
	I2C_START    = 0x0000,
	I2C_FAIL     = 0xFFFF,
	I2C_SUCCESS	 = 0x0001
}I2C_RW_STATE_e;

//-----------------------------------------------------------------------------
// I2C_EEPROM defines

#define EEPROM_CHIP_ADDRESS		0x0000		//!< I2C_EEPROM Chip Select Bits
#define EEPROM_CONTROL_CODE		0x00A0		//!< I2C_EEPROM Control Code Bits
#define EEPROM_COMMAND_WRITE	0x0000		//!< I2C_EEPROM Write Bit
#define EEPROM_COMMAND_READ		0x0001		//!< I2C_EEPROM Read  Bit
#define EEPROM_WR_CONTROL_BYTE	(EEPROM_CHIP_ADDRESS | EEPROM_CONTROL_CODE | EEPROM_COMMAND_WRITE)
#define EEPROM_RD_CONTROL_BYTE	(EEPROM_CHIP_ADDRESS | EEPROM_CONTROL_CODE | EEPROM_COMMAND_READ)

// ================================================================================================
// the typedefs

//! I2C Message Structure
typedef struct
{
	 I2C_CMD_e       State;		   //!< Only modify it when it's in I2C_STATE_IDLE mode;
	 I2C_RW_STATE_e  WriteStatus;  //!< Write operation result(Clear Before Stateflow);
	 I2C_RW_STATE_e  ReadStatus;   //!< Read  operation result(Clear Before Stateflow);
	 int16_t         ValidBytes;   //!< Buffer中的有效字节数;
	 uint16_t        HighAddr;     //!< I2C Serial EEPROM 目标存储单元的高地址;
	 uint16_t        LowAddr;      //!< I2C Serial EEPROM 目标存储单元的低地址;
	 uint16_t        Buffer[32];   //!< I2C Serial EEPROM 对应一个 Page的存储空间;
}I2CMSG;

#define I2CMSG_DEFAULTS {I2C_STATE_IDLE,I2C_START, I2C_START,2,0,0, \
                         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  \
                         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}



// ================================================================================================
// the globals


// ================================================================================================
// the function prototypes

//! \brief Initializes the I2C object
//! \param[in] pMemory          Memory pointer for new object
//! \param[in] numBytes         Object size
//! \return                     I2C Handle
extern I2C_Handle I2C_init(void *pMemory,const size_t numBytes);


//! \brief     Initialize the I2C peripheral
//! \param[in] I2CHandle        Handle to I2C object
extern void HAL_setupI2C(I2C_Handle Handle);


//! \brief     sets the I2C clk
//! \param[in] I2CHandle        Handle to I2C object
//! \param[in] psc              Clock prescaler
inline void I2C_Prescaler(I2C_Handle Handle, uint32_t psc)
{
	Handle->I2CPSC.all = psc;
}


//! \brief     sets the I2C clock high time
//! \param[in] I2CHandle        Handle to I2C object
//! \param[in] Tim              Clock Low time
inline void I2C_clkLowTime(I2C_Handle Handle, uint32_t Tim)
{
	Handle->I2CCLKL = Tim;
}


//! \brief     sets the I2C clock low time
//! \param[in] I2CHandle        Handle to I2C object
//! \param[in] Tim              Clock Low time
inline  void I2C_clkHighTime(I2C_Handle Handle, uint32_t Tim)
{
	Handle->I2CCLKH = Tim;
}


//! \brief     sets the I2C own address
//! \param[in] I2CHandle        Handle to I2C object
//! \param[in] add              I2C own address
inline void I2C_OwnAdd(I2C_Handle Handle,uint32_t add)
{
	Handle->I2COAR = add;
}


//! \brief     sets the I2C slave address
//! \param[in] I2CHandle        Handle to I2C object
//! \param[in] add              I2C slave address
inline void I2C_SlvAdd(I2C_Handle Handle, uint32_t add)
{
	Handle->I2CSAR = add;
}

//! <pre>
//! \brief     sets the I2C EEprom write and read state flow
//! \details
//!           1.SDA开路: 写时会检测到NACK标志,导致写失败;
//!			  2.SDA开路: 读时会写命令,也可检测到NACK标志,导致读失败;
//!			  3.SDA短路: 写时会失去仲裁,导致写超时;
//!		      4.SDA短路: 读时会写命令,同样会失去仲裁,导致写超时;
//!		      5.SCK异常: 读写时从机无反应,会检测到NACK标志;
//! \param[in] I2CHandle        Handle to I2C object
//! \param[in] add              I2C slave address
//! </pre>
extern void I2C_Stateflow(I2C_Handle Handle,I2CMSG *Msg);


//! \brief     resets the I2C EEprom when power up
extern void I2C_EEProm_Reset(GPIO_Handle gpioHandle);


// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of HAL_I2C

#endif // end of hal_i2c.h
