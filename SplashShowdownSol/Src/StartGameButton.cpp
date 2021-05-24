#include "StartGameButton.h"
#include "CallBacks.h"
#include "SceneMng.h"
#include "ChangeWeaponButton.h"


StartGameButton::StartGameButton(QuackEntity* e)
{
	//guarda el metodo al que tenemos que llamar
	CallBacks::instance()->addMethod("StartGame", botonPulsado);
}


void StartGameButton::botonPulsado()
{
	std::cout << "Agarrate que nos vamos de escena\n";

	//sacamos que arma tenemos equipada
	bool explosiveWeapon = SceneMng::Instance()->getCurrentScene()->getObjectWithName("weaponButton")
	->getComponent<ChangeWeaponButton>()->getWeapon();
	//si es true, tenemos el diaparo explosivo, si es false, tenemos el rebotante
	
		
	SceneMng::Instance()->loadScene("scenes/Partida1.lua", "Partida1");
}
