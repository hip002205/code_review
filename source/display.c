#include "display.h"
#include "select.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 3

int count_a_win = 0;
int count_b_win = 0;

RESULT GameBoard(){
    RESULT result = NONE_WINNER;
    PLAYER_TURN player = P_RESET;
    SELECT select = START;
    char board[3][3] = {"123", "456", "789"};

    do{
        player = WhoTurn(player);
        printf(" ________________________ \n");
        printf("                         \n");
        printf("   %s    リセット:R    \n", player == TURN_A ? ("Aの番") : ("Bの番"));
        DisplayBoard(&board);
        player = InputBoard(player, &board);
        if(player == P_RESET){
            result =  R_RESET;
        }
        result = JudgeMatch(player, &board);
        if(result != NONE_WINNER && result != R_RESET){
            select = Rematch();
            if(select == END){
                result = R_RESET;
            }
        }
    }while(result == R_RESET);

    return result;
}

PLAYER_TURN WhoTurn(PLAYER_TURN p){
    srand((unsigned int)time(NULL));
    if(p == P_RESET){
        int n = rand() % 2;
        if(n == 0){
            return TURN_A;
        }
        else{
            return TURN_B;
        }
    }
    else{
        if(p == TURN_A){
            return TURN_B;
        }
        else{
            return TURN_A;
        }
    }
}

void DisplayBoard(char* c){
    printf("                         \n");
    for(int i = 0; i < LENGTH; i++){
        printf("         |   |           \n");
    printf("       %d | %d | %d         \n", c[0], c[1], c[2]);
    c++;
    printf("         |   |           \n");
    if(i != 2){
        printf("      ___|___|___        \n");
    }
    else {
        printf("         |   |           \n");
    }
    }
    printf("                         \n");
}

PLAYER_TURN InputBoard(PLAYER_TURN p, char* c){
    char input_char[5];
    int input_num = 0;

    while(1){
        printf("    どこにいれますか? :   \n");
        scanf_s("%s", &input_char, sizeof(input_char));
        printf("                         \n");
        printf(" _______________________ \n");

        if(strlen(input_char) == 1){
            if(input_char[0] < '1' || input_char > '9' || RESET_COMMAND){
                if(input_char  == RESET_COMMAND){
                    return P_RESET;
                }
                else{
                    input_num = atoi(input_char);
                }
            }
            else{
                //入力エラー
                InputError();
                continue;
            }
        }
        else{
            //入力エラー
            InputError();
            continue;
        }

        for(int i = 0; i < LENGTH; i++){
            if(strchr(c, input_num) != NULL){
                if(p == TURN_A){
                    c[input_num-1] = 'o';
                    return TURN_A;
                }
                else{
                    c[input_num-1] = 'x';
                    return TURN_B;
                }
            }
            else if(i + 1  == LENGTH){
                //重複エラー
                SameInputError();
                continue;
            }
            c++;
        }
    }
}

RESULT JudgeMatch(PLAYER_TURN p, char* c){
    //横列判定
    for(int i = 0; i < LENGTH; i++){
        if(c[0] == c[1] == c[2]){
            if(p == TURN_A){
                return WINNER_A;
            }else{
                return WINNER_B;
            }
        }
        c++;
    }
    c -= 2;
    //縦列判定
    for(int i = 0; i < LENGTH; i++){
        if(c[i] == (c+1)[i] == (c+2)[i]){
            if(p == TURN_A){
                return WINNER_A;
            }else{
                return WINNER_B;
            }
        }
    }

    //斜め判定
    if(c[0] == (c+1)[1] == (c+2)[2]){
        if(p == TURN_A){
                return WINNER_A;
            }else{
                return WINNER_B;
            }
    }

    if(c[2] == (c+1)[1] == (c+2)[0]){
        if(p == TURN_A){
                return WINNER_A;
            }else{
                return WINNER_B;
            }
    }

    return NONE_WINNER;
}

void Result(RESULT r){
    printf("  __________________________ \n");
    printf("                            \n");
    printf("                            \n");
    printf("           %cの勝利         \n", r == WINNER_A ? "A" : "B");
    printf("        Aの勝利回数：%d       \n", r == WINNER_A ? ++count_a_win : count_a_win);
    printf("        Bの勝利回数：%d       \n", r == WINNER_B ? ++count_b_win : count_b_win);
}

void InputError() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == 0 || i == 4) {
                if (i == 0 && (j == 0 || j == 25)) {
                    printf(" ");
                }
                if (j >= 1 && j <= 24) {
                    printf("_");
                }
            }
            if (i >= 1 && i <= 4) {
                if (j == 0 || j == 25) {
                    printf("|");
                }
                if (i == 2) {
                    if (j == 6) {
                        printf("不正な入力です");
                        j += 14;
                    }
                }
                if (i == 3) {
                    if (j == 1) {
                        printf("もう一度入力してください|");
                        j += 24;
                    }
                }
                if (i <= 3 && (j >= 1 && j <= 24)) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void SameInputError() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == 0 || i == 4) {
                if (i == 0 && (j == 0 || j == 25)) {
                    printf(" ");
                }
                if (j >= 1 && j <= 24) {
                    printf("_");
                }
            }
            if (i >= 1 && i <= 4) {
                if (j == 0 || j == 25) {
                    printf("|");
                }
                if (i == 2) {
                    if (j == 2) {
                        printf("すでに入力されています");
                        j += 22;
                    }
                }
                if (i == 3) {
                    if (j == 1) {
                        printf("もう一度入力してください|");
                        j += 24;
                    }
                }
                if (i <= 3 && (j >= 1 && j <= 24)) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}