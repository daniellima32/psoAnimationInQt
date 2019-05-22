#ifndef SOLUTION_H
#define SOLUTION_H

#include <QVector2D>

class Solution
{
public:
    Solution();

    Solution(QVector2D position, QVector2D velocity);
    void setPosition(QVector2D position);
    void setVelocity(QVector2D velocity);

    QVector2D getPosition();
    QVector2D getVelocity();

private:
    QVector2D position;
    QVector2D velocity;
};

#endif // SOLUTION_H
