#ifndef PLAYER_H
#define PLAYER_H

#include "pch.h"
#include "Enums.h"

class Item;
class Shop;

class Player
{
public:
	Player();
	~Player();

	void Init();
	void PrintUI();
	void LongRest();
	void DrinkPotion();
	void ShowInventory();
	void AddRandomItem();
	void AddExp(int someExp);
	void AddItem(Item anItem);
	void AddGold(int someGold);
	void SetShopPtr(Shop* aShopPtr);
	void SetIntel(const int someIntel);
	void AddAttackType(EAttackType anAttack);
	void TakeDamage(int& aDamageToTake);
	void TakeDamage(int aDamageToTake, EDamageType aDmgType);


	std::vector<EAttackType>& GetAttackTypes();
	std::string AtkTypeToString(EAttackType &anAtkType);

	int GetHealth() const;
	uint16_t GetGold() const;
	uint16_t GetLevel() const;
	uint16_t GetArmour() const;
	uint16_t GetPhysDmg() const;
	uint16_t GetSpellDmg() const;
	uint16_t GetHPPotions() const;
	uint16_t GetSpellArmour() const;

private:

	void EquipRing(Item* aRing);
	void UnEquipRing(Item* aRing);
	void ChangeEquipment(EItemType anItemType, bool &isRight);

	uint16_t myEXP;
	uint16_t myGold;
	uint16_t myLevel;
	uint16_t myStrength;
	uint16_t myHealthMax;
	uint16_t myHPPotions;
	uint16_t myEXPRequired;
	uint16_t myIntelligence;

	int myHealth;
	int myPhysDmg;
	int mySpellDmg;
	int myHealthMod;
	int myDefenceMod;
	int myStrengthMod;
	int myIntelligenceMod;

	/* Equipped item-pointers */
	Item* mySword;
	Item* myStaff;
	Item* myArmour;
	Item* myRingLeft;
	Item* myRingRight;
	Item* mySpellArmour;

	std::vector<Item*>* myItems;
	std::vector<EAttackType> myAttackTypes;

	Shop* myShopPtr;
};

#endif