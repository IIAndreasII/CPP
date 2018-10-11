#include "stdafx.h"
#include "Item.h"

Item::Item() : myLevel(), myIsEquipped(false)
{
}

Item::Item(int aLevel) : myLevel(aLevel), myIsEquipped(false)
{
}

Item::Item(std::string aName, int aStat, EItemType anItemType) : myName(aName), myStat(aStat), myItemType(anItemType)
{
}

Item::Item(std::string aName, int aStat, EItemType anItemType, bool isEquipped) : myName(aName), myStat(aStat), myItemType(anItemType), myIsEquipped(isEquipped)
{
}

Item::~Item()
{
}

std::string & Item::GetName()
{
	return myName;
}

EItemType & Item::GetItemType()
{
	return myItemType;
}

std::string Item::GetRingType()
{
	std::string tempReturnValue;
	switch (myRingType)
	{
	case ERingType::NOT_A_RING:
		tempReturnValue = "";
		break;
	case ERingType::DEFENCE:
		tempReturnValue = "Defence ";
		break;
	case ERingType::INTELLIGENCE:
		tempReturnValue = "Intelligence ";
		break;
	case ERingType::STRENGTH:
		tempReturnValue = "Strength ";
		break;
	case ERingType::VITALITY:
		tempReturnValue = "Vitality ";
		break;
	}
	tempReturnValue += std::to_string(myLevel);
	return tempReturnValue;
}

unsigned& Item::GetLevel()
{
	return myLevel;
}

int& Item::GetStat()
{
	return myStat;
}

void Item::SetIsEquipped(bool aValue)
{
	myIsEquipped = aValue;
}

bool& Item::GetIsEquipped()
{
	return myIsEquipped;
}