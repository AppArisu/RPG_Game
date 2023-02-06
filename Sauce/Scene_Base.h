#pragma once
#include"Scene.h"

class SceneBase :public Scene
{
public:
    SceneBase();
    ~SceneBase() {}

    void Initialize() override;
    void Finalize() override;

    void Update(float elapsedTime) override;

    void Render() override;
    void RenderImGui() override;

    void Change(Scene* nextscene);

private:

};