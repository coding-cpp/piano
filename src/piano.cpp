#include "piano.h"

Piano::Piano(){
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Piano");
    window->setFramerateLimit(FPS);

    background = new sf::RectangleShape();
    background->setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    background->setPosition(sf::Vector2f(0, 0));
    background->setFillColor(bgColor);

    soundBuffer = new sf::SoundBuffer();
    if (!soundBuffer->loadFromFile(soundFilePath)){
        std::cout << "Couldn't load sound file. Exiting now.." << std::endl;
        exit(1);
    }

    double lowerWF[7], upperWF[7];
    double lowerBF[5], upperBF[5];

    for (int i=0; i<7; i++){
        if (i < 5){
            lowerBF[i] = blackFrequencies[i] / 2;
            upperBF[i] = blackFrequencies[i] * 2;
        }
        lowerWF[i] = whiteFrequencies[i] / 2;
        upperWF[i] = whiteFrequencies[i] * 2;
    }

    whiteOctaves[0] = new WhiteOctave(window, soundBuffer, 0, lowerWF);
    whiteOctaves[1] = new WhiteOctave(window, soundBuffer, 1, whiteFrequencies);
    whiteOctaves[2] = new WhiteOctave(window, soundBuffer, 2, upperWF);

    blackOctaves[0] = new BlackOctave(window, soundBuffer, 0, lowerBF);
    blackOctaves[1] = new BlackOctave(window, soundBuffer, 1, blackFrequencies);
    blackOctaves[2] = new BlackOctave(window, soundBuffer, 2, upperBF);
}

Piano::~Piano(){
    delete background;
    for (int i=0; i<3; i++){
        delete whiteOctaves[i];
        delete blackOctaves[i];
    }
    delete soundBuffer;
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

void Piano::stopPlaying(){
    for (int i=0; i<3; i++){
        whiteOctaves[i]->stopPlaying();
        blackOctaves[i]->stopPlaying();
    }
}

void Piano::handleKeyboard(){
    // Stop playing
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        stopPlaying();
        return;
    }

    // Lower Octave
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) whiteOctaves[0]->pressKeyByNumber(0); else whiteOctaves[0]->stopPressingKeyByNumber(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) whiteOctaves[0]->pressKeyByNumber(1); else whiteOctaves[0]->stopPressingKeyByNumber(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) whiteOctaves[0]->pressKeyByNumber(2); else whiteOctaves[0]->stopPressingKeyByNumber(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) whiteOctaves[0]->pressKeyByNumber(3); else whiteOctaves[0]->stopPressingKeyByNumber(3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) whiteOctaves[0]->pressKeyByNumber(4); else whiteOctaves[0]->stopPressingKeyByNumber(4);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) whiteOctaves[0]->pressKeyByNumber(5); else whiteOctaves[0]->stopPressingKeyByNumber(5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) whiteOctaves[0]->pressKeyByNumber(6); else whiteOctaves[0]->stopPressingKeyByNumber(6);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) blackOctaves[0]->pressKeyByNumber(0); else blackOctaves[0]->stopPressingKeyByNumber(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) blackOctaves[0]->pressKeyByNumber(1); else blackOctaves[0]->stopPressingKeyByNumber(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) blackOctaves[0]->pressKeyByNumber(2); else blackOctaves[0]->stopPressingKeyByNumber(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) blackOctaves[0]->pressKeyByNumber(3); else blackOctaves[0]->stopPressingKeyByNumber(3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash)) blackOctaves[0]->pressKeyByNumber(4); else blackOctaves[0]->stopPressingKeyByNumber(4);

    // Normal Octave
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) whiteOctaves[1]->pressKeyByNumber(0); else whiteOctaves[1]->stopPressingKeyByNumber(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) whiteOctaves[1]->pressKeyByNumber(1); else whiteOctaves[1]->stopPressingKeyByNumber(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) whiteOctaves[1]->pressKeyByNumber(2); else whiteOctaves[1]->stopPressingKeyByNumber(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) whiteOctaves[1]->pressKeyByNumber(3); else whiteOctaves[1]->stopPressingKeyByNumber(3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) whiteOctaves[1]->pressKeyByNumber(4); else whiteOctaves[1]->stopPressingKeyByNumber(4);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) whiteOctaves[1]->pressKeyByNumber(5); else whiteOctaves[1]->stopPressingKeyByNumber(5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) whiteOctaves[1]->pressKeyByNumber(6); else whiteOctaves[1]->stopPressingKeyByNumber(6);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) blackOctaves[1]->pressKeyByNumber(0); else blackOctaves[1]->stopPressingKeyByNumber(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) blackOctaves[1]->pressKeyByNumber(1); else blackOctaves[1]->stopPressingKeyByNumber(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) blackOctaves[1]->pressKeyByNumber(2); else blackOctaves[1]->stopPressingKeyByNumber(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) blackOctaves[1]->pressKeyByNumber(3); else blackOctaves[1]->stopPressingKeyByNumber(3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) blackOctaves[1]->pressKeyByNumber(4); else blackOctaves[1]->stopPressingKeyByNumber(4);

    // Upper Octave
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) whiteOctaves[2]->pressKeyByNumber(0); else whiteOctaves[2]->stopPressingKeyByNumber(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) whiteOctaves[2]->pressKeyByNumber(1); else whiteOctaves[2]->stopPressingKeyByNumber(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) whiteOctaves[2]->pressKeyByNumber(2); else whiteOctaves[2]->stopPressingKeyByNumber(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) whiteOctaves[2]->pressKeyByNumber(3); else whiteOctaves[2]->stopPressingKeyByNumber(3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) whiteOctaves[2]->pressKeyByNumber(4); else whiteOctaves[2]->stopPressingKeyByNumber(4);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon)) whiteOctaves[2]->pressKeyByNumber(5); else whiteOctaves[2]->stopPressingKeyByNumber(5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) whiteOctaves[2]->pressKeyByNumber(6); else whiteOctaves[2]->stopPressingKeyByNumber(6);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) blackOctaves[2]->pressKeyByNumber(0); else blackOctaves[2]->stopPressingKeyByNumber(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) blackOctaves[2]->pressKeyByNumber(1); else blackOctaves[2]->stopPressingKeyByNumber(1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) blackOctaves[2]->pressKeyByNumber(2); else blackOctaves[2]->stopPressingKeyByNumber(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) blackOctaves[2]->pressKeyByNumber(3); else blackOctaves[2]->stopPressingKeyByNumber(3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)) blackOctaves[2]->pressKeyByNumber(4); else blackOctaves[2]->stopPressingKeyByNumber(4);
}

void Piano::display(){
    window->clear();
    window->draw(*background);

    for (int i=0; i<3; i++){
        whiteOctaves[i]->draw();
        blackOctaves[i]->draw();
    }

    window->display();
}