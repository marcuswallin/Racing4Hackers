//
// Created by marwa079 on 23/11/16.
//

#ifndef RACING_4_HACKERZ_GRASS_H
#define RACING_4_HACKERZ_GRASS_H

#include "TrackElement.h"

class Grass : public TrackElement {

public:

    Grass() = default;

    double getAcceleration() const noexcept override;
    double getDeAcceleration() const noexcept override;
    double getMaxSpeed() const noexcept override;
    double getAngularVelocity() const noexcept override;


};


#endif //RACING_4_HACKERZ_GRASS_H
