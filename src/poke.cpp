#include "Poke.hpp"

/* Default constructor for Poke object,
initilizes all values to default state */ 
Poke::Poke() {
    id = -99;
    name = "default";
}

/* Constructor that allows declaration of
an ID along with the default Poke object */
Poke::Poke(int idDecleration) {
    id = idDecleration;
    name = "default";
}

/* Default destructor for Poke object */
Poke::~Poke() {}

/* Sets Poke object's id */
void Poke::setID(int input) {
    id = input;
}

/* Sets Poke object's name */
void Poke::setName(std::string input) {
    name = input;
}

/* Gets Poke object's id,
returns as an integer */
const int Poke::getID() const {
    return id;
}

/* Gets Poke object's name,
returns as a string */
const std::string Poke::getName() const {
    return name;
}