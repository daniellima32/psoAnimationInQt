#include "solution.h"

#include "fitness.h"

Solution::Solution()
{

}

Solution::Solution(Vector5d position, Vector5d velocity, float inercia, float n1, float n2, QSize max):
    inercia(inercia), n1(n1), n2 (n2), max(max)
{
    setPosition(position);
    this->fitnessOfCurrentPosition = Fitness::calculateFitness(position);
    setVelocity(velocity);

    //Inicialmente, a melhor solução é a inicial
    setPBest(position);
    this->fitnessOfPBest = Fitness::calculateFitness(pBest);
}

void Solution::setPosition(Vector5d position)
{
    this->position = position;
}

void Solution::setVelocity(Vector5d velocity)
{
    this->velocity = velocity;
}

void Solution::setPBest(Vector5d position)
{
    this->pBest = position;
}

Vector5d Solution::getPosition()
{
    return position;
}

Vector5d Solution::getVelocity()
{
    return velocity;
}

Vector5d Solution::getPBest()
{
    return pBest;
}

float Solution::getFitnessOfCurrentPosition()
{
    return this->fitnessOfCurrentPosition;
}

float Solution::getFitnessOfPBest()
{
    return this->fitnessOfPBest;
}

void Solution::updateVelocityAndPosition(Vector5d gBest)
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

void Solution::updateVelocity(Vector5d gBest)
{
    for (int index = 0; index < 5; ++index)
    {
        velocity[index] = inercia*velocity[index] +
                n1*(rand() % 1)*(pBest[index]-position[index])+
                n2*(rand() % 1)*(gBest[index]-position[index]);
    }

    /*velocity[0] = inercia*velocity[0] +
            n1*(rand() % 1)*(pBest[0]-position[0])+
            n2*(rand() % 1)*(gBest[0]-position[0]);
    velocity[1] = inercia*velocity[1] +
            n1*(rand() % 1)*(pBest[1]-position[1])+
            n2*(rand() % 1)*(gBest[1]-position[1]);*/

    /*if (velocity[0] > max.width())
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
    }*/
}

void Solution::updatePosition()
{
    for (int index = 0; index < 5; ++index)
    {
        position[index] = position[index] + velocity[index];
    }

    for (int index = 0; index < 5; ++index)
    {
        if (position[index] > maxValues[index]) //maximo
        {
            position[index] = maxValues[index]; //maximo
        }
        else if (position[index] < minValues[index]) //minimo
        {
            position[index] = minValues[index]; //minimo
        }
    }

    //position[0] = position[0] + velocity[0];
    //position[1] = position[1] + velocity[1];

    /*if (position[0] > max.width())
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
    }*/
}
