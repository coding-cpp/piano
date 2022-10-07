#include "white_key.h"

WhiteKey::WhiteKey(){

}

WhiteKey::WhiteKey(sf::RenderWindow* renderWindow, int num){
    window = renderWindow;

    rect->setPosition(sf::Vector2f((num+4)*WINDOW_WIDTH/15, WINDOW_HEIGHT/3));
    rect->setSize(sf::Vector2f(WINDOW_WIDTH/15, WINDOW_HEIGHT/2));
    rect->setFillColor(sf::Color::White);
    rect->setOutlineThickness(5);
    rect->setOutlineColor(sf::Color::Black);
}

WhiteKey::~WhiteKey(){

}

void WhiteKey::play(){
    std::cout << "White " << rect->getPosition().x*15/WINDOW_WIDTH-4 << std::endl;
}