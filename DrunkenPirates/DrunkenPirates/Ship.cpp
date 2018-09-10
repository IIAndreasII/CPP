#include "pch.h"
#include "Ship.h"
#include "ConstDefinitions.h"

Ship::Ship() : myAccuracy(100.0f), myCannons(), myHitChance(100.0f), myHull(), myIsSinking(false), myMast()
{
}


Ship::~Ship()
{
}

void Ship::DisplayStatus()
{

	bool tempLoop = true;

	while (tempLoop)
	{
		CLSSlow();
		WriteLine("Ship status:");
		myHull.DisplayStatus();
		myMast.DisplayStatus();
		myCannons.DisplayStatus();
		
		WriteLine("\n[1] Repair hull\n[2] Repair mast\n[3] Repair cannons\n[4] Back");
		
		switch (GetInput())
		{
		case 1:
			
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			tempLoop = false;

			break;
		}
	}
}

void Ship::UpdateStatus()
{
	if (myHull.GetIntegrity() <= INTEGRITY_MIN)
	{
		myIsSinking = true;
		return;
	}

	float tempCannonIntegrity = myCannons.GetIntegrity();
	uint8_t tempNrOfCannons = myCannons.GetNrOfCannons();

	if (tempCannonIntegrity <= 75.0f && tempNrOfCannons == 4)
	{
		myCannons.SetNrOfCannons(3);
	}
	else if (tempCannonIntegrity <= 50.0f && tempNrOfCannons == 3)
	{
		myCannons.SetNrOfCannons(2);
	}
	else if (tempCannonIntegrity <= 25.0f && tempNrOfCannons == 2)
	{
		myCannons.SetNrOfCannons(1);
	}
	else if (tempCannonIntegrity <= 0.0f && tempNrOfCannons == 1)
	{
		myCannons.SetNrOfCannons(0);
	}

	if (myMast.GetIntegrity() <= 0)
	{
		myMast.SetAreSailsUp(true);
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
