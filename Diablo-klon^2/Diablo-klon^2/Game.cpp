#include "stdafx.h"
#include "Game.h"


Game::Game() : myGameState(EGameState::EMenu)
{
}


Game::~Game()
{
}

int Game::Play()
{
	bool tempLoop = true;

	while (tempLoop)
	{
		switch (myGameState)
		{
		case EGameState::EMenu:
			MainMenu();
			break;

		case EGameState::EPlaying:
			Play();
			break;
		
		}
	}


	return 0;
}

void Game::MainMenu()
{
	CLSSlow();
	WriteLine("Diabloclone^2\n[1] Play\n[2] Quit");


	switch (GetInput())
	{
	case 1:

		break;
	}
}

void Game::GameMenu()
{
}
