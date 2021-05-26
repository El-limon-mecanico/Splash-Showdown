#include "ExitButton.h"
#include "SceneMng.h"
#include "CallBacks.h"
#include "QuackEnginePro.h"
#include "AudioSource.h"

AudioSource* ExitButton::audioCmp;

ExitButton::ExitButton(QuackEntity* e)
{
	//guarda el metodo al que tenemos que llamar
	CallBacks::instance()->addMethod("Exit", botonPulsado);
}

void ExitButton::start()
{
	audioCmp = SceneMng::Instance()->getCurrentScene()->getObjectWithName("sonidoBoton")
		->getComponent<AudioSource>();
}


void ExitButton::botonPulsado()
{
	std::cout << "Salimos\n";
	audioCmp->play();
	while (audioCmp->isPlaying()); //esperamos a que termine el sonido para cambiar
	QuackEnginePro::Instance()->quit();
}
