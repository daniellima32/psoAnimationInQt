#ifndef SOLUTION_H
#define SOLUTION_H

#include <QVector2D>
#include <QSize>

class Solution
{
public:
    Solution();

    Solution(QVector2D position, QVector2D velocity, int inercia, int n1, int n2, QSize max);
    void setPosition(QVector2D position);
    void setVelocity(QVector2D velocity);
    void setPBest(QVector2D position);

    QVector2D getPosition();
    QVector2D getVelocity();
    QVector2D getPBest();

    int getFitnessOfCurrentPosition();
    int getFitnessOfPBest();

    void updateVelocityAndPosition(QVector2D gBest);
    void updateVelocity(QVector2D gBest);
    void updatePosition();

private:
    QVector2D position;
    QVector2D velocity;
    int fitnessOfCurrentPosition;

    QVector2D pBest;
    int fitnessOfPBest;

    int inercia;
    int n1;
    int n2;

    QSize max;
};

#endif // SOLUTION_H
