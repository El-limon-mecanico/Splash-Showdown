#pragma once
#include "Component.h"

class BulletMovement;
class DealDamage;

class Ricochet :
    public Component
{
private:
    //Variables que leemos de lua
    int bouncesMax_ = 2;

    //otras variables
    int bounces_;
    BulletMovement* bM_ = nullptr;
    DealDamage* dealDmg_ = nullptr;


public:
    Ricochet();
    ~Ricochet();

    static std::string GetName() { return "Ricochet"; }
    bool init(luabridge::LuaRef parameterTable = { nullptr }) override;
    void start() override;

    void onCollisionEnter(QuackEntity* other, Vector3D point, Vector3D normal) override;

};

