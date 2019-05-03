//
// Created by marwa079 on 2016-12-05.
//

#ifndef RACING4HACKERS_TRACKLINE_H
#define RACING4HACKERS_TRACKLINE_H


#include "../Other/Coordinate.h"
#include "../Vehicle/Vehicle.h"
//#include "../Vehicle/Vehicle.h"

//class Vehicle;

class TrackLine  {
public:

    TrackLine(double x1,double y1, double x2 , double y2);

    TrackLine() = default;
    bool detectCollision(Vehicle *vehicle) const noexcept;

    Coordinate getClosestEndPoint(Coordinate const & c) const noexcept;
    Coordinate getOtherEndPoint(Coordinate const & c) const noexcept;

    Coordinate endPoint1;
    Coordinate endPoint2;

private:



    bool inBetween(Coordinate const & wheel) const noexcept;



};


#endif //RACING4HACKERS_TRACKLINE_H
