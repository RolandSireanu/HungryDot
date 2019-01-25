#include "HungryDot.h"
#include "FpsRegulator.h"
#include <iostream>


/* Initiaize the internal state */
HungryDot::HungryDot()
{
	m_hungryDotTextures.resize(NR_OF_SPRITES);

	m_hungryDotTextures[(unsigned int)Direction::LEFT].loadFromFile("Media/LeftDot.png");
	m_hungryDotTextures[(unsigned int)Direction::LEFT+1].loadFromFile("Media/MiddleLeft.png");
	m_hungryDotTextures[(unsigned int)Direction::RIGHT].loadFromFile("Media/RightDot.png");
	m_hungryDotTextures[(unsigned int)Direction::RIGHT+1].loadFromFile("Media/MiddleRight.png");
	m_hungryDotSprite.setTexture(m_hungryDotTextures[(unsigned int)Direction::RIGHT]);	

	Reset();
}

void HungryDot::Move()
{
	static unsigned int counter = 1;

	if(counter % FpsRegulator::GetFpsDivDot() == 0)
	{
		if(direction == Direction::LEFT)
		{
			xSpeed = -DEFAULT_X_SPEED;
			ySpeed = 0;
		}
		else if(direction == Direction::RIGHT)
		{
			xSpeed = DEFAULT_X_SPEED;
			ySpeed = 0;	
		}
		else if(direction == Direction::UP)
		{
			xSpeed = 0;
			ySpeed = -DEFAULT_Y_SPEED;
		}
		else if(direction == Direction::DOWN)
		{
			xSpeed = 0;
			ySpeed = DEFAULT_Y_SPEED;
		}
		counter = 0;
	}
	else
	{
		xSpeed = 0;
		ySpeed = 0;
	}

	counter++;
	m_hungryDotSprite.move(sf::Vector2f(xSpeed,ySpeed));
}

bool HungryDot::WallCollision()
{
	sf::Vector2f tempPos = m_hungryDotSprite.getPosition();

	if(tempPos.x > FpsRegulator::resolution.x || tempPos.x < 0)
		return true;
	if(tempPos.y > FpsRegulator::resolution.y || tempPos.y < 0)
		return true;
	
	return false;

}

void HungryDot::Update()
{
	Move();
	if(WallCollision())
		std::cout<<"WALL COLLISION !!!" <<std::endl;
}

void HungryDot::Reset()
{

	direction = Direction::RIGHT;
	score = 0;
	lives = DEFAULT_NR_OF_LIVES;
	xSpeed = 10.0f;
	ySpeed = 0.0f;

}

void HungryDot::Render(sf::RenderWindow& window)
{	
	static bool middle = false;
	static unsigned int fpsDivider = 0;
	unsigned int tempDirection = static_cast<unsigned int>(direction) % NR_OF_SPRITES;

	fpsDivider++;
	if(fpsDivider % FpsRegulator::GetFpsDivDotTexture() == 0)
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


