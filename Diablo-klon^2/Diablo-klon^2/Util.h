#ifndef UTIL_H
#define UTIL_H

#include "pch.h"
#include <chrono>
#include <random>

extern std::default_random_engine s_RandEng;

extern inline void WriteLine(std::string tempValue);

extern inline void CLS();

extern inline void CLSSlow();

extern inline int GetInput();

extern inline bool Confirm();

extern int RNG(int min, int max);

#endif