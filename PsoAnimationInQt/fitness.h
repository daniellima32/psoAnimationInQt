#ifndef FITNESS_H
#define FITNESS_H

#include <QVector2D>

using Vector5d = std::vector<float>;

class Fitness
{
public:
    static float calculateFitness(Vector5d vec);
};

#endif // FITNESS_H
