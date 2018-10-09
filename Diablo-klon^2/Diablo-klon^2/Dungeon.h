#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"

class Dungeon
{
public:
	Dungeon();
	Dungeon(uint16_t aMaxNumberOfRooms);
	~Dungeon();

	void PrintMap();

	void Navigate();

	void Enter();

	uint16_t& GetNrDoors();

private:

	Room *myRooms[21][21];

	void Generate(Room aPreviousRoom, Door aPreviousDoor, uint16_t &aRoomCount);

	uint16_t myRoomMax;

	Room& myCurrentRoom;

	Door GetRandomDoor();

};

#endif