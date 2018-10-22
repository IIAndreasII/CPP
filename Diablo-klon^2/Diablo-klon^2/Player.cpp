#include "stdafx.h"
#include "Player.h"
#include "Util.h"
#include <thread>
#include "Item.h"

Player::Player() : 
	myItems(new std::vector<Item*>()), 
	myAttackTypes(new std::vector<EAttackTypes>()), 
	myCharms(new std::vector<ECharmType>()), 
	mySword(0), 
	myStaff(1), 
	myArmour(2), 
	myRingRight(3), 
	myRingLeft(4), 
	myGold(50), 
	myHealthMax(100),
	myHPPotions(5),
	myLevel(1)
{
	/* Basic attack types */
	myAttackTypes->push_back(EAttackTypes::SLASH);
	myAttackTypes->push_back(EAttackTypes::ICELANCE);

	/* Add starting items */
	myItems->push_back(new Item("Sharp thing", 15, EItemType::SWORD, true));
	myItems->push_back(new Item("Wooden stick-thing", 15, EItemType::STAFF, true));
	myItems->push_back(new Item("Flat thing", 2, EItemType::ARMOUR, true));
	myItems->push_back(new Item("Round thing", 0, EItemType::RING, true));
	myItems->push_back(new Item("Circular thing", 0, EItemType::RING, true));

	/* Test dummy */
	myItems->push_back(new Item("Sharp potato", 10, EItemType::SWORD, false));

	myHealth = myHealthMax;
}

Player::~Player()
{
	SafeDelete(myCharms);
	SafeDelete(myItems);
	SafeDelete(myAttackTypes);
}

int& Player::GetHealth()
{
	return myHealth;
}

int & Player::GetArmour()
{
	return myItems->at(myArmour)->GetStat();
}

void Player::ShowInventory()
{
	bool tempLoop = true;
	while (tempLoop)
	{
		CLSSlow();
		PrintUI();
		Print("__| Inventory |__\n[] Gold: " + std::to_string(myGold) + "\n[] Health Potions: " + std::to_string(myHPPotions) +
			"\n\n___| Equipment |___\n[1] Sword: " + myItems->at(mySword)->GetName() + " [Attack: " + std::to_string(myItems->at(mySword)->GetStat()) + "  Level: " + std::to_string(myItems->at(mySword)->GetLevel()) + 
			"]\n[2] Staff: " + myItems->at(myStaff)->GetName() + " [Attack: " + std::to_string(myItems->at(myStaff)->GetStat()) + "  Level: " + std::to_string(myItems->at(myStaff)->GetLevel()) + 
			"]\n[3] Armour: " + myItems->at(myArmour)->GetName() + " [Defence: " + std::to_string(GetArmour()) + "  Level: " + std::to_string(myItems->at(mySword)->GetLevel()) + 
			"]\n[4] R Ring: " + myItems->at(myRingRight)->GetName() + " [" + myItems->at(myRingRight)->GetRingTypeToString() + "  Stat: " + std::to_string(myItems->at(myRingRight)->GetStat()) + "  Level: " + std::to_string(myItems->at(myRingRight)->GetLevel()) +
			"]\n[5] L Ring: " + myItems->at(myRingLeft)->GetName() + " [" + myItems->at(myRingLeft)->GetRingTypeToString() + " Stat: " + std::to_string(myItems->at(myRingLeft)->GetStat()) + "  Level: " + std::to_string(myItems->at(myRingRight)->GetLevel()) +
			"]\n[6] Back");

		EItemType tempItemType = EItemType::SWORD;
		bool tempIsRight = true;
		switch (GetInput())
		{
		case 1:
			tempItemType = EItemType::SWORD;
			break;
		case 2:
			tempItemType = EItemType::STAFF;
			break;
		case 3:
			tempItemType = EItemType::ARMOUR;
			break;
		case 4:
			tempItemType = EItemType::RING;
			tempIsRight = true;
			break;
		case 5:
			tempItemType = EItemType::RING;
			tempIsRight = false;
			break;
		case 6:
			tempLoop = false;
			break;
		}
		if (tempLoop)
		{
			ChangeEquipment(tempItemType, tempIsRight);
		}
	}
}

void Player::LongRest()
{
	CLSSlow();
	PrintUI();
	myHealth = myHealthMax;
	Print("You take a nap beside the campfire");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Print("Health restored!");
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
}

void Player::AddAttackType(EAttackTypes anAttack)
{
	if (!(std::find(myAttackTypes->begin(), myAttackTypes->end(), anAttack) != myAttackTypes->end()))
	{
		myAttackTypes->push_back(anAttack);
	}
}

