#ifndef UTIL_H
#define UTIL_H

#include "pch.h"
#include <chrono>

extern inline void Print(std::string tempValue);

extern inline void CLS();

extern inline void CLSSlow();

extern inline int GetInput();

extern inline int GetInput(int& out);

extern inline bool TryGetInput(int& out);

extern inline bool Confirm();

extern int RNG(int min, int max);

#endif