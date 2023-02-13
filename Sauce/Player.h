#pragma once
#include "Character.h"

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
};