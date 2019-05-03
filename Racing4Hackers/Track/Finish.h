//
// Created by marwa079 on 2016-11-24.
//

#ifndef RACING_4_HACKERZ_FINISH_H
#define RACING_4_HACKERZ_FINISH_H


#include "TrackLine.h"

class Finish : public TrackLine{
public:

    Finish(double x1,double y1, double x2 , double y2)
            : TrackLine{x1,y1,x2,y2} {};


    Finish() = default;


};


#endif //RACING_4_HACKERZ_FINISH_H
