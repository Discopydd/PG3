#include <iostream>
#include <conio.h> 

using namespace std;

class Enemy {
public:
   
    typedef void (Enemy::*StateFunc)();

    // 静的メンバ関数ポインタテーブル
    static StateFunc stateTable[];

    // コンストラクタ、初期状態インデックスを0（接近状態）に設定
    Enemy() : stateIndex(0) {}

    // 現在の状態関数を実行
    void update() {
        if (stateTable[stateIndex] != nullptr) {
            (this->*stateTable[stateIndex])();  // 現在の状態関数を呼び出す
        }
    }

private:
    int stateIndex;  // 現在の状態インデックス

    // 状態：接近
    void approach() {
        cout << "敵が接近しています！" << endl;
        stateIndex = 1;  
    }

    // 状態：射撃
    void shoot() {
        cout << "敵が射撃しています！" << endl;
        stateIndex = 2; 
    }

    // 状態：離脱
    void retreat() {
        cout << "敵が離脱しています！" << endl;
        stateIndex = 0; 
    }
};

// 静的メンバ関数ポインタテーブルの初期化
Enemy::StateFunc Enemy::stateTable[] = {
    &Enemy::approach,  // インデックス0は接近状態
    &Enemy::shoot,     // インデックス1は射撃状態
    &Enemy::retreat,   // インデックス2は離脱状態
    nullptr            // 終了マーカー（オプション）
};

int main() {
    Enemy enemy;

    cout << "任意のキーで状態を更新、'0' キーで終了..." << endl;

    while (true) {
        // キーが押された場合
        if (_kbhit()) {
            // 押されたキーを取得
            char ch = _getch();

            if (ch == '0') {
                cout << "プログラムを終了します..." << endl;
                break;
            }

            // その他のキーが押された場合、状態を更新
            enemy.update();
        }
    }

    return 0;
}
