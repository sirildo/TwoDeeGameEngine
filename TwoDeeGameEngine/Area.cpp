#include "Area.h"

Area::Area(SDL_Renderer* renderer, ResourceManager* resourceManager, const std::string& backgroundFilePath)
    : renderer(renderer), resourceManager(resourceManager), backgroundFilePath(backgroundFilePath), isOverworld(false) {
    // Load the background texture
    backgroundTexture = resourceManager->getTexture(backgroundFilePath);
}

Area::~Area() {
    // Note: The ResourceManager will handle cleaning up the texture
}

void Area::enter() {
    // Initialize or reset area-specific resources or entities
}

void Area::exit() {
    // Cleanup or save state as necessary
}

void Area::update(float deltaTime) {
    // Update logic for the area
}

void Area::render() {
    if (backgroundTexture) {
        // Render the background texture
        SDL_RenderCopy(renderer, backgroundTexture, nullptr, nullptr); // Adjust the last two parameters as needed
    }
    // Render other entities or objects in the area
}
