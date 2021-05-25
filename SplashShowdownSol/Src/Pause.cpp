#include "Pause.h"
#include "InputManager.h"
#include "SceneMng.h"

bool Pause::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;
	
	correct &= readVariable(parameterTable, "SceneRoute", &pauseSceneRoute);
	correct &= readVariable(parameterTable, "SceneName", &pauseSceneName);

	return correct;
}

void Pause::update()
{
	if(InputManager::Instance()->getKeyDown(SDL_Scancode::SDL_SCANCODE_ESCAPE))
	{
		SceneMng::Instance()->pushNewScene(pauseSceneRoute, pauseSceneName);
		//SceneMng::Instance()->loadScene(pauseSceneRoute, pauseSceneName);
	}
}
