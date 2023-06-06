// ================================================================================================
//! \file       AngelComp.c
//! \brief
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017Äê5ÔÂ23ÈÕ
//! \copyright  SANTROLL.
// ================================================================================================


void AngelComp_Calc(ANGELCOMP_OBJ* A)
{
    A->Angle_park  = A->Angel + A->Delay_park  * A->Ne * (PI2/60.0);
    A->Angle_ipark = A->Angel + A->Delay_ipark * A->Ne * (PI2/60.0);
}


// ================================================================================================
// end of AngelComp.c
