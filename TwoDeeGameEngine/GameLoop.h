#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <SDL.h>

class GameLoop {
public:
    GameLoop();
    ~GameLoop();

    // Initialize game resources and state
    bool initialize();

    // Starts the main game loop
    void run();

private:
    Uint32 lastFrameTime;
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

    // Handles user input and other events
    void handleEvents();

    // Updates the game state
    void update(float deltaTime);

    // Renders the game to the screen
    void draw();

    // Clean up game resources
    void cleanUp();
};

#endif // GAMELOOP_H
