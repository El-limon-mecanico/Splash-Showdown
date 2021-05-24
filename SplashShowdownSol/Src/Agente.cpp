#include "Agente.h"
#include "QuackEntity.h"

#ifndef _USE_MATH_DEFINES
	#define _USE_MATH_DEFINES
#endif
#include <math.h>


Agente::Agente()
{
}

Agente::~Agente()
{
}

bool Agente::init(luabridge::LuaRef parameterTable)
{
	return false;
}

void Agente::start()
{
	speed = Vector3D(0.0f);
	steering_ = Steering();
	rigidbody_ = entity_->getComponent<Rigidbody>();

	orientation_ = transform->localRotation().y;
}

void Agente::fixedUpdate()
{
	if (rigidbody_ == nullptr) return;
	
	Vector3D displacement = speed * /*time.fixedDeltaTime*/;	// TODO MULTIPLICAR POR /*time.fixedDeltaTime*/
	orientation_ += angularSpeed_ * /*time.fixedDeltaTime*/;

	if (orientation_ < 0.0f) orientation_ += 360.0f;
	else if (orientation_ > 360.0f) orientation_ -= 360.0f;

	rigidbody_->setVelocity(displacement);
	transform->rotation = orientation_;
}

void Agente::update()
{
}

void Agente::lateUpdate()
{
}

void Agente::setSteering(Steering newSteering) {
	steering_ = newSteering;
}

void Agente::setSteering(Steering newSteering, float weight)
{
	steering_.linear += (newSteering.linear * weight);
	steering_.angular += (newSteering.angular * weight);
}

void Agente::setSteering(Steering newSteering, int priority)
{
	if (groups.find(priority) == groups.end())
		groups.insert({ priority, std::list<Steering>() });
	groups[priority].push_back(newSteering);
}

Steering Agente::getSteeringByPriority()
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
		if (steering.linear.magnitude > priorityThreshold_ || abs(steering.angular) > priorityThreshold_)
			return steering;
	}

	return steering;
}

Vector3D Agente::OriToVec(float orientation)
{
	Vector3D vector(0.0f);
	vector.x = sin(orientation * 180.0f / M_PI);
	vector.z = cos(orientation * 180.0f / M_PI);
	return vector.normalize();
}