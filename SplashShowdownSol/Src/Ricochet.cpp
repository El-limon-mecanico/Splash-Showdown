#include "Ricochet.h"
#include "BulletMovement.h"
#include "QuackEntity.h"
#include "Health.h"

Ricochet::Ricochet()
{
}

Ricochet::~Ricochet()
{
	bM_ = nullptr;
}

bool Ricochet::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;

	correct &= readVariable<int>(parameterTable, "BouncesMax", &bouncesMax_);

	bounces_ = bouncesMax_;

	return correct;
}

void Ricochet::start()
{
	bM_ = entity_->getComponent<BulletMovement>();
}

void Ricochet::onCollisionEnter(QuackEntity* other, Vector3D point, Vector3D normal)
{
	bounces_--;

	if (other->tag() == "pato") {
		//other->getComponent<Health>()->setHealth(1);    //TODO hacer que pierda vida bien
		std::cout << entity_->name() <<": AAAA RESIBI UN BALASO \n"; 
		entity_->destroy();
		return;
	}

	if (bounces_ < 0) {
		entity_->destroy();
	}
	else {
		Vector3D dir = bM_->getDir();

		//formula de la reflexion de la luz mirala que bonita me tenia que haber metido a optica
		bM_->setDir(((dir - Vector3D(2, 2, 2) * (dir * normal.normalize()) * normal.normalize()) * Vector3D(1, 0, 1)).normalize());
	}
}