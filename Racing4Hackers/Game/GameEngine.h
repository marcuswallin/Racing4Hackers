//
//GameEngine.h
//
//Game loop that communicates with the different parts of the game.
//Keyboard inputs are handled, graphic functions are called at and
//the vehicle object is controlled.

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "../Vehicle/Vehicle.h"
#include "Graphics.h"
#include "../Track/Track.h"
#include "../SFML/Graphics.hpp"
#include "../Vehicle/Car.h"
#include "../Vehicle/Motorcycle.h"

#include <string>
#include <iostream>
#include <memory>

class GameEngine
{

public:
    GameEngine(Vehicle* vehicle, std::string trackName);
    ~GameEngine() = default;

    void run();


private:
    void handleInput(sf::RenderWindow& window, bool& running, std::vector<Wall> w);
    void renderGraphics(Graphics& graphics, int hundreds);

    bool leftTurn{false};
    bool rightTurn{false};

    Vehicle* vehicle;
    Track track;

};



#endif
