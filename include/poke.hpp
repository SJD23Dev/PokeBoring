#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <fstream>
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
        void setSprite(std::string input);

        // Getters
        const int getID() const;
        const std::string getName() const;
        const std::string getSprite() const;
    private:
        int id;
        std::string name;
        Stats stats;
        std::string sprite;
};

struct pokeDataFetcher {
    bool fetchData(Poke& poke);
    void connectData(Poke& pokeToConnect, std::string readBuffer);

    bool setSprite(Poke& pokeToConnect, nlohmann::json jsonFile);
};

#endif