#pragma once
#include "Component.h"

class AudioSource;

class PlayButton : public Component
{
private:
	static void botonPulsado();

	static AudioSource* audioCmp;

	void play();
public:
	PlayButton(QuackEntity* e = nullptr);
	~PlayButton() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; };
	
	virtual void start() override;

	static std::string GetName() { return "PlayButton"; }
};