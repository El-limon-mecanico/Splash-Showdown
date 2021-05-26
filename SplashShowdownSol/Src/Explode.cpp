#include "Explode.h"
#include "QuackEntity.h"
#include "Health.h"
#include "DealDamage.h"
#include "AudioSource.h"
#include "Rigidbody.h"
#include "MeshRenderer.h"

Explode::~Explode()
{
	dealDmg_ = nullptr;
}

void Explode::start()
{
	dealDmg_ = entity_->getComponent<DealDamage>();
	audio_ = entity_->getComponent<AudioSource>();
}

void Explode::update()
{
	if (destroy && !audio_->isPlaying()) {
		entity_->destroy();
		std::cout << "Explode: Destroy bullet\n";
	}
}

void Explode::onCollisionEnter(QuackEntity* other, Vector3D point, Vector3D normal)
{
	if (other->tag() == "pato") {
		std::cout << other->name() << ": AAAA RESIBI UN BALASO\n";
		dealDmg_->dealDamage(other->getComponent<Health>());
	}

	entity_->getComponent<Rigidbody>()->setEnable(false);
	entity_->getComponent<MeshRenderer>()->setEnable(false);
	audio_->play();
	destroy = true;
}