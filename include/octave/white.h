#ifndef WHITE_OCTAVE_H_INCLUDED
#define WHITE_OCTAVE_H_INCLUDED

#include "key/white.h"

class WhiteOctave
{
    private:
        WhiteKey* keys[7];
    
    public:
        WhiteOctave();
        WhiteOctave(sf::RenderWindow* renderWindow, sf::SoundBuffer* soundBuffer, int octaveNumber, const double frequencies[]);
        ~WhiteOctave();

        void draw();
        void pressKeyByNumber(int keyNum);
        void stopPressingKeyByNumber(int keyNum);
        void stopPlaying();
};

#endif // WHITE_OCTAVE_H_INCLUDED