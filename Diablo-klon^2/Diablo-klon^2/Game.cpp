#include "stdafx.h"
#include "Game.h"
#include "Util.h"
#include "Dungeon.h"
#include "Player.h"


Game::Game() : myGameState(EGameState::EMenu), myPlayer()
{
}


Game::~Game()
{
	delete myPlayer;
	myPlayer = NULL;
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
		
		default:
			return 0;
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
		GameMenu();
		break;

	case 2:
		myGameState = EGameState::EQuitting;
		break;
	}
}

void Game::GameMenu()
{
	bool tempLoop = true;
	while (tempLoop)
	{
		CLSSlow();
		WriteLine("____| Select |____\n[1] Enter Dungeon\n[2] Inventory\n[3] Long rest\n[4] Shop\n[5] Quit game");
		switch (GetInput())
		{
		case 1:
			//tempLoop = false;
			myDungeon->Enter();
			break;
		case 2:
			//tempLoop = false;
			myPlayer->ShowInventory();
			break;
		case 3:
		//	tempLoop = false;
			myPlayer->LongRest();
			break;
		case 4:
			//tempLoop = false;
			// TODO: Add a shop
			break;
		case 5:
			if (Confirm())
			{
				tempLoop = false;
				myGameState = EGameState::EQuitting;
			}
			break;
		}
	}
}

Player& Game::GetPlayer()
{
	return *myPlayer;
}
