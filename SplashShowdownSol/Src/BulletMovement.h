#pragma once
#include "Component.h"
#include "Rigidbody.h"

class BulletMovement : public Component
{
private:
	//Variables leidas por .lua
	float speed_ = 3.0;

	//Otras variables
	Rigidbody* rb_ = nullptr;
	Vector3D dir_;

public:
	BulletMovement() {};
	~BulletMovement();

	static std::string GetName() { return "BulletMovement"; }
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
	void start();
	void update();

	void onCollisionEnter(QuackEntity* other, Vector3D point);

	Vector3D getDir() { return dir_; }
	void setDir(Vector3D d) { dir_ = d; }
	float getSpeed() { return speed_; }
	void setSpeed(float s) { speed_ = s; }
};