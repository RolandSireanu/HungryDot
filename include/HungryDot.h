#ifndef HUNGRY_DOT
#define HUNGRY_DOT

#include "SFML/Graphics.hpp"
#include <map>
#include <unordered_map>
#include <functional>
#include "InputEvents.h"
#include "Globals.h"

class HungryDot
{

	

	public:

		enum class Direction : unsigned int {LEFT=0x00 , RIGHT=0x02 , UP=0x06 , DOWN=0x0A};
		enum class JoystickButtons : unsigned int {CROSS = 0x00 , CIRCLE=0x01 , TRIANGLE=0x02 , RECTANGLE=0x03 };

	public:

		HungryDot(Direction arg_dr , int arg_xs , int arg_ys , float arg_xpos , float arg_ypos);

		/* Handle DIRECTION */
		void SetDirection(Direction arg_direction) { direction = arg_direction; }
		Direction GetDirection() { return direction; }

		/* Handle NR_OF_LIVES */
		unsigned int GetNrOfLives() { return lives; }
		void ResetNrOfLives() { lives = 3; }
		void DecreaseNrOfLives() { lives--; }

		/* Handle SCORE */
		void IncreaseScore(unsigned int arg_deltaScore)
		{
			score+=arg_deltaScore;
			Globals::bestScoreSoFar = std::max(Globals::bestScoreSoFar , score);
		}
		unsigned int GetScore() const { return score; }
		unsigned int GetBestScoreSoFar() const {return Globals::bestScoreSoFar;}
		unsigned int ResetScore() { score = 0; }
		unsigned int GetHeight() const { return HEIGHT_OF_HUNGRYDOT;}
		unsigned int GetWidth() const { return WIDTH_OF_HUNGRYDOT;}


		void Move(sf::Time);
		void Update(sf::Time);
		void Reset();
		void Render(sf::RenderWindow& window);
		void WallCollision();
		void IncreaseSpeed();

		void HandleInput(InputEvents::Ev arg_event);

		sf::Vector2f GetCurrentPosition() const;

		struct hashFunctorEv
		{
			size_t operator()(const InputEvents::Ev& arg_ev) const
			{
				int temporary = static_cast<int>(arg_ev.keyboardKey);

				return (std::hash<unsigned int>()(arg_ev.joystickButton)  ^ std::hash<int>()(temporary));
			}
		};

	private:

		void KeepTheDotInPlay(int& , int&);


		Direction direction;
		unsigned int score;
		//unsigned int bestScoreSoFar;
		unsigned int lives;
		unsigned int wallsCollision;		
		int xSpeed;
		int ySpeed;		
		std::vector<sf::Texture> m_hungryDotTextures;
		sf::Sprite m_hungryDotSprite;
		sf::Vector2u position;

		const unsigned int DEFAULT_NR_OF_LIVES = 3;
		const unsigned int NR_OF_SPRITES = 4;
		unsigned int DEFAULT_X_SPEED;
		unsigned int DEFAULT_Y_SPEED;
		const sf::Vector2f POSITION;
		const Direction DIRECTION;
		const unsigned int LEFT_WALL_MASK = 0x01;
		const unsigned int RIGHT_WALL_MASK = 0x02;
		const unsigned int UP_WALL_MASK = 0x04;
		const unsigned int DOWN_WALL_MASK = 0x08;
		const unsigned int WIDTH_OF_HUNGRYDOT = 50;
		const unsigned int HEIGHT_OF_HUNGRYDOT = 50;

		std::unordered_map<InputEvents::Ev , std::function<void(void)> , hashFunctorEv> generalActionBinding;

};

#endif
