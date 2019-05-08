#include <iostream>
#include "Window.h"
#include "Game.h"
#include "HungryDot.h"
#include "FpsRegulator.h"
#include "SFML/System/Clock.hpp"
#include "Application.h"


using namespace std;

FpsRegulator useless;

int main()
{
	Application application;

	application.run();

	return 0;
}
