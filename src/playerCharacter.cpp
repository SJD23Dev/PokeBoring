#include "playerCharacter.hpp"

// TODO: Document
PlayerCharacter::PlayerCharacter() {
    pokeInventoryCounter = 0;
}

// TODO: Document
PlayerCharacter::~PlayerCharacter() {}

// TODO: Document
bool PlayerCharacter::pokeInventoryAdd(Poke pokeToAdd) {
    if (pokeInventory.size() >= 6) {
        return false;
    } else {
        pokeInventory.push_back(pokeToAdd);
        pokeInventoryCounter++;
        return true;
    }
}

// TODO: Document
bool PlayerCharacter::pokeInventoryRemove(int index) {
    if (pokeInventory.size() <= 0) {
        return false;
    } else {
        pokeInventory.erase(pokeInventory.begin() + index);
        pokeInventoryCounter--;
        return true;
    }
}

// TODO: Document
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

/* Move a Poke from the PC's 6-slot Poke Inventory vector 
to the 1-slot Active Poke array */
void PlayerCharacter::activePokeSwap(int fromPokeInventoryIndex) {
    Poke temp = activePoke[0];

    activePoke[0] = pokeInventory[fromPokeInventoryIndex];
    activePoke[0].setIsFighting(true);

    pokeInventory[fromPokeInventoryIndex] = temp;
    pokeInventory[fromPokeInventoryIndex].setIsFighting(false);
}

// TODO: Document
void PlayerCharacter::activePokeSet(Poke& pokeToSet) {
    activePoke[0] = pokeToSet;
    activePoke[0].setIsFighting(true);
}

// TODO: Document
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