#ifndef PCH_H
#define PCH_H

#include <string>
#include <iostream>
#include <memory>


inline void WriteLine(std::string tempValue)
{
	std::cout << tempValue << std::endl;
}

/*inline void WriteLine(std::string tempValue)
{
	std::cout << tempValue << std::endl;
}*/

inline void CLS()
{
	std::cout << std::string(50, '\n');
}

inline void CLSUnsafe()
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
		CLSUnsafe();
		return true;
	default:
		CLSUnsafe();
		return false;
	}
}

template<typename T> void SafeDelete(T*& tempItemToDelete)
{
	delete tempItemToDelete;
	tempItemToDelete = NULL;
}

#endif