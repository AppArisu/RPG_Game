#pragma once
#include<memory>
#include "Shop.h"
#include "Item.h"

class ShopWeapon :public Shop
{
public:
    ShopWeapon();
    ~ShopWeapon()override {}

    // �C���X�^���X�擾
    static ShopWeapon& Instance()
    {
        static ShopWeapon instance;
        return instance;
    }

    void Update() override;
    void Render() override;
    void RenderImGui() override;

private:
    // �Ȃ�
    void TransitionNoneState() override;
    void UpdateNoneState(float elapsedTime) override;

    // �b��
    void TransitionTalkState() override;
    void UpdateTalkState(float elapsedTime) override;

    // ����
    void TransitionBuyState() override;
    void UpdateBuyState(float elapsedTime) override;

    // ����
    void TransitionSellState() override;
    void UpdateSellState(float elapsedTime) override;

    // �I���
    void TransitionEndState() override;
    void UpdateEndState(float elapsedTime) override;

private:
    std::unique_ptr<Item> items = nullptr;

    int select = 0;
};