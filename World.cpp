#include "World.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "FpsRegulator.h"
#include <iostream>
#include "Arrow.h"

//Lungime latime 4341 x 1804  DUSTER
//Golf 5 : 4204 1759

World::World() : arrowsPool(arrowsTexture)
{
	const unsigned int xBoundery = FpsRegulator::resolution.x - FpsRegulator::sizeOfHungryDot.x;
	const unsigned int yBoundery = FpsRegulator::resolution.y - FpsRegulator::sizeOfHungryDot.y;


	fruitsTexture.loadFromFile("Media/Vegetable.png");
	arrowsTexture.loadFromFile("Media/Arrows.png");

	vegSprites.resize(DEFAULT_NR_OF_VEG);
	arrowsToDraw.resize(0);		//Tolba este goala	
	
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


	LoadArrows();
	//arrows[0].setTexture(arrowsTexture);
	//arrows[0].setTextureRect(sf::IntRect(0,0,9,17));
	//arrows[0].setPosition(300.0f , 300.0f);


}

void World::Update(const HungryDot& arg_hungryDot)
{
	//std::cout<<"vegSprites.size = "<<vegSprites.size()<<std::endl;

	for(int counter = 0; counter < vegSprites.size(); counter++)
	{
		if(arg_hungryDot.GetCurrentPosition().x == (vegSprites[counter].getPosition().x - 10))
		{
			if(arg_hungryDot.GetCurrentPosition().y == (vegSprites[counter].getPosition().y - 10))	
			{
				vegSprites.erase(vegSprites.begin() + counter);
				break;
			}
		}
	}

	std::cout<<"arrowsToDraw.size = "<<arrowsToDraw.size()<<std::endl;
	if(arrowsToDraw.size() < 4)
	{
		Arrow *tempPtr;
		bool acquired = false;

		acquired = arrowsPool.AcquireArrow(Arrow::DIRECTION::LEFT_RIGHT , &tempPtr);
		if(acquired)
		{
			arrowsToDraw.push_back(tempPtr);
			std::cout<<"Arrow acquired and pushed into vector"<<std::endl;
		}
	}

	for(auto it = arrowsToDraw.begin(); it != arrowsToDraw.end(); it++)
	{
		(*it)->MoveArrow();
	}

}

void World::Render(sf::RenderWindow& arg_window)
{
	//arg_window.draw(fruit);
	for(int counter = 0; counter < vegSprites.size(); counter++)
	{
		arg_window.draw(vegSprites[counter]);
	}

	for(auto itr = arrowsToDraw.begin(); itr != arrowsToDraw.end(); itr++)
	{
		std::cout<<"Arrow draw !"<<std::endl;
		arg_window.draw((*itr)->GetSprite());		
	}
}

void World::LoadArrows()
{
/*
	//RIGHT_LEFT ARROW <-
	allArrows[0].setTexture(arrowsTexture);
	allArrows[0].setTextureRect(sf::IntRect(50,0,17,11));

	//LEFT_RIGHT ARROW ->
	allArrows[1].setTexture(arrowsTexture);	
	allArrows[1].setTextureRect(sf::IntRect(31,0,17,11));

	//DOWN_UP ARROW 
	allArrows[2].setTexture(arrowsTexture);
	allArrows[2].setTextureRect(sf::IntRect(0,0,8,17));

	//UP_DOWN ARROW
	allArrows[3].setTexture(arrowsTexture);
	allArrows[2].setTextureRect(sf::IntRect(16,0,10,17));
*/
}


void World::Level1()
{


}
