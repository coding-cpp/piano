#include "piano.h"

Piano::Piano(){
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Piano");
    window->setFramerateLimit(10);
}

Piano::~Piano(){
    delete window;
}

void Piano::play(){
    while (window->isOpen()){
        window->pollEvent(event);

        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void Piano::display(){
    window->clear();
    window->display();
}