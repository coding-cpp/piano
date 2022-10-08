#ifndef PIANO_H_INCLUDED
#define PIANO_H_INCLUDED

#include <iostream>

#include "octave/white.h"
#include "octave/black.h"

class Piano
{
    private:
        sf::RenderWindow* window;
        sf::Event event;
        sf::RectangleShape* background;

        sf::SoundBuffer* soundBuffer;

        WhiteOctave* whiteOctaves[3];
        BlackOctave* blackOctaves[3];

    public:
        Piano();
        ~Piano();

        void play();
        void stopPlaying();
        void handleKeyboard();

        void display();
};


#endif // PIANO_H_INCLUDED