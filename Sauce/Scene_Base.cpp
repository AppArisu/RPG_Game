#include "Scene_Base.h"
#include "Scene_Manager.h"
#include "Scene_Loading.h"

#include "Scene_Title.h"
#include "Scene_Shop.h"
#include "Scene_Dungeon.h"

SceneBase::SceneBase()
{
}

void SceneBase::Initialize()
{
}

void SceneBase::Finalize()
{
}

void SceneBase::Update(float elapsedTime)
{
    if (GetGameState() == Play)
    {

    }
}

void SceneBase::Render()
{
}

void SceneBase::RenderImGui()
{
#if _DEBUG
#endif
}

void SceneBase::Change(Scene* nextscene)
{
    SceneManager::Instance().ChangeScene(new SceneLoading(nextscene));
}