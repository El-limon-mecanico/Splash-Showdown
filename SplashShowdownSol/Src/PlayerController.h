#pragma once
#include "Component.h"
#include "InputManager.h"
#include "Rigidbody.h"

class PlayerController : public Component
{
private:

	//Variables leidas por .lua
	float movSpeed_ = 15.0;
	float rotSpeed_ = 2.5;
	float movSpeedLimit_ = 10.0;
	float rotSpeedLimit_ = 10.0;
	float turretSpeed_ = 55.0;
	SDL_Scancode turretLeftKey_ = SDL_SCANCODE_Q;
	SDL_Scancode turretRightKey_ = SDL_SCANCODE_E;
	SDL_Scancode shootKey_ = SDL_SCANCODE_R;

	//Otras variables
	Rigidbody* rb_ = nullptr;
	Vector3D vX_ = Vector3D(0, 0, 0);
	Vector3D aX_ = Vector3D(0, 0, 0);

	void move();
	void rotate();
	void rotateTurret();
	void shoot();

public:
	PlayerController() {};
	~PlayerController();

	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
	void start();
	void update();

	static std::string GetName() { return "PlayerMovement"; }
};