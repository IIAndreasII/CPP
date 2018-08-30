#include "pch.h"
#include "Hull.h"


Hull::Hull()
{
	myIntegrity = MAX_INTERGRITY;
}


Hull::~Hull()
{
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
