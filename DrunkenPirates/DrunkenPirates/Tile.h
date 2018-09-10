#ifndef TILE_H
#define TILE_H

//#include "pch.h"

#include <vector>

enum TileType
{
	EMPTY,
	ENEMY_CAMP,
	SHOP
};

enum Path
{
	NORTH,
	EARTH,
	SOUTH,
	WEST
};

class Tile
{
public:
	Tile();
	Tile(const Path tempPathToPush);
	~Tile();

	

	// Get
	TileType& GetTileType();
	std::vector<Path>& GetPaths();

	// Set
	void SetTileType(const TileType newVaule);
	void AddPath(const Path newVaule);

private:

	TileType myTileType;

	std::vector<Path> myPaths;
};

#endif