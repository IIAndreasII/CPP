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

	void ShowInventory();
	void LongRest();

	void AddAttackType(EAttackTypes anAttack);
	std::vector<EAttackTypes>& GetAttackTypes();
	std::string AtkTypeToString(EAttackTypes anAtkType);

	void LevelUp();

	void TakeDamage(int& aDamageToTake);

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

	unsigned mySpellArmour;

	/* START Indexes for the respective items*/
	unsigned mySword;
	unsigned myStaff;
	unsigned myArmour;
	unsigned myRingRight;
	unsigned myRingLeft;
	/*END*/

	unsigned myAttackMod;

	std::vector<Item>* myItems;
	std::vector<EAttackTypes>* myAttackTypes;
};

#endif