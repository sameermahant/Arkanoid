#include "Paddle.hpp"

#include "Settings.hpp"

#include <SFML/Window/Keyboard.hpp>

const sf::Color Paddle::defaultColor{sf::Color::Blue};

Paddle::Paddle(float x, float y)
{
    shape_.setPosition(x, y);
    shape_.setSize({defaultWidth, defaultHeight});
    shape_.setFillColor(defaultColor);
    shape_.setOrigin(defaultWidth / 2.0f, defaultHeight / 2.0f);
}

Paddle::~Paddle() = default;

void Paddle::update()
{
    processPlayerInput();
    shape_.move(velocity_);
}

void Paddle::render(sf::RenderWindow& target)
{
    target.draw(shape_);
}

void Paddle::processPlayerInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && leftEdge() > 0) {
        velocity_.x = -defaultVelocity;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && rightEdge() < Settings::windowWidth) {
        velocity_.x = defaultVelocity;
    } else {
        velocity_.x = 0;
    }
}
