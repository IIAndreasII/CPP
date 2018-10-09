#include "stdafx.h"
#include "DungeonManager.h"
#include "Dungeon.h"
#include "Util.h"
//#include "Game.h"


DungeonManager::DungeonManager() : myDungeon()
{
}


DungeonManager::~DungeonManager()
{
}

void DungeonManager::ViewMap()
{
	bool tempLoop = true;
	while (tempLoop)
	{
		CLSSlow();
		myDungeon->PrintMap();

		WriteLine("[1] Back");
		if (GetInput() == 1)
		{
			tempLoop = false;
		}
	}
}
