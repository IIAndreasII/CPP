#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include "pch.h"

class Player;

class Dungeon
{
public:
	Dungeon();
	Dungeon(int aLevel);

	~Dungeon();

	void ViewMap();

	bool Navigate(Player &aPlayer);

	void Enter(Player &aPlayer);

private:

	std::vector<Room> myRooms;

	uint16_t myRoomMax;

	Room* myCurrentRoom;

	size_t myCurrentRoomIndex;
};

#endif