#pragma once

#include <SFML/Graphics/CircleShape.hpp>

class Circle {
  public:
    float x() const noexcept;
    float y() const noexcept;
    float radius() const noexcept;
    float leftEdge() const noexcept;
    float rightEdge() const noexcept;
    float topEdge() const noexcept;
    float bottomEdge() const noexcept;

  protected:
    sf::CircleShape shape_;
};
