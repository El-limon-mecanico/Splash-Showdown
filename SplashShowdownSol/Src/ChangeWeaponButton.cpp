#include "ChangeWeaponButton.h"
#include "CallBacks.h"
#include "SceneMng.h"


bool ChangeWeaponButton::exploviseWeapon;

ChangeWeaponButton::ChangeWeaponButton(QuackEntity* e)
{
	//guarda el metodo al que tenemos que llamar
	CallBacks::instance()->addMethod("ChangeWeapon", botonPulsado);
}

void ChangeWeaponButton::start()
{
	if (SceneMng::Instance()->getCurrentScene()->getObjectWithName("explosiveWeapon")->isActive())
		exploviseWeapon = true;
	else
		exploviseWeapon = false;

	setImages();
}


void ChangeWeaponButton::botonPulsado()
{
	exploviseWeapon = !exploviseWeapon;	
	setImages();
}


void ChangeWeaponButton::setImages()
{
	if (exploviseWeapon)
	{
		SceneMng::Instance()->getCurrentScene()->getObjectWithName("explosiveWeapon")->setActive(true);
		SceneMng::Instance()->getCurrentScene()->getObjectWithName("bouncingWeapon")->setActive(false);
	}
	else
	{
		SceneMng::Instance()->getCurrentScene()->getObjectWithName("explosiveWeapon")->setActive(false);
		SceneMng::Instance()->getCurrentScene()->getObjectWithName("bouncingWeapon")->setActive(true);		
	}
}
