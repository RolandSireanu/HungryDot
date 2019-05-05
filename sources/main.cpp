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
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while(!game.GetWindow()->IsDone())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while(timeSinceLastUpdate > FpsRegulator::timePerFrame)
		{
			timeSinceLastUpdate -= FpsRegulator::timePerFrame;
			game.Update(FpsRegulator::timePerFrame);

		}
		game.Render();
	}


	return 0;
}
