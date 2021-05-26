#pragma once
#include "Component.h"

class AudioSource;

class Shoot : public Component
{
private:
	//Variables leidas por .lua
	std::string bulletPrefabFile_ = "";

	//Otras variables
	int cont_ = 0;
	AudioSource* aS_;

public:
	Shoot() {};
	~Shoot() {};

	static std::string GetName() { return "Shoot"; }
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
	void start() override;

	void shootBullet(Vector3D dir, Vector3D pos);
};