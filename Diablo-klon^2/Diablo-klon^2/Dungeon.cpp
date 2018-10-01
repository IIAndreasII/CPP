#include "stdafx.h"
#include "Dungeon.h"


Dungeon::Dungeon()
{
}


Dungeon::~Dungeon()
{
}

void Dungeon::Generate(Room &aPreviousRoom, Door &aPreviousDoor, uint16_t &aDoorCount)
{
	if (aDoorCount <= 0)
	{
		return;
	}
	if (aPreviousRoom.GetXPos() < 1 || aPreviousRoom.GetXPos() > 12 ||)
}


