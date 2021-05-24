#include "BulletMovement.h"
#include "QuackEntity.h"
#include <QuackEnginePro.h>

BulletMovement::~BulletMovement() {
	delete rb_;
	rb_ = nullptr;
}

bool BulletMovement::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;
	correct &= readVariable<float>(parameterTable, "BulletSpeed", &speed_);

	if (!correct) return false;

	return true;
}

void BulletMovement::start()
{
	rb_ = entity_->getComponent<Rigidbody>();
}

void BulletMovement::update()
{
	transform->Translate(dir_.normalize() * speed_
		* QuackEnginePro::Instance()->time()->deltaTime());

	//rb_-> //gestionar colision
}

void BulletMovement::onCollisionEnter(QuackEntity* other, Vector3D point)
{

}