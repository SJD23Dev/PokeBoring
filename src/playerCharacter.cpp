#include "playerCharacter.hpp"

PlayerCharacter::PlayerCharacter() {
    pokeInventoryCounter = 0;
}

PlayerCharacter::~PlayerCharacter() {}

void PlayerCharacter::pokeInventoryAdd(Poke pokeToAdd) {
    pokeInventory[pokeInventoryCounter] = pokeToAdd;
    pokeInventoryCounter += 1;
}

void PlayerCharacter::pokeInventoryRemove(int index) {
    pokeInventory[2].
}