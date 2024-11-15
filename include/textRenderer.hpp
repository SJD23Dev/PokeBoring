#ifndef TEXTRENDERER_HPP
#define TEXTRENDERER_HPP

#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class TextRenderer {
    public:
        TextRenderer(const std::string& fontLocation, int fontSize);
        ~TextRenderer();
        void render(SDL_Renderer* renderer, const std::string& input, int x, int y, SDL_Color color);
    private:
        TTF_Font* font;
};

#endif