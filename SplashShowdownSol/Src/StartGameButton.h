#pragma once
#include "Component.h"
class StartGameButton : public Component
{
private:
	static void botonPulsado();
public:
	StartGameButton(QuackEntity* e = nullptr);
	~StartGameButton() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }

	static std::string GetName() { return "StartGameButton"; }
};