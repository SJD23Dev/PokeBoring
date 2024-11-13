#include "poke.hpp"

/* Default constructor for Poke object,
initilizes all values to default state */ 
Poke::Poke() {
    id = -99;
    name = "default";
    level = -99;
    sprite = "default";

    stats.setHP(-99);
    stats.setAttack(-99);
    stats.setDefense(-99);
    stats.setSpeAttack(-99);
    stats.setSpeDefense(-99);
    stats.setSpeed(-99);
}

/* Constructor that allows declaration of
an ID along with the default Poke object */
Poke::Poke(int idDeclaration) {
    id = idDeclaration;
    name = "default";
    level = -99;
    sprite = "default";

    stats.setHP(-99);
    stats.setAttack(-99);
    stats.setDefense(-99);
    stats.setSpeAttack(-99);
    stats.setSpeDefense(-99);
    stats.setSpeed(-99);
}

/* Default destructor for Poke object */
Poke::~Poke() {
    // remove(sprite.c_str()); // Delete Poke's sprite png from assets/images/sprites
}

/* Sets Poke object's id */
void Poke::setID(int input) {
    id = input;
}

/* Sets Poke object's name */
void Poke::setName(std::string input) {
    name = input;
}

/* Sets Poke object's level */
void Poke::setLevel(int input) {
    level = input;
}

/* Sets Poke object's sprite file location */
void Poke::setSprite(std::string input) {
    sprite = input;
}

/* Sets Poke object's HP stat */
void Poke::setStatHP(int input) {
    stats.setHP(input);
}

/* Sets Poke object's attack stat */
void Poke::setStatAttack(int input) {
    stats.setAttack(input);
}

/* Sets Poke object's defense stat */
void Poke::setStatDefense(int input) {
    stats.setDefense(input);
}

/* Sets Poke object's special attack stat */
void Poke::setStatSpeAttack(int input) {
    stats.setSpeAttack(input);
}

/* Sets Poke object's special defense stat */
void Poke::setStatSpeDefense(int input) {
    stats.setSpeDefense(input);
}

/* Sets Poke object's speed stat */
void Poke::setStatSpeed(int input) {
    stats.setSpeed(input);
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

/* Get Poke object's level,
returns as an int */
const int Poke::getLevel() const {
    return level;
}

/* Gets Poke object's sprite file location,
returns as a string */
const std::string Poke::getSprite() const {
    return sprite;
}

/* Gets Poke object's HP stat,
returns as an integer */
const int Poke::getStatHP() const {
    return stats.getHP();
}

/* Gets Poke object's attack stat,
returns as an integer */
const int Poke::getStatAttack() const {
    return stats.getAttack();
}

/* Gets Poke object's defense stat,
returns as an integer */
const int Poke::getStatDefense() const {
    return stats.getDefense();
}

/* Gets Poke object's special attack stat,
returns as an integer */
const int Poke::getStatSpeAttack() const {
    return stats.getSpeAttack();
}

/* Gets Poke object's special defense stat,
returns as an integer */
const int Poke::getStatSpeDefense() const {
    return stats.getSpeDefense();
}

/* Gets Poke object's speed stat,
returns as an integer */
const int Poke::getStatSpeed() const {
    return stats.getSpeed();
}

/* Adds move to Poke object's move set */
void Poke::moveSetAdd(Move move) {
    moveSet.push_back(move);
}

/* Searches move set for a name match,
returns true or false */
bool Poke::moveSetCheckFor(std::string moveName) {
    for (int i = 0; i < moveSet.size(); i++) {
        if (moveName == moveSet[i].getName()) {
            return true;
        }
    }
    return false;
}

/* Prints total move set to terminal */
void Poke::moveSetPrint() {
    std::cout << "Complete move set for " + getName() + ":" << std::endl;
    for (int i = 0; i < moveSet.size(); i++) {
        std::cout << i + 1 << ". " << moveSet[i].getName() << " | Learned at level: " << moveSet[i].getLevelLearnedAt() << std::endl;
    }
}

/* Initilizes a Poke object's active move set 
to level 1 moves */
void Poke::activeMoveSetInitilize() {
    int maxMoves = 4;
    int addedMoves = 0;
    for (int i = 0; i < moveSet.size(); i++) {
        if (moveSet[i].getLevelLearnedAt() == 1 && addedMoves < maxMoves) {
            activeMoveSet[addedMoves] = moveSet[i];
            addedMoves += 1;
        }
    }
}

/* Prints active move set to terminal */
void Poke::activeMoveSetPrint() {
    std::cout << "Active move set for " + getName() + ":" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << i + 1 << ". " << activeMoveSet[i].getName() << std::endl;
    }
}

