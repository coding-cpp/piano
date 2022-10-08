#include "octave/black.h"

BlackOctave::BlackOctave(){

}

BlackOctave::BlackOctave(sf::RenderWindow* renderWindow, sf::SoundBuffer* soundBuffer, int octaveNumber, const double frequencies[]){
    for (int i=0; i<5; i++)
        keys[i] = new BlackKey(renderWindow, soundBuffer, octaveNumber, i, (frequencies[i]/baseFrequency));
}

BlackOctave::~BlackOctave(){
    for (int i=0; i<5; i++)
        delete keys[i];
}

void BlackOctave::draw(){
    for (int i=0; i<5; i++)
        keys[i]->draw();
}

void BlackOctave::pressKeyByNumber(int keyNum){
    keys[keyNum]->press();
}

void BlackOctave::stopPressingKeyByNumber(int keyNum){
    keys[keyNum]->stopPressing();
}

void BlackOctave::stopPlaying(){
    for (int i=0; i<5; i++)
        keys[i]->stopPlaying();
}