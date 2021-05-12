#include "Bounce.h"
#include "QuackEntity.h"
#include "Rigidbody.h"

void Bounce::bounce()
{
	bounces_--;

	
	if (bounces_ == 0)
	{
		//matamos la bala
	}

	else
	{
		//si choca con un tanque
		//if(tanque)
			//tanque->getComponent(Health)->kill();
		//else if(pared)
			// changeDir();	// de esto se ocupa el rigidbody?
	}
}
