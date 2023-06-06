// ================================================================================================
//! \file       CanUpper.h
//! \brief      ��������λ��ͨѶ
//! \author     xjh
//! \version    1.0.0
//! \date       2019��10��08��
//! \copyright  SANTROLL.
// ================================================================================================

#ifndef _CANUPPER_H_
#define _CANUPPER_H_

//! @defgroup CanUpper CanUpper
//! @{

#ifdef __cplusplus
extern "C" {
#endif
// ================================================================================================


// ================================================================================================
// the includes


// ================================================================================================
// the defines
// ����λ��ʹ��
#define NEWMONSOFT  1

// ================================================================================================
// the typedefs
//! ��λ��ͨѶ

#ifdef NEWMONSOFT

typedef struct
{
    uint16_t Index0;  // ������
    uint16_t Index1;
    uint16_t Index2;
    uint16_t Index3;
    uint16_t Index4;
    uint16_t Index5;
    uint16_t Index6;
    uint16_t Index7;
    uint16_t TotalNum;  // �ܸ�����1-8��
    uint16_t RefreshTm; // ���£�1-10��*10ms
    uint16_t PeriTmCnt; // ����ʱ�����
    uint16_t TxTmCnt;   // ���ͼ�ʱ
    ECANMSG  Msg1;      // ��Ҫ���͵�����1
    ECANMSG  Msg2;      // ��Ҫ���͵�����2
    void     (*DrawTx)(); // ��ͼ���ͺ���
}MONDRAW_OBJ;

#define MONDRAW_OBJ_DEFAULTS { 0,0,0,0,0,0,0,0,0,\
                                0,0,0,ECANMSG_DEFAULTS,ECANMSG_DEFAULTS,\
                                (void (*)(long))DrawTx}

typedef struct
{
    uint16_t Step;
    uint16_t ID;
    uint16_t RxBox;
    uint16_t TxBox;
    uint16_t TxBox1;
    uint16_t TxBox2;
    ECANMSG  Msg;
    MONDRAW_OBJ MonDraw;
    void  (*Comm)();
    void  (*Watch)();
    void  (*ReadAll)();
    void  (*ReadOne)();
    void  (*Write)();
    void  (*ClrFault)();
    void  (*DrawRt)();
}MONSOFT_OBJ;
    #if PROTUPCOMM == 0
        #define DEVICE_ID 0x20        //!< �豸ID
    #else
        #define DEVICE_ID 0x60        //!< �豸ID
    #endif

#define MONSOFT_OBJ_DEFAULTS {  0,\
                                DEVICE_ID,\
                                0,\
                                1,\
                                2,\
                                3,\
                                ECANMSG_DEFAULTS,\
                                MONDRAW_OBJ_DEFAULTS,\
                               (void (*)(long))NewMonSoft_Comm,\
                               (void (*)(long))NewMonSoft_Watch,\
                               (void (*)(long))NewMonSoft_ReadAll,\
                               (void (*)(long))NewMonSoft_ReadOne,\
                               (void (*)(long))NewMonSoft_Write,\
                               (void (*)(long))NewMonSoft_ClrFault,\
                               (void (*)(long))NewMonSoft_DrawRt}

extern void NewMonSoft_Comm(MONSOFT_OBJ* M);
extern void NewMonSoft_Watch(MONSOFT_OBJ* M);
extern void NewMonSoft_ReadAll(MONSOFT_OBJ* M);
extern void NewMonSoft_ReadOne(MONSOFT_OBJ* M);
extern void NewMonSoft_Write(MONSOFT_OBJ* M);
extern void NewMonSoft_ClrFault(MONSOFT_OBJ* M);
extern void NewMonSoft_DrawRt(MONSOFT_OBJ* M);

extern void DrawTx(MONSOFT_OBJ* M);

#else

typedef struct
{
    uint16_t Step;
    uint16_t ID;
    uint16_t RxBox;
    uint16_t TxBox;
    ECANMSG  Msg;
    void  (*Comm)();
    void  (*Watch)();
    void  (*ReadAll)();
    void  (*ReadOne)();
    void  (*Write)();
    void  (*ClrFault)();
}MONSOFT_OBJ;
#define MONSOFT_OBJ_DEFAULTS {  0,\
                                0x60,\
                                0,\
                                1,\
                                ECANMSG_DEFAULTS,\
                               (void (*)(long))MonSoft_Comm,\
                               (void (*)(long))MonSoft_Watch,\
                               (void (*)(long))MonSoft_ReadAll,\
                               (void (*)(long))MonSoft_ReadOne,\
                               (void (*)(long))MonSoft_Write,\
                               (void (*)(long))MonSoft_ClrFault}

extern void MonSoft_Comm(MONSOFT_OBJ* M);
extern void MonSoft_Watch(MONSOFT_OBJ* M);
extern void MonSoft_ReadAll(MONSOFT_OBJ* M);
extern void MonSoft_ReadOne(MONSOFT_OBJ* M);
extern void MonSoft_Write(MONSOFT_OBJ* M);
extern void MonSoft_ClrFault(MONSOFT_OBJ* M);
#endif

// ================================================================================================
// the globals
extern MONSOFT_OBJ MonSoft;
extern WATCH_OBJ Watch;

// ================================================================================================
// the function prototypes



// ================================================================================================
#ifdef __cplusplus
}
#endif // extern "C"

//! @} // end of CanUpper

#endif // end of _CANUPPER_H_
