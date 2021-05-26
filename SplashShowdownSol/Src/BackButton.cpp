#include "BackButton.h"
#include "CallBacks.h"
#include "SceneMng.h"
#include "AudioSource.h"

AudioSource* BackButton::audioCmp;

BackButton::BackButton(QuackEntity* e)
{
	//guarda el metodo al que tenemos que llamar
	CallBacks::instance()->addMethod("Back", botonPulsado);
	
}

void BackButton::start()
{
	audioCmp = SceneMng::Instance()->getCurrentScene()->getObjectWithName("sonidoBoton")
		->getComponent<AudioSource>();
}


void BackButton::botonPulsado()
{
	std::cout << "Agarrate que nos vamos de escena\n";

	audioCmp->play();
	while (audioCmp->isPlaying()); //esperamos a que termine el sonido para cambiar
	
	SceneMng::Instance()->loadScene("scenes/mainMenu.lua", "mainMenu");	
}
