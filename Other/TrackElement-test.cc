#include "catch.hpp"

#include "../Track/Track.h"

#include "../Track/Grass.h"
#include "../Track/Asphalt.h"
#include "../Track/Finish.h"

#include "../Track/Wall.h"


using namespace std;



//TESTS----------------------------------------

TEST_CASE("Asphalt") {

    Asphalt as{};
    REQUIRE(as.getAngularVelocity() == 3);
    REQUIRE(as.getAcceleration() == 5);
    REQUIRE(as.getMaxSpeed() == 3.3);
    REQUIRE(as.getDeAcceleration() == 1);


}

TEST_CASE("Grass") {

    Grass g{};
    REQUIRE(g.getAngularVelocity() == 2.4);
    REQUIRE(g.getAcceleration() == 3);
    REQUIRE(g.getMaxSpeed() == 2);
    REQUIRE(g.getDeAcceleration() == 0);


}


TEST_CASE("Finish") {

    Finish f{};
    REQUIRE(f.getAngularVelocity() == 3);
    REQUIRE(f.getAcceleration() == 5);
    REQUIRE(f.getMaxSpeed() == 3.3);
    REQUIRE(f.getDeAcceleration() == 1);



}




TEST_CASE("Track; OnlyAsphalt") {

    Track tr{"/home/marwa079/TDDC76/christoffer-3/Data/OnlyAsphalt.map"};

    REQUIRE(tr.getTrackElement(2,4)->getAcceleration() == 5);
    REQUIRE(tr.getTrackElement(49,1)->getAcceleration() == 5);
    REQUIRE_THROWS_AS(tr.getTrackElement(1,40), out_of_range);
    REQUIRE_THROWS_AS(tr.getTrackElement(50,1), out_of_range);



}


TEST_CASE("Track; TestTrack") {

    Track tr{"/home/marwa079/TDDC76/christoffer-3/Data/TestTrack.map"};

    REQUIRE(tr.getTrackElement(2,4)->getAcceleration() == 3);
    REQUIRE(tr.getTrackElement(9,1)->getAcceleration() == 5);
    REQUIRE(tr.getTrackElement(10,1)->getAcceleration() == 5);
    REQUIRE(tr.getTrackElement(11,1)->getAcceleration() == 5);
    REQUIRE(tr.getTrackElement(12,1)->getAcceleration() == 5);
    REQUIRE(tr.getTrackElement(13,1)->getAcceleration() == 3);

    Finish* f1 = dynamic_cast<Finish*>(tr.getTrackElement(3,9));
    REQUIRE(f1 != nullptr);

    Finish* f2 = dynamic_cast<Finish*>(tr.getTrackElement(2,9));
    REQUIRE(f2 == nullptr);

    REQUIRE_THROWS_AS(tr.getTrackElement(-100,-5), out_of_range);
    REQUIRE_THROWS_AS(tr.getTrackElement(1,40), out_of_range);
    REQUIRE_THROWS_AS(tr.getTrackElement(50,1), out_of_range);


}

TEST_CASE("Track; wrong filename") {


    REQUIRE_THROWS_AS(Track{"fel namn"}, invalid_argument);


}



//-----------WALL----------------------------


//this will not work later
TEST_CASE("Wall"){

    Wall w(1,4,3,2);
    REQUIRE(w.X1 == 1);
    REQUIRE(w.Y1 == 4);
    REQUIRE(w.X2 == 3);
    REQUIRE(w.Y2 == 2);


}

TEST_CASE("Track loadWalls") {

  //  Track tr{"/home/marwa079/TDDC76/christoffer-3/Data/TestTrack"};

}





