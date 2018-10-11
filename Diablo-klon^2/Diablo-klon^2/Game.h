#ifndef GAME_H
#define GAME_H

#include "pch.h"

class Player;
class DungeonManager;

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

	void MainMenu();
	void GameMenu();

	Player& GetPlayer();

private:
	EGameState myGameState;

	DungeonManager* myDM;

	Player* myPlayer;
};

#endif