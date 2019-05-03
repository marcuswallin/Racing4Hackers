//
// Created by marwa079 on 2016-12-05.
//

#ifndef RACING4HACKERS_CHECKPOINT_H
#define RACING4HACKERS_CHECKPOINT_H


//#include "Asphalt.h"
#include "TrackLine.h"

class CheckPoint : public TrackLine {
public:
    CheckPoint(double x1,double y1, double x2 , double y2)
            : TrackLine{x1,y1,x2,y2} {};
};


#endif //RACING4HACKERS_CHECKPOINT_H
