#include "textRenderer.hpp"

TextRenderer::TextRenderer(const std::string& fontLocation, int fontSize) {
    // Create font with the file path of the font and given font size
    font = TTF_OpenFont(fontLocation.c_str(), fontSize);

    if (!font) { // If the font failed to create...
        throw std::runtime_error("[TextRenderer::TextRenderer()] " + std::to_string(__LINE__) + " " + std::string(SDL_GetError()));
    }
}

TextRenderer::~TextRenderer() {
    if (font) { // If font object is still open...
        TTF_CloseFont(font);
    }
}

void TextRenderer::render(SDL_Renderer* renderer, const std::string& input, int x, int y, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, input.c_str(), color);
    
    if (!surface) {
        throw std::runtime_error("[TextRenderer::render()] " + std::to_string(__LINE__) + " " + std::string(SDL_GetError()));
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    
    if (!texture) {
        SDL_FreeSurface(surface);
        throw std::runtime_error("[TextRenderer::render()] " + std::to_string(__LINE__) + " " + std::string(SDL_GetError()));
    }

    SDL_Rect destRect = {x, y, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, nullptr, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}