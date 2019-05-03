#include "Brick.hpp"

#include <iostream>

const sf::Color Brick::defaultColor{sf::Color::Yellow};

Brick::Brick(float x, float y)
{
    shape_.setPosition(x, y);
    shape_.setSize({defaultWidth, defaultHeight});
    shape_.setFillColor(defaultColor);
    shape_.setOrigin(defaultWidth / 2.0f, defaultHeight / 2.0f);
}

Brick::~Brick() = default;

void Brick::update() {}

void Brick::render(sf::RenderWindow& target)
{
    target.draw(shape_);
}

void Brick::setStrength(int strength) noexcept
{
    strength_ = strength;
}

void Brick::decrementStrength() noexcept
{
    --strength_;
    if (strength_ <= 0) {
        markToDestroy();
    }
}
