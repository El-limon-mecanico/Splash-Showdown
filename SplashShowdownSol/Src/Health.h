#pragma once
#include "Component.h"

class Health : public Component
{
private:
	int health_ = 100;

public:
	Health(QuackEntity* e = nullptr);
	~Health() {}

	static std::string GetName() { return "Health"; }

	int getHealth() { return health_; }
	void setHealth(int health) { health_ = health; }

	bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

	bool receiveDamage(int dmg);
};