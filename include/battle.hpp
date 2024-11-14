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
        Move getUserMove(Poke& userPoke);
        Move getEnemyMove(Poke& enemyPoke);
        void moveResolution(Poke& userPoke, Poke& enemyPoke, Move& userMove, Move& enemyMove);
        int getTurnOrder(Poke& userPoke, Poke& enemyPoke, Move& userMove, Move& enemyMove);
    private:
        int turnCounter;
};

#endif