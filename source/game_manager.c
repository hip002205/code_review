#include <stdio.h>
#include "display.h"
#include "select.h"

//プログラム進行関数
int main(void) {
    RESULT r = NONE_WINNER;
    SELECT s;

    s = StartEnd();

    while (s == START)
    {
        r = GameBoard();
        if (r == R_RESET) {
            s = StartEnd();
        }
    }

    return 0;
}