#ifndef ITEM_H
#define ITEM_H

#include "Enums.h"
#include <string>

class Item
{
public:
	Item();
	Item(uint16_t aLevel);
	Item(std::string aName, uint16_t aStat, EItemType anItemType);
	Item(std::string aName, uint16_t aStat, EItemType anItemType, bool isEquipped);
	Item(uint16_t aLevel, std::string aName, uint16_t aStat, EItemType anItemType, ERingType aRingType, bool isEquipped);
	~Item();

	std::string GetName() const;
	std::string GetRingTypeToString() const;
	std::string GetItemTypeToString() const;

	EItemType GetItemType() const;
	ERingType GetRingType() const;

	uint16_t GetStat() const;
	uint16_t GetLevel() const;

	bool& GetIsEquipped();

	void SetIsEquipped(bool aValue);

	void Combine(Item* anItem);

	Item* ToNewPtr();

private:

	std::string myName;

	uint16_t myStat;
	uint16_t myLevel;

	bool myIsEquipped;

	EItemType myItemType;
	ERingType myRingType;

};

#endif