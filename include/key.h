#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Key
{
    protected:
        sf::RenderWindow* window;
        sf::RectangleShape* rect;

        sf::Sound* sound;

        bool isPlaying;

    public:
        Key();
        ~Key();

        void draw();
        void play();
        void stopDisplaying();
        void stopPlaying();
};

#endif // KEY_H_INCLUDED