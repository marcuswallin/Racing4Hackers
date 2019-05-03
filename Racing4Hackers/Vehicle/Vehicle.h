//
//Vehicle.h
//
//Uncompleted. Only for testing.
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "../Track/TrackElement.h"
#include "../Other/Coordinate.h"
//#include "../Track/Wall.h"
//#include "CheckPoint.h"
#include <vector>
//#include "CheckPoint.h"

class CheckPoint;
class Wall;

class Vehicle
{
public:

    Vehicle() = default;
    Vehicle(double x, double y, double startAngle, std::string name_);
    Vehicle(const Vehicle&) = default;

    virtual double getX() const;
    virtual double getY() const;
    virtual double getAngle() const;
    virtual void saveTime(int t);
    virtual int getTime() const;
    virtual std::string getTimeString() const;
    virtual std::string getName() const;

    virtual void accelerate(TrackElement* te);
    virtual void rotateLeft(TrackElement* te);
    virtual void rotateRight(TrackElement* te);
    virtual void deAccelerate(TrackElement* te);
    //virtual std::string Vehicletype();
    virtual double getDeacceleration()=0;
    virtual double getAngularVelocity()=0;
    virtual double getAcceleration()=0;
    virtual double getMaxSpeed()=0;
    virtual std::string getType()=0;





    virtual void addCheckPointNotIncluded(CheckPoint * c) noexcept;
    bool checkedCheckPoints(std::vector<CheckPoint*> const & v) const noexcept;
    virtual void resetCheckPoints() noexcept;

    void setWheelCoordinates() noexcept;
    Coordinate rightFrontWheel;
    Coordinate rightBackWheel;
    Coordinate leftFrontWheel;
    Coordinate leftBackWheel;
    void moveForward(TrackElement* te);
    int lapNr{};
    virtual void followWall(std::vector<Wall> wall);
    virtual void deAccelerateWall(TrackElement*te);
    void accelerateWall(TrackElement*te);


protected:
    std::string name;
    std::string type;
    int hundreds;

    std::vector<CheckPoint*> checkPoints;
    double xpos{};
    double ypos{};
    double angle{};
    double speed{};




    virtual Coordinate getCoordRightBack()  noexcept;
    virtual Coordinate getCoordLeftBack()  noexcept;
    virtual Coordinate getCoordRightFront()  noexcept;
    virtual Coordinate getCoordLeftFront()  noexcept;


};






#endif
