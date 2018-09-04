#include "pch.h"
#include "Cannons.h"
#include "ConstDefinitions.h"

using namespace std;

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
	WriteLine("Cannons:");
	WriteLine(" -Integrity: " + to_string(myIntegrity));
	WriteLine(" -Number of cannons: " + to_string(myNumberOfCannons));
}

void Cannons::SetNrOfCannons(const uint8_t tempValue)
{
	myNumberOfCannons = tempValue;
}

uint8_t Cannons::GetNrOfCannons()
{
	return myNumberOfCannons;
}
