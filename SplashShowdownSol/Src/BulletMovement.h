#pragma once
#include "Component.h"

class BulletMovement : public Component
{
private:
	Vector3D dir_;
	float speed_;

public:
	BulletMovement() {};
	~BulletMovement() {};

	static std::string GetName() { return "BulletMovement"; }
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
	void update();

	Vector3D getDir() {return dir_;}
	void setDir(Vector3D d) {dir_ = d; }
	float getSpeed() {return speed_;}
	void setSpeed(float s) { speed_ = s; }
};