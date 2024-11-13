#include "move.hpp"

/* Default constructor for Move object,
initilizes all values to default state */ 
Move::Move() {
    id = -99;
    name = "default";
    power = -99;
    pp = -99;
    priority = -99;
    accuracy = -99;
}

/* Default destructor for Move object,
initilizes all values to default state */
Move::~Move() {}

/* Sets Move object's id */
void Move::setID(int input) {
    id = input;
}

/* Sets Move object's name */
void Move::setName(std::string input) {
    name = input;
}

/* Sets Move object's power */
void Move::setPower(int input) {
    power = input;
}

/* Sets Move object's pp */
void Move::setPP(int input) {
    pp = input;
}

/* Sets Move object's priority */
void Move::setPriority(int input) {
    priority = input;
}

/* Sets Move object's accuracy */
void Move::setAccuracy(int input) {
    accuracy = input;
}

/* Gets Move object's id,
returns as an integer */
const int Move::getID() const {
    return id;
}

/* Gets Move object's name,
returns as a string */
const std::string Move::getName() const {
    return name;
}

/* Gets Move object's power,
returns as an integer */
const int Move::getPower() const {
    return power;
}

/* Gets Move object's pp,
returns as an integer */
const int Move::getPP() const {
    return pp;
}

/* Gets Move object's priority,
returns as an integer */
const int Move::getPriority() const {
    return priority;
}

/* Gets Move object's accuracy,
returns as an integer */
const int Move::getAccuracy() const {
    return accuracy;
}