#ifndef ENEMY_H
#define ENEMY_H

#include "pch.h"

class Player;

class Enemy
{
public:
	Enemy();
	~Enemy();

	std::string& GetName();

	int& GetHealth();
	int& GetDamage();
	unsigned& GetArmour();

	void TakeDamage(unsigned& aDamageToTake);

private:

	std::string myName;

	int myHealth;
	int myDamage;

	unsigned myArmour;
};

#endif