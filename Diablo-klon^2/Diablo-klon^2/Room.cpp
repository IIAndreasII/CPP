#include "stdafx.h"
#include "Room.h"
#include "Util.h"
#include "Enemy.h"

Room::Room() : myIsTrueRoom(false), myIsCurrentRoom(false), myEnemies(new std::vector<Enemy>())
{
	int tempEnemies = RNG(0, 5);
}


Room::Room(uint8_t anX, uint8_t aY) : myDoors(), myX(anX), myY(aY), myIsTrueRoom(true), myIsCurrentRoom(false), myEnemies(new std::vector<Enemy>())
{
	int tempEnemies = RNG(0, 5);
}

Room::~Room()
{
	SafeDelete(myEnemies);
}

void Room::AddDoor(const Door aDoor)
{
	if (!(std::find(myDoors.begin(), myDoors.end(), aDoor) != myDoors.end()))
	{
		myDoors.push_back(aDoor);
	}
}

uint8_t & Room::GetXPos()
{
	return myX;
}

uint8_t & Room::GetYPos()
{
	return myY;
}

std::vector<Door>& Room::GetDoors()
{
	return myDoors;
}

bool & Room::GetIsTrueRoom()
{
	return myIsTrueRoom;
}

bool & Room::GetIsCurrentRoom()
{
	return myIsCurrentRoom;
}

void Room::SetIsCurrentRoom(bool aValue)
{
	myIsCurrentRoom = aValue;
}

void Room::SetPos(int X, int Y)
{
	myX = X;
	myY = Y;
}

void Room::SetIsTrueRoom(bool aValue)
{
	myIsTrueRoom = aValue;
}
