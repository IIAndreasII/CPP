#include "stdafx.h"
#include "Player.h"
#include "Util.h"
#include <thread>
#include "Item.h"

Player::Player() :
	myItems(new std::vector<Item*>()),
	myAttackTypes(),
	myGold(50),
	myHealthMax(100),
	myHPPotions(5),
	myLevel(1),
	myIntelligenceMod(0),
	myStrengthMod(0),
	myDefenceMod(0),
	myHealthMod(0)
{
	Init();
}

Player::~Player()
{
	SafeDelete(mySword);
	SafeDelete(myStaff);
	SafeDelete(myArmour);
	SafeDelete(mySpellArmour);
	SafeDelete(myRingLeft);
	SafeDelete(myRingRight);
	
	for (Item* it : *myItems)
	{
		SafeDelete(it);
	}
	myItems->clear();
	SafeDelete(myItems);
}

int Player::GetHealth() const
{
	return myHealth;
}

uint16_t Player::GetArmour() const
{
	return myArmour->GetStat() + myDefenceMod;
}

uint16_t Player::GetSpellArmour() const
{
	return mySpellArmour->GetStat() + myDefenceMod;
}

void Player::ShowInventory()
{
	bool tempLoop = true;
	while (tempLoop)
	{
		CLSSlow();
		PrintUI();
		Print("__| Inventory |__\n[] Gold: " + std::to_string(myGold) + "\n[] Health Potions: " + std::to_string(myHPPotions) +
			"\n\n___| Equipment |___\n[1] Sword: " + mySword->GetName() + " [Attack: " + std::to_string(mySword->GetStat()) + ", Level: " + std::to_string(mySword->GetLevel()) +
			"]\n[2] Staff: " + myStaff->GetName() + " [Attack: " + std::to_string(myStaff->GetStat()) + ", Level: " + std::to_string(myStaff->GetLevel()) +
			"]\n[3] Armour: " + myArmour->GetName() + " [Defence: " + std::to_string(GetArmour()) + ", Level: " + std::to_string(myArmour->GetLevel()) +
			"]\n[4] Spellarmour: " + mySpellArmour->GetName() + " [Defence: " + std::to_string(GetSpellArmour()) + ", Level: " + std::to_string(mySpellArmour->GetLevel()) +
			"]\n[5] R Ring: " + myRingRight->GetName() + " [Type: " + myRingRight->GetRingTypeToString() + ", Stat: " + std::to_string(myRingRight->GetStat()) + ", Level: " + std::to_string(myRingRight->GetLevel()) +
			"]\n[6] L Ring: " + myRingLeft->GetName() + " [Type: " + myRingLeft->GetRingTypeToString() + ", Stat: " + std::to_string(myRingLeft->GetStat()) + ", Level: " + std::to_string(myRingRight->GetLevel()) +
			"]\n[7] Back");

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
			tempItemType = EItemType::SPELLARMOUR;
			break;
		case 5:
			tempItemType = EItemType::RING;
			tempIsRight = true;
			break;
		case 6:
			tempItemType = EItemType::RING;
			tempIsRight = false;
			break;
		case 7:
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
	myHealth = myHealthMax + myHealthMod;
	Print("You take a nap beside the campfire");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Print("Health restored!");
	std::this_thread::sleep_for(std::chrono::milliseconds(750));
}

void Player::AddAttackType(EAttackType anAttack)
{
	if (!(std::find(myAttackTypes.begin(), myAttackTypes.end(), anAttack) != myAttackTypes.end()))
	{
		myAttackTypes.push_back(anAttack);
	}
}

std::vector<EAttackType>& Player::GetAttackTypes()
{
	return myAttackTypes;
}

std::string Player::AtkTypeToString(EAttackType &anAtkType)
{
	switch (anAtkType)
	{
	case EAttackType::SLASH:
		return "Slash";
	case EAttackType::SWEEP:
		return "Sweep";
	case EAttackType::WHIRLWIND:
		return "Whirlwind";
	case EAttackType::ICELANCE:
		return "Icelance";
	case EAttackType::COC:
		return "Cone of Cold";
	case EAttackType::BLIZZARD:
		return "Blizzard";
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

uint16_t Player::GetLevel() const
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

void Player::TakeDamage(int aDamageToTake, EDamageType aDmgType)
{
	int tempDamageTaken = 0;
	switch (aDmgType)
	{
	case EDamageType::MAGICAL:
		tempDamageTaken = aDamageToTake - GetSpellArmour();
		break;
	case EDamageType::PHYSICAL:
		tempDamageTaken = aDamageToTake - GetArmour();
		break;
	}

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
		Print("YOU DIED!");
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}

void Player::PrintUI()
{
	std::string tempStringToPrint = "Health: " + std::to_string(myHealth) + "  Armour: " + std::to_string(GetArmour() + myDefenceMod) + "  Spellarmour: " + std::to_string(GetSpellArmour() + myDefenceMod) + "  Strength: " + std::to_string(myStrength + myStrengthMod) + "  Intelligence: " + std::to_string(myIntelligence + myIntelligenceMod) + " |";
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

void Player::Init()
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

	myIntelligenceMod = 0;
	myStrengthMod = 0;
	myDefenceMod = 0;
	myHealthMod = 0;

	myItems->clear();
	myAttackTypes.clear();

	/* Basic attack types */
	myAttackTypes.push_back(EAttackType::SLASH);
	myAttackTypes.push_back(EAttackType::ICELANCE);

	/* Add starting items */
	myItems->push_back(new Item("Sharp thing", 15, EItemType::SWORD, true));
	myItems->push_back(new Item("Wooden stick-thing", 15, EItemType::STAFF, true));
	myItems->push_back(new Item("Flat thing", 2, EItemType::ARMOUR, true));
	myItems->push_back(new Item("Anti-spell thing", 2, EItemType::SPELLARMOUR, true));
	myItems->push_back(new Item("Round thing", 1, EItemType::RING, true));
	myItems->push_back(new Item("Circular thing", 1, EItemType::RING, true));
	
	mySword = myItems->at(0);
	myStaff = myItems->at(1);
	myArmour = myItems->at(2);
	mySpellArmour = myItems->at(3);
	myRingRight = myItems->at(4);
	myRingLeft = myItems->at(5);
	EquipRing(myRingRight);
	EquipRing(myRingLeft);

	/* Test dummies */
	myItems->push_back(new Item("Sharp potato", 10, EItemType::SWORD, false));
	myItems->push_back(new Item("Flat potato", 10, EItemType::ARMOUR, false));
	myItems->push_back(new Item("Anti-spell potato", 3, EItemType::SPELLARMOUR, false));
	myItems->push_back(new Item("Circular thing the second", 5, EItemType::RING, false));
}

uint16_t Player::GetPhysDmg() const
{
	return mySword->GetStat() + myStrength + myStrengthMod;
}

uint16_t Player::GetSpellDmg() const
{
	return myStaff->GetStat() + myIntelligence + myIntelligenceMod;
}

uint16_t Player::GetHPPotions() const
{
	return myHPPotions;
}

void Player::DrinkPotion()
{
	myHPPotions--;
	myHealth += myHealthMax / 2;
	if (myHealth > myHealthMax + myHealthMod)
	{
		myHealth = myHealthMax + myHealthMod;
	}

	CLSSlow();
	PrintUI();
	Print("You drink an estus flask!\n");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Print("Health restored!");
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Player::AddRandomItem()
{
	myItems->push_back(new Item(myLevel));
}

void Player::SetIntel(const int someIntel)
{
	myIntelligence = someIntel;
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
			if (anItemType == EItemType::RING)
			{
				Print("[" + std::to_string(tempIt) + "] " + myItems->at(i)->GetName() + " [Type: " + myItems->at(i)->GetRingTypeToString() + "  Level: " + std::to_string(myItems->at(i)->GetLevel()) + " Stat: " + std::to_string(myItems->at(i)->GetStat()) + "]");
			}
			else
			{
				Print("[" + std::to_string(tempIt) + "] " + myItems->at(i)->GetName() + " [Level: " + std::to_string(myItems->at(i)->GetLevel()) + " Stat: " + std::to_string(myItems->at(i)->GetStat()) + "]");
			}
		}
	}

	if (tempIndexes.size() == 0)
	{
		Print("No available items");
		std::this_thread::sleep_for(std::chrono::seconds(1));
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
				mySword->SetIsEquipped(false);
				mySword = myItems->at(tempIndexes.at(tempInput - 1));
				mySword->SetIsEquipped(true);
				break;
			case EItemType::STAFF:
				myStaff->SetIsEquipped(false);
				myStaff = myItems->at(tempIndexes.at(tempInput - 1));
				myStaff->SetIsEquipped(true);
				break;
			case EItemType::ARMOUR:
				myArmour->SetIsEquipped(false);
				myArmour = myItems->at(tempIndexes.at(tempInput - 1));
				myArmour->SetIsEquipped(true);
				break;
			case EItemType::SPELLARMOUR:
				mySpellArmour->SetIsEquipped(false);
				mySpellArmour = myItems->at(tempIndexes.at(tempInput - 1));
				mySpellArmour->SetIsEquipped(true);
				break;
			case EItemType::RING:
				if (isRight)
				{
					myRingRight->SetIsEquipped(false);
					UnEquipRing(myRingRight);
					myRingRight = myItems->at(tempIndexes.at(tempInput - 1));
					myRingRight->SetIsEquipped(true);
					EquipRing(myRingRight);
				}
				else
				{
					myRingLeft->SetIsEquipped(false);
					UnEquipRing(myRingLeft);
					myRingLeft = myItems->at(tempIndexes.at(tempInput - 1));
					myRingLeft->SetIsEquipped(true);
					EquipRing(myRingLeft);
				}
				break;
			}
			break;
		case 2:
			SafeDelete(myItems->at(tempIndexes.at(tempInput - 1)));
			myItems->erase(myItems->begin() + (tempIndexes.at(tempInput - 1)));
			break;
		case 3:
			int tempAmountToSubtract = 50 * myItems->at(tempIndexes.at(tempInput - 1))->GetLevel();
			if (myGold - tempAmountToSubtract >= 0)
			{
				myGold -= tempAmountToSubtract;
				switch (anItemType)
				{
				case EItemType::SWORD:
					mySword->Combine(myItems->at(tempIndexes.at(tempInput - 1)));
					SafeDelete(myItems->at(tempIndexes.at(tempInput - 1)));
					myItems->erase(myItems->begin() + tempIndexes.at(tempInput - 1));
					break;
				case EItemType::STAFF:
					myStaff->Combine(myItems->at(tempIndexes.at(tempInput - 1)));
					SafeDelete(myItems->at(tempIndexes.at(tempInput - 1)));
					myItems->erase(myItems->begin() + tempIndexes.at(tempInput - 1));
					break;
				case EItemType::ARMOUR:
					myArmour->Combine(myItems->at(tempIndexes.at(tempInput - 1)));
					SafeDelete(myItems->at(tempIndexes.at(tempInput - 1)));
					myItems->erase(myItems->begin() + tempIndexes.at(tempInput - 1));
					break;
				case EItemType::SPELLARMOUR:
					mySpellArmour->Combine(myItems->at(tempIndexes.at(tempInput - 1)));
					SafeDelete(myItems->at(tempIndexes.at(tempInput - 1)));
					myItems->erase(myItems->begin() + tempIndexes.at(tempInput - 1));
					break;
				case EItemType::RING:
					if (isRight)
					{
						myRingRight->Combine(myItems->at(tempIndexes.at(tempInput - 1)));
						SafeDelete(myItems->at(tempIndexes.at(tempInput - 1)));
						myItems->erase(myItems->begin() + tempIndexes.at(tempInput - 1));
					}
					else
					{
						myRingLeft->Combine(myItems->at(tempIndexes.at(tempInput - 1)));
						SafeDelete(myItems->at(tempIndexes.at(tempInput - 1)));
						myItems->erase(myItems->begin() + tempIndexes.at(tempInput - 1));
					}
					break;
				}
			}
		}
	}
}

void Player::EquipRing(Item* aRing)
{
	switch (aRing->GetRingType())
	{
	case ERingType::DEFENCE:
		myDefenceMod += aRing->GetStat();
		break;
	case ERingType::INTELLIGENCE:
		myIntelligenceMod += aRing->GetStat();
		break;
	case ERingType::STRENGTH:
		myStrengthMod += aRing->GetStat();
		break;
	case ERingType::VITALITY:
		myHealth += aRing->GetStat();
		myHealthMod += aRing->GetStat();
		break;
	}
}

void Player::UnEquipRing(Item* aRing)
{
	switch (aRing->GetRingType())
	{
	case ERingType::DEFENCE:
		myDefenceMod -= aRing->GetStat();
		break;
	case ERingType::INTELLIGENCE:
		myIntelligenceMod -= aRing->GetStat();
		break;
	case ERingType::STRENGTH:
		myStrengthMod -= aRing->GetStat();
		break;
	case ERingType::VITALITY:
		myHealth -= aRing->GetStat();
		myHealthMod -= aRing->GetStat();
		break;
	}
}