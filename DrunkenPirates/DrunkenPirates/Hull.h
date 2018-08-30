#pragma once

#include "ShipComponent.h"
#include "ConstDefinitions.h"

class Hull :
	public ShipComponent
{
public:
	Hull();
	~Hull();

	void DisplayStatus();

	bool TakeDamage(float &tempDamage);


};

