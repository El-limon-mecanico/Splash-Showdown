#include "BulletMovement.h"
#include "Transform.h"
#include <QuackEnginePro.h>

bool BulletMovement::init(luabridge::LuaRef parameterTable)
{
	readVariable<float>(parameterTable, "BulletSpeed", &speed_);
	LuaRef dirAux = NULL;
	readVariable<LuaRef>(parameterTable, "AuxDir", &dirAux);
	dir_ = Vector3D(dirAux[1], dirAux[2], dirAux[3]);

	return true;
}

void BulletMovement::update()
{
	transform->Translate(dir_.normalize() * speed_
		* QuackEnginePro::Instance()->time()->deltaTime());
}