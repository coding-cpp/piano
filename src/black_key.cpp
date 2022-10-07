#include "black_key.h"

BlackKey::BlackKey(){

}

BlackKey::BlackKey(sf::RenderWindow* renderWindow, int xPos, double pitchInit){
    window = renderWindow;
    pitch = pitchInit;

    rect->setPosition(sf::Vector2f(xPos+10, WINDOW_HEIGHT/6));
    rect->setSize(sf::Vector2f(WINDOW_WIDTH/15-20, WINDOW_HEIGHT/2.5));
    rect->setFillColor(sf::Color::Black);
}

BlackKey::~BlackKey(){

}