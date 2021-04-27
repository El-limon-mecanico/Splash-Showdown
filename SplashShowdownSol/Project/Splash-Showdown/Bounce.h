#pragma once
#include "Component.h"

class Bounce : public Component
{
private:
	int bounces_;

public:

	Bounce() {}
	~Bounce() {}

	void bounce();
};

