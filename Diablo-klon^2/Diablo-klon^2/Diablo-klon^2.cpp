// Diablo-klon^2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "pch.h"
#include "Util.h"
#include <random>



int main()
{
	srand(time(NULL));

	Game tempGame;
	s_Game = tempGame;
	return s_Game.Play();
}