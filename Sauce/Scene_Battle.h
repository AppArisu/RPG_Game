#pragma once
#include"Scene.h"
#include "Player.h"
#include "UI_Pause.h"

class SceneBattle :public Scene
{
public:
    SceneBattle();
    ~SceneBattle() {}

    void Initialize() override;
    void Finalize() override;

    void Update(float elapsedTime) override;
    void ProcessInput() override;

    void Render() override;
    void RenderImGui() override;

    void Change(Scene* nextscene);

private:
    bool SceneChangeflg = false;

    // ÉvÉåÉCÉÑÅ[
    std::unique_ptr<Player> player = nullptr;
    // UI
    std::unique_ptr<UIPause> pause = nullptr;
};