#include "pch.h"
#include "App.h"

App::App() : myAppstate(Appstate::MENU), myShouldExit(false), myPlayer()
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
		switch (myAppstate)
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
		SetAppstate(Appstate::PLAYING);
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

void App::GameMenu()
{
	bool tempLoop = true;

	while (tempLoop)
	{
		CLSUnsafe();
		WriteLine("[1] Venture the seas\n[2] View ship\n[3] Back to menu");

		switch (GetInput())
		{
		case 1:

			// TODO: Venture the seas

			tempLoop = false;
			break;

		case 2:

			myPlayer.DisplayShipStatus();

			tempLoop = false;
			break;

		case 3:

			if (Confirm())
			{
				SetAppstate(Appstate::MENU);
				tempLoop = false;
			}
			break;

		default:
			break;
		}
	}
}

Player & App::GetPlayer()
{
	return myPlayer;
}

void App::SetAppstate(const Appstate newValue)
{
	myAppstate = newValue;
}
