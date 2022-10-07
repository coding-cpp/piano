#ifndef WHITE_KEY_H_INCLUDED
#define WHITE_KEY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "config.h"
#include "key.h"

class WhiteKey : public Key
{
    public:
        WhiteKey();
        WhiteKey(sf::RenderWindow* renderWindow, int num);
        ~WhiteKey();

        void play();
};

#endif // WHITE_KEY_H_INCLUDED