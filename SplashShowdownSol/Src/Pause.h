#pragma once
#include "Component.h"

class Pause : public Component
{
private:
	std::string pauseSceneRoute;
	std::string pauseSceneName;

public:
	Pause(){}
	~Pause(){}
	
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
	void update();

	static std::string GetName() { return "Pause"; }
};
