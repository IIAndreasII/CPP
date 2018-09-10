#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

class Player
{
public:
	Player();
	~Player();

    void DisplayShipStatus();

	// Get
	Ship& GetShip();
	uint32_t& GetDoubloons();

	// Set
	void SetDoubloons(uint32_t tempValue);
	

private:

	Ship myShip;

	uint32_t myDoubloons;

};

#endif