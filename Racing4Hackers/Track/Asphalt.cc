

#include "TrackElement.h"
#include "Asphalt.h"

using namespace std;

double Asphalt::getAcceleration() const noexcept
{
    return 1;
}

double Asphalt::getAngularVelocity() const noexcept
{
    return 4;
}


double Asphalt::getMaxSpeed() const noexcept
{
    return 5;
}


double Asphalt::getDeAcceleration() const noexcept
{
    return 0.5;
}
