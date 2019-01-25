#include <iostream>
#include "Window.h"
#include "Game.h"
using namespace std;


int main()
{
	Game game;


	while(!game.GetWindow()->IsDone())
	{

		game.Update();
		game.Render();
	}


	return 0;
}