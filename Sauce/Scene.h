#pragma once
#include<vector>

enum GameState
{
	Play,
	Paused,
	Quit
};

// �V�[��
class Scene
{
public:
	Scene() {}
	virtual ~Scene() {}

	// ������
	virtual void Initialize() = 0;

	// �I����
	virtual void Finalize() = 0;

	// �X�V����
	virtual void Update(float elapsedTime) = 0;
	virtual void ProcessInput() = 0;

	// �`�揈��
	virtual void Render() = 0;
	virtual void RenderImGui() {};

	// �����������Ă��邩
	bool IsReady() const { return ready; }

	// ���������ݒ�
	void SetReady() { ready = true; }

	auto GetGameState() const { return this->gState; }
	void SetGameState(auto state) { gState = state; }

private:
	bool	ready = false;

	GameState gState = GameState::Play;
};
