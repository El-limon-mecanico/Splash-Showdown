#include "PlayerMovement.h"
#include "QuackEntity.h"
#include <QuackEnginePro.h>

PlayerMovement::~PlayerMovement() {
    delete rb_;
    rb_ = nullptr;
}

bool PlayerMovement::init(luabridge::LuaRef parameterTable)
{
    bool correct = true;

    correct &= readVariable<float>(parameterTable, "MovSpeed", &movSpeed_);
    correct &= readVariable<float>(parameterTable, "RotSpeed", &rotSpeed_);
    correct &= readVariable<float>(parameterTable, "MovSpeedLimit", &movSpeedLimit_);
    correct &= readVariable<float>(parameterTable, "RotSpeedLimit", &rotSpeedLimit_);
    correct &= readVariable<float>(parameterTable, "TurretSpeed", &turretSpeed_);

    int aux;
    correct &= readVariable<int>(parameterTable, "TurretLeftKey", &aux);
    turretLeft_ = (SDL_Scancode)aux;
    correct &= readVariable<int>(parameterTable, "TurretRightKey", &aux);
    turretRight_ = (SDL_Scancode)aux;;

    if (!correct) return false;

    return true;
}

void PlayerMovement::start()
{
    rb_ = entity_->getComponent<Rigidbody>();
}

void PlayerMovement::move() {
    //Fuerza a 0
    Vector3D aux = rb_->velocity();
    aux.y = 0.0f;
    aux *= -1;
    rb_->addForce(aux);

    if (abs(aux.x) < movSpeedLimit_ && abs(aux.z) < movSpeedLimit_) {
        Vector3D fuerza = transform->up * -movSpeed_ * InputManager::Instance()->getAxis(Axis::Vertical);
        rb_->addForce(fuerza);
    }
}

void PlayerMovement::rotate() {
    //Torsion a 0
    Vector3D aux = rb_->angularVelocity();
    aux.x = aux.z = 0.0f;
    aux *= -1;
    rb_->addTorque(aux);

    if (abs(aux.y) < rotSpeedLimit_) {
        Vector3D a = Vector3D(0, -rotSpeed_, 0) * InputManager::Instance()->getAxis(Axis::Horizontal);
        rb_->addTorque(a);
    }
}

void PlayerMovement::rotateTurret() {
    if (InputManager::Instance()->getKey(turretLeft_)) {
        transform->getChild(0)->transform()->Rotate(Vector3D(0, 0, turretSpeed_)
            * QuackEnginePro::Instance()->time()->deltaTime());
    }
    else if (InputManager::Instance()->getKey(turretRight_)) {
        transform->getChild(0)->transform()->Rotate(Vector3D(0, 0, -turretSpeed_)
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