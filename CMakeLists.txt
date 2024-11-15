cmake_minimum_required(VERSION 3.12)
project(PokeBoring)

# Suppress developer warnings
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS ON)

# Add .cpp files in src/ to the project
add_executable(PokeBoring
               src/main.cpp
               src/random.cpp
               src/curlHelpers.cpp
               src/poke.cpp
               src/stats.cpp
               src/move.cpp
               src/levelMechanics.cpp
               src/playerCharacter.cpp
               src/trainer.cpp
               src/encounter.cpp
               src/window.cpp
               src/screenManager.cpp
               src/textRenderer.cpp)

# Include the .hpp header files in include/
target_include_directories(PokeBoring PUBLIC ${CMAKE_SOURCE_DIR}/include/)

# Find and link libcurl using pkg-config for better compatibility
find_package(PkgConfig REQUIRED)
pkg_check_modules(CURL REQUIRED libcurl)
target_link_libraries(PokeBoring PRIVATE ${CURL_LIBRARIES})
target_include_directories(PokeBoring PRIVATE ${CURL_INCLUDE_DIRS})

# Find and link nlohmann/json
find_package(nlohmann_json REQUIRED)
target_link_libraries(PokeBoring PRIVATE nlohmann_json::nlohmann_json)

# Find and link SDL2
find_package(SDL2 REQUIRED)
target_link_libraries(PokeBoring PRIVATE SDL2::SDL2)

# Find and link SDL2 TTF
find_package(SDL2_ttf REQUIRED)
target_link_libraries(PokeBoring PRIVATE SDL2_ttf::SDL2_ttf)

# Enable testing
include(CTest)
enable_testing()

# Set project version
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)