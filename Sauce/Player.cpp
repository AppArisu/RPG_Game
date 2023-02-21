#include<imgui.h>
#include "Player.h"

Player::Player()
{
    Player::SetHP(Pram().HP);
    Player::SetMaxHP(Pram().MaxHP);
    Player::SetAttack(Pram().Attack);
    Player::SetDefense(Pram().Defense);
    Player::SetSpeed(Pram().Speed);

    sPlayer = std::make_unique<Sprite>("Data/Sprite/Character/Woman01.png");
}

void Player::Update(float elapsedTime)
{
}

void Player::Render()
{
    RenderImGui();
}

void Player::RenderImGui()
{
#if _DEBUG
    ImGui::Begin("Character");
    if (ImGui::TreeNode("Player"))
    {
        if (ImGui::TreeNode("Parameter"))
        {
            int pram[] =
            {
                Player::GetHP(),
                Player::GetMaxHP(),
                Player::GetAttack(),
                Player::GetDefense(),
                Player::GetSpeed()
            };

            ImGui::InputInt("HP", &pram[0]);
            ImGui::InputInt("MaxHP", &pram[1]);
            ImGui::InputInt("Attack", &pram[2]);
            ImGui::InputInt("Defense", &pram[3]);
            ImGui::InputInt("Speed", &pram[4]);
            ImGui::TreePop();
        }
        if (ImGui::TreeNode("Items"))
        {
            ImGui::TreePop();
        }
        ImGui::TreePop();
    }
    ImGui::End();
#endif
}
