#pragma once
#include "Component.h"

class AudioSource;

class Health : public Component
{
private:
	int health_ = 100;
	AudioSource* aS_ = nullptr;
public:
	Health(QuackEntity* e = nullptr);
	~Health() {
		aS_ = nullptr;
	}

	static std::string GetName() { return "Health"; }

	int getHealth() { return health_; }
	void setHealth(int health) { health_ = health; }

	bool init(luabridge::LuaRef parameterTable = { nullptr }) override;
	void start() override;

	bool receiveDamage(int dmg);
};