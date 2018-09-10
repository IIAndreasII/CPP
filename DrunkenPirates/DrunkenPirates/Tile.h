#pragma once

enum TileType
{
	WATER,
	ISLAND,
	ISLAND_W_SHOP,
	ISLAND_W_ENEMIES
};

enum Direction
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
	~Tile();

	// Get
	TileType& GetTileType();
	Direction& GetDirection();

	// Set
	void SetTileType(const TileType newVaule);
	void SetDirection(const Direction newVaule);

private:
	TileType myTileType;
	Direction myDirection;
};

