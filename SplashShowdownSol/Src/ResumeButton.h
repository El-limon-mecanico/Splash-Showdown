#pragma once
#include "Component.h"

class ResumeButton : public Component
{
private:
	static void botonPulsado();
public:
	ResumeButton(QuackEntity* e = nullptr);
	~ResumeButton() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }

	static std::string GetName() { return "ResumeButton"; }
};