#pragma once

#include "Ball.hpp"
#include "Brick.hpp"
#include "Paddle.hpp"

template<typename T1, typename T2>
bool isIntersecting(const T1& A, const T2& B) noexcept
{
    return A.rightEdge() >= B.leftEdge() && A.leftEdge() <= B.rightEdge() && A.bottomEdge() >= B.topEdge()
        && A.topEdge() <= B.bottomEdge();
}

inline void solvePaddleBallCollision(const Paddle& paddle, Ball& ball) noexcept
{
    if (!isIntersecting(paddle, ball)) {
        return;
    }

    auto velocityX = ball.x() < paddle.x() ? -Ball::defaultVelocity : Ball::defaultVelocity;
    auto velocityY = -Ball::defaultVelocity;

    ball.setVelocityX(velocityX);
    ball.setVelocityY(velocityY);
}

inline void solveBrickBallCollision(Brick& brick, Ball& ball) noexcept
{
    if (!isIntersecting(brick, ball)) {
        return;
    }

    brick.decrementStrength();

    float overlapLeft{ball.rightEdge() - brick.leftEdge()};
    float overlapRight{brick.rightEdge() - ball.leftEdge()};
    float overlapTop{ball.bottomEdge() - brick.topEdge()};
    float overlapBottom{brick.bottomEdge() - ball.topEdge()};

    bool isHitFromLeft(std::abs(overlapLeft) < std::abs(overlapRight));
    bool isHitFromTop(std::abs(overlapTop) < std::abs(overlapBottom));

    float minOverlapX{isHitFromLeft ? overlapLeft : overlapRight};
    float minOverlapY{isHitFromTop ? overlapTop : overlapBottom};

    if (std::abs(minOverlapX) < std::abs(minOverlapY)) {
        auto velocityX = isHitFromLeft ? -Ball::defaultVelocity : Ball::defaultVelocity;
        ball.setVelocityX(velocityX);
    } else {
        auto velocityY = isHitFromTop ? -Ball::defaultVelocity : Ball::defaultVelocity;
        ball.setVelocityY(velocityY);
    }
}