#include "PlayButton.h"
#include "CallBacks.h"
#include "SceneMng.h"
#include "AudioSource.h"

AudioSource* PlayButton::audioCmp;

PlayButton::PlayButton(QuackEntity* e)
{
	//guarda el metodo al que tenemos que llamar
	CallBacks::instance()->addMethod("Play", botonPulsado);	
}

void PlayButton::start()
{
	audioCmp = SceneMng::Instance()->getCurrentScene()->getObjectWithName("sonidoBoton")
			->getComponent<AudioSource>();
}


void PlayButton::botonPulsado()
{
	std::cout << "Agarrate que nos vamos de escena\n";
	audioCmp->play();
	while (audioCmp->isPlaying()); //esperamos a que termine el sonido para cambiar
	
	SceneMng::Instance()->loadScene("scenes/weaponMenu.lua", "weaponMenu");
}
