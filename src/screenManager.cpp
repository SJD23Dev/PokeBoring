#include "screenManager.hpp"

void ScreenManager::switchTo(std::unique_ptr<Screen> newScreen) {
    currentScreen = std::move(newScreen);
}

void ScreenManager::handleInput(SDL_Event& event) {
    if (currentScreen) {
        currentScreen->handleInput(event);
    }
}

void ScreenManager::update() {
    if (currentScreen) {
        currentScreen->update();
    }
}

void ScreenManager::render(SDL_Renderer* renderer) {
    if (currentScreen) {
        currentScreen->render(renderer);
    }
}