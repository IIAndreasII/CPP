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

	void Reset();
	void Enter(Player &aPlayer);
	bool Navigate(Player &aPlayer);

private:

	std::vector<Room> myRooms;

	Room* myCurrentRoom;

	size_t myCurrentRoomIndex;
};

#endif