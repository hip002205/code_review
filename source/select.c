#include "select.h"
#include "display.h"
#include <stdio.h>
#include <string.h>

//ゲームの開始終了を選択させる関数
SELECT StartEnd() {
    char check_str[3];
    printf(" ________________________ \n\n\n\n");
    printf("       三目並べ           \n");
    while (1) {
        printf("     Start  [y/n] :");
        scanf_s("%s", &check_str, sizeof(check_str));


        if (strlen(check_str) != 1) {
            //再入力
            InputError();
            continue;
        }

        if (check_str[0] == 'y') {
            printf("\n\n ________________________ \n");
            return START;
        }
        else if (check_str[0] == 'n') {
            printf("\n\n ________________________ \n");
            return END;
        }
        else {
            //入力エラー
            InputError();
            continue;
        }
    }

}

//ゲームの再選を選択させる関数
SELECT Rematch() {
    char check_str[3] = "";
    while (1) {
        printf("       Continue?  [y/n] :");
        scanf_s("%s", &check_str, sizeof(check_str));

        if (strlen(check_str) != 1) {
            //再入力
            InputError();
            continue;
        }

        if (check_str[0] == 'y') {
            return START;
        }
        else if (check_str[0] == 'n') {
            return END;
        }
        else {
            //入力エラー
            InputError();
            continue;
        }
    }
    printf("\n\n  __________________________\n");
}