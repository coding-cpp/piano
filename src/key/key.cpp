#include "key/key.h"

Key::Key(){
    sound = new sf::Sound();

    rect = new sf::RectangleShape();
    rect->setOutlineColor(sf::Color::Black);
    rect->setOutlineThickness(2);

    isPlaying = false;
}

Key::~Key(){
    delete rect;
    delete sound;
}

void Key::draw(){
    window->draw(*rect);
}

void Key::press(){
    if (!isPlaying){
        sound->stop();
        sound->play();
        isPlaying = true;

        if (rect->getFillColor() == sf::Color::White)
            rect->setFillColor(sf::Color(200, 200, 200));
        else if (rect->getFillColor() == sf::Color::Black)
            rect->setFillColor(sf::Color(50, 50, 50));
    }
}

void Key::stopPressing(){
    if (rect->getFillColor() == sf::Color(200, 200, 200))
        rect->setFillColor(sf::Color::White);
    else if (rect->getFillColor() == sf::Color(50, 50, 50))
        rect->setFillColor(sf::Color::Black);

    isPlaying = false;
}

void Key::stopPlaying(){
    sound->stop();
    stopPressing();
}