#pragma once
#include "Enemy.h"

class EnemyZombie :public Enemy
{
public:
    EnemyZombie();
    ~EnemyZombie()override {}

    void Update(float elapsedTime)override;
    void Render()override;
    void RenderImGui();

protected:
    // ダメージ
    void OnDamaged() override;
    // 死亡
    void OnDead() override;

private:
    // パラメーター
    struct Pram
    {
        int HP = 20;
        int MaxHP = 20;
        int Attack = 10;
        int Defense = 0;
        int Speed = 5;
    };

private:

};