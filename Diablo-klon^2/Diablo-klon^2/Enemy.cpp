#include "stdafx.h"
#include "util.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(int aLevel) : myHealth(aLevel * 15), myDamage(aLevel * 5), myArmour(aLevel * 3)
{
	std::vector<std::string> tempNames = { "Skeleton", "Zombie", "Grunt", "Orc", "Cultist", "Cobold", "Darkelf", "Zerg" };
	myName = tempNames.at(RNG(0, tempNames.size() - 1));
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

void Enemy::TakeDamage(int & aDamageToTake)
{
	myHealth -= (aDamageToTake - myArmour);
}