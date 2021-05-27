#include "BulletMovement.h"
#include "QuackEntity.h"
#include <QuackEnginePro.h>

BulletMovement::~BulletMovement() {
	rb_ = nullptr;
}

bool BulletMovement::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;
	correct &= readVariable<float>(parameterTable, "BulletSpeed", &speed_);

	return correct;
}

void BulletMovement::start()
{
	rb_ = entity_->getComponent<Rigidbody>();
	lastTime_ = QuackEnginePro::Instance()->time()->Time();
}

void BulletMovement::update()
{
	rb_->setVelocity(dir_.normalize() * speed_);

	//Eliminar de la escena pasado un tiempo
	float currentTime_ = QuackEnginePro::Instance()->time()->Time();
	if (lastTime_ + 15.0 < currentTime_) {
		entity_->destroy();
	}
}