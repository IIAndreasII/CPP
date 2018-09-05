#ifndef CANNONS_H
#define CANNONS_H

#include "ShipComponent.h"

class Cannons :
	public ShipComponent
{
public:
	Cannons();
	~Cannons();

	virtual void DisplayStatus() override;

	void SetNrOfCannons(const uint8_t tempValue);

	uint8_t GetNrOfCannons();

private:

	uint8_t myNumberOfCannons;
};

#endif