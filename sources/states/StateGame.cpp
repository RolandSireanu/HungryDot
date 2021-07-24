/*
 * StateGame.cpp
 *
 *  Created on: May 8, 2019
 *      Author: roland
 */


#include "StateGame.h"
#include "DataBase.h"
#include "Globals.h"
#include <fstream>

StateGame::StateGame(SharedContext& arg_context , StateStack* arg_stateStack):
	BaseState(arg_context , arg_stateStack),
	m_hungryDot(HungryDot::Direction::RIGHT , 6 , 6 , 0.0f , 0.0f),
	m_world(),
	firstRun(true),	
	audioPlayer(Audio::AudioStates::STATE_GAME_AUDIO)
{
	audioPlayer.Play();
	
}

void StateGame::Update(sf::Time dt)
{
	m_hungryDot.Update(dt);	
	if(m_world.Update(m_hungryDot , dt , firstRun) == true)
	{
		int currentBestScoreFromDb;
		unsigned int currentBestScore;
		//sharedContext.refDataBase>>currentBestScoreFromDb;

		currentBestScore = m_hungryDot.GetBestScoreSoFar();		
		DataBase::GetObject()->WriteScore(currentBestScore , Globals::currentPlayer);			

		m_stateStack->addStateToStack(BaseState::STATES::STATE_GAME_OVER);
	}
	else
	{
		firstRun = false;
	}	

}
void StateGame::Render()
{
	m_hungryDot.Render(sharedContext.sharedRenderWindow);
	m_world.Render(sharedContext.sharedRenderWindow , m_hungryDot);
}

void StateGame::HandleInput(InputEvents::Ev arg_event)
{
	m_hungryDot.HandleInput(arg_event);
}
