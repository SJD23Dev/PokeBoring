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
    private:
        int id;
        std::string name;
        std::string sprite;
        Stats stats;
};

struct pokeDataFetcher {
    bool fetchData(Poke& poke);
    void connectData(Poke& pokeToConnect, std::string readBuffer);
    bool downloadSprite(Poke& pokeToConnect, nlohmann::json jsonFile);
};

#endif