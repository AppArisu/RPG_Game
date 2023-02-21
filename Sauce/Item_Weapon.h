#pragma once
#include"Item.h"

class ItemWeapon :public Item
{
public:
    int GetItemID() const { return weaponId; }
    void SetItemID(int id) { this->weaponId = id; }

public:
    enum WeaponID
    {
        Sword_Wood,     // �؂̌�
        Sword_Stone,     // �΂̌�
        Sword_Iron,       // �S�̌�

        WeaponMax
    };

private:
    int weaponId = 0;
};