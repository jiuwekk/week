/*
 * functions.h
 *
 *  Created on: 2022Äê2ÔÂ12ÈÕ
 *      Author: sz-p783
 */

#ifndef SW_SOLUTIONS_FUNCS_FUNCTIONS_H_
#define SW_SOLUTIONS_FUNCS_FUNCTIONS_H_

#ifdef __cplusplus
extern "C" {
#endif


typedef struct
{
    union
    {
        uint16_t All[4];
        struct
        {
            uint16_t rsvd1:16;
            uint16_t rsvd2:16;
            uint16_t rsvd3:16;
            uint16_t rsvd4:16;
        }Bits;
    }Fault;
    struct
    {
        uint16_t ui_FaultFlag     :1 ;
        uint16_t ui_FaultSndFlag  :1 ;
        uint16_t uiFaultNum       :16;
    }Flags;
}ERR_CODE_OBJ;
#define ERR_CODE_OBJ_DEFAULTS {0,0,0,0,0,0,0}



extern void Mono_Limit_Num(int16_t *Num,int16_t MinLim,int16_t MaxLim);
extern void Loop_Limit_Num(int16_t *Num,int16_t MinLim,int16_t MaxLim);
extern uint16_t Schmidt(int16_t cnt,uint16_t maxcnt,uint16_t mincnt);
extern uint16_t On_Off_Judge(int16_t cnt,uint16_t judgevalue);
extern uint16_t SW_Filter(uint16_t Index,uint16_t FilterTimes,uint16_t IO_NewSta,uint16_t IO_OldSta);




extern ERR_CODE_OBJ ErrCode;
extern void GetFaultCode(uint16_t KSIst,FAULT_OBJ *F,uint16_t Tablestyle);
extern uint16_t Err_Code_SendState(void);




extern float DoubleErrCheck(uint16_t Err1,uint16_t Err2, \
                            float Temp1,float Temp2,\
                            float defaultvalue);
extern float TripleErrCheck(uint16_t Err1,uint16_t Err2,uint16_t Err3, \
                            float Temp1,float Temp2,float Temp3,\
                            float defaultvalue);
extern float CrossValueFCN(uint16_t fault1,uint16_t fault2,\
                           float Temp1,float Temp2);





#ifdef __cplusplus
}
#endif // extern "C"
#endif /* SW_SOLUTIONS_FUNCS_FUNCTIONS_H_ */
