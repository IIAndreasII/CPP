#include "stdafx.h"
#include "Room.h"
#include "Util.h"
#include "Player.h"
#include <thread>

Room::Room() :
	myEnemies()
{
}

Room::Room(uint16_t aLevel) :
	myEnemies()
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
			bool tempLoop = true;
			while (tempLoop)
			{
				CLSSlow();
				aPlayer.PrintUI();
				Print("__| Make a choice |__\n[1] Attack\n[2] Drink estus flask (Available: " + std::to_string(aPlayer.GetHPPotions()) + ")\n[3] Preview enemies\n[4] Suicide (confuses the enemy)");

				switch (GetInput())
				{
				case 1:
				{
					CLSSlow();
					aPlayer.PrintUI();
					Print("__| Available attacks |__");
					unsigned tempIt = 0;
					for (EAttackType tempAtkType : aPlayer.GetAttackTypes())
					{
						tempIt++;
						Print("[" + std::to_string(tempIt) + "] " + aPlayer.AtkTypeToString(tempAtkType));
					}

					int tempInput = 0;
					while (GetInput(tempInput) > aPlayer.GetAttackTypes().size());
					tempInput--; // Compensate

					int tempDamageToDeal = 0;
					bool tempIsAoE = true;
					EDamageType tempDamageType = EDamageType::PHYSICAL;
					switch (aPlayer.GetAttackTypes().at(tempInput))
					{
					case EAttackType::SLASH:
						tempDamageToDeal = aPlayer.GetPhysDmg();
						tempIsAoE = false;
						break;
					case EAttackType::SWEEP:
						tempDamageToDeal = aPlayer.GetPhysDmg() / 4;
						break;
					case EAttackType::WHIRLWIND:
						tempDamageToDeal = aPlayer.GetPhysDmg() / 2;
						break;
					case EAttackType::ICELANCE:
						tempDamageToDeal = aPlayer.GetSpellDmg();
						tempIsAoE = false;
						tempDamageType = EDamageType::MAGICAL;
						break;
					case EAttackType::COC:
						tempDamageToDeal = aPlayer.GetSpellDmg() / 4;
						tempDamageType = EDamageType::MAGICAL;
						break;
					case EAttackType::BLIZZARD:
						tempDamageToDeal = aPlayer.GetSpellDmg() / 2;
						tempDamageType = EDamageType::MAGICAL;
						break;
					}

					if (!tempIsAoE)
					{
						CLSSlow();
						aPlayer.PrintUI();
						Print("__| Choose an enemy |__");

						int tempIt = 0;
						std::vector<unsigned> tempIndexes;
						for (unsigned i = 0; i < myEnemies.size(); i++)
						{
							if (myEnemies.at(i).GetHealth() > 0)
							{
								tempIt++;
								tempIndexes.push_back(i);
								Print("[" + std::to_string(tempIt) + "] " + myEnemies.at(i).GetName() + " [Health: " + std::to_string(myEnemies.at(i).GetHealth()) + " Armour: " + std::to_string(myEnemies.at(i).GetArmour()) + "]");
							}
						}

						tempInput = 0;
						while (GetInput(tempInput) > tempIndexes.size() && tempInput == 0);
						tempInput--; // Compensate

						CLSSlow();
						aPlayer.PrintUI();
						myEnemies.at(tempIndexes.at(tempInput)).TakeDamage(tempDamageToDeal, tempDamageType);
						if (myEnemies.at(tempIndexes.at(tempInput)).GetHealth() <= 0)
						{
							Print("\n" + myEnemies.at(tempIndexes.at(tempInput)).GetName() + " enemy has perished!");
							std::this_thread::sleep_for(std::chrono::milliseconds(1500));
						}
					}
					else
					{
						for (size_t i = 0; i < myEnemies.size(); i++)
						{
							if (myEnemies.at(i).GetHealth() > 0)
							{
								myEnemies.at(i).TakeDamage(tempDamageToDeal, tempDamageType);
								if (myEnemies.at(i).GetHealth() <= 0)
								{
									Print("\n" + myEnemies.at(i).GetName() + " has perished!");
									std::this_thread::sleep_for(std::chrono::milliseconds(1500));
								}
							}
						}
					}

					for (Enemy tempEnemy : myEnemies)
					{
						if (tempEnemy.GetHealth() > 0)
						{
							CLSSlow();
							aPlayer.PrintUI();
							Print("The enemy strikes!\n");
							std::this_thread::sleep_for(std::chrono::seconds(1));
							aPlayer.TakeDamage(tempEnemy.GetDamage(), tempEnemy.GetDamageType());
						}
					}

					tempLoop = false;
					break;
				}
				case 2:
				{
					CLSSlow();
					aPlayer.PrintUI();
					Print("___| Enemies |___");
					for (unsigned i = 0; i < myEnemies.size(); i++)
					{
						if (myEnemies.at(i).GetHealth() > 0)
						{
							Print("[" + std::to_string(i + 1) + "] " + myEnemies.at(i).GetName() + " [Health: " + std::to_string(myEnemies.at(i).GetHealth()) + " Armour: " + std::to_string(myEnemies.at(i).GetArmour()) + "]");
						}
					}
					Print("[Any key] Back");

					switch (GetInput())
					{
					default:
						break;
					}
					break;
				}
				case 3:
				{
					if (aPlayer.GetHPPotions() > 0)
					{
						aPlayer.DrinkPotion();
					}
					break;
				}
				case 4:
				{
					aPlayer.SetIntel(-100);
					CLSSlow();
					aPlayer.PrintUI();
					aPlayer.TakeDamage(aPlayer.GetHealth() + aPlayer.GetArmour(), EDamageType::PHYSICAL);
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
				int tempGold = RNG(0, 6) * 5;
				if (tempGold != 0)
				{
					aPlayer.AddGold(tempGold);
					CLSSlow();
					aPlayer.PrintUI();
					Print("You found " + std::to_string(tempGold) + " gold on one of the corpses!");
					std::this_thread::sleep_for(std::chrono::milliseconds(1500));
				}
			}

			if (RNG(0, 10) > 3)
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