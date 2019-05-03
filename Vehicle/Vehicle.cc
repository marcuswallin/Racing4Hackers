//
//Vehicle.cc
//

#include "Vehicle.h"
#include "../Track/Wall.h"
//#include "TrackElement.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>


#include <iostream>

using namespace std;

Vehicle::Vehicle(double x, double y, double startAngle, string name_) :
        xpos{x}, ypos{y}, angle{startAngle}, name{name_}
{

}

double Vehicle::getX() const
{
    return xpos;
}

double Vehicle::getY() const
{
    return ypos;
}

double Vehicle::getAngle() const
{
    return angle;
}

void Vehicle::saveTime(int t)
{
    hundreds = t;
}

int Vehicle::getTime() const
{
    return hundreds;
}

string Vehicle::getTimeString() const
{
    stringstream ss;
    ss << setfill('0') << setw(2) << (hundreds / 6000)
       << ":" << setw(2) << (hundreds / 100 % 60)
       << "." << setw(2) << (hundreds % 100);
    return ss.str();
}


string Vehicle::getName() const
{
    return name;
}




void Vehicle::moveForward(TrackElement* te)
{
    xpos = xpos + speed * cos((3.14 / 180) * angle);
    ypos = ypos - speed * sin((3.14 / 180) * angle);
}

void Vehicle::accelerate(TrackElement *te)
{
    if(speed < getMaxSpeed()*te->getMaxSpeed())
    {

        speed = speed + getAcceleration()*te->getAcceleration();




    }
    else if (speed > getMaxSpeed()*te->getMaxSpeed())
    {
        deAccelerate(te);
    }
}

void Vehicle::rotateLeft(TrackElement* te)
{
    angle = angle + getAngularVelocity()*te->getAngularVelocity();
}

void Vehicle::rotateRight(TrackElement* te)
{
    angle = angle - getAngularVelocity()*te->getAngularVelocity();
}






//checks all checkpoints and adds the checkpoint to checkPoints
// if it can not find it in the list
//if it already is there it will do nothing
void Vehicle::addCheckPointNotIncluded(CheckPoint * c) noexcept{

    auto it = checkPoints.begin();

    while(it != checkPoints.end())
    {
        if(*it == c)
            return;

        ++it;
    }
    cout << "Checkpoint! Time: " << getTimeString() << endl;
    checkPoints.emplace_back(c);

}


bool Vehicle::checkedCheckPoints(std::vector<CheckPoint *> const &v)
const noexcept{

    return v.size() == checkPoints.size();



}


void Vehicle::resetCheckPoints() noexcept
{

    checkPoints.clear();

}



void Vehicle::setWheelCoordinates() noexcept {

    rightFrontWheel = getCoordRightFront();
    rightBackWheel = getCoordRightBack();
    leftFrontWheel = getCoordLeftFront();
    leftBackWheel = getCoordLeftBack();

}





//returns coordinates of right back wheel
Coordinate Vehicle::getCoordRightBack()  noexcept{

    Coordinate coordinate {};
    //vector<double> coordinates {0,0};
    double newX = xpos + 7.5 * sin((angle/360) * 2 * 3.1415);
    double newY = ypos + 7.5 * cos((angle/360) * 2 * 3.1415);


    coordinate.X = newX;
    coordinate.Y = newY;

    return coordinate;
}


//returns coordinates of left back wheel
Coordinate Vehicle::getCoordLeftBack()  noexcept{

    Coordinate coordinate {};
    double newX = xpos - 7.5 * sin((angle/360) * 2 * 3.1415);
    double newY = ypos - 7.5 * cos((angle/360) * 2 * 3.1415);


    coordinate.X = newX;
    coordinate.Y = newY;

    return coordinate;
}


//returns coordinates of right front wheel
Coordinate Vehicle::getCoordRightFront()  noexcept {

    Coordinate coordinate {move(getCoordRightBack())};

    coordinate.X = coordinate.X + 26 * cos((angle/360) * 2 * 3.1415);
    coordinate.Y = coordinate.Y - 26 * sin((angle/360) * 2 * 3.1415);

    return coordinate;

}

//returns coordinates of left front wheel
Coordinate Vehicle::getCoordLeftFront()  noexcept {

    Coordinate coordinate {move(getCoordLeftBack())};

    coordinate.X = coordinate.X + 26 * cos((angle/360) * 2 * 3.1415);
    coordinate.Y = coordinate.Y - 26 * sin((angle/360) * 2 * 3.1415);

    return coordinate;

}




void Vehicle::deAccelerateWall(TrackElement*te) {
    if (speed > 0) {

        speed -= getAcceleration()* te->getDeAcceleration();

    }else if (speed <= 0){
        speed = 0;
    }
}

void Vehicle::deAccelerate(TrackElement* te) {
    if (speed > 0) {
        speed = speed - getDeacceleration() * te->getDeAcceleration();
    } else if (speed <= 0) {
        speed = 0;
    }
}


void Vehicle::accelerateWall(TrackElement*te) {
    if(speed < getMaxSpeed()*te->getMaxSpeed())
    {
        speed += 0.5*getAcceleration()*te->getAcceleration();
    }
    else if (speed > getMaxSpeed()*te->getMaxSpeed())
    {
        deAccelerateWall(te);

    }
}


