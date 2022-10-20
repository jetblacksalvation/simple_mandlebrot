// seirpinski.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <complex>
#include <string.h>

using  comp = std::complex<double>;



comp mandle(comp z, comp c) {
    //sortof efficient, it doesn't re initialize variables, which is good 
    z = pow(z, 2) + c;


    return z;
}

int main()
{
    //numbers 
    comp z(0, 0);

    //---


    sf::RectangleShape pixel;
    pixel.setSize({ 1,1 });

    sf::RenderWindow window({ 800,800 }, "seirpinksi");
    sf::Event event;

    int x = 0;
    char buffer[10];

    puts("give me the x pos of mandle brot\n");
    fgets(buffer, 10, stdin);
    float x_start = atof(buffer);
    strcmp(buffer, " ");
    puts("give me the y pos of mandle brot\n");
    fgets(buffer, 10, stdin);
    float y_start = atof(buffer);


    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == event.Closed) {
                window.close();
            }

        }
        for (float xpos = x_start; xpos <= x_start +800; xpos++) {

            for (float ypos = y_start; ypos <= y_start+800; ypos++) {



                for (x =0; x < 255 and abs(z) <2; x++) {
                    z = mandle(z, {  xpos / 800, ypos / 800 });
                    
               
                }
                pixel.setPosition({ xpos-x_start, ypos-y_start });
                pixel.setFillColor(sf::Color(x,x,x));
                window.draw(pixel);
                window.display();
                z = { 0,0 };
            }
        }
        //finished the vals
        
        exit(0);
        
        //render stuff and do math here

    }
}

