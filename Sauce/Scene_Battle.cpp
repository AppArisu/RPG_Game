#include "Scene_Battle.h"
#include "Scene_Manager.h"
#include "Scene_Loading.h"
#include "Scene_Base.h"
#include "EnemyManager.h"

SceneBattle::SceneBattle()
{
}

void SceneBattle::Initialize()
{
    // プレイヤー
    player = std::make_unique<Player>();

    // エネミー
    CallEnemy(slime, Slime);
    CallEnemy(robot, Robot);
    CallEnemy(zombie, Zombie);
    CallEnemy(golem, Golem);
}

void SceneBattle::Finalize()
{
    EnemyManager::Instance().Clear();
}

void SceneBattle::Update(float elapsedTime)
{
    ProcessInput();

    if (SceneChangeflg)
    {
        Change(new SceneBase);
    }
}

void SceneBattle::ProcessInput()
{
    GamePad& gamePad = Input::Instance().GetGamePad();

    if (GetGameState() == GameState::Play)
    {
        if (gamePad.GetButtonDown() & GamePad::BTN_A)
        {
            SceneChangeflg = true;
        }

        if (GetKeyState(VK_TAB) & 0x8000)
        {
            // ポーズに移行
            pause = std::make_unique<UIPause>(this);
        }
    }

    if (GetGameState() == Paused)
    {
        if (GetKeyState(VK_BACK) & 0x8000)
        {
            // プレイに移行
            pause->Update();
        }
    }
}

void SceneBattle::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();
    ID3D11RenderTargetView* rtv = graphics.GetRenderTargetView();
    ID3D11DepthStencilView* dsv = graphics.GetDepthStencilView();

    // 画面クリア＆レンダーターゲット設定
    FLOAT color[] = { 1.0f, 1.0f, 0.0f, 1.0f };	// RGBA(0.0～1.0)
    dc->ClearRenderTargetView(rtv, color);
    dc->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    dc->OMSetRenderTargets(1, &rtv, dsv);

    if (GetGameState() == GameState::Paused)
    {
        pause->Render();
        RenderImGui();
    }
}

void SceneBattle::RenderImGui()
{
#if _DEBUG
    player->RenderImGui();

    slime->RenderImGui();
    zombie->RenderImGui();
    robot->RenderImGui();
    golem->RenderImGui();
#endif
}

void SceneBattle::Change(Scene* nextscene)
{
    SceneManager::Instance().ChangeScene(new SceneLoading(nextscene));
}

void SceneBattle::CallEnemy(Enemy* enemy, EnemyID id)
{
    EnemyManager& enemyManager = EnemyManager::Instance();

    switch (id)
    {
    case SceneBattle::Slime:
        slime = new EnemySlime;
        break;
    case SceneBattle::Robot:
        robot = new EnemyRobot;
        break;
    case SceneBattle::Zombie:
        zombie = new EnemyZombie;
        break;
    case SceneBattle::Golem:
        golem = new EnemyGolem;
        break;
    }
    enemyManager.Register(enemy);
}
