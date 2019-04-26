#include "HungryDot.h"
#include "FpsRegulator.h"
#include <iostream>
#include "SFML/System/Vector2.hpp"

/* Initiaize the internal state */
HungryDot::HungryDot(Direction arg_dr , int arg_xs , int arg_ys , float arg_xpos , float arg_ypos)
	: DIRECTION(arg_dr) , DEFAULT_X_SPEED(arg_xs) , DEFAULT_Y_SPEED(arg_ys) , POSITION(arg_xpos , arg_ypos)
{
	m_hungryDotTextures.resize(NR_OF_SPRITES);

	m_hungryDotTextures[(unsigned int)Direction::LEFT].loadFromFile("Media/LeftDot.png");
	m_hungryDotTextures[(unsigned int)Direction::LEFT+1].loadFromFile("Media/MiddleLeft.png");
	m_hungryDotTextures[(unsigned int)Direction::RIGHT].loadFromFile("Media/RightDot.png");
	m_hungryDotTextures[(unsigned int)Direction::RIGHT+1].loadFromFile("Media/MiddleRight.png");
	m_hungryDotSprite.setTexture(m_hungryDotTextures[(unsigned int)DIRECTION]);
	
	Reset();
}

void HungryDot::KeepTheDotInPlay(int& arg_xSpeed , int& arg_ySpeed)
{
	if(wallsCollision & RIGHT_WALL_MASK)
		arg_xSpeed = arg_xSpeed > 0 ? 0 : arg_xSpeed;

	if(wallsCollision & LEFT_WALL_MASK)
		arg_xSpeed = arg_xSpeed < 0 ? 0 : arg_xSpeed;		

	if(wallsCollision & UP_WALL_MASK)
		arg_ySpeed = arg_ySpeed < 0 ? 0 : arg_ySpeed;

	if(wallsCollision & DOWN_WALL_MASK)
		arg_ySpeed = arg_ySpeed > 0 ? 0 : arg_ySpeed;
}

void HungryDot::Move(long long arg_deltaTiming)
{
	static unsigned int counter = 1;
	static double shadowSpeed = 0.00;
	static double shadow_ySpeed = 0.00;

	//std::cout<<"computation result = "<<((float)arg_deltaTiming / (1000000 / FpsRegulator::fps))*DEFAULT_X_SPEED<<std::endl;
	shadowSpeed = shadowSpeed + (((float)arg_deltaTiming / (1000000 / FpsRegulator::fps)) * DEFAULT_X_SPEED);
	//std::cout<<"shadowSpeed = "<<shadowSpeed<<std::endl;

	if(shadowSpeed >= 1.0000)
	{

		if(direction == Direction::LEFT)
		{

			//xSpeed = -DEFAULT_X_SPEED;
			xSpeed = -(unsigned int)shadowSpeed;
			ySpeed = 0;
		}
		else if(direction == Direction::RIGHT)
		{
			//xSpeed = DEFAULT_X_SPEED;
			xSpeed = (unsigned int)shadowSpeed;
			ySpeed = 0;	
		}
		else if(direction == Direction::UP)
		{
			xSpeed = 0;
			//ySpeed = -DEFAULT_Y_SPEED;
			ySpeed = -(unsigned int)shadowSpeed;
		}
		else if(direction == Direction::DOWN)
		{
			xSpeed = 0;
			//ySpeed = DEFAULT_Y_SPEED;
			ySpeed = (unsigned int)shadowSpeed;
		}
		//counter = 0;
		shadowSpeed = 0.000;
	}
	else
	{
		xSpeed = 0;
		ySpeed = 0;
	}

	counter++;


	KeepTheDotInPlay(xSpeed , ySpeed);
	m_hungryDotSprite.move(sf::Vector2f(xSpeed,ySpeed));
}

void HungryDot::WallCollision()
{	
	sf::Vector2f tempPos = m_hungryDotSprite.getPosition();
	sf::Vector2u sizeOfSprite = m_hungryDotSprite.getTexture()->getSize();

//	std::cout<<"sizeOfSprite.x = "<<sizeOfSprite.x<<std::endl;
//	std::cout<<"tempPos.x = "<<tempPos.x<<" and resolution.x = "<<FpsRegulator::resolution.x<<std::endl;
	if(tempPos.x >= FpsRegulator::resolution.x - sizeOfSprite.x)
		wallsCollision |= RIGHT_WALL_MASK;	
	else
		wallsCollision &= (~RIGHT_WALL_MASK);		

	if(tempPos.x <= 0)
		wallsCollision |= LEFT_WALL_MASK;	
	else
		wallsCollision &= (~LEFT_WALL_MASK);

	if(tempPos.y >= FpsRegulator::resolution.y - sizeOfSprite.y)
		wallsCollision |= DOWN_WALL_MASK;		
	else
		wallsCollision &= (~DOWN_WALL_MASK);

	if(tempPos.y <= 0)
		wallsCollision |= UP_WALL_MASK;		
	else
		wallsCollision &= (~UP_WALL_MASK);		
}




void HungryDot::Update(long long arg_deltaT)
{
	Move(arg_deltaT);
	WallCollision();
		
}

void HungryDot::Reset()
{

	direction = DIRECTION;
	score = 0;
	lives = DEFAULT_NR_OF_LIVES;
	xSpeed = DEFAULT_X_SPEED;
	ySpeed = DEFAULT_Y_SPEED;

	m_hungryDotSprite.setPosition(POSITION);

}

void HungryDot::Render(sf::RenderWindow& window)
{	
	static bool middle = false;
	static unsigned int fpsDivider = 0;
	unsigned int tempDirection = static_cast<unsigned int>(direction) % NR_OF_SPRITES;

	fpsDivider++;
	//if(fpsDivider % FpsRegulator::GetFpsDivDotTexture() == 0)
	if(true)
	{
		if(middle)
		{
			tempDirection++;		
		}
	
		m_hungryDotSprite.setTexture(m_hungryDotTextures[tempDirection]);

		
		window.draw(m_hungryDotSprite);
		middle = !middle;
		fpsDivider = 0;
	}
	else
	{		
		window.draw(m_hungryDotSprite);
	}

}

sf::Vector2f HungryDot::GetCurrentPosition() const
{
	sf::Vector2f p = m_hungryDotSprite.getPosition();
	p.y += 5;
	return p;
}
