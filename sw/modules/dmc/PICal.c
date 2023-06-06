// ================================================================================================
//! \file       PICal.c
//! \brief      PI����
//! \author     lining
//! \version    1.0.0
//! \date       2017��4��5��
//! \copyright  SANTROLL.
// ================================================================================================


void PICal(PI_OBJ* v)
{
	float OutTmp;
	v->Err = v->Ref - v->Fbk;
	OutTmp = v->Err * v->Kp + v->Ui; //UiΪ�����ڻ����ۼ�ֵ

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
