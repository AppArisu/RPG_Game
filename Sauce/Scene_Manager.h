#pragma once
#include <string>
#include "Scene.h"

// �V�[���}�l�[�W���[
class SceneManager
{
private:
	SceneManager() {}
	~SceneManager() {}

public:
	// �B��̃C���X�^���X�擾
	static SceneManager& Instance()
	{
		static SceneManager instance;
		return instance;
	}

	// �X�V����
	void Update(float elapsedTime);

	// �`�揈��
	void Render();

	// �V�[���N���A
	void Clear();

	// �V�[���؂�ւ�
	void ChangeScene(Scene* scene);

	// imGui�ɂ��V�[���؂�ւ�
	void imGuiSceneChanger();

private:
	Scene* currentScene = nullptr;
	Scene* nextScene = nullptr;

#if _DEBUG
	bool Sceneflg[6] = {};
	std::string SceneName[6] =
	{
		"Sample",
		"Title",
		"Base",
		"Shop",
		"Dungeon",
		"Battle"
	};
#endif
};