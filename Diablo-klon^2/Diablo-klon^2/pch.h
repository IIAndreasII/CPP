#ifndef PCH_H
#define PCH_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>


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
	tempItemToDelete = NULL;
}


#endif
