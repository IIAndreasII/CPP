#ifndef HULL_H
#define HULL_H

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

#endif