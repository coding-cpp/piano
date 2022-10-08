#include "octave/white.h"

WhiteOctave::WhiteOctave(){

}

WhiteOctave::WhiteOctave(sf::RenderWindow* renderWindow, sf::SoundBuffer* soundBuffer, int octaveNumber, const double frequencies[]){
    for (int i=0; i<7; i++)
        keys[i] = new WhiteKey(renderWindow, soundBuffer, octaveNumber, i, (frequencies[i]/baseFrequency));
}

WhiteOctave::~WhiteOctave(){
    for (int i=0; i<7; i++)
        delete keys[i];
}

void WhiteOctave::draw(){
    for (int i=0; i<7; i++)
        keys[i]->draw();
}

void WhiteOctave::pressKeyByNumber(int keyNum){
    keys[keyNum]->press();
}

void WhiteOctave::stopPressingKeyByNumber(int keyNum){
    keys[keyNum]->stopPressing();
}

void WhiteOctave::stopPlaying(){
    for (int i=0; i<7; i++)
        keys[i]->stopPlaying();
}