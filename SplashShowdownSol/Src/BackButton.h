#pragma once
#include "Component.h"

class AudioSource;

class BackButton : public Component
{
private:
	static void botonPulsado();

	static AudioSource* audioCmp;
public:
	BackButton(QuackEntity* e = nullptr);
	~BackButton() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }

	virtual void start() override;

	static std::string GetName() { return "BackButton"; }
};