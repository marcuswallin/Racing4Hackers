//
//Track.cc
//
using namespace std;
#include "TrackElement.h"
#include "Asphalt.h"
#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include "Track.h"
#include "Grass.h"
#include "Wall.h"
#include <vector>


Track::Track(string const & trackName_) : trackName{trackName_}
{

    loadTrack(trackName_);
    loadWalls(trackName_);
}

string Track::getTrackName()
{
    return trackName;
}


TrackElement*  Track::getTrackElement(double x, double y) const{

    int tileX {(int) x/16};
    int tileY {(int) y/16};

    return track.at(tileY).at(tileX).get();
}


//loads the trackelements from a file
//currently adds Asphalt on All #,F, and C elements
void Track::loadTrack(std::string const & trackName) {



    ifstream in{"Data/" + trackName + ".map"};

    if(!in.is_open()){
        in.close();
        throw invalid_argument("The .map file does not exist");

    }

    char currentElement{};


    while(in.good()){

        vector<unique_ptr<TrackElement>> row;

        do{
            currentElement = in.get();


            if(currentElement == '#'){
                row.emplace_back(unique_ptr<TrackElement>(new Asphalt()));
            }
            else if(currentElement == '-'){
                row.emplace_back(unique_ptr<TrackElement>(new Grass()));
            }
             else if(currentElement == 'F'){
                 row.emplace_back(unique_ptr<TrackElement>(new Asphalt()));
             }
            else if(currentElement == 'C'){
                 row.emplace_back(unique_ptr<TrackElement>(new Asphalt()));
             }


        }
        while(currentElement != '\n' && in.good());

        track.emplace_back(move(row));
    }

    in.close();
}



//loads walls from a file

void Track::loadWalls(std::string const & trackName) {


//    ifstream in1{trackName};


    ifstream in{"Data/" + trackName + ".wall"};

    if(!in.is_open()){
        in.close();
        throw invalid_argument("The .wall file does not exist");

    }

    double x1;
    double y1;
    double x2;
    double y2;

    string lineType{};
    string line{};


    while(getline(in,line)){

        istringstream ss{line};

        if(ss >> x1)
        {
            ss >> y1;
            ss >> x2;
            ss >> y2;

            if(lineType == "wall:") {

                cout << "added wall" << endl;
                walls.emplace_back(Wall{x1, y1, x2, y2});
            }
            else if(lineType == "checkpoint:")
            {
                cout << "added checkpoint" << endl;
                checkPoints.emplace_back(new CheckPoint{x1, y1, x2, y2});
            }
            else if(lineType == "finish:")
            {
                cout << "added finish" << endl;
                finish = move(Finish{x1, y1, x2, y2});
            }

        }
        else
        {

            lineType = line;
        }

    }

    in.close();

}



//checks iif the vehicle has collided with any walls
vector<Wall> Track::collisionAllWalls(Vehicle * vehicle) noexcept {

    vector<Wall> wallVector;

    for(int i = 0 ; i < walls.size() ; ++i)
    {

        if(walls.at(i).detectCollision(vehicle))
        {

                wallVector.emplace_back(walls.at(i)) ;
        }

    }
    return wallVector;

}

//adds a checkpint to the checkpoint list of the vehicle if it passes it.
void Track::detectCheckPoints(Vehicle *vehicle) noexcept{


    for(int i = 0 ; i < checkPoints.size() ; ++i)
    {

        if(checkPoints.at(i)->detectCollision(vehicle))
        {
            vehicle->addCheckPointNotIncluded( checkPoints.at(i));
        }


    }

}

//compares if the vehicle and CheckPoints vector are the same length, if so,
//returns true
bool Track::detectFinish(Vehicle *vehicle) noexcept {

    bool result{false};

    if(finish.detectCollision(vehicle) && vehicle->checkedCheckPoints(checkPoints))
    {
        ++vehicle->lapNr;

        if(vehicle->lapNr < 3)
        {
            cout << "Laptime: " << vehicle->getTimeString() << endl;
            vehicle->resetCheckPoints();
        }
        else
        {
            result = true;
        }
    }


/*
    if(vehicle->checkedCheckPoints(checkPoints) && finish.detectCollision(vehicle))
        cout << "Finish!" << endl;
*/
    return result;

}
