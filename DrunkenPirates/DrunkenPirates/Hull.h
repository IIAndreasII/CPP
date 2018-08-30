#pragma once

#include "ShipComponent.h"
#include "ConstDefinitions.h"

class Hull :
	public ShipComponent
{
public:
	Hull();
	~Hull();

	bool TakeDamage(float &tempDamage);


};

