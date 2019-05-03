#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

class Rectangle {
  public:
    float x() const noexcept;
    float y() const noexcept;
    float width() const noexcept;
    float height() const noexcept;
    float leftEdge() const noexcept;
    float rightEdge() const noexcept;
    float topEdge() const noexcept;
    float bottomEdge() const noexcept;

  protected:
    sf::RectangleShape shape_;
};
