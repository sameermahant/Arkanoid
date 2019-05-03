#include "Ball.hpp"

#include "Settings.hpp"

const sf::Color Ball::defaultColor{sf::Color::Red};

Ball::Ball(float x, float y)
{
    shape_.setPosition(x, y);
    shape_.setRadius(defaultRadius);
    shape_.setFillColor(defaultColor);
    shape_.setOrigin(defaultRadius, defaultRadius);
}

Ball::~Ball() = default;

void Ball::update()
{
    shape_.move(velocity_);
    solveBoundCollisions();
}

void Ball::render(sf::RenderWindow& target)
{
    target.draw(shape_);
}

void Ball::setVelocityX(float velocityX) noexcept
{
    velocity_.x = velocityX;
}

void Ball::setVelocityY(float velocityY) noexcept
{
    velocity_.y = velocityY;
}

void Ball::solveBoundCollisions() noexcept
{
    if (leftEdge() < 0) {
        velocity_.x = defaultVelocity;
    } else if (rightEdge() > Settings::windowWidth) {
        velocity_.x = -defaultVelocity;
    }

    if (topEdge() < 0) {
        velocity_.y = defaultVelocity;
    } else if (bottomEdge() > Settings::windowHeight) {
        markToDestroy();
    }
}
