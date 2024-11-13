#include "battle.hpp"

/* Default constructor for Battle object,
initilizes all values to default state */ 
Battle::Battle() {
    turnCounter = 0;
}

/* Default destructor for Battle object,
initilizes all values to default state */ 
Battle::~Battle() {}

/* The main driver for Pokemon battles, takes in
the user's Pokemon and the enemy Pokemon */
void Battle::fight(Poke& userPoke, Poke& enemyPoke) {
    // Increment turn counter by 1
    turnCounter += 1;

    // Get action from user

    // Get action from enemy

    // Calculate turn order + anything else

    // Resolve turn moves

    // Check win conitions + level up stuff if necessary
}