#include "Agent.h"
#include "QuackEntity.h"

#ifndef _USE_MATH_DEFINES
	#define _USE_MATH_DEFINES
#endif
#include <math.h>

Agent::Agent()
{
}

Agent::~Agent()
{
}

bool Agent::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;
	correct &= readVariable<bool>(parameterTable, "CombineByWeight", &combineByWeight);
	correct &= readVariable<bool>(parameterTable, "CombineByPriority", &combineByPrio);
	correct &= readVariable<float>(parameterTable, "PriorityThreshold", &priorityThreshold);
	correct &= readVariable<float>(parameterTable, "MaxSpeed", &maxSpeed);
	correct &= readVariable<float>(parameterTable, "MaxAcceleration", &maxAccel);
	correct &= readVariable<float>(parameterTable, "AngularSpeed", &angularSpeed);
	correct &= readVariable<float>(parameterTable, "MaxAngularSpeed", &maxAngularSpeed);
	correct &= readVariable<float>(parameterTable, "MaxAngularAcceleration", &maxAngularAccel);

	if (!correct) return false;

	return true;
}

void Agent::start()
{
	speed_ = Vector3D(0.0f);
	steering_ = Steering();
	rigidbody_ = entity_->getComponent<Rigidbody>();

	orientation = transform->localRotation().y;
}

void Agent::fixedUpdate()
{
	if (rigidbody_ == nullptr) return;
	
	Vector3D displacement = speed_/* * time.fixedDeltaTime*/;	// TODO MULTIPLICAR POR /*time.fixedDeltaTime*/
	orientation += angularSpeed/* * time.fixedDeltaTime*/;

	if (orientation < 0.0f) orientation += 360.0f;
	else if (orientation > 360.0f) orientation -= 360.0f;

	rigidbody_->setVelocity(displacement);
	transform->setGlobalRotation({0.0, orientation, 0.0});
}

void Agent::update()
{
	if (rigidbody_ != nullptr)
		return;

	Vector3D displacement = speed_/* * deltaTime*/;
	orientation += angularSpeed/* * deltaTime*/;
	// constraint orientation to range (0,360)
	if (orientation < 0.0f)
		orientation += 360.0f;
	else if (orientation > 360.0f)
		orientation -= 360.0f;
	transform->setGlobalPosition(transform->position + displacement);
	// Restaura la rotación al punto inicial antes de rotar el objeto nuestro valor
	transform->setGlobalRotation({0.0, orientation, 0.0});
}

void Agent::lateUpdate()
{
	if (combineByPrio) {
		steering_ = getSteeringByPriority();
		groups.clear();
	}

	speed_ = steering_.linear;
	angularSpeed += steering_.angular;

	if (speed_.magnitude > maxSpeed) {
		speed_ = speed_.normalize();
		speed_ *= maxSpeed;
	}

	if (angularSpeed > maxAngularSpeed)
		angularSpeed = maxAngularSpeed;
	else if (angularSpeed < -maxAngularSpeed)
		angularSpeed = -maxAngularSpeed;

	if (steering_.angular == 0.0f)
		angularSpeed = 0.0f;

	if (sqrt(steering_.linear.magnitude()) == 0.0f)
		speed_ = Vector3D(0.0f);

	steering_ = Steering();
}

Steering Agent::getSteering() { return steering_; }

void Agent::setSteering(Steering newSteering) {
	steering_ = newSteering;
}

void Agent::setSteering(Steering newSteering, float weight)
{
	steering_.linear += (newSteering.linear * weight);
	steering_.angular += (newSteering.angular * weight);
}

void Agent::setSteering(Steering newSteering, int priority)
{
	if (groups.find(priority) == groups.end())
		groups.insert({ priority, std::list<Steering>() });
	groups[priority].push_back(newSteering);
}

Steering Agent::getSteeringByPriority()
{
	Steering steering;
	std::list<int> gIdList(groups.size());
	gIdList.sort();
	for (int& gid : gIdList)
	{
		steering = Steering();
		for (Steering& st : groups[gid]) {
			steering.linear += st.linear;
			steering.angular += st.angular;
		}
		if (steering.linear.magnitude > priorityThreshold || abs(steering.angular) > priorityThreshold)
			return steering;
	}

	return steering;
}

Vector3D Agent::FloatToLookAt(float orientation)
{
	Vector3D vector(0.0f);
	vector.x = sin(orientation * 180.0f / M_PI);
	vector.z = cos(orientation * 180.0f / M_PI);
	return vector.normalize();
}