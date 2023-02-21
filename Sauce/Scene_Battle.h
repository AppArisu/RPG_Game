#pragma once
#include"Scene.h"

#include "Player.h"

#include "Enemy.h"
#include "Enemy_Slime.h"
#include "Enemy_Zombie.h"
#include "Enemy_Robot.h"
#include "Enemy_Golem.h"

#include "UI_Pause.h"

class SceneBattle :public Scene
{
public:
    SceneBattle();
    ~SceneBattle() {}

    void Initialize() override;
    void Finalize() override;

    void Update(float elapsedTime) override;
    void ProcessInput() override;

    void Render() override;
    void RenderImGui() override;

    void Change(Scene* nextscene);

private:
    enum EnemyID
    {
        None,
        Slime,
        Robot,
        Zombie,
        Golem
    };
    void CallEnemy(Enemy* enemy, EnemyID id);

private:
    // プレイヤー
    std::unique_ptr<Player> player = nullptr;
    // エネミー
    EnemySlime* slime = nullptr;
    EnemyRobot* robot = nullptr;
    EnemyZombie* zombie = nullptr;
    EnemyGolem* golem = nullptr;
    // UI
    std::unique_ptr<UIPause> pause = nullptr;

    EnemyID enemyID = EnemyID::None;

    bool SceneChangeflg = false;
};