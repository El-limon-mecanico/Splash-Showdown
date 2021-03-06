#include "StartGameButton.h"
#include "CallBacks.h"
#include "SceneMng.h"
#include "ChangeWeaponButton.h"
#include "AudioSource.h"

AudioSource* StartGameButton::audioCmp;


StartGameButton::StartGameButton(QuackEntity* e)
{
	//guarda el metodo al que tenemos que llamar
	CallBacks::instance()->addMethod("StartGame", botonPulsado);
}

void StartGameButton::start()
{
	audioCmp = SceneMng::Instance()->getCurrentScene()->getObjectWithName("sonidoBoton")
		->getComponent<AudioSource>();
}


void StartGameButton::botonPulsado()
{
	std::cout << "Agarrate que nos vamos de escena\n";

	//sacamos que arma tenemos equipada
	bool explosiveWeapon = SceneMng::Instance()->getCurrentScene()->getObjectWithName("weaponButton")
	->getComponent<ChangeWeaponButton>()->getWeapon();
	//si es true, tenemos el diaparo explosivo, si es false, tenemos el rebotante
	
	audioCmp->play();
	while (audioCmp->isPlaying()); //esperamos a que termine el sonido para cambiar

	//cargar distintas escenas segun el arma
	int mapa = rand() % 2;
	if(mapa == 1)
	{
		if(explosiveWeapon)
			SceneMng::Instance()->loadScene("scenes/Partida1Explosion.lua", "Partida1Explosion");
		else
			SceneMng::Instance()->loadScene("scenes/Partida1Rebote.lua", "Partida1Rebote");
	}
	else
	{
		if(explosiveWeapon)
			SceneMng::Instance()->loadScene("scenes/Partida2Explosion.lua", "Partida2Explosion");
		else
			SceneMng::Instance()->loadScene("scenes/Partida2Rebote.lua", "Partida2Rebote");
	}
}
