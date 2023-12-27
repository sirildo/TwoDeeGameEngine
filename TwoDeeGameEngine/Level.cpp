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

void Level::updateCamera(int x, int y) {
    // Update camera position based on character position 
    cameraX = x - (bgWidth / 2);
    cameraY = y - (bgHeight / 2);
    // Boundary checks to keep the camera within the background dimensions
    if (cameraX < 0) cameraX = 0;
    else if (cameraX > bgWidth - windowWidth) cameraX = bgWidth - windowWidth;

    if (cameraY < 0) cameraY = 0;
    else if (cameraY > bgHeight - windowHeight) cameraY = bgHeight - windowHeight;
    

}

void Level::draw(SDL_Renderer* renderer) {
    SDL_Rect srcRect = { 0, 0, bgWidth, bgHeight };
    SDL_Rect destRect = { -cameraX, -cameraY, bgWidth, bgHeight };  // Adjust based on camera position
    SDL_RenderCopy(renderer, backgroundTexture, &srcRect, &destRect);
}

int Level::getCameraX() const {
    return cameraX;
}

int Level::getCameraY() const {
    return cameraY;
}