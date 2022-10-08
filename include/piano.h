#ifndef PIANO_H_INCLUDED
#define PIANO_H_INCLUDED

#include "white_key.h"
#include "black_key.h"
#include "sound_config.h"

class Piano
{
    private:
        sf::RenderWindow* window;
        sf::Event event;
        sf::RectangleShape* background;

        sf::SoundBuffer* soundBuffer;
        sf::Sound* sound;

        WhiteKey* whiteKeys[7];
        BlackKey* blackKeys[5];

    public:
        Piano();
        ~Piano();

        void play();
        void stopPlaying();

        void display();
        
        void handleKeyboard();
};

#endif // PIANO_H_INCLUDED