#include "Enemy_Robot.h"
#include "Graphic/Graphics.h"

EnemyRobot::EnemyRobot()
{
    EnemyRobot::SetHP(Pram().HP);
    EnemyRobot::SetMaxHP(Pram().MaxHP);
    EnemyRobot::SetAttack(Pram().Attack);
    EnemyRobot::SetDefense(Pram().Defense);
    EnemyRobot::SetSpeed(Pram().Speed);
}

void EnemyRobot::Update(float elapsedTime)
{
}

void EnemyRobot::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();

    //float screenWidth = static_cast<float>(graphics.GetScreenWidth());
    //float screenHeight = static_cast<float>(graphics.GetScreenHeight());
    //float textureWidth = static_cast<float>(slime->GetTextureWidth());
    //float textureHeight = static_cast<float>(slime->GetTextureHeight());
}

void EnemyRobot::RenderImGui()
{
#if _DEBUG
    ImGui::Begin("Enemy");
    if (ImGui::TreeNode("Robot"))
    {
        int pram[] =
        {
            EnemyRobot::GetHP(),
            EnemyRobot::GetMaxHP(),
            EnemyRobot::GetAttack(),
            EnemyRobot::GetDefense(),
            EnemyRobot::GetSpeed()
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

void EnemyRobot::OnDamaged()
{
}

void EnemyRobot::OnDead()
{
}
