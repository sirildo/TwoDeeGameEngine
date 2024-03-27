#include "Entity.h"

Entity::Entity(float x, float y) : x(x), y(y) {}

Entity::~Entity() {
    // Cleanup resources specific to the entity, if any
}

void Entity::update(float deltaTime) {
    // Implement logic to update the entity's state
    // This might include moving the entity, checking for collisions, etc.
}

void Entity::render(SDL_Renderer* renderer) {
    // Implement the logic to render the entity on the screen
    // This might involve drawing a sprite, a shape, or some other visual representation
}

float Entity::getX() const {
    return x;
}

float Entity::getY() const {
    return y;
}

void Entity::setX(float newX) {
    x = newX;
}

void Entity::setY(float newY) {
    y = newY;
}
