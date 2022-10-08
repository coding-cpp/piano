#include "key/white.h"

WhiteKey::WhiteKey(){

}

WhiteKey::WhiteKey(sf::RenderWindow* renderWindow, sf::SoundBuffer* soundBuffer, int octaveNumber, int position, double pitch){
    window = renderWindow;

    sound->setBuffer(*soundBuffer);
    sound->setPitch(pitch);

    rect->setSize(whiteKeySize);
    rect->setFillColor(sf::Color::White);
    rect->setPosition(sf::Vector2f((octaveNumber*7+1+position)*whiteKeySize.x, WINDOW_HEIGHT/2-20));
}

WhiteKey::~WhiteKey(){

}