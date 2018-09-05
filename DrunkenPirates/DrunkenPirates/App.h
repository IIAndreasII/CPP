#ifndef APP_H
#define APP_H

#include "AppstateEnum.h"
#include "pch.h"
#include "Game.h"

class App
{
public:
	App();
	~App();

	void Run();

	void Play();
	void Exit();

	bool MainMenu();

	void GameMenu();

	Game& GetGame();

private:


	Appstate myAppState;

	Game myGame;

	bool myShouldExit;


};

#endif