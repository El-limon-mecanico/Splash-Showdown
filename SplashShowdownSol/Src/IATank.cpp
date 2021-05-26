#include "IATank.h"
#include "QuackEntity.h"
#include "Rigidbody.h"
#include "SceneMng.h"

#ifndef _USE_MATH_DEFINES
	#define _USE_MATH_DEFINES
#endif
#include <math.h>

#define TARGETPOS target->transform()->position()

bool IATank::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;
	correct &= readVariable<std::string>(parameterTable, "TargetName", &targetName);
	correct &= readVariable<float>(parameterTable, "MaxSpeed", &maxSpeed);
	correct &= readVariable<float>(parameterTable, "MaxAcceleration", &maxAccel);
	correct &= readVariable<float>(parameterTable, "AngularIncrease", &angularIncrease);

	if (!correct) return false;

	return true;
}

void IATank::start()
{
	QuackEntity* targetEnt = SceneMng::Instance()->getCurrentScene()->getObjectWithName(targetName);
	if (targetEnt != nullptr)
		target = targetEnt->transform();
	else std::cout << "ERROR: no se encontró el objeto con nombre " << targetName << " para usar su transform en el componente " << GetName() << "\n";
}

void IATank::fixedUpdate()
{
}

void IATank::update()
{
	if (target)
	{
		if()
	}
}

void IATank::lateUpdate()
{
}

float IATank::LookAtToFloat(Vector3D lookAt)
{
	float dot = lookAt.x * transform->forward.x + lookAt.z * transform->forward.z;		// dot product between[x1, y1] and [x2, y2]
	float det = lookAt.x * transform->forward.z - lookAt.z * transform->forward.x;		// determinant
	return atan2(det, dot);		// atan2(y, x) or atan2(sin, cos)
}

Vector3D IATank::FloatToLookAt(float orientation)
{
	Vector3D vector(0.0f);
	vector.x = sin(orientation * 180.0f / M_PI);
	vector.z = cos(orientation * 180.0f / M_PI);
	return vector.normalize();
}
