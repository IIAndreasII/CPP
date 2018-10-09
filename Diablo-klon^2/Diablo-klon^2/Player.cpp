#include "stdafx.h"
#include "Player.h"
#include "Util.h"

Item tempSword("Sharp thing", 10, EItemType::SWORD, true);
Item tempStaff("Wooden stick-thing", 10, EItemType::STAFF, true);
Item tempArmour("Flat thing", 10, EItemType::ARMOUR, true);
Item tempRing("Round thing", 0, EItemType::RING, true);
Item tempRing2("Circular thing", 0, EItemType::RING, true);

Player::Player() : myItems(), myAttackTypes(), mySword(tempSword), myStaff(tempStaff), myArmour(tempArmour), myRingRight(tempRing), myRingLeft(tempRing2)
{
	myAttackTypes.push_back(EAttackTypes::SLASH);
	myAttackTypes.push_back(EAttackTypes::ICELANCE);

	myItems.push_back(tempSword);
	myItems.push_back(tempStaff);
	myItems.push_back(tempArmour);
	myItems.push_back(tempRing);
	myItems.push_back(tempRing2);

	mySword = myItems.at(0);
	myStaff = myItems.at(1);
	myArmour = myItems.at(2);
	myRingRight = myItems.at(3);
	myRingLeft = myItems.at(4);

}

Player::~Player()
{
}

int& Player::GetHealth()
{
	return myHealth;
}

int& Player::GetArmour()
{
	return myArmour.GetStat();
}

int& Player::GetAttack()
{
	return mySword.GetStat();
}

void Player::ShowInventory()
{
	bool tempLoop = true;

	while (tempLoop)
	{
		CLSSlow();
		WriteLine("__| Inventory |__\n[] Gold: " + std::to_string(myGold) + "\n[] Health Potions: " + std::to_string(myHPPotions) +
			"\n\n___| Equipment |___\n[1] Sword: " + mySword.GetName() + " [Atk: " + std::to_string(mySword.GetStat()) +
			"]\n[2] Staff: " + myStaff.GetName() + " [Atk: " + std::to_string(myStaff.GetStat()) +
			"]\n[3] Armour: " + myArmour.GetName() + " [Def: " + std::to_string(myArmour.GetStat()) +
			"]\n[4] Righthand Ring: " + myRingRight.GetName() + " [" + myRingRight.GetRingType() + ": " + std::to_string(myRingRight.GetStat()) +
			"]\n[5] Lefthand Ring: " + myRingLeft.GetName() + " [" + myRingLeft.GetRingType() + ": " + std::to_string(myRingRight.GetStat()) + 
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

	for (size_t i = 0; i < myItems.size(); i++)
	{
		if (myItems.at(i).GetItemType() == anItemType && !myItems.at(i).GetIsEquipped())
		{
			tempIndexes.push_back(i);
			WriteLine("[" + std::to_string(i) + "] " + myItems.at(i).GetName() + " [Lvl: " + std::to_string(myItems.at(i).GetLevel()) + " Stat: " + std::to_string(myItems.at(i).GetStat()) + "]");
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

		while (GetInput(tempInput) > tempIndexes.size() + 1);

		WriteLine("[1] Equip [2] Throw away [3] Cancel");

		while (GetInput(tempConfirmInput) > 3);

		switch (tempConfirmInput)
		{
		case 1:
			switch (anItemType)
			{
			case EItemType::SWORD:
				mySword.SetIsEquipped(false);
				mySword = myItems.at(tempIndexes.at(tempInput));
				mySword.SetIsEquipped(true);
				break;
			case EItemType::STAFF:
				myStaff.SetIsEquipped(false);
				myStaff = myItems.at(tempIndexes.at(tempInput));
				myStaff.SetIsEquipped(true);
				break;
			case EItemType::ARMOUR:
				myArmour.SetIsEquipped(false);
				myArmour = myItems.at(tempIndexes.at(tempInput));
				myArmour.SetIsEquipped(true);
				break;
			case EItemType::RING:
				if (isRight)
				{
					myRingRight.SetIsEquipped(false);
					myRingRight = myItems.at(tempIndexes.at(tempInput));
					myRingRight.SetIsEquipped(true);
				}
				else
				{
					myRingLeft.SetIsEquipped(false);
					myRingLeft = myItems.at(tempIndexes.at(tempInput));
					myRingLeft.SetIsEquipped(true);
				}
				break;
			}
			break;
		case 2:
			myItems.erase(myItems.begin() + tempIndexes.at(tempInput) - 1);
			break;
		}
	}
}
