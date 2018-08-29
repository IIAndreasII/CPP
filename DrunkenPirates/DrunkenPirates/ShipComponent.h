#pragma once

#include "pch.h"

class ShipComponent
{
public:
	ShipComponent();
	~ShipComponent();

	// Get
	float& GetIntegrity();
	int& GetStrenght();
	int& GetLevel();

	// Set
	void SetIntegrity(float tempIntegrity);
	void SetStrength(const int tempStrength);
	void SetLevel(const int tempLevel);

protected:

	float myIntegrity;
	int myStrength;
	int myLevel;
};

