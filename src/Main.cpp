#include "Entity.hpp"
#include "Game.hpp"

#include <cstdlib>
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv, [[maybe_unused]] char* envp[])
{
    Game game;
    game.runGameLoop();

    return EXIT_SUCCESS;
}
