#include "Game.hpp"

#include <iostream>
Game::Game()
{
    window_.setFramerateLimit(60);

    fontName_.loadFromFile(R"(/usr/share/fonts/open-sans/OpenSans-Bold.ttf)");

    stateText_.setFont(fontName_);
    stateText_.setPosition(10, 10);
    stateText_.setCharacterSize(35);
    stateText_.setFillColor(sf::Color::White);
    stateText_.setString("Paused");
}

void Game::start()
{
    state_ = State::Initial;
    stateText_.setString("Press 'Enter' to start \nPress 'Esc' to quit");

    while (true) {
        window_.clear(sf::Color::Blue);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
            state_ = State::Running;
            break;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            break;
        }
        window_.draw(stateText_);
        window_.display();
    }
}

void Game::runGameLoop()
{
    while (true) {
        window_.clear(sf::Color::Blue);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            break;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
            if (!isPausePressedLastFrame_) {
                if (state_ == State::Paused) {
                    state_ = State::Running;
                } else if (state_ == State::Running) {
                    state_ = State::Paused;
                }
            }
            isPausePressedLastFrame_ = true;
        } else {
            isPausePressedLastFrame_ = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
            reset();
        }

        if (state_ != State::Running) {
            if (state_ == State::Paused) {
                stateText_.setString("Paused");
            } else if (state_ == State::GameOver) {
                stateText_.setString("Game over!");
            } else if (state_ == State::Victory) {
                stateText_.setString("You won!");
            }
            window_.draw(stateText_);
        } else {
            stateText_.setString("Running");
            window_.draw(stateText_);
        }

        window_.display();
    }
}

void Game::reset()
{
    state_ = State::Running;
    stateText_.setString("Restarting the game in 3 seconds");
    window_.draw(stateText_);
    window_.display();
    sf::sleep(sf::seconds(3));
}