#ifndef MOVES_HPP
#define MOVES_HPP

#include <string>

class Move {
    public:
        // Constructors
        Move();
        ~Move();

        // Setters
        void setID(int input);
        void setName(std::string input);
        void setPower(int input);
        void setPP(int input);
        void setPriority(int input);
        void setAccuracy(int input);

        // Getters
        const int getID() const;
        const std::string getName() const;
        const int getPower() const;
        const int getPP() const;
        const int getPriority() const;
        const int getAccuracy() const;
    private:
        int id;
        std::string name;
        int power;
        int pp;
        int priority;
        int accuracy;
};

#endif