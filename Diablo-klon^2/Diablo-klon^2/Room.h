#ifndef ROOM_H
#define ROOM_H

#include "pch.h"

#include "Enemy.h"
class Player;

enum Door
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FAULTY
};

class Room
{
public:
	Room();
	Room(uint8_t anX, uint8_t aY);
	~Room();

	void AddDoor(const Door aDoor);

	uint8_t& GetXPos();
	uint8_t& GetYPos();

	std::vector<Door>& GetDoors();

	bool& GetIsTrueRoom();

	bool& GetIsCurrentRoom();

	void SetIsCurrentRoom(bool aValue);

	void SetPos(int X, int Y);

	void SetIsTrueRoom(bool aValue);

	void Enter(Player &aPlayer);

private:

	std::vector<Door> myDoors;

	uint8_t myX, myY;

	bool myIsTrueRoom, myIsCurrentRoom;

	std::vector<Enemy> myEnemies;
};

#endif