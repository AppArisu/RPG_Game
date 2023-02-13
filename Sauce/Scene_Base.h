#pragma once
#include"Scene.h"
#include "Player.h"
#include "UI_Pause.h"

class SceneBase :public Scene
{
public:
    SceneBase();
    ~SceneBase() {}

    void Initialize() override;
    void Finalize() override;

    void Update(float elapsedTime) override;
    void ProcessInput() override;

    void Render() override;
    void RenderImGui() override; 

    void Change(Scene* nextscene);

private:
    enum class ChangeState
    {
        Base,
        Shop_Weapon,
        Shop_Defense,
        Shop_Recovery,
        Shop_Tool,
        Dungeon,
        End
    };

private:
    ChangeState state = ChangeState::Base;

    bool SceneChangeflg = false;

    // ÉvÉåÉCÉÑÅ[
    std::unique_ptr<Player> player = nullptr;
    // UI
    std::unique_ptr<UIPause> pause = nullptr;
};