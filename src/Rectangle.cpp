#include "Rectangle.hpp"

float Rectangle::x() const noexcept
{
    return shape_.getPosition().x;
}

float Rectangle::y() const noexcept
{
    return shape_.getPosition().y;
}

float Rectangle::width() const noexcept
{
    return shape_.getSize().x;
}

float Rectangle::height() const noexcept
{
    return shape_.getSize().y;
}

float Rectangle::leftEdge() const noexcept
{
    return x() - width() / 2.0f;
}

float Rectangle::rightEdge() const noexcept
{
    return x() + width() / 2.0f;
}

float Rectangle::topEdge() const noexcept
{
    return y() - height() / 2.0f;
}

float Rectangle::bottomEdge() const noexcept
{
    return y() + height() / 2.0f;
}
