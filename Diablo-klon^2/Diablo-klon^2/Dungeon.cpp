#include "stdafx.h"
#include "Dungeon.h"


Dungeon::Dungeon()
{
	int tempX = 6, tempY = 6;


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

	if (aPreviousRoom.GetXPos() < 1 || aPreviousRoom.GetXPos() > 12 || aPreviousRoom.GetYPos() < 1 || aPreviousRoom.GetYPos() > 12)
	{
		return;
	}


}


