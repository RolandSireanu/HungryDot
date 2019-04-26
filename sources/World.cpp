#include "World.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "FpsRegulator.h"
#include <iostream>
#include "Arrow.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"

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
}

void World::Reset()
{

	const unsigned int xBoundery = FpsRegulator::resolution.x - FpsRegulator::sizeOfHungryDot.x;
	const unsigned int yBoundery = FpsRegulator::resolution.y - FpsRegulator::sizeOfHungryDot.y;

	vegSprites.clear();

	for(int counter = 0; counter < DEFAULT_NR_OF_VEG; counter++)
	{
		unsigned int randXPos = rand() % xBoundery;
		unsigned int randYPos = rand() % yBoundery;
		sf::Sprite tempVeg;

		randXPos -= (randXPos % FpsRegulator::sizeOfHungryDot.x);
		randYPos -= (randYPos % FpsRegulator::sizeOfHungryDot.y);

		tempVeg.setTexture(fruitsTexture);
		tempVeg.setTextureRect(sf::IntRect(0,0,25,25));
		tempVeg.setPosition((float)randXPos+10 , (float)randYPos+10);
		vegSprites.push_back(tempVeg);
	}

	for(std::vector<Arrow*>::iterator it = arrowsToDraw.begin(); it != arrowsToDraw.end(); it++)
	{
		arrowsPool.ReleaseArrow((*it));
	}

	arrowsToDraw.clear();


}

bool World::Update(const HungryDot& arg_hungryDot , long long dt)
{

	vegSprites.erase(std::remove_if(vegSprites.begin() , vegSprites.end() , [&](sf::Sprite& arg_sprite)
			{
				sf::Vector2f vegPosition = arg_sprite.getPosition();
				sf::Vector2f hungryDotPosition = arg_hungryDot.GetCurrentPosition();

				if(vegPosition.x > hungryDotPosition.x+40 || vegPosition.x+25 < hungryDotPosition.x)
					return false;
				else if(vegPosition.y > hungryDotPosition.y + 40 || vegPosition.y + 25 < hungryDotPosition.y)
					return false;
				else
					return true;

			}) , vegSprites.end());


	//Search collision between moaca and arrows
	auto it = std::find_if(arrowsToDraw.begin() , arrowsToDraw.end() , [=](Arrow* a){
		sf::Vector2u arrowP = (sf::Vector2u)a->GetSprite().getPosition();
		sf::Vector2u hungryDotP = (sf::Vector2u) arg_hungryDot.GetCurrentPosition();

		if((arrowP.x >= hungryDotP.x) && (arrowP.x <= (hungryDotP.x+arg_hungryDot.GetWidth())))
		{
			if((arrowP.y >= hungryDotP.y) && (arrowP.y <= (hungryDotP.y+arg_hungryDot.GetHeight())))
			{
				std::cout<<"arrowP = "<<arrowP.x<<" , "<<arrowP.y<<std::endl;
				std::cout<<"hungryDotP="<<hungryDotP.x<<" , "<<hungryDotP.y<<std::endl;
				return true;
			}
		}

		return false;
	});


	if(it != arrowsToDraw.end())
		return true;


	//If there are less than 4 arrows in play add 4 more
	if(arrowsToDraw.size() < 4)
	{
		Arrow *tempPtr;
		bool acquired = false;

		for(int index = 0; index < 4; index++)
		{
			acquired = arrowsPool.AcquireArrow((Arrow::DIRECTION)index , &tempPtr);

			if(acquired)
			{
				arrowsToDraw.push_back(tempPtr);
			}
			else
			{

			}
		}
	}

	//Remove all arrows who reaches end of the screen
	arrowsToDraw.erase( std::remove_if(arrowsToDraw.begin() , arrowsToDraw.end(), [&](Arrow* pArrow)
			{
				bool wasMoved;

				wasMoved = pArrow->MoveArrow(dt);
				if(wasMoved == false)
				{
					arrowsPool.ReleaseArrow(pArrow);
					return true;
				}

				return false;
			}) , arrowsToDraw.end());

	return false;
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
		arg_window.draw((*itr)->GetSprite());		
	}
}


void World::Level1()
{


}
