#ifndef TILESET_H
#define TILESET_H
#include "Tile.h"

class Tileset
{
public:
	Tileset();
	~Tileset();

	// Get
	auto& GetTileSet();

private:

	Tile myTileset[20][20];

	void GenerateTileset();

};

#endif