#pragma once
#include "Component.h"
class PlayButton : public Component
{
private:
	static void botonPulsado();
public:
	PlayButton(QuackEntity* e = nullptr);
	~PlayButton() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }

	static std::string GetName() { return "PlayButton"; }
};