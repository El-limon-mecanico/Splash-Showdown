#pragma once
#include "Component.h"
#include "InputManager.h"
#include "Rigidbody.h"


class PlayerMovement : public Component
{
private:
	float movSpeed_;
	float rotSpeed_;
	float movSpeedLimit_;
	float rotSpeedLimit_;
	float turretSpeed_;
	Rigidbody* rb_;
	Transform* tr_;
	Vector3D vX_ = Vector3D(0, 0, 0);
	Vector3D aX_ = Vector3D(0, 0, 0);

	SDL_Scancode turretLeft_;
	SDL_Scancode turretRight_;

	void move();
	void rotate();
	void rotateTurret();

public:
	PlayerMovement() {};
	~PlayerMovement();

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
	void update();
	//void fixedUpdate();

	static std::string GetName() { return "PlayerMovement"; }
};