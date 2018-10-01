#include "stdafx.h"
#include "Room.h"


Room::Room()
{
}


Room::Room(const Door aDoor, uint8_t anX, uint8_t aY) : myDoors(), myX(anX), myY(aY)
{
	AddDoor(aDoor);
}

Room::~Room()
{
}

void Room::AddDoor(const Door aDoor)
{
	myDoors.push_back(aDoor);
}

uint8_t & Room::GetXPos()
{
	return myX;
}

uint8_t & Room::GetYPos()
{
	return myY;
}
