#include "pch.h"
#include "ShipComponent.h"


void ShipComponent::Repair(uint32_t& tempDoubloons)
{

	myIntegrity = 100.0f;
}

float & ShipComponent::GetIntegrity()
{
	return myIntegrity;
}

int & ShipComponent::GetStrenght()
{
	return myStrength;
}

uint8_t & ShipComponent::GetLevel()
{
	return myLevel;
}

void ShipComponent::SetIntegrity(float tempIntegrity)
{
	myIntegrity = tempIntegrity;
}

void ShipComponent::SetStrength(const int tempStrength)
{
	myStrength = tempStrength;
}

void ShipComponent::SetLevel(const int tempLevel)
{
	myLevel = tempLevel;
}
