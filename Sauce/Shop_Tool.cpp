#include<imgui.h>
#include "Shop_Tool.h"
#include "item_Tool.h"

// �R���X�g���N�^
ShopTool::ShopTool()
{
    TransitionNoneState();

    items = std::make_unique<Item>("Data/Text/Tool.txt");
}

// �X�V����
void ShopTool::Update()
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
void ShopTool::Render()
{
    RenderImGui();
}

void ShopTool::RenderImGui()
{
    using enum ItemTool::ToolID;

    ImGui::Begin("Item");
    if (ImGui::TreeNode("Tool"))
    {
        for (int i = 0; i < ToolMax; i++)
        {
            ImGui::Text(items->itemParam(i)->Name);
        }
        ImGui::TreePop();
    }
    ImGui::End();
}

// �Ȃ�
void ShopTool::TransitionNoneState()
{
    state = State::None;
}
void ShopTool::UpdateNoneState(float elapsedTime)
{
}

// �b��
void ShopTool::TransitionTalkState()
{
    state = State::Talk;
}
void ShopTool::UpdateTalkState(float elapsedTime)
{
}

// ����
void ShopTool::TransitionBuyState()
{
    state = State::Buy;
}
void ShopTool::UpdateBuyState(float elapsedTime)
{
}

// ����
void ShopTool::TransitionSellState()
{
    state = State::Sell;
}
void ShopTool::UpdateSellState(float elapsedTime)
{
}

// �I���
void ShopTool::TransitionEndState()
{
    state = State::End;
}
void ShopTool::UpdateEndState(float elapsedTime)
{
}
