// Diablo-klon^2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "pch.h"
#include "Util.h"



int main()
{
	unsigned tempSeed = std::chrono::system_clock::now().time_since_epoch().count();
	
	s_RandEng.seed(tempSeed);

	Game tempGame;
	s_Game = tempGame;
	return s_Game.Play();
}