#include "stdafx.h"
#include "Game.h"
#include "Util.h"
#include "Dungeon.h"


Game::Game() : myGameState(EGameState::EMenu), myPlayer()
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
		
		case EGameState::EQuitting:
			return 0;
		}
	}


	return 0;
}

void Game::MainMenu()
{
//	CLSSlow();
	Dungeon tempDung;

	tempDung.PrintMap();

	std::cout << tempDung.GetNrDoors() << std::endl;

	WriteLine("Diabloclone^2\n[1] Play\n[2] Quit");


	switch (GetInput())
	{
	case 1:

		break;

	case 2:
		myGameState = EGameState::EQuitting;
		break;
	}
}

void Game::GameMenu()
{
}

Player & Game::GetPlayer()
{
	return *myPlayer;
}
