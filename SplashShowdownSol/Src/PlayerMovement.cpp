#include "PlayerMovement.h"
#include "QuackEntity.h"
#include <QuackEnginePro.h>

PlayerMovement::~PlayerMovement() {
    delete rb_;
    delete tr_;
}

bool PlayerMovement::init(luabridge::LuaRef parameterTable) //TODO: Manejo de errores
{
    movSpeed_ = readVariable<float>(parameterTable, "MovSpeed");
    rotSpeed_ = readVariable<float>(parameterTable, "RotSpeed");
    turretSpeed_ = readVariable<float>(parameterTable, "TurretSpeed");
    turretLeft_ = (SDL_Scancode)readVariable<int>(parameterTable, "TurretLeftKey");
    turretRight_ = (SDL_Scancode)readVariable<int>(parameterTable, "TurretRightKey");

    rb_ = entity_->getComponent<Rigidbody>();
    tr_ = entity_->transform();

    return true;
}

void PlayerMovement::move() {
    rb_->addForce(transform->forward * movSpeed_ * InputManager::Instance()->getAxis(Axis::Vertical));
}

void PlayerMovement::rotate() {
    rb_->addTorque(Vector3D(0, -rotSpeed_, 0) * InputManager::Instance()->getAxis(Axis::Horizontal));
}

void PlayerMovement::rotateTurret() {
    if (InputManager::Instance()->isKeyDown(turretLeft_)) {
        tr_->getChildByName("torreta")->transform()->Rotate(Vector3D(0, turretSpeed_, 0)
            * QuackEnginePro::Instance()->time()->deltaTime());
    }
    else if (InputManager::Instance()->isKeyDown(turretRight_)) {
        tr_->getChildByName("torreta")->transform()->Rotate(Vector3D(0, -turretSpeed_, 0)
            * QuackEnginePro::Instance()->time()->deltaTime());
    }
}

void PlayerMovement::update()
{
    rb_->clearForce();
    move(); //TODO: Si se puede, pasar a FixedUpdate
    rotate(); //TODO: Si se puede, pasar a FixedUpdate
    rotateTurret();
}