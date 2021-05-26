#pragma once
#include "Component.h"

class AudioSource;

class ChangeWeaponButton : public Component
{
private:
	static void botonPulsado();

	static bool exploviseWeapon;

	static AudioSource* audioCmp;

	static void setImages();
public:
	ChangeWeaponButton(QuackEntity* e = nullptr);
	~ChangeWeaponButton() {}

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) { return true; }

	virtual void start();

	static std::string GetName() { return "ChangeWeaponButton"; }

	bool getWeapon() { return exploviseWeapon; }
};