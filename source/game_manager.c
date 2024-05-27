#include <stdio.h>
#include "display.h"
#include "select.h"



int main(){
    RESULT r = NONE_WINNER;
    SELECT s = StartEnd();

    while (s == START)
    {
        r = GameBoard();
        if(r == R_RESET){
            s = StartEnd();
        }
    }

    return 0;
}