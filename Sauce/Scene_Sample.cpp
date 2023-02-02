#include "Scene_Sample.h"
#include "Scene_Manager.h"
#include "Scene_Loading.h"
#include "Graphic/Graphics.h"

// ������
void SceneSample::Initialize()
{
}

// �I����
void SceneSample::Finalize()
{
}

// �X�V����
void SceneSample::Update(float elapsedTime)
{
}

// �C���v�b�g����
void SceneSample::ProcessInput()
{
}

// �`�揈��
void SceneSample::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();
    ID3D11RenderTargetView* rtv = graphics.GetRenderTargetView();
    ID3D11DepthStencilView* dsv = graphics.GetDepthStencilView();

    // ��ʃN���A�������_�[�^�[�Q�b�g�ݒ�
    FLOAT color[] = { 1.0f, 0.0f, 0.0f, 1.0f };	// RGBA(0.0�`1.0)
    dc->ClearRenderTargetView(rtv, color);
    dc->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    dc->OMSetRenderTargets(1, &rtv, dsv);
}

// ImGui�`�揈��
void SceneSample::RenderImGui()
{
#if _DEBUG
#endif
}

// �V�[���J�ڏ���
void SceneSample::Change(float elapsedTime)
{
    //SceneManager::Instance().ChangeScene(new SceneLoading(new SceneGame));
}