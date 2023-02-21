#pragma once

class Shop
{
public:
    Shop() {}
    virtual ~Shop() {}

    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void RenderImGui() = 0;

    auto GetEndState() const { return endflg; }
    void SetEndState(auto end) { this->endflg = end; }

protected:
    // �Ȃ�
    virtual void TransitionNoneState() {}
    virtual void UpdateNoneState(float elapsedTime) {}

    // �Ȃ�
    virtual void TransitionTalkState() {}
    virtual void UpdateTalkState(float elapsedTime) {}

    // ����
    virtual void TransitionBuyState() {}
    virtual void UpdateBuyState(float elapsedTime) {}

    // ����
    virtual void TransitionSellState() {}
    virtual void UpdateSellState(float elapsedTime) {}

    // �I��
    virtual void TransitionEndState() {}
    virtual void UpdateEndState(float elapsedTime) {}

    enum State
    {
        None,
        Talk,
        Buy,
        Sell,
        End
    };

    State state = State::None;

    bool endflg = true;
};