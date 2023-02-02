#pragma once
#include "Scene.h"

// �^�C�g���V�[��
class SceneSample :public Scene
{
public:
    SceneSample() {}
    ~SceneSample()override {}

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
    bool SceneChangeflg = 0;

};