#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"

class Dungeon
{
public:
	Dungeon();
	~Dungeon();


private:

	Room myRooms[13][13];

	void Generate(Room &aPreviousRoom, Door &aPreviousDoor, uint16_t &aDoorCount);

};

#endif