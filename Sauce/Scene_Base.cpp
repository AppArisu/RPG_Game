#include "Scene_Base.h"
#include "Scene_Manager.h"
#include "Scene_Loading.h"

#include "Scene_Title.h"
#include "Scene_Shop.h"
#include "Scene_Dungeon.h"

SceneBase::SceneBase()
{
}

void SceneBase::Initialize()
{
    // プレイヤー
    player = std::make_unique<Player>();
}

void SceneBase::Finalize()
{
}

void SceneBase::Update(float elapsedTime)
{
    ProcessInput();

    if (GetGameState() == Play)
    {
        switch (state)
        {
            using enum SceneBase::ChangeState;
        case Base:
            break;
        case Shop_Weapon:
            Change(new SceneShop);
            break;
        case Shop_Defense:
            Change(new SceneShop);
            break;
        case Shop_Recovery:
            Change(new SceneShop);
            break;
        case Shop_Tool:
            Change(new SceneShop);
            break;
        case Dungeon:
            Change(new SceneDungeon);
            break;
        case End:
            Change(new SceneTitle);
            break;
        }
    }
}

void SceneBase::ProcessInput()
{
    GamePad& gamePad = Input::Instance().GetGamePad();

    if (GetGameState() == Play)
    {
        if (gamePad.GetButtonDown() & GamePad::BTN_UP)
        {
            state = ChangeState::Shop_Weapon;
        }
        //if (gamePad.GetButtonDown() & GamePad::BTN_UP)
        //{
        //    state = ChangeState::Shop_Defense;
        //}
        //if (gamePad.GetButtonDown() & GamePad::BTN_UP)
        //{
        //    state = ChangeState::Shop_Recovery;
        //}
        //if (gamePad.GetButtonDown() & GamePad::BTN_UP)
        //{
        //    state = ChangeState::Shop_Tool;
        //}
        if (gamePad.GetButtonDown() & GamePad::BTN_A)
        {
            state = ChangeState::Dungeon;
        }
        if (gamePad.GetButtonDown() & GamePad::BTN_BACK)
        {
            state = ChangeState::End;
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

void SceneBase::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();
    ID3D11RenderTargetView* rtv = graphics.GetRenderTargetView();
    ID3D11DepthStencilView* dsv = graphics.GetDepthStencilView();

    // 画面クリア＆レンダーターゲット設定
    FLOAT color[] = { 0.0f, 0.0f, 1.0f, 1.0f };	// RGBA(0.0～1.0)
    dc->ClearRenderTargetView(rtv, color);
    dc->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    dc->OMSetRenderTargets(1, &rtv, dsv);

    if (GetGameState() == GameState::Paused)
    {
        pause->Render();
        RenderImGui();
    }
}

void SceneBase::RenderImGui()
{
#if _DEBUG
    player->RenderImGui();
#endif
}

void SceneBase::Change(Scene* nextscene)
{
    SceneManager::Instance().ChangeScene(new SceneLoading(nextscene));
}