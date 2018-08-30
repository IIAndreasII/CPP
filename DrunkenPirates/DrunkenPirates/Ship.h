#pragma once

#include "Cannons.h"
#include "Hull.h"
#include "Mast.h"

class Ship
{
public:
	Ship();
	~Ship();

private:

	Mast myMast;
	Hull myHull;
	Cannons myCannons;
};

