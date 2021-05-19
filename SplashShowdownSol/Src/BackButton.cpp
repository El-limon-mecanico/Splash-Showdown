#include "BackButton.h"
#include "CallBacks.h"
#include "SceneMng.h"


BackButton::BackButton(QuackEntity* e)
{
	//guarda el metodo al que tenemos que llamar
	CallBacks::instance()->addMethod("Back", botonPulsado);
}


void BackButton::botonPulsado()
{
	std::cout << "Agarrate que nos vamos de escena\n";
	SceneMng::Instance()->loadScene("scenes/mainMenu.lua", "mainMenu");
}
