#include <stdio.h>
#include "select.h"

SELECT StartEnd() {
    int  input;
    char c_input[2] = {""};
    printf(" ________________________ \n\n\n\n");
    printf("         三目並べ         \n");
    while (1) {
        printf("     Start  [y/n] :");
        while ((input = getchar()) != '\n' && input != EOF) {
            c_input[0] = input;
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
            continue;
        }
    }
}

SELECT Rematch() {
    int  input;
    char c_input[2] = {""};
    while(1) {
        printf("       Continue?  [y/n] :");
        while ((input = getchar()) != '\n' && input != EOF) {
            c_input[0] = input;
        }

        if (c_input[0] == 0x79) {
            return START;
        } else if (c_input[0] == 0x6e) {
            return END;
        } else {
            InputError();
            continue;
        }
    }
    printf("\n\n  __________________________ \n");
}
