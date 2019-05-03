#include <SFML/Graphics.hpp>
#include "../Game/Graphics.h"
int x = 10;
int y = 10;

int t = 0;
int main()
{
    //Create Graphics object
    Graphics G1("HighwayToHell", "Car");
    while (G1.window.isOpen())
    {


        sf::Event event;
        while(G1.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                G1.window.close();
        }

        G1.drawBackground();
        G1.drawVehicle();
        G1.drawTime(t);
        t++;

        G1.window.display();

        G1.vehicleImage.setPosition(x,y);
        x++;
        y++;


    }
    return 0;
}
