#ifndef STATS_HPP
#define STATS_HPP

class Stats {
    public:
        // Constructors
        Stats();
        ~Stats();

        // Setters
        void setHP(int input);
        void setAttack(int input);
        void setDefense(int input);
        void setSpeAttack(int input);
        void setSpeDefense(int input);
        void setSpeed(int input);

        // Getters
        const int getHP() const;
        const int getAttack() const;
        const int getDefense() const;
        const int getSpeAttack() const;
        const int getSpeDefense() const;
        const int getSpeed() const;
    private:
        int hp;

        int attack;
        int defense;

        int speAttack;
        int speDefense;

        int speed;
};

#endif