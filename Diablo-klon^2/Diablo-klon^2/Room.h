#ifndef ROOM_H
#define ROOM_H

#include "pch.h"
#include "Enemy.h"

class Player;

class Room
{
public:
	Room();
	Room(int aLevel);
	~Room();

	void SetEnemies(int &aLevel);

	bool Enter(Player &aPlayer);

private:

	std::vector<Enemy> myEnemies;
};

#endif