#include "Player.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "Stage.h"

int main() {
    // プレイヤーを生成
    Player player(100, 20, 5);

    // パワーアップアイテムを生成
    PowerUp powerUp(1);

    // プレイヤーがパワーアップアイテムを取得し、攻撃を行う
    player.collectPowerUp(powerUp);
    player.shoot();

    // ステージを生成し、敵を出現させる
    Stage stage({ MovePattern::STRAIGHT, MovePattern::FOLLOW, MovePattern::ZIGZAG });
    stage.spawnEnemies();

    // 敵がプレイヤーを攻撃
    Enemy enemy(50, 10, 3, MovePattern::FOLLOW);
    enemy.attackPlayer();
    player.takeDamage(10);

    return 0;
}
