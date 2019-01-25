#include "HungryDot.h"



/* Initiaize the internal state */
HungryDot::HungryDot()
{
	m_hungryDotTexture.loadFromFile("Media/HungryDot.png");
	m_hungryDotSprite.setTexture(m_hungryDotTexture);

	Reset();
}

void HungryDot::Move()
{

}

void HungryDot::Update()
{


}

void HungryDot::Reset()
{

	direction = Direction::RIGHT;
	score = 0;
	lives = DEFAULT_NR_OF_LIVES;

}

void HungryDot::Render(sf::RenderWindow& window)
{
	window.draw(m_hungryDotSprite);
}