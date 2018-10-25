#ifndef GAME_H
#define GAME_H

#include "pch.h"
#include "Dungeon.h"

class Player;
class Shop;

enum EGameState
{
	EMenu,
	EPlaying,
	EQuitting
};

class Game
{
public:
	Game();
	~Game();

	int Play();

	void Reset();
	void MainMenu();
	void GameMenu();

private:

	EGameState myGameState;

	Dungeon myDungeon;

	Player* myPlayer;

	Shop* myShop;
};

#endif