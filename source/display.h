#ifndef DISPLAY_H
#define DISPLAY_H

//試合結果
typedef enum {
    WINNER_A,
    WINNER_B,
    DRAW,
    NONE_WINNER,
    R_RESET
}RESULT;

//手番
typedef enum{
    TURN_A,
    TURN_B,
    P_RESET
}PLAYER_TURN;

#define RESET_COMMAND "r"



RESULT GameBoard(); //三目並べを進行する関数

PLAYER_TURN WhoTurn(PLAYER_TURN p); //ゲームが初めて行われたかを判定し
                                    //初めてならランダム、二回目以降なら手番を交代する関数

void DisplayBoard(char* c); //配列の中身を画面に表示する関数

PLAYER_TURN InputBoard(PLAYER_TURN p, char* c); //プレイヤーに入力を求め入力されたところの配列の番号に手番ごとのマークを挿入する関数

RESULT JudgeMatch(PLAYER_TURN p, char* c);  //勝敗を判定する関数

void Result(RESULT r);  //結果を表示する関数

void InputErrer();

void SameInputErrer();

#endif