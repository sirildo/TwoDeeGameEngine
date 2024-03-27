#ifndef AREA_H
#define AREA_H

#include <SDL.h>
#include <string>
#include "ResourceManager.h" // Make sure this is included

class Area {
public:
    Area(SDL_Renderer* renderer, ResourceManager* resourceManager, const std::string& backgroundFilePath);
    virtual ~Area();

    virtual void enter();
    virtual void exit();
    virtual void update(float deltaTime);
    virtual void render();

    //bool isOverworldArea() const;

protected:
    bool isOverworld;
    SDL_Renderer* renderer; // Needed for rendering
    ResourceManager* resourceManager; // For loading and managing resources
    std::string backgroundFilePath;
    SDL_Texture* backgroundTexture; // The background image texture
};

#endif // AREA_H
