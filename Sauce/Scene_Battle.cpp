#include "Scene_Battle.h"
#include "Scene_Manager.h"
#include "Scene_Loading.h"
#include "Scene_Base.h"

SceneBattle::SceneBattle()
{
}

void SceneBattle::Initialize()
{
}

void SceneBattle::Finalize()
{
}

void SceneBattle::Update(float elapsedTime)
{
    ProcessInput();

    if (SceneChangeflg)
    {
        SceneChangeflg = true;
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
            Change(new SceneBase);
        }
    }
}

void SceneBattle::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();
    ID3D11RenderTargetView* rtv = graphics.GetRenderTargetView();
    ID3D11DepthStencilView* dsv = graphics.GetDepthStencilView();

    // ��ʃN���A�������_�[�^�[�Q�b�g�ݒ�
    FLOAT color[] = { 1.0f, 1.0f, 0.0f, 1.0f };	// RGBA(0.0�`1.0)
    dc->ClearRenderTargetView(rtv, color);
    dc->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    dc->OMSetRenderTargets(1, &rtv, dsv);
}

void SceneBattle::RenderImGui()
{
#if _DEBUG
#endif
}

void SceneBattle::Change(Scene* nextscene)
{
    SceneManager::Instance().ChangeScene(new SceneLoading(nextscene));
}
