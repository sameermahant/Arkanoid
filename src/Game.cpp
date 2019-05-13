#include "Game.hpp"

#include "Ball.hpp"
#include "Brick.hpp"
#include "GameLogic.Impl.hpp"
#include "Paddle.hpp"

#include <iostream>

Game::Game() {
    window_.setFramerateLimit(60);

    fontName_.loadFromFile(R"(/usr/share/fonts/dejavu/DejaVuSans-Bold.ttf)");

    stateText_.setString("Paused");
    stateText_.setFont(fontName_);
    stateText_.setCharacterSize(35);
    stateText_.setFillColor(sf::Color::White);
    stateText_.setOrigin(stateText_.getGlobalBounds().left / 2.0f, stateText_.getGlobalBounds().top / 2.0f);
    auto posX = (Settings::windowWidth - stateText_.getGlobalBounds().width) / 2.0f;
    auto posY = (Settings::windowHeight - stateText_.getGlobalBounds().height) / 2.0f;
    stateText_.setPosition(sf::Vector2f(posX, posY));

    livesText_.setFont(fontName_);
    livesText_.setPosition(60, 10);
    livesText_.setCharacterSize(15);
    livesText_.setFillColor(sf::Color::White);
}

void Game::restart() {
    remainingLives_ = 3;

    state_ = State::Paused;
    manager_.clear();

    for (int row{1}; row <= Settings::brickRows; ++row) {
        for (int column{1}; column <= Settings::brickColumns; ++column) {
            float x{column * (Brick::defaultWidth + Settings::brickSpacing)};
            float y{row * (Brick::defaultHeight + Settings::brickSpacing)};
            x += Settings::brickOffsetX;
            y += Settings::brickOffsetY;

            auto &brick(manager_.create<Brick>(x, y));
            brick.setStrength(1);
        }
    }

    manager_.create<Ball>(Settings::windowWidth / 2.0f, Settings::windowHeight / 2.0f);
    manager_.create<Paddle>(Settings::windowWidth / 2, Settings::windowHeight - 50);
}

void Game::runGameLoop() {
    while (true) {
        window_.clear(sf::Color::Black);

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
            restart();
        }

        if (state_ != State::Running) {
            if (state_ == State::Paused) {
                stateText_.setString("Paused");
            } else if (state_ == State::GameOver) {
                stateText_.setString("Game over!");
            } else if (state_ == State::Victory) {
                stateText_.setString("You won!");
            }
            auto posX = (Settings::windowWidth - stateText_.getGlobalBounds().width) / 2.0f;
            auto posY = (Settings::windowHeight - stateText_.getGlobalBounds().height) / 2.0f;
            stateText_.setPosition(sf::Vector2f(posX, posY));
            window_.draw(stateText_);

        } else { // Game logic

            if (manager_.getAll<Ball>().empty()) {
                manager_.create<Ball>(Settings::windowWidth / 2.0f, Settings::windowHeight / 2.0f);
                --remainingLives_;
            }

            if (manager_.getAll<Brick>().empty()) {
                state_ = State::Victory;
            }

            if (remainingLives_ <= 0) {
                state_ = State::GameOver;
            }

            manager_.update();

            manager_.forEachEntity<Ball>([this](auto &ball) {
                manager_.forEachEntity<Brick>([&ball](auto &brick) { solveBrickBallCollision(brick, ball); });
                manager_.forEachEntity<Paddle>([&ball](auto &paddle) { solvePaddleBallCollision(paddle, ball); });
            });

            manager_.refresh();
            manager_.render(window_);

            livesText_.setString("Lives: " + std::to_string(remainingLives_));

            window_.draw(livesText_);
        }

        window_.display();
    }
}
