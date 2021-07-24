#include "World.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "FpsRegulator.h"
#include <iostream>
#include "Arrow.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"
#include "Globals.h"
#include "MediaResources.h"

//Lungime latime 4341 x 1804  DUSTER
//Golf 5 : 4204 1759

World::World() //: arrowsPool(new ArrowsObjectPool(arrowsTexture))
{
	const unsigned int xBoundery = FpsRegulator::resolution.x - FpsRegulator::sizeOfHungryDot.x;
	const unsigned int yBoundery = FpsRegulator::resolution.y - FpsRegulator::sizeOfHungryDot.y;

	arrowsPool = std::make_shared<ArrowsObjectPool>(arrowsTexture);

	fruitsTexture.loadFromFile(MediaResources::getVegetable());
	arrowsTexture.loadFromFile(MediaResources::getArrows());
	cannonTextureLeft.loadFromFile(MediaResources::getCannonLeft());
	cannonTextureRight.loadFromFile(MediaResources::getCannonRight());
	cannonTextureUp.loadFromFile(MediaResources::getCannonUp());
	cannonTextureDown.loadFromFile(MediaResources::getCannonDown());
	


	//{FpsRegulator::resolution.x-Cannon::CANNON_REC_SIZE,FpsRegulator::resolution.y / 2,Cannon::CANNON_DIRECTION::CANNON_LEFT}, 
		// 	{0 , FpsRegulator::resolution.y / 2,Cannon::CANNON_DIRECTION::CANNON_RIGHT},
		// 	{FpsRegulator::resolution.x / 2 , FpsRegulator::resolution.y-32,Cannon::CANNON_DIRECTION::CANNON_UP},
		// 	{FpsRegulator::resolution.x / 2 , 0,Cannon::CANNON_DIRECTION::CANNON_DOWN} 

	//cannons.resize(4);	
	// cannons.emplace_back(FpsRegulator::resolution.x-Cannon::CANNON_REC_SIZE,FpsRegulator::resolution.y / 2,Cannon::CANNON_DIRECTION::CANNON_LEFT);
	// cannons.emplace_back(0 , FpsRegulator::resolution.y / 2,Cannon::CANNON_DIRECTION::CANNON_RIGHT);
	// cannons.emplace_back(FpsRegulator::resolution.x / 2 , FpsRegulator::resolution.y-32,Cannon::CANNON_DIRECTION::CANNON_UP);
	// Cannon * c1 = new Cannon(FpsRegulator::resolution.x-Cannon::CANNON_REC_SIZE,FpsRegulator::resolution.y / 2,Cannon::CANNON_DIRECTION::CANNON_LEFT);
	// Cannon * c2 = new Cannon(0 , FpsRegulator::resolution.y / 2,Cannon::CANNON_DIRECTION::CANNON_RIGHT);
	// Cannon * c3 = new Cannon(FpsRegulator::resolution.x / 2 , FpsRegulator::resolution.y-32,Cannon::CANNON_DIRECTION::CANNON_UP);
	// Cannon * c4 = new Cannon(FpsRegulator::resolution.x / 2 , 0,Cannon::CANNON_DIRECTION::CANNON_DOWN);
	
	cannons.push_back(Cannon(FpsRegulator::resolution.x-Cannon::CANNON_REC_SIZE,FpsRegulator::resolution.y / 2,Cannon::CANNON_DIRECTION::CANNON_LEFT , cannonTextureLeft));
	cannons.push_back(Cannon(0 , FpsRegulator::resolution.y / 2,Cannon::CANNON_DIRECTION::CANNON_RIGHT , cannonTextureRight));
	cannons.push_back(Cannon(FpsRegulator::resolution.x / 2 , FpsRegulator::resolution.y-32,Cannon::CANNON_DIRECTION::CANNON_UP , cannonTextureUp));
	cannons.push_back(Cannon(FpsRegulator::resolution.x / 2 , 0,Cannon::CANNON_DIRECTION::CANNON_DOWN , cannonTextureDown));	
	
	

	if (!font.loadFromFile("Media/arial.ttf"))
	{
		std::cout<<"Can't load font !"<<std::endl;
	}
	else
	{
		std::cout<<"Font was loaded ! "<<std::endl;
		textScore.setFont(font);
		textScore.setCharacterSize(16);
		textScore.setPosition(475,10);
		textScore.setFillColor(sf::Color::Red);
		textScore.setColor(sf::Color::White);
	}


	//arrowsToDraw.resize(0);		//Tolba este goala

	ReloadVegetables();
	
	srand(time(NULL));

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

	for(auto& arrow : arrowsToDraw)
	{
		arrow.reset();
	}

	arrowsToDraw.clear();


}

