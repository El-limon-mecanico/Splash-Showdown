#pragma once
#include "Component.h"

class DealDamage;
class AudioSource;

class Explode : public Component
{
private:
    //Otras variables
    DealDamage* dealDmg_ = nullptr;
    AudioSource* audio_ = nullptr;
    bool destroy = false;

public:
    Explode() {};
    ~Explode();

    static std::string GetName() { return "Explode"; }
    bool init(luabridge::LuaRef parameterTable = { nullptr }) override { return true; };
    void start() override;
    void update();

    void onCollisionEnter(QuackEntity* other, Vector3D point, Vector3D normal) override;
};