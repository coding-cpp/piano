#ifndef WHITE_KEY_H_INCLUDED
#define WHITE_KEY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "config.h"

class WhiteKey
{
    private:
        sf::RenderWindow* window;
        sf::RectangleShape* rect;

    public:
        WhiteKey();
        WhiteKey(sf::RenderWindow* renderWindow, int num);
        ~WhiteKey();

        void draw();
        void play();
};

#endif // WHITE_KEY_H_INCLUDED