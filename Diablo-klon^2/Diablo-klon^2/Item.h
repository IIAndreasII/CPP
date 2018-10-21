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
	unsigned& GetLevel();
	int& GetStat();

	void SetIsEquipped(bool aValue);
	bool& GetIsEquipped();

	bool operator == (Item);

private:

	std::string myName;

	unsigned myLevel;
	int myStat;

	bool myIsEquipped;

	EItemType myItemType;
	ERingType myRingType;

};

#endif