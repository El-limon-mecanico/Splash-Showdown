#include "StartGameButton.h"
#include "CallBacks.h"
#include "SceneMng.h"


StartGameButton::StartGameButton(QuackEntity* e)
{
	//guarda el metodo al que tenemos que llamar
	CallBacks::instance()->addMethod("StartGame", botonPulsado);
}


void StartGameButton::botonPulsado()
{
	std::cout << "Agarrate que nos vamos de escena\n";
	SceneMng::Instance()->loadScene("scenes/Partida.lua", "Partida");
}
