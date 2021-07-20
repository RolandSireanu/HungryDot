/*
 * BaseState.h
 *
 *  Created on: Feb 25, 2019
 *      Author: roland
 */

#ifndef STATE_INTRO_H
#define STATE_INTRO_H

#include "BaseState.h"
#include "SFML/Graphics.hpp"
#include "FpsRegulator.h"
#include "StateStack.h"
#include "AudioPlayer.h"

class StateIntro : public BaseState
{

	public:

		StateIntro(BaseState::SharedContext& arg_sharedContext , StateStack* arg_stateStack) : BaseState(arg_sharedContext , arg_stateStack) , spritesToDraw(),
		dotSprite(new sf::Sprite()) , greenBeanSprite(new sf::Sprite()) , introSprite(new sf::Sprite()) , text(new sf::Text()) , player(Audio::AudioStates::STATE_INTRO_AUDIO)
		{
			font.loadFromFile("Media/arial.ttf");
			dotTexture.loadFromFile("Media/MiddleRight.png");
			dotTextureOpen.loadFromFile("Media/RightDot.png");
			greenBeanTexture.loadFromFile("Media/Vegetable.png" , sf::IntRect(0,0,25,25));
			dotSprite->setTexture(dotTexture);
			dotSprite->setPosition(FpsRegulator::resolution.x * 0.10 ,335);
			greenBeanSprite->setTexture(greenBeanTexture);
			greenBeanSprite->setPosition(FpsRegulator::resolution.x * 0.80,350);

			text->setFont(font);
			text->setCharacterSize(24);
			text->setPosition(100,250);
			text->setFillColor(sf::Color::Blue);
			text->setColor(sf::Color::White);
			text->setString("Press ENTER key to start the game !");

			introTexture.loadFromFile("Media/IntroPic.png");
			introSprite->setTexture(introTexture);
			introSprite->setPosition(35,50);

			spritesToDraw.push_back(dotSprite);
			spritesToDraw.push_back(greenBeanSprite);
			spritesToDraw.push_back(introSprite);

			player.Play();
		}

		void Update(sf::Time);
		void Render();
		void HandleInput(InputEvents::Ev);

		~StateIntro() = default;

	private :

		sf::Font font;
		std::shared_ptr<sf::Text> text;
		sf::Texture dotTextureOpen;
		sf::Texture dotTexture;
		sf::Texture greenBeanTexture;
		std::shared_ptr<sf::Sprite> dotSprite;
		std::shared_ptr<sf::Sprite> greenBeanSprite;
		sf::Texture introTexture;
		std::shared_ptr<sf::Sprite> introSprite;
		const unsigned int dotXSpeed = 175;
		bool readyToSwitchState = false;
		std::vector<std::shared_ptr<sf::Drawable> > spritesToDraw;
		Audio::Player player;

};



#endif /* BASESTATE_H_ */
