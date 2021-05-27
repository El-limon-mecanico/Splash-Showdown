#include "PlayerController.h"
#include "QuackEntity.h"
#include <QuackEnginePro.h>
#include "Shoot.h"

PlayerController::~PlayerController() {
    rb_ = nullptr;
}

bool PlayerController::init(luabridge::LuaRef parameterTable)
{
    bool correct = true;

    correct &= readVariable<float>(parameterTable, "MovSpeed", &movSpeed_);
    correct &= readVariable<float>(parameterTable, "RotSpeed", &rotSpeed_);
    correct &= readVariable<float>(parameterTable, "MovSpeedLimit", &movSpeedLimit_);
    correct &= readVariable<float>(parameterTable, "RotSpeedLimit", &rotSpeedLimit_);
    correct &= readVariable<float>(parameterTable, "TurretSpeed", &turretSpeed_);

    int aux;
    correct &= readVariable<int>(parameterTable, "TurretLeftKey", &aux);
    turretLeftKey_ = (SDL_Scancode)aux;
    correct &= readVariable<int>(parameterTable, "TurretRightKey", &aux);
    turretRightKey_ = (SDL_Scancode)aux;;
    correct &= readVariable<int>(parameterTable, "ShootKey", &aux);
    shootKey_ = (SDL_Scancode)aux;;

    return correct;
}

void PlayerController::start()
{
    rb_ = entity_->getComponent<Rigidbody>();
}

void PlayerController::move() {
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

void PlayerController::rotate() {
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

void PlayerController::rotateTurret() {
    if (InputManager::Instance()->getKey(turretLeftKey_)) {
        transform->getChild(0)->transform()->Rotate(Vector3D(0, 0, turretSpeed_)
            * QuackEnginePro::Instance()->time()->deltaTime());
    }
    else if (InputManager::Instance()->getKey(turretRightKey_)) {
        transform->getChild(0)->transform()->Rotate(Vector3D(0, 0, -turretSpeed_)
            * QuackEnginePro::Instance()->time()->deltaTime());
    }
}

void PlayerController::shoot()
{
    if (InputManager::Instance()->getKeyDown(shootKey_)) {
        Vector3D dir = transform->getChild(0)->transform()->up * -1;
        Vector3D pos = transform->getChild(0)->transform()->position();
        entity_->getComponent<Shoot>()->shootBullet(dir.normalize(), pos + dir.normalize());
    }
}

void PlayerController::update()
{
    move();
    rotate();
    rotateTurret();
    shoot();
}