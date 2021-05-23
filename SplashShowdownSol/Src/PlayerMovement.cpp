#include "PlayerMovement.h"
#include "QuackEntity.h"
#include <QuackEnginePro.h>

PlayerMovement::~PlayerMovement() {
    delete rb_;
    delete tr_;
}

bool PlayerMovement::init(luabridge::LuaRef parameterTable) //TODO: Manejo de errores
{
    readVariable<float>(parameterTable, "MovSpeed", &movSpeed_);
    readVariable<float>(parameterTable, "RotSpeed", &rotSpeed_);
    readVariable<float>(parameterTable, "MovSpeedLimit", &movSpeedLimit_);
	readVariable<float>(parameterTable, "RotSpeedLimit", &rotSpeedLimit_);
    readVariable<float>(parameterTable, "TurretSpeed", &turretSpeed_);
    
    readVariable<SDL_Scancode>(parameterTable, "TurretLeftKey", &turretLeft_);
    readVariable<SDL_Scancode>(parameterTable, "TurretRightKey", &turretRight_);

    rb_ = entity_->getComponent<Rigidbody>();
    tr_ = entity_->transform();

    return true;
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