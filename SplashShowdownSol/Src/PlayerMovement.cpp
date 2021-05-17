#include "PlayerMovement.h"

bool PlayerMovement::init(luabridge::LuaRef parameterTable)
{
    speed_ = readVariable<float>(parameterTable, "Speed");
    keyForward_ = readVariable<SDL_Scancode>(parameterTable, "KeyUp");
    keyBack_ = readVariable<SDL_Scancode>(parameterTable, "KeyDown");
    keyLeft_ = readVariable<SDL_Scancode>(parameterTable, "KeyLeft");
    keyRight_ = readVariable<SDL_Scancode>(parameterTable, "KeyRight");

    return true;
}

void PlayerMovement::update()
{
    if (InputManager::Instance()->isKeyDown(keyForward_)) { //Adelante
        std::cout << "Pulsada Forward\n";
    }

    if (InputManager::Instance()->isKeyDown(keyBack_)) { //Atrás
        std::cout << "Pulsada Back\n";
    }

    if (InputManager::Instance()->isKeyDown(keyLeft_)) { //Izquierda
        std::cout << "Pulsada Left\n";
    }

    if (InputManager::Instance()->isKeyDown(keyRight_)) { //Derecha
        std::cout << "Pulsada Right\n";
    }
}
