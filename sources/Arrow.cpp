#include "Arrow.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "FpsRegulator.h"
#include <iostream>
/*
	0 - RIGHT_LEFT
	1 - LEFT_RIGHT
	2 - DOWN_UP
	3 - UP_DOWN	
*/

namespace
{
	double arrowSpeed = 10;
	double shadowSpeed = 0.0;
	const double defaultArrowSpeed = 5.0;

};
const std::vector<sf::IntRect> Arrow::originPositions = {{50,0,17,11} , {31,0,17,11} , {0,0,8,17} , {16,0,10,17}};
const std::vector<sf::Vector2f> Arrow::arrowMoves = {{-1.0,0.0} , {1.0,0.0} , {0.0 ,-1.0} , {0.0,1.0}};



/*
	direction : 1 arrow is poiting to the left
	direction : 2 arrow is poiting to the right
	direction : 3 arrow is poiting to the up
	direction : 4 arrow is poiting to the down
*/
Arrow::Arrow(DIRECTION arg_direction , const sf::Texture& arg_arrowTexture , double arg_arrowSpeed , bool arg_firstRun) : defaultArrowSpeed(arg_arrowSpeed)
{
	texture = arg_arrowTexture;
	this->direction = arg_direction;	


	arrowSprite.setTexture(arg_arrowTexture);	
	arrowSprite.setTextureRect(originPositions[(unsigned int)direction]);	
	ResetArrow(arg_firstRun);
}


bool Arrow::MoveArrow(sf::Time arg_dt)
{
	bool retStatus = true;

	unsigned int dr = (unsigned int)direction;
	float deltaT = arg_dt.asSeconds();

	//shadowSpeed += (((float)deltaT / (1000000 / FpsRegulator::fps)) * defaultArrowSpeed);
	shadowSpeed += defaultArrowSpeed;
	if(shadowSpeed >= 1.00000)
	{
		arrowSprite.move(arrowMoves[dr]);

		sf::Vector2u tempPosition;
		tempPosition.x = (unsigned int) arrowSprite.getPosition().x;
		tempPosition.y = (unsigned int) arrowSprite.getPosition().y;		 
		if(tempPosition.x >= FpsRegulator::resolution.x || tempPosition.x <= 0)
		{

			retStatus = false;
		}
		else if(tempPosition.y >= FpsRegulator::resolution.y || tempPosition.y <= 0)
		{
			retStatus = false;
		}

		shadowSpeed = 0.00;

	}
	return retStatus;
}


void Arrow::ResetArrow(bool arg_firstRun)
{
	
	sf::Vector2u tempPos;

	if(arg_firstRun)
	{
		const sf::Vector2u topLeft {220,0};
		const sf::Vector2u bottomLeft {FpsRegulator::resolution.x ,FpsRegulator::resolution.y};
		tempPos = GenNewArrowPos(direction , topLeft , bottomLeft);
	}
	else
	{
		tempPos = GenNewArrowPos(direction);
	}
	
	arrowSprite.setPosition((float)tempPos.x , (float)tempPos.y);
}

sf::Vector2u Arrow::GenNewArrowPos(DIRECTION arg_direction)
{
	switch(arg_direction)
	{

		//RIGHT_LEFT ARROW
		case DIRECTION::RIGHT_LEFT:
		{			
			//Generate random number and put it in [0 , resolution.y]
			unsigned int pos = rand() % FpsRegulator::resolution.y;
			//Modulate it to be inline with MOACA
			unsigned int temp = (pos % FpsRegulator::sizeOfHungryDot.y);
			//Put it in the middle of MOACA
			pos = pos - temp + 23;

			return sf::Vector2u(FpsRegulator::resolution.x , pos);

			break;
		}

		//LEFT_RIGHT Arrow ->
		case DIRECTION::LEFT_RIGHT:
		{			
			//Generate random number 
			unsigned int pos = rand() % FpsRegulator::resolution.y;
			//Modulate it to in in line with MOACA
			unsigned int temp = (pos % FpsRegulator::sizeOfHungryDot.y);
			//Put it in the middle of MOACA
			pos = pos - temp + 23;

			return sf::Vector2u(0 , pos);
			
		}


		case DIRECTION::UP_DOWN:
		{			
			//Generate random number 
			unsigned int pos = rand() % FpsRegulator::resolution.x;
			//Modulate it to in in line with MOACA
			unsigned int temp = (pos % FpsRegulator::sizeOfHungryDot.x);
			//Put it in the middle of MOACA
			pos = pos - temp + 18;

			return sf::Vector2u(pos , 0);
			

		}

		case DIRECTION::DOWN_UP:
		{			
			//Generate random number 
			unsigned int pos = rand() % FpsRegulator::resolution.x;
			//Modulate it to in in line with MOACA
			unsigned int temp = (pos % FpsRegulator::sizeOfHungryDot.x);
			//Put it in the middle of MOACA
			pos = pos - temp + 18;


			return sf::Vector2u(pos , FpsRegulator::resolution.y);
		}	

		default :
			break;
	}
}

