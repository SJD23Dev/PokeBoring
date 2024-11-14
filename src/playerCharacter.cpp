#include "playerCharacter.hpp"

/* Default constructor for PlayerCharacter object,
initilizes all values to default state */ 
PlayerCharacter::PlayerCharacter() {
    pokeInventoryCounter = 0;

    activePoke[0] = nullptr;
}

/* Default destructor for PlayerCharacter object,
initilizes all values to default state */ 
PlayerCharacter::~PlayerCharacter() {}

/* If space, add Poke object into PC's Poke Inventory */
bool PlayerCharacter::pokeInventoryAdd(Poke pokeToAdd) {
    if (pokeInventory.size() >= 6) {
        return false;
    } else {
        pokeInventory.push_back(pokeToAdd);
        pokeInventoryCounter++;
        return true;
    }
}

/* Remove Poke from PC's Poke Inventory at given index */
bool PlayerCharacter::pokeInventoryRemove(int index) {
    if (pokeInventory.size() <= 0) {
        return false;
    } else {
        pokeInventory.erase(pokeInventory.begin() + index);
        pokeInventoryCounter--;
        return true;
    }
}

/* Print the PC's Poke Inventory to the teminal */
void PlayerCharacter::pokeInventoryPrint() {
    std::cout << "Pokémon Inventory [" << pokeInventoryCounter << "/" << 6 << "]:" << std::endl;
    for (int i = 0; i < pokeInventory.size(); i++) {
        std::cout << i + 1 << ". " << pokeInventory[i].getName() << " | lvl " << pokeInventory[i].getLevel();
        if (pokeInventory[i].getIsFighting() == true) {
            std::cout << " | ACTIVE!" << std::endl;
        } else {
            std::cout << std::endl;
        }
    }
}

/* Assigns the Poke in the PC's Poke Inventory (1-6) to the 
Active Poke array */
void PlayerCharacter::activePokeSetFrom(int pokeInventorySlot) {
    int index = pokeInventorySlot - 1;

    for (auto& poke : pokeInventory) {
        poke.setIsFighting(false);
    }

    activePoke[0] = &pokeInventory[index];
    activePoke[0]->setIsFighting(true);
}

/* Assigns a Poke object to the PC's Active Poke array */
void PlayerCharacter::activePokeSet(Poke& pokeToSet) {
    if (activePoke[0] != nullptr) {
        activePoke[0]->setIsFighting(false);
    }

    activePoke[0] = &pokeToSet;
    activePoke[0]->setIsFighting(true);
}

/* Generate and add random lvl 1 Poke's to the PC's inventory,
numberOfPoke will generate 1-6 Poke's */
void PlayerCharacter::populateInventoryWithRandom(int numberOfPoke) {
    for (int i = 0; i < numberOfPoke; i++) {
        std::uniform_int_distribution<int> range(0, 1024);
        int randomID = range(rng);

        Poke poke(randomID);
        pokeDataFetcher::fetch(poke);

        pokeInventoryAdd(poke);

        if (i == 0) {
            activePokeSet(poke);
            pokeInventory[i].setIsFighting(true);
        }
    }
}