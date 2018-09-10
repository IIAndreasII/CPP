#include "pch.h"
#include "ShipComponent.h"
#include "ConstDefinitions.h"


ShipComponent::ShipComponent()
{
}

ShipComponent::~ShipComponent()
{
}

void ShipComponent::DisplayStatus()
{
}

void ShipComponent::Repair(uint32_t& tempDoubloons)
{
	myIntegrity = 100.0f;
}

bool ShipComponent::TakeDamage(uint32_t & tempDamage)
{
	myIntegrity -= tempDamage;
	if (myIntegrity <= INTEGRITY_MIN)
	{
		return true;
	}

	return false;
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
