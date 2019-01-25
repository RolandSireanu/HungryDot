#ifndef HUNGRY_DOT
#define HUNGRY_DOT

#include "SFML/Graphics.hpp"

class HungryDot
{
	
	private:

		enum class Direction : unsigned int {LEFT=0x01 , RIGHT=0x02 , UP=0x03 , DOWN=0x04};


	public:

		HungryDot();

		/* Handle DIRECTION */
		void SetDirection(Direction arg_direction) { direction = arg_direction; }
		Direction GetDirection() { return direction; }

		/* Handle NR_OF_LIVES */
		unsigned int GetNrOfLives() { return lives; }
		void ResetNrOfLives() { lives = 3; }
		void DecreaseNrOfLives() { lives--; }

		/* Handle SCORE */
		void IncreaseScore() { score++; }
		unsigned int GetScore() { return score; }
		unsigned int ResetScore() { score = 0; }


		void Move();
		void Update();
		void Reset();
		void Render(sf::RenderWindow& window);

	private:

		Direction direction;
		unsigned int score;
		unsigned int lives;
		sf::Texture m_hungryDotTexture; 
		sf::Sprite m_hungryDotSprite;
		
		const unsigned int DEFAULT_NR_OF_LIVES = 3;

};

#endif