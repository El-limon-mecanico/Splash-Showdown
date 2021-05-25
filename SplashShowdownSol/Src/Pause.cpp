#include "Pause.h"
#include "InputManager.h"
#include "SceneMng.h"

bool Pause::init(luabridge::LuaRef parameterTable)
{
	readVariable(parameterTable, "SceneRoute", &pauseSceneRoute);
	readVariable(parameterTable, "SceneName", &pauseSceneName);

	return true;
}

void Pause::update()
{
	if(InputManager::Instance()->getKeyDown(SDL_Scancode::SDL_SCANCODE_ESCAPE))
	{
		SceneMng::Instance()->pushNewScene(pauseSceneRoute, pauseSceneName);
		//SceneMng::Instance()->loadScene(pauseSceneRoute, pauseSceneName);
	}
}
