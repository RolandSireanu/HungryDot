#ifndef STATE_LEADERBOARD
#define STATE_LEADERBOARD

#include "BaseState.h"
#include "DataBase.h"
#include <iostream>
#include "SFML/System.hpp"
#include "MediaResources.h"

class StateLeaderBoard : public BaseState
{

    public:
        StateLeaderBoard(SharedContext& arg_context , StateStack* arg_stateStack);

        void Update(sf::Time) override;
        void Render() override;
        void HandleInput(InputEvents::Ev) override;

        ~StateLeaderBoard();

    private:
        const unsigned int MAX_PLAYERS_LEADRBOARD = 5;
        unsigned int nr_of_players_leaderboards=5;
        sf::Font font;
		std::unique_ptr<sf::Text[]> text;
};



#endif