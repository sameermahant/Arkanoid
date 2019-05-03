#include "Game.hpp"

Game::Game()
{
    window_.setFramerateLimit(60);
}

void Game::runGameLoop()
{
    while (true) {
        window_.clear(sf::Color::Black);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            break;
        }

        window_.display();
    }
}
