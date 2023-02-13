#pragma once
#include "Character.h"

class Player :public Character
{
public:
    // コンストラクタ
    Player();
    // デストラクタ
    ~Player() override {}

    // インスタンス取得
    static Player& Instance()
    {
        static Player instance;
        return instance;
    }

    // 更新処理
    void Update(float elapsedTime)override;
    // 描画処理
    void Render()override;

    // ImGui
    void RenderImGui();

protected:
    // ダメージ
    void OnDamaged() override {}
    // 死亡
    void OnDead() override {}

private:
    // パラメーター
    struct Pram
    {
        int HP = 100;
        int MaxHP = 100;
        int Attack = 30;
        int Defense = 20;
        int Speed = 10;
    };
};