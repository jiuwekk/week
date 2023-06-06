// ================================================================================================
//! \file       park.c
//! \brief      Contains various functions related to the park object
//! \author     zw
//! \version    1.0.0
//! \date       2017Äê4ÔÂ5ÈÕ
//! \copyright  SANTROLL.
// ================================================================================================


void park_calc(PARK_OBJ* v)
{

    float Cosine,Sine;
    Sine = sin(v->Angle);
    Cosine = cos(v->Angle);

    v->Ds = v->Alpha*Cosine + v->Beta *Sine;
    v->Qs = v->Beta*Cosine  - v->Alpha*Sine;
}



// ================================================================================================
// end of park.c
