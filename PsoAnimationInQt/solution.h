#ifndef SOLUTION_H
#define SOLUTION_H

#include <QVector2D>
#include <QSize>

using Vector5d = std::vector<float>;

class Solution
{
public:

    const std::vector<float> minValues = {0,-20,0.01,-10,0.1};
    const std::vector<float> maxValues = {1500,20,50,50,900};

    Solution();

    Solution(Vector5d position, Vector5d velocity, float inercia, float n1, float n2, QSize max);
    void setPosition(Vector5d position);
    void setVelocity(Vector5d velocity);
    void setPBest(Vector5d position);

    Vector5d getPosition();
    Vector5d getVelocity();
    Vector5d getPBest();

    float getFitnessOfCurrentPosition();
    float getFitnessOfPBest();

    void updateVelocityAndPosition(Vector5d gBest);
    void updateVelocity(Vector5d gBest);
    void updatePosition();

private:
    Vector5d position;
    Vector5d velocity;
    float fitnessOfCurrentPosition;

    Vector5d pBest;
    float fitnessOfPBest;

    float inercia;
    float n1;
    float n2;

    QSize max;
};

#endif // SOLUTION_H
