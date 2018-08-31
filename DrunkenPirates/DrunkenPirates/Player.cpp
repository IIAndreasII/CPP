#include "pch.h"
#include "Player.h"


Player::Player() : myDoubloons(0)
{
}


Player::~Player()
{
}

Ship& Player::GetShip()
{
	return myShip;
}

uint32_t & Player::GetDoubloons()
{
	return myDoubloons;
}

void Player::SetDoubloons(uint32_t tempValue)
{
	myDoubloons = tempValue;
}
