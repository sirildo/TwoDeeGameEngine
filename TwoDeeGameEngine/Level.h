#ifndef LEVEL_H
#define LEVEL_H

#include <SDL.h>
#include <SDL_image.h>  // Include SDL_image for image loading

class Level {
public:
    Level(SDL_Renderer* renderer, const char* backgroundImagePath);  // Constructor now takes a renderer
    ~Level();  // Destructor to clean up the texture
    void update();  // Update level state
    void draw(SDL_Renderer* renderer);

    // Additional methods as needed, e.g., for loading level data, handling collisions, etc.

private:
    // Level-specific attributes, e.g., layout, background, entities, etc.
    SDL_Texture* backgroundTexture;  // Texture for the background image
    int bgWidth, bgHeight;  // Dimensions of the background image


};

#endif // LEVEL_H
