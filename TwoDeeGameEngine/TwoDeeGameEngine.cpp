// TwoDeeGameEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SDL.h>
#include <iostream>
#include "Character.h"
#include "Level.h"
#include "Camera.h"


// Event handling function
void handleEvents(bool& isRunning, Character& character) {
    SDL_Event event;
    // Event handling
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            if (event.key.keysym.sym == SDLK_w) character.setMovingUp(true);
            else if (event.key.keysym.sym == SDLK_s) character.setMovingDown(true);
            else if (event.key.keysym.sym == SDLK_a) character.setMovingLeft(true);
            else if (event.key.keysym.sym == SDLK_d) character.setMovingRight(true);
        }
        else if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_w) character.setMovingUp(false);
            else if (event.key.keysym.sym == SDLK_s) character.setMovingDown(false);
            else if (event.key.keysym.sym == SDLK_a) character.setMovingLeft(false);
            else if (event.key.keysym.sym == SDLK_d) character.setMovingRight(false);
        }

    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    const int screenWidth = 640;
    const int screenHeight = 480;

    SDL_Window* window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Character character(100, 100, 50, 50); // Create a character
    Level level(renderer, "twodeebg.png", screenWidth, screenHeight); // Create a level
    Camera camera(screenWidth, screenHeight); // Create camera


    // Frame rate configuration
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;  // Milliseconds per frame
    Uint32 frameStart;
    int frameTime;

    int cameraX = 0;
    int cameraY = 0;

    bool isRunning = true;


    while (isRunning) { // Start of game loop
  

        frameStart = SDL_GetTicks();
        handleEvents(isRunning, character);


        // Update character's position
        character.update(); 
        // Update the level
        level.update(); 
        // Update camera position based on character position
        //level.updateCamera(character.getX(), character.getY());//TODO: Delete
        camera.update(character.getX(), character.getY(), level.getWidth(), level.getHeight());



        // Clear screen
        SDL_RenderClear(renderer);
        // Draw the level with camera offset
        level.draw(renderer); 
        // Draw the character with camera offset
        //character.draw(renderer, level.getCameraX(), level.getCameraY()); 
        character.draw(renderer, camera.getX(), camera.getY());

        // Update screen
        SDL_RenderPresent(renderer);
        // Frame time management
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
        

    }



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
