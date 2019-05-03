//
// Created by marwa079 on 2016-12-05.
//

#ifndef RACING4HACKERS_COORDINATE_H
#define RACING4HACKERS_COORDINATE_H


struct Coordinate {

    double X{};
    double Y{};


    Coordinate() = default;
    Coordinate(double x, double y) : X{x} , Y{y} {};
    Coordinate(Coordinate const &) = default;


    Coordinate operator*(double k) const noexcept;
    Coordinate operator+(Coordinate const & c) const noexcept;
    Coordinate operator-(Coordinate const & c) const noexcept;
    Coordinate operator/(double value) const noexcept;
    bool equalsInt(int x, int y) const noexcept;
    bool operator == (Coordinate const & c) const noexcept;
    double distanceTo(Coordinate const & c) const noexcept;

    double scalar(Coordinate const & c) const noexcept ;
};


#endif //RACING4HACKERS_COORDINATE_H
