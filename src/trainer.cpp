#include "trainer.hpp"

/* Default constructor for Trainer object,
initilizes all values to default state */ 
Trainer::Trainer() {
    name = "default";
}

/* Default destructor for Trainer object,
initilizes all values to default state */ 
Trainer::~Trainer() {}

/* Sets Trainer objects name */
void Trainer::setName(std::string input) {
    name = input;
}

/* Gets Trainer objects name,
returns as a string */
const std::string Trainer::getName() const {
    return name;
}

/* Generate a completely random Trainer with
the entered number of Poke's */
void Trainer::generateRandom(int numberOfPokemon) {
    Names name;
    setName(name.generateRandomName()); // Give Trainer object a random name from /assets/txt/

    // Generate 'n' number of Pokemon
    for (int i = 0; i < numberOfPokemon; i++) {
        std::uniform_int_distribution<int> range(0, 1024);
        int randomID = range(rng);
        Poke poke(randomID);
        pokeDataFetcher::fetch(poke);
        pokeInventoryAdd(poke);
    }
}

/* Add entered Poke object to Trainer's
Poke Inventory */
bool Trainer::pokeInventoryAdd(Poke pokeToAdd) {
    if (pokeInventory.size() >= 6) {
        return false;
    } else {
        pokeInventory.push_back(pokeToAdd);
        pokeInventoryCounter++;
        return true;
    }
}

/* Remove Poke at entered index 
from Trainer's Poke Inventory */
bool Trainer::pokeInventoryRemove(int index) {
    if (pokeInventory.size() <= 0) {
        return false;
    } else {
        pokeInventory.erase(pokeInventory.begin() + index);
        pokeInventoryCounter--;
        return true;
    }
}

/* Print the Trainer's Poke Inventory to the terminal */
void Trainer::pokeInventoryPrint() {
    std::cout << getName() << "'s Pokémon Inventory [" << pokeInventory.size() << "/" << 6 << "]:" << std::endl;
    for (int i = 0; i < pokeInventory.size(); i++) {
        std::cout << i + 1 << ". " << pokeInventory[i].getName() << " | lvl " << pokeInventory[i].getLevel() << std::endl;
    }
}

/* Load in last and first names into a Name's object */
bool Names::getNames() {
    std::ifstream fileFirstNames("/home/sjd23/projects/PokeBoring/assets/txt/trainer_first_names.txt");
    std::ifstream fileLastName("/home/sjd23/projects/PokeBoring/assets/txt/trainer_last_names.txt");

    if (!fileFirstNames.is_open()) {
        std::cerr << "Error: Could not open /home/sjd23/projects/PokeBoring/assets/txt/trainer_first_names.txt" << std::endl;
        return false;
    }

    if (!fileLastName.is_open()) {
        std::cerr << "Error: Could not open /home/sjd23/projects/PokeBoring/assets/txt/trainer_last_names.txt" << std::endl;
        return false;
    }

    std::string firstName;
    while (fileFirstNames >> firstName) {
        firstNameList.push_back(firstName);
    }

    std::string lastName;
    while (fileLastName >> lastName) {
        lastNameList.push_back(lastName);
    }

    fileFirstNames.close();
    fileLastName.close();

    return true;
}

/* Generate a random name,
return as a string */
std::string Names::generateRandomName() {
    std::uniform_int_distribution<int> range1(0, firstNameList.size() - 1);
    std::uniform_int_distribution<int> range2(0, lastNameList.size() - 1);

    int firstIndex = range1(rng);
    int lastIndex = range2(rng);

    return firstNameList[firstIndex] + " " + lastNameList[lastIndex];
}