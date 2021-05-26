#include "ResumeButton.h"
#include "CallBacks.h"
#include "SceneMng.h"
#include "AudioSource.h"

AudioSource* ResumeButton::audioCmp;

ResumeButton::ResumeButton(QuackEntity* e)
{
	CallBacks::instance()->addMethod("ResumeGame", botonPulsado);
}

void ResumeButton::botonPulsado()
{
	std::cout << "Volvemos al juego\n";

	audioCmp = SceneMng::Instance()->getCurrentScene()->getObjectWithName("sonidoBoton")
		->getComponent<AudioSource>();
	audioCmp->play();
	while (audioCmp->isPlaying()); //esperamos a que termine el sonido para cambiar
	
	SceneMng::Instance()->popCurrentScene();
}
