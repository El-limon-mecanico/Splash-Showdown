#pragma once
#include "Component.h"

class PlayerMovement : public Component
{
private:
	float speed_;

public:
	PlayerMovement() {};
	~PlayerMovement() {};

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
	void update();

	static std::string GetName() { return "PlayerMovement"; }
};