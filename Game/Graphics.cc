//
// Created by andan879 on 22/11/16.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iomanip>
#include <sstream>
#include <bits/unique_ptr.h>
#include "Graphics.h"
#include <iostream>

using namespace std;


/*Graphics Constructor*/
Graphics::Graphics(std::string trackName_, Vehicle* vh_)
        : trackName(trackName_) , vehicle(vh_)
{
    createWindow();
    loadSound();
    loadTrack();
    loadVehicle();
    loadContDown();
    loadFont();
    loadAnimationGraphics();
}

/*End Of Constructor - Start of Methods*/
void Graphics::loadAnimationGraphics()
{
    if(!fadeTexture.loadFromFile("Data/fade.png"))
    {
        std::cerr << "Error, could not load fade image" << std::endl;
        window.close();
    }
    else
    {
        fadeImage.setTexture(fadeTexture);

    }

}
void Graphics::createWindow()
{
    //Create window
    window.create(sf::VideoMode(800,640), "R4H");


    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(true);

}

//Load sound
void Graphics::loadSound()
{
    if(!soundBuffer.loadFromFile("Data/race_game_music.wav"))
    {
        std::cerr << "Error, could not load sound" << std::endl;
    }
    else
    {
        song1.setBuffer(soundBuffer);
    }
}

//Load vehicle
void Graphics::loadVehicle()
{
    if(vehicle->getType() == "Car")
    {
        if((!vTexture.loadFromFile("Data/car_forward.png"))
           or (!vLeftTexture.loadFromFile("Data/car_left.png"))
           or (!vRightTexture.loadFromFile("Data/car_right.png")))

        {
            std::cerr << "Error, could not load car texture" << std::endl;
            window.close();
        }
        else
        {
            vehicleImage.setTexture(vTexture);
            vehicleImage.setOrigin(5,7.5);

            vehicleLeftImage.setTexture(vLeftTexture);
            vehicleLeftImage.setOrigin(5,7.5);

            vehicleRightImage.setTexture(vRightTexture);
            vehicleRightImage.setOrigin(5,7.5);
        }
    }
    else
    {
        if ((!vTexture.loadFromFile("Data/motorcycle_forward.png"))
            or (!vLeftTexture.loadFromFile("Data/motorcycle_left.png"))
            or (!vRightTexture.loadFromFile("Data/motorcycle_right.png")))

        {
            std::cerr << "Error, could not load car texture" << std::endl;
            window.close();
        } else {

            vehicleImage.setTexture(vTexture);
            vehicleImage.setOrigin(1,7.5);

            vehicleLeftImage.setTexture(vLeftTexture);
            vehicleLeftImage.setOrigin(1, 7.5);

            vehicleRightImage.setTexture(vRightTexture);
            vehicleRightImage.setOrigin(1, 7.5);
        }
    }



}

//Load Track Image
void Graphics::loadTrack() {

    //Load Track Image
    if ((!tTexture.loadFromFile("Data/" + trackName + ".png")))

    {
        std::cerr << "Error, could not load Track texture" << std::endl;
        window.close();
    }
    else
    {
        trackImage.setTexture(tTexture);
    }
}

//Load font for time
void Graphics::loadFont()
{
    //Load font for time
    if(!font.loadFromFile("Data/Arkitech Light.ttf"))
    {
        std::cerr << "Error, timer font can not be loaded" << std::endl;
        window.close();
    };
}


//Load CountDown Images
void Graphics::loadContDown() {
    if((!c1Texture.loadFromFile("Data/cd1.png"))
       or (!c2Texture.loadFromFile("Data/cd2.png"))
       or (!c3Texture.loadFromFile("Data/cd3.png"))
       or (!goTexture.loadFromFile("Data/cdgo.png")))
    {
        std::cerr << "Error, could not load CountDown texture"
                  << std::endl;
        window.close();
    }
    else
    {
        //countdown1Image
        countdown1Image.setTexture(c1Texture);
        countdown1Image.setOrigin(125,125);
        countdown1Image.setPosition(400,320);
        //countdown2Image
        countdown2Image.setTexture(c2Texture);
        countdown2Image.setOrigin(125,125);
        countdown2Image.setPosition(400,320);
        //countdown3Image
        countdown3Image.setTexture(c3Texture);
        countdown3Image.setOrigin(125,125);
        countdown3Image.setPosition(400,320);
        //countdownGoImage
        countdownGoImage.setTexture(goTexture);
        countdownGoImage.setOrigin(200,175);
        countdownGoImage.setPosition(400,320);

    }
}

//Help function for drawTime.
std::string StringStreamTime(int hundreds)
{

    long hundreds2 = hundreds % 100;
    long seconds = hundreds / 100 % 60;
    long minutes = hundreds / 100 / 60;

    std::stringstream str;
    str << std::setfill('0') << std::setw(2)
        << minutes << ':' << std::setw(2)
        << seconds << '.' << std::setw(2) << hundreds2;
    return str.str();
}

