#pragma once
#include <iostream>

class Character {
public:
    Character(int life, int attack, int speed) : life(life), attack(attack), speed(speed) {}
    virtual ~Character() = default;

    // 純仮想関数：移動メソッド
    virtual void move() = 0;

    // ダメージを受けるメソッド
    void takeDamage(int damage) {
        life -= damage;
        if (life <= 0) {
            std::cout << "キャラクターが倒された！" << std::endl;
        }
    }

protected:
    int life;     // 体力
    int attack;   // 攻撃力
    int speed;    // スピード
};
