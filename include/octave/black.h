#ifndef BLACK_OCTAVE_H_INCLUDED
#define BLACK_OCTAVE_H_INCLUDED

#include "key/black.h"

class BlackOctave
{
    private:
        BlackKey* keys[5];
    
    public:
        BlackOctave();
        BlackOctave(sf::RenderWindow* renderWindow, sf::SoundBuffer* soundBuffer, int octaveNumber, const double frequencies[]);
        ~BlackOctave();

        void draw();
        void pressKeyByNumber(int keyNum);
        void stopPressingKeyByNumber(int keyNum);
        void stopPlaying();
};

#endif // BLACK_OCTAVE_H_INCLUDED