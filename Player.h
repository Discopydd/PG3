#pragma once
#include "Character.h"
#include "PowerUp.h"

class Player : public Character {
public:
    Player(int life, int attack, int speed) : Character(life, attack, speed), powerLevel(1) {}

    // 移動メソッドの実装
    void move() override {
        std::cout << "プレイヤーが移動しています。" << std::endl;
    }

    // 攻撃メソッド
    void shoot() {
        std::cout << "プレイヤーが射撃！ 攻撃力：" << attack * powerLevel << std::endl;
    }

    // パワーアップアイテムを収集して攻撃力を強化
    void collectPowerUp(const PowerUp& powerUp) {
        powerLevel += powerUp.getEffect();
        std::cout << "パワーアップを取得！現在の攻撃力レベル：" << powerLevel << std::endl;
    }

private:
    int powerLevel; // 攻撃力レベル
};
