#include "levelMechanics.hpp"

int levelMechanics::gfErratic(int n) {
    if (n < 50) {
        int xpToLevelUp = ((pow(n,3) * (100-n)) / 50);
        return xpToLevelUp;
    } else if (n >= 50 && n < 68) {
        int xpToLevelUp = ((pow(n,3) * (150-n)) / 100);
        return xpToLevelUp;
    } else if (n >= 68 && n < 98) {
        int xpToLevelUp = (pow(n,3) * ((1911 - (10*n)) / 3));
        return xpToLevelUp;
    } else {
        int xpToLevelUp = ((pow(n,3) * (160-n)) / 100);
        return xpToLevelUp;
    }
}

int levelMechanics::gfFast(int n) {
    int xpToLevelUp = ((4 * pow(n,3))/5);
    return xpToLevelUp;
}

int levelMechanics::gfMediumFast(int n) {
    int xpToLevelUp = pow(n,3);
    return xpToLevelUp;
}

int levelMechanics::gfMediumSlow(int n) {
    int xpToLevelUp = ((1.2 * pow(n,3)) - (15 * pow(n,2)) + (100*n) - 140);
    return xpToLevelUp;
}

int levelMechanics::gfSlow(int n) {
    int xpToLevelUp = (pow(n,3) * 1.25);
    return xpToLevelUp;
}