#include "QuackEnginePro.h"

#include "FactoryManager.h"
#include "PlayerMovement.h"


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

		QuackEnginePro::Instance()->start("Scenes/scene1.lua", "scene1");
	}

	return 0;
}

	