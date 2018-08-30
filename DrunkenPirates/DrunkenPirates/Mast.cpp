#include "pch.h"
#include "Mast.h"


Mast::Mast() : myAreSailsUp(false) 
{
	myIntegrity = 100.0f;
	myStrength = 80;
	myLevel = 1;
}


Mast::~Mast()
{
}

bool & Mast::GetAreSailsUp()
{
	return myAreSailsUp; 
}

void Mast::SetAreSailsUp(const bool tempValue)
{
	myAreSailsUp = tempValue;
}
