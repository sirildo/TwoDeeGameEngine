#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>

class Character {
public:
    Character(int x, int y, int width, int height);
    void update();  // Update the character's position
    void draw(SDL_Renderer* renderer, int cameraX, int cameraY);

    int getX() const;
    int getY() const;

private:
    int x, y;       // Position of the character
    int width, height;  // Size of the character
    int speed;      // Speed of the character
};

#endif // CHARACTER_H
