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
    Vector3D a = transform->up * -movSpeed_ * InputManager::Instance()->getAxis(Axis::Vertical);
    rb_->addForce(a);
    //std::cout << a << '\n';
}

void PlayerMovement::rotate() {
    Vector3D a = Vector3D(0, -rotSpeed_, 0) * InputManager::Instance()->getAxis(Axis::Horizontal);
    rb_->addTorque(a);
    //std::cout << a << '\n';
}

void PlayerMovement::rotateTurret() {
    if (InputManager::Instance()->getKey(turretLeft_)) {
        tr_->getChild(0)->transform()->Rotate(Vector3D(0, 0, turretSpeed_)
            * QuackEnginePro::Instance()->time()->deltaTime());
    }
    else if (InputManager::Instance()->getKey(turretRight_)) {
        tr_->getChild(0)->transform()->Rotate(Vector3D(0, 0, -turretSpeed_)
            * QuackEnginePro::Instance()->time()->deltaTime());
    }
}

void PlayerMovement::update()
{
	move();
	rotate();
    rotateTurret();
}

//void PlayerMovement::fixedUpdate()
//{
//    rb_->clearForce();
//    move();
//    rotate();
//}