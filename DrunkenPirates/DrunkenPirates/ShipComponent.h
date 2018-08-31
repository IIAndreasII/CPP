#pragma once

#include "pch.h"

class ShipComponent
{
public:
	
	void Repair(uint32_t& tempDoubloons);

	// Get
	float& GetIntegrity();
	int& GetStrenght();
	uint8_t& GetLevel();

	// Set
	void SetIntegrity(float tempIntegrity);
	void SetStrength(const int tempStrength);
	void SetLevel(const int tempLevel);

protected:

	float myIntegrity;
	int myStrength;
	uint8_t myLevel;
};

