#include "stdafx.h"
#include "Room.h"
#include "Util.h"
#include "Player.h"
#include <thread>

Room::Room() : myEnemies()
{
}

Room::Room(int aLevel)
{
	int tempEnemies = RNG(0, 4);
	for (size_t i = 0; i < tempEnemies; i++)
	{
		Enemy tempEnemy(aLevel);
		myEnemies.push_back(tempEnemy);
	}
}

Room::~Room()
{
}

void Room::SetEnemies(int & aLevel)
{
	
}

bool Room::Enter(Player & aPlayer)
{
	CLSSlow();
	aPlayer.PrintUI();
	if (myEnemies.size() > 0)
	{
		Print("You have encountered " + std::to_string(myEnemies.size()) + " enemies!");
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));

		bool tempEnemiesAreAlive = true;
		while (tempEnemiesAreAlive && aPlayer.GetHealth() > 1)
		{
			CLSSlow();
			aPlayer.PrintUI();
			Print("__| Make a choice |__\n[1] Attack\n[2] Drink estus flask (Available: " + std::to_string(aPlayer.GetHPPotions()) + ")\n[3] Suicide (confuses the enemy and ends the game)");

			bool tempLoop = true;
			while (tempLoop)
			{
				switch (GetInput())
				{
					case 1:
					{
						CLSSlow();
						aPlayer.PrintUI();
						Print("__| Available attacks |__");
						unsigned tempIt = 0;
						for (EAttackTypes tempAtkType : aPlayer.GetAttackTypes())
						{
							tempIt++;
							Print("[" + std::to_string(tempIt) + "] " + aPlayer.AtkTypeToString(tempAtkType));
						}

						int tempInput = 0; 
						while (GetInput(tempInput) > aPlayer.GetAttackTypes().size() && tempInput == 0);
						tempInput--; // Compensate


						int tempDamageToDeal = 0;
						unsigned tempEnemiesToHitAoE = 0;
						bool tempIsAoE = true;
						switch (aPlayer.GetAttackTypes().at(tempInput))
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

						if (!tempIsAoE)
						{
							CLSSlow();
							aPlayer.PrintUI();
							Print("__| Choose an enemy |__");
							std::vector<unsigned> tempIndexes;
							int tempIt = 0;
							for (unsigned i = 0; i < myEnemies.size(); i++)
							{			
								if (myEnemies.at(i).GetHealth() > 0)
								{
									tempIndexes.push_back(i);
									tempIt++;
									Print("[" + std::to_string(tempIt) + "] " + myEnemies.at(i).GetName() + " [Health: " + std::to_string(myEnemies.at(i).GetHealth()) + " Armour: " + std::to_string(myEnemies.at(i).GetArmour()) + "]");
								}
							}

							tempInput = 0;
							while (GetInput(tempInput) > tempIndexes.size() && tempInput == 0);
							tempInput--; // Compensate

							myEnemies.at(tempIndexes.at(tempInput)).TakeDamage(tempDamageToDeal);

							CLSSlow();
							aPlayer.PrintUI();
							Print("The enemy takes " + std::to_string(tempDamageToDeal - myEnemies.at(tempIndexes.at(tempInput)).GetArmour()) + " damage");
						}
						else
						{
							for (Enemy tempEnemy : myEnemies)
							{
								if (tempEnemy.GetHealth() > 0)
								{
									tempEnemy.TakeDamage(tempDamageToDeal);
								}
							}
							Print("All enemies take " + std::to_string(tempDamageToDeal) + " damage!");
						}
						std::this_thread::sleep_for(std::chrono::milliseconds(1500));

						for (Enemy tempEnemy : myEnemies)
						{
							if (tempEnemy.GetHealth() > 0)
							{
								CLSSlow();
								aPlayer.PrintUI();
								Print("The enemy strikes!\n");
								std::this_thread::sleep_for(std::chrono::seconds(1));
								aPlayer.TakeDamage(tempEnemy.GetDamage());
							}
						}

						tempLoop = false;
					}
				break;

					case 3:
					{
						CLSSlow();
						aPlayer.PrintUI();
						aPlayer.TakeDamage(aPlayer.GetHealth() + aPlayer.GetArmour());
						CLSSlow();
						aPlayer.PrintUI();
						Print("You killed yourself and confused the enemy in doing so.");
						std::this_thread::sleep_for(std::chrono::seconds(3));
						tempLoop = false;
					}
				}
			}

			tempEnemiesAreAlive = false;
			for (Enemy tempEnemy : myEnemies)
			{
				if (tempEnemy.GetHealth() > 0)
				{
					tempEnemiesAreAlive = true;
				}
			}
		}

		if (aPlayer.GetHealth() <= 0)
		{
			return false;
		}

		if (!tempEnemiesAreAlive)
		{
			CLSSlow();
			aPlayer.PrintUI();
			Print("All enemies defeated!");
			std::this_thread::sleep_for(std::chrono::seconds(1));

			int tempXP = static_cast<int>(myEnemies.size()) * 5 * aPlayer.GetLevel();
			CLSSlow();
			aPlayer.PrintUI();
			Print(std::to_string(tempXP) + " experience gained!");
			std::this_thread::sleep_for(std::chrono::seconds(1));
			aPlayer.AddExp(tempXP);

			for (size_t i = 0; i < myEnemies.size(); i++)
			{
				int tempGold = RNG(0, 10) * 5;
				if (tempGold != 0)
				{
					aPlayer.AddGold(tempGold);
					CLSSlow();
					aPlayer.PrintUI();
					Print("You found " + std::to_string(tempGold) + " on one of the corpses!");
					std::this_thread::sleep_for(std::chrono::seconds(1));
				}
			}

			if (RNG(0, 10) > 9)
			{
				aPlayer.AddRandomItem();
				CLSSlow();
				aPlayer.PrintUI();
				Print("You have found an item!");
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}

			myEnemies.clear();
		}
	}
	else
	{
		Print("There are no enemies here");
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return true;
}