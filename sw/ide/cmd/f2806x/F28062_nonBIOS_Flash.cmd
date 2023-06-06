//=======================================================================================
// [ File           ] F28062_nonBIOS_Flash.cmd
// [ Version        ] V1.00
// [ Inherited From ] None
// [ Author         ] sunyanjun@engineer.com
// [ Date           ] 2013.10.25
// [ Compiler       ] CCS5.21
// [ Description    ] Linker command file for non-DSP/BIOS code with DSP in jump-to-flash boot mode.
//=======================================================================================
--diag_suppress=16002

MEMORY
{
	//-------------------------------------------------------------------------
	// Program Memory
    PAGE 0:
        BEGIN_M0           : origin = 0x000000, length = 0x000002     // Part of M0SARAM.  Used for "Boot to M0" bootloader mode.
        RAM_L0L1L2L3       : origin = 0x008000, length = 0x002000     // L0 L1 L2 L3 DPSARAM, CSM secure,
        OTP            (R) : origin = 0x3D7800, length = 0x000400     // OTP
        FLASH_HGFEDCBA (R) : origin = 0x3E8000, length = 0x00DFFC     // FLASH, All sectors combined,length = 0x00FF80
        CSM_RSVD       (R) : origin = 0x3F7F80, length = 0x000076     // Part of FLASH Sector A.  Reserved when CSM is in use.
        BEGIN_FLASH    (R) : origin = 0x3F7FF6, length = 0x000002     // Part of FLASH Sector A.  Used for "Jump to flash" bootloader mode.
        PASSWORDS      (R) : origin = 0x3F7FF8, length = 0x000008     // Part of FLASH Sector A.  CSM password locations.
        FPUTABLES      (R) : origin = 0x3FD860, length = 0x0006A0     // Part of Boot ROM
        IQTABLES       (R) : origin = 0x3FDF00, length = 0x000B50     // Part of Boot ROM
        IQTABLES2      (R) : origin = 0x3FEA50, length = 0x00008C     // Part of Boot ROM
        IQTABLES3      (R) : origin = 0x3FEADC, length = 0x0000AA     // Part of Boot ROM

        BOOTROM        (R) : origin = 0x3FF3B0, length = 0x000C10     // Boot ROM
        RESET          (R) : origin = 0x3FFFC0, length = 0x000002     // part of Boot ROM
        VECTORS        (R) : origin = 0x3FFFC2, length = 0x00003E     // part of boot ROM

	//-------------------------------------------------------------------------
	// Data Memory
    PAGE 1 :
        BOOT_RSVD          : origin = 0x000002, length = 0x00004E     // Part of M0SARAM, BOOT rom will use this for stack
        RAM_M0             : origin = 0x000050, length = 0x0003B0     // M0 SARAM
        RAM_M1             : origin = 0x000400, length = 0x000400     // M1 SARAM
        RAM_L4L5           : origin = 0x00A000, length = 0x006000     //
      //RAM_L0             : origin = 0x008000, length = 0x000800     // L0 DPSARAM, CSM secure,
      //RAM_L1             : origin = 0x008800, length = 0x000400     // L1 DPSARAM, CSM secure,
      //RAM_L2             : origin = 0x008C00, length = 0x000400     // L2 DPSARAM, CSM secure,
      //RAM_L3             : origin = 0x009000, length = 0x001000     // L3 DPSARAM, CSM secure,
      //RAM_L4             : origin = 0x00A000, length = 0x002000     // L4   SARAM, CSM secure,
      //RAM_L5             : origin = 0x00C000, length = 0x002000     // L5 DPSARAM, DMA RAM 0
}


SECTIONS
{
	//-------------------------------------------------------------------------
    // Program memory (PAGE 0) sections
    .text              : > FLASH_HGFEDCBA,                        PAGE = 0
    .cinit             : > FLASH_HGFEDCBA,                        PAGE = 0
    .const             : > FLASH_HGFEDCBA,                        PAGE = 0
    .econst            : > FLASH_HGFEDCBA,                        PAGE = 0
    .pinit             : > FLASH_HGFEDCBA,                        PAGE = 0
    .switch            : > FLASH_HGFEDCBA,                        PAGE = 0
    .reset             : > RESET,                                 PAGE = 0, TYPE = DSECT  // We are not using the .reset section
     vectors           : > VECTORS,                               PAGE = 0, TYPE = DSECT

	//-------------------------------------------------------------------------
    // Data Memory (PAGE 1) sections
    .bss               : > RAM_L4L5,                              PAGE = 1
    .ebss              : > RAM_L4L5,                              PAGE = 1
    .cio               : > RAM_L4L5,                              PAGE = 1
    .stack             : > RAM_L4L5,                              PAGE = 1
    .sysmem            : > RAM_L4L5,                              PAGE = 1
    .esysmem           : > RAM_L4L5,                              PAGE = 1

	//-------------------------------------------------------------------------
    // User Defined Sections
    codestart          : > BEGIN_FLASH,                           PAGE = 0                // Used by file CodeStartBranch.asm
    csm_rsvd           : > CSM_RSVD,                              PAGE = 0                // Used by file Passwords.asm
    csmpasswds         : > PASSWORDS,                             PAGE = 0                // Used by file Passwords.asm
    ramfuncs           :   LOAD = FLASH_HGFEDCBA,                 PAGE = 0                // Used by file Flash.c
                           RUN  = RAM_L0L1L2L3,                   PAGE = 0                // Load to flash, run from CSM secure RAM
                           LOAD_START(_RamfuncsLoadStart),
                           LOAD_END(_RamfuncsLoadEnd),
                           LOAD_SIZE(_RamfuncsLoadSize),
                           RUN_START(_RamfuncsRunStart)

	//-------------------------------------------------------------------------
    // FPU MATH
    FPUmathTables      : > FPUTABLES,                             PAGE = 0, TYPE = NOLOAD

	//-------------------------------------------------------------------------
    // IQ MATH
    IQmath             : > FLASH_HGFEDCBA,                        PAGE = 0                // Math Code
    IQmathTables       : > IQTABLES,                              PAGE = 0, TYPE = NOLOAD
    /*
    IQmathTables2      : > IQTABLES2,                             PAGE = 0, TYPE = NOLOAD
    {
        IQmath.lib<IQNexpTable.obj> (IQmathTablesRam)
    }
    IQmathTables3      : > IQTABLES3,                             PAGE = 0, TYPE = NOLOAD
    {
        IQmath.lib<IQNasinTable.obj> (IQmathTablesRam)
    }
    */
}

//=======================================================================================
// End Of File
//=======================================================================================
