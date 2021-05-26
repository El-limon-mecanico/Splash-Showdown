#include "Shoot.h"
#include "SceneMng.h"
#include "BulletMovement.h"

bool Shoot::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;
	//TODO el prefab debería elegirse por código a la hora de elegir arma y no por .lua porque habrá dos prefabs (Ricochet y Explosion)
	correct &= readVariable<std::string>(parameterTable, "BulletPrefabRoute", &bulletPrefabFile_);

	return correct;
}

void Shoot::shootBullet(Vector3D dir, Vector3D pos)
{
	cont_++;
	std::string aux = std::to_string(cont_);
	std::string aux2 = entity_->name();
	std::string name = "bullet_" + aux2 + "_" + aux;
	std::cout << name;

	QuackEntity* bullet = SceneMng::Instance()->getCurrentScene()->createEntityByPrefab(bulletPrefabFile_, "Bullet", name);

	if (bullet != nullptr) {
		bullet->getComponent<BulletMovement>()->setDir(dir);
		bullet->transform()->setGlobalPosition(pos);
	}
}