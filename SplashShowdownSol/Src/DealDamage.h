#pragma once
#include "Component.h"

class Health;

class DealDamage :
    public Component
{
private:
    //Variables que leemos de lua
    int damage_ = 20;

public:
    DealDamage();
    ~DealDamage();

    static std::string GetName() { return "DealDamage"; }
    bool init(luabridge::LuaRef parameterTable = { nullptr }) override;

    bool dealDamage(Health* healthCmp);

};