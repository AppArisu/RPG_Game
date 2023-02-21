#pragma once
#include<memory>
#include "Character.h"
#include "Graphic/Sprite.h"
#include "Item.h"

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

private:
    std::unique_ptr<Sprite> sPlayer = nullptr;
};

class Inventory
{
public:
    Inventory() {}
    ~Inventory() {}

    void Update() {}
    void Render() {}
    void RenderImGui() {}

    // アイテム追加
    void AddItem(Parameter itme)
    {
        if (itmes.size() < Capacity)
        {
            itmes.push_back(itme);
        }
    }
    // アイテム削除
    void RemoveItem(int index)
    {
        if (index >= 0 && index < itmes.size())
        {
            itmes.erase(itmes.begin() + index);
        }
    }
    // アイテム取得
    Parameter& GetItem(int index) { return itmes[index]; }
    // アイテムの数を取得
    int GetItemCount()const { return itmes.size(); }

private:
    std::vector<Parameter> itmes;
    const int Capacity = 10;
};