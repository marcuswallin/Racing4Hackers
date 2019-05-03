//
// Created by marwa079 on 2016-12-05.
//

#include "TrackLine.h"





using namespace std;



TrackLine::TrackLine(double x1, double y1, double x2, double y2) :
        endPoint1{x1, y1} , endPoint2{x2,y2} {}



bool TrackLine::inBetween(Coordinate const &wheel) const noexcept {


    Coordinate line{endPoint1 - endPoint2};
    Coordinate lineToWheel{wheel - endPoint2};
    Coordinate projection =  line * (lineToWheel.scalar(line) /(line.scalar(line)));
    bool scalar = line.scalar(lineToWheel) > 0;

    bool inside{scalar &&
                (projection.distanceTo(Coordinate{0,0}) <
                 line.distanceTo(Coordinate{0,0}))};

    return inside;

}







//checks if the vehicle has collided with the current wall object
bool TrackLine::detectCollision(Vehicle *vehicle) const noexcept {



    Coordinate RF = vehicle->rightFrontWheel;
    Coordinate RB = vehicle->rightBackWheel;
    Coordinate LF = vehicle->leftFrontWheel;
    Coordinate LB = vehicle->leftBackWheel;



    if(!(inBetween(RF) || inBetween(LF) ||
         inBetween(RB) || inBetween(LB)) )
        return false;

    double RFCrossProduct =
            (endPoint1.X - RF.X) * (endPoint2.Y - RF.Y) -
            (endPoint1.Y - RF.Y) * (endPoint2.X - RF.X);
    double LFCrossProduct =
            (endPoint1.X - LF.X) * (endPoint2.Y - LF.Y) -
            (endPoint1.Y - LF.Y) * (endPoint2.X - LF.X);
    double RBCrossProduct =
            (endPoint1.X - RB.X) * (endPoint2.Y - RB.Y) -
            (endPoint1.Y - RB.Y) * (endPoint2.X - RB.X);
    double LBCrossProduct =
            (endPoint1.X - LB.X) * (endPoint2.Y - LB.Y) -
            (endPoint1.Y - LB.Y) * (endPoint2.X - LB.X);

    bool notCollision =
            ((RFCrossProduct > 0) &&
             (LFCrossProduct > 0) &&
             ((RBCrossProduct > 0) &&
              (LBCrossProduct > 0)) ||
             ((RFCrossProduct < 0) &&
              (LFCrossProduct < 0) &&
              (RBCrossProduct < 0) &&
              (LBCrossProduct < 0)));




    return !notCollision;
}




Coordinate TrackLine::getClosestEndPoint(Coordinate const &c) const noexcept{

    if(c.distanceTo(endPoint1) < c.distanceTo(endPoint2))
        return endPoint1;
    else
        return endPoint2;


}

Coordinate TrackLine::getOtherEndPoint(Coordinate const &c) const noexcept{

    if(c == endPoint1)
    {
        return endPoint2;
    }
    else
    {
        return endPoint1;
    }

}
