#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
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

void Enemy::TakeDamage(unsigned & aDamageToTake)
{
	myHealth -= (aDamageToTake - myArmour);
}