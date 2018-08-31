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
	cout << "Cannons:\n" << endl;
	cout << " -Integrity: " + to_string(myIntegrity) + "\n" << endl;
	cout << " -Number of cannons: " + to_string(myNumberOfCannons) + "\n" << endl;
}
