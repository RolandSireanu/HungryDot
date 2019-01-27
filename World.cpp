#include "World.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "FpsRegulator.h"
#include <iostream>

World::World()
{
	const unsigned int xBoundery = FpsRegulator::resolution.x - FpsRegulator::sizeOfHungryDot.x;
	const unsigned int yBoundery = FpsRegulator::resolution.y - FpsRegulator::sizeOfHungryDot.y;


	fruitsTexture.loadFromFile("Media/Vegetable.png");

	vegSprites.resize(DEFAULT_NR_OF_VEG);
	srand(time(NULL));


	for(int counter = 0; counter < DEFAULT_NR_OF_VEG; counter++)
	{
		unsigned int randXPos = rand() % xBoundery;
		unsigned int randYPos = rand() % yBoundery;
		
		randXPos -= (randXPos % FpsRegulator::sizeOfHungryDot.x);
		randYPos -= (randYPos % FpsRegulator::sizeOfHungryDot.y);

		vegSprites[counter].setTexture(fruitsTexture);
		vegSprites[counter].setTextureRect(sf::IntRect(0,0,25,25));
		vegSprites[counter].setPosition((float)randXPos+10 , (float)randYPos+10);
	}

	//fruit.setTexture(fruitsTexture);
	//fruit.setTextureRect(sf::IntRect(0,0,50,50));

	/*fruit[0].position = sf::Vector2f(30,30);	
	fruit[1].position = sf::Vector2f(30,90);	
	fruit[2].position = sf::Vector2f(90,30);
	fruit[3].position = sf::Vector2f(90,90);

	fruit[0].texCoords = sf::Vector2f(30,30);
	fruit[1].texCoords = sf::Vector2f(30,90);
	fruit[2].texCoords = sf::Vector2f(90,30);
	fruit[3].texCoords = sf::Vector2f(90,90);
	*/
}

void World::Update()
{

}

void World::Render(sf::RenderWindow& arg_window)
{
	//arg_window.draw(fruit);
	for(int counter = 0; counter < DEFAULT_NR_OF_VEG; counter++)
	{
		arg_window.draw(vegSprites[counter]);
	}
}

void World::Level1()
{


}