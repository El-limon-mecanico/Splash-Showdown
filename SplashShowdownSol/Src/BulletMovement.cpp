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

	if (!correct) return false;

	return true;
}

void BulletMovement::start()
{
	rb_ = entity_->getComponent<Rigidbody>();
	lastTime_ = QuackEnginePro::Instance()->time()->Time();
}

void BulletMovement::update()
{
	rb_->setVelocity(dir_.normalize() * speed_);
	//transform->Translate(dir_.normalize() * speed_
	//	* QuackEnginePro::Instance()->time()->deltaTime());

	//Eliminar de la escena pasado un tiempo
	float currentTime_ = QuackEnginePro::Instance()->time()->Time();
	if (lastTime_ + 15.0 < currentTime_) {
		entity_->destroy();
	}
}

//void BulletMovement::onCollisionEnter(QuackEntity* other, Vector3D point, Vector3D normal)
//{
//	std::cout << "\n----Destroy " << entity_->name();
//	entity_->destroy();
//}