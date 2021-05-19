#include "ExitButton.h"
#include "CallBacks.h"
#include "QuackEnginePro.h"


ExitButton::ExitButton(QuackEntity* e)
{
	//guarda el metodo al que tenemos que llamar
	CallBacks::instance()->addMethod("Exit", botonPulsado);
}


void ExitButton::botonPulsado()
{
	std::cout << "Salimos\n";
	QuackEnginePro::Instance()->quit();
}