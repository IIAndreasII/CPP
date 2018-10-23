#ifndef ENEMY_H
#define ENEMY_H

#include "pch.h"

class Player;

class Enemy
{
public:
	Enemy();
	Enemy(int aLevel);
	~Enemy();

	std::string& GetName();

	int& GetHealth();
	int GetDamage() const;
	unsigned& GetArmour();

	bool GetCanTakePhysDmg() const;

	void TakeDamage(int& aDamageToTake);

private:

	std::string myName;

	int myHealth;
	int myDamage;

	bool myCanTakePhysDmg;

	unsigned myArmour;
};

#endif