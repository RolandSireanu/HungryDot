#include <iostream>
#include "Window.h"
#include "Game.h"
#include "HungryDot.h"
#include "FpsRegulator.h"
using namespace std;

FpsRegulator useless;

int main()
{
	Game game;


	while(!game.GetWindow()->IsDone())
	{

		game.Update();
		game.Render();
		sf::sleep(sf::milliseconds(FpsRegulator::GetMsOfSleepApp()));
	}


	return 0;
}