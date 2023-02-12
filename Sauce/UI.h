#pragma once
#include<memory>

class UI
{
public:
    UI() {}
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

private:
    UIState mState = Closing;
};