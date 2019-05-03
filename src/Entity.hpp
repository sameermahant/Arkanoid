#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Entity {
  public:
    virtual ~Entity() = default;

    void markToDestroy() { markedToDestroy_ = true; }
    bool isMarkedToDestroy() { return markedToDestroy_; }

    virtual void update() = 0;
    virtual void render(sf::RenderWindow& target) = 0;

  protected:
    bool markedToDestroy_{false};
};
