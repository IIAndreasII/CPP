#include "stdafx.h"
#include "Room.h"


Room::Room()
{
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
