#pragma once
#include "DealDamage.h"
#include "Health.h"
#include "QuackEntity.h"

DealDamage::DealDamage()
{
}

DealDamage::~DealDamage()
{
}

bool DealDamage::init(luabridge::LuaRef parameterTable)
{
	bool correct = true;

	correct &= readVariable<int>(parameterTable, "Damage", &damage_);

	return correct;
}

bool DealDamage::dealDamage(Health* healthCmp)
{
	return healthCmp->receiveDamage(damage_);	 
}
