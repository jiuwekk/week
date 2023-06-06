// ================================================================================================
//! \file       LookupTable.c
//! \brief      
//! \author     sunyanjun
//! \version    1.0.0
//! \date       2017��4��5��
//! \copyright  SANTROLL.
// ================================================================================================

float LookupTab_1Dxy(float xIn, const float* Tab, int32_t xMaxIndx)
{
    int32_t xIndx = 0;  //Index x

    xIndx = (int32_t)xIn;
    if(xIn >= xMaxIndx) xIndx -= 1;

    return(Tab[xIndx] + (xIn - (float)xIndx)*(Tab[xIndx + 1] - Tab[xIndx]));
}

/**
  * @brief  ��ά����㷨.
  * @param  xIn:x������ֵ����������echo:1.5����1��2�м�ֵ��.
  *         yIn:y������ֵ����������echo:1.5����1��2�м�ֵ��.
  *         Tab:��ά��
  *         xMaxIndx:x���������ֵ��������
  *         yMaxIndx:y���������ֵ��������
  * @retval ���ҵĽ��ֵ
  */
float LookupTab_2Dxyz(float xIn,float yIn, const float* Tab, int32_t xMaxIndx, int32_t yMaxIndx)
{
    int32_t xIndx = 0;    //Index x
    int32_t yIndx = 0;    //Index y

    float   x1Comm = 0;    //x����� x1/(x1 + x2)
    float   y1Comm = 0;    //y�����y1/(y1 + y2)
    float   x2Comm = 0;    //x�����x2/(x1 + x2)
    float   y2Comm = 0;    //y�����y2/(y1 + y2)

    //  ---------
    // |x1y1   x2y1
    // |x1y2   x2y2

    float   x1y1  = 0;
    float   x1y2  = 0;
    float   x2y1  = 0;
    float   x2y2  = 0;

    // �ݴ����
    float   Temp1 = 0;
    float   Temp2 = 0;
    float   Temp3 = 0;
    float   Temp4 = 0;

    // �����߽����ƴ���
    xIndx = (int32_t)xIn;
    if(xIndx >= xMaxIndx) xIndx -= 1;

    yIndx = (int32_t)yIn;
    if(yIndx >= yMaxIndx) yIndx -= 1;

    // ��ȡ�ĸ�������
    x1y1 = Tab[xIndx*(yMaxIndx + 1) + yIndx];
    x1y2 = Tab[xIndx*(yMaxIndx + 1) + yIndx + 1];
    x2y1 = Tab[(xIndx + 1)*(yMaxIndx + 1) + yIndx];
    x2y2 = Tab[(xIndx + 1)*(yMaxIndx + 1) + yIndx + 1];

    // ���ݴ��θ�������������֮��ı���
    x1Comm = xIn - xIndx;
    y1Comm = yIn - yIndx;
    x2Comm = 1 - x1Comm;
    y2Comm = 1 - y1Comm;

    // �����м����
    Temp1 = x1y1 * x2Comm * y2Comm;
    Temp2 = x1y2 * x2Comm * y1Comm;
    Temp3 = x2y2 * x1Comm * y1Comm;
    Temp4 = x2y1 * x1Comm * y2Comm;


    return (Temp1+Temp2+Temp3+Temp4);

}

float LookupTab_2Dxzy(float xIn,float zIn, const float* Tab, int32_t xMaxIndx, int32_t yMaxIndx)
{
     int32_t xIndx = 0;    //Index x
     int32_t yIndx = 0;    //Index y
     int32_t iLeft = 0;    //Index y Left
     int32_t iRght = 0;    //Index y Right
     float   yFrac = 0;    //y��΢��

     xIndx = (int32_t)xIn;
     if(xIndx >= xMaxIndx) xIndx -= 1;

     iLeft = 0;
     iRght = yMaxIndx;
     yIndx = yMaxIndx >> 1;
     while ((iRght - iLeft)> 1)
     {
       if (zIn > (Tab[xIndx*(yMaxIndx+1) + yIndx]))
       {
           iLeft = yIndx;
       }
       else
       {
           iRght = yIndx;
       }
       yIndx = (iRght + iLeft) >> 1;
     }

     yFrac = (zIn - Tab[xIndx*(yMaxIndx+1)+yIndx])/(Tab[(xIndx+1)*(yMaxIndx+1)+yIndx+1] - Tab[xIndx*(yMaxIndx+1)+yIndx]);
     if(yFrac > 1) yFrac = 1;

     return(((float)yIndx + yFrac)/yMaxIndx);
}

// ================================================================================================
// end of LookupTable.c
