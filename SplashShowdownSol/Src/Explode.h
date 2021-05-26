#pragma once
#include "Component.h"

class DealDamage;

class Explode : public Component
{
private:
    //Otras variables
    DealDamage* dealDmg_ = nullptr;

public:
    Explode() {};
    ~Explode();

    static std::string GetName() { return "Explode"; }
    bool init(luabridge::LuaRef parameterTable = { nullptr }) override { return true; };
    void start() override;

    void onCollisionEnter(QuackEntity* other, Vector3D point, Vector3D normal) override;
};