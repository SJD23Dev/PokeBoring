#pragma once

#include <iostream>
#include <vector>
#include "poke.hpp"
#include "random.hpp"

extern std::mt19937 rng;

class PlayerCharacter {
    public:
        // Constructors
        PlayerCharacter();
        ~PlayerCharacter();

        // Pokemon inventory functions
        bool pokeInventoryAdd(Poke pokeToAdd);
        bool pokeInventoryRemove(int index);
        void pokeInventoryPrint();

        // Active pokemon functions
        void activePokeSet(Poke& pokeToSet);
        void activePokeSetFrom(int pokeInventorySlot);

        // Generation functions
        void populateInventoryWithRandom(int numberOfPoke);
    private:
        Poke* activePoke[1];
        Poke* active;

        std::vector<Poke> pokeInventory;
        int pokeInventoryCounter;
};