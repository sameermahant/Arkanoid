#include "Circle.hpp"

float Circle::x() const noexcept
{
    return shape_.getPosition().x;
}

float Circle::y() const noexcept
{
    return shape_.getPosition().y;
}

float Circle::radius() const noexcept
{
    return shape_.getRadius();
}

float Circle::leftEdge() const noexcept
{
    return x() - shape_.getRadius();
}

float Circle::rightEdge() const noexcept
{
    return x() + shape_.getRadius();
}

float Circle::topEdge() const noexcept
{
    return y() - shape_.getRadius();
}

float Circle::bottomEdge() const noexcept
{
    return y() + shape_.getRadius();
}
