#pragma once
#include <thread>
#include "Scene.h"
//#include "Graphic/Sprite.h"

// ���[�f�B���O�V�[��
class SceneLoading : public Scene
{
public:
	SceneLoading(Scene* nextScene) : nextScene(nextScene) {}
	~SceneLoading() override {}

	// ������
	void Initialize() override;

	// �I����
	void Finalize() override;

	// �X�V����
	void Update(float elapsedTime) override;
	void ProcessInput() override {}

	// �`�揈��
	void Render() override;
	void RenderImGui() override {}

private:
	// ���[�f�B���O�X���b�h
	static void LoadingThread(SceneLoading* scene);

private:
	Scene* nextScene = nullptr;
	//Sprite* sprite = nullptr;
	float	angle = 0.0f;
	std::thread* thread = nullptr;
};