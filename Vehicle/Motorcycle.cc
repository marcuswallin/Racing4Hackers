
#include "Motorcycle.h"


using namespace std;

Motorcycle::Motorcycle(double x, double y, double startAngle, string name_) :
        Vehicle(x, y, startAngle, name_)
{}



double Motorcycle::getDeacceleration(){

    return 0.2;
}
double Motorcycle::getAngularVelocity(){

    return 1;

}
double Motorcycle::getAcceleration(){

    return 0.2;
}

double Motorcycle::getMaxSpeed(){

    return 1;

}

string Motorcycle::getType(){

    return "Motorcycle";
}


