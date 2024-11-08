#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "curlHelpers.hpp"
#include "stats.hpp"

class Poke {
    public:
        // Constructors
        Poke();
        Poke(int idDecleration);
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

struct pokeDataFetcher {
    bool fetchData(Poke& poke);
    void connectData(Poke& pokeToConnect, std::string readBuffer);
};

#endif