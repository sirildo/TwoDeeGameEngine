#include "Character.h"
#include <iostream>

Character::Character(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height), speed(5), movingUp(false), movingDown(false), movingLeft(false), movingRight(false) {
}

void Character::update() {
    if (movingUp) y -= speed;
    if (movingDown) y += speed;
    if (movingLeft) x -= speed;
    if (movingRight) x += speed;
}

void Character::setMovingUp(bool moving) {
    movingUp = moving;
}

void Character::setMovingDown(bool moving) {
    movingDown = moving;
}

void Character::setMovingLeft(bool moving) {
    movingLeft = moving;
}

void Character::setMovingRight(bool moving) {
    movingRight = moving;
}

void Character::draw(SDL_Renderer* renderer, int cameraX, int cameraY) {
    SDL_Rect rect = { x - cameraX, y - cameraY, width, height };     // Adjust position by camera offset
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set the drawing color for character (e.g., red)
    SDL_RenderFillRect(renderer, &rect); // Draw the rectangle
}

int Character::getX() const {
    return x;
}

int Character::getY() const {
    return y;
}

