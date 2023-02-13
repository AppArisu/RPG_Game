#pragma once
#include<memory>
#include"Scene.h"

class UI
{
public:
    UI(Scene* scene) :uiScene(scene), mState(Active) {}
    virtual ~UI() {}

    virtual void Update() {}
    virtual void ProcessInput() {}
    virtual void Render() {}

    enum UIState
    {
        Active,
        Closing
    };

    auto GetUIState()const { return this->mState; }
    void SetUIState(UIState state) { mState = state; }

protected:
    void Closed() { mState = Closing; }

protected:
    Scene* uiScene = nullptr;
    UIState mState = Closing;
};