#include<imgui.h>
#include"Shop_Medicine.h"
#include"Item_Medicine.h"

// コンストラクタ
ShopMedicine::ShopMedicine()
{
    TransitionNoneState();

    items = std::make_unique<Item>("Data/Text/Recovery.txt");
}

// 更新処理
void ShopMedicine::Update()
{
    switch (state)
    {
    case Shop::None: // なし
        UpdateNoneState(1);
        break;
    case Shop::Talk: // 話す
        UpdateNoneState(1);
        break;
    case Shop::Buy: // 買う
        UpdateNoneState(1);
        break;
    case Shop::Sell: // 売る
        UpdateNoneState(1);
        break;
    case Shop::End: // 終わり
        UpdateNoneState(1);
        break;
    }
}

// 描画処理
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

// なし
void ShopMedicine::TransitionNoneState()
{
    state = State::None;
}
void ShopMedicine::UpdateNoneState(float elapsedTime)
{
}

// 話す
void ShopMedicine::TransitionTalkState()
{
    state = State::Talk;
}
void ShopMedicine::UpdateTalkState(float elapsedTime)
{
}

// 買う
void ShopMedicine::TransitionBuyState()
{
    state = State::Buy;
}
void ShopMedicine::UpdateBuyState(float elapsedTime)
{
}

// 売る
void ShopMedicine::TransitionSellState()
{
    state = State::Sell;
}
void ShopMedicine::UpdateSellState(float elapsedTime)
{
}

// 終わり
void ShopMedicine::TransitionEndState()
{
    state = State::End;
}
void ShopMedicine::UpdateEndState(float elapsedTime)
{
}
