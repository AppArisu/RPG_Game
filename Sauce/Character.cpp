#include "Character.h"

bool Character::ApplyDamage(int damage)
{
    if (damage == 0 || HP <= 0) return false;

    // �_���[�W����
    HP -= damage;

    // ���Sor�_���[�W
    if (HP <= 0)
    {
        OnDead();
    }
    else
    {
        OnDamaged();
    }

    return true;
}
