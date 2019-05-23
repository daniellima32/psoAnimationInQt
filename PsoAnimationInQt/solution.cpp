#include "solution.h"

#include "fitness.h"

Solution::Solution()
{

}

Solution::Solution(QVector2D position, QVector2D velocity, int inercia, int n1, int n2, QSize max):
    inercia(inercia), n1(n1), n2 (n2), max(max)
{
    setPosition(position);
    this->fitnessOfCurrentPosition = Fitness::calculateFitness(position);
    setVelocity(velocity);

    //Inicialmente, a melhor solução é a inicial
    setPBest(position);
    this->fitnessOfPBest = Fitness::calculateFitness(pBest);
}

void Solution::setPosition(QVector2D position)
{
    this->position = position;
}

void Solution::setVelocity(QVector2D velocity)
{
    this->velocity = velocity;
}

void Solution::setPBest(QVector2D position)
{
    this->pBest = position;
}

QVector2D Solution::getPosition()
{
    return position;
}

QVector2D Solution::getVelocity()
{
    return velocity;
}

QVector2D Solution::getPBest()
{
    return pBest;
}

int Solution::getFitnessOfCurrentPosition()
{
    return this->fitnessOfCurrentPosition;
}

int Solution::getFitnessOfPBest()
{
    return this->fitnessOfPBest;
}

void Solution::updateVelocityAndPosition(QVector2D gBest)
{
    updateVelocity(gBest);
    updatePosition();

    //calculates the fitness of position, updating pBest if needed
    this->fitnessOfCurrentPosition = Fitness::calculateFitness(position);
    if (this->fitnessOfCurrentPosition > this->fitnessOfPBest)
    {
        setPBest(position);
        this->fitnessOfPBest = this->fitnessOfCurrentPosition;
    }
}

void Solution::updateVelocity(QVector2D gBest)
{
    velocity[0] = inercia*velocity[0] +
            n1*(rand() % 1)*(pBest[0]-position[0])+
            n2*(rand() % 1)*(gBest[0]-position[0]);
    velocity[1] = inercia*velocity[1] +
            n1*(rand() % 1)*(pBest[1]-position[1])+
            n2*(rand() % 1)*(gBest[1]-position[1]);

    if (velocity[0] > max.width())
    {
        velocity[0] = max.width();
    }
    else if (velocity[0] < 0)
    {
        velocity[0] = 0;
    }

    if (velocity[1] > max.height())
    {
        velocity[1] = max.height();
    }
    else if (velocity[1] < 0)
    {
        velocity[1] = 0;
    }
}

void Solution::updatePosition()
{
    position[0] = position[0] + velocity[0];
    position[1] = position[1] + velocity[1];

    if (position[0] > max.width())
    {
        position[0] = max.width();
    }
    else if (position[0] < 0)
    {
        position[0] = 0;
    }

    if (position[1] > max.height())
    {
        position[1] = max.height();
    }
    else if (position[1] < 0)
    {
        position[1] = 0;
    }
}
