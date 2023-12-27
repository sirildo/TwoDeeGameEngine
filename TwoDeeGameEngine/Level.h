#ifndef LEVEL_H
#define LEVEL_H

#include <SDL.h>
#include <SDL_image.h>  // Include SDL_image for image loading

class Level {
public:
    Level(SDL_Renderer* renderer, const char* backgroundImagePath, int windowWidth, int windowHeight);  // Constructor now takes a renderer
    ~Level();  // Destructor to clean up the texture
    void update();  // Update level state
    void updateCamera(int x, int y);  // Method to update camera position
    void draw(SDL_Renderer* renderer);
    int getCameraX() const;           // Getter for cameraX
    int getCameraY() const;           // Getter for cameraY
    // Additional methods as needed, e.g., for loading level data, handling collisions, etc.

private:
    // Level-specific attributes, e.g., layout, background, entities, etc.
    SDL_Texture* backgroundTexture;  // Texture for the background image
    int bgWidth, bgHeight;  // Dimensions of the background image
    int cameraX, cameraY;  // Camera position
    int windowWidth, windowHeight; // Store window dimensions
};

#endif // LEVEL_H
