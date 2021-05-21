#pragma once
#include "Component.h"
class ExitButton : public Component
{
private:
	static void botonPulsado();
public:
	ExitButton(QuackEntity* e = nullptr);
	~ExitButton() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }

	static std::string GetName() { return "ExitButton"; }
};