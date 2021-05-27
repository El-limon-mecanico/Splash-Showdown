#include "IATank.h"
#include "QuackEntity.h"
#include "Rigidbody.h"
#include "SceneMng.h"
#include "Shoot.h"
#include <QuackEnginePro.h>

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

#define TARGETPOS target->transform()->position()

IATank::IATank()
{
	/* initialize random seed: */
	srand(time(NULL));
}

bool IATank::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;
	correct &= readVariable<std::string>(parameterTable, "TargetName", &targetName);
	correct &= readVariable<float>(parameterTable, "MovSpeed", &movSpeed_);
	correct &= readVariable<float>(parameterTable, "RotSpeed", &rotSpeed_);
	correct &= readVariable<float>(parameterTable, "MovSpeedLimit", &movSpeedLimit_);
	correct &= readVariable<float>(parameterTable, "RotSpeedLimit", &rotSpeedLimit_);
	correct &= readVariable<float>(parameterTable, "TurretSpeed", &turretSpeed_);

	if (!correct) return false;

	return true;
}

void IATank::start()
{
	rigidbody_ = entity_->getComponent<Rigidbody>();
	if (rigidbody_ == nullptr) std::cout << "ERROR: no hay rigidbody en la entidad de la IA\n";
	shoot = entity_->getComponent<Shoot>();
	if (shoot == nullptr) std::cout << "ERROR: no hay Shoot en la entidad de la IA\n";

	torreta = transform->getChild(0);

	QuackEntity* targetEnt = SceneMng::Instance()->getCurrentScene()->getObjectWithName(targetName);
	if (targetEnt != nullptr)
		target = targetEnt->transform();
	else std::cout << "ERROR: no se encontr� el objeto con nombre " << targetName << " para usar su transform en el componente " << GetName() << "\n";

	dirMovement = Vector3D(1, 0, 1);
}

void IATank::rotateTurret(float diff)
{
	if (abs(diff) > precision)
	{
		float dir = (diff < 0) ? -1 : 1;
		torreta->transform()->Rotate(Vector3D(.0f, .0f, turretSpeed_ * dir) * QuackEnginePro::Instance()->time()->deltaTime());
	}
}

void IATank::rotate(float diff)
{
	if (abs(diff) <= precision) return;

	pickNewRandom = true;

	float dir = (diff < 0) ? -1 : 1;

	//Torsion a 0
	Vector3D aux = rigidbody_->angularVelocity() * -1;
	aux.x = aux.z = 0.0f;
	rigidbody_->addTorque(aux);

	if (abs(aux.y) < rotSpeedLimit_) {
		rigidbody_->addTorque({ 0, 0, -rotSpeed_ * dir * diff });
	}
	if (visible) {
		Vector3D dir = torreta->transform()->up * -1;
		Vector3D pos = torreta->transform()->position();
		shoot->shootBullet(dir.normalize(), pos + dir.normalize() + Vector3D(.0, -.5, .0));
	}
}

void IATank::move(Vector3D dir)
{
	Vector3D vel = rigidbody_->velocity();
	vel.y = 0.0f;
	rigidbody_->addForce(dir.normalize() * (movSpeedLimit_ - vel.magnitude()));
}

void IATank::fixedUpdate()
{
	rigidbody_->setVelocity(dirMovement);
	rigidbody_->setAngularVelocity(rigidbody_->angularVelocity() * 0.99);
}

void IATank::update()
{
	torreta->transform()->lookAt(target->position(), Y_AXIS);
	std::cout << torreta->transform()->rotation() <<"\n";
}

void IATank::onCollisionEnter(QuackEntity* other, Vector3D point, Vector3D normal) {

	dirMovement = ((dirMovement - Vector3D(2, 2, 2) * (dirMovement * normal.normalize()) * normal.normalize()) * Vector3D(1, 0, 1)).normalize() * 1.5;

	Vector3D v = Vector3D((rand() % 3 - 1), 0, (rand() % 3 - 1));

	dirMovement += v;
}

float IATank::lookAtToFloat(Vector3D lookAt, Vector3D from)
{
	float dot = lookAt.x * from.x + lookAt.z * from.z;		// dot product between[x1, y1] and [x2, y2]
	float det = lookAt.x * from.z - lookAt.z * from.x;		// determinant
	return atan2(det, dot);		// atan2(y, x) or atan2(sin, cos)
}

Vector3D IATank::FloatToLookAt(float orientation)
{
	Vector3D vector(0.0f);
	vector.x = sin(orientation * 180.0f / M_PI);
	vector.z = cos(orientation * 180.0f / M_PI);
	return vector.normalize();
}
