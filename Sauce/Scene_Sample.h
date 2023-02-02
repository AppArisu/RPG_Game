#pragma once
#include "Scene.h"

// タイトルシーン
class SceneSample :public Scene
{
public:
    SceneSample() {}
    ~SceneSample()override {}

    // 初期化
    void Initialize() override;

    // 終了化
    void Finalize() override;

    // 更新処理
    void Update(float elapsedTime) override;
    void ProcessInput() override;

    // 描画処理
    void Render() override;
    void RenderImGui() override;

    // シーン遷移
    void Change(float elapsedTime);

private:
    bool SceneChangeflg = 0;

};