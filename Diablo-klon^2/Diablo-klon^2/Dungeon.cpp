#include "stdafx.h"
#include "Dungeon.h"
#include "Util.h"

Dungeon::Dungeon() : myNumberOfDoors(10), myCurrentRoom(myRooms[10][10]), myRooms()
{
	Door tempDoorToAdd = GetRandomDoor();
	for (size_t i = 0; i < 2; i++)
	{
		while (std::find(myRooms[10][10].GetDoors().begin(), myRooms[10][10].GetDoors().end(), tempDoorToAdd) != myRooms[10][10].GetDoors().end())
		{
			tempDoorToAdd = GetRandomDoor();
		}
		
		myRooms[10][10].AddDoor(tempDoorToAdd);
	}

	myRooms[10][10].SetPos(10, 10);
	myRooms[10][10].SetIsCurrentRoom(true);
	myRooms[10][10].SetIsTrueRoom(true);

	for (Door tempDoor : myRooms[10][10].GetDoors())
	{
		Generate(myRooms[10][10], tempDoor, myNumberOfDoors);
	}

	myCurrentRoom = myRooms[10][10];
}

Dungeon::Dungeon(uint16_t aNumberOfMaximumDoors) : myNumberOfDoors(aNumberOfMaximumDoors), myCurrentRoom(myRooms[4][4]), myRooms()
{
	Door tempDoorToAdd = GetRandomDoor();
	for (size_t i = 0; i < 2; i++)
	{
		while (std::find(myRooms[10][10].GetDoors().begin(), myRooms[10][10].GetDoors().end(), tempDoorToAdd) != myRooms[10][10].GetDoors().end())
		{
			tempDoorToAdd = GetRandomDoor();
		}
		myRooms[10][10].AddDoor(tempDoorToAdd);
	}

	for (Door tempDoor : myRooms[10][10].GetDoors())
	{
		Generate(myRooms[10][10], tempDoor, myNumberOfDoors);
	}

	myCurrentRoom = myRooms[10][10];
}


Dungeon::~Dungeon()
{
}

void Dungeon::PrintMap()
{
	std::string tempRows[21];

	for (size_t i = 0; i < 21; i++)
	{
		tempRows[i] += "|";
		for (size_t j = 0; j < 21; j++)
		{
			char tempCharToAdd;

			if (myRooms[i][j].GetIsTrueRoom())
			{
				if (myRooms[i][j].GetIsCurrentRoom())
				{
					tempCharToAdd = 'X';
				}
				else
				{
					tempCharToAdd = 'O';
				}
			}
			else
			{
				tempCharToAdd = ' ';
			}

			tempRows[i] += tempCharToAdd;
		}
		tempRows[i] += "|";
	}

	WriteLine("________| Map |________");
	for (size_t i = 0; i < 21; i++)
	{
		WriteLine(tempRows[i]);
	}
	WriteLine("|_____________________|");

}

void Dungeon::Navigate()
{
	std::string tempRows[4];

	for (Door tempDoor : myCurrentRoom.GetDoors())
	{
		switch (tempDoor)
		{
		case Door::NORTH:
			tempRows[0] = "[1] North";
			break;
		case Door::EAST:
			tempRows[1] = "[2] East";
			break;
		case Door::SOUTH:
			tempRows[2] = "[3] South";
			break;
		case::WEST:
			tempRows[3] = "[4] West";
			break;
		}
	}

	bool tempLoop = true;
	int tempX = myCurrentRoom.GetXPos();
	int tempY = myCurrentRoom.GetYPos();

	while (tempLoop)
	{
		CLSSlow();
		WriteLine("__| Doors |__");
		for (size_t i = 0; i < 4; i++)
		{
			WriteLine(tempRows[i]);
		}

		switch (GetInput())
		{
		case 1:
			if (std::find(myCurrentRoom.GetDoors().begin(), myCurrentRoom.GetDoors().end(), Door::NORTH) != myCurrentRoom.GetDoors().end())
			{
				tempY -= 1;
				tempLoop = false;
			}
			break;
		case 2:
			if (std::find(myCurrentRoom.GetDoors().begin(), myCurrentRoom.GetDoors().end(), Door::EAST) != myCurrentRoom.GetDoors().end())
			{
				tempX += 1;
				tempLoop = false;
			}
			break;
		case 3:
			if (std::find(myCurrentRoom.GetDoors().begin(), myCurrentRoom.GetDoors().end(), Door::SOUTH) != myCurrentRoom.GetDoors().end())
			{
				tempY += 1;
				tempLoop = false;
			}
			break;
		case 4:
			if (std::find(myCurrentRoom.GetDoors().begin(), myCurrentRoom.GetDoors().end(), Door::WEST) != myCurrentRoom.GetDoors().end())
			{
				tempX -= 1;
				tempLoop = false;
			}
			break;
		}
	}
	myCurrentRoom = myRooms[tempX][tempY];
}

