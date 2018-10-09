#ifndef PLAYER_H
#define PLAYER_H

#include "pch.h"
#include "Enums.h"
#include "Item.h"

class Player
{
public:
	Player();
	~Player();


	int& GetHealth();
	int& GetArmour();
	int& GetAttack();

	void ShowInventory();
	void LongRest();

	void AddAttackType(EAttackTypes anAttack);

	void LevelUp();

private:

	void ChangeEquipment(EItemType anItemType, bool &isRight);

	int myHealth;
	int myHealthMax;
	int myStrength;
	int myIntelligence;

	unsigned myLevel;
	unsigned myEXP;
	unsigned myEXPRequired;
	unsigned myGold;
	unsigned myHPPotions;

	uint16_t mySword;
	uint16_t myStaff;
	uint16_t myArmour;
	uint16_t myRingRight;
	uint16_t myRingLeft;

	std::vector<Item> myItems;
	std::vector<EAttackTypes> myAttackTypes;
};

#endif