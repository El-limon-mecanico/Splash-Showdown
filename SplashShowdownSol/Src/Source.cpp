#include "QuackEnginePro.h"
#include "FactoryManager.h"

#include "FactoryManager.h"
#include "PlayerController.h"
#include "BulletMovement.h"
#include "Shoot.h"
#include "Ricochet.h"
#include "Explode.h"
#include "Health.h"
#include "DealDamage.h"
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
	
	if (QuackEnginePro::Init("Splash Showdown")) {
		FactoryManager::instance()->add<PlayerController>();
		FactoryManager::instance()->add<BulletMovement>();
		FactoryManager::instance()->add<Shoot>();
		FactoryManager::instance()->add<Ricochet>();
		FactoryManager::instance()->add<Explode>();
		FactoryManager::instance()->add<DealDamage>();
		FactoryManager::instance()->add<Health>();
		FactoryManager::instance()->add<PlayButton>();
		FactoryManager::instance()->add<ExitButton>();
		FactoryManager::instance()->add<BackButton>();
		FactoryManager::instance()->add<StartGameButton>();
		FactoryManager::instance()->add<ChangeWeaponButton>();
		FactoryManager::instance()->add<Pause>();
		FactoryManager::instance()->add<ResumeButton>();

		QuackEnginePro::Instance()->setFullScreen(true);
		QuackEnginePro::Instance()->start("scenes/mainMenu.lua", "mainMenu");
	}
	

	return 0;
}

	