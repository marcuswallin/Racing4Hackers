//
// Created by marwa079 on 23/11/16.
//

#include "Grass.h"

using namespace std;

double Grass::getAcceleration() const noexcept
{
    return 0.6;
}

double Grass::getAngularVelocity() const noexcept
{
    return 2;
}


double Grass::getMaxSpeed() const noexcept
{
    return 2;
}


double Grass::getDeAcceleration() const noexcept
{
    return 1;
}
