#include "solution.h"

Solution::Solution()
{

}

Solution::Solution(QVector2D position, QVector2D velocity)
{
    setPosition(position);
    setVelocity(velocity);
}

void Solution::setPosition(QVector2D position)
{
    this->position = position;
}

void Solution::setVelocity(QVector2D velocity)
{
    this->velocity = velocity;
}

QVector2D Solution::getPosition()
{
    return position;
}

QVector2D Solution::getVelocity()
{
    return velocity;
}
