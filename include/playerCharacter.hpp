#ifndef PLAYERCHARACTER
#define PLAYERCHARACTER

#include "poke.hpp"

class PlayerCharacter {
    public:
        // Constructors
        PlayerCharacter();
        ~PlayerCharacter();

        // Pokemon inventory functions
        void pokeInventoryAdd(Poke pokeToAdd);
        void pokeInventoryRemove(int index);
        void pokeInventoryPrint();
    private:
        Poke pokeInventory[6];
        int pokeInventoryCounter;
};

#endif