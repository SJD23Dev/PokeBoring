#include "window.hpp"

/* Constructor for Window class, 
creates an SDL2 window */
Window::Window() {
    // Initilize SDL pointers
    window = nullptr;
    renderer = nullptr;

    SDL_Init(SDL_INIT_EVERYTHING); // SDL function to initilize everything
    TTF_Init(); // Initilize SDL TTF
    
    // Create the window
    window = SDL_CreateWindow("PokeBoring", 
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              700,
                              750,
                              SDL_WINDOW_SHOWN);

    if (!window) { // If the window failed to start...
        throw std::runtime_error("[Window::Window()] " + std::to_string(__LINE__) + " " + std::string(SDL_GetError()));
    }

    // Create the renderer
    renderer = SDL_CreateRenderer(window, 
                                  -1, 
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) { // If the renderer failed to start...
        SDL_DestroyWindow(window);
        throw std::runtime_error("[Window::Window()] " + std::to_string(__LINE__) + " " + std::string(SDL_GetError()));
    }                            
}

/* Destructor for Window class */
Window::~Window() {
    if (renderer) { // If the renderer is open, destroy it
        SDL_DestroyRenderer(renderer);
    }

    if (window) { // If the window is open, destroy it
        SDL_DestroyWindow(window);
    }

    TTF_Quit(); // Close down SDL TTF (opposite function to TTF_Init())
    SDL_Quit(); // Close down SDL (opposite function to SDL_Init())
}