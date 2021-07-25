#include "AudioPlayer.h"

namespace Audio
{
    Player::Player(AudioStates arg_audioState) : stateMenuAudio(MediaResources::getMenuMusic()) , stateGameAudio(MediaResources::getGameMusic()) , stateIntroAudio(MediaResources::getMenuMusic())
    {         

        switch (arg_audioState)
        {
            case AudioStates::STATE_MENU_AUDIO:
                music.openFromFile(stateMenuAudio);
                
                break;

            case AudioStates::STATE_GAME_AUDIO:
                music.openFromFile(stateGameAudio);
                break;

            case AudioStates::STATE_INTRO_AUDIO:
                music.openFromFile(stateIntroAudio);

            default:
                break;
        }
    }

    void Player::Play()
    {
        music.play();
    }

};