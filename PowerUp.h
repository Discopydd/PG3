#pragma once

class PowerUp {
public:
    PowerUp(int effect) : effect(effect) {}

    // 効果を取得するメソッド
    int getEffect() const {
        return effect;
    }

private:
    int effect; // 効果値（攻撃力の増加）
};
