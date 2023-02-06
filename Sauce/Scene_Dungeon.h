#pragma once
#include"Scene.h"

class SceneDungeon : public Scene
{
public:
    SceneDungeon();
    ~SceneDungeon() {}

    void Initialize() override;
    void Finalize() override;

    void Update(float elapsedTime) override;

    void Render() override;
    void RenderImGui() override;

    void Change(Scene* nextscene);
private:

};