// Diablo-klon^2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <chrono>
#include "Game.h"
#include "Dungeon.h"

int main()
{
	/* Init rng */
	srand(static_cast<unsigned>(time(NULL)));

	Game tempGame;
	return tempGame.Play();
}