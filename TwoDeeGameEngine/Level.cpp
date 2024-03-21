#include "Level.h"

Level::Level(SDL_Renderer* renderer, const char* backgroundImagePath, int windowWidth, int windowHeight)
    : windowWidth(windowWidth), windowHeight(windowHeight) {
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

void Level::draw(SDL_Renderer* renderer, Camera& camera) {
    // Calculate the part of the level to draw based on the camera's position
    SDL_Rect srcRect;
    srcRect.x = camera.getX();
    srcRect.y = camera.getY();
    srcRect.w = camera.getWidth(); // Assuming getWidth() returns the camera's viewport width
    srcRect.h = camera.getHeight(); // Assuming getHeight() returns the camera's viewport height

    // The destination rectangle is where on the screen we want to draw the srcRect portion of the level
    SDL_Rect destRect = { 0, 0, camera.getWidth(), camera.getHeight() };

    // Render the portion of the level that is within the camera's viewport
    SDL_RenderCopy(renderer, backgroundTexture, &srcRect, &destRect);
}

