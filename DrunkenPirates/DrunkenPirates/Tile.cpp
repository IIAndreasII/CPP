#include "pch.h"
#include "Tile.h"


Tile::Tile()
{
}

Tile::Tile(const Path tempPathToPush) : myPaths()
{
	myPaths.push_back(tempPathToPush);
}


Tile::~Tile()
{
}

TileType & Tile::GetTileType()
{
	return myTileType;
}

std::vector<Path>& Tile::GetPaths()
{
	return myPaths;
}

void Tile::SetTileType(const TileType newValue)
{
	myTileType = newValue;
}

void Tile::AddPath(const Path tempPathToPush)
{
	myPaths.push_back(tempPathToPush);
}
