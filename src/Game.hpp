#pragma once

#include "Manager.hpp"
#include "Settings.hpp"

#include <SFML/Graphics.hpp>

class Game {
  public:
    Game();

    void restart();
    void runGameLoop();

  private:
    enum class State { Paused, Running, Victory, GameOver };
    State state_{State::GameOver};
    bool isPausePressedLastFrame_{false};
    sf::RenderWindow window_{{Settings::windowWidth, Settings::windowHeight}, Settings::windowTitle};
    sf::Font fontName_;
    sf::Text stateText_;
    int remainingLives_{0};
    sf::Text livesText_;
    Manager manager_;
};
