#include "BulletMovement.h"
#include "Transform.h"
#include <QuackEnginePro.h>

bool BulletMovement::init(luabridge::LuaRef parameterTable)
{
	speed_ = readVariable<float>(parameterTable, "BulletSpeed");
	LuaRef dirAux = readVariable<LuaRef>(parameterTable, "AuxDir");
	dir_ = Vector3D(dirAux[1], dirAux[2], dirAux[3]);

	return true;
}

void BulletMovement::update()
{
	transform->Translate(dir_.normalize() * speed_
		* QuackEnginePro::Instance()->time()->deltaTime());
}