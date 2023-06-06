// ================================================================================================
//! \file       PICal.c
//! \brief      PI计算
//! \author     lining
//! \version    1.0.0
//! \date       2017年4月5日
//! \copyright  SANTROLL.
// ================================================================================================


void PICal(PI_OBJ* v)
{
	float OutTmp;
	v->Err = v->Ref - v->Fbk;
	OutTmp = v->Err * v->Kp + v->Ui; //Ui为上周期积分累计值

	if(OutTmp > v->Max)
	{
		v->Out = v->Max;
		v->StsOut = 1;
	}
	else if(OutTmp < v->Min)
	{
		v->Out = v->Min;
		v->StsOut = 1;
	}
	else
	{
		v->Out = OutTmp;
		v->StsOut = 0;
	}

	OutTmp = v->Out - OutTmp;

	if(v->StsIn == 0)
		v->Ui = v->Ui + v->Ki*v->Err + v->Kcor*OutTmp;
	else
		v->Ui = v->Ui + v->Kcor*OutTmp;
}


void PICalInit(PI_OBJ* v)
{
	v->Kcor = v->Ki / v->Kp;
}









// ================================================================================================
// end of PICal.c
