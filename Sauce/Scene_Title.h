#pragma once
#include "Scene.h"
#include "Graphic/Sprite.h"
#include "Graphic/Texture.h"

// �^�C�g���V�[��
class SceneTitle :public Scene
{
public:
    SceneTitle() {}
    ~SceneTitle()override {}

    // ������
    void Initialize() override;

    // �I����
    void Finalize() override;

    // �X�V����
    void Update(float elapsedTime) override;
    void ProcessInput() override;

    // �`�揈��
    void Render() override;
    void RenderImGui() override;

    // �V�[���J��
    void Change(float elapsedTime);

private:
    std::unique_ptr<Sprite> sprite;
    std::unique_ptr<Texture> texture;
    std::unique_ptr<Texture> maskTexture;

    float dissolveThreshold = 0.0f;
    bool dissolveFlg = false;

    bool SceneChangeflg = 0;
};