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
    levelLearnedAt = -99;
}

/* Constructor that allows declaration of
an name along with the default Move object */
Move::Move(std::string nameDeclaration) {
    id = -99;
    name = nameDeclaration;
    power = -99;
    pp = -99;
    priority = -99;
    accuracy = -99;
    levelLearnedAt = -99;
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

/* Sets Move object's level learned at */
void Move::setLevelLearnedAt(int input) {
    levelLearnedAt = input;
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

/* Gets Move object's level learned at,
returns as an integer */
const int Move::getLevelLearnedAt() const {
    return levelLearnedAt;
}

/* Downloads and syncs a Move
object to a PokeAPI JSON file,
returns a boolean true or false */
bool moveDataFetcher::fetch(Move& move) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();

    if (curl) {
        std::string URL = "https://pokeapi.co/api/v2/move/" + move.getName();

        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            connect(move, readBuffer);
            return true;
        } else {
            return false;
        }
    }
    return false;
}

/* Assigns the data from the JSON file to the Move object */
void moveDataFetcher::connect(Move& moveToConnect, std::string readBuffer) {
    auto jsonData = nlohmann::json::parse(readBuffer);

    moveToConnect.setID(jsonData["id"].get<int>()); // ID
    moveToConnect.setName(jsonData["name"].get<std::string>()); // Name
    moveToConnect.setPriority(jsonData["priority"].get<int>()); // Priority
} 