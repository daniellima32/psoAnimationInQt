#include "fitness.h"

int Fitness::calculateFitness(QVector2D vec)
{
    return 3 * vec.x() - vec.y();
}
