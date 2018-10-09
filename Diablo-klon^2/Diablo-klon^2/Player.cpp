#include "stdafx.h"
#include "Player.h"
#include "Util.h"


Player::Player() : myItems(), myAttackTypes(), mySword(0), myStaff(1), myArmour(2), myRingRight(3), myRingLeft(4)
{
	myAttackTypes.push_back(EAttackTypes::SLASH);
	myAttackTypes.push_back(EAttackTypes::ICELANCE);

	Item tempSword("Sharp thing", 10, EItemType::SWORD, true);
	Item tempStaff("Wooden stick-thing", 10, EItemType::STAFF, true);
	Item tempArmour("Flat thing", 10, EItemType::ARMOUR, true);
	Item tempRing("Round thing", 0, EItemType::RING, true);
	Item tempRing2("Circular thing", 0, EItemType::RING, true);

	myItems.push_back(tempSword);
	myItems.push_back(tempStaff);
	myItems.push_back(tempArmour);
	myItems.push_back(tempRing);
	myItems.push_back(tempRing2);

	Item tempSword2("Sharp potato", 10, EItemType::SWORD, false);

	myItems.push_back(tempSword2);
	
}

Player::~Player()
{
}

int& Player::GetHealth()
{
	return myHealth;
}


void Player::ShowInventory()
{
	bool tempLoop = true;

	while (tempLoop)
	{
		CLSSlow();
		WriteLine("__| Inventory |__\n[] Gold: " + std::to_string(myGold) + "\n[] Health Potions: " + std::to_string(myHPPotions) +
			"\n\n___| Equipment |___\n[1] Sword: " + myItems.at(mySword).GetName() + " [Atk: " + std::to_string(myItems.at(mySword).GetStat()) +
			"]\n[2] Staff: " + myItems.at(myStaff).GetName() + " [Atk: " + std::to_string(myItems.at(myStaff).GetStat()) +
			"]\n[3] Armour: " + myItems.at(myArmour).GetName() + " [Def: " + std::to_string(myItems.at(myArmour).GetStat()) +
			"]\n[4] Righthand Ring: " + myItems.at(myRingRight).GetName() + " [" + myItems.at(myRingRight).GetRingType() + ": " + std::to_string(myItems.at(myRingRight).GetStat()) +
			"]\n[5] Lefthand Ring: " + myItems.at(myRingLeft).GetName() + " [" + myItems.at(myRingLeft).GetRingType() + ": " + std::to_string(myItems.at(myRingRight).GetStat()) +
			"]\n[6] Back");

		EItemType tempItemType;
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
}

void Player::AddAttackType(EAttackTypes anAttack)
{
	if (!(std::find(myAttackTypes.begin(), myAttackTypes.end(), anAttack) != myAttackTypes.end()))
	{
		myAttackTypes.push_back(anAttack);
	}
}

void Player::LevelUp()
{
	if (myEXP >= myEXPRequired)
	{
		myEXP -= myEXPRequired;
		myLevel += 1;
		myHealthMax += 10;
		myEXPRequired *= 2;
		myStrength += 2;
		myIntelligence += 2;
	}
}

void Player::ChangeEquipment(EItemType anItemType, bool &isRight)
{
	std::vector<int> tempIndexes;

	WriteLine("__| Available items |__");

	int tempIt = 0;
	for (size_t i = 0; i < myItems.size(); i++)
	{
		if (myItems.at(i).GetItemType() == anItemType && !myItems.at(i).GetIsEquipped())
		{
			tempIt++;
			tempIndexes.push_back(i);
			WriteLine("[" + std::to_string(tempIt) + "] " + myItems.at(i).GetName() + " [Lvl: " + std::to_string(myItems.at(i).GetLevel()) + " Stat: " + std::to_string(myItems.at(i).GetStat()) + "]");
		}
	}

	if (tempIndexes.size() <= 0)
	{
		WriteLine("No available items");
	}
	else
	{
		int tempInput = 0;
		int tempConfirmInput = 0;

		while (GetInput(tempInput) > tempIndexes.size());

		WriteLine("[1] Equip [2] Cancel");

		while (GetInput(tempConfirmInput) > 2);


		switch (tempConfirmInput)
		{
		case 1:
			switch (anItemType)
			{
			case EItemType::SWORD:
				myItems.at(mySword).SetIsEquipped(false);
				mySword = tempIndexes.at(tempInput - 1);
				myItems.at(mySword).SetIsEquipped(true);
				break;
			case EItemType::STAFF:
				myItems.at(myStaff).SetIsEquipped(false);
				myStaff = tempIndexes.at(tempInput - 1);
				myItems.at(myStaff).SetIsEquipped(true);
				break;
			case EItemType::ARMOUR:
				myItems.at(myArmour).SetIsEquipped(false);
				myArmour = tempIndexes.at(tempInput - 1);
				myItems.at(myArmour).SetIsEquipped(true);
				break;
			case EItemType::RING:
				if (isRight)
				{
					myItems.at(myRingRight).SetIsEquipped(false);
					myRingRight = tempIndexes.at(tempInput - 1);
					myItems.at(myRingRight).SetIsEquipped(true);
				}
				else
				{
					myItems.at(myRingLeft).SetIsEquipped(false);
					myRingLeft = tempIndexes.at(tempInput - 1);
					myItems.at(myRingLeft).SetIsEquipped(true);
				}
				break;
			}
			break;
		}
	}
}
