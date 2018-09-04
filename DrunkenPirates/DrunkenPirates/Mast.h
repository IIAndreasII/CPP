#ifndef MAST_H
#define MAST_H

#include "ShipComponent.h"

class Mast :
	public ShipComponent
{
public:
	Mast();
	~Mast();

	void DisplayStatus();

	// Get
	bool& GetAreSailsUp();

	// Set
	void SetAreSailsUp(const bool tempValue);

private:

	bool myAreSailsUp; // false = wind is blowing in the sails; true = wind is not blowing the sails
};

#endif