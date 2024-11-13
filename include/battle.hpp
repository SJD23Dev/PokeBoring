#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "poke.hpp"

class Battle {
    public:
        // Constructors
        Battle();
        ~Battle();

        // Battle functions
        void fight(Poke& userPoke, Poke& enemyPoke);
    private:
        int turnCounter;
};

#endif