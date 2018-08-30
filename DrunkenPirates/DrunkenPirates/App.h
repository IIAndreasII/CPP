#pragma once

#include "AppstateEnum.h"
#include "pch.h"

class App
{
public:
	App();
	~App();

	void Run();
	void Exit();

private:

	Appstate myAppState;

	bool myShouldExit;
};

