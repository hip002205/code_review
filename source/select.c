#include "select.h"
#include "display.h"
#include <stdio.h>
#include <string.h>

SELECT StartEnd(){
    char check_str[3];
    printf(" ____________________________ \n\n\n\n");
    printf("            三目並べ           \n");
    printf("          Start  [y/n] :");
    scanf_s("%s", &check_str, sizeof(check_str));
    printf("\n\n\n ____________________________ ");

    if(strlen(check_str) != 1){
        //再入力
    }

    if(check_str[0] = 'y'){
        return START;
    }
    else if(check_str[0] == 'n') {
        return END;
    }
    else {
        //入力エラー
    }

}

SELECT Rematch(){
    char check_str[3];
    printf("       Continue?  [y/n] :   \n");
    scanf_s("%s", &check_str, sizeof(check_str));
    printf("                            \n");
    printf("                            \n");
    printf("  __________________________ \n");


    if(strlen(check_str) != 1){
        //再入力
    }

    if(check_str[0] = 'y'){
        return START;
    }
    else if(check_str[0] == 'n') {
        return END;
    }
    else {
        //入力エラー
    }
}