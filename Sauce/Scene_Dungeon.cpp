#include "Scene_Dungeon.h"
#include "Scene_Manager.h"
#include "Scene_Loading.h"
#include "Scene_Battle.h"

SceneDungeon::SceneDungeon()
{
}

void SceneDungeon::Initialize()
{
}

void SceneDungeon::Finalize()
{
}

void SceneDungeon::Update(float elapsedTime)
{
    ProcessInput();

    if (SceneChangeflg)
    {
        Change(new SceneBattle);
    }
}

void SceneDungeon::ProcessInput()
{
    GamePad& gamePad = Input::Instance().GetGamePad();

    if (GetGameState() == GameState::Play)
    {
        if (gamePad.GetButtonDown() & GamePad::BTN_A)
        {
            SceneChangeflg = true;
        }
    }
}

void SceneDungeon::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();
    ID3D11RenderTargetView* rtv = graphics.GetRenderTargetView();
    ID3D11DepthStencilView* dsv = graphics.GetDepthStencilView();

    // 画面クリア＆レンダーターゲット設定
    FLOAT color[] = { 0.0f, 1.0f, 0.0f, 1.0f };	// RGBA(0.0～1.0)
    dc->ClearRenderTargetView(rtv, color);
    dc->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    dc->OMSetRenderTargets(1, &rtv, dsv);
}

void SceneDungeon::RenderImGui()
{
#if _DEBUG
#endif
}

void SceneDungeon::Change(Scene* nextscene)
{
    SceneManager::Instance().ChangeScene(new SceneLoading(nextscene));
}
