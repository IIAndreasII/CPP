#ifndef APP_H
#define APP_H

#include "AppstateEnum.h"
#include "pch.h"
#include "Player.h"

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

	Player& GetPlayer();

	void SetAppstate(const Appstate newValue);

private:


	Appstate myAppstate;

	Player myPlayer;

	bool myShouldExit;


};

#endif