uint16_t & Dungeon::GetNrDoors()
{
	return myNumberOfDoors;
}

void Dungeon::Generate(Room aPreviousRoom, Door aPreviousDoor, uint16_t &aRoomCount)
{
	if (aRoomCount <= 0)
	{
		return;
	}
	else if (aPreviousRoom.GetXPos() < 1 || aPreviousRoom.GetXPos() > 20 || aPreviousRoom.GetYPos() < 1 || aPreviousRoom.GetYPos() > 20)
	{
		return;
	}

	int tempNumberOfDoors = RNG(0, (aRoomCount > 2 ? 2 : aRoomCount));

	int tempX = aPreviousRoom.GetXPos();
	int	tempY = aPreviousRoom.GetYPos();

	if (tempNumberOfDoors <= 0)
	{
		Door tempDoorToAdd = Door::FAULTY;
		switch (aPreviousDoor)
		{
		case Door::EAST:
			tempX += 1;
			tempDoorToAdd = Door::WEST;
			break;
		case Door::NORTH:
			tempY += 1;
			tempDoorToAdd = Door::SOUTH;
			break;
		case Door::SOUTH:
			tempY -= 1;
			tempDoorToAdd = Door::NORTH;
			break;
		case Door::WEST:
			tempX -= 1;
			tempDoorToAdd = Door::EAST;
			break;
		}

		if (!myRooms[tempX][tempY].GetIsTrueRoom())
		{
			myRooms[tempX][tempY].AddDoor(tempDoorToAdd);
			myRooms[tempX][tempY].SetPos(tempX, tempY);
			myRooms[tempX][tempY].SetIsTrueRoom(true);
		}
		return;
	}
	else
	{
		Door tempPrevDoor = FAULTY;
		switch (aPreviousDoor)
		{
		case Door::NORTH:
			tempY += 1;
			tempPrevDoor = Door::SOUTH;
			break;
		case Door::SOUTH:
			tempY -= 1;
			tempPrevDoor = Door::NORTH;
			break;
		case Door::EAST:
			tempX += 1;
			tempPrevDoor = Door::WEST;
			break;
		case Door::WEST:
			tempX -= 1;
			tempPrevDoor = Door::EAST;
			break;
		}
		if (!myRooms[tempX][tempY].GetIsTrueRoom())
		{
			myRooms[tempX][tempY].AddDoor(tempPrevDoor);
			myRooms[tempX][tempY].SetPos(tempX, tempY);
			myRooms[tempX][tempY].SetIsTrueRoom(true);
		}

		Door tempDoorToAdd = GetRandomDoor();
		for (size_t i = 0; i < tempNumberOfDoors; i++)
		{
			if (myRooms[tempX][tempY].GetDoors().size() < 4)
			{
				while (std::find(myRooms[tempX][tempY].GetDoors().begin(), myRooms[tempX][tempY].GetDoors().end(), tempDoorToAdd) != myRooms[tempX][tempY].GetDoors().end())
				{
					tempDoorToAdd = GetRandomDoor();
				}

				myRooms[tempX][tempY].AddDoor(tempDoorToAdd);
			}
		}

		for (Door tempDoor : myRooms[tempX][tempY].GetDoors())
		{
			if (tempPrevDoor != tempDoor)
			{
				aRoomCount -= 1;
				Generate(myRooms[tempX][tempY], tempDoor, aRoomCount);
			}
		}
		return;
	}
}

Door Dungeon::GetRandomDoor()
{
	switch (RNG(0, 3))
	{
	case 0:
		return Door::NORTH;
	case 1:
		return Door::SOUTH;
	case 2:
		return Door::EAST;
	case 3:
		return Door::WEST;
	}
	return Door::SOUTH;
}


