#include<imgui.h>
#include"Item_Weapon.h"
#include"Shop_Weapon.h"
#include"Player.h"

// �R���X�g���N�^
ShopWeapon::ShopWeapon()
{
    TransitionNoneState();

    items = std::make_unique<Item>("Data/Text/Weapon.txt");
}

// �X�V����
void ShopWeapon::Update()
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
void ShopWeapon::Render()
{
    RenderImGui();
}

void ShopWeapon::RenderImGui()
{
    using enum ItemWeapon::WeaponID;

    ImGui::Begin("Item");
    if (ImGui::TreeNode("Weapon"))
    {
        for (int i = 0; i < WeaponMax; i++)
        {
            ImGui::Text(items->itemParam(i)->Name);
        }
        ImGui::TreePop();
    }
    ImGui::End();
}

// �Ȃ�
void ShopWeapon::TransitionNoneState()
{
    state = State::None;
}
void ShopWeapon::UpdateNoneState(float elapsedTime)
{
}

// �b��
void ShopWeapon::TransitionTalkState()
{
    state = State::Talk;
}
void ShopWeapon::UpdateTalkState(float elapsedTime)
{
}

// ����
void ShopWeapon::TransitionBuyState()
{
    state = State::Buy;
}
void ShopWeapon::UpdateBuyState(float elapsedTime)
{
}

// ����
void ShopWeapon::TransitionSellState()
{
    state = State::Sell;
}
void ShopWeapon::UpdateSellState(float elapsedTime)
{
}

// �I���
void ShopWeapon::TransitionEndState()
{
    state = State::End;
}
void ShopWeapon::UpdateEndState(float elapsedTime)
{
}
