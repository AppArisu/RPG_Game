#include "Scene_Title.h"
#include "Scene_Manager.h"
#include "Scene_Loading.h"
#include "Scene_Base.h"

// ������
void SceneTitle::Initialize()
{
    texture = std::make_unique<Texture>("Data/Sprite/Title.png");
    maskTexture = std::make_unique<Texture>("Data/Sprite/Shader/dissolve02.png");
    dissolveThreshold = 1.0f;
    dissolveFlg = false;

    sprite = std::make_unique<Sprite>();
    sprite->SetShaderResourceView(texture->GetShaderResourceView(), texture->GetWidth(), texture->GetHeight());
}

// �I����
void SceneTitle::Finalize()
{
}

// �X�V����
void SceneTitle::Update(float elapsedTime)
{
    ProcessInput();

    if (SceneChangeflg)
    {
        Change(elapsedTime);
    }

    // �G�t�F�N�g
    {
        sprite->Update(
            0.0f, 0.0f,
            Graphics::Instance().GetScreenWidth(), Graphics::Instance().GetScreenHeight(),
            0.0f, 0.0f,
            static_cast<float>(texture->GetWidth()), static_cast<float>(texture->GetHeight()),
            0.0f,
            1.0f, 1.0f, 1.0f, 1.0f
        );
    }
}

// �C���v�b�g����
void SceneTitle::ProcessInput()
{
    GamePad& gamePad = Input::Instance().GetGamePad();

    if (gamePad.GetButtonDown() & GamePad::BTN_A)
    {
        SceneChangeflg = true;
    }
}

// �`�揈��
void SceneTitle::Render()
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

    {
        RenderContext rc;
        rc.deviceContext = dc;

        SpriteShader* spShader = graphics.GetSprite(static_cast<int>(SpriteTypeID::Mask));

        spShader->Begin(rc);

        rc.maskData.maskTexture = maskTexture->GetShaderResourceView().Get();
        rc.maskData.dissolveThreshold = dissolveThreshold;

        spShader->Draw(rc, sprite.get());

        spShader->End(rc);
    }
}

// ImGui�`�揈��
void SceneTitle::RenderImGui()
{
#if _DEBUG
    ImGui::Begin("Parameter");
    if (ImGui::TreeNode("Mask"))
    {
        ImGui::SliderFloat("Dissolve Threshold", &dissolveThreshold, 0.0f, 1.0f);
        ImGui::Checkbox("Dissolve Flg", &dissolveFlg);
        ImGui::TreePop();
    }
    ImGui::End();
#endif
}

// �V�[���J�ڏ���
void SceneTitle::Change(float elapsedTime)
{
    if (dissolveThreshold > 0.0f)
    {
        dissolveThreshold -= elapsedTime;
    }
    else
    {
        SceneManager::Instance().ChangeScene(new SceneLoading(new SceneBase));
    }
}