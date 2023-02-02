#include "Scene_Sample.h"
#include "Scene_Manager.h"
#include "Scene_Loading.h"
#include "Graphic/Graphics.h"

// 初期化
void SceneSample::Initialize()
{
}

// 終了化
void SceneSample::Finalize()
{
}

// 更新処理
void SceneSample::Update(float elapsedTime)
{
}

// インプット処理
void SceneSample::ProcessInput()
{
}

// 描画処理
void SceneSample::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();
    ID3D11RenderTargetView* rtv = graphics.GetRenderTargetView();
    ID3D11DepthStencilView* dsv = graphics.GetDepthStencilView();

    // 画面クリア＆レンダーターゲット設定
    FLOAT color[] = { 1.0f, 0.0f, 0.0f, 1.0f };	// RGBA(0.0～1.0)
    dc->ClearRenderTargetView(rtv, color);
    dc->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    dc->OMSetRenderTargets(1, &rtv, dsv);
}

// ImGui描画処理
void SceneSample::RenderImGui()
{
#if _DEBUG
#endif
}

// シーン遷移処理
void SceneSample::Change(float elapsedTime)
{
    //SceneManager::Instance().ChangeScene(new SceneLoading(new SceneGame));
}