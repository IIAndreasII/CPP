#ifndef PCH_H
#define PCH_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>

template<typename T> void SafeDelete(T*& aPtrToDelete)
{
	delete (aPtrToDelete);
	aPtrToDelete = NULL;
}

#endif
