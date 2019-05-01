#pragma once

#include "Settings.hpp"

#include <SFML/Graphics.hpp>

class Game {
public:
  Game();

  void runGameLoop();

private:
  sf::RenderWindow window_{ { Settings::windowWidth, Settings::windowHeight },
                            Settings::windowTitle };
};
