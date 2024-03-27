#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>

// The Entity class serves as a base class for all movable and interactive objects within the game.
class Entity {
public:
    Entity(float x, float y);
    virtual ~Entity();

    // Update the entity's state. deltaTime is the time elapsed since the last frame.
    virtual void update(float deltaTime);

    // Render the entity to the screen
    virtual void render(SDL_Renderer* renderer);

    // Getters for position
    float getX() const;
    float getY() const;

    // Setters for position
    void setX(float x);
    void setY(float y);

protected:
    float x, y; // Position of the entity in the game world
    // Consider adding more properties such as velocity, dimensions, textures, etc.
};

#endif // ENTITY_H
