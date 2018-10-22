#ifndef GAME_H
#define GAME_H

#include "pch.h"

class Player;
#include "Dungeon.h"

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

	Player& GetPlayer();

private:
	EGameState myGameState;

	Dungeon myDungeon;

	Player* myPlayer;
};

#endif