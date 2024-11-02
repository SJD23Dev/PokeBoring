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

/* Set Stat object's hitpoints stat */
void Stats::setHP(int input) {
    hp = input;
}

/* Set Stat object's attack stat */
void Stats::setAttack(int input) {
    attack = input;
}

/* Set Stat object's defense stat */
void Stats::setDefense(int input) {
    defense = input;
}

/* Set Stat object's special attack stat */
void Stats::setSpeAttack(int input) {
    speAttack = input;
}

/* Set Stat object's special defense stat */
void Stats::setSpeDefense(int input) {
    speDefense = input;
}

/* Set Stat object's speed stat */
void Stats::setSpeed(int input) {
    speed = input;
}

/* Get Stat object's hitpoint stat,
returns as an integer */
const int Stats::getHP() const {
    return hp;
}

/* Get Stat object's attack stat,
returns as an integer */
const int Stats::getAttack() const {
    return attack;
}

/* Get Stat object's defense stat,
returns as an integer */
const int Stats::getDefense() const {
    return defense;
}

/* Get Stat object's special attack stat,
returns as an integer */
const int Stats::getSpeAttack() const {
    return speAttack;
}

/* Get Stat object's special defense stat,
returns as an integer */
const int Stats::getSpeDefense() const {
    return speDefense;
}

/* Get Stat object's speed stat,
returns as an integer */
const int Stats::getSpeed() const {
    return speed;
}