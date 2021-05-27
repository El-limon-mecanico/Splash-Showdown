#pragma once
#include "Component.h"

class QuackEntity;
class Rigidbody;
class Shoot;

class IATank : public Component
{
private:
	Vector3D randomDir = { 0.0f };
	bool pickNewRandom = true;

	Rigidbody* rigidbody_ = nullptr;
	std::string targetName = "";

	//Variables leidas por .lua
	float movSpeed_ = 15.0;
	float rotSpeed_ = 2.5;
	float movSpeedLimit_ = 10.0;
	float rotSpeedLimit_ = 10.0;
	float turretSpeed_ = 55.0;

	float precision = 0.8f;

	Transform* target = nullptr;
	Shoot* shoot = nullptr;
	QuackEntity* torreta = nullptr;

	void rotateTurret(float diff);
	void rotate(float diff);
	void move(Vector3D dir);

public:
	IATank();
	~IATank() {};
	
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

	static std::string GetName() { return "IATank"; }

	virtual void start();
	virtual void fixedUpdate();
	virtual void update();
	virtual void onCollisionEnter(QuackEntity* other, Vector3D point, Vector3D normal) override;

	static float lookAtToFloat(Vector3D lookAt, Vector3D from);
	static Vector3D FloatToLookAt(float orientation);
};