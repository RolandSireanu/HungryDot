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
Arrow::Arrow(DIRECTION arg_direction , const sf::Texture& arg_arrowTexture , double arg_arrowSpeed) : defaultArrowSpeed(arg_arrowSpeed)
{
	texture = arg_arrowTexture;
	this->direction = arg_direction;	


	arrowSprite.setTexture(arg_arrowTexture);
	arrowSprite.setTextureRect(originPositions[(unsigned int)direction]);

	ResetArrow();
}


bool Arrow::MoveArrow(long long arg_dt)
{
	bool retStatus = true;

	unsigned int dr = (unsigned int)direction;

	shadowSpeed += (((float)arg_dt / (1000000 / FpsRegulator::fps)) * defaultArrowSpeed);

	if(shadowSpeed >= 1.00000)
	{
		arrowSprite.move(arrowMoves[dr]);

		sf::Vector2u tempPosition = (sf::Vector2u)arrowSprite.getPosition();
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


void Arrow::ResetArrow()
{
	const sf::Vector2u tempPos = GenNewArrowPos(direction);
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
