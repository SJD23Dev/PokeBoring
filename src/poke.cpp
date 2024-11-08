#include "poke.hpp"

/* Default constructor for Poke object,
initilizes all values to default state */ 
Poke::Poke() {
    id = -99;
    name = "default";

    stats.setHP(-99);
    stats.setAttack(-99);
    stats.setDefense(-99);
    stats.setSpeAttack(-99);
    stats.setSpeDefense(-99);
    stats.setSpeed(-99);

    sprite = "default";
}

/* Constructor that allows declaration of
an ID along with the default Poke object */
Poke::Poke(int idDecleration) {
    id = idDecleration;
    name = "default";

    stats.setHP(-99);
    stats.setAttack(-99);
    stats.setDefense(-99);
    stats.setSpeAttack(-99);
    stats.setSpeDefense(-99);
    stats.setSpeed(-99);

    sprite = "default";
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

/* Sets Poke object's sprite file location */
void Poke::setSprite(std::string input) {
    sprite = input;
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

/* Gets Poke object's sprite file location */
const std::string Poke::getSprite() const {
    return sprite;
}

/* Downloads and syncs a Poke
object to a PokeAPI JSON file,
returns a boolean true or false */
bool pokeDataFetcher::fetchData(Poke& poke) {
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

        if (res == CURLE_OK) {
            connectData(poke, readBuffer);
        } else {
            return false;
        }
    }

    return true;
}

/* Assigns the data from the JSON file to the Poke object */
void pokeDataFetcher::connectData(Poke& pokeToConnect, std::string readBuffer) {
    auto jsonData = nlohmann::json::parse(readBuffer);

    pokeToConnect.setID(jsonData["id"].get<int>());
    pokeToConnect.setName(jsonData["name"].get<std::string>());
}