#include "StateLeaderBoard.h"

StateLeaderBoard::StateLeaderBoard(SharedContext& arg_context , StateStack* arg_stateStack) : BaseState(arg_context , arg_stateStack) , 
        text(new sf::Text[MAX_PLAYERS_LEADRBOARD])
{    
    std::vector<DataBase::TPlayer> topPlayer;
    std::cout<<"StateLeaderBoard begin ==== "<<std::endl;
    std::shared_ptr<DataBase> tsp = DataBase::GetObject();
    if(tsp != nullptr)
    {
        topPlayer = tsp->GetLeaderBoard();
    }
    else
    {
        std::cout<<"tsp is null !"<<std::endl;
    }
    
    for(auto& p : topPlayer)
    {        
        std::cout<<p.name<<" "<<p.score<<std::endl;
    }    

    nr_of_players_leaderboards = std::min(MAX_PLAYERS_LEADRBOARD , (unsigned int)topPlayer.size());

    font.loadFromFile("Media/arial.ttf");

    for(int i=0; i<nr_of_players_leaderboards; i++)
    {
        text[i].setFont(font);
        text[i].setCharacterSize(30);
        text[i].setPosition(150 , 60*(i+1));
        text[i].setColor(sf::Color::White);
        text[i].setString(topPlayer[i].name + "   " + std::to_string(topPlayer[i].score));
    }

}

void StateLeaderBoard::Update(sf::Time)
{
    return;
}

void StateLeaderBoard::Render()
{
    for(int i = 0; i < nr_of_players_leaderboards; i++)
    {
        sharedContext.sharedRenderWindow.draw(text[i]);
    }
}


void StateLeaderBoard::HandleInput(InputEvents::Ev)
{

}

StateLeaderBoard::~StateLeaderBoard()
{

}