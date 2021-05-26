#pragma once
#include "Component.h"
#include "Rigidbody.h"
#include <map>

struct Steering {
	Vector3D linear = Vector3D(0.0f); 
	float angular = 0.0f;
};

class Agent : public Component
{
private:
	std::map<int, std::list<Steering>> groups;
	Rigidbody* rigidbody_ = nullptr;

	Steering getSteeringByPriority();

protected:
	Steering steering_;
	Vector3D speed_{ 0.0f, 0.0f, 0.0f };

public:
	bool combineByWeight = false;
	bool combineByPrio = false;
	float priorityThreshold = 0.2f;
	float maxSpeed = 10.0f;
	float maxAccel = 5.0f;
	float maxAngularSpeed = 90.0f;
	float maxAngularAccel = 5.0f;
	float orientation = 0.0f;
	float angularSpeed = 0.0f;
	
	Agent();
	virtual ~Agent();

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

	static std::string GetName() { return "Agent"; }

	virtual void start();
	virtual void fixedUpdate();
	virtual void update();
	virtual void lateUpdate();

	inline float getOrientation() { return orientation; }
	inline Vector3D getLookAt() { return FloatToLookAt(orientation); }
	virtual Steering getSteering();
	virtual void setSteering(Steering newSteering);
	virtual void setSteering(Steering newSteering, float weight);
	virtual void setSteering(Steering newSteering, int priority);

	static Vector3D FloatToLookAt(float orientation);
};