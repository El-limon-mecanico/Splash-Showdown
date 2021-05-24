#pragma once
#include "Component.h"

//BulletMovement gestiona la colisión y llama a destroy()

//Crea una bala<tipo> con sus componentes: Transform, MeshRenderer, Rigidbody, BulletMovement, <tipo>
//Hay que settear despues de crearla:
	//Su posicion: La cabeza del pato
	//Su direccion: A donde mira la cabeza del pato
	//Su velocidad: Por Lua coge la velocidad de BulletMovement
	//Hacerla hija de algo?? (un bullet manager por ej.)

class Shoot : public Component
{
private:
	//Variables leidas por .lua
	std::string bulletPrefabFile_ = "";

	//Otras variables
	int cont = 0;
	Transform* headTr_;

public:
	Shoot() {};
	~Shoot() {};

	static std::string GetName() { return "Shoot"; }
	virtual bool init(luabridge::LuaRef parameterTable = { nullptr });
	void start();

	void shootBullet();
};