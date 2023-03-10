#include <imgui.h>
#include "EnemyManager.h"

void EnemyManager::Update(float elapsedTime)
{
	for (Enemy* enemy : enemies)
	{
		enemy->Update(elapsedTime);
	}

	// ?j??????
	for (Enemy* enemy : removes)
	{
		std::vector<Enemy*>::iterator it = std::find(enemies.begin(), enemies.end(), enemy);
		if (it != enemies.end())
		{
			enemies.erase(it);
		}

		// ?폜
		delete enemy;
	}

	// ?j?????X?g???N???A
	removes.clear();
}

void EnemyManager::Render()
{
	for (Enemy* enemy : enemies)
	{
		enemy->Render();
	}
}

void EnemyManager::Register(Enemy* enemy)
{
	enemies.emplace_back(enemy);
}

void EnemyManager::Clear()
{
	for (Enemy* enemy : enemies)
	{
		delete enemy;
	}
	enemies.clear();
}

void EnemyManager::Remove(Enemy* enemy)
{
	// ?j?????X?g?ɒǉ?
	removes.insert(enemy);
}
