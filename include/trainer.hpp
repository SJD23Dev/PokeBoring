#ifndef TRAINER_HPP
#define TRAINER_HPP

#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "random.hpp"
#include "poke.hpp"

extern std::mt19937 rng;

class Trainer {
    public:
        // Constructors
        Trainer();
        ~Trainer();

        // Setters
        void setName(std::string input);

        // Getters
        const std::string getName() const;

        // Generation functions
        void generateRandom(int numberOfPokemon);

        // Pokemon inventory functions
        bool pokeInventoryAdd(Poke pokeToAdd);
        bool pokeInventoryRemove(int index);
        void pokeInventoryPrint();
    private:
        std::string name;
        std::vector<Poke> pokeInventory;
        int pokeInventoryCounter;
};

struct Names {
    bool getNames();
    std::string generateRandomName();
    std::vector<std::string> firstNameList;
    std::vector<std::string> lastNameList;
};

#endif