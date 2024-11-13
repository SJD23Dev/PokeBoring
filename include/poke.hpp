#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <fstream>
#include <cstdlib>
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
        void setStatHP(int input);
        void setStatAttack(int input);
        void setStatDefense(int input);
        void setStatSpeAttack(int input);
        void setStatSpeDefense(int input);
        void setStatSpeed(int input);

        // Getters
        const int getID() const;
        const std::string getName() const;
        const std::string getSprite() const;
        const int getStatHP() const;
        const int getStatAttack() const;
        const int getStatDefense() const;
        const int getStatSpeAttack() const;
        const int getStatSpeDefense() const;
        const int getStatSpeed() const;
    private:
        int id;
        std::string name;
        std::string sprite;
        Stats stats;
};

namespace pokeDataFetcher {
    bool fetch(Poke& poke);
    void connect(Poke& pokeToConnect, std::string readBuffer);
    bool downloadSprite(Poke& pokeToConnect, nlohmann::json jsonFile);
}

#endif