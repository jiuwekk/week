// ================================================================================================
//! \file       svpwm.c
//! \brief      SVPWM调制
//! \author     lining
//! \version    1.0.0
//! \date       2017年3月31日
//! \copyright  SANTROLL.
// ================================================================================================

void SVPWMCal(SVPWM_OBJ* sv)
{
	float Va,Vb,Vc,X,Y,Z,taon,tbon,tcon,t1,t2;
	Uint16 sector=0;

	Va = sv->Beta;
	Vb = 0.8660254 * sv->Alpha - 0.5 * sv->Beta;
	Vc = -Vb - sv->Beta;

    X = sv->Beta ;
    Y = 0.8660254 * sv->Alpha + 0.5 * sv->Beta;
    Z = -0.8660254 * sv->Alpha + 0.5 * sv->Beta;

	if( Va > 0 )
	{
		sector += 1;
	}
	if( Vb > 0 )
	{
		sector += 2;
	}
	if( Vc > 0 )
	{
		sector += 4;
	}

	switch( sector )
	{
		case 0:
			t1 = 0;
			t2 = 0;
		break;

		case 1:
			t1 = Z;
			t2 = Y;
		break;

		case 2:
			t1 = Y;
			t2 = -X;
		break;

		case 3:
			t1 = -Z;
			t2 = X;
		break;

		case 4:
			t1 = -X;
			t2 = Z;
		break;

		case 5:
			t1 = X;
			t2 = -Y;
		break;

		case 6:
			t1 = -Y;
			t2 = -Z;
		break;

		default:
		break;
	}
	if(t1 + t2 > 1)
	{
		if((t1 > t2) && (t1 > 1))
		{
			t1 = 1;
			t2 = 0;
		}
		else if( (t1 <=  t2) && (t2 > 1) )
		{
			t1 = 0;
			t2 = 1;
		}
		else
		{
			t1 = t1 / (t1 + t2);
			t2 = 1 - t1;
		}
	}

	if(sv->SEG57 == SVPWM_SEG5)
	{
		taon = ( 1 - t1 - t2 );     //五段式SVPWM
	}
	else
	{
		taon = ( 1 - t1 - t2 )*0.5; //七段式SVPWM
	}
	tbon = taon + t1;
	tcon = tbon + t2;

	switch(sector)
	{
		case 0:
		{
			sv->Ta = taon;
			sv->Tb = tbon;
			sv->Tc = tcon;
			break;
		}
		case 1:
		{
			sv->Ta = tbon;
			sv->Tb = taon;
			sv->Tc = tcon;
			break;
		}
		case 2:
		{
			sv->Ta = taon;
			sv->Tb = tcon;
			sv->Tc = tbon;
			break;
		}

		case 3:
		{
			sv->Ta = taon;
			sv->Tb = tbon;
			sv->Tc = tcon;
			break;
		}
		case 4:
		{
			sv->Ta = tcon;
			sv->Tb = tbon;
			sv->Tc = taon;
			break;
		}
		case 5:
		{
			sv->Ta = tcon;
			sv->Tb = taon;
			sv->Tc = tbon;
			break;
		}
		case 6:
		{
			sv->Ta = tbon;
			sv->Tb = tcon;
			sv->Tc = taon;
			break;
		}
		default:
		{
			break;
		}
	}
}



// ================================================================================================
// end of SVPWM.c