sf::Vector2u Arrow::GenNewArrowPos(DIRECTION arg_direction , sf::Vector2u arg_topLeftOrigin, sf::Vector2u arg_bottomRightOrigin)
{

	switch(arg_direction)
	{

		//RIGHT_LEFT ARROW
		case DIRECTION::RIGHT_LEFT:
		{
			//Generate random number and put it in [0 , resolution.y]
			//unsigned int pos = rand() % FpsRegulator::resolution.y;
			unsigned int pos = (rand() % (arg_bottomRightOrigin.y - arg_topLeftOrigin.y) + arg_topLeftOrigin.y);
			//Modulate it to be inline with MOACA
			unsigned int temp = (pos % FpsRegulator::sizeOfHungryDot.y);
			//Put it in the middle of MOACA
			pos = pos - temp + 23;

			return sf::Vector2u(FpsRegulator::resolution.x , pos);

			break;
		}

		//LEFT_RIGHT Arrow ->
		case DIRECTION::LEFT_RIGHT:
		{
			//Generate random number			
			unsigned int pos = (rand() % (arg_bottomRightOrigin.y - arg_topLeftOrigin.y) + arg_topLeftOrigin.y);
			//Modulate it to in in line with MOACA
			unsigned int temp = (pos % FpsRegulator::sizeOfHungryDot.y);
			//Put it in the middle of MOACA
			pos = pos - temp + 23;

			return sf::Vector2u(0 , pos);

		}

		case DIRECTION::UP_DOWN:
		{
			//Generate random number
			//unsigned int pos = rand() % FpsRegulator::resolution.x;
			unsigned int pos = (rand() % (arg_bottomRightOrigin.x - arg_topLeftOrigin.x) + arg_topLeftOrigin.x);
			//Modulate it to in in line with MOACA
			unsigned int temp = (pos % FpsRegulator::sizeOfHungryDot.x);
			//Put it in the middle of MOACA
			pos = pos - temp + 18;

			return sf::Vector2u(pos , 0);


		}

		case DIRECTION::DOWN_UP:
		{
			//Generate random number
			//unsigned int pos = rand() % FpsRegulator::resolution.x;
			unsigned int pos = (rand() % (arg_bottomRightOrigin.x - arg_topLeftOrigin.x) + arg_topLeftOrigin.x);
			//Modulate it to in in line with MOACA
			unsigned int temp = (pos % FpsRegulator::sizeOfHungryDot.x);
			//Put it in the middle of MOACA
			pos = pos - temp + 18;


			return sf::Vector2u(pos , FpsRegulator::resolution.y);
		}

		default :
			break;
	}
}

void Arrow::SetArrowPosition(float x , float y)
{
	arrowSprite.setPosition(x , y);
}



void Arrow::IncreaseSpeedOfArrow()
{
	arrowSpeed++;
}

// void Arrow::RandomizeArrowPos()
// {
// 	sf::Vector2u temporaryPosition = GenNewArrowPos(direction);
// 	arrowSprite.setPosition(static_cast<sf::Vector2f>(temporaryPosition));
// }
