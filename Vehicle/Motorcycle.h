  #ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {

public:
    Motorcycle() = default;
    Motorcycle(double x, double y, double startAngle, std::string name_);
 //   Motorcycle(const Motorcycle&);


    double getAngularVelocity() override ;
    double getAcceleration() override ;
    double getMaxSpeed() override ;
    std::string getType() override ;
    double getDeacceleration() override ;






};



#endif
