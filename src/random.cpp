#include "random.hpp"

std::mt19937 rng;

void seedRNG() {
    rng.seed(static_cast<unsigned>(std::time(nullptr)));
}