#include "levelMechanics.hpp"

/* Returns XP to increase to n level for Erratic fomula,
https://bulbapedia.bulbagarden.net/wiki/Experience */
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

/* Returns XP to increase to n level for Fast fomula,
https://bulbapedia.bulbagarden.net/wiki/Experience */
int levelMechanics::gfFast(int n) {
    int xpToLevelUp = ((4 * pow(n,3))/5);
    return xpToLevelUp;
}

/* Returns XP to increase to n level for Medium-Fast fomula,
https://bulbapedia.bulbagarden.net/wiki/Experience */
int levelMechanics::gfMediumFast(int n) {
    int xpToLevelUp = pow(n,3);
    return xpToLevelUp;
}

/* Returns XP to increase to n level for Medium-Slow fomula,
https://bulbapedia.bulbagarden.net/wiki/Experience */
int levelMechanics::gfMediumSlow(int n) {
    int xpToLevelUp = ((1.2 * pow(n,3)) - (15 * pow(n,2)) + (100*n) - 140);
    return xpToLevelUp;
}

/* Returns XP to increase to n level for Slow fomula,
https://bulbapedia.bulbagarden.net/wiki/Experience */
int levelMechanics::gfSlow(int n) {
    int xpToLevelUp = (pow(n,3) * 1.25);
    return xpToLevelUp;
}

/* Returns XP to increase to n level for Fluctuating fomula,
https://bulbapedia.bulbagarden.net/wiki/Experience */
int levelMechanics::gfFluctuating(int n) {
    if (n < 15) {
        int xpToLevelUp = (pow(n,3) * (((n+1) / 3) + 24));
        return xpToLevelUp;
    } else if (n >= 15 && n < 36) {
        int xpToLevelUp = ((pow(n,3) * (n + 14)) / 50);
        return xpToLevelUp;
    } else {
        int xpToLevelUp = ((pow(n,3) * ((n/2) + 32)) / 50);
        return xpToLevelUp;
    }
}