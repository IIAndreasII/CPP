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

    virtual void DisplayStatus() override;

	bool TakeDamage(float &tempDamage);



};

#endif