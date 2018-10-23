#include "stdafx.h"
#include "Dungeon.h"
#include "Util.h"
#include "Player.h"
#include <thread>

Dungeon::Dungeon() : myRooms(), myCurrentRoomIndex(0)
{
	Room tempRoom(1);
	myRooms.push_back(tempRoom);
}

Dungeon::Dungeon(int aLevel) : myRooms(), myCurrentRoomIndex(0)
{
	Room tempRoom(aLevel);
	myRooms.push_back(tempRoom);
}

Dungeon::~Dungeon()
{
}

void Dungeon::ViewMap()
{
	/*std::string tempRows[21];

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

	bool tempLoop = true;
	while (tempLoop)
	{
		CLSSlow();

		Print("________| Map |________");
		for (size_t i = 0; i < 21; i++)
		{
			Print(tempRows[i]);
		}
		Print("|_____________________|\n[1] Back");

		if (GetInput() == 1)
		{
			tempLoop = false;
		}
	}*/
}

void Dungeon::Reset()
{
	myRooms.clear();
	Room tempRoom(1);
	myRooms.push_back(tempRoom);
}

bool Dungeon::Navigate(Player &aPlayer)
{
	Room tempRoom(aPlayer.GetLevel());

	size_t tempPrevRoomIndex = myCurrentRoomIndex;

	bool tempLoop = true;
	while (tempLoop)
	{
		CLSSlow();
		aPlayer.PrintUI();

		Print("__| Select |__\n[1] Continue on journey\n[2] Inventory\n[3] Rest\n[4] Quit");

		bool tempInnerLoop = true;
		bool tempAllowPrevRoom = false;
		switch (GetInput())
		{
		case 1:
			while (tempInnerLoop)
			{
				CLSSlow();
				aPlayer.PrintUI();
				Print("__| Choose |__\n[1] Next area");
				if (myCurrentRoomIndex > 0)
				{
					Print("[2] Previous area");
					tempAllowPrevRoom = true;
				}

				switch (GetInput())
				{
				case 1:
					myRooms.push_back(tempRoom);
					myCurrentRoomIndex++;
					tempInnerLoop = false;
					tempLoop = false;
					break;

				case 2:
					if (tempAllowPrevRoom)
					{
						myCurrentRoomIndex--;
						tempInnerLoop = false;
						tempLoop = false;
					}
					break;
				}
			}

			break;

		case 2:
			aPlayer.ShowInventory();
			break;
		case 3:
			aPlayer.LongRest();
			break;
		case 4:
			return !Confirm();
		}
	}

	return true;
}

void Dungeon::Enter(Player &aPlayer)
{
	CLSSlow();
	aPlayer.PrintUI();
	Print("You enter the nearest dungeon");
	std::this_thread::sleep_for(std::chrono::seconds(2));

	bool tempLoop = true;
	while (tempLoop)
	{
		if (myRooms.at(myCurrentRoomIndex).Enter(aPlayer))
		{
			tempLoop = Navigate(aPlayer);
		}
		else
		{
			tempLoop = false;
		}
	}
}