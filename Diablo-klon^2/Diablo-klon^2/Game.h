#ifndef GAME_H
#define GAME_H

#include "pch.h"

enum EGameState 
{
	EMenu,
	EPlaying
};

class Game
{
public:
	Game();
	~Game();

	int Play();

	void MainMenu();
	void GameMenu();

private:
	EGameState myGameState;
};

#endif