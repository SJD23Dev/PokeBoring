#ifndef LEVELMECHANICS_HPP
#define LEVELMECHANICS_HPP

#include "poke.hpp"

namespace levelMechanics {
    // Gain formula functions
    int gfErratic(int n);
    int gfFast(int n);
    int gfMediumFast(int n);
    int gfMediumSlow(int n);
    int gfSlow(int n);
    int gfFluctuating(int n);
} 

#endif