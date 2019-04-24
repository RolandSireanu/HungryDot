#include "FpsRegulator.h"

unsigned int FpsRegulator::fps = 10;
unsigned int FpsRegulator::fpsDot = 5;
sf::Vector2u FpsRegulator::resolution = {650,450};
sf::Vector2u FpsRegulator::sizeOfHungryDot = {50,50};
