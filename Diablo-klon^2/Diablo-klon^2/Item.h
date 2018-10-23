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

	std::string GetName() const;
	std::string GetRingTypeToString() const;
	
	EItemType GetItemType() const;
	ERingType GetRingType() const;
	
	int& GetStat();
	uint16_t& GetLevel();
	bool& GetIsEquipped();

	void SetIsEquipped(bool aValue);

	void Combine(Item &anItem);

private:

	std::string myName;

	int myStat;
	
	uint16_t myLevel;

	

	bool myIsEquipped;

	EItemType myItemType;
	ERingType myRingType;

	std::string ItemTypeToString(EItemType &aType);

};

#endif