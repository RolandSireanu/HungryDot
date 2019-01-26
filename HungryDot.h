#ifndef HUNGRY_DOT
#define HUNGRY_DOT

#include "SFML/Graphics.hpp"

class HungryDot
{
	
	public:

		enum class Direction : unsigned int {LEFT=0x00 , RIGHT=0x02 , UP=0x06 , DOWN=0x0A};


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
		void WallCollision();

	private:		

		void KeepTheDotInPlay(int& , int&);

		Direction direction;
		unsigned int score;
		unsigned int lives;
		unsigned int wallsCollision;
		bool leftWallCollision;
		bool rightWallCollision;
		bool upWallCollision;
		bool downWallCollision;
		int xSpeed;
		int ySpeed;		
		std::vector<sf::Texture> m_hungryDotTextures;
		sf::Sprite m_hungryDotSprite;
		sf::Vector2u position;

		const unsigned int DEFAULT_NR_OF_LIVES = 3;
		const unsigned int NR_OF_SPRITES = 4;
		const float DEFAULT_X_SPEED = 10.0f;
		const float DEFAULT_Y_SPEED = 10.0f;
		const unsigned int LEFT_WALL_MASK = 0x01;
		const unsigned int RIGHT_WALL_MASK = 0x02;
		const unsigned int UP_WALL_MASK = 0x04;
		const unsigned int DOWN_WALL_MASK = 0x08;

};

#endif