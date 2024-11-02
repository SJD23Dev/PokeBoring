#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include "stats.hpp"

class Poke {
    public:
        // Constructors
        Poke();
        ~Poke();

        // Setters
        void setID(int input);
        void setName(std::string input);

        // Getters
        const int getID() const;
        const std::string getName() const;
    private:
        int id;
        std::string name;
        Stats stats;
};

#endif