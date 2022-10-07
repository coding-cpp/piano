#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED

#include <SFML/Graphics.hpp>

class Key
{
    protected:
        sf::RenderWindow* window;
        sf::RectangleShape* rect;

    public:
        Key();
        ~Key();

        void draw();
};

#endif // KEY_H_INCLUDED