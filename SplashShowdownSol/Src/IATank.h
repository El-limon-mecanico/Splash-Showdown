#pragma once
#include "Component.h"

class QuackEntity;
class Rigidbody;

class IATank : public Component
{
private:
	Rigidbody* rigidbody_ = nullptr;
	std::string targetName = "";
	float maxSpeed = 10.0f;
	float maxAccel = 5.0f;
	float orientation = 0.0f;
	float angularIncrease = 1.0f;
	Transform* target = nullptr;

	float precision = 0.1f;

public:
	IATank() {};
	~IATank() {};
	
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

	static std::string GetName() { return "IATank"; }

	virtual void start();
	virtual void fixedUpdate();
	virtual void update();
	virtual void lateUpdate();

	inline Vector3D getLookAt() { return FloatToLookAt(orientation); }
	float LookAtToFloat(Vector3D lookAt);
	static Vector3D FloatToLookAt(float orientation);
};