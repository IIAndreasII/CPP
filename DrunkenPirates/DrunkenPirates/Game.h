#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void Play();


	// Get
	Player& GetPlayer();

	// Set

private:

	void Menu();

	Player myPlayer;

	// TODO: Add handlers here
};

#endif