#ifndef DM_H
#define DM_H

#include "Dungeon.h"

class DungeonManager
{
public:
	DungeonManager();
	~DungeonManager();

	void Reset();

	Dungeon& GetDungeon();

private:
	Dungeon myDungeon;
};

#endif