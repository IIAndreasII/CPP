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
	Room(const Door aDoor, uint8_t anX, uint8_t aY);
	~Room();


	void AddDoor(const Door aDoor);

	uint8_t& GetXPos();
	uint8_t& GetYPos();

private:
	std::vector<Door> myDoors;

	uint8_t myX, myY;

};

#endif