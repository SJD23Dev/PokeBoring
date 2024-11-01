#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>

class Poke {
    public:
        // Constructors
        Poke();
        ~Poke() {}

        // Setters
        void setID(int input) {id = input;}
        void setName(std::string input) {name = input;}

        // Getters
        const int getID() const {return id;}
        const std::string getName() const {return name;}
    private:
        int id;
        std::string name;
};

#endif