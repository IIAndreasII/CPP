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

	int GetHealth() const;
	int GetArmour() const;
	int GetSpellArmour() const;

	void ShowInventory();
	void LongRest();

	void AddAttackType(EAttackType anAttack);
	std::vector<EAttackType>& GetAttackTypes();
	std::string AtkTypeToString(EAttackType &anAtkType);

	void AddGold(int someGold);
	void AddExp(int someExp);
	unsigned GetLevel() const;

	void TakeDamage(int& aDamageToTake);
	void TakeDamage(int aDamageToTake, EDamageType aDmgType);

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
	void EquipRing(Item &aRing);
	void UnEquipRing(Item &aRing);

	int myHealth;
	int myHealthMax;
	int myStrength;
	int myIntelligence;

	int myHealthMod;
	int myStrengthMod;
	int myIntelligenceMod;
	int myDefenceMod;

	int myPhysDmg;
	int mySpellDmg;

	unsigned myLevel;
	int myEXP;
	int myEXPRequired;
	int myGold;
	unsigned myHPPotions;

	// TODO: Change to pointers
	/* START Indexes for the respective items*/
	unsigned mySword;
	unsigned myStaff;
	unsigned myArmour;
	unsigned mySpellArmour;
	unsigned myRingRight;
	unsigned myRingLeft;
	/*END*/

	unsigned myAttackMod;

	std::vector<Item*>* myItems;
	std::vector<EAttackType>* myAttackTypes;
};

#endif