#include "World.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "FpsRegulator.h"
#include <iostream>

World::World(): arrowMoves{{-10,0} , {10,0} , {0,-10}, {0,10}}
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

	if(arrowsToDraw.size() == 0)
	{
		sf::Vector2u position = GenNewArrowPos(1);

		//Add arrow sprite to vector
		//arrowsToDraw.push_back(tempSprite);


		sf::Vector2u position2 = GenNewArrowPos(0);
		
		std::cout<<"x , y = "<<position2.x<<" , "<<position2.y<<std::endl;
		//tempSprite2.setPosition((float)position2.x , (float)position2.y);
		//arrowsToDraw.push_back(tempSprite2);


		//std::cout<<"Generated positon = "<<position.x<<" , "<<position.y<<std::endl;
	}
	else
	{	
		//Move the arrow
		for(int c = 0; c < arrowsToDraw.size(); c++)
		{
			// arrowsToDraw[c]

		}

		for(auto itr = arrowsToDraw.begin(); itr != arrowsToDraw.end(); itr++)
		{ 
			itr->move(sf::Vector2f(10.0f , 0.0f));
		}
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
		arg_window.draw(*itr);		
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


sf::Vector2u World::GenNewArrowPos(unsigned int startingDirection)
{
	//srand(time(NULL));

	switch(startingDirection)
	{

		//RIGHT_LEFT ARROW
		case 0:
		{
			//(x , y)


			return sf::Vector2u(FpsRegulator::resolution.x-100,100);

			break;
		}

		//LEFT_RIGHT Arrow ->
		case 1:
		{
			unsigned int pos = rand() % FpsRegulator::resolution.y;
			unsigned int temp = (pos % FpsRegulator::sizeOfHungryDot.y);
			pos = pos - temp + 23;

			return sf::Vector2u(0 , pos);

			break;
		}

		


		default :
			break;
	}

	return sf::Vector2u(0,0);


}