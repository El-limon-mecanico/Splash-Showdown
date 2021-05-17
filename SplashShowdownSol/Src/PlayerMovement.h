#pragma once
#include "Component.h"
#include "InputManager.h"
#include "Rigidbody.h"


class PlayerMovement : public Component
{
private:
	float speed_;
	SDL_Scancode rotKeyLeft_;
	SDL_Scancode rotKeyRight_;

	Rigidbody* rb_;
	Transform* tr_;

	Vector3D vX_ = Vector3D(0, 0, 0);
	Vector3D aX_ = Vector3D(0, 0, 0);

	void move();
	void rotate();

public:
	PlayerMovement() {};
	~PlayerMovement();

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
	void update();
	void fixedUpdate();

	static std::string GetName() { return "PlayerMovement"; }
};