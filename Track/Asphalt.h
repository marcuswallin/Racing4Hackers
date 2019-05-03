//
// Created by marwa079 on 2016-11-22.
//


#ifndef ASPHALT_H
#define ASPHALT_H


#include "TrackElement.h"
//#include "Asphalt.cc"

class Asphalt : public TrackElement
{
public:

    Asphalt() = default;

    double getAcceleration() const noexcept override;
    double getDeAcceleration() const noexcept override;
    double getMaxSpeed() const noexcept override;
    double getAngularVelocity() const noexcept override;

};


#endif
