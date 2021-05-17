#include "PlayerMovement.h"
#include "QuackEntity.h"
#include <QuackEnginePro.h>

PlayerMovement::~PlayerMovement() {
    delete rb_;
    delete tr_;
}

bool PlayerMovement::init(luabridge::LuaRef parameterTable) //TODO: Manejo de errores
{
    speed_ = readVariable<float>(parameterTable, "Speed");
    rotKeyLeft_ = (SDL_Scancode)readVariable<int>(parameterTable, "RotKeyLeft");
    rotKeyRight_ = (SDL_Scancode)readVariable<int>(parameterTable, "RotKeyRight");

    rb_ = entity_->getComponent<Rigidbody>();
    tr_ = entity_->transform();

    return true;
}

void PlayerMovement::move() {
    //Vector3D vel = Vector3D(0, 0, 0);
    //rb_->setVelocity(vel);
    rb_->clearForce();

    rb_->addForce(Vector3D(speed_, 0, 0) * InputManager::Instance()->getAxis(Axis::Horizontal));
    rb_->addForce(Vector3D(0, 0, -speed_) * InputManager::Instance()->getAxis(Axis::Vertical));

    //if (InputManager::Instance()->isKeyDown(keyForward_)) { //Adelante
    //    //rb_->setVelocity(vel + Vector3D(0, 0, -speed_));
    //    rb_->addForce(Vector3D(0, 0, -speed_));
    //}
}

void PlayerMovement::rotate() {
    if (InputManager::Instance()->isKeyDown(rotKeyLeft_)) { //Izquierda
        
    }

    if (InputManager::Instance()->isKeyDown(rotKeyRight_)) { //Derecha

    }
}

void PlayerMovement::update()
{
    move();
}

void PlayerMovement::fixedUpdate()
{
    //move();
}