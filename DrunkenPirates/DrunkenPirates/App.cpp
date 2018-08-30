#include "pch.h"
#include "App.h"


App::App() : myAppState(Appstate::MENU), myShouldExit(false)
{
}


App::~App()
{
}

void App::Run()
{
	// TODO: Add logic for different states

	while (!myShouldExit) 
	{
		switch (myAppState)
		{
			case Appstate::MENU:

				break;

			case Appstate::PLAYING:

				break;
		}
	}
}

void App::Exit()
{
	myShouldExit = true;
}
