//
//TrackElement.h
//
#ifndef TRACKELEMENT_H
#define TRACKELEMENT_H



class TrackElement {

public:

    TrackElement() = default;

    virtual double getAcceleration() const noexcept = 0;
    virtual double getDeAcceleration() const noexcept = 0;
    virtual double getMaxSpeed() const noexcept = 0;
    virtual double getAngularVelocity() const noexcept = 0;

};


#endif
