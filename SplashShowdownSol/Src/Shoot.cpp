#include "Shoot.h"
#include "SceneMng.h"
#include "BulletMovement.h"

bool Shoot::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;
	correct &= readVariable<std::string>(parameterTable, "BulletPrefabRoute", &bulletPrefabFile_);

	if (!correct) return false;

	return true;
}

void Shoot::start()
{
	headTr_ = transform->getChild(0)->transform();
}

void Shoot::shootBullet()
{
	cont++;
	std::string name = "Bullet" + entity_->name() + std::to_string(cont);

	QuackEntity* bullet = SceneMng::Instance()->getCurrentScene()->createEntityByPrefab(bulletPrefabFile_, "Bullet", name);

	bullet->getComponent<BulletMovement>()->setDir(headTr_->up);
	bullet->getComponent<Transform>()->setGlobalPosition(headTr_->position());
}