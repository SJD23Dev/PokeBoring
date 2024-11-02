cmake_minimum_required(VERSION 3.12.0)
project(PokeBoring)

# Supress developer warnings
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS ON)

# Add .cpp files in ../src to the project
add_executable(PokeBoring
               src/main.cpp
               src/poke.cpp
               src/pokeDataFetcher.cpp
               src/stats.cpp)

# Include the .hpp header files in ../include the project
target_include_directories(PokeBoring PUBLIC ${CMAKE_SOURCE_DIR}/include/)

# Find and link curl
find_package(curl REQUIRED)
target_link_libraries(PokeBoring PRIVATE CURL::libcurl)

# Find and link nlohmann/json
find_package(nlohmann_json REQUIRED)
target_link_libraries(PokeBoring PRIVATE nlohmann_json::nlohmann_json)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
