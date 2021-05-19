#include "PlayButton.h"
#include "CallBacks.h"
#include "SceneMng.h"


PlayButton::PlayButton(QuackEntity* e)
{
	//guarda el metodo al que tenemos que llamar
	CallBacks::instance()->addMethod("Play", botonPulsado);
}


void PlayButton::botonPulsado()
{
	std::cout << "Agarrate que nos vamos de escena\n";
	//SceneMng::Instance()->popCurrentScene();
	SceneMng::Instance()->loadScene("scenes/weaponMenu.lua", "weaponMenu");
}