#include "Timer.h"
/*
	Returns true when is GAME OVER , false otherwise 

*/
bool World::Update(HungryDot& arg_hungryDot , sf::Time dt , bool arg_firstRun)
{

	//Search collisions between HungryDot and vegetables
	unsigned int nrOfVegetablesOnMap = vegSprites.size();
	if(nrOfVegetablesOnMap == 0)
	{
		ReloadVegetables();
		arg_hungryDot.IncreaseSpeed();
	}
	else
	{
		Timer::StartTimer();
		auto newEnd = std::remove_if(vegSprites.begin() , vegSprites.end() , [&](sf::Sprite& arg_sprite)
				{
					sf::Vector2f vegPosition = arg_sprite.getPosition();
					sf::Vector2f hungryDotPosition = arg_hungryDot.GetCurrentPosition();

					if(vegPosition.x > hungryDotPosition.x+40 || vegPosition.x+25 < hungryDotPosition.x)
						return false;
					else if(vegPosition.y > hungryDotPosition.y + 40 || vegPosition.y + 25 < hungryDotPosition.y)
						return false;
					else
						return true;

				});		
		vegSprites.erase(newEnd , vegSprites.end());				
		arg_hungryDot.IncreaseScore(nrOfVegetablesOnMap - (vegSprites.size()));		

	}

	
	//Search collision between moaca and arrows
	
	auto it = std::find_if(arrowsToDraw.begin() , arrowsToDraw.end() , [&arg_hungryDot](ArrowsObjectPool::arrowUniquePtr& a){
		
		sf::Vector2u arrowP = (sf::Vector2u)a->GetSprite().getPosition();
		sf::Vector2u hungryDotP = (sf::Vector2u) arg_hungryDot.GetCurrentPosition();
			
		

		if((arrowP.x >= hungryDotP.x) && (arrowP.x <= (hungryDotP.x+arg_hungryDot.GetWidth())))
		{
			if((arrowP.y >= hungryDotP.y) && (arrowP.y <= (hungryDotP.y+arg_hungryDot.GetHeight())))
			{
				//std::cout<<"arrowP = "<<arrowP.x<<" , "<<arrowP.y<<std::endl;
				//std::cout<<"hungryDotP="<<hungryDotP.x<<" , "<<hungryDotP.y<<std::endl;
				return true;
			}
		}

		return false;
	});	
	

	if(it != arrowsToDraw.end())
		return true;


//Remove all arrows who reaches end of the screen and INCREMENT arrows positions
	arrowsToDraw.erase( std::remove_if(arrowsToDraw.begin() , arrowsToDraw.end(), [&](ArrowsObjectPool::arrowUniquePtr& pArrow)
			{
				bool wasMoved;

				wasMoved = pArrow->MoveArrow(dt);
				if(wasMoved == false)
				{					
					pArrow.reset();
					return true;
				}

				return false;
			}) , arrowsToDraw.end());


	
	//Move all cannons 
	for(auto &c : cannons)
	{
		c.MoveCannon(0);
	}



	//If there are less than 4 arrows in play add 4 more
	if(arrowsToDraw.size() < DEFAULT_NR_OF_ARROWS)
	{
		//std::unique_ptr<Arrow>tempPtr;
		bool acquired = false;

		for(int index = 0; index < DEFAULT_NR_OF_ARROWS; index++)
		{		
			ArrowsObjectPool::arrowUniquePtr tempPtr = arrowsPool->AcquireArrow((Arrow::DIRECTION)index , arg_firstRun , acquired);
			//Test code ! 			

			if(acquired)
			{
				if((Arrow::DIRECTION)index == Arrow::DIRECTION::LEFT_RIGHT)
				{
					sf::Vector2f temp = cannons[1].GetSprite().getPosition();
					cannons[1].SetFiringMode();
					//printf("sprite position = %f , %f \n" , temp.x , temp.y);
					tempPtr->SetArrowPosition(temp.x+10,temp.y+10);
					
				}
				else if((Arrow::DIRECTION)index == Arrow::DIRECTION::RIGHT_LEFT)
				{
					sf::Vector2f temp = cannons[0].GetSprite().getPosition();
					cannons[0].SetFiringMode();
					printf("sprite position = %f , %f \n" , temp.x , temp.y);
					tempPtr->SetArrowPosition(temp.x,temp.y+10);
				}
				else if((Arrow::DIRECTION)index == Arrow::DIRECTION::UP_DOWN)
				{
					sf::Vector2f temp = cannons[3].GetSprite().getPosition();
					cannons[3].SetFiringMode();
					printf("sprite position = %f , %f \n" , temp.x , temp.y);
					tempPtr->SetArrowPosition(temp.x+10,temp.y);
				}
				else if((Arrow::DIRECTION)index == Arrow::DIRECTION::DOWN_UP)
				{
					sf::Vector2f temp = cannons[2].GetSprite().getPosition();
					cannons[2].SetFiringMode();
					printf("sprite position = %f , %f \n" , temp.x , temp.y);
					tempPtr->SetArrowPosition(temp.x+10,temp.y);
				}


				std::cout<<"push_back to arrowsToDraw:"<<(unsigned int)tempPtr->direction<<std::endl;
				arrowsToDraw.push_back(std::move(tempPtr));			
				
			}
			else
			{

			}
		}
	}

	return false;
}

void World::Render(sf::RenderWindow& arg_window , const HungryDot& arg_hungryDot)
{

	textScore.setString("Current score : "+std::to_string(arg_hungryDot.GetScore())+"\n"+"Best score :"+std::to_string(arg_hungryDot.GetBestScoreSoFar()) + "\nPlayer:"+Globals::currentPlayer);

	//arg_window.draw(fruit);
	for(int counter = 0; counter < vegSprites.size(); counter++)
	{
		arg_window.draw(vegSprites[counter]);
	}

	for(auto itr = arrowsToDraw.begin(); itr != arrowsToDraw.end(); itr++)
	{
		arg_window.draw((*itr)->GetSprite());		
	}
	
	for(Cannon& c : cannons)
	{		
		arg_window.draw(c);
	}

	arg_window.draw(textScore);
}


void World::Level1()
{


}

void World::ReloadVegetables()
{
	const unsigned int xBoundery = FpsRegulator::resolution.x - FpsRegulator::sizeOfHungryDot.x;
	const unsigned int yBoundery = FpsRegulator::resolution.y - FpsRegulator::sizeOfHungryDot.y;

	vegSprites.resize(DEFAULT_NR_OF_VEG);

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
