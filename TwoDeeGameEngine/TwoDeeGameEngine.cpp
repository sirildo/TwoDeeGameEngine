// TwoDeeGameEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SDL.h>
#include <iostream>
#include "Character.h"
#include "Level.h"


int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    const int screenWidth = 640;
    const int screenHeight = 480;

    SDL_Window* window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Character character(100, 100, 50, 50); // Create a character
    Level level(renderer, "twodeebg.png"); // Create a level


    // Frame rate configuration
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;  // Milliseconds per frame
    Uint32 frameStart;
    int frameTime;

    int cameraX = 0;
    int cameraY = 0;

    bool isRunning = true;
    SDL_Event event;

    while (isRunning) { // Start of game loop
        frameStart = SDL_GetTicks();

        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_w:
                    character.setMovingUp(true);

                    break;
                case SDLK_s:
                    character.setMovingDown(true);
                    break;
                case SDLK_a:
                    character.setMovingLeft(true);
                    break;
                case SDLK_d:
                    character.setMovingRight(true);
                    break;
                }
            }
            else if (event.type == SDL_KEYUP) {
                switch (event.key.keysym.sym) {
                case SDLK_w:
                    character.setMovingUp(false);
                    break;
                case SDLK_a:
                    character.setMovingDown(false);
                    break;
                case SDLK_s:
                    character.setMovingLeft(false);
                    break;
                case SDLK_d:
                    character.setMovingRight(false);
                    break;
                }
            }
            
        }

        character.update(); // Update character's position
        level.update(); // Update the level

        // Clear screen
        SDL_RenderClear(renderer);

        // Center the camera on the character
        cameraX = character.getX() - (screenWidth / 2);
        cameraY = character.getY() - (screenHeight / 2);

        level.draw(renderer); // Draw the level with camera offset
        character.draw(renderer, cameraX, cameraY); // Draw the character with camera offset
        SDL_RenderPresent(renderer); // Update screen

        // Frame time management
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
