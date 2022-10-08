#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

// You may change the following variables to your liking
const sf::Vector2f whiteKeySize = sf::Vector2f(60, 200);
const sf::Vector2f blackKeySize = sf::Vector2f(40, 180);
const std::string soundFilePath = "/media/adit/HDD/GITHUB/Piano/res/sound/sound.ogg";
const sf::Color bgColor = sf::Color(80, 80, 80);

// The following variables shouldn't be changed as doing so will lead to compromise in quality
const int FPS = 20;
const int WINDOW_WIDTH = whiteKeySize.x * (3*7 + 2);
const int WINDOW_HEIGHT = whiteKeySize.y*2;
const double baseFrequency = 261.63;

// The following are the frequencies used for pitch modulation
const double whiteFrequencies[] = { 261.630, 293.665, 329.628, 349.228, 391.995, 440.000, 493.883 };
const double blackFrequencies[] = { 277.183, 311.127, 369.994, 415.305, 466.160 };

#endif // CONFIG_H_INCLUDED