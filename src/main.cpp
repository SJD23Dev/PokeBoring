#include <iostream>
#include "poke.hpp"

int main() {
    Poke poke(685);
    pokeDataFetcher fetch;
    fetch.fetchData(poke);
    std::cout << poke.getName() << std::endl;
}
