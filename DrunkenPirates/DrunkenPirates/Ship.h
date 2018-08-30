#pragma once

#include "Cannons.h"
#include "Hull.h"
#include "Mast.h"

class Ship
{
public:
	Ship();
	~Ship();

	void DisplayStatus();
	void UpdateStatus();


	// Get
	Mast& GetMast();
	Hull& GetHull();
	Cannons& GetCannons();

	float& GetHitChance();
	float& GetAccuracy();

	bool& GetIsSinking();

	// Set
	void SetHitChance(const float tempValue);
	void SetAccuracy(const float tempValue);


private:

	// Ship components
	Mast myMast;
	Hull myHull;
	Cannons myCannons;

	float myHitChance;
	float myAccuracy;

	bool myIsSinking;

};

