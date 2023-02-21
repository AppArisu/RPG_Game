#pragma once
#include<memory>
#include "Enemy.h"
#include "Graphic/Sprite.h"

class EnemyRobot :public Enemy
{
public:
    EnemyRobot();
    ~EnemyRobot()override {}

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
    std::unique_ptr<Sprite> sRobot = nullptr;
};