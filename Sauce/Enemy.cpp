#include "Enemy.h"
#include "EnemyManager.h"

// ”j‰ó
void Enemy::Destroy()
{
    EnemyManager::Instance().Remove(this);
}
