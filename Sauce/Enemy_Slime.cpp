#include "Enemy_Slime.h"
#include "Graphic/Graphics.h"

EnemySlime::EnemySlime()
{
    EnemySlime::SetHP(Pram().HP);
    EnemySlime::SetMaxHP(Pram().MaxHP);
    EnemySlime::SetAttack(Pram().Attack);
    EnemySlime::SetDefense(Pram().Defense);
    EnemySlime::SetSpeed(Pram().Speed);
}

void EnemySlime::Update(float elapsedTime)
{
}

void EnemySlime::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();

    //float screenWidth = static_cast<float>(graphics.GetScreenWidth());
    //float screenHeight = static_cast<float>(graphics.GetScreenHeight());
    //float textureWidth = static_cast<float>(slime->GetTextureWidth());
    //float textureHeight = static_cast<float>(slime->GetTextureHeight());
}

void EnemySlime::RenderImGui()
{
#if _DEBUG
    ImGui::Begin("Enemy");
    if (ImGui::TreeNode("Slime"))
    {
        int pram[] =
        {
            EnemySlime::GetHP(),
            EnemySlime::GetMaxHP(),
            EnemySlime::GetAttack(),
            EnemySlime::GetDefense(),
            EnemySlime::GetSpeed()
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

void EnemySlime::OnDamaged()
{
}

void EnemySlime::OnDead()
{
}
