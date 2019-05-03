#pragma once

#include "Entity.hpp"
#include "Rectangle.hpp"

class Brick
  : public Entity
  , public Rectangle {
  public:
    static const sf::Color defaultColor;
    static constexpr float defaultWidth{60.0f};
    static constexpr float defaultHeight{20.0f};

    Brick(float x, float y);
    ~Brick() override;

    void update() override;
    void render(sf::RenderWindow& target) override;

    void setStrength(int strength) noexcept;
    void decrementStrength() noexcept;

  private:
    int strength_{1};
};
