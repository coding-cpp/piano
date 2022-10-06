#ifndef PIANO_H_INCLUDED
#define PIANO_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "config.h"

class Piano
{
    private:
        sf::RenderWindow* window;
        sf::Event event;

    public:
        Piano();
        ~Piano();

        void play();
        void display();
};

#endif // PIANO_H_INCLUDED