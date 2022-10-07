#include "black_key.h"

BlackKey::BlackKey(){

}

BlackKey::BlackKey(sf::RenderWindow* renderWindow, int xPos){
    window = renderWindow;

    rect = new sf::RectangleShape();
    rect->setPosition(sf::Vector2f(xPos+10, WINDOW_HEIGHT/6));
    rect->setSize(sf::Vector2f(WINDOW_WIDTH/15-20, WINDOW_HEIGHT/2.5));
    rect->setFillColor(sf::Color::Black);
}

BlackKey::~BlackKey(){
    delete rect;
}

void BlackKey::draw(){
    window->draw(*rect);
}

void BlackKey::play(){
    std::cout << "Black " << rect->getPosition().x-10 << std::endl;
}