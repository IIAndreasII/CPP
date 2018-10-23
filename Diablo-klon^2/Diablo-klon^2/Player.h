#ifndef PLAYER_H
#define PLAYER_H

#include "pch.h"
#include "Enums.h"

class Item;

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
	std::string AtkTypeToString(EAttackTypes &anAtkType);
	std::string CharmTypeToString(ECharmType &aCharmType);

	void AddGold(int someGold);
	void AddExp(int someExp);
	unsigned GetLevel() const;

	void TakeDamage(int& aDamageToTake);
	void TakeDamage(int aDamageToTake);

	void PrintUI();

	void Reset();

	int& GetPhysDmg();
	int& GetSpellDmg();
	unsigned& GetHPPotions();
	void DrinkPotion();

	void AddRandomItem();

	void SetIntel(const int someIntel);

private:

	void ChangeEquipment(EItemType anItemType, bool &isRight);

	int myHealth;
	int myHealthMax;
	int myStrength;
	int myIntelligence;

	int myPhysDmg;
	int mySpellDmg;

	unsigned myLevel;
	int myEXP;
	int myEXPRequired;
	int myGold;
	unsigned myHPPotions;

	unsigned mySpellArmour;

	/* START Indexes for the respective items*/
	unsigned mySword;
	unsigned myStaff;
	unsigned myArmour;
	unsigned myRingRight;
	unsigned myRingLeft;
	unsigned myCharm;
	/*END*/

	unsigned myAttackMod;

	std::vector<ECharmType>* myCharms;
	std::vector<Item*>* myItems;
	std::vector<EAttackTypes>* myAttackTypes;
};

#endif