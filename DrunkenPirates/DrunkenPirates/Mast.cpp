#include "pch.h"
#include "Mast.h"

using namespace std;

Mast::Mast() : myAreSailsUp(false) 
{
	myIntegrity = 100.0f;
	myStrength = 80;
	myLevel = 1;
}


Mast::~Mast()
{
}

void Mast::DisplayStatus()
{
	cout << "Mast:\n" << endl;
	cout << " -Integrity: " + to_string(myIntegrity) + "\n" << endl;

	std::string tempSailState;
	if(myAreSailsUp)
	{
		tempSailState = "Rolled up";
	}
	else
	{
		tempSailState = "Rolled down";
	}

	cout << " -Sail-state: " + tempSailState + "\n" << endl;
}

bool & Mast::GetAreSailsUp()
{
	return myAreSailsUp; 
}

void Mast::SetAreSailsUp(const bool tempValue)
{
	myAreSailsUp = tempValue;
}
