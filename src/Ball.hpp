#pragma once

#include "Circle.hpp"
#include "Entity.hpp"

class Ball
  : public Entity
  , public Circle {
  public:
    static const sf::Color defaultColor;
    static constexpr float defaultRadius{10.0f};
    static constexpr float defaultVelocity{5.0f};

    Ball(float x, float y);
    ~Ball() override;

    void update() override;
    void render(sf::RenderWindow& target) override;

    void setVelocityX(float velocityX) noexcept;
    void setVelocityY(float velocityY) noexcept;

  private:
    sf::Vector2f velocity_{-defaultVelocity, -defaultVelocity};

    void solveBoundCollisions() noexcept;
};
