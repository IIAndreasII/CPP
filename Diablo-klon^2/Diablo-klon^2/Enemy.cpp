#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(int aLevel) : myHealth(aLevel * 15), myDamage(aLevel * 5), myArmour(aLevel * 3), myName("Skeleton")
{
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

int & Enemy::GetDamage()
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