std::vector<EAttackTypes>& Player::GetAttackTypes()
{
	return *myAttackTypes;
}

std::string Player::AtkTypeToString(EAttackTypes &anAtkType)
{
	switch (anAtkType)
	{
	case EAttackTypes::SLASH:
		return "Slash";
	case EAttackTypes::SWEEP:
		return "Sweep";
	case EAttackTypes::WHIRLWIND:
		return "Whirlwind";
	case EAttackTypes::ICELANCE:
		return "Icelance";
	case EAttackTypes::COC:
		return "Cone of Cold";
	case EAttackTypes::BLIZZARD:
		return "Blizzard";
	}
	return std::string();
}

std::string Player::CharmTypeToString(ECharmType &aCharmType)
{
	switch (aCharmType)
	{
	case ECharmType::HEALTH:
		return "Vitality-charm";
	case ECharmType::PROTECTION:
		return "Protection-charm";
	case ECharmType::STUN:
		return "Stun-charm";
	case ECharmType::VENOM:
		return "Venom-charm";
	}
	return std::string();
}

void Player::AddGold(int someGold)
{
	myGold += someGold;
}

void Player::AddExp(int someExp)
{
	myEXP += someExp;
	if (myEXP >= myEXPRequired)
	{
		myEXP -= myEXPRequired;
		myLevel += 1;
		myHealthMax += 10;
		myHealth = myHealthMax;
		myEXPRequired *= 2;
		myStrength += 5;
		myIntelligence += 5;
		
		CLSSlow();
		PrintUI();
		Print("Level up!");
		std::this_thread::sleep_for(std::chrono::seconds(1));

		if (myLevel == 5 || myLevel == 10)
		{
			CLSSlow();
			PrintUI();
			Print("New attacktypes available in the shop!");
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
}

unsigned Player::GetLevel() const
{
	return myLevel;
}

void Player::TakeDamage(int& aDamageToTake)
{
	int tempDamageTaken = aDamageToTake - GetArmour();
	myHealth -= tempDamageTaken;
	Print("You take " + std::to_string(tempDamageTaken) + " damage!");
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	if (myHealth <= 0)
	{
		CLSSlow();
		PrintUI();
		Print("YOU DIED!");
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}

void Player::TakeDamage(int aDamageToTake)
{
	int tempDamageTaken = aDamageToTake - GetArmour();
	if (tempDamageTaken < 0)
	{
		tempDamageTaken = 0;
	}
	myHealth -= tempDamageTaken;
	
	Print("You take " + std::to_string(tempDamageTaken) + " damage!");
	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	if (myHealth <= 0)
	{
		CLSSlow();
		PrintUI();
		Print("YOU DIED");
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}

void Player::PrintUI()
{
	std::string tempStringToPrint = "Health: " + std::to_string(myHealth) + "  Armour: " + std::to_string(GetArmour()) + "  Strength: +" + std::to_string(myStrength) + "  Intelligence: +" + std::to_string(myIntelligence) + " |";
	std::string tempUnderline;

	for (size_t i = 0; i < tempStringToPrint.size(); i++)
	{
		if (i == tempStringToPrint.size() - 1)
		{
			tempUnderline += '|';
		}
		else
		{
			tempUnderline += '_';
		}
	}
	Print(tempStringToPrint + "\n" + tempUnderline + "\n");

}

void Player::Reset()
{
	myHealthMax = 100;
	myHealth = myHealthMax;
	myStrength = 0;
	myIntelligence = 0;
	myLevel = 1;
	myEXP = 0;
	myEXPRequired = 20;
	myGold = 50;
	myHPPotions = 5;

	myItems->clear();
	myAttackTypes->clear();

	/* Basic attack types */
	myAttackTypes->push_back(EAttackTypes::SLASH);
	myAttackTypes->push_back(EAttackTypes::ICELANCE);

	/* Add starting items */
	myItems->push_back(new Item("Sharp thing", 15, EItemType::SWORD, true));
	myItems->push_back(new Item("Wooden stick-thing", 15, EItemType::STAFF, true));
	myItems->push_back(new Item("Flat thing", 2, EItemType::ARMOUR, true));
	myItems->push_back(new Item("Round thing", 0, EItemType::RING, true));
	myItems->push_back(new Item("Circular thing", 0, EItemType::RING, true));

	/* Test dummy */
	myItems->push_back(new Item("Sharp potato", 10, EItemType::SWORD, false));
}

int& Player::GetPhysDmg()
{
	myPhysDmg = myItems->at(mySword)->GetStat() + myStrength;
	return myPhysDmg;
}

int& Player::GetSpellDmg()
{
	mySpellDmg = myItems->at(myStaff)->GetStat() + myIntelligence;
	return mySpellDmg;
}

unsigned & Player::GetHPPotions()
{
	return myHPPotions;
}

void Player::DrinkPotion()
{
	myHealth += myHealthMax / 2;
	if (myHealth > myHealthMax)
	{
		myHealth = myHealthMax;
	}
}

void Player::AddRandomItem()
{
	myItems->push_back(new Item(myLevel));
}

void Player::ChangeEquipment(EItemType anItemType, bool &isRight)
{
	std::vector<int> tempIndexes;

	Print("__| Available items |__");

	int tempIt = 0;
	for (unsigned i = 0; i < myItems->size(); i++)
	{
		if (myItems->at(i)->GetItemType() == anItemType && !myItems->at(i)->GetIsEquipped())
		{
			tempIt++;
			tempIndexes.push_back(i);
			Print("[" + std::to_string(tempIt) + "] " + myItems->at(i)->GetName() + " [Lvl: " + std::to_string(myItems->at(i)->GetLevel()) + " Stat: " + std::to_string(myItems->at(i)->GetStat()) + "]");
		}
	}

	if (tempIndexes.size() == 0)
	{
		Print("No available items");
	}
	else
	{
		int tempInput = 0,
			tempConfirmInput = 0;

		while (GetInput(tempInput) > tempIndexes.size() && tempInput == 0);

		Print("[1] Equip  [2] Throw away  [3] Combine w/ equipped (" + std::to_string(50 * myItems->at(tempIndexes.at(tempInput - 1))->GetLevel()) + " gold) [4] Cancel");

		while (GetInput(tempConfirmInput) > 2 && tempConfirmInput == 0);

		switch (tempConfirmInput)
		{
		case 1:
			switch (anItemType)
			{
			case EItemType::SWORD:
				myItems->at(mySword)->SetIsEquipped(false);
				mySword = tempIndexes.at(tempInput - 1);
				myItems->at(mySword)->SetIsEquipped(true);
				break;
			case EItemType::STAFF:
				myItems->at(myStaff)->SetIsEquipped(false);
				myStaff = tempIndexes.at(tempInput - 1);
				myItems->at(myStaff)->SetIsEquipped(true);
				break;
			case EItemType::ARMOUR:
				myItems->at(myArmour)->SetIsEquipped(false);
				myArmour = tempIndexes.at(tempInput - 1);
				myItems->at(myArmour)->SetIsEquipped(true);
				break;
			case EItemType::RING:
				if (isRight)
				{
					myItems->at(myRingRight)->SetIsEquipped(false);
					myRingRight = tempIndexes.at(tempInput - 1);
					myItems->at(myRingRight)->SetIsEquipped(true);
				}
				else
				{
					myItems->at(myRingLeft)->SetIsEquipped(false);
					myRingLeft = tempIndexes.at(tempInput - 1);
					myItems->at(myRingLeft)->SetIsEquipped(true);
				}
				break;
			}
			break;
		case 2:
			myItems->erase(myItems->begin() + (tempIndexes.at(tempInput - 1)));
			break;
		case 3:
			if (myGold - 50 * myItems->at(tempIndexes.at(tempInput - 1))->GetLevel() >= 0)
			{
				myGold -= 50 * myItems->at(tempIndexes.at(tempInput - 1))->GetLevel();
				switch (anItemType)
				{
				case EItemType::SWORD:
					myItems->at(mySword)->Combine(*myItems->at(tempIndexes.at(tempInput - 1)));
					myItems->erase(myItems->begin() + tempIndexes.at(tempInput - 1));
					break;
				case EItemType::STAFF:
					myItems->at(myStaff)->Combine(*myItems->at(tempIndexes.at(tempInput - 1)));
					myItems->erase(myItems->begin() + tempIndexes.at(tempInput - 1));
					break;
				case EItemType::ARMOUR:
					myItems->at(myArmour)->Combine(*myItems->at(tempIndexes.at(tempInput - 1)));
					myItems->erase(myItems->begin() + tempIndexes.at(tempInput - 1));
					break;
				case EItemType::RING:
					if (isRight)
					{
						myItems->at(myRingRight)->Combine(*myItems->at(tempIndexes.at(tempInput - 1)));
						myItems->erase(myItems->begin() + tempIndexes.at(tempInput - 1));
					}
					else
					{
						myItems->at(myRingLeft)->Combine(*myItems->at(tempIndexes.at(tempInput - 1)));
						myItems->erase(myItems->begin() + tempIndexes.at(tempInput - 1));
					}
					break;
				}
			}
		}
	}
}