#ifndef PCH_H
#define PCH_H

#include <string>
#include <iostream>
#include <memory>


inline void WriteLine(const std::string tempValue)
{
	std::cout << tempValue << std::endl;
}

inline void WriteLine(std::string &tempValue)
{
	std::cout << tempValue << std::endl;
}

inline void CLS()
{
	std::cout << std::string(75, '\n');
}

template<typename T> void SafeDelete(T*& tempItemToDelete)
{
	delete tempItemToDelete;
	tempItemToDelete = NULL;
}

#endif