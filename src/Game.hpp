#pragma once

#include "Settings.hpp"

#include <SFML/Graphics.hpp>

class Game {
  public:
    Game();

    void start();
    void runGameLoop();

  private:
    enum class State { Initial, Paused, Running, Victory, GameOver };
    State state_{State::GameOver};
    bool isPausePressedLastFrame_{false};
    sf::RenderWindow window_{{Settings::windowWidth, Settings::windowHeight}, Settings::windowTitle};
    sf::Font fontName_;
    sf::Text stateText_;

    void reset();
};
