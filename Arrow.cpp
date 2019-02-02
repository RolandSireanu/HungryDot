#include "Arrow.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "FpsRegulator.h"

/*
	0 - RIGHT_LEFT
	1 - LEFT_RIGHT
	2 - DOWN_UP
	3 - UP_DOWN	
*/
const std::vector<sf::IntRect> Arrow::originPositions = {{50,0,17,11} , {31,0,17,11} , {0,0,8,17} , {16,0,10,17}};

const std::vector<sf::Vector2f> Arrow::arrowMoves = {{-10.0,0.0} , {10.0,0.0} , {0.0 ,10.0} , {0.0,-10.0}};

/*
	direction : 1 arrow is poiting to the left
	direction : 2 arrow is poiting to the right
	direction : 3 arrow is poiting to the up
	direction : 4 arrow is poiting to the down
*/
Arrow::Arrow(DIRECTION direction , const sf::Texture& arg_arrowTexture)
{
	texture = arg_arrowTexture;
	direction = direction;

	arrowSprite.setTexture(arg_arrowTexture);
	arrowSprite.setTextureRect(originPositions[(int)direction]);

	ResetArrow();
}


bool Arrow::MoveArrow()
{
	arrowSprite.move(arrowMoves[(int)direction]);
	return true;
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

			break;
		}

		default :
			break;
	}
}