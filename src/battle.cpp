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
    while (true) {
        // Increment turn counter by 1
        turnCounter += 1;

        // Get action from user
        Move userMove = getUserMove(userPoke);

        // Get action from enemy
        Move enemyMove = getEnemyMove(enemyPoke);

        // Resolve moves
        moveResolution(userPoke, enemyPoke, userMove, enemyMove);

        // Check win conitions + level up stuff if necessary
    }
}

Move Battle::getUserMove(Poke& userPoke) {
    userPoke.activeMoveSetPrint();
    std::cout << "I select (input index) -> ";
    int moveSelection;
    std::cin >> moveSelection;
    Move userMove = userPoke.activeMoveSetGet(moveSelection - 1);
    return userMove;
}

Move Battle::getEnemyMove(Poke& enemyPoke) {
    enemyPoke.activeMoveSetPrint();
    std::cout << "I select (input index) -> ";
    int moveSelection;
    std::cin >> moveSelection;
    Move userMove = enemyPoke.activeMoveSetGet(moveSelection - 1);
    return userMove;
}

void Battle::moveResolution(Poke& userPoke, Poke& enemyPoke, Move& userMove, Move& enemyMove) {
    int turnOrder = getTurnOrder(userPoke, enemyPoke, userMove, enemyMove);

    switch (turnOrder) {
        case 0:
            std::cout << userPoke.getName() + " plays " + userMove.getName() + "!" << std::endl
                      << enemyPoke.getName() + " plays " + enemyMove.getName() + "!" << std::endl;
                      break;
        case 1:
            std::cout << enemyPoke.getName() + " plays " + enemyMove.getName() + "!" << std::endl
                      << userPoke.getName() + " plays " + userMove.getName() + "!" << std::endl;    
                      break;    
    }
}

/* Calculate turn order of battle and returns 0 or 1,
0 = user first, 1 = enemy first */
int Battle::getTurnOrder(Poke& userPoke, Poke& enemyPoke, Move& userMove, Move& enemyMove) {
    if (userMove.getPriority() > enemyMove.getPriority()) {
        return 0;
    } else if (userMove.getPriority() < enemyMove.getPriority()) {
        return 1;
    } else if (userPoke.getStatSpeed() > enemyPoke.getStatSpeed()) {
        return 0;
    } else if (userPoke.getStatSpeed() < enemyPoke.getStatSpeed()) {
        return 1;
    } else {
        // TODO: Randomly generate 1 or 0 to make ties fair
        return 0;
    }
}