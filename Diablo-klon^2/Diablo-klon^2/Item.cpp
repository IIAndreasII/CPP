#include "stdafx.h"
#include "Item.h"
#include "Util.h"

Item::Item() : myLevel(1), myIsEquipped(false)
{
}

Item::Item(uint16_t aLevel) : myLevel(aLevel), myIsEquipped(false)
{
	myStat = RNG(5, 10) * aLevel;
	switch (RNG(0, 4))
	{
	case 0:
		myItemType = EItemType::SWORD;
		break;
	case 1:
		myItemType = EItemType::STAFF;
		break;
	case 2:
		myItemType = EItemType::ARMOUR;
		break;
	case 3:
		myItemType = EItemType::SPELLARMOUR;
		break;
	case 4:
		myItemType = EItemType::RING;

		switch (RNG(0, 3))
		{
		case 0:
			myRingType = ERingType::DEFENCE;
			break;
		case 1:
			myRingType = ERingType::INTELLIGENCE;
			break;
		case 2:
			myRingType = ERingType::STRENGTH;
			break;
		case 3:
			myRingType = ERingType::VITALITY;
		}

		break;
	}

	std::vector<std::string> tempNames = { "of silliness", " of stupidity", " of peanutbutter", " of Neverwinter", " of Waterdeep", " of evil", " of Korn", " of Thor", " of jelly" };
	myName = ItemTypeToString(myItemType) + tempNames.at(RNG(0, static_cast<int>(tempNames.size()) - 1));
}

Item::Item(std::string aName, uint16_t aStat, EItemType anItemType) : myName(aName), myStat(aStat), myItemType(anItemType), myLevel(1)
{
}

Item::Item(std::string aName, uint16_t aStat, EItemType anItemType, bool isEquipped) : myName(aName), myStat(aStat), myItemType(anItemType), myIsEquipped(isEquipped), myLevel(1)
{
	if (myItemType == EItemType::RING)
	{
		switch (RNG(0, 3))
		{
		case 0:
			myRingType = ERingType::DEFENCE;
			break;
		case 1:
			myRingType = ERingType::INTELLIGENCE;
			break;
		case 2:
			myRingType = ERingType::STRENGTH;
			break;
		case 3:
			myRingType = ERingType::VITALITY;
			break;
		}
	}
	else
	{
		myRingType = ERingType::NOT_A_RING;
	}
}

Item::~Item()
{
}

std::string Item::GetName() const
{
	return myName;
}

EItemType Item::GetItemType() const
{
	return myItemType;
}

ERingType Item::GetRingType() const
{
	return myRingType;
}

std::string Item::GetRingTypeToString() const
{
	std::string tempReturnValue;
	switch (myRingType)
	{
	case ERingType::NOT_A_RING:
		tempReturnValue = "ERROR";
		break;
	case ERingType::DEFENCE:
		tempReturnValue = "Defence";
		break;
	case ERingType::INTELLIGENCE:
		tempReturnValue = "Intelligence";
		break;
	case ERingType::STRENGTH:
		tempReturnValue = "Strength";
		break;
	case ERingType::VITALITY:
		tempReturnValue = "Vitality";
		break;
	}
	return tempReturnValue;
}

uint16_t Item::GetLevel() const
{
	return myLevel;
}

uint16_t Item::GetStat() const
{
	return myStat;
}

void Item::SetIsEquipped(bool aValue)
{
	myIsEquipped = aValue;
}

void Item::Combine(Item* anItem)
{
	myName = "Combined " + myName;
	myStat += anItem->GetStat();
	myLevel += 1;
}

bool& Item::GetIsEquipped()
{
	return myIsEquipped;
}

std::string Item::ItemTypeToString(EItemType & aType)
{
	switch (aType)
	{
	case EItemType::SWORD:
		return "Sword";
	case EItemType::STAFF:
		return "Staff";
	case EItemType::ARMOUR:
		return "Armour";
	case EItemType::RING:
		return "Ring";
	}
	return std::string();
}