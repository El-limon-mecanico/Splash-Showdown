#pragma once
#include "Component.h"

class AudioSource;

class ExitButton : public Component
{
private:
	static void botonPulsado();

	static AudioSource* audioCmp;
public:
	ExitButton(QuackEntity* e = nullptr);
	~ExitButton() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }

	virtual void start() override;

	static std::string GetName() { return "ExitButton"; }
};