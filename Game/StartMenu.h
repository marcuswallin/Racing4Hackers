//
//StartMenu.h
//
//Start menu where commands from the user is executed.
//The user can choose between playing the game, 
//showing high score and exiting the program. 
#ifndef STARTMENU_H
#define STARTMENU_H

#include "HighScore.h"
#include "GameEngine.h"
#include "../Other/CountDown.h"
#include "../Vehicle/Vehicle.h"
#include "../Vehicle/Car.h"
#include "../Vehicle/Motorcycle.h"



#include <string>


class StartMenu
{
public:
    StartMenu();
    ~StartMenu() = default;

    StartMenu(const StartMenu&) = delete;
    StartMenu& operator=(const StartMenu&) = delete;

    void run();

private:
    static const std::string validCommands;
    char command;
    static const std::string track1;
    static const std::string track2;

    void printMenu() const;
    void getCommand();
    void executeCommand();
    bool validCommand() const;

    void startGame();
    void chooseVehicle(std::string playerName);
    void chooseTrack();

    void showHighScore();
    void exitGame();

    HighScore highScore1;
    HighScore highScore2;
    Vehicle* vehicle;
    std::string trackName;
};
#endif
