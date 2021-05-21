#include "QuackEnginePro.h"

#include "FactoryManager.h"
#include "PlayerMovement.h"
#include "BulletMovement.h"


#if (defined _DEBUG)
int main() {
#else
#include <windows.h>
int WINAPI
WinMain(HINSTANCE zHInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif

	// TODO: AQUI FALTA MANEJO DE ERRORES Y EXCEPCIONES
	if (QuackEnginePro::Init("Splash Showdown")) {
		FactoryManager::instance()->add<PlayerMovement>();
		FactoryManager::instance()->add<BulletMovement>();

		QuackEnginePro::Instance()->start("Scenes/Partida.lua", "Partida");
	}

	return 0;
}

	