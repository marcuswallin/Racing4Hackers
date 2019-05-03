//
//Car.cc
//

#include "Car.h"
#include <string>

#include "../Track/TrackElement.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>

#include <iostream>

using namespace std;

Car::Car(double x, double y, double startAngle, string name_) :
        Vehicle(x, y, startAngle, name_ )
{
    /*
    angularVelocity = 0.85;
    acceleration = 0.1;
    maxSpeed = 1;
    type = "car";
    deacceleration = 1;
     */
}


double Car::getDeacceleration(){

    return 0.2;
}
double Car::getAngularVelocity(){

    return 0.8;

}
double Car::getAcceleration(){

    return 0.08;
}


double Car::getMaxSpeed(){

    return 1.2;


    }

string Car::getType(){

    return "Car";
}


