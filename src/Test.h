#include "/home/codeleaded/System/Static/Library/AlxParser.h"
#include "/home/codeleaded/System/Static/Container/Database.h"

typedef float FLOAT;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned long long QWORD;
typedef CStr VARCHAR;

CStr DB_Fn_CStr_Float(void* ptr){
    return (char*)Number_Get(*(FLOAT*)ptr);
}
CStr DB_Fn_CStr_Word(void* ptr){
    return (char*)Number_Get(*(WORD*)ptr);
}
CStr DB_Fn_CStr_DWord(void* ptr){
    return (char*)Number_Get(*(DWORD*)ptr);
}
CStr DB_Fn_CStr_QWord(void* ptr){
    return (char*)Number_Get(*(QWORD*)ptr);
}
CStr DB_Fn_CStr_VarChar(void* ptr){
    return CStr_Cpy((char*)ptr);
}

char DB_Fn_Cmp_Float(void* ptr1,void* ptr2){
    const FLOAT p1 = *(FLOAT*)ptr1;
    const FLOAT p2 = *(FLOAT*)ptr2;
    return p1 > p2 ? 1 : (p1 < p2 ? -1 : 0);
}
char DB_Fn_Cmp_Word(void* ptr1,void* ptr2){
    const WORD p1 = *(WORD*)ptr1;
    const WORD p2 = *(WORD*)ptr2;
    return p1 > p2 ? 1 : (p1 < p2 ? -1 : 0);
}
char DB_Fn_Cmp_DWord(void* ptr1,void* ptr2){
    const DWORD p1 = *(DWORD*)ptr1;
    const DWORD p2 = *(DWORD*)ptr2;
    return p1 > p2 ? 1 : (p1 < p2 ? -1 : 0);
}
char DB_Fn_Cmp_QWord(void* ptr1,void* ptr2){
    const QWORD p1 = *(QWORD*)ptr1;
    const QWORD p2 = *(QWORD*)ptr2;
    return p1 > p2 ? 1 : (p1 < p2 ? -1 : 0);
}
char DB_Fn_Cmp_VarChar(void* ptr1,void* ptr2){
    char* const p1 = (char*)ptr1;
    char* const p2 = (char*)ptr2;
    return CStr_Cmp(p1,p2) == 1 ? 0 : 1;//-1 ignored not with !
}

DB_Bool DB_Fn_Test(Vector* vec){
    VARCHAR v0 = *(VARCHAR*)Vector_Get(vec,0);
    WORD    v1 = **(WORD**)Vector_Get(vec, 1);
    FLOAT   v2 = **(FLOAT**)Vector_Get(vec,2);
    DWORD   v3 = **(DWORD**)Vector_Get(vec,3);
    QWORD   v4 = **(QWORD**)Vector_Get(vec,4);
    return v1 < 200U;
}

int main(){
    Database db = Database_Make(
        5,
        (DB_Type[]){ 
            DB_Type_New(-1,           "VARCHAR",DB_TYPE_NOMEMBERS,DB_Fn_CStr_VarChar,DB_Fn_Cmp_VarChar),
            DB_Type_New(sizeof(WORD), "WORD",   DB_TYPE_NOMEMBERS,DB_Fn_CStr_Word,   DB_Fn_Cmp_Word   ),
            DB_Type_New(sizeof(FLOAT),"FLOAT",  DB_TYPE_NOMEMBERS,DB_Fn_CStr_Float,  DB_Fn_Cmp_Float  ),
            DB_Type_New(sizeof(DWORD),"DWORD",  DB_TYPE_NOMEMBERS,DB_Fn_CStr_DWord,  DB_Fn_Cmp_DWord  ),
            DB_Type_New(sizeof(QWORD),"QWORD",  DB_TYPE_NOMEMBERS,DB_Fn_CStr_QWord,  DB_Fn_Cmp_QWord  )
        },
        (char*[]){
            "Name",
            "IQ",
            "Height",
            "Money",
            "ID",
        }
    );

    Database_Entry_Push(&db,(void*[]){ 
        (CStr[]){ "Alex" },
        (WORD[]){ 69U },
        (FLOAT[]){ 1.8f },
        (DWORD[]){ 986000U },
        (QWORD[]){ 0x3F4A4B5C5E6FULL },
    });
    Database_Entry_Push(&db,(void*[]){ 
        (CStr[]){ "Yanis" },
        (WORD[]){ 169U },
        (FLOAT[]){ 1.8f },
        (DWORD[]){ 86000U },
        (QWORD[]){ 0x34A4B5C5E6F7ULL },
    });
    Database_Entry_Push(&db,(void*[]){ 
        (CStr[]){ "Nick" },
        (WORD[]){ 255U },
        (FLOAT[]){ 1.8f },
        (DWORD[]){ 1686000U },
        (QWORD[]){ 0x3F4A4B5C56F7ULL },
    });
    Database_Entry_Push(&db,(void*[]){ 
        (CStr[]){ "Andi" },
        (WORD[]){ 191U },
        (FLOAT[]){ 1.8f },
        (DWORD[]){ 1860000U },
        (QWORD[]){ 0x3F4A45C5E6F7ULL },
    });
    Database_Entry_Push(&db,(void*[]){ 
        (CStr[]){ "Marc" },
        (WORD[]){ 199U },
        (FLOAT[]){ 1.8f },
        (DWORD[]){ 9986000U },
        (QWORD[]){ 0xF4A4B5C5E6F7ULL },
    });

    Database_Entry_Update(&db,1,"World",(int[]){ 69 });
    Database_Entry_Remove(&db,DB_Fn_Test);
    Database_Print(&db);

    Database_Write(&db,"./db3.alxql");
    Database_Free(&db);

    Database_Read(&db,"./db3.alxql");
    Database_Print(&db);
    Database_Free(&db);
    return 0;
}