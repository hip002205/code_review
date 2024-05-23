#include <iostream>
#include "select.h"

typedef enum {
    START,
    END
} SELECT;

SELECT StartEnd() {
    // ユーザーにゲームの開始終了を選択させる
    char input;
    scanf("%c", input);
    // yで三目並べ開始、nで終了
    if (input == 'y') {
        // 三目並べ開始
        return START;
    } else if (input == 'n') {
        // 三目並べ終了
        return END;
    }
    // [y/n]以外の入力はエラーとする
}

SELECT Rematch() {
    // ユーザーにゲームの開始終了を選択させる
    char input;
    scanf("%c", input);
    // yで三目並べ開始、nで終了
    if (input == 'y') {
        // 三目並べ開始
        return START;
    } else if (input == 'n') {
        // 三目並べ終了
        return END;
    }
    // [y/n]以外の入力はエラーとする
}