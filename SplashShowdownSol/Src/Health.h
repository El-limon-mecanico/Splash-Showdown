#pragma once
#include "Component.h"
class Health : public Component
{
private:
	int health_;

public:
	Health(QuackEntity* e = nullptr);
	~Health() {}

	static std::string GetName() { return "Health"; }

	int getHealth() { return health_; }
	void setHealth(int health) { health_ = health; }


	//virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
};