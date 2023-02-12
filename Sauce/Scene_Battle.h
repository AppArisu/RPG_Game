#pragma once
#include"Scene.h"

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
};