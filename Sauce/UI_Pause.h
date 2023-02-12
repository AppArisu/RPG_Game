#pragma once
#include <memory>
#include "UI.h"
#include "Scene.h"
#include "Graphic/Sprite.h"

class UIPause:public UI
{
public:
    UIPause(Scene* scene);
    ~UIPause()override {}

    void Update() override;
    void ProcessInput() override;
    void Render() override;

private:
    std::unique_ptr<Scene> uiScene;
    std::unique_ptr<Sprite> sprite;
};