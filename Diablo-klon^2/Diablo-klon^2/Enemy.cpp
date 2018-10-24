#include "stdafx.h"
#include "Util.h"
#include "Enemy.h"
#include <thread>

Enemy::Enemy()
{
}

Enemy::Enemy(int aLevel) : myHealth(aLevel * 15), myDamage(aLevel * 5), myArmour(aLevel * 3), myCanTakePhysDmg(true), myDamageType(EDamageType::PHYSICAL)
{
	std::vector<std::string> tempNames = { "Skeleton", "Zombie", "Grunt", "Orc", "Cultist", "Cobold", "Darkelf", "Zerg", "Goblin", "Wraith", "Spectre", "Phaser", "Phantom", "Animated armour", "Ghast", "Shadow demon", "Shade", "Willow wisp" };

	int tempIndex = RNG(0, static_cast<int>(tempNames.size() - 1));
	myName = tempNames.at(tempIndex);
	if (tempIndex > 8)
	{
		myCanTakePhysDmg = false;
		myDamageType = EDamageType::MAGICAL;
	}
}

Enemy::~Enemy()
{
}

std::string & Enemy::GetName()
{
	return myName;
}

int Enemy::GetHealth() const
{
	return myHealth;
}

uint16_t Enemy::GetDamage() const
{
	return myDamage;
}

uint16_t Enemy::GetArmour() const
{
	return myArmour;
}

EDamageType Enemy::GetDamageType() const
{
	return myDamageType;
}

bool Enemy::GetCanTakePhysDmg() const
{
	return myCanTakePhysDmg;
}

void Enemy::TakeDamage(int &aDamageToTake, EDamageType &aDmgType)
{
	if (!myCanTakePhysDmg && aDmgType == EDamageType::PHYSICAL)
	{
		Print("The attack had no effect!");
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	else
	{
		myHealth -= (aDamageToTake - myArmour);
		Print(myName + " takes " + std::to_string(aDamageToTake - myArmour) + " damage!");
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}