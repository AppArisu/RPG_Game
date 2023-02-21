#pragma once
#include"Item.h"

class ItemArmor :public Item
{
public:
    int GetItemID() const { return armorId; }
    void SetItemID(int id) { this->armorId = id; }

public:
    enum ArmorID
    {
        Leather_Hat,        // ��̖X�q
        Leather_Armor,    // ��̊Z
        Iron_Helmet,        // �S�̊�
        Iron_Armor,         // �S�̊Z

        ArmorMax
    };

private:
    int armorId = 0;
};