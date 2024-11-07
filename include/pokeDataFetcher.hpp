#ifndef POKEMONDATAFETCHER_HPP
#define POKEMONDATAFETCHER_HPP

#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "curlHelpers.hpp"
#include "poke.hpp"

struct pokeDataFetcher {
    bool fetchData(Poke& poke);
    void connectData(Poke& pokeToConnect, std::string readBuffer);
};

#endif