void Graphics::handleView(int hundreds)
{
    sf::View view(sf::FloatRect(0,0,400,320));
    double ve_x = vehicle->getX();
    double ve_y = vehicle->getY();
    if((ve_x > 200 && ve_x < 600) && (ve_y > 160 && ve_y < 480))
    {
        view.setCenter(ve_x, ve_y);
        text = sf::Text(StringStreamTime(hundreds), font);
        text.setPosition(ve_x - 190,ve_y - 150);
    }

    else if(ve_x < 200 && ve_y < 160)
    {
        view.setCenter(200,160);
        text = sf::Text(StringStreamTime(hundreds), font);
        text.setPosition(10,10);
    }
    else if(ve_x < 200 && ve_y > 480)
    {
        view.setCenter(200,480);
        text = sf::Text(StringStreamTime(hundreds), font);
        text.setPosition(10,330);
    }
    else if(ve_x > 600 && ve_y < 160)
    {
        view.setCenter(600,160);
        text = sf::Text(StringStreamTime(hundreds), font);
        text.setPosition(410,10);
    }
    else if(ve_x > 600 && ve_y > 480)
    {
        view.setCenter(600,480);
        text = sf::Text(StringStreamTime(hundreds), font);
        text.setPosition(410,330);
    }
    else if(ve_x < 200)
    {
        view.setCenter(200,ve_y);
        text = sf::Text(StringStreamTime(hundreds), font);
        text.setPosition(10,ve_y - 150);
    }
    else if(ve_x > 600)
    {
        view.setCenter(600,ve_y);
        text = sf::Text(StringStreamTime(hundreds), font);
        text.setPosition(410,ve_y - 150);
    }
    else if(ve_y < 160)
    {
        view.setCenter(ve_x,160);
        text = sf::Text(StringStreamTime(hundreds), font);
        text.setPosition(ve_x - 190,10);
    }
    else if(ve_y > 480)
    {
        view.setCenter(ve_x,480);
        text = sf::Text(StringStreamTime(hundreds), font);
        text.setPosition(ve_x - 190,330);
    }

    //Set chosen view to window
    window.setView(view);
}

//drawBackground() applies .png image as background in the created window
void Graphics::drawBackground()
{
    window.draw(trackImage);
}

void Graphics::drawCountDown()
{

    for(int i = 0; i<=3;i++)
    {
        if(i==0) {
            window.draw(countdown3Image);
            window.display();
            sf::sleep(sf::seconds(1));
            window.draw(trackImage);
            window.draw(vehicleImage);
        }
        if(i == 1) {
            window.draw(countdown2Image);
            window.display();
            sf::sleep(sf::seconds(1));
            window.clear();
            window.draw(trackImage);
            window.draw(vehicleImage);
        }
        if(i == 2)
        {
            window.draw(countdown1Image);
            window.display();
            sf::sleep(sf::seconds(1));
            window.clear();
            window.draw(trackImage);
            window.draw(vehicleImage);
        }
        if(i == 3)
        {
            cout << "\nGAME START!\n" << endl;
            window.draw(countdownGoImage);
            window.display();
            sf::sleep(sf::seconds(1));

            window.clear();
            window.draw(trackImage);
            window.draw(vehicleImage);
        }
    }
}


void Graphics::playSound() {
    song1.setLoop(true);
    song1.play();
}

void Graphics::drawVehicle(bool leftTurn, bool rightTurn)
{
    float xposse {(float) vehicle->getX()};
    float yposse {(float) vehicle->getY()};
    float angle  {(float) vehicle->getAngle()};

    if (leftTurn && !rightTurn)
    {
        vehicleLeftImage.setPosition(xposse,yposse);
        vehicleLeftImage.setRotation(-angle);
        window.draw(vehicleLeftImage);
    }
    else if (!leftTurn && rightTurn)
    {
        vehicleRightImage.setPosition(xposse,yposse);
        vehicleRightImage.setRotation(-angle);
        window.draw(vehicleRightImage);
    }
    else
    {
        vehicleImage.setPosition(xposse,yposse);
        vehicleImage.setRotation(-angle);
        window.draw(vehicleImage);
    }

}

//drawTime draws a clock in the top left corner of the window.
void Graphics::drawTime()
{
    text.setCharacterSize(16);
    text.setColor(sf::Color::Black);
    window.draw(text);
}

void Graphics::finishAnimation(int hundreds,TrackElement * te)
{
    int a{0};
    for( int i = 0; i < 50;i=i+1 )
    {
        fadeImage.setColor(sf::Color(255,255,255,a));

        vehicle->moveForward(te);
        vehicle->deAccelerate(te);

        a = a + 4;

        vehicleImage.setPosition(vehicle->getX(),vehicle->getY());
        vehicleImage.setRotation(-vehicle->getAngle());
        window.draw(trackImage);
        window.draw(vehicleImage);
        window.draw(fadeImage);
        window.display();
    }
    text = sf::Text(StringStreamTime(hundreds), font);
    text.setPosition(205,125);
    text2.setCharacterSize(20);
    text.setColor(sf::Color::White);

    std::string finishMessage = "Congratulations " + vehicle->getName() + "! " + "\nYour time: ";

    text2 = sf::Text(finishMessage, font);
    text2.setPosition(207,110);
    text2.setCharacterSize(9);
    text2.setColor(sf::Color::White);

    //window.draw(fadeImage);
    window.draw(text);
    window.draw(text2);
    window.display();
    sf::sleep(sf::seconds(4));

}





