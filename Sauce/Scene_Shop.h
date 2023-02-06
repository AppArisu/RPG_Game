#pragma once
#include "Scene.h"

class SceneShop :public Scene
{
public:
    SceneShop();
    ~SceneShop() {}

    void Initialize() override;
    void Finalize() override;

    void Update(float elapsedTime) override;

    void Render() override;
    void RenderImGui() override;

    // ƒV[ƒ“‘JˆÚ
    void Change(Scene* nextscene);

private:

};