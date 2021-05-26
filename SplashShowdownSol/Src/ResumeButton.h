#pragma once
#include "Component.h"

class AudioSource;

class ResumeButton : public Component
{
private:
	static void botonPulsado();

	static AudioSource* audioCmp;
public:
	ResumeButton(QuackEntity* e = nullptr);
	~ResumeButton() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }

	static std::string GetName() { return "ResumeButton"; }
};