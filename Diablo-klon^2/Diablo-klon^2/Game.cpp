#include "stdafx.h"
#include "Game.h"
#include "Util.h"
#include "Player.h"
#include "Shop.h"

Game::Game() :
	myGameState(EGameState::EMenu),
	myPlayer(new Player()),
	myDungeon(),
	myShop(new Shop())
{
	myPlayer->SetShopPtr(myShop);
	myShop->SetPlayerPtr(myPlayer);
}

Game::~Game()
{
	SafeDelete(myPlayer);
	SafeDelete(myShop);
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

void Game::Reset()
{
	myPlayer->Init();
	myDungeon.Reset(myPlayer->GetLevel());
}

void Game::MainMenu()
{
	Reset();
	CLSSlow();
	Print("Diabloclone^2\n[1] Play\n[2] Instructions\n[3] Quit");

	switch (GetInput())
	{
	case 1:
		CLSSlow();
		Print("Foul beasts have been eviscerating people as they please for decades.\nAre you ready to rid the world of said foul beasts by raiding their dungeons?\n[1] Of course!\n[2] Hell nah!");
		switch (GetInput())
		{
		case 1:
			GameMenu();
			break;
		}
		break;
	case 2:
		Instructions();
		break;
	case 3:
		if (Confirm())
		{
			myGameState = EGameState::EQuitting;
		}
		break;
	}
}

void Game::GameMenu()
{
	myShop->Restock();
	bool tempLoop = true;
	while (tempLoop)
	{
		if (myPlayer->GetHealth() <= 0)
		{
			break;
		}

		CLSSlow();
		myPlayer->PrintUI();
		Print("____| Select |____\n[1] Enter Dungeon\n[2] Inventory\n[3] Long rest\n[4] Shop\n[5] Quit game");
		switch (GetInput())
		{
		case 1:
			myDungeon.Reset(myPlayer->GetLevel());
			myDungeon.Enter(*myPlayer);
			myShop->Restock();
			break;
		case 2:
			myPlayer->ShowInventory();
			break;
		case 3:
			myPlayer->LongRest();
			break;
		case 4:
			myShop->Enter();
			break;
		case 5:
			if (Confirm())
			{
				tempLoop = false;
				myGameState = EGameState::EMenu;
			}
			break;
		}
	}
}

void Game::Instructions()
{
	bool tempLoop = true;
	while (tempLoop)
	{
		CLSSlow();
		Print("Diabloclone^2\n\nDungeons: Enter a dungeon and battle enemies to gain loot and experience\n\nItems: Different items have different types (e.g Sword, Armour, Ring).\n       Items with the same type can be combined into a more powerful version in exchange for gold\n\nSkills: Different skills strikes the enemy in different ways. \n        You gain access to more skills in the shop by leveling up\n\nDamagetypes: There are two different types of damage; magical and physical. \n             Pay attention to the enemies' names as they can help you rule out what doesn't damage them\n\nStrength: Empowers your physical damage output\n\nIntelligence: Empowers your magical damage output\n\n[1] Back");

		switch (GetInput())
		{
		case 1:
			tempLoop = false;
			break;
		default:
			break;
		}
	}
}