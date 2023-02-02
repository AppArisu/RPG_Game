#include"Graphic/Graphics.h"
#include"Scene_Manager.h"
#include"Scene_Loading.h"

// �X�V����
void SceneManager::Update(float elapsedTime)
{
	if (nextScene != nullptr)
	{
		// �Â��V�[�����I������
		Clear();

		// �V�����V�[����ݒ�
		currentScene = nextScene;
		nextScene = nullptr;

		// �V�[������������
		if (!currentScene->IsReady())
		{
			currentScene->Initialize();
		}
	}

	if (currentScene != nullptr)
	{
		currentScene->Update(elapsedTime);
	}
}

// �`�揈��
void SceneManager::Render()
{
	imGuiSceneChanger();

	if (currentScene != nullptr)
	{
		currentScene->Render();
	}
}

// �V�[���N���A
void SceneManager::Clear()
{
	if (currentScene != nullptr)
	{
		currentScene->Finalize();
		delete currentScene;
		currentScene = nullptr;
	}
}

// �V�[���؂�ւ�
void SceneManager::ChangeScene(Scene* scene)
{
	nextScene = scene;
}

// ImGUI�ɂ��V�[���؂�ւ�
void SceneManager::imGuiSceneChanger()
{
#if _DEBUG
	//ImGui::Begin("Scene");
	//if (ImGui::Button("Title"))
	//{
	//	ChangeScene(new SceneLoading(new SceneTitle));
	//}
	//if (ImGui::Button("Game"))
	//{
	//	ChangeScene(new SceneLoading(new SceneGame));
	//}
	//if (ImGui::Button("Shop"))
	//{
	//	ChangeScene(new SceneLoading(new SceneShop));
	//}
	//if (ImGui::Button("Battle"))
	//{
	//	ChangeScene(new SceneLoading(new SceneBattle));
	//}
	//ImGui::End();
#endif
}