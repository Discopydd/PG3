#pragma once
#include <vector>
#include "Enemy.h"
class Stage {
public:
    Stage(const std::vector<MovePattern>& patterns) : enemySpawnPatterns(patterns) {}

    // 敵を出現させるメソッド
    void spawnEnemies() {
        for (const auto& pattern : enemySpawnPatterns) {
            Enemy enemy(100, 10, 2, pattern);
            enemies.push_back(enemy);
            std::cout << "敵が生成されました。移動パターン：";
            enemy.move();
        }
    }

private:
    std::vector<MovePattern> enemySpawnPatterns; // 敵の出現パターン
    std::vector<Enemy> enemies;                      // ステージ上の敵リスト
};
