#include "stdafx.h"
#include "Util.h"

std::default_random_engine s_RandEng;

int RNG(int min, int max)
{
	std::uniform_int_distribution<int> tempDist(min, max);
	return (tempDist(s_RandEng) % (max - min + 1)) + min;
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

template<typename T> void SafeDelete(T*& tempItemToDelete)
{
	delete tempItemToDelete;
	tempItemToDelete = nullptr;
}