#include "ResumeButton.h"
#include "CallBacks.h"
#include "SceneMng.h"

ResumeButton::ResumeButton(QuackEntity* e)
{
	CallBacks::instance()->addMethod("ResumeGame", botonPulsado);
}


void ResumeButton::botonPulsado()
{
	std::cout << "Volvemos al juego\n";
	SceneMng::Instance()->popCurrentScene();
}