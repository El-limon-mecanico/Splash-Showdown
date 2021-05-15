#include "QuackEnginePro.h"


#if (defined _DEBUG)
int main() {
#else
#include <windows.h>
int WINAPI
WinMain(HINSTANCE zHInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif

	
	if (QuackEnginePro::Init()) {
		QuackEnginePro::Instance()->start();
	}


	return 0;
}

	