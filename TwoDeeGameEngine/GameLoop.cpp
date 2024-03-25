#include "GameLoop.h"
#include <iostream>

GameLoop::GameLoop() : isRunning(false), window(nullptr), renderer(nullptr) {}

GameLoop::~GameLoop() {
    cleanUp();
}

bool GameLoop::initialize() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create window
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize renderer color
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    lastFrameTime = SDL_GetTicks(); // Initialize the last frame time

    isRunning = true;
    return true;
}

void GameLoop::run() {
    
    const float targetFrameRate = 60.0f;
    const float targetDeltaTime = 1.0f / targetFrameRate;

    while (isRunning) {

        Uint32 currentFrameTime = SDL_GetTicks();
        float deltaTime = (currentFrameTime - lastFrameTime) / 1000.0f; // Delta time in seconds
        
        handleEvents();
        update(deltaTime);
        draw();

        lastFrameTime = currentFrameTime;
        //// Optional: Implement frame rate capping
        //Uint32 frameTime = SDL_GetTicks() - currentFrameTime;
        //if (targetDeltaTime > frameTime / 1000.0f) {
        //    SDL_Delay((targetDeltaTime - frameTime / 1000.0f) * 1000.0f);
        //}
    
    }

    cleanUp();
}

void GameLoop::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        // User requests quit
        if (e.type == SDL_QUIT) {
            isRunning = false;
        }
        // Add more event handling logic here
    }
}

void GameLoop::update(float deltaTime) {
    // Update game state here
}

void GameLoop::draw() {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF); // Set draw color to dark grey
    SDL_RenderClear(renderer);

    // Add your drawing code here

    // Update screen
    SDL_RenderPresent(renderer);
}

void GameLoop::cleanUp() {
    // Destroy window
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    // Quit SDL subsystems
    SDL_Quit();
}
