#pragma once
#include "Component.h"
#include "InputManager.h"
#include "Rigidbody.h"


class PlayerMovement : public Component
{
private:
	//Variables leidas por .lua
	float movSpeed_ = 15.0;
	float rotSpeed_ = 2.5;
	float movSpeedLimit_ = 10.0;
	float rotSpeedLimit_ = 10.0;
	float turretSpeed_ = 55.0;
	Rigidbody* rb_ = nullptr;
	Transform* tr_ = nullptr;
	SDL_Scancode turretLeft_ = SDL_SCANCODE_Q;
	SDL_Scancode turretRight_ = SDL_SCANCODE_E;

	//Otras variables
	Vector3D vX_ = Vector3D(0, 0, 0);
	Vector3D aX_ = Vector3D(0, 0, 0);

	void move();
	void rotate();
	void rotateTurret();

public:
	PlayerMovement() {};
	~PlayerMovement();

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
	void start();
	void update();
	//void fixedUpdate();

	static std::string GetName() { return "PlayerMovement"; }
};