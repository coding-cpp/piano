#include "white_key.h"

WhiteKey::WhiteKey(){

}

WhiteKey::WhiteKey(sf::RenderWindow* renderWindow, int num, double pitch, sf::SoundBuffer* soundBuffer){
    window = renderWindow;

    sound->setBuffer(*soundBuffer);
    sound->setPitch(pitch);

    rect->setPosition(sf::Vector2f((num+4)*WINDOW_WIDTH/15, WINDOW_HEIGHT/3));
    rect->setSize(sf::Vector2f(WINDOW_WIDTH/15, WINDOW_HEIGHT/2));
    rect->setFillColor(sf::Color::White);
}

WhiteKey::~WhiteKey(){

}