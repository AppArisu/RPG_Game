#include <imgui.h>
#include "Shop_Armor.h"
#include "Item_Armor.h"

// �R���X�g���N�^
ShopArmor::ShopArmor()
{
    TransitionNoneState();

    items = std::make_unique<Item>("Data/Text/Armor.txt");
}

// �X�V����
void ShopArmor::Update()
{
    switch (state)
    {
    case Shop::None: // �Ȃ�
        UpdateNoneState(1);
        break;
    case Shop::Talk: // �b��
        UpdateNoneState(1);
        break;
    case Shop::Buy: // ����
        UpdateNoneState(1);
        break;
    case Shop::Sell: // ����
        UpdateNoneState(1);
        break;
    case Shop::End: // �I���
        UpdateNoneState(1);
        break;
    }
}

// �`�揈��
void ShopArmor::Render()
{
    RenderImGui();
}

void ShopArmor::RenderImGui()
{
    using enum ItemArmor::ArmorID;
    ImGui::Begin("Item");
    if (ImGui::TreeNode("Armor"))
    {
        for (int i = 0; i < ArmorMax; i++)
        {
            ImGui::Text(items->itemParam(i)->Name);
        }
        ImGui::TreePop();
    }
    ImGui::End();
}

// �Ȃ�
void ShopArmor::TransitionNoneState()
{
    state = State::None;
}
void ShopArmor::UpdateNoneState(float elapsedTime)
{
}

// �b��
void ShopArmor::TransitionTalkState()
{
    state = State::Talk;
}
void ShopArmor::UpdateTalkState(float elapsedTime)
{
}

// ����
void ShopArmor::TransitionBuyState()
{
    state = State::Buy;
}
void ShopArmor::UpdateBuyState(float elapsedTime)
{
}

// ����
void ShopArmor::TransitionSellState()
{
    state = State::Sell;
}
void ShopArmor::UpdateSellState(float elapsedTime)
{
}

// �I���
void ShopArmor::TransitionEndState()
{
    state = State::End;
}
void ShopArmor::UpdateEndState(float elapsedTime)
{
}
