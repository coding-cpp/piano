#ifndef BLACK_KEY_H_INCLUDED
#define BLACK_KEY_H_INCLUDED

#include "key/key.h"

class BlackKey : public Key
{
    public:
        BlackKey();
        BlackKey(sf::RenderWindow* renderWindow, sf::SoundBuffer* soundBuffer, int octaveNumber, int position, double pitch);
        ~BlackKey();
};

#endif // BLACK_KEY_H_INCLUDED