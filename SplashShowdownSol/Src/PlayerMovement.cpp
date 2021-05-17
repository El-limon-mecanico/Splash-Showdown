#include "PlayerMovement.h"
#include "InputManager.h"

bool PlayerMovement::init(luabridge::LuaRef parameterTable)
{
    //speed_ = readVariable<float>(parameterTable, "Speed");

    return true;
}

void PlayerMovement::update()
{
    if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_W)) { //Adelante
        std::cout << "Pulsada W\n";
    }

    if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_S)) { //Atrás
        std::cout << "Pulsada S\n";
    }

    if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_A)) { //Izquierda
        std::cout << "Pulsada A\n";
    }

    if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_D)) { //Derecha
        std::cout << "Pulsada D\n";
    }
}
