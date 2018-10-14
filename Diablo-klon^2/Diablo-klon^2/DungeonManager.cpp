#include "stdafx.h"
#include "DungeonManager.h"
#include "Dungeon.h"
#include "Util.h"

DungeonManager::DungeonManager() : myDungeon()
{
}

DungeonManager::~DungeonManager()
{
}

void DungeonManager::Reset()
{
	SafeDelete(myDungeon);
	myDungeon = new Dungeon();
}

Dungeon & DungeonManager::GetDungeon()
{
	return *myDungeon;
}