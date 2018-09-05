#include "pch.h"
#include "Game.h"


Game::Game() : myPlayer()
{
}

Game::~Game()
{
}

void Game::Play()
{
}

void Game::Menu()
{
	bool tempLoop = true;

	while (tempLoop)
	{
		CLSUnsafe();
		WriteLine("[1] Venture the seas\n[2] View ship\n[3] Back to menu");

		switch (GetInput())
		{
		case 1:

			// TODO: Venture the seas

			tempLoop = false;
			break;

		case 2:

			myPlayer.DisplayShipStatus();

			tempLoop = false;
			break;

		case 3:

			tempLoop = false;
			break;

		default:
			break;
		}
	}

}

Player& Game::GetPlayer()
{
	return myPlayer;
}
