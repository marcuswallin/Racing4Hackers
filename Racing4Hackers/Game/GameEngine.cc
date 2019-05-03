//
//GameEngine.cc
//

#include "GameEngine.h"



using namespace std;

//constructor
GameEngine::GameEngine(Vehicle* v, string trackName) : vehicle(v), track(trackName)
{

}


void GameEngine::run()
{
    Graphics graphics(track.getTrackName(), vehicle);
    int hundreds{0};


    graphics.drawBackground();
    graphics.drawVehicle(leftTurn,rightTurn);
    graphics.playSound();
    graphics.drawCountDown();


    //clock to time game loop
    bool running {true};
    sf::Clock clock;
    sf::Time targetFrameRate {sf::milliseconds(20)};


    //game loop
    while(running)
    {
        clock.restart();

        renderGraphics(graphics, hundreds);
        //check if close window
        sf::Event event;
        while (graphics.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                hundreds = 0;
                running = false;
            }
        }

        vehicle->setWheelCoordinates();
        vector<Wall> w = track.collisionAllWalls(vehicle);

        handleInput(graphics.window, running, w);


        vehicle->saveTime(hundreds);

        //timing of loop and securing constant loop time
        auto frameRate = clock.getElapsedTime();
        if(frameRate < targetFrameRate) {
            auto sleepTime = targetFrameRate - frameRate;
            sf::sleep(sleepTime);
        }


        track.detectCheckPoints(vehicle);

        if(track.detectFinish(vehicle))
        {

            TrackElement* te = track.getTrackElement(vehicle->getX(), vehicle->getY());
            graphics.finishAnimation(hundreds, te);
            running = false;


        }

        hundreds = hundreds + 2;

    }



}

//handle keyboard input and control vehicle accordingly
void GameEngine::handleInput(sf::RenderWindow& window, bool& running, vector<Wall> w )
{
    TrackElement* te = track.getTrackElement(vehicle->getX(), vehicle->getY());


    if(w.size() != 0)
    {


        vehicle->followWall(w);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            vehicle->accelerateWall(te);
        }
        else
        {
            vehicle->deAccelerateWall(te);
        }

    }
    else
    {
        //check if (de)accelerate

           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
               vehicle->accelerate(te);
           }
           else
           {
               vehicle->deAccelerate(te);
           }
        vehicle->moveForward(te);
    }

        leftTurn = false;
    //Check if rotate left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        vehicle->rotateLeft(te);
        leftTurn = true;
    }

    rightTurn = false;
    //Check if rotate right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        vehicle->rotateRight(te);
        rightTurn = true;
    }
}

//draw graphics
void GameEngine::renderGraphics(Graphics& graphics, int hundreds) {
    graphics.window.clear();
    graphics.drawBackground();
    graphics.drawVehicle(leftTurn, rightTurn);

    graphics.drawTime();
    graphics.handleView(hundreds);
    graphics.window.display();

}
