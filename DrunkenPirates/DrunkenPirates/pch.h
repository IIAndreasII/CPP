#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here


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
	system("CLS");
}

template<typename T> void SafeDelete(T*& tempItemToDelete)
{
	delete tempItemToDelete;
	tempItemToDelete = NULL;
}

#endif

