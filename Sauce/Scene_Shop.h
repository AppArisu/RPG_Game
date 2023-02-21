#pragma once
#include "Scene.h"
#include "Player.h"
#include "UI_Pause.h"
#include "Shop_Weapon.h"
#include "Shop_Armor.h"
#include  "Shop_Medicine.h"
#include "Shop_Tool.h"

class SceneShop :public Scene
{
public:
    SceneShop();
    ~SceneShop() {}

    void Initialize() override;
    void Finalize() override;

    void Update(float elapsedTime) override;
    void ProcessInput() override;

    void Render() override;
    void RenderImGui() override;

    // シーン遷移
    void Change(Scene* nextscene);

private:
    bool SceneChangeflg = false;

    // プレイヤー
    std::unique_ptr<Player> player = nullptr;

    // UI
    std::unique_ptr<UIPause> pause = nullptr;

    // ショップ
    std::unique_ptr<ShopWeapon> weapon = nullptr;
    std::unique_ptr<ShopArmor> armor = nullptr;
    std::unique_ptr<ShopMedicine> medicine = nullptr;
    std::unique_ptr<ShopTool> tool = nullptr;
};