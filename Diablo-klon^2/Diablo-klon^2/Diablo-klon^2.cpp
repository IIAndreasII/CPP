// Diablo-klon^2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "pch.h"
#include "Util.h"
#include "Game.h"

int main()
{
	/* Init rng */
	srand(time(NULL));

	Game tempGame;
	return tempGame.Play();
}