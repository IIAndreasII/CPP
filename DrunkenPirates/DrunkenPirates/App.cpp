#include "pch.h"
#include "App.h"

App::App() : myAppState(Appstate::MENU), myShouldExit(false), myGame()
{
}


App::~App()
{
}

void App::Run()
{
	// TODO: Add logic for different states

	// Main loop
	while (!myShouldExit)
	{
		switch (myAppState)
		{
		case Appstate::MENU:

			while (!MainMenu())
			{
				CLSUnsafe();
			}

			break;

		case Appstate::PLAYING:

			GameMenu();

			break;
		}
	}
}

void App::Play()
{

}

void App::Exit()
{
	myShouldExit = true;
}

bool App::MainMenu()
{
	WriteLine("Drunken Pirates\n[1] Play\n[2] Quit");
	
	switch (GetInput())
	{
	case 1:
		myAppState = Appstate::PLAYING;
		return true;

	case 2:
		if (Confirm())
		{
			Exit();
		}
		return true;

	default:
		return false;
	}
}



Game& App::GetGame()
{
	return myGame;
}

