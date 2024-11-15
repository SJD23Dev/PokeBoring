#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Window {
    public:
        Window();
        ~Window();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};

#endif