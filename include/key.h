#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class Key
{
    protected:
        sf::RenderWindow* window;
        sf::RectangleShape* rect;

        double pitch;

    public:
        Key();
        ~Key();

        void draw();
        void play();
};

#endif // KEY_H_INCLUDED