#pragma once

#include "Entity.hpp"
#include "Rectangle.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

class Paddle
  : public Entity
  , public Rectangle {
  public:
    static const sf::Color defaultColor;
    static constexpr float defaultWidth{60.0f};
    static constexpr float defaultHeight{20.0f};
    static constexpr float defaultVelocity{8.0f};

    Paddle(float x, float y);
    ~Paddle() override;

    void update() override;
    void render(sf::RenderWindow& target) override;

  private:
    sf::Vector2f velocity_;

    void processPlayerInput();
};
