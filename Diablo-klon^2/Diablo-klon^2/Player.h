#ifndef PLAYER_H
#define PLAYER_H

#include "pch.h"

enum EAttackTypes
{
	SLASH,
	SWEEP,
	WHIRLWIND,
	ICELANCE,
	COC, // Cone of Cold
	BLIZZARD
};

class Player
{
public:
	Player();
	~Player();


	int& GetHealth();
	int& GetArmour();
	int& GetAttack();

	void AddAttackType(EAttackTypes anAttack);

private:

	int myHealth;
	int myArmour;
	int myAttack;

	int myAttackMod;
	int myArmourMod;
	int myHealthMod;

	unsigned myLevel;
	unsigned myEXP;



	std::vector<EAttackTypes> myAttackTypes;
};

#endif