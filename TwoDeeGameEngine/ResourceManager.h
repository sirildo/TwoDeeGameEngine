#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <unordered_map>

class ResourceManager {
public:
    ResourceManager(SDL_Renderer* renderer);
    ~ResourceManager();

    // Prevent copying to ensure a single manager instance
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    // Load a texture from a file, or get it if it's already loaded
    SDL_Texture* getTexture(const std::string& filePath);

private:
    SDL_Renderer* renderer;
    std::unordered_map<std::string, SDL_Texture*> textures;

    // Helper function to actually load a texture
    SDL_Texture* loadTexture(const std::string& filePath);
};

#endif // RESOURCEMANAGER_H
