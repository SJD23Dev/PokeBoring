#ifndef SCREENMANAGER_HPP
#define SCREENMANAGER_HPP

#include <memory>
#include <SDL2/SDL.h>

class Screen {
    public:
        virtual ~Screen() = default;
        virtual void handleInput(SDL_Event& event) = 0;
        virtual void update() = 0;
        virtual void render(SDL_Renderer* renderer) = 0;
};

class ScreenManager {
    public:
        void switchTo(std::unique_ptr<Screen> newScreen);
        void handleInput(SDL_Event& event);
        void update();
        void render(SDL_Renderer* renderer);
    private:
        std::unique_ptr<Screen> currentScreen;
};

#endif