#include "select.h"
#include "display.h"
#include <stdio.h>
#include <string.h>

#define DELETE_BUFFER         \
    while (getchar() != '\n') \
        ;

SELECT StartEnd()
{
    char check_str = "";
    printf(" ________________________ \n\n\n\n");
    printf("       三目並べ           \n");
    while (1)
    {
        printf("     Start  [y/n] :");
        scanf_s("%c", &check_str, (unsigned int)sizeof(check_str));

        if (check_str == '\n')
        {
            InputError();
            continue;
        }

        if (getchar() != '\n')
        {
            // 入力エラー
            InputError();
            DELETE_BUFFER;
            continue;
        }

        if (check_str == 'y')
        {
            printf("\n\n ________________________ \n");
            return START;
        }
        else if (check_str == 'n')
        {
            printf("\n\n ________________________ \n");
            return END;
        }
        else
        {
            // 入力エラー
            InputError();
            DELETE_BUFFER;
            continue;
        }
    }
}

SELECT Rematch()
{
    char check_str = "";
    while (1)
    {
        printf("       Continue?  [y/n] : ");
        scanf_s("%c", &check_str, (unsigned int)sizeof(check_str));

        if (check_str == '\n')
        {
            InputError();
            continue;
        }

        if (getchar() != '\n')
        {
            // 入力エラー
            InputError();
            DELETE_BUFFER;
            continue;
        }

        if (check_str == 'y')
        {
            return START;
        }
        else if (check_str == 'n')
        {
            return END;
        }
        else
        {
            // 入力エラー
            InputError();
            DELETE_BUFFER;
            continue;
        }
    }
    printf("\n\n  __________________________ \n");
}