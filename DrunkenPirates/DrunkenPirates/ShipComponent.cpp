#include "pch.h"
#include "ShipComponent.h"


ShipComponent::ShipComponent()
{
}


ShipComponent::~ShipComponent()
{
}

float & ShipComponent::GetIntegrity()
{
	return myIntegrity;
}

int & ShipComponent::GetStrenght()
{
	return myStrength;
}

int & ShipComponent::GetLevel()
{
	return myLevel;
}

void ShipComponent::SetIntegrity(float tempIntegrity)
{
}

void ShipComponent::SetStrength(const int tempStrength)
{
}

void ShipComponent::SetLevel(const int tempLevel)
{
}
