#include "stdafx.h"
#include "Util.h"
#include "Game.h"

std::default_random_engine s_RandEng;

Game s_Game;

int RNG(int min, int max)
{
	//std::uniform_int_distribution<int> tempDist(min, max);
	return (rand() % (max - min + 1)) + min;
}

inline void WriteLine(std::string tempValue)
{
	std::cout << tempValue << std::endl;
}

/*inline void WriteLine(const std::string tempValue)
{
std::cout << tempValue << std::endl;
}*/

inline void CLS()
{
	std::cout << std::string(29
		, '\n');
}

inline void CLSSlow()
{
	system("CLS");
}

inline int GetInput()
{
	std::string tempStringToParse;
	std::cin >> tempStringToParse;
	int tempValuetoReturn = 0;
	try
	{
		tempValuetoReturn = std::stoi(tempStringToParse);
	}
	catch (...)
	{
	}
	return tempValuetoReturn;
}

inline int GetInput(int& out)
{
	std::string tempStringToParse;
	std::cin >> tempStringToParse;
	out = 0;
	try
	{
		out = std::stoi(tempStringToParse);
	}
	catch (...)
	{
	}
	return out;
}

inline bool TryGetInput(int& out)
{
	std::string tempStringToParse;
	std::cin >> tempStringToParse;
	out = 0;
	try
	{
		out = std::stoi(tempStringToParse);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

inline bool Confirm()
{
	WriteLine("Are you sure?\n[1] Yes\n[2] No");
	switch (GetInput())
	{
	case 1:
		CLSSlow();
		return true;
	default:
		CLSSlow();
		return false;
	}
}

template<typename T> void SafeDelete(T*& aPtrToDelete)
{
	delete (aPtrToDelete);
	aPtrToDelete = NULL;
}