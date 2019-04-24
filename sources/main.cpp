#include <iostream>
#include "Window.h"
#include "Game.h"
#include "HungryDot.h"
#include "FpsRegulator.h"
#include "SFML/System/Clock.hpp"

using namespace std;

FpsRegulator useless;

int main()
{
	Game game;
	sf::Clock clock;
	long long oldTimeStamp = 0;

	while(!game.GetWindow()->IsDone())
	{
		clock.restart();
		game.Update(oldTimeStamp);
		game.Render();
		//sf::sleep(sf::milliseconds(FpsRegulator::GetMsOfSleepApp()));
		oldTimeStamp = clock.getElapsedTime().asMicroseconds();
	}


	return 0;
}
