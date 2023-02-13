#include "UI_Pause.h"
#include "Input.h"

UIPause::UIPause(Scene* scene)
    :UI(scene)
{
    sprite = std::make_unique<Sprite>("Data/Sprite/Shader/Black.png");
    uiScene->SetGameState(GameState::Paused);
}

void UIPause::Update()
{
    ProcessInput();
}

void UIPause::ProcessInput()
{
    if (GetKeyState(VK_BACK) & 0x8000)
    {
        Closed();
        uiScene->SetGameState(GameState::Play);
    }
}

void UIPause::Render()
{
    Graphics& graphics = Graphics::Instance();
    ID3D11DeviceContext* dc = graphics.GetDeviceContext();

    float screenWidth = static_cast<float>(graphics.GetScreenWidth());
    float screenHeight = static_cast<float>(graphics.GetScreenHeight());
    float textureWidth = static_cast<float>(sprite->GetTextureWidth());
    float textureHeight = static_cast<float>(sprite->GetTextureHeight());

    sprite->Render(dc, 0.0f, 0.0f,
        screenWidth, screenHeight,
        0.0f, 0.0f,
        textureWidth, textureHeight,
        0.0f,
        1.0f, 1.0f, 1.0f, 0.3f);
}
