#ifndef BLACK_KEY_H_INCLUDED
#define BLACK_KEY_H_INCLUDED

#include "config.h"
#include "key.h"

class BlackKey : public Key
{
    public:
        BlackKey();
        BlackKey(sf::RenderWindow* renderWindow, int xPos, double pitchInit, sf::SoundBuffer* soundBuffer);
        ~BlackKey();
};

#endif // BLACK_KEY_H_INCLUDED