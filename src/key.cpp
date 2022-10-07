#include "key.h"

Key::Key(){
    rect = new sf::RectangleShape();
}

Key::~Key(){
    delete rect;
}

void Key::draw(){
    window->draw(*rect);
}

void Key::play(){
    std::cout << pitch << std::endl;
}