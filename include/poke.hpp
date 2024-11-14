#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "curlHelpers.hpp"
#include "stats.hpp"
#include "move.hpp"

class Poke {
    public:
        // Constructors
        Poke();
        Poke(int idDeclaration);
        ~Poke();

        // Setters
        void setID(int input);
        void setName(std::string input);
        void setLevel(int input);
        void setSprite(std::string input);
        void setStatHP(int input);
        void setStatAttack(int input);
        void setStatDefense(int input);
        void setStatSpeAttack(int input);
        void setStatSpeDefense(int input);
        void setStatSpeed(int input);
        void setIsFighting(bool input);

        // Getters
        const int getID() const;
        const std::string getName() const;
        const int getLevel() const;
        const std::string getSprite() const;
        const int getStatHP() const;
        const int getStatAttack() const;
        const int getStatDefense() const;
        const int getStatSpeAttack() const;
        const int getStatSpeDefense() const;
        const int getStatSpeed() const;
        const bool getIsFighting() const;
        
        // Move set functions
        void moveSetAdd(Move move);
        bool moveSetCheckFor(std::string moveName);
        void moveSetPrint();

        // Active move set functions
        void activeMoveSetInitilize();
        const Move activeMoveSetGet(int index) const;
        void activeMoveSetPrint();
    private:
        int id;
        std::string name;
        int level;
        std::string sprite;
        Stats stats;
        std::vector<Move> moveSet; // Vector of all learnable moves through level up
        Move activeMoveSet[4]; // Array with 4 slots for active/playable moves
        bool isFighting; // Flag for determining if a Poke is "active" (in combat/chosen to be sent out)
};

namespace pokeDataFetcher {
    bool fetch(Poke& poke);
    void connect(Poke& pokeToConnect, std::string readBuffer);
    void connectMoves(Poke& pokeToConnect, nlohmann::json jsonFile);
    bool connectSprite(Poke& pokeToConnect);
}

#endif