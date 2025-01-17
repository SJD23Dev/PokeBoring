#pragma once

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "curlHelpers.hpp"

class Move {
    public:
        // Constructors
        Move();
        Move(std::string nameDeclaration);
        ~Move();

        // Setters
        void setID(int input);
        void setName(std::string input);
        void setPower(int input);
        void setPP(int input);
        void setPriority(int input);
        void setAccuracy(int input);
        void setLevelLearnedAt(int input);

        // Getters
        const int getID() const;
        const std::string getName() const;
        const int getPower() const;
        const int getPP() const;
        const int getPriority() const;
        const int getAccuracy() const;
        const int getLevelLearnedAt() const;
    private:
        int id;
        std::string name;
        int power;
        int pp;
        int priority;
        int accuracy;
        int levelLearnedAt;
};

namespace moveDataFetcher {
    bool fetch(Move& move);
    void connect(Move& moveToConnect, std::string readBuffer);   
}