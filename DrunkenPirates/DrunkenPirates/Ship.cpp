#include "pch.h"
#include "Ship.h"


Ship::Ship()
{
}


Ship::~Ship()
{
}

void Ship::DisplayStatus()
{
	std::cout << "Ship status:\n" << std::endl;
	myHull.DisplayStatus();
	myMast.DisplayStatus();
	myCannons.DisplayStatus();
}

void Ship::UpdateStatus()
{
	if (myHull.GetIntegrity() <= 0)
	{
		myIsSinking = true;
	}
}

Mast& Ship::GetMast()
{
	return myMast;
}

Hull& Ship::GetHull()
{
	return myHull;
}

Cannons& Ship::GetCannons()
{
	return myCannons;
}

float& Ship::GetHitChance()
{
	return myHitChance;
}

float& Ship::GetAccuracy()
{
	return myAccuracy;
}

bool& Ship::GetIsSinking()
{
	return myIsSinking;
}

void Ship::SetHitChance(const float tempValue)
{
	myHitChance = tempValue;
}

void Ship::SetAccuracy(const float tempValue)
{
	myAccuracy = tempValue;
}
