#include "pch.h"
#include "Hull.h"
#include "ConstDefinitions.h"

using namespace std;

Hull::Hull()
{
	myIntegrity = INTEGRITY_MAX;
	myStrength = STRENGTH_LEVEL_1;
}


Hull::~Hull()
{
}

void Hull::DisplayStatus()
{
	WriteLine(" -Hull:\n  -Integrity: " + to_string(myIntegrity));
}

bool Hull::TakeDamage(float & tempDamage)
{
	myIntegrity -= tempDamage;
	if (myIntegrity > 0)
	{
		return true;
	}
	return false;
}
