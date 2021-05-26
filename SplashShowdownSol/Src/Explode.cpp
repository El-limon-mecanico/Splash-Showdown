#include "Explode.h"
#include "QuackEntity.h"
#include "Health.h"
#include "DealDamage.h"
#include "AudioSource.h"

Explode::~Explode()
{
	dealDmg_ = nullptr;
}

bool Explode::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;

	return correct;
}

void Explode::start()
{
	dealDmg_ = entity_->getComponent<DealDamage>();
}

void Explode::onCollisionEnter(QuackEntity* other, Vector3D point, Vector3D normal)
{
	if (other->tag() == "pato") {
		std::cout << other->name() << ": AAAA RESIBI UN BALASO\n";
		dealDmg_->dealDamage(other->getComponent<Health>());
	}

	std::cout << entity_->name() << ": Colision\n";
	entity_->getComponent<AudioSource>()->play();
	entity_->destroy();
}