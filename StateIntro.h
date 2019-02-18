#ifndef STATE_INTRO
#define STATE_INTRO

#include "StateManager.h"

class State_Intro : public BaseState
{
	public:

		void OnCreate();
		void OnDestroy();
		void Activate();
		void Deactivate();
		void Update(const sf::Time& l_time);
		void Draw();

		void Continue(EventDetails* arg_details);

	private:

		sf::Texture m_introTexture;
		sf::Sprite m_introSprite;
		sf::Text m_text;
		float m_timePassed;

};





#endif
