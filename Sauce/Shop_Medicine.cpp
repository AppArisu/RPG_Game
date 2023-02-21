#include<imgui.h>
#include"Shop_Medicine.h"
#include"Item_Medicine.h"

// �R���X�g���N�^
ShopMedicine::ShopMedicine()
{
    TransitionNoneState();

    items = std::make_unique<Item>("Data/Text/Recovery.txt");
}

// �X�V����
void ShopMedicine::Update()
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
void ShopMedicine::Render()
{
    RenderImGui();
}

void ShopMedicine::RenderImGui()
{
    using enum ItemRecovery::RecoveryID;
    ImGui::Begin("Item");
    if (ImGui::TreeNode("Medicine"))
    {
        for (int i = 0; i < RecoveryMax; i++)
        {
            ImGui::Text(items->itemParam(i)->Name);
        }
        ImGui::TreePop();
    }
    ImGui::End();
}

// �Ȃ�
void ShopMedicine::TransitionNoneState()
{
    state = State::None;
}
void ShopMedicine::UpdateNoneState(float elapsedTime)
{
}

// �b��
void ShopMedicine::TransitionTalkState()
{
    state = State::Talk;
}
void ShopMedicine::UpdateTalkState(float elapsedTime)
{
}

// ����
void ShopMedicine::TransitionBuyState()
{
    state = State::Buy;
}
void ShopMedicine::UpdateBuyState(float elapsedTime)
{
}

// ����
void ShopMedicine::TransitionSellState()
{
    state = State::Sell;
}
void ShopMedicine::UpdateSellState(float elapsedTime)
{
}

// �I���
void ShopMedicine::TransitionEndState()
{
    state = State::End;
}
void ShopMedicine::UpdateEndState(float elapsedTime)
{
}
