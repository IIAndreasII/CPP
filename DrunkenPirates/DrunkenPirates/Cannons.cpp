#include "pch.h"
#include "Cannons.h"

using namespace std;

Cannons::Cannons() : myNumberOfCannons(4)
{
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
