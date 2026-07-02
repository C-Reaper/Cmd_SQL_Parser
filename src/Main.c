#include "/home/codeleaded/System/Static/Library/QueryLanguage.h"

int main(int argc,char** argv){
    //if(argc==1){
    //    printf("Expected a Script!\n");
    //    exit(1);
    //}

    ///*
    CStr path = Files_cwd();
    CStr target = CStr_Concat(path,"/data");
    CStr_Free(&path);
    printf("Target: %s\n",target);
    
    QueryLanguage ql = QueryLanguage_New(target);
    CStr_Free(&target);

    QueryLanguage_InterpretScript(&ql,"./code/Create2.alxql");
    QueryLanguage_Free(&ql);
    //*/

    /*
    CStr path = Files_cwd();
    CStr target = CStr_Concat(path,"/data");
    CStr_Free(&path);

    QueryLanguage ql = QueryLanguage_New(target);
    CStr_Free(&target);

    QueryLanguage_Load(&ql,"./data/db1.alxdb","db1");
    QueryLanguage_Print(&ql);
    
    QueryLanguage_PrintDB(&ql,"db1");
    QueryLanguage_ImportDB(&ql,"./data/customers.csv","db1");
    QueryLanguage_PrintDB(&ql,"db1");

    QueryLanguage_Save(&ql,"./data/db1.alxdb","db1");
    QueryLanguage_Free(&ql);
    */
    return 0;
}