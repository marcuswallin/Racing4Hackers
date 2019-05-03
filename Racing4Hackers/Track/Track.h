//
//Track.h
//
#ifndef TRACK_H
#define TRACK_H



#include <string>
#include <vector>
#include "TrackElement.h"
#include <memory>
#include "Wall.h"
#include "CheckPoint.h"
#include "Finish.h"


class  Track
{
private:
    std::string trackName;

    std::vector<std::vector<std::unique_ptr<TrackElement>>> track;
    std::vector<Wall> walls;
    std::vector<CheckPoint*> checkPoints;
    Finish finish;



public:
    Track(std::string const & trackName);

    std::string getTrackName();

    TrackElement*  getTrackElement(double x, double y) const;
    void loadTrack(std::string const & trackName);
    void loadWalls(std::string const & trackName);

    std::vector<Wall> collisionAllWalls(Vehicle * vehicle) noexcept;
    void detectCheckPoints(Vehicle * vehicle)  noexcept;
    bool detectFinish(Vehicle* vehicle)  noexcept;
};

#endif