#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

int & Player::GetHealth()
{
	return myHealth;
}

int & Player::GetArmour()
{
	return myArmour;
}

int & Player::GetAttack()
{
	return myAttack;
}

void Player::ShowInventory()
{
}

void Player::LongRest()
{
}

void Player::AddAttackType(EAttackTypes anAttack)
{
	if (!(std::find(myAttackTypes.begin(), myAttackTypes.end(), anAttack) != myAttackTypes.end()))
	{
		myAttackTypes.push_back(anAttack);
	}
}
