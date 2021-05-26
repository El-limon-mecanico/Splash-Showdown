#include "Health.h"
#include "QuackEntity.h"
#include "SceneMng.h"

Health::Health(QuackEntity* e) : Component(e)
{
}

bool Health::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;

	correct &= readVariable<int>(parameterTable, "HitPoints", &health_);

	return correct;
}

bool Health::receiveDamage(int dmg)
{
	health_ -= dmg;

	bool alive = health_ > 0;

	if (!alive)
	{
		//entity_->destroy();
		std::cout << entity_->name() << ": Me he muerto :c\n";

		//cambiar de escena
		SceneMng::Instance()->loadScene("scenes/endOfRoundMenu.lua", "endOfRoundMenu");
	}
	return alive;
}
