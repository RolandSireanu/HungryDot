/*
 * StateGame.cpp
 *
 *  Created on: May 8, 2019
 *      Author: roland
 */


#include "../include/StateGame.h"
#include "DataBase.h"
#include <fstream>

StateGame::StateGame(SharedContext& arg_context , StateStack* arg_stateStack):
	BaseState(arg_context , arg_stateStack),
	m_hungryDot(HungryDot::Direction::RIGHT , 6 , 6 , 0.0f , 0.0f),
	m_world()
{

}


void StateGame::Update(sf::Time dt)
{
	m_hungryDot.Update(dt);
	if(m_world.Update(m_hungryDot , dt) == true)
	{
		int currentBestScoreFromDb;
		unsigned int currentBestScore;
		//sharedContext.refDataBase>>currentBestScoreFromDb;

		currentBestScore = m_hungryDot.GetBestScoreSoFar();
		currentBestScoreFromDb = DataBase::GetObject()->ReadBestScore();
		std::cout<<"Current best score from DB is = "<<currentBestScoreFromDb<<std::endl;
		std::cout<<"Current best score from HungryDot is  = "<<currentBestScore<<std::endl;

		if(currentBestScoreFromDb < currentBestScore)
		{
			std::cout<<"Write best score in db !"<<std::endl;
			DataBase::GetObject()->WriteBestScore(currentBestScore);
			//sharedContext.refDataBase<<currentBestScore<<std::endl;
		}

		m_stateStack->addStateToStack(BaseState::STATES::STATE_GAME_OVER);
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
