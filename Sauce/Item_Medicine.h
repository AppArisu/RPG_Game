#pragma once
#include"Item.h"

class ItemRecovery :public Item
{
public:
    int GetItemID() const { return recoveryId; }
    void SetItemID(int id) { this->recoveryId = id; }

public:
    enum RecoveryID
    {
        Herb_Cure,              // ��
        Herb_AntiPoison,     // �ŏ�����
        Portion_Cure,          // �񕜖�
        Portion_AntiPoison, // �ŏ�����

        RecoveryMax
    };

private:
    int recoveryId = 0;
};