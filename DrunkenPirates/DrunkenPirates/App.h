#ifndef APP_H
#define APP_H

#include "AppstateEnum.h"
#include "pch.h"

class App
{
public:
	App();
	~App();

	void Run();
	void Exit();

	bool Menu();

private:

	Appstate myAppState;

	bool myShouldExit;
};

#endif