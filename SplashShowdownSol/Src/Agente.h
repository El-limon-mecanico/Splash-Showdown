#pragma once
#include "Component.h"
#include "Rigidbody.h"
#include <map>

struct Steering {
	Vector3D linear = Vector3D(0.0f); 
	float angular = 0.0f;
};

class Agente : public Component
{
private:
	std::map<int, std::list<Steering>> groups;
	Rigidbody* rigidbody_ = nullptr;

	Steering getSteeringByPriority();

protected:
	bool combineByWeight_ = false;
	bool combineByPrio_ = false;
	float priorityThreshold_ = 0.2f;
	float maxSpeed_ = 10.0f;
	float maxAccel_ = 5.0f;
	float maxRotation_ = 90.0f;
	float maxAngularAccel_ = 5.0f;
	float orientation_ = 0.0f;
	float angularSpeed_ = 0.0f;
	
	Steering steering_;
	Vector3D speed{ 0.0f, 0.0f, 0.0f };

public:
	Agente();
	virtual ~Agente();

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

	virtual void start();
	virtual void fixedUpdate();
	virtual void update();
	virtual void lateUpdate();

	inline float getOrientation() { return orientation_; }
	inline Vector3D getOrientationAsVec3() { return OriToVec(orientation_); }
	virtual void setSteering(Steering newSteering);
	virtual void setSteering(Steering newSteering, float weight);
	virtual void setSteering(Steering newSteering, int priority);

	static Vector3D OriToVec(float orientation);
};