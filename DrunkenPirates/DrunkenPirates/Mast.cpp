#include "pch.h"
#include "Mast.h"
#include "ConstDefinitions.h"

using namespace std;

Mast::Mast() : myAreSailsUp(false) 
{
	myIntegrity = INTEGRITY_MAX;
	myStrength = STRENGTH_LEVEL_1;
	myLevel = 1;
}


Mast::~Mast()
{
}

void Mast::DisplayStatus()
{
	WriteLine("Mast status:");
	WriteLine(" -Integrity: " + to_string(myIntegrity));

	std::string tempSailState;
	if(myAreSailsUp)
	{
		tempSailState = "Rolled up";
	}
	else
	{
		tempSailState = "Rolled down";
	}

	WriteLine(" -Sail-state: " + tempSailState);
}

bool & Mast::GetAreSailsUp()
{
	return myAreSailsUp; 
}

void Mast::SetAreSailsUp(const bool tempValue)
{
	myAreSailsUp = tempValue;
}
