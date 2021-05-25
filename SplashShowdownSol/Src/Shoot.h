#pragma once
#include "Component.h"

class Shoot : public Component
{
private:
	//Variables leidas por .lua
	std::string bulletPrefabFile_ = "";

	//Otras variables
	int cont_ = 0;

public:
	Shoot() {};
	~Shoot() {};

	static std::string GetName() { return "Shoot"; }
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });

	void shootBullet(Vector3D dir, Vector3D pos);
};