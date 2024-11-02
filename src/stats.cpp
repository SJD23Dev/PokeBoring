#include "stats.hpp"

/* Default constructor for Stats object,
initilizes all values to default state */ 
Stats::Stats() {
    hp = -99;
    attack = -99;
    defense = -99;
    speAttack = -99;
    speDefense = -99;
    speed = -99;
}

/* Default destructor for Stats object */
Stats::~Stats() {}

/* Sets Stat object's hitpoints stat */
void Stats::setHP(int input) {
    hp = input;
}

/* Sets Stat object's attack stat */
void Stats::setAttack(int input) {
    attack = input;
}

/* Sets Stat object's defense stat */
void Stats::setDefense(int input) {
    defense = input;
}

/* Sets Stat object's special attack stat */
void Stats::setSpeAttack(int input) {
    speAttack = input;
}

/* Sets Stat object's special defense stat */
void Stats::setSpeDefense(int input) {
    speDefense = input;
}

/* Sets Stat object's speed stat */
void Stats::setSpeed(int input) {
    speed = input;
}

/* Gets Stat object's hitpoint stat,
returns as an integer */
const int Stats::getHP() const {
    return hp;
}

/* Gets Stat object's attack stat,
returns as an integer */
const int Stats::getAttack() const {
    return attack;
}

/* Gets Stat object's defense stat,
returns as an integer */
const int Stats::getDefense() const {
    return defense;
}

/* Gets Stat object's special attack stat,
returns as an integer */
const int Stats::getSpeAttack() const {
    return speAttack;
}

/* Gets Stat object's special defense stat,
returns as an integer */
const int Stats::getSpeDefense() const {
    return speDefense;
}

/* Gets Stat object's speed stat,
returns as an integer */
const int Stats::getSpeed() const {
    return speed;
}