#ifndef WHITE_KEY_H_INCLUDED
#define WHITE_KEY_H_INCLUDED

#include "config.h"
#include "key.h"

const sf::Color whiteKeyPressedColor(200, 200, 200);

class WhiteKey : public Key
{
    public:
        WhiteKey();
        WhiteKey(sf::RenderWindow* renderWindow, int num, double pitchInit, sf::SoundBuffer* soundBuffer);
        ~WhiteKey();
};

#endif // WHITE_KEY_H_INCLUDED