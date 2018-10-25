#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include "pch.h"

class Player;

class Dungeon
{
public:
	Dungeon();
	Dungeon(uint16_t aLevel);
	~Dungeon();

	void Reset(uint16_t aLevel);
	void Enter(Player &aPlayer);
	bool Navigate(Player &aPlayer);

private:

	std::vector<Room> myRooms;

	Room* myCurrentRoom;

	size_t myCurrentRoomIndex;
};

#endif