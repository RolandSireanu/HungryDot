#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include <string>
#include <SFML/Audio/Music.hpp>
#include <thread> 


namespace Audio
{

    enum class AudioStates : unsigned int { STATE_MENU_AUDIO , STATE_GAME_AUDIO , STATE_INTRO_AUDIO };


    class Player
    {
        public:
            Player(AudioStates arg_audioState);      

            void Play();
            
            

        private:
            std::string stateMenuAudio;
            std::string stateGameAudio;
            std::string stateIntroAudio;
            sf::Music music;
            
    };

};

#endif