//will always take in a vector that is not empty
void Vehicle::followWall(vector<Wall> walls){

    //vector<double> distanceVector{};

    auto element = walls.begin();
    double shortestDistance{10000};

    for(auto i = walls.begin() ; i != walls.end(); ++i)
    {
        Coordinate closestEnd = i->getClosestEndPoint(rightFrontWheel);
        Coordinate farAwayEndPoint = i->getOtherEndPoint(closestEnd);

        //this will create a vector from the closest to the furthest
        Coordinate unitWallVector = (farAwayEndPoint - closestEnd)
                                    / farAwayEndPoint.distanceTo(closestEnd);

        Coordinate compPosition = closestEnd + unitWallVector;


        if (compPosition.distanceTo(Coordinate{xpos, ypos}) < shortestDistance)
        {
            element = i;
            shortestDistance = compPosition.distanceTo(Coordinate{xpos, ypos});
        }

    }


    Coordinate wallVector{element->endPoint2.X - element->endPoint1.X  ,
                          element->endPoint2.Y - element->endPoint1.Y };
    Coordinate carVector{speed * cos((3.14 / 180) * angle), - speed * sin((3.14 / 180) * angle)};


    xpos = xpos - speed * cos((3.14 / 180) * angle)  / 2;
    ypos = ypos + speed * sin((3.14 / 180) * angle)  / 2;


    Coordinate projection =  wallVector * (carVector.scalar(wallVector) /(wallVector.scalar(wallVector)));


    xpos +=  projection.X ;
    ypos +=  projection.Y;
    setWheelCoordinates();



}




















/*
void Vehicle:: followWall(vector<Wall> wall){

    if(currentWall == nullptr)
    {
        currentWall = &wall.at(0);
    }
    Coordinate carVector{speed * cos((3.14 / 180) * angle), -speed * sin((3.14 / 180) * angle)};


    if(wall.size() > 1) {
        if (&wall.at(0) == currentWall)
        {

            Coordinate wallVector{wall.at(0).endPoint2.X - wall.at(0).endPoint1.X,
                                  wall.at(0).endPoint2.Y - wall.at(0).endPoint1.Y};

           xpos = xpos - speed * cos((3.14 / 180) * angle);
            ypos = ypos + speed * sin((3.14 / 180) * angle);


            Coordinate projection = wallVector * (carVector.scalar(wallVector) / (wallVector.scalar(wallVector)));

            currentWall = &wall.at(0);
            xpos += 2 *  projection.X;
            ypos += 2 *  projection.Y;
            setWheelCoordinates();


        }
        else {


            Coordinate wallVector{wall.at(1).endPoint2.X - wall.at(1).endPoint1.X,
                                  wall.at(1).endPoint2.Y - wall.at(1).endPoint1.Y};

            xpos = xpos - speed * cos((3.14 / 180) * angle);
            ypos = ypos + speed * sin((3.14 / 180) * angle);


            Coordinate projection = wallVector * (carVector.scalar(wallVector) / (wallVector.scalar(wallVector)));

            currentWall = &wall.at(1);
            xpos += 2 * projection.X;
            ypos +=  2 * projection.Y;
            setWheelCoordinates();

/*
            bool EndPoint1Closest =
                    wall.at(0).endPoint1.distanceTo(Coordinate{xpos, ypos}) <
                    wall.at(0).endPoint2.distanceTo(Coordinate{xpos, ypos});

            Coordinate wallVector{wall.at(0).endPoint2.X - wall.at(0).endPoint1.X,
                                  wall.at(0).endPoint2.Y - wall.at(0).endPoint1.Y};

            if(EndPoint1Closest)
            {
                wallVector = Coordinate{wall.at(0).endPoint2.X - wall.at(0).endPoint1.X  , wall.at(0).endPoint2.Y - wall.at(0).endPoint1.Y};
            }
            else
            {
                wallVector = Coordinate{wall.at(0).endPoint1.X - wall.at(0).endPoint2.X  , wall.at(0).endPoint1.Y - wall.at(0).endPoint2.Y};
            }

            double scalar = wallVector.scalar(carVector);


            bool wrongWall = false;
            if(scalar > 0)
            {
                wallVector = Coordinate{currentWall->endPoint2.X - currentWall->endPoint1.X  ,
                                        currentWall->endPoint2.Y - currentWall->endPoint1.Y };

            }


            wallVector = Coordinate{wall.at(0).endPoint2.X - wall.at(0).endPoint1.X  , wall.at(0).endPoint2.Y - wall.at(0).endPoint1.Y };

            xpos = xpos - speed * cos((3.14 / 180) * angle);
            ypos = ypos + speed * sin((3.14 / 180) * angle);


            Coordinate projection =  wallVector * (carVector.scalar(wallVector) /(wallVector.scalar(wallVector)));

            currentWall = wall;
            xpos += 2 * projection.X ;
            ypos += 2 * projection.Y;
            setWheelCoordinates();

        }



    }
    else{

        Coordinate wallVector{wall.at(0).endPoint2.X - wall.at(0).endPoint1.X  , wall.at(0).endPoint2.Y - wall.at(0).endPoint1.Y };
        Coordinate carVector{speed * cos((3.14 / 180) * angle), - speed * sin((3.14 / 180) * angle)};


        wallVector = Coordinate{wall.at(0).endPoint2.X - wall.at(0).endPoint1.X  , wall.at(0).endPoint2.Y - wall.at(0).endPoint1.Y };

        xpos = xpos - speed * cos((3.14 / 180) * angle);
        ypos = ypos + speed * sin((3.14 / 180) * angle);


        Coordinate projection =  wallVector * (carVector.scalar(wallVector) /(wallVector.scalar(wallVector)));

        currentWall = &wall.at(0);
        xpos += 2 *  projection.X ;
        ypos += 2 * projection.Y;
        setWheelCoordinates();
    }

}


*/