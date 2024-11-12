#pragma once
#include "Character.h"

enum class MovePattern { STRAIGHT, FOLLOW, ZIGZAG };

// 敵クラス：Characterの派生クラス
class Enemy : public Character {
public:
    Enemy(int life, int attack, int speed, MovePattern pattern)
        : Character(life, attack, speed), movePattern(pattern) {}

    // 移動メソッドの実装（移動パターンによって動作を変更）
    void move() override {
        switch (movePattern) {
            case MovePattern::STRAIGHT:
                std::cout << "敵が直進します。" << std::endl;
                break;
            case MovePattern::FOLLOW:
                std::cout << "敵がプレイヤーを追尾します。" << std::endl;
                break;
            case MovePattern::ZIGZAG:
                std::cout << "敵がジグザグに移動します。" << std::endl;
                break;
        }
    }

    // プレイヤーに攻撃するメソッド
    void attackPlayer() {
        std::cout << "敵がプレイヤーに " << attack << " ダメージを与えます。" << std::endl;
    }

private:
    MovePattern movePattern; // 移動パターン
};
