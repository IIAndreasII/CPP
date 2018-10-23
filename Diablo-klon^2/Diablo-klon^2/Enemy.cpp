#include "stdafx.h"
#include "util.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(int aLevel) : myHealth(aLevel * 15), myDamage(aLevel * 5), myArmour(aLevel * 3), myCanTakePhysDmg(true)
{
	std::vector<std::string> tempNames = { "Skeleton", "Zombie", "Grunt", "Orc", "Cultist", "Cobold", "Darkelf", "Zerg", "Goblin", "Wraith", "Spectre", "Phaser", "Phantom", "Animated armour", "Ghast", "Shadow demon", "Shade", "Willow wisp" };
	
	int tempIndex = RNG(0, tempNames.size() - 1);
	myName = tempNames.at(tempIndex);
	if (tempIndex > 8)
	{
		myCanTakePhysDmg = false;
	}
}

Enemy::~Enemy()
{
}

std::string & Enemy::GetName()
{
	return myName;
}

int & Enemy::GetHealth()
{
	return myHealth;
}

int Enemy::GetDamage() const
{
	return myDamage;
}

unsigned & Enemy::GetArmour()
{
	return myArmour;
}

bool Enemy::GetCanTakePhysDmg() const
{
	return myCanTakePhysDmg;
}

void Enemy::TakeDamage(int & aDamageToTake)
{
	myHealth -= (aDamageToTake - myArmour);
}