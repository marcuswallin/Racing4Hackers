//
// Created by marwa079 on 2016-11-28.
//

#ifndef RACING_4_HACKERZ_WALL_H
#define RACING_4_HACKERZ_WALL_H


#include <string>
//#include "Vehicle.h"
#include <vector>
#include "../Other/Coordinate.h"
#include "TrackLine.h"


class Wall : public TrackLine{



public:

    Wall(double x1,double y1, double x2 , double y2)
            : TrackLine{x1,y1,x2,y2} {};

};


#endif //RACING_4_HACKERZ_WALL_H
