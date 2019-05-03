//
// Created by marwa079 on 2016-12-05.
//

#include "Coordinate.h"
#include <cmath>


bool Coordinate::equalsInt(int x, int y) const noexcept{

    return ((int) X == x) && ((int) Y == y);

}

Coordinate Coordinate::operator*( double k) const noexcept {
    Coordinate tempCoordinate{};
    tempCoordinate.X = X * k;
    tempCoordinate.Y = Y * k;

    return tempCoordinate;
}


Coordinate Coordinate::operator+(Coordinate const &c) const noexcept {


    Coordinate tempCoordinate{};
    tempCoordinate.X = X + c.X;
    tempCoordinate.Y = Y + c.Y;

    return tempCoordinate;
}


Coordinate Coordinate::operator-(Coordinate const &c) const noexcept {


    Coordinate tempCoordinate{};
    tempCoordinate.X = X - c.X;
    tempCoordinate.Y = Y - c.Y;

    return tempCoordinate;
}


double Coordinate::distanceTo(Coordinate const &c) const noexcept {

    double xDistance = X - c.X;
    double yDistance = Y - c.Y;

    return sqrt(pow(xDistance, 2) + pow(yDistance, 2));

}


double Coordinate::scalar(Coordinate const &c) const noexcept
{
    return X * c.X + Y * c.Y;
}


bool Coordinate::operator==(Coordinate const &c) const noexcept{

    return X == c.X && Y == c.Y;

}

Coordinate Coordinate::operator/(double value) const noexcept{

    Coordinate tempCoordinate{};
    tempCoordinate.X = X / value;
    tempCoordinate.Y = Y / value;

    return tempCoordinate;

}