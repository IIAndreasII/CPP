#include "pch.h"
#include "Cannons.h"
#include "ConstDefinitions.h"

Cannons::Cannons() : myNumberOfCannons(4)
{
	myIntegrity = INTEGRITY_MAX;
	myStrength = STRENGTH_LEVEL_1;
}


Cannons::~Cannons()
{
}

void Cannons::DisplayStatus()
{
	WriteLine(" -Cannons:\n  -Integrity: " + std::to_string(myIntegrity) + "\n  -Number of cannons: " + std::to_string(myNumberOfCannons));
}

void Cannons::SetNrOfCannons(const uint8_t tempValue)
{
	myNumberOfCannons = tempValue;
}

uint8_t Cannons::GetNrOfCannons()
{
	return myNumberOfCannons;
}
