#include <stdio.h>
#include "select.h"

//ゲーム開始時選択関数
SELECT StartEnd(void) {
    int  input_cnt = 0;
    int  input;
    char c_input[2] = { "" };
    printf(" ________________________ \n\n\n\n");
    printf("         三目並べ         \n");
    while (1) {
        printf("     Start  [y/n] :");
        while ((input = getchar()) != '\n' && input != EOF) {
            input_cnt++;
            c_input[0] = input;
        }

        if (input_cnt != 1) {
            InputError();
            input_cnt = 0;
            continue;
        }

        if (c_input[0] == 0x79) {
            printf("\n\n ________________________ \n");
            return START;
        }
        else if (c_input[0] == 0x6e) {
            ("\n\n ________________________ \n");
            return END;
        }
        else {
            InputError();
            input_cnt = 0;
            continue;
        }
    }
}

//再戦時選択関数
SELECT Rematch(void) {
    int  input_cnt = 0;
    int  input;
    char c_input[2] = { "" };
    while (1) {
        printf("       Continue?  [y/n] :");
        while ((input = getchar()) != '\n' && input != EOF) {
            input_cnt++;
            c_input[0] = input;
        }

        if (input_cnt != 1) {
            InputError();
            input_cnt = 0;
            continue;
        }

        if (c_input[0] == 0x79) {
            return START;
        }
        else if (c_input[0] == 0x6e) {
            return END;
        }
        else {
            InputError();
            input_cnt = 0;
            continue;
        }
    }
    printf("\n\n  __________________________ \n");
}
