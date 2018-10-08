#ifndef ITEM_H
#define ITEM_H

#include "Enums.h"
#include <string>

class Item
{
public:
	Item();
	Item(int aLevel);
	Item(std::string aName, int aStat, EItemType anItemType);
	Item(std::string aName, int aStat, EItemType anItemType, bool isEquipped);
	~Item();

	std::string& GetName();
	EItemType& GetItemType();
	std::string GetRingType();
	int& GetLevel();
	int& GetStat();

	void SetIsEquipped(bool aValue);
	bool& GetIsEquipped();

private:

	std::string myName;

	int myLevel;
	int myStat;

	bool myIsEquipped;

	EItemType myItemType;
	ERingType myRingType;
};

#endif