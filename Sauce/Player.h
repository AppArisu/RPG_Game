#pragma once
#include<memory>
#include "Character.h"
#include "Graphic/Sprite.h"
#include "Item.h"

class Player :public Character
{
public:
    // �R���X�g���N�^
    Player();
    // �f�X�g���N�^
    ~Player() override {}

    // �C���X�^���X�擾
    static Player& Instance()
    {
        static Player instance;
        return instance;
    }

    // �X�V����
    void Update(float elapsedTime)override;
    // �`�揈��
    void Render()override;

    // ImGui
    void RenderImGui();

protected:
    // �_���[�W
    void OnDamaged() override {}
    // ���S
    void OnDead() override {}

private:
    // �p�����[�^�[
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

    // �A�C�e���ǉ�
    void AddItem(Parameter itme)
    {
        if (itmes.size() < Capacity)
        {
            itmes.push_back(itme);
        }
    }
    // �A�C�e���폜
    void RemoveItem(int index)
    {
        if (index >= 0 && index < itmes.size())
        {
            itmes.erase(itmes.begin() + index);
        }
    }
    // �A�C�e���擾
    Parameter& GetItem(int index) { return itmes[index]; }
    // �A�C�e���̐����擾
    int GetItemCount()const { return itmes.size(); }

private:
    std::vector<Parameter> itmes;
    const int Capacity = 10;
};