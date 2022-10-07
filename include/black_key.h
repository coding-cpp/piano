#ifndef BLACK_KEY_H_INCLUDED
#define BLACK_KEY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "config.h"

class BlackKey
{
    private:
        sf::RenderWindow* window;
        sf::RectangleShape* rect;

    public:
        BlackKey();
        BlackKey(sf::RenderWindow* renderWindow, int xPos);
        ~BlackKey();

        void draw();
        void play();
};

#endif // BLACK_KEY_H_INCLUDED