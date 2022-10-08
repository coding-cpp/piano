#ifndef WHITE_KEY_H_INCLUDED
#define WHITE_KEY_H_INCLUDED

#include "key/key.h"

class WhiteKey : public Key
{
    public:
        WhiteKey();
        WhiteKey(sf::RenderWindow* renderWindow, sf::SoundBuffer* soundBuffer, int octaveNumber, int position, double pitch);
        ~WhiteKey();
};

#endif // WHITE_KEY_H_INCLUDED