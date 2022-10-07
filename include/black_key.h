#ifndef BLACK_KEY_H_INCLUDED
#define BLACK_KEY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "config.h"
#include "key.h"

class BlackKey : public Key
{
    public:
        BlackKey();
        BlackKey(sf::RenderWindow* renderWindow, int xPos);
        ~BlackKey();

        void play();
};

#endif // BLACK_KEY_H_INCLUDED