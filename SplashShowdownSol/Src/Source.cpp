#include "QuackEnginePro.h"
#include "FactoryManager.h"

#include "PlayButton.h"
#include "ExitButton.h"
#include "BackButton.h"

//class PlayButton;
//class ExitButton;

#if (defined _DEBUG)
int main() {
#else
#include <windows.h>
int WINAPI
WinMain(HINSTANCE zHInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif



	
	if (QuackEnginePro::Init("Splash")) {
		FactoryManager::instance()->add<PlayButton>();
		FactoryManager::instance()->add<ExitButton>();
		FactoryManager::instance()->add<BackButton>();
		QuackEnginePro::Instance()->start("scenes/mainMenu.lua", "mainMenu");
	}


	return 0;
}

	