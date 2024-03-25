#include "GameLoop.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // Creating an instance of GameLoop
    GameLoop gameLoop;

    // Attempt to initialize the game. If initialization fails, log an error and exit.
    if (!gameLoop.initialize()) {
        std::cerr << "Game initialization failed." << std::endl;
        return -1; // Use an error code to indicate failure
    }

    // If initialization is successful, run the game loop
    gameLoop.run();

    // No explicit cleanup here, assuming GameLoop's destructor handles it.
    // The program ends when the game loop is finished.

    return 0; // Successful execution
}