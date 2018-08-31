#pragma once

#include "ShipComponent.h"

class Cannons :
	public ShipComponent
{
public:
	Cannons();
	~Cannons();

    void DisplayStatus();

private:

	uint8_t myNumberOfCannons;
};

