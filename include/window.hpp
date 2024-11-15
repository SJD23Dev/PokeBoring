#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>

class Window {
    public:
        Window();
        ~Window();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};

#endif