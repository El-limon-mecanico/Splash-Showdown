#include "QuackEnginePro.h"
#include "FactoryManager.h"

#include "FactoryManager.h"
#include "PlayerController.h"
#include "BulletMovement.h"
#include "Shoot.h"
#include "PlayButton.h"
#include "ExitButton.h"
#include "BackButton.h"
#include "StartGameButton.h"
#include "ChangeWeaponButton.h"
#include "Pause.h"
#include "ResumeButton.h"


#if (defined _DEBUG)
int main() {
#else
#include <windows.h>
int WINAPI
WinMain(HINSTANCE zHInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif

	// TODO: AQUI FALTA MANEJO DE ERRORES Y EXCEPCIONES
	if (QuackEnginePro::Init("Splash Showdown")) {
		FactoryManager::instance()->add<PlayerController>();
		FactoryManager::instance()->add<BulletMovement>();
		FactoryManager::instance()->add<Shoot>();
		FactoryManager::instance()->add<PlayButton>();
		FactoryManager::instance()->add<ExitButton>();
		FactoryManager::instance()->add<BackButton>();
		FactoryManager::instance()->add<StartGameButton>();
		FactoryManager::instance()->add<ChangeWeaponButton>();
		FactoryManager::instance()->add<Pause>();
		FactoryManager::instance()->add<ResumeButton>();
		
		QuackEnginePro::Instance()->start("scenes/mainMenu.lua", "mainMenu");
	}

	return 0;
}

	