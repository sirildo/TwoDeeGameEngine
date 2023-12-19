#include "Level.h"

Level::Level(SDL_Renderer* renderer, const char* backgroundImagePath) {
    // Load the background image
    SDL_Surface* tempSurface = IMG_Load(backgroundImagePath);
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_QueryTexture(backgroundTexture, NULL, NULL, &bgWidth, &bgHeight);
    SDL_FreeSurface(tempSurface);
}

Level::~Level() {
    // Clean up the background texture
    SDL_DestroyTexture(backgroundTexture);
}

void Level::update() {
    // Update the level state, e.g., moving platforms, enemy behavior, etc.
}

void Level::draw(SDL_Renderer* renderer) {
    SDL_Rect srcRect = { 0, 0, bgWidth, bgHeight };
    SDL_Rect destRect = { 0, 0, bgWidth, bgHeight };  // Adjust as needed

    SDL_RenderCopy(renderer, backgroundTexture, &srcRect, &destRect);
}
