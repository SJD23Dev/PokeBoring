#pragma once

#include <random>
#include <ctime>

/* MT for randomness thoughout the program,
seedRNG() should be run at the beginning of main()
and only once! */

extern std::mt19937 rng;
void seedRNG();
