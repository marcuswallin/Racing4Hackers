#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle{

public:
    Car() = default;
    Car(double x, double y, double startAngle, std::string name_);
    Car(const Car&) = default;


    double getAngularVelocity() override ;
    double getAcceleration() override ;
    double getMaxSpeed() override ;
    std::string getType() override ;
    double getDeacceleration() override ;

private:

};


#endif