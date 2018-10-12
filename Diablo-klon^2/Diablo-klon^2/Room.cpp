#include "stdafx.h"
#include "Room.h"
#include "Util.h"
#include "Enemy.h"
#include "Player.h"
#include <thread>

Room::Room() : myIsTrueRoom(false), myIsCurrentRoom(false), myEnemies(new std::vector<Enemy>())
{
	int tempEnemies = RNG(0, 5);
}

Room::Room(uint8_t anX, uint8_t aY) : myDoors(), myX(anX), myY(aY), myIsTrueRoom(true), myIsCurrentRoom(false), myEnemies(new std::vector<Enemy>())
{
	int tempEnemies = RNG(0, 5);
}

Room::~Room()
{
	SafeDelete(myEnemies);
}

void Room::AddDoor(const Door aDoor)
{
	if (!(std::find(myDoors.begin(), myDoors.end(), aDoor) != myDoors.end()))
	{
		myDoors.push_back(aDoor);
	}
}

uint8_t & Room::GetXPos()
{
	return myX;
}

uint8_t & Room::GetYPos()
{
	return myY;
}

std::vector<Door>& Room::GetDoors()
{
	return myDoors;
}

bool & Room::GetIsTrueRoom()
{
	return myIsTrueRoom;
}

bool & Room::GetIsCurrentRoom()
{
	return myIsCurrentRoom;
}

void Room::SetIsCurrentRoom(bool aValue)
{
	myIsCurrentRoom = aValue;
}

void Room::SetPos(int X, int Y)
{
	myX = X;
	myY = Y;
}

void Room::SetIsTrueRoom(bool aValue)
{
	myIsTrueRoom = aValue;
}

void Room::Enter(Player & aPlayer)
{
	if (myEnemies->size() > 0)
	{
		Print("You have encountered " + std::to_string(myEnemies->size()) + "enemies!");
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));

		bool tempEnemiesAreAlive = true;
		while (tempEnemiesAreAlive && aPlayer.GetHealth())
		{
			Print("__| Make a choice |__\n[1] Attack\n[2] Flee\n[3] Suicide (confuses the enemy)");

			bool tempLoop = true;
			while (tempLoop)
			{
				switch (GetInput())
				{
					case 1:
					{
						Print("__| Available attacks |__");
						unsigned tempIt = 0;
						for (EAttackTypes tempAtkType : aPlayer.GetAttackTypes())
						{
							tempIt++;
							Print("[" + std::to_string(tempIt) + "] " + aPlayer.AtkTypeToString(tempAtkType));
						}

						int tempIndex = 0; 
						while (GetInput(tempIndex) > aPlayer.GetAttackTypes().size() && tempIndex == 0);
						tempIndex--; // Compensate


						int tempDamageToDeal = 0;
						unsigned tempEnemiesToHitAoE = 0;
						bool tempIsAoE = true;
						switch (aPlayer.GetAttackTypes().at(tempIndex))
						{
						case EAttackTypes::SLASH:
							tempDamageToDeal = aPlayer.GetPhysDmg();
							tempIsAoE = false;
							break;
						case EAttackTypes::SWEEP:
							tempDamageToDeal = aPlayer.GetPhysDmg() / 2;
							break;
						case EAttackTypes::WHIRLWIND:
							tempDamageToDeal = aPlayer.GetPhysDmg() / 3;
							break;
						case EAttackTypes::ICELANCE:
							tempDamageToDeal = aPlayer.GetSpellDmg();
							tempIsAoE = false;
							break;
						case EAttackTypes::COC:
							tempDamageToDeal = aPlayer.GetSpellDmg();
							break;
						case EAttackTypes::BLIZZARD:
							tempDamageToDeal = aPlayer.GetSpellDmg();
							break;
						}

						tempIt = 0;
						std::vector<unsigned> tempIndexes;
						for (Enemy tempEnemy : *myEnemies)
						{
							tempIt++;
							if (tempEnemy.GetHealth())
							{
								tempIndexes.push_back(tempIt);
								Print("[" + std::to_string(tempIt) + "] " + tempEnemy.GetName() + "[HP: " + std::to_string(tempEnemy.GetHealth()) + " Def: " + std::to_string(tempEnemy.GetArmour()) + "]");
							}
						}


						// TODO: Add damage enemy logic


					}
				break;

					case 3:
					{
						aPlayer.TakeDamage(aPlayer.GetHealth());
						Print("You killed yourself and confused the enemy in doing so");
						std::this_thread::sleep_for(std::chrono::seconds(3));
					}
				}
			}
		}
	}
	else
	{
		Print("There are no enemies here");
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}