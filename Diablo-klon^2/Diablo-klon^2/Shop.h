#ifndef SHOP_H
#define SHOP_H

#include "pch.h"
#include "Item.h"
#include "Enums.h"

class Player;

class Shop
{
public:
	Shop();
	~Shop();

	void Restock();
	void Enter();

	void SetPlayerPtr(Player* aPlayerPtr);
	void AddAttackType(EAttackType anAtkType);

private:

	uint8_t myEstusAmount;

	std::vector<Item> myItems;

	Player* myPlayerPtr;

	std::vector<EAttackType> mySkills;
};

#endif