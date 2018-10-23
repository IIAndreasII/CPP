#ifndef ENEMY_H
#define ENEMY_H

#include "pch.h"
#include "Enums.h"

class Player;

class Enemy
{
public:
	Enemy();
	Enemy(int aLevel);
	~Enemy();

	std::string& GetName();

	int GetHealth() const;
	int GetDamage() const;
	unsigned& GetArmour();

	EDamageType GetDamageType() const;

	bool GetCanTakePhysDmg() const;

	void TakeDamage(int &aDamageToTake, EDamageType &aDmgType);

private:

	std::string myName;

	int myHealth;
	int myDamage;

	bool myCanTakePhysDmg;

	unsigned myArmour;

	EDamageType myDamageType;
};

#endif