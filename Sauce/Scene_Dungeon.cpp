#include "Scene_Dungeon.h"
#include "Scene_Manager.h"
#include "Scene_Loading.h"
#include "Scene_Battle.h"

SceneDungeon::SceneDungeon()
{
}

void SceneDungeon::Initialize()
{
    // �v���C���[
    player = std::make_unique<Player>();
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

        if (GetKeyState(VK_TAB) & 0x8000)
        {
            // �|�[�Y�Ɉڍs
            pause = std::make_unique<UIPause>(this);
        }
    }

    if (GetGameState() == Paused)
    {
        if (GetKeyState(VK_BACK) & 0x8000)
        {
            // �v���C�Ɉڍs
            pause->Update();
        }
    }
}

void SceneDungeon::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();
    ID3D11RenderTargetView* rtv = graphics.GetRenderTargetView();
    ID3D11DepthStencilView* dsv = graphics.GetDepthStencilView();

    // ��ʃN���A�������_�[�^�[�Q�b�g�ݒ�
    FLOAT color[] = { 0.0f, 1.0f, 0.0f, 1.0f };	// RGBA(0.0�`1.0)
    dc->ClearRenderTargetView(rtv, color);
    dc->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    dc->OMSetRenderTargets(1, &rtv, dsv);

    if (GetGameState() == GameState::Paused)
    {
        pause->Render();
        RenderImGui();
    }
}

void SceneDungeon::RenderImGui()
{
#if _DEBUG
    player->RenderImGui();
#endif
}

void SceneDungeon::Change(Scene* nextscene)
{
    SceneManager::Instance().ChangeScene(new SceneLoading(nextscene));
}
