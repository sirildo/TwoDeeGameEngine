#include "ResourceManager.h"
#include <iostream>

ResourceManager::ResourceManager(SDL_Renderer* renderer) : renderer(renderer) {}

ResourceManager::~ResourceManager() {
    // Cleanup all loaded textures
    for (auto& pair : textures) {
        SDL_DestroyTexture(pair.second);
    }
    textures.clear();
}

SDL_Texture* ResourceManager::getTexture(const std::string& filePath) {
    // Check if the texture is already loaded
    auto it = textures.find(filePath);
    if (it != textures.end()) {
        return it->second; // Return the existing texture
    }

    // Load the texture if it's not found
    return loadTexture(filePath);
}

SDL_Texture* ResourceManager::loadTexture(const std::string& filePath) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath.c_str());
    if (!texture) {
        std::cerr << "Failed to load texture: " << filePath << " SDL_Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    textures[filePath] = texture;
    return texture;
}
