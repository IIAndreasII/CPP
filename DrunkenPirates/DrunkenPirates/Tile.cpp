#include "pch.h"
#include "Tile.h"


Tile::Tile()
{
}


Tile::~Tile()
{
}

TileType & Tile::GetTileType()
{
	return myTileType;
}

Direction & Tile::GetDirection()
{
	return myDirection;
}

void Tile::SetTileType(const TileType newValue)
{
	myTileType = newValue;
}

void Tile::SetDirection(const Direction newValue)
{
	myDirection = newValue;
}
