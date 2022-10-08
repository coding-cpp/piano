#include "key/black.h"

BlackKey::BlackKey(){

}

BlackKey::BlackKey(sf::RenderWindow* renderWindow, sf::SoundBuffer* soundBuffer, int octaveNumber, int position, double pitch){
    window = renderWindow;

    sound->setBuffer(*soundBuffer);
    sound->setPitch(pitch);

    double offset;
    switch (position){
        case 0:
            offset = 1;
            break;
        case 1:
            offset = 2;
            break;
        case 2:
            offset = 4;
            break;
        case 3:
            offset = 5;
            break;
        case 4:
            offset = 6;
            break;
    }
    double xPos = whiteKeySize.x*(1 + octaveNumber*7 + offset) - blackKeySize.x/2 - 2;

    rect->setSize(blackKeySize);
    rect->setFillColor(sf::Color::Black);
    rect->setPosition(sf::Vector2f(xPos, blackKeySize.y/2));
}

BlackKey::~BlackKey(){

}