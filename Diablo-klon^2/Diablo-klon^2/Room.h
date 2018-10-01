#ifndef ROOM_H
#define ROOM_H

#include "pch.h"

enum Door
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Room
{
public:
	Room();
	~Room();


	void AddDoor(const Door aDoor);

	uint8_t& GetXPos();
	uint8_t& GetYPos();

private:
	std::vector<Door> myDoors;

	uint8_t myX, myY;

};

#endif