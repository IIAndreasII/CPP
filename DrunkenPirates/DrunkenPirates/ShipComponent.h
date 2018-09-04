#ifndef SHIPCOMPONENT_H
#define SHIPCOMPONENT_H

#include "pch.h"

class ShipComponent
{
public:
	
	ShipComponent();
	~ShipComponent();

	void Repair(uint32_t& tempDoubloons);
	bool TakeDamage(uint32_t& tempDamage);

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

#endif