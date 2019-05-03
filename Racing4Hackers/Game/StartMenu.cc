//
//StartMenu.cc
//
#include "StartMenu.h"
#include "../Vehicle/Car.h"
#include "../Vehicle/Motorcycle.h"
#include <iostream>

using namespace std;

const string StartMenu::track1{"HighWayToHell"};
const string StartMenu::track2{"StairWayToHeaven"};

StartMenu::StartMenu() : highScore1{"Data/" + track1 + ".hs"}, highScore2{"Data/" + track2 + ".hs"}
{

}

//valid inputs in the terminal start menu
const string StartMenu::validCommands{"PHE"};

//wait on, validate and execute commands from the user
void StartMenu::run()
{
    printMenu();

    do
    {
        try
        {
            getCommand();
            if (validCommand())
            {
                executeCommand();
            }
        }
        catch(const exception& e)
        {
            cout << e.what() << endl;
        }
    }
    while (command != 'E');
}

void StartMenu::printMenu() const
{
    cout << "\n\nRacing 4 Hackers\n\n";

    cout << "  P     Play game " << endl;
    cout << "  H     Show high score" << endl;
    cout << "  E     Exit program" << endl;
}

void StartMenu::getCommand()
{
    cout << ">> ";
    cin >> command;
    command = toupper(command);
}

void StartMenu::executeCommand()
{
    switch (command)
    {
        case 'P':
            startGame();
            break;
        case 'H':
            showHighScore();
            break;
        case 'E':
            exitGame();
            break;
    }
}

bool StartMenu::validCommand() const
{
    if (validCommands.find(command) == string::npos)
    {
        cout << "Invalid command: " << command << "" << endl;
        return false;
    }
    return true;
}

//Create, and call run()-function of, a Fgine object with
//parameters depending on input (name and vehicle type) by the user
void StartMenu::startGame()
{
    string playerName;
    cout << "Type your name:" << endl;
    cin >> playerName;

    chooseVehicle(playerName);
    chooseTrack();

    GameEngine gameEngine(vehicle, trackName);
    gameEngine.run();

    cout << "\nYour time was " << vehicle->getTimeString() << endl;
    if (trackName == track1)
    {
        if (highScore1.updateHighScore(vehicle))
        {
            cout << "NEW HIGHSCORE" << endl;
            highScore1.writeHighScore();
        }
    }
    else if (trackName == track2)
    {
        if (highScore2.updateHighScore(vehicle))
        {
            cout << "NEW HIGHSCORE" << endl;
            highScore2.writeHighScore();
        }
    }
    printMenu();
}

//creates vehicle object if input is valid
void StartMenu::chooseVehicle(string playerName)
{
    int vehicleType{0};

    cin.ignore(1000, '\n');
    cout << "Choose vehicle:" << endl;
    cout << "1. Car" << endl;
    cout << "2. MotorCycle" << endl;

    //check if integer
    while (!(cin >> vehicleType))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input must be an integer. Try again:" << endl;
    }

    //create vehicle object
    if (vehicleType == 1)
    {

        vehicle = new Car{330, 32, 180, playerName};

    }
    else if (vehicleType == 2)
    {
        vehicle = new Motorcycle{330, 32, 180, playerName};
    }
    else //rerun function if input not 1 or 2
    {
        cout << "Invalid input!" << endl;
        chooseVehicle(playerName);
    }
}

//validate input and assign track name
void StartMenu::chooseTrack()
{
    int track{0};

    cin.ignore(1000, '\n');
    cout << "Choose track:" << endl;
    cout << "1. Highway to Hell" << endl;
    cout << "2. Stairway to Heaven" << endl;

    //check if integer
    while (!(cin >> track))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input must be an integer. Try again:" << endl;
    }

    //assign track name
    if (track == 1)
    {
        trackName = track1;
    }
    else if (track == 2)
    {
        trackName = track2;
    }
    else //rerun function if input not 1 or 2
    {
        cout << "Invalid input!" << endl;
        chooseTrack();
    }
}

void StartMenu::showHighScore()
{
    highScore1.printHighScore();
    highScore2.printHighScore();
    printMenu();
}

void StartMenu::exitGame()
{
    cout << "Shutting down..." << endl;
}
