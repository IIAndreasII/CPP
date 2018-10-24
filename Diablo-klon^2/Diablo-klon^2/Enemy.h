#ifndef ENEMY_H
#define ENEMY_H

#include "pch.h"
#include "Enums.h"

class Enemy
{
public:
	Enemy();
	Enemy(int aLevel);
	~Enemy();

	std::string& GetName();

	int GetHealth() const;
	uint16_t GetDamage() const;
	uint16_t GetArmour() const;

	EDamageType GetDamageType() const;

	bool GetCanTakePhysDmg() const;

	void TakeDamage(int &aDamageToTake, EDamageType &aDmgType);

private:

	std::string myName;

	int myHealth;
	uint16_t myDamage;
	uint16_t myArmour;

	bool myCanTakePhysDmg;

	EDamageType myDamageType;
};

#endif