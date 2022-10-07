#include "piano.h"

Piano::Piano(){
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Piano");
    window->setFramerateLimit(20);

    background = new sf::RectangleShape();
    background->setPosition(sf::Vector2f(0, 0));
    background->setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    background->setFillColor(sf::Color::Cyan);
    
    soundBuffer = new sf::SoundBuffer();
    if (!soundBuffer->loadFromFile(soundFile)){
        std::cout << "Couldn't load sound file. Exiting now.." << std::endl;
        exit(1);
    }

    for (int i=0; i<7; i++)
        whiteKeys[i] = new WhiteKey(window, i, (frequency[i]/frequency[0]), soundBuffer);
    double xPosBlack[5] = {9.0/30.0, 11.0/30.0, 15.0/30.0, 17.0/30.0, 19.0/30.0};
    for (int i=0; i<5; i++)
        blackKeys[i] = new BlackKey(window, WINDOW_WIDTH*xPosBlack[i], (frequency[i+7]/frequency[0]), soundBuffer);
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
    else
        whiteKeys[0]->stopPlaying();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        blackKeys[0]->play();
    else
        blackKeys[0]->stopPlaying();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        whiteKeys[1]->play();
    else
        whiteKeys[1]->stopPlaying();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        blackKeys[1]->play();
    else
        blackKeys[1]->stopPlaying();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
        whiteKeys[2]->play();
    else
        whiteKeys[2]->stopPlaying();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
        whiteKeys[3]->play();
    else
        whiteKeys[3]->stopPlaying();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
        blackKeys[2]->play();
    else
        blackKeys[2]->stopPlaying();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
        whiteKeys[4]->play();
    else
        whiteKeys[4]->stopPlaying();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
        blackKeys[3]->play();
    else
        blackKeys[3]->stopPlaying();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
        whiteKeys[5]->play();
    else
        whiteKeys[5]->stopPlaying();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
        blackKeys[4]->play();
    else
        blackKeys[4]->stopPlaying();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
        whiteKeys[6]->play();
    else
        whiteKeys[6]->stopPlaying();
}