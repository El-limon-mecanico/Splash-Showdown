#pragma once
#include "Component.h"
class BackButton : public Component
{
private:
	static void botonPulsado();
public:
	BackButton(QuackEntity* e = nullptr);
	~BackButton() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }

	static std::string GetName() { return "BackButton"; }
};