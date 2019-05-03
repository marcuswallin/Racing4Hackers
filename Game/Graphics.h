//
// Created by andan879 on 22/11/16.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Vehicle/Vehicle.h"

#ifndef SFMLCLION_GRAPHICS_H
#define SFMLCLION_GRAPHICS_H


class Graphics {

public:
    /*Constructor*/
    Graphics(const std::string trackName_, Vehicle* vh);
    /*Destructor*/
    ~Graphics() = default;

    /*Data Members*/
    /*Window*/
    sf::RenderWindow window;
    /*Track*/
    sf::Texture tTexture;
    sf::Sprite trackImage;

    /*Vehicle*/
    //Car
    sf::Texture vTexture;
    sf::Sprite vehicleImage;

    sf::Texture vLeftTexture;
    sf::Sprite vehicleLeftImage;

    sf::Texture vRightTexture;
    sf::Sprite vehicleRightImage;
    //Motorcycle (implement later)

    sf::Texture mTexture;
    sf::Sprite motorcycleImage;


    /*CountDown*/
    sf::Texture c1Texture;
    sf::Sprite countdown1Image;

    sf::Texture c2Texture;
    sf::Sprite countdown2Image;

    sf::Texture c3Texture;
    sf::Sprite countdown3Image;

    sf::Texture goTexture;
    sf::Sprite countdownGoImage;

    /*Finish Animation*/
    sf::Texture fadeTexture;
    sf::Sprite fadeImage;

    /*Fonts*/
    //font for time
    sf::Font font;
    sf::Text text;
    sf::Text text2;

    /*Sounds (needs fixing)*/

    sf::SoundBuffer soundBuffer;
    sf::Sound song1;

    /*Methods*/
    void drawBackground();
    void drawVehicle(bool leftTurn, bool rightTurn);
    void drawTime();
    void drawCountDown();
    void playSound();
    void handleView(int hundreds);
    void finishAnimation(int hundreds, TrackElement * te);



private:
    std::string trackName;
    Vehicle* vehicle;

    /*methods*/
    void loadFont();
    void loadContDown();
    void loadTrack();
    void loadSound();
    void loadVehicle();
    void createWindow();
    void loadAnimationGraphics();


};


#endif //SFMLCLION_GRAPHICS_H