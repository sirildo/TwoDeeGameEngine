#ifndef LEVEL_H
#define LEVEL_H

#include <SDL.h>
#include <SDL_image.h>  // Include SDL_image for image loading

class Level {
public:
    Level(SDL_Renderer* renderer, const char* backgroundImagePath, int windowWidth, int windowHeight);  // Constructor now takes a renderer
    ~Level();  // Destructor to clean up the texture
    void update();  // Update level state
    //void updateCamera(int x, int y);  // DELETE
    void draw(SDL_Renderer* renderer);
    //int getCameraX() const;           // Getter for cameraX
    //int getCameraY() const;           // Getter for cameraY
    int getWidth() const { return bgWidth; }
    int getHeight() const { return bgHeight; }

    // Additional methods as needed, e.g., for loading level data, handling collisions, etc.

private:
    // Level-specific attributes, e.g., layout, background, entities, etc.
    SDL_Texture* backgroundTexture;  // Texture for the background image
    int bgWidth, bgHeight;  // Dimensions of the background image
    //int cameraX, cameraY;  // Camera position //TODO: Delete
    int windowWidth, windowHeight; // Store window dimensions
};

#endif // LEVEL_H
