#include "IATank.h"
#include "QuackEntity.h"
#include "Rigidbody.h"
#include "SceneMng.h"
#include "Shoot.h"
#include <QuackEnginePro.h>
#include "QuackRaycast.h"

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
	correct &= readVariable<int>(parameterTable, "Frequency", &timebetween_);

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
	else std::cout << "ERROR: no se encontró el objeto con nombre " << targetName << " para usar su transform en el componente " << GetName() << "\n";

	dirMovement = Vector3D(1, 0, 1);
}

void IATank::fixedUpdate()
{
	rigidbody_->setVelocity(dirMovement);
	rigidbody_->setAngularVelocity(rigidbody_->angularVelocity() * 0.99);
}

void IATank::update()
{
	if(++currtime >= timebetween_) {
		QuackRaycast raycast(transform->position() + transform->forward * transform->scale().z, target->position());
		float len = (target->position() - transform->position()).magnitude() + 1.0f;

		if (raycast.getLength() >= len) {
			Vector3D dir = torreta->transform()->up * -1;
			Vector3D pos = torreta->transform()->position();
			pos.y += 0.2;
			shoot->shootBullet(dir.normalize(), pos + dir.normalize() * 1.5);
		}
		currtime = 0;
	}

	torreta->transform()->lookAt(target, NEGATIVE_Y_AXIS);
}

void IATank::onCollisionEnter(QuackEntity* other, Vector3D point, Vector3D normal) {

	dirMovement = ((dirMovement - Vector3D(2, 2, 2) * (dirMovement * normal.normalize()) * normal.normalize()) * Vector3D(1, 0, 1)).normalize() * 1.5;

	Vector3D v = Vector3D((rand() % 3 - 1), 0, (rand() % 3 - 1));

	dirMovement += v;
}