#include "pokeDataFetcher.hpp"

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

