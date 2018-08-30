#pragma once

#include "Ship.h"

class Player
{
public:
	Player();
	~Player();

	Ship& GetShip();


private:

	Ship myShip;
};

