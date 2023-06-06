// ================================================================================================
//! \file       config.h
//! \brief      
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017年4月14日
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _CONFIG_H_

#define _CONFIG_H_

//! @defgroup CONFIG CONFIG
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// Current Sensor type: MACROs Can not be modified!
// UVW电流传感器标号以实际位置为准，不参考PCB标号
#define CUR_SEN_plusU_plusV_plusW           (0x01)  //!< [+U +V +W]
#define CUR_SEN_mnusU_mnusV_mnusW           (0x02)  //!< [-U -V -W]
#define CUR_SEN_plusU_plusV_noneW           (0x03)  //!< [+U +V   ]
#define CUR_SEN_plusU_mnusV_noneW           (0x04)  //!< [+U -V   ]
#define CUR_SEN_mnusU_plusV_noneW           (0x05)  //!< [-U +V   ]
#define CUR_SEN_mnusU_mnusV_noneW           (0x06)  //!< [-U -V   ]
#define CUR_SEN_plusU_noneV_plusW           (0x07)  //!< [+U    +W]
#define CUR_SEN_plusU_noneV_mnusW           (0x08)  //!< [+U    -W]
#define CUR_SEN_mnusU_noneV_plusW           (0x09)  //!< [-U    +W]
#define CUR_SEN_mnusU_noneV_mnusW           (0x0A)  //!< [-U    -W]
#define CUR_SEN_noneU_plusV_plusW           (0x0B)  //!< [   +V +W]
#define CUR_SEN_noneU_plusV_mnusW           (0x0C)  //!< [   +V -W]
#define CUR_SEN_noneU_mnusV_plusW           (0x0D)  //!< [   -V +W]
#define CUR_SEN_noneU_mnusV_mnusW           (0x0E)  //!< [   -V -W]

// ================================================================================================
//!< CONSTANTs: MACROs Can not be modified!
#define PI1                                 (3.141592653589793)  //!< π
#define PI2                                 (6.283185307179586)  //!< 2π
#define PI_2                                (1.570796326794897)  //!< π/2
#define SQRT2                               (1.414213562373095)  //!< sqrt(2)
#define SQRT3                               (1.732050807568877)  //!< sqrt(3) cosf
#define SQRT1_2                             (0.707106781186547)  //!< sqrt(1/2)
#define SQRT1_3                             (0.577350269189626)  //!< sqrt(1/3)

// setting
#include"sw/config/Setting.h"

// modules
#include "sw/modules/types/src/types.h"
#include "sw/modules/FPUfastRTS/V100/include/C28x_FPU_FastRTS.h"
#include "sw/modules/IQmath/v160/include/IQmathLib.h"
#include "sw/modules/memCopy/src/memCopy.h"
#include "sw/modules/usDelay/src/32b/usDelay.h"

#include "sw/modules/dmc/PICal.h"
#include "sw/modules/dmc/svpwm.h"
#include "sw/modules/dmc/park.h"
#include "sw/modules/dmc/ipark.h"
#include "sw/modules/dmc/clarke.h"
#include "sw/modules/dmc/iclarke.h"
#include "sw/modules/dmc/lpf.h"
#include "sw/modules/dmc/AngelComp.h"
#include "sw/modules/dmc/LookupTable.h"

#include "sw/config/SystemConfig.h"
#include "sw/config/ConfigParm.h"

// mbd
#include "sw/solutions/Mbds/MbdInclude.h"


#include"sw/hal/hal.h"
#include "sw/solutions/MainInits.h"
#include "sw/solutions/Globals.h"
#include "sw/solutions/MainISR.h"
#include "sw/solutions/MainLoop.h"
#include "sw/solutions/funcs/Signals.h"
#include "sw/solutions/funcs/Faults.h"
#include "sw/solutions/funcs/CanUpper.h"
#include "sw/solutions/funcs/CanDbgData.h"
#include "sw/solutions/funcs/functions.h"

#if COUST_ID == 0
    #include "sw/solutions/funcs/ProtFunc/SantProt.h"
#else
    #include "sw/solutions/funcs/ProtFunc/SantProt.h"
#endif


// 母线电流计算TAB表
#define OMTAB {\
        1.0000,0.9988,0.9963,0.9937,0.9902,0.9866,0.9827,0.9783,\
        0.9739,0.9690,0.9641,0.9590,0.9536,0.9482,0.9426,0.9370,\
        0.9312,0.9253,0.9194,0.9133,0.9072,0.9011,0.8955,0.8899,\
        0.8843,0.8792,0.8740,0.8689,0.8640,0.8591,0.8545,0.8499,\
        0.8452,0.8408,0.8362,0.8318,0.8276,0.8232,0.8191,0.8149,\
        0.8110,0.8069,0.8030,0.7988,0.7949,0.7910,0.7874,0.7834,\
        0.7795,0.7759,0.7722,0.7686,0.7649,0.7612,0.7576,0.7542,\
        0.7505,0.7471,0.7437,0.7400,0.7366,0.7332,0.7297,0.7266,\
        0.7231,0.7200,0.7166,0.7134,0.7100,0.7068,0.7036,0.7004,\
        0.6973,0.6943,0.6912,0.6880,0.6851,0.6819,0.6790,0.6760,\
        0.6729,0.6699,0.6670,0.6641,0.6611,0.6584,0.6555,0.6526,\
        0.6499,0.6470,0.6443,0.6416,0.6387,0.6360,0.6333,0.6306,\
        0.6279,0.6252,0.6226,0.6201,0.6174,0.6147,0.6123,0.6096,\
        0.6072,0.6047,0.6023,0.5996,0.5972,0.5947,0.5923,0.5898,\
        0.5876,0.5852,0.5828,0.5803,0.5781,0.5757,0.5735,0.5713,\
        0.5688,0.5667,0.5645,0.5623,0.5601,0.5579,0.5557,0.5535,\
        0.5513}
// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of CONFIG

#endif // end of _CONFIG_H_
