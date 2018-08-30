#pragma once
#include "ShipComponent.h"
class Cannons :
	public ShipComponent
{
public:
	Cannons();
	~Cannons();

private:

	uint8_t myNumberOfCannons;
};

