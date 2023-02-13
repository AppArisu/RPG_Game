#include"Graphic/Graphics.h"

#include"Scene_Manager.h"
#include"Scene_Loading.h"
#include"Scene_Sample.h"
#include"Scene_Title.h"
#include"Scene_Base.h"
#include"Scene_Shop.h"
#include"Scene_Dungeon.h"
#include"Scene_Battle.h"

// 更新処理
void SceneManager::Update(float elapsedTime)
{
	if (nextScene != nullptr)
	{
		// 古いシーンを終了処理
		Clear();

		// 新しいシーンを設定
		currentScene = nextScene;
		nextScene = nullptr;

		// シーン初期化処理
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

// 描画処理
void SceneManager::Render()
{
	imGuiSceneChanger();

	if (currentScene != nullptr)
	{
		currentScene->Render();
	}
}

// シーンクリア
void SceneManager::Clear()
{
	if (currentScene != nullptr)
	{
		currentScene->Finalize();
		delete currentScene;
		currentScene = nullptr;
	}
}

// シーン切り替え
void SceneManager::ChangeScene(Scene* scene)
{
	nextScene = scene;

	for (int i = 0; i < 6; i++)
	{
		Sceneflg[i] = false;
	}
}

// ImGUIによるシーン切り替え
void SceneManager::imGuiSceneChanger()
{
#if _DEBUG
	ImGui::Begin("Scene");
	if (ImGui::Button("Sample"))
	{
		ChangeScene(new SceneLoading(new SceneSample));
		Sceneflg[0] = true;
	}
	if (ImGui::Button("Title"))
	{
		ChangeScene(new SceneLoading(new SceneTitle));
		Sceneflg[1] = true;
	}
	if (ImGui::Button("Base"))
	{
		ChangeScene(new SceneLoading(new SceneBase));
		Sceneflg[2] = true;
	}
	if (ImGui::Button("Shop"))
	{
		ChangeScene(new SceneLoading(new SceneShop));
		Sceneflg[3] = true;
	}
	if (ImGui::Button("Dungeon"))
	{
		ChangeScene(new SceneLoading(new SceneDungeon));
		Sceneflg[4] = true;
	}
	if (ImGui::Button("Battle"))
	{
		ChangeScene(new SceneLoading(new SceneBattle));
		Sceneflg[5] = true;
	}
	for (int i = 0; i < 6; i++)
	{
		ImGui::Checkbox(SceneName[i].c_str(), &Sceneflg[i]);
	}

	ImGui::End();
#endif
}