#include "Character.h"

Character::Character(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {
}

void Character::update() {
    // Example movement logic (you can modify this as needed)
    x += speed;  // Move the character horizontally
}

void Character::draw(SDL_Renderer* renderer, int cameraX, int cameraY) {
    // Adjust position by camera offset
    SDL_Rect rect = { x - cameraX, y - cameraY, width, height };

    // Set the drawing color for character (e.g., red)
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Draw the rectangle
    SDL_RenderFillRect(renderer, &rect);
}

int Character::getX() const {
    return x;
}

int Character::getY() const {
    return y;
}