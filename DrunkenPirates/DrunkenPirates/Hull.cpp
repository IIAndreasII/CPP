#include "pch.h"
#include "Hull.h"

using namespace std;

Hull::Hull()
{
	myIntegrity = MAX_INTERGRITY;
}


Hull::~Hull()
{
}

void Hull::DisplayStatus()
{
	cout << "Hull:\n" << endl;
	cout << " -Integrity: " + to_string(myIntegrity) + "\n" << endl;
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
