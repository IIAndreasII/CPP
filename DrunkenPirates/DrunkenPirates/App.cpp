#include "pch.h"
#include "App.h"

using namespace std;

App::App() : myAppState(Appstate::MENU), myShouldExit(false)
{
}


App::~App()
{
}

void App::Run()
{
	// TODO: Add logic for different states

	// Main loop

		bool tempStillInMenu;

		switch (myAppState)
		{
			case Appstate::MENU:

				tempStillInMenu = Menu();

				while (!tempStillInMenu) 
				{
					tempStillInMenu = Menu();
				}
				

				break;

			case Appstate::PLAYING:

				break;
		}
	
}

void App::Exit()
{
	myShouldExit = true;
}

bool App::Menu()
{
	CLS();
	WriteLine("Drunken Pirates");
	WriteLine("[1] Play");
	WriteLine("[2] Quit");
	
	string tempInput;
	cin >> tempInput;


	if (tempInput == "1")
	{
		return true;
	}
	else if (tempInput == "2")
	{
		Exit();
		return true;
	}

	return false;
}
