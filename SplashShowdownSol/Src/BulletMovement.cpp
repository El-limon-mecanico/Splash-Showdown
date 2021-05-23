#include "BulletMovement.h"
#include "Transform.h"
#include <QuackEnginePro.h>

bool BulletMovement::init(luabridge::LuaRef parameterTable) //TODO borrar lo comentado cuando ya no haga falta
{
	//LuaRef dirAux = NULL;
	bool correct = true;

	correct &= readVariable<float>(parameterTable, "BulletSpeed", &speed_);
	//correct &= readVariable<LuaRef>(parameterTable, "AuxDir", &dirAux);
	//dir_ = Vector3D(dirAux[1], dirAux[2], dirAux[3]);

	if (!correct) return false;

	return true;
}

void BulletMovement::update()
{
	transform->Translate(dir_.normalize() * speed_
		* QuackEnginePro::Instance()->time()->deltaTime());
}