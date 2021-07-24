#include "FpsRegulator.h"

unsigned int FpsRegulator::fps = 60;
unsigned int FpsRegulator::fpsDot = 5;
sf::Vector2u FpsRegulator::resolution = {650,450};
sf::Vector2u FpsRegulator::sizeOfHungryDot = {50,50};
sf::Time FpsRegulator::timePerFrame = sf::seconds((1.f / (float)FpsRegulator::fps));
