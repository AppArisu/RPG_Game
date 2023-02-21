#include "Enemy_Zombie.h"
#include "Graphic/Graphics.h"

EnemyZombie::EnemyZombie()
{
    EnemyZombie::SetHP(Pram().HP);
    EnemyZombie::SetMaxHP(Pram().MaxHP);
    EnemyZombie::SetAttack(Pram().Attack);
    EnemyZombie::SetDefense(Pram().Defense);
    EnemyZombie::SetSpeed(Pram().Speed);

    sZombie = std::make_unique<Sprite>("Data/Sprite/Character/Human04.png");
}

void EnemyZombie::Update(float elapsedTime)
{
}

void EnemyZombie::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();

    //float screenWidth = static_cast<float>(graphics.GetScreenWidth());
    //float screenHeight = static_cast<float>(graphics.GetScreenHeight());
    //float textureWidth = static_cast<float>(slime->GetTextureWidth());
    //float textureHeight = static_cast<float>(slime->GetTextureHeight());
}

void EnemyZombie::RenderImGui()
{
#if _DEBUG
    ImGui::Begin("Character");
    if (ImGui::TreeNode("Zombie"))
    {
        int pram[] =
        {
            EnemyZombie::GetHP(),
            EnemyZombie::GetMaxHP(),
            EnemyZombie::GetAttack(),
            EnemyZombie::GetDefense(),
            EnemyZombie::GetSpeed()
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

void EnemyZombie::OnDamaged()
{
}

void EnemyZombie::OnDead()
{
}
