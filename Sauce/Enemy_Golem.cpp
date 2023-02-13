#include "Enemy_Golem.h"
#include "Graphic/Graphics.h"

EnemyGolem::EnemyGolem()
{
    EnemyGolem::SetHP(Pram().HP);
    EnemyGolem::SetMaxHP(Pram().MaxHP);
    EnemyGolem::SetAttack(Pram().Attack);
    EnemyGolem::SetDefense(Pram().Defense);
    EnemyGolem::SetSpeed(Pram().Speed);
}

void EnemyGolem::Update(float elapsedTime)
{
}

void EnemyGolem::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();

    //float screenWidth = static_cast<float>(graphics.GetScreenWidth());
    //float screenHeight = static_cast<float>(graphics.GetScreenHeight());
    //float textureWidth = static_cast<float>(slime->GetTextureWidth());
    //float textureHeight = static_cast<float>(slime->GetTextureHeight());
}

void EnemyGolem::RenderImGui()
{
#if _DEBUG
    ImGui::Begin("Enemy");
    if (ImGui::TreeNode("Golem"))
    {
        int pram[] =
        {
            EnemyGolem::GetHP(),
            EnemyGolem::GetMaxHP(),
            EnemyGolem::GetAttack(),
            EnemyGolem::GetDefense(),
            EnemyGolem::GetSpeed()
        };

        ImGui::InputInt("HP", &pram[0]);
        ImGui::InputInt("MaxHP", &pram[1]);
        ImGui::InputInt("Attack", &pram[2]);
        ImGui::InputInt("Defense", &pram[3]);
        ImGui::InputInt("Speed", &pram[4]);
        ImGui::TreePop();
    }
    ImGui::End();
#endif
}

void EnemyGolem::OnDamaged()
{
}

void EnemyGolem::OnDead()
{
}
