#ifndef GAME_H
#define GAME_H

#include "pch.h"

enum EGameState 
{
	EMenu,
	EPlaying,
	EQuitting
};

class Player;

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

	Player* myPlayer;
};

#endif