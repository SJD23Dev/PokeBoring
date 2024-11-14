#include "random.hpp"

std::mt19937 rng;

/* Seed the MT with the current CPU time */
void seedRNG() {
    rng.seed(static_cast<unsigned>(std::time(nullptr)));
}