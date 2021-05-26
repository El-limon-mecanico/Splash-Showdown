#pragma once
#include "Component.h"

class AudioSource;

class StartGameButton : public Component
{
private:
	static void botonPulsado();

	static AudioSource* audioCmp;
public:
	StartGameButton(QuackEntity* e = nullptr);
	~StartGameButton() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }

	virtual void start() override;

	static std::string GetName() { return "StartGameButton"; }
};