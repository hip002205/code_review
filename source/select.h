#ifndef SELECT_H
#define SELECT_H

//選択
typedef enum{
    START,
    END
}SELECT;

SELECT StartEnd();  //ゲームの開始と終了をプレイヤーに選択させる関数

SELECT Rematch();   //プレイヤーに再戦するかを選択させる関数

#endif