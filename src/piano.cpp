#include "piano.h"

Piano::Piano(){
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Piano");
    window->setFramerateLimit(10);

    background = new sf::RectangleShape();
    background->setPosition(sf::Vector2f(0, 0));
    background->setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    background->setFillColor(sf::Color::Cyan);

    for (int i=0; i<7; i++)
        whiteKeys[i] = new WhiteKey(window, i, (frequency[i]/frequency[0]));
    double xPosBlack[5] = {9.0/30.0, 11.0/30.0, 15.0/30.0, 17.0/30.0, 19.0/30.0};
    for (int i=0; i<5; i++)
        blackKeys[i] = new BlackKey(window, WINDOW_WIDTH*xPosBlack[i], (frequency[i+7]/frequency[0]));
}

Piano::~Piano(){
    delete background;
    for (int i=0; i<7; i++)
        delete whiteKeys[i];
    for (int i=0; i<5; i++)
        delete blackKeys[i];
    delete window;
}

void Piano::play(){
    while (window->isOpen()){
        window->pollEvent(event);

        if (event.type == sf::Event::Closed)
            window->close();
        handleKeyboard();
        
        display();
    }
}

void Piano::display(){
    window->clear();
    window->draw(*background);

    for (WhiteKey* whiteKey: whiteKeys)
        whiteKey->draw();
    for (BlackKey* blackKey: blackKeys)
        blackKey->draw();
    
    window->display();
}

void Piano::handleKeyboard(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        whiteKeys[0]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        blackKeys[0]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        whiteKeys[1]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        blackKeys[1]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
        whiteKeys[2]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
        whiteKeys[3]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
        blackKeys[2]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
        whiteKeys[4]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
        blackKeys[3]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
        whiteKeys[5]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
        blackKeys[4]->play();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
        whiteKeys[6]->play();
}