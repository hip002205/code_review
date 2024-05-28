#include "display.h"
#include "select.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 3

int judge_cnt = 0;

int count_a_win = 0;
int count_b_win = 0;

RESULT GameBoard() {
    RESULT result = NONE_WINNER;
    PLAYER_TURN player = P_RESET;
    SELECT select = START;
    char board[3][3] = { "123", "456", "789" };

    do {
        player = WhoTurn(player);
        printf(" ________________________ \n");
        printf("                         \n");
        printf("            %s\n", player == TURN_A ? ("Aの番") : ("Bの番"));
        DisplayBoard(&board);
        player = InputBoard(player, &board);
        if (player == P_RESET) {
            result = R_RESET;
        }
        else {
            result = JudgeMatch(player, &board);
        }

        if (result != NONE_WINNER && result != R_RESET) {
            Result(result);
            select = Rematch();
            if (select == END) {
                result = R_RESET;
            }
            else {
                int code = 49;
                for (int i = 0; i < LENGTH; i++) {
                    for (int y = 0; y < LENGTH; y++) {
                        board[i][y] = code;
                        code++;
                    }
                }
            }
            judge_cnt = 0;
        }
    } while (result != R_RESET);

    return result;
}

PLAYER_TURN WhoTurn(PLAYER_TURN p) {
    srand((unsigned int)time(NULL));
    if (p == P_RESET) {
        int n = rand() % 2;
        if (n == 0) {
            return TURN_A;
        }
        else {
            return TURN_B;
        }
    }
    else {
        if (p == TURN_A) {
            return TURN_B;
        }
        else {
            return TURN_A;
        }
    }
}

void DisplayBoard(char* c) {
    printf("\n");
    for (int i = 0; i < LENGTH; i++) {
        printf("         |   |\n");
        printf("       %c | %c | %c\n", c[i*3], c[i*3+1], c[i*3+2]);
        printf("         |   |\n");
        if (i != 2) {
            printf("      ___|___|___\n");
        }
        else {
            printf("         |   | \n");
        }
    }
    printf("\n");
}

PLAYER_TURN InputBoard(PLAYER_TURN p, char* c) {
    char input_char[5];
    int input_num = 0;

    while (1) {
        printf("  どこにいれますか?(Reset:r):");
        scanf_s("%s", &input_char, sizeof(input_char));
        printf("\n ________________________\n");

        if (strlen(input_char) == 1) {
            if (input_char[0] >= '1' && input_char[0] <= '9') {
                input_num = atoi(input_char);
            }
            else if (input_char[0] == RESET_COMMAND) {
                return P_RESET;
            }
            else {
                //入力エラー
                InputError();
                continue;
            }
        }
        else {
            //入力エラー
            InputError();
            continue;
        }

        if (strchr(c, input_char[0]) != NULL) {
            if (p == TURN_A) {
                c[input_num - 1] = 'o';
                return TURN_A;
            }
            else {
                c[input_num - 1] = 'x';
                return TURN_B;
            }
        }

        if (c[input_num - 1] == 'o' || c[input_num - 1] == 'x') {
            //重複エラー
            SameInputError();
            continue;
        }
    }
}

RESULT JudgeMatch(PLAYER_TURN p, char* c) {
    judge_cnt++;
    //横列判定
    for (int i = 0; i < LENGTH; i++) {
        if (c[i*3] == c[i*3+1]) {
            if (c[i * 3 + 1] == c[i * 3 + 2]) {
                if (p == TURN_A) {
                    return WINNER_A;
                }
                else {
                    return WINNER_B;
                }
            }
        }
    }
    //縦列判定
    for (int i = 0; i < LENGTH; i++) {
        if (c[i] == c[i + 3]) {
            if (c[i + 3] == c[i + 6]) {
                if (p == TURN_A) {
                    return WINNER_A;
                }
                else {
                    return WINNER_B;
                }
            }
        }
    }

    //斜め判定
    if (c[0] == c[4]) {
        if (c[4] == c[8]) {
            if (p == TURN_A) {
                return WINNER_A;
            }
            else {
                return WINNER_B;
            }
        }
    }

    if (c[2] == c[4]) {
        if (c[4] == c[6]) {
            if (p == TURN_A) {
                return WINNER_A;
            }
            else {
                return WINNER_B;
            }
        }
    }

    if (judge_cnt == 9) {
        return DRAW;
    }

    return NONE_WINNER;
}

void Result(RESULT r) {
    printf(" ________________________ \n\n\n");
    if (r == DRAW) {
        printf("           引き分け\n");
    }
    else {
        printf("           %sの勝利\n", r == WINNER_A ? "A" : "B");
    }
    printf("        Aの勝利回数：%d\n", r == WINNER_A ? ++count_a_win : count_a_win);
    printf("        Bの勝利回数：%d\n", r == WINNER_B ? ++count_b_win : count_b_win);
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