#ifndef PCH_H
#define PCH_H

#include <string>
#include <iostream>
#include <vector>

template<typename T> void SafeDelete(T*& aPtrToDelete)
{
	delete (aPtrToDelete);
	aPtrToDelete = nullptr;
}

#endif