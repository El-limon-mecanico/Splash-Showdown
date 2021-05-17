#pragma once
#include "Component.h"
#include "InputManager.h"

class PlayerMovement : public Component
{
private:
	float speed_;
	SDL_Scancode keyForward_;
	SDL_Scancode keyBack_;
	SDL_Scancode keyLeft_;
	SDL_Scancode keyRight_;

public:
	PlayerMovement() {};
	~PlayerMovement() {};

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
	void update();

	static std::string GetName() { return "PlayerMovement"; }
};