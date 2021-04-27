#pragma once
#include "Component.h"
class BulletMovement : public Component
{
private:
	//Vector3 dir_;
	float speed_;

public:
	BulletMovement() {};
	~BulletMovement() {};

	void update();
	//virtual bool init(luabridge::LuaRef parameterTable = { nullptr });

	//Vector3 getDir() {return dir_;}
	//void setDir(Vector3 d) {dir_ = d; }
	float getSpeed() {return speed_;}
	void setSpeed(float s) { speed_ = s; }

};

