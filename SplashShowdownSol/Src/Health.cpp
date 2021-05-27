#include "Health.h"
#include "QuackEntity.h"
#include "AudioSource.h"
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

void Health::start()
{
	aS_ = entity_->getComponent<AudioSource>();
}

bool Health::receiveDamage(int dmg)
{
	aS_->play();
	health_ -= dmg;

	bool alive = health_ > 0;

	if (!alive)
	{
		//entity_->destroy();
		std::cout << entity_->name() << ": Me he muerto :c\n";

		//cambiar de escena
		//TODO diferenciar entre jugador y IA, pero la ia aun no est�
		std::cout << entity_->tag() << "\n";
		 if(entity_->tag() == "player")
			SceneMng::Instance()->loadScene("scenes/endOfRoundMenuLose.lua", "endOfRoundMenuLose");
		else if(entity_->tag() == "enemy")
			SceneMng::Instance()->loadScene("scenes/endOfRoundMenuWin.lua", "endOfRoundMenuWin");
	}
	return alive;
}