/* Downloads and syncs a Poke
object to a PokeAPI JSON file,
returns a boolean true or false */
bool pokeDataFetcher::fetch(Poke& poke) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();

    if (curl) {
        std::string URL = "https://pokeapi.co/api/v2/pokemon/" + std::to_string(poke.getID());

        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            connect(poke, readBuffer);
            return true;
        } else {
            return false;
        }
    }
    return false;
}

/* Assigns the data from the JSON file to the Poke object */
void pokeDataFetcher::connect(Poke& pokeToConnect, std::string readBuffer) {
    auto jsonData = nlohmann::json::parse(readBuffer);

    pokeToConnect.setID(jsonData["id"].get<int>()); // ID
    pokeToConnect.setName(jsonData["name"].get<std::string>()); // Name
    pokeToConnect.setStatHP(jsonData["stats"][0]["base_stat"].get<int>()); // Stat: HP
    pokeToConnect.setStatAttack(jsonData["stats"][1]["base_stat"].get<int>()); // Stat: Attack
    pokeToConnect.setStatDefense(jsonData["stats"][2]["base_stat"].get<int>()); // Stat: Defense
    pokeToConnect.setStatSpeAttack(jsonData["stats"][3]["base_stat"].get<int>()); // Stat: Special Attack
    pokeToConnect.setStatSpeDefense(jsonData["stats"][4]["base_stat"].get<int>()); // Stat: Special Defense
    pokeToConnect.setStatSpeed(jsonData["stats"][5]["base_stat"].get<int>()); // Stat: Speed

    connectMoves(pokeToConnect, jsonData); // Move Set
    pokeToConnect.activeMoveSetInitilize(); // Active (level 1) move set
    pokeToConnect.setLevel(1); // Set to level 1

    connectSprite(pokeToConnect); // Sprite
}

// TODO: Add function comment :)
void pokeDataFetcher::connectMoves(Poke& pokeToConnect, nlohmann::json jsonFile) {
    std::string moveName, moveLearnMethod;
    int moveLevelLearnedAt;

    for (int i = 0; i < jsonFile["moves"].size(); i++) {
        for (int j = 0; j < jsonFile["moves"][i]["version_group_details"].size(); j++) {
            moveLearnMethod = jsonFile["moves"][i]["version_group_details"][j]["move_learn_method"]["name"].get<std::string>();
            moveName = jsonFile["moves"][i]["move"]["name"].get<std::string>();
            moveLevelLearnedAt = jsonFile["moves"][i]["version_group_details"][j]["level_learned_at"].get<int>();
            
            if (moveLearnMethod == "level-up" && !pokeToConnect.moveSetCheckFor(moveName)) {
                Move newMove(moveName);
                moveDataFetcher::fetch(newMove);
                newMove.setLevelLearnedAt(moveLevelLearnedAt);
                pokeToConnect.moveSetAdd(newMove);
            }
        }
    }
}

/* Downloads a Poke object's sprite into assets/images/sprites,
saves file address as Poke object's sprite variable */
bool pokeDataFetcher::connectSprite(Poke& pokeToConnect) {
    CURL* curl;
    CURLcode res;

    // TODO: Fix this to where spritePNG uses a relative path, not the absolute one below
    std::ofstream spritePNG("/home/sjd23/projects/PokeBoring/assets/images/sprites/" + pokeToConnect.getName() + ".png", std::ios::binary);

    curl = curl_easy_init();

    if (curl) {
        std::string URL = "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/" + std::to_string(pokeToConnect.getID()) + ".png";

        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteSpriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &spritePNG);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
        spritePNG.close();

        if (res != CURLE_OK) {
            return false;
        } else {
            pokeToConnect.setSprite("/home/sjd23/projects/PokeBoring/assets/images/sprites/" + pokeToConnect.getName() + ".png");
            return true;
        }
    }
    return false